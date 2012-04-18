from fileinput import input

words = input( 'input/pe42.txt' )[ 0 ].split( ',' )
words = [ word[ 1:-1 ] for word in words ] #remove quotes

#Upper bound for triangle numbers is 26 times the maximum length of any word
upper = max( [ len( word ) for word in words ] ) * 26 + 1

#Triangles will contain all the triangle numbers from first to upper-th
triangles = set( [ x * ( x + 1 ) / 2 for x in xrange( 1, upper ) ] )

#String ord (sum of all character's ords)
sord = lambda s: sum( [ ord( ch ) - 64 for ch in s ] )

print sum( [ sord( word ) in triangles for word in words ] )
