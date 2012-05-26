def lenin( l ):
    ret = 0
    i = 1
    while len( str( i**l ) ) <= l:
        if len( str( i**l ) ) == l:
            ret += 1
        i += 1
    return ret

ans = 0
i = 1
while True:
    v = lenin( i )
    if v == 0:
        break
    ans += v
    i += 1

print ans
