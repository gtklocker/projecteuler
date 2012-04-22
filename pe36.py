def powsum( n ):
    """Return the sum of 2**n..0."""
    ret = 0
    for i in range( n, -1, -1 ):
        ret += 2 ** i
    return ret

def nearest( n ):
    """Return the minimum number of bits we need for saving the number - 1."""
    i = 7
    while powsum( i ) < n:
        i += 8
    return i

def binary( n ):
    """Return the binary intepretation of a decimal number n."""
    ret = str()
    for i in range( nearest( n ), -1, -1 ):
        if n >= 2 ** i:
            ret += '1'
            n -= 2 ** i
        else:
            ret += '0'
    try:
        return ret[ ret.index( '1' ): ]
    except ValueError:
        return '0'

def palindrome( n ):
    """Returns True if a number is palindrome and False if it's not."""
    n = str( n ) if isinstance( n, int ) else n
    return n == n[ ::-1 ]

def main():
    """Solution for Problem 36."""
    print sum( [ i for i in range( 1, 1000000 ) if palindrome( i ) and palindrome( binary( i ) ) ] )

if __name__ == '__main__':
    main()
