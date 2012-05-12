from math import log10 as lg
def expg( a, b ):
    """
    Returns the largest ( base, exponent ) tuple from a, b.
    This solution utilizes logarithmic properties to simplify the calculations.

    Consider two base-exponent pairs that we want to compare, say a**b and c**d:
        a**b > c**d
        ( 10**loga )**b > ( 10**logc )**d
        10**( loga * b ) > 10**( logc * d )

    Now we have the same base, and we can simplify our comparison:
        loga * b > logc * d

    """
    return a if lg( a[ 0 ] )*a[ 1 ] > lg( b[ 0 ] )*b[ 1 ] else b

with open( 'base_exp.txt', 'r' ) as f:
    lines = f.read().split( '\r\n' )
    cur = ( 1, 1 )
    maxline = 1
    for i in range( len( lines ) ):
        new = tuple( [ int( x ) for x in lines[ i ].split( ',' ) ] )
        if expg( cur, new ) != cur:
            cur = new
            maxline = i + 1

print maxline
