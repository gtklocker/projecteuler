from fileinput import input
from math import sqrt

words = [ word[ 1:-1 ] for word in input( 'input/pe42.txt' )[ 0 ].split( ',' ) ]
sord = lambda s: sum( [ ord( ch ) - 64 for ch in s ] )
triangle = lambda n: ( ( sqrt( 1 + 8 * n ) + 1 ) / 2 ).is_integer()
print sum( [ triangle( sord( word ) ) for word in words ] )
