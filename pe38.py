def pandigital( n ):
    n = str( n )
    sh = []
    for i in range( 1, len( n ) + 1 ):
        sh += str( i )
    return sorted( n ) == sh

def panmult( n ):
    con = ''
    i = 1
    while len( con ) < 9:
        con += str( n * i )
        i += 1
    return [ con, pandigital( int( con ) ) ]

#Pandigital testcases
assert pandigital( 12 ) == True
assert pandigital( 1234 ) == True
assert pandigital( 987654321 ) == True
assert pandigital( 987654322 ) == False
assert panmult( 192 )[ 1 ] == True
assert panmult( 193 )[ 1 ] == False

i = 192
while i <= 100000:
    p = panmult( i )
    if p[ 1 ]:
        print p[ 0 ]
    i += 1
