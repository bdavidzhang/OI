t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    #finite state dp    

    order = sorted(range(n), key=lambda i: arr[i], reverse=True)
    peak = order[0] % 2
    side = 1 - peak

    states = {0}
    for i in order[1:]:
      val = i % 2
      ns = set()
      for state in states:
        l = state // 2
        r = state % 2

        if val == (side if l == 0 else peak):
          ns.add(((l ^ 1) * 2) + r)
        if val == (side if r == 0 else peak):
          ns.add((l * 2) + (r ^ 1))

      states = ns

    ans = peak * 2 + ((n - 1 - peak) % 2)
    print("YES" if ans in states else "NO")

