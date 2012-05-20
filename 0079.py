def findpos(key, n):
    try:
        return key.index(n)
    except:
        if n == 0:
            return -1
        return findpos(key, n - 1)

def main():
    key = []
    with open('keylog.txt') as fp:
        attempts = fp.read().split('\r\n')[:-1]

    for attempt in attempts:
        pos = []
        for ns in attempt:
            ns = int(ns)
            pos.append(findpos(key, ns))
            if not ns in key:
                key.append(ns)

        if pos[0] > pos[1]:
            key[pos[0]], key[pos[1]] = key[pos[1]], key[pos[0]]
        if pos[1] > pos[2]:
            key[pos[1]], key[pos[2]] = key[pos[2]], key[pos[1]]
        if pos[0] > pos[2]:
            key[pos[0]], key[pos[2]] = key[pos[2]], key[pos[0]]

    print ''.join([str(c) for c in key])

if __name__ == '__main__':
    main()
