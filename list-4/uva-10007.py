while True:
    num = int(input())
    if not num: break
    
    res = 1
    for i in range(num+2, 2*num+1):
        res *= i
    print(res)