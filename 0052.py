def ok( n ):
    dig = sorted( str( n ) )
    for i in range( 2, 6 + 1 ):
        if sorted( str( i * n ) ) != dig:
            return False
    return True

i = 1
while True:
    if ok( i ):
        print i
        break
    i += 1
