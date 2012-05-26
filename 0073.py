from fractions import Fraction as f
from fractions import gcd

ans = 0
os = f( 1, 2 )
ot = f( 1, 3 )
for d in xrange( 1, 12001 ):
    for n in xrange( d / 3, d ):
        if f( n, d ) >= os:
            break
        if f( n, d ) <= ot:
            continue
        if gcd( n, d ) == 1:
            ans += 1

print ans
