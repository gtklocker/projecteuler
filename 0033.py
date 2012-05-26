from fractions import Fraction as f
def can_simplify( fr ):
    a = str( fr[ 0 ] )
    b = str( fr[ 1 ] )

    if '0' in a and '0' in b:
        return False
    for i in a:
        if b.find( i ) > -1:
            if len( a.replace( i, '' ) ) == 0 \
                or len( b.replace( i, '' ) ) == 0:
                continue
            newa = int( a.replace( i, '' ) )
            newb = int( b.replace( i, '' ) )
            if newb == 0:
                continue
            if f( newa, newb ) == f( fr[ 0 ], fr[ 1 ] ):
                return True
    return False

frac = f( 1, 1 )
for i in range( 10, 100 ):
    for j in range( 10, i ):
        if can_simplify( ( j, i ) ):
            frac *= f( j, i )

print frac
