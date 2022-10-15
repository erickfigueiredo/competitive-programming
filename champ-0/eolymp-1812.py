while(True):
    votos = input()
    if votos == '#': break

    cont = {
        'Y':0,
        'N':0,
        'P':0,
        'A':0
        }
    for i in votos:
        cont[i]+=1

    if(cont['A'] >= len(votos)/2):
        print('need quorum')
    elif(cont['Y'] >= cont['N']):
        if(cont['Y'] > cont['N']):
            print('yes')
        else:
            print('tie')
    else:
        print('no')

