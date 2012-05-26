def cycle( dividend, divisor ):
    current = 0 
    quotient = str()

    index = 0
    current = int( str( dividend )[ index ] )
    index += 1
    sav = {}
    while current > 0:
        while current < divisor:
            if index < len( str( dividend ) ):
                current = current * 10 + int( str( dividend )[ index ] )
                index += 1
            else:
                if quotient.find( '.' ) > -1:
                    current *= 10
                else:
                    quotient += '.'
            #print "Current small, made %d to fit." % current
        if current in sav:
            #print "Cycle of length %d." % ( len( quotient ) - sav[ current ] )
            return len( quotient ) - sav[ current ]
            break
        else:
            sav[ current ] = len( quotient )
        quotient += str( current / divisor )
        #print "New quotient is %s." % quotient
        current -= ( current / divisor ) * divisor
        #print "Current lessed, now %d." % current 
    return 0

ans = max( [ ( cycle( 1, x ), x ) for x in range( 1, 1000 ) ] )[ 1 ]
print ans
