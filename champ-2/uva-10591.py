n = int(input())

for i in range(n):
    num = input()
    
    print(f'Case #{i+1}: {num} is a', end='')
    s = set()
    s.add(num)
    while num != '1':
        acc = 0
        for d in num:
            acc += int(d)**2
        
        num = str(acc)
        if num in s: break
        s.add(num)

    
    if num == '1':
        print(' Happy number.')
    else:
        print('n Unhappy number.')
