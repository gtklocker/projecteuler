nums = range( 1, 100 )
ways = [ 1 ] + [ 0 ] * 100

for num in nums:
    for i in range( num, 101 ):
        ways[ i ] += ways[ i - num ]

print ways[ 100 ]
