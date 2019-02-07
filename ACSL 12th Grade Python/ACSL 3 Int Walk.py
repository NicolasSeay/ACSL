#input/board creation
inputFile = open('S://Public/CS/check/intest.txt', 'r')
input = inputFile.readline()
row1 = []
row2 = []
row3 = []
row4 = []
row5 = []
row6 = []
row7 = []
row8 = []

srow1 = input[:input.find(' ')]
input = input[len(srow1)+1:]
srow1 = bin(int(srow1, 16))[2:].zfill(8)


srow2 = input[:input.find(' ')]
input = input[len(srow2)+1:]
srow2 = bin(int(srow2, 16))[2:].zfill(8)
for x in range(8):
    row2.append(int(srow2[x]))

srow3 = input[:input.find(' ')]
input = input[len(srow3)+1:]
srow3 = bin(int(srow3, 16))[2:].zfill(8)
for x in range(8):
    row3.append(int(srow3[x]))

srow4 = input[:input.find(' ')]
input = input[len(srow4)+1:]
srow4 = bin(int(srow4, 16))[2:].zfill(8)
for x in range(8):
    row4.append(int(srow4[x]))

srow5 = input[:input.find(' ')]
input = input[len(srow5)+1:]
srow5 = bin(int(srow5, 16))[2:].zfill(8)
for x in range(8):
    row5.append(int(srow5[x]))

srow6 = input[:input.find(' ')]
input = input[len(srow6)+1:]
srow6 = bin(int(srow6, 16))[2:].zfill(8)
for x in range(8):
    row6.append(int(srow6[x]))

srow7 = input[:input.find(' ')]
input = input[len(srow7)+1:]
srow7 = bin(int(srow7, 16))[2:].zfill(8)
for x in range(8):
    row7.append(int(srow7[x]))

srow8 = input
input = input[len(srow8)+1:]
srow8 = bin(int(srow8, 16))[2:].zfill(8)
for x in range(8):
    row8.append(int(srow8[x]))


ary = []

#print srow2


for x in range(5):
    row1 = []
    row2 = []
    row3 = []
    row4 = []
    row5 = []
    row6 = []
    row7 = []
    row8 = []
    for x in range(8):
        row1.append(int(srow1[x]))
    for x in range(8):
        row2.append(int(srow2[x]))
    for x in range(8):
        row3.append(int(srow3[x]))
    for x in range(8):
        row4.append(int(srow4[x]))
    for x in range(8):
        row5.append(int(srow5[x]))
    for x in range(8):
        row6.append(int(srow6[x]))
    for x in range(8):
        row7.append(int(srow7[x]))
    for x in range(8):
        row8.append(int(srow8[x]))
    ary.append(row1)
    ary.append(row2)
    ary.append(row3)
    ary.append(row4)
    ary.append(row5)
    ary.append(row6)
    ary.append(row7)
    ary.append(row8)

##    for x in range(8):
##        for y in range(8):
##            print ary[x][y],
##            if y == 7:
##                print ""
    
    input = inputFile.readline()
    print input
    crow = int(input[0])-1 #current row (0-7)
    ccol = int(input[2])-1 #current column (0-7)
    direction =  input[4]
    timer = int(input[6])
    
    for x in range(timer):
        if direction == 'L':
            if ary[crow][ccol] == 0:
                ccol+=1
            else:
                ary[crow][ccol] = 0
                direction = 'B'
                crow-=1
            if crow >= 8:
                crow = 0
            if ccol >= 8:
                ccol = 0
        elif direction == 'R':
            if ary[crow][ccol] == 0:
                ccol-=1
            else:
                ary[crow][ccol] = 0
                direction = 'A'
                crow+=1
            if crow >= 8:
                crow = 0
            if ccol >= 8:
                ccol = 0
        elif direction == 'B':
            if ary[crow][ccol] == 0:
                crow-=1
            else:
                ary[crow][ccol] = 0
                direction = 'R'
                ccol-=1
            if crow >= 8:
                crow = 0
            if ccol >= 8:
                ccol = 0
        elif direction == 'A':
            if ary[crow][ccol] == 0:
                crow+=1
            else:
                ary[crow][ccol] = 0
                direction = 'L'
                ccol+=1
            if crow >= 8:
                crow = 0
            if ccol >= 8:
                ccol = 0
        
        #print direction
    print " ", crow+1, ccol+1
    print ""
    
    del ary[0]
    del ary[0]
    del ary[0]
    del ary[0]
    del ary[0]
    del ary[0]
    del ary[0]
    del ary[0]
    del row1
    del row2
    del row3
    del row4
    del row5
    del row6
    del row7
    del row8
