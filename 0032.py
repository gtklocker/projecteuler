def isPandig( n ):
    return sorted( n ) == [ str( x ) for x in range( 1, 10 ) ]

found = set()
for i in xrange( 1, 9001 ):
    for j in xrange( 1, 9001 ):
        al = str( i ) + str( j ) + str( i * j )
        if len( al ) > 9:
            break
        if len( al ) == 9:
            if isPandig( al ):
                found.add( i * j )
print sum( found )
