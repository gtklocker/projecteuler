#include <cstdio>
#include <algorithm>

using namespace std;

const int primeUp = 10000;
bool isPrime[ primeUp ];

int fullNum( int a[] ) {
    int ret = 0;
    for ( int i = 0; i < 4; ++i ) {
        ret *= 10;
        ret += a[ i ];
    }
    return ret;
}

int main() {
    for ( int i = 2; i < primeUp; ++i ) {
        isPrime[ i ] = true;
    }
    for ( int i = 2; i * i < primeUp; ++i ) {
        for ( int j = i * i; j < primeUp; j += i ) {
            isPrime[ j ] = false;
        }
    }

    for ( int i = 1; i < 10; ++i ) {
        for ( int j = 0; j < 10; ++j ) {
            for ( int k = 0; k < 10; ++k ) {
                for ( int l = 0; l < 10; ++l ) {
                    int e[] = { i, j, k, l };
                    int orig = fullNum( e );

                    bool first = true;
                    int diff;
                    while ( next_permutation( e, e + 4 ) ) {
                        int nextN = fullNum( e );
                        if ( nextN - orig > 0 && isPrime[ nextN ] && first ) {
                            diff = nextN - orig;
                            first = false;
                            continue;
                        }
                        if ( !first && isPrime[ nextN ] && nextN - ( 2 * diff ) == orig ) {
                            printf( "%d%d%d\n", orig, nextN - diff, nextN );
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
