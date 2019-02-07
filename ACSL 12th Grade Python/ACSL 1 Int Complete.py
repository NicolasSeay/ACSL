inputFile = open('ACSL 1 Input.txt', 'r')

for i in range(0,5):
    inputLine = inputFile.readline()
    value = int(inputLine[:2])
    pile = []
#####
    
    if inputLine[4] != 9 and inputLine[4] != 'T' and inputLine[4] != 'J' and inputLine[4] != 'Q' and inputLine[4] != 'K' and inputLine[4] != 'A':
        pile.append(int(inputLine[4]))
    else:
        pile.append(inputLine[4])

    if inputLine[7] != 9 and inputLine[7] != 'T' and inputLine[7] != 'J' and inputLine[7] != 'Q' and inputLine[7] != 'K' and inputLine[7] != 'A':
        pile.append(int(inputLine[7]))
    else:
        pile.append(inputLine[7])
        
    if inputLine[10] != 9 and inputLine[10] != 'T' and inputLine[10] != 'J' and inputLine[10] != 'Q' and inputLine[10] != 'K' and inputLine[10] != 'A':
        pile.append(int(inputLine[10]))
    else:
        pile.append(inputLine[10])

    if inputLine[13] != 9 and inputLine[13] != 'T' and inputLine[13] != 'J' and inputLine[13] != 'Q' and inputLine[13] != 'K' and inputLine[13] != 'A':
        pile.append(int(inputLine[13]))
    else:
        pile.append(inputLine[13])

    if inputLine[16] != 9 and inputLine[16] != 'T' and inputLine[16] != 'J' and inputLine[16] != 'Q' and inputLine[16] != 'K' and inputLine[16] != 'A':
        pile.append(int(inputLine[16]))
    else:
        pile.append(inputLine[16])
        
    if inputLine[19] != 9 and inputLine[19] != 'T' and inputLine[19] != 'J' and inputLine[19] != 'Q' and inputLine[19] != 'K' and inputLine[19] != 'A':
        pile.append(int(inputLine[19]))
    else:
        pile.append(inputLine[19])

    if inputLine[22] != 9 and inputLine[22] != 'T' and inputLine[22] != 'J' and inputLine[22] != 'Q' and inputLine[22] != 'K' and inputLine[22] != 'A':
        pile.append(int(inputLine[22]))
    else:
        pile.append(inputLine[22])

    if inputLine[25] != 9 and inputLine[25] != 'T' and inputLine[25] != 'J' and inputLine[25] != 'Q' and inputLine[25] != 'K' and inputLine[25] != 'A':
        pile.append(int(inputLine[25]))
    else:
        pile.append(inputLine[25])

    if inputLine[28] != 9 and inputLine[28] != 'T' and inputLine[28] != 'J' and inputLine[28] != 'Q' and inputLine[28] != 'K' and inputLine[28] != 'A':
        pile.append(int(inputLine[28]))
    else:
        pile.append(inputLine[28])

    if inputLine[31] != 9 and inputLine[31] != 'T' and inputLine[31] != 'J' and inputLine[31] != 'Q' and inputLine[31] != 'K' and inputLine[31] != 'A':
        pile.append(int(inputLine[31]))
    else:
        pile.append(inputLine[31])


#####

    for x in range(0,10):
        if pile[x]=='T':     
            pile[x] = -10
        elif pile[x]=='J':
            pile[x] = 11
        elif pile[x]=='Q':
            pile[x] = 12
        elif pile[x]=='K':
            pile[x] = 13
        elif pile[x]=='A':
            pile[x] = 14
        elif pile[x]=='9':
            pile[x] = 0
    
    
    counter = 0
    
    while value < 100:
        decision = pile[0]
        posRemove = 0
        if counter%2 == 0:
            if abs(pile[1]) > abs(decision):
                decision = pile[1]
                posRemove = 1
            if abs(pile[2]) > abs(decision):
                decision = pile[2]
                posRemove = 2
            if decision == 9:
                decision = 0
            if value >=86 and decision == 14:
                decision = 1
            value += decision
            pile.remove(pile[posRemove])
            
        else:
            if pile[3] == 9:
                pile[3] = 0
            if value >= 86 and pile[3] == 14:
                pile[3] = 1
            value += pile[3]
            pile.remove(pile[3])
        
        counter+=1

    if counter%2 == 0:
        print value, ", player"
    else:
        print value, ", dealer"
    print ""
