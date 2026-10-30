# D. Dr. Agos's Dark Mode

## 1. Modulo 3 observation

Since

\[
2^k \equiv (-1)^k \pmod 3,
\]

the value of a binary segment modulo `3` depends only on the parity of the
positions of its `1`s.

A segment containing exactly one `1` can never be divisible by `3`, because
its value is a power of `2`. Therefore, all segments consisting only of zeroes
are always irritating, while a segment containing one `1` is harmless.

For two `1`s whose distance is `d`, the segment containing both has value

\[
2^d + 1.
\]

This is nonzero modulo `3` exactly when `d` is even. Thus, if two `1`s are an
even distance apart, every segment containing both of them is also harmless.

## 2. The general construction with two `1`s

Write the string as

\[
0^x\,1\,0^y\,1\,0^z.
\]

The distance between the `1`s is `y + 1`, so we require `y` to be odd.
Then the only irritating segments are the all-zero segments.

If a zero block has length `k`, it contributes

\[
1+2+\cdots+k = \frac{k(k+1)}2
\]

irritating segments. Consequently, the total is

\[
T(x)+T(y)+T(z),
\qquad T(k)=\frac{k(k+1)}2,
\]

where

\[
x+y+z=n-2.
\]

The function `T` is convex, so the minimum is obtained by making the three
blocks as equal as possible. The only additional condition is that `y` must be
odd. Try the one or two odd values of `y` closest to `(n-2)/3`, split the
remaining zeroes between `x` and `z` as evenly as possible, and keep the best
candidate.

This gives the optimal construction for almost every `n`.

## 3. The exceptional residue class

When `n = 6q + 2`, the rounding condition for the two-`1` construction loses
one extra segment. Three `1`s can do better:

\[
1\,0^{2q}\,1\,0^{2q-1}\,1\,0^{2q}.
\]

For example, for `n = 20` (`q = 3`) this is

```text
1000000100000100000
```

The zero blocks have lengths `0, 2q, 2q-1, 2q`, so their contribution is

\[
T(2q)+T(2q-1)+T(2q).
\]

The only additional irritating segments are the segments containing the first
two `1`s. There are `2q` such segments, giving the total

\[
2T(2q)+T(2q-1)+2q.
\]

The parity of the gaps ensures that every other segment containing `1`s is
nonzero modulo `3`.

Small values of `n` can be handled directly with fixed optimal strings, for
example:

```text
n = 1: 1
n = 2: 10
n = 3: 101
```

## 4. Why balancing is optimal

For any fixed number of `1`s, the zero-only contribution is a sum of triangular
numbers. If two zero blocks differ by at least two, moving one zero from the
larger block to the smaller one decreases the sum:

\[
T(a)+T(b) > T(a-1)+T(b+1)
\quad\text{when }a\ge b+2.
\]

Therefore every optimal construction has gaps differing by at most one,
subject to the parity condition needed to prevent segments containing two
`1`s from being divisible by `3`.

The only time the parity restriction makes the two-`1` arrangement worse than
using three `1`s is `n \equiv 2 \pmod 6`; the construction above fixes exactly
that case.

## 5. Complexity

Only a constant number of candidate strings are considered. Constructing and
printing a string takes `O(n)` time and `O(n)` memory.
