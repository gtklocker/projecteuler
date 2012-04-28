s = ''
i = 0
while len( s ) <= 1000002:
    for j in range( 0, 10 ):
        if not i:
            if j:
                s += str( j )
        else:
            s += str( i )
            s += str( j )
    i += 1

def ins( i ):
    return int( s[ i - 1 ] )

i = 1
su = 1
while i <= 1000000:
    su *= ins( i )
    i *= 10
print su
