def nex( n ):
    return sum( [ int( x )**2 for x in str( n ) ] )

c = {}
def chain( n ):
    cur = n
    seen = []
    while cur not in seen:
        if cur == 1 or cur == 89:
            c[ n ] = cur
            return c[ n ]
        if cur in c:
            return c[ cur ]
        seen.append( cur )
        cur = nex( cur )
    c[ n ] = cur
    return c[ n ]

assert chain( 44 ) == 1
assert chain( 85 ) == 89

print sum( [ chain( x ) == 89 for x in range( 1, 10000000 ) ] )
