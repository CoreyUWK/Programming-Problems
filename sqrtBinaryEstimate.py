def sqrtBinaryEsitmate(value):
    lowerLimit = 0.0
    upperLimit = value
    
    while (lowerLimit <= upperLimit): 
        guessMid = lowerLimit + (upperLimit - lowerLimit) / 2
        guessVal = guessMid ** 2
        
        print "1) Low: ", lowerLimit, "Up: ", upperLimit
        print "2) Mid: ", guessMid, "EstVal: ", guessVal
        
        if abs(value - guessVal) <= 0.0001:
            return guessMid
        elif value > guessVal:
            lowerLimit = guessMid
            print "3) Val: ", value, "Guess: ", guessVal, "Low: ", lowerLimit
        else:
            upperLimit = guessMid
            print "3) Val: ", value, "Guess: ", guessVal, "Up: ", upperLimit
    
        print ""
    
    return guessMid

val = 5.0
sqrtVal = sqrtBinaryEsitmate(val)
print("Square root of %0.4f is %0.4f" % (val, sqrtVal))