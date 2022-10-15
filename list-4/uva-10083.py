import math


while True:
    try:
        b, exp1, exp2 = map(int, input().split())
        
        print(f'({b}^{exp1}-1)/({b}^{exp2}-1)', end=' ')
        
        if b == 1:
            print('is not an integer with less than 100 digits.')
            continue
        
        if exp1 == exp2:
            print('1')
            continue
        
        if ((exp1-exp2)*math.log10(b)) > 99:
            print('is not an integer with less than 100 digits.')
            continue
        
        parc2 = b**exp2 - 1
        if not parc2:
            print('is not an integer with less than 100 digits.')
            continue
            
        parc1 = b**exp1 - 1
        
        if not (parc1%parc2):
            res = str(parc1//parc2)
            print(res)
        else:
            print('is not an integer with less than 100 digits.')

    except EOFError:
        break