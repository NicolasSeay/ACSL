inputFile = open('ACSL 2 Input.txt', 'r')

for i in range(0,5):
    inputLine = inputFile.readline()
    pacount = 0
    brcount = 0
    MissingChar = ""
    output = []
    symbols = "+-/*"
    nums = "0123456789"
    if '(' in inputLine:
        pacount += 1
    if ')' in inputLine:
        pacount += 1
    if '[' in inputLine:
        brcount += 1
    if ']' in inputLine:
        brcount += 1

    if pacount == 1:
        if '(' in inputLine:
            MissingChar = ')'
        if ')' in inputLine:
            MissingChar = '('
    elif brcount == 1:
        if '[' in inputLine:
            MissingChar = ']'
        if ']' in inputLine:
            MissingChar = '['
    
    if pacount == 0 or brcount == 0:#///COMPLETE
        if MissingChar == '(':    #missing piece is a STARTING symbol
            substr = inputLine[:inputLine.find(')')+1]
            for x in range(len(substr)):
                if substr[x] in nums and substr[x+1] in symbols and x < len(substr)-2:
                    output.append(x+1)  # <---no need to hardcode any outputs
        elif MissingChar == ')':    #missing piece is an ENDING symbol
            substr = inputLine[inputLine.find('('):]
            cutoff = len(inputLine[:inputLine.find('(')])
            for x in range(len(substr)):
                if substr[x-1] in nums and substr[x] in symbols and x > 2:
                    output.append(x+1+cutoff)
            output.append(len(substr)+cutoff) #<--- need to hardcode last spot ONLY FOR ENDING SYMBOLS
    else:
        if MissingChar == '(':#COMPLETE can handle multi-digit numbers
            substr = inputLine[inputLine.find('[')+1:inputLine.find(')')+1]
            cutoff = len(inputLine[:inputLine.find('[')])+1
            backcount = 0#for multi-digit numbers
            for x in range(len(substr)):
                if substr[x] in nums and substr[x+1] in symbols and x < len(substr)-2:
                    if substr[x-1] in nums:
                        backcount -= 1
                        if substr[x-2] in nums:
                            backcount -= 1
                    output.append(x+1+cutoff+backcount)
                    backcount = 0 
        elif MissingChar == ')':#COMPLETE can handle multi-digit numbers
            substr = inputLine[inputLine.find('(')+1:inputLine.find(']')+1]
            cutoff = len(inputLine[:inputLine.find('(')])+1
            backcount = 0#for multi-digit numbers
            symbolcount = 0
            for x in range(len(substr)):
                if substr[x-1] in nums and substr[x] in symbols and x > 2:
                    if symbolcount > 0:
                        output.append(x+1+cutoff)
                if substr[x] in symbols:
                    symbolcount += 1
            output.append(len(substr)+cutoff)
        elif MissingChar == '[':#COMPLETE can handle multi-digit numbers
            substr = inputLine[:inputLine.find('(')+1]
            backcount = 0#for multi-digit numbers
            for x in range(len(substr)):
                if substr[x] in nums and substr[x+1] in symbols and x < len(substr)-2:
                    if substr[x-1] in nums:
                        backcount -= 1
                        if substr[x-2] in nums:
                            backcount -= 1
                    output.append(x+1+backcount)
                    backcount = 0
            output.append(len(substr))
        elif MissingChar == ']':#COMPLETE can handle multi-digit numbers
            substr = inputLine[inputLine.find(')')+1:]
            cutoff = len(inputLine[:inputLine.find(')')])+1
            backcount = 0#for multi-digit numbers
            output.append(len(substr[0])+cutoff)
            for x in range(len(substr)):
                if substr[x-1] in nums and substr[x] in symbols:
                    output.append(x+1+cutoff)
            output.append(len(substr)+cutoff)

    print output
    print ""
    print ""
