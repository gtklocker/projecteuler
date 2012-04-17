def isPower( n ):
    return n == sum( [ int( x )**5 for x in str( n ) ] )
print sum( filter( isPower, range( 2, 999999 ) ) )
