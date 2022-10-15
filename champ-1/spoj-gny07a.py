n = int(input())

for i in range(n):
    line = input().split(' ')
    pos = int(line[0])-1
    word = line[1]
    print(f'{i+1} ', end='')
    for i, l in enumerate(word):
        if pos != i:
            print(l, end='')
    print()
    n-=1