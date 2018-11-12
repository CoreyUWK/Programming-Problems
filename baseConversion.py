# Convert int hex value to string value
def intToHexString(intHex):
    if intHex < 10:
        return intHex
    if intHex == 10:
        return "A"
    elif intHex == 11:
        return "B"
    elif intHex == 12:
        return "C"
    elif intHex == 13:
        return "D"
    elif intHex == 14:
        return "E"
    elif intHex == 15:
        return "F"
    else:
        print "Conversion Error to Hex"
        return -1
    

# Convert from b1 to base10
def toBase10(b1, b1StringVal):
    if b1 != 10:
        newVal = 0
        for i in range(len(b1StringVal)):
           newVal += int(b1StringVal[-i-1]) * b1 ** i
        return str(newVal)
    else:    
        return b1StringVal


# Convert from base10 to b2
def base10ToOther(b2, base10String):
    # Convert from base10 to b2
    b2String = ""
    quotient = int(base10String)
    remainder = 0
    while quotient > 0:
        #print "quotient: %d remainder: %s" % (quotient, str(remainder))
        tmpQuotient = int(quotient / b2)
        remainder = quotient % b2
        quotient = tmpQuotient
        
        if 16 == b2 and remainder > 9:
           remainder = intToHexString(remainder)
        b2String += str(remainder)
    #print "quotient: %d remainder: %s" % (quotient, str(remainder))

    return b2String[::-1]


# Convert string value from base b1 to base b2
def baseConv(b1, b1StringVal, b2):
    if b1 == b2:
        return b1StringVal

    # Convert to base10
    base10String = toBase10(b1, b1StringVal)

    # if b2 = base10 then done
    if 10 == b2:
       return base10String
           
    # else convert from base10 to b2
    return base10ToOther(b2, base10String)

print baseConv(10, "13", 2)
print baseConv(10, "13", 10)
print baseConv(10, "13", 8)
print baseConv(10, "13", 16)
print baseConv(10, "174", 16)
print baseConv(2, "1010", 10)
print baseConv(2, "1010", 8)
print baseConv(2, "1010", 16)

