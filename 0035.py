from math import ceil, sqrt

def rotate(n):
    "Rotate n according to the problem statement"
    n = str(n)
    ret = []
    for i in range(len(n)):
        ret.append(int(n[i] + n[i + 1:] + n[:i]))
    return ret

def main():
    """Solution for Problem 35:
    This code is different from anything else on this repo as far as coding
    style goes and that's because I tried following the Google Python Coding
    Style: http://google-styleguide.googlecode.com/svn/trunk/pyguide.html

    """
    upper = 1000000

    #When generating primes, we need to know the upper bound which is defined by
    #our maximum rotation
    max_perm = max(max(rotate(upper)), max(rotate(upper - 1)))

    #Array that will tell whether a number is prime or not
    prime = [True] * (max_perm + 1)
    prime[0] = False
    prime[1] = False

    for i in range(2, int(ceil(sqrt(max_perm + 1))) + 1):
        for j in range(2, max_perm + 1):
            if i * j >= max_perm:
                break
            prime[i * j] = False

    found = [] #List of all the circular primes
    for i in range(2, upper):
        if prime[i]:
            try:
                for r in rotate(i):
                    if not prime[r]:
                        raise Exception
                found.append(i)
            except:
                continue
    print len(found)

if __name__ == '__main__':
    main()
