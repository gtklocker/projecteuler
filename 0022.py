import fileinput

names = fileinput.input( 'input/pe22.txt' )[ 0 ].split( ',' )
n = len( names )
for i in xrange( n ):
    names[ i ] = names[ i ][ 1:-1 ]

names.sort()

def val( ch ):
    return ord( ch ) - 64
def strval( st ):
    ret = 0
    for i in st:
        ret += val( i )
    return ret

total = 0
for i in xrange( n ):
    total += ( i + 1 ) * strval( names[ i ] )
print total
