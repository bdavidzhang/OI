class SegTree:
    def __init__(self, values):
        self.length = len(values)
        self.size = 1
        while self.size < self.length:
            self.size *= 2

        tree_size = 2 * self.size
        self.prefix_zero = [0] * tree_size
        self.prefix_one = [0] * tree_size
        self.suffix_zero = [0] * tree_size
        self.suffix_one = [0] * tree_size
        self.odd_count = [0] * tree_size
        self.total_parity = [0] * tree_size

        self.weighted_sum = 0
        for index, bit in enumerate(values):
            self._set_leaf(self.size + index, bit)
            if bit:
                self.weighted_sum += (index + 1) * (self.length - index)

        for node in range(self.size - 1, 0, -1):
            self._pull(node)

    def _set_leaf(self, node, bit):
        self.total_parity[node] = bit
        if bit:
            self.prefix_one[node] = self.suffix_one[node] = 1
            self.odd_count[node] = 1
        else:
            self.prefix_zero[node] = self.suffix_zero[node] = 1

    def _pull(self, node):
        left = node * 2
        right = left + 1

        self.total_parity[node] = self.total_parity[left] ^ self.total_parity[right]
        self.odd_count[node] = (
            self.odd_count[left]
            + self.odd_count[right]
            + self.suffix_zero[left] * self.prefix_one[right]
            + self.suffix_one[left] * self.prefix_zero[right]
        )

        self.prefix_zero[node] = self.prefix_zero[left]
        self.prefix_one[node] = self.prefix_one[left]
        if self.total_parity[left] == 0:
            self.prefix_zero[node] += self.prefix_zero[right]
            self.prefix_one[node] += self.prefix_one[right]
        else:
            self.prefix_zero[node] += self.prefix_one[right]
            self.prefix_one[node] += self.prefix_zero[right]

        self.suffix_zero[node] = self.suffix_zero[right]
        self.suffix_one[node] = self.suffix_one[right]
        if self.total_parity[right] == 0:
            self.suffix_zero[node] += self.suffix_zero[left]
            self.suffix_one[node] += self.suffix_one[left]
        else:
            self.suffix_zero[node] += self.suffix_one[left]
            self.suffix_one[node] += self.suffix_zero[left]

    def toggle(self, index):
        if not 0 <= index < self.length:
            return
        node = self.size + index
        old_bit = self.total_parity[node]
        self.weighted_sum += (1 if old_bit == 0 else -1) * (index + 1) * (self.length - index)
        self.prefix_zero[node] = self.prefix_one[node] = 0
        self.suffix_zero[node] = self.suffix_one[node] = 0
        self.odd_count[node] = 0
        self._set_leaf(node, old_bit ^ 1)
        node //= 2
        while node:
            self._pull(node)
            node //= 2

    def answer(self):
        return (self.weighted_sum + self.odd_count[1]) // 2


t = int(input())

for _ in range(t):
    n, q = map(int, input().split())
    s = input().strip()
    b = [s[i] != s[i + 1] for i in range(n - 1)]
    tree = SegTree(b)

    ans = [str(tree.answer())]
    for _ in range(q):
        pos = int(input()) - 1
        tree.toggle(pos - 1)
        tree.toggle(pos)
        ans.append(str(tree.answer()))

    print(" ".join(ans))

