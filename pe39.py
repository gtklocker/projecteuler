fnd = [ 0 ] * 1002
ma = 1
for p in range( 1, 1001 ):
    for a in range( 1, p ):
        for b in range( 1, p ):
            c = p - a - b
            if a < b < c and a + b + c == p and c**2 == a**2 + b**2:
                fnd[ p ] += 1
    if fnd[ p ] > fnd[ ma ]:
        ma = p

print ma
