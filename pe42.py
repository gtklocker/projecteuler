import fileinput

words = fileinput.input( 'input/pe42.txt' )[ 0 ].split( ',' )
n = len( words )
upper = 0
for i in xrange( n ):
    words[ i ] = words[ i ][ 1:-1 ]
    upper = max( upper, len( words[ i ] ) )
upper *= 26
upper += 1

tri = set()
for i in xrange( 1, upper ):
    tri.add( ( i * ( i + 1 ) ) / 2 )

def strOrd( s ):
    return sum( [ ord( ch ) - 64 for ch in s ] )

def isTri( s ):
    x = strOrd( s )
    return x in tri

found = 0
for i in xrange( n ):
    if isTri( words[ i ] ):
        found += 1
print found
