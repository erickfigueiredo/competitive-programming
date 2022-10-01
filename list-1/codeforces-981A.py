word = input()

aux = ''
maxNonPalindrome = 0

for i in range(len(word)):
    for j in range(i, len(word)):
        aux += word[j]
        if(aux != aux[::-1] and len(aux) > maxNonPalindrome):
            maxNonPalindrome = len(aux)
    aux = ''
    
print(maxNonPalindrome)
