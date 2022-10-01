while True:
    n1, n2 = input().split(' ')
    n1 = n1[::-1]
    n2 = n2[::-1]

    
    if(not int(n1) and not int(n2)): 
        break
    
    if len(n1) > len(n2):
        start = len(n2)
        end = len(n1)
        for _ in range(start, end):
            n2+='0'
            
    elif len(n1) < len(n2):
        start = len(n1)
        end = len(n2)
        for _ in range(start, end):
            n1+='0'
    
    carries = 0
    prev_carry = False
    for d1, d2 in zip(n1, n2):
        d1 = int(d1)
        d2 = int(d2)
        
        if(prev_carry):
            d1+=1
            prev_carry = False
        
        if(d1+d2) > 9: 
            carries += 1
            prev_carry = True
            
    if not carries:
        print('No carry operation.')
    elif carries == 1:
        print('1 carry operation.')
    else:
        print(f'{carries} carry operations.')
