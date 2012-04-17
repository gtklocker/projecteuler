pows = set()
for a in xrange( 2, 101 ):
    for b in xrange( 2, 101 ):
        pows.add( a ** b )
print len( pows )
