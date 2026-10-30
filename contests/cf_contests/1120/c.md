# C2. Floor of MEX (Hard Version)

For a set `B`,

```text
f(B, k) = mex({x // k : x in B})
```

We are given `a[k] = f(B, k)` for every `1 <= k <= n`, and must count all valid subsets `B` of `[0, n - 1]` modulo `10**9 + 7`.

## 1. Translate the mex conditions

Fix `k` and write `q = a[k]`.

The values whose quotient is `q` form the interval

```text
[q * k, (q + 1) * k - 1]
```

Therefore this interval is forbidden: `B` must not contain any of its elements.

For every `p < q`, `B` must contain at least one element from

```text
[p * k, (p + 1) * k - 1]
```

Otherwise quotient `p` is absent and the mex is smaller than `q`.

So the problem becomes counting subsets that:

1. avoid all forbidden intervals;
2. hit every required interval at least once.

The input guarantees that at least one valid subset exists.

## 2. Required intervals

For fixed `k`, the required intervals are indexed by `p = 0, 1, ..., a[k] - 1`:

```text
left  = p * k
right = min(n - 1, (p + 1) * k - 1)
```

For each right endpoint `right`, store the largest left endpoint among intervals ending there:

```text
need = [-1] * n
need[right] = max(need[right], left)
```

Why is only the largest left endpoint needed? If a selected position is at least the largest left endpoint, it belongs to every other interval with the same right endpoint too.

The last interval may go past `n - 1`, so its right endpoint must be clamped.

## 3. Why this is O(n log n)

It may look like there are too many required intervals, but

```text
a[k] <= ceil(n / k)
```

because `x < n`, so `x // k` cannot be too large. Hence the total number of intervals is

```text
sum(a[k]) <= sum(ceil(n / k)) = O(n log n).
```

Thus, for every `k`, directly loop over `p in range(a[k])` and update `need`.

The forbidden interval for `k` is

```text
left  = a[k] * k
right = min(n - 1, (a[k] + 1) * k - 1)
```

Mark all forbidden positions with a difference array:

```text
diff[left] += 1
diff[right + 1] -= 1
```

A prefix sum recovers whether each position is forbidden.

## 4. DP by the last selected position

While scanning positions from left to right, a partial subset only needs to remember its last selected position.

Let `dp[x]` be the number of valid partial subsets whose last selected position is `x`.
There is also an empty state with last position `-1`.

When processing position `x`, every required interval ending at `x` must already have been hit. Therefore the previous last selected position must be at least `need[x]`.

If the last selected position is smaller, that state is permanently invalid: the interval has ended and cannot be repaired later.

Maintain:

- `low`: the smallest last-selected position still alive;
- `alive`: the total number of alive partial subsets;
- `dp[x]`: states whose newest selected position is `x`.

`low` only moves right. At position `x`, remove all states with last position below `need[x]`.
Use `need[x] = -1` when no required interval ends at `x`; otherwise an unconstrained
position would incorrectly remove the empty state.

Then:

- not selecting `x` keeps all alive states;
- if `x` is not forbidden, selecting `x` is possible from every alive state, so

```text
dp[x] = alive
alive += dp[x]
```

At the end, `alive` is the answer.

## 5. DP pseudocode

Store the empty state's count separately as `empty = 1`, or put it at index `-1`.

```text
alive = 1
low = -1

for x in 0 .. n - 1:
    target = max(low, need[x])

    while low < target:
        low += 1
        if low == 0:
            alive -= empty
        else:
            alive -= dp[low]
        alive %= MOD

    low = target

    if x is not forbidden:
        dp[x] = alive
        alive += dp[x]
        alive %= MOD

answer = alive
```

The removal loop is linear overall because `low` never decreases. When `need[x] = 0`, the empty state is removed before position `x`, which correctly forces the first required interval `[0, k - 1]` to contain a selected element.

At each position, process the requirement first and only then consider selecting that position.

## 6. Complexity

For one test case:

- construct all required intervals: `O(n log n)`;
- construct forbidden positions: `O(n)`;
- run the DP: `O(n)`.

Therefore the total complexity is

```text
O(n log n) time and O(n) memory.
```

The sum of `n` over all test cases is at most `10**5`.
