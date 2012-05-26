def digSum( n ):
    return sum( [ int( x ) for x in str( n ) ] )

sav = []
i = 1
while len( sav ) <= 100:
    for j in range( 1, i ):
        p = i**j
        if len( str( p ) ) < 2:
            continue

        d = digSum( p )
        if d == i:
            sav.append( p )

    i += 1
print sorted( sav )[ 29 ]
