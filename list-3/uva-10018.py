nTests = int(input())
count  = 0
while nTests:
    n = input()
    n_rev = n[::-1]
    
    while True:
        count += 1
        
        n = int(n)
        n_rev = int(n_rev)
        
        n = str(n + n_rev)
        n_rev = n[::-1]
        if n == n_rev:
            print(count, n)
            break
        
    count = 0
    nTests -= 1