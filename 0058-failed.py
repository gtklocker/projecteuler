from gmpy import is_prime

def is_oddsq( n ):
    x = ( n + 1 ) / 2.0
    return x.is_integer()

n = 2
small = 2
diag = 0
moar = 1
diagsum = 1.0
primesum = 0.0
while True:
    diagsum += n
    if is_prime( n ) and is_oddsq( n ):
        primesum += n

    n += small
    diag += 1
    if diag == 4:
        diag = 0
        small += 2
        moar += 1
        if primesum / diagsum < .1:
            break
print moar
