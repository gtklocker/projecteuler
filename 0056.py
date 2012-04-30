m = -1000
for a in range( 1, 100 ):
    for b in range( 1, 100 ):
        m = max( m, sum( [ int( x ) for x in str( a**b ) ] ) )
print m
