t = int(input())

for _ in range(t):
    a,b,c,d = (int(a) for a in input().split(" "))
    a_to_win = min(b,d)
    b_to_win = min(a,c)
    if a_to_win > b_to_win:
        print("Flower")
    else:
        print("Gellyfish")