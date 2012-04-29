from math import sqrt
UPPER = 1000000
SQUP = int( sqrt( UPPER ) ) + 1
prime = [ True ] * UPPER
prime[ 0 ] = False
prime[ 1 ] = False

for i in xrange( 2, SQUP ):
    j = 2
    while i * j < UPPER:
        prime[ i * j ] = False
        j += 1

def isPrime( s ):
    return len( s ) == 0 or prime[ int( s ) ]

def trunc( n ):
    n = str( n )
    if not isPrime( n ):
        return False
    l = len( n )
    for i in xrange( l ):
        if not isPrime( n[ i: ] ) or not isPrime( n[ :i ] ):
            return False
    return True

n, happ, summ = 10, 0, 0
while happ < 11:
    if trunc( n ):
        summ += n
        happ += 1
    n += 1

print summ
