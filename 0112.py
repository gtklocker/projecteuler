from fractions import Fraction as f
def bouncy( n ):
    n = str( n )
    case1 = not n == ''.join( sorted( n ) )
    case2 = not n == ''.join( sorted( n )[ ::-1 ] )
    return n > 100 and case1 and case2

bouncin = 0
total = 0
n = 1 
while True:
    if bouncy( n ):
        bouncin += 1
    total += 1

    #get fucking float precision, argh
    if 100 * bouncin >= 99 * total:
        break

    n += 1
print n
