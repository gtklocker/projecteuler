from fileinput import input
from math import sqrt

#Remove quotes from original input
words = [ word[ 1:-1 ] for word in input( 'input/pe42.txt' )[ 0 ].split( ',' ) ]

#String ord (sum of all characters' ords)
sord = lambda s: sum( [ ord( ch ) - 64 for ch in s ] )

#Triangle is any number that evaluates ( sqrt( 1 + 8 * n ) + 1 ) / 2
isint = lambda n: int( n ) == n
triangle = lambda n: isint( ( sqrt( 1 + 8 * n ) + 1 ) / 2 )

print sum( [ triangle( sord( word ) ) for word in words ] )
