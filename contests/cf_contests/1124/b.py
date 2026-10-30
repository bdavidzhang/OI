def next(number):
    return sum(int(d) ** 2 for d in str(number))


t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    cnts = {}

    for number in nums:
        for _ in range(1000):
            number = next(number)
        cnts[number] = cnts.get(number, 0) + 1

    ans = sum(cnt * (cnt - 1) // 2 for cnt in cnts.values())
    print(ans)



