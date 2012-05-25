f = {}
f[ 0 ] = lambda n: n * ( n + 1 ) / 2
f[ 1 ] = lambda n: n**2
f[ 2 ] = lambda n: n * ( 3 * n - 1 ) / 2
f[ 3 ] = lambda n: n * ( 2 * n - 1 )
f[ 4 ] = lambda n: n * ( 5 * n - 3 ) / 2
f[ 5 ] = lambda n: n * ( 3 * n - 2 )

def getCandidates( i ):
    ret = []
    j = 1
    res = 0
    while res < 10000:
        res = f[ i ]( j )
        if 10000 > res >= 1000:
            ret.append( ( res, i ) )
        j += 1

    return ret

allcand = []
for i in range( 6 ):
    for j in getCandidates( i ):
        allcand.append( j )

def isCyclic( n1, n2 ):
    return str( n1 )[ -2: ] == str( n2 )[ :2 ]

def arCyclic( a ):
    l = len( a )
    for i in range( l ):
        if not isCyclic( a[ i ], a[ ( i + 1 ) % l ] ):
            return False
    return True

init = []
for i in allcand:
    for j in allcand:
        if isCyclic( i[ 0 ], j[ 0 ] ) and i[ 0 ] < j[ 0 ]:
            init.append( [ i, j ] )
            break

for pair in init:
    for i in allcand:
        if len( list( set( pair ) ) ) == 6:
            bad = False
            visited = [ 0 ] * 7
            for i in range( 6 ):
                visited[ pair[ 1 ] ] += 1
                if visited[ pair[ 1 ] ] > 1:
                    bad = True
                    break
            if not bad:
                print pair
            break
        if isCyclic( pair[ 1 ][ 0 ], i[ 0 ] ) and pair[ 1 ][ 0 ] < i[ 0 ]:
            init.append( pair + [ i ] )
