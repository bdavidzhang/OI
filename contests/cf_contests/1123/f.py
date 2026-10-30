
import heapq


def transform(values):
  limit = len(values)
  left_child = [-1]
  right_child = [-1]
  count = [0]

  for value in values:
    node = 0
    count[node] += 1
    for bit in range(29, -1, -1):
      if value & (1 << bit):
        if right_child[node] == -1:
          right_child[node] = len(count)
          left_child.append(-1)
          right_child.append(-1)
          count.append(0)
        node = right_child[node]
      else:
        if left_child[node] == -1:
          left_child[node] = len(count)
          left_child.append(-1)
          right_child.append(-1)
          count.append(0)
        node = left_child[node]
      count[node] += 1

  heap = [(0, 0, 0, 29)]
  result = []

  while heap and len(result) < limit:
    xor_prefix, first, second, bit = heapq.heappop(heap)

    if bit < 0:
      if first == second:
        pairs = count[first] * (count[first] - 1) // 2
      else:
        pairs = count[first] * count[second]
      result.extend([xor_prefix] * min(pairs, limit - len(result)))
      continue

    first_children = (left_child[first], right_child[first])
    second_children = (left_child[second], right_child[second])

    if first == second:
      for first_bit, child_first in enumerate(first_children):
        if child_first != -1:
          heapq.heappush(heap, (xor_prefix, child_first, child_first, bit - 1))
      if first_children[0] != -1 and first_children[1] != -1:
        heapq.heappush(
          heap,
          (xor_prefix | (1 << bit), first_children[0], first_children[1], bit - 1),
        )
    else:
      for first_bit, child_first in enumerate(first_children):
        if child_first == -1:
          continue
        for second_bit, child_second in enumerate(second_children):
          if child_second == -1:
            continue
          if child_first <= child_second:
            pair = (child_first, child_second)
          else:
            pair = (child_second, child_first)
          next_xor = xor_prefix
          if first_bit != second_bit:
            next_xor |= 1 << bit
          heapq.heappush(heap, (next_xor, pair[0], pair[1], bit - 1))

  return result


t = int(input())

for _ in range(t):
  n, q = map(int, input().split())
  arr = list(map(int, input().split()))

  qs = [int(input()) for _ in range(q)]

  ans = []
  cur = arr
  while True:
      ans.append(max(cur) - min(cur))
      if max(cur) == 0:
          break
      cur = transform(cur)

  print(*(ans[q] if q < len(ans) else 0 for q in qs))


  

