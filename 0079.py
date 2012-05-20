key = []

def findpos(n):
    try:
        return key.index(n)
    except:
        if n == 0:
            return -1
        return findpos(n - 1)

with open('keylog.txt') as fp:
    attempts = fp.read().split('\r\n')[:-1]

for attempt in attempts:
    for ns in attempt:
        ns = int(ns)
        if not ns in key:
            key.append(ns)

    pos_a = findpos(int(attempt[0]))
    pos_b = findpos(int(attempt[1]))
    pos_c = findpos(int(attempt[2]))
    if pos_a > pos_b:
        key[pos_a], key[pos_b] = key[pos_b], key[pos_a]
    if pos_b > pos_c:
        key[pos_b], key[pos_c] = key[pos_c], key[pos_b]
    if pos_a > pos_c:
        key[pos_a], key[pos_c] = key[pos_c], key[pos_a]

print ''.join([str(c) for c in key])
