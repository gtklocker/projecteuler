def rev( n ):
    return int( str( n )[ ::-1 ] )
def pal( n ):
    return str( n ) == str( n )[ ::-1 ]
def nonlych( n ):
    if n < 196:
        return True
    for it in range( 0, 50 ):
        n += rev( n )
        if pal( n ):
            return True
    return False
def lych( n ):
    return not nonlych( n )
print sum( [ lych( x ) for x in range( 10000 ) ] )
