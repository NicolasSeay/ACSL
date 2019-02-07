inputFile = open('ACSL 4 Input.txt', 'r')

def add(bigArrayL, bigArrayC, history, line):
    line = line[line.find(' ')+1 : len(line)-1]
    newLine = line
    for x in range(len(line)):
        if line[x] == ' ':
            newLine = line.replace(" ", "")
    for x in newLine:
        addLetter(bigArrayL, bigArrayC, history, x)
    
def addLetter(bigArrayL, bigArrayC, history, letter):
    inList = 0
    counter = 0
    if len(bigArrayL) == 0:
        bigArrayL += [letter]
        bigArrayC += [1]
        history.append((bigArrayL[:]))
    else:
        for x in range(len(bigArrayL)):
            if letter in bigArrayL[x]:  #if its in the list, adds to bigArrayC
                bigArrayC[x] += 1
                inList = 1
        if inList == 0:
            for x in range(len(bigArrayL)):
                if letter < bigArrayL[x]:
                    bigArrayL.insert(counter, letter)
                    bigArrayC.insert(counter, 1)
                    history.append((bigArrayL[:]))
                    break
                elif x == len(bigArrayL)-1:
                    bigArrayL.insert(len(bigArrayL), letter)
                    bigArrayC.insert(len(bigArrayL), 1)
                    history.append((bigArrayL[:]))
                    break
                counter += 1

def delete(bigArrayL, bigArrayC, history, line):
    line = line[line.find(' ')+1 : len(line)-1]
    for x in line:
        deleteLetter(bigArrayL, bigArrayC, history, x)

def deleteLetter(bigArrayL, bigArrayC, history, letter):
    inList = 0
    counter = 0
    for x in range(len(bigArrayL)):
        if letter in bigArrayL[x]:
            if bigArrayC[x] == 1:
                del bigArrayL[x]
                del bigArrayC[x]
                history.append((bigArrayL[:]))
                break
            else:
                bigArrayC[x] = bigArrayC[x] - 1

def report(history, line):
    value = int(line[line.find(" ")+1:len(line)])
    events = ""
    for x in history:
        if len(x) >= value:
            if len(events) == 0:
                events += x[value-1]
            else:
                if x[value-1] != events[len(events)-1]:
                    events += x[value-1]
    print events
    print ""


#main
lines = inputFile.readlines()
bigArrayL = []
bigArrayC = []
history = []
for f in range(len(lines)):
    if "RESET" in lines[f]:
        bigArrayL = []
        bigArrayC = []
        history = []
        add(bigArrayL, bigArrayC, history, lines[f].upper())
    elif "ADD" in lines[f]:
        add(bigArrayL, bigArrayC, history, lines[f].upper())
    elif "DELETE" in lines[f]:
        delete(bigArrayL, bigArrayC, history, lines[f].upper())
    elif "REPORT" in lines[f]:
        report(history, lines[f].upper())
    #print bigArrayL
    #print bigArrayC
    #print history
#print bigArrayL
#print bigArrayC
#print history
