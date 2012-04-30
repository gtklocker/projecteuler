from math import factorial as f
def c( n, r ):
    return f( n ) / ( f( r ) * f( n - r ) )

found = 0
for i in range( 23, 100 + 1 ):
    for j in range( 1, i + 1 ):
        if c( i, j ) > 1000000:
            found += 1
print found
