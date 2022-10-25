first = True
while (True):
    n = list(map(int, input().split()))
    if not n[0]:
        break

    if first:
        first = False
    else:
        print()

    comb = []

    for i in range(2**n[0]):
        b_mask = bin(i).split('b')[1].rjust(n[0], '0')

        if b_mask.count('1') != 6:
            continue

        comb.append([i for i, d in enumerate(b_mask) if d == '1'])

    comb.reverse()
    for i in range(len(comb)):
        for j in range(6):
            print(n[comb[i][j]+1], end=' ') if j < 5 else print(n[comb[i][j]+1])
