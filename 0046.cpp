#include <cstdio>
#include <cmath>

using namespace std;

const int primeUpper = 10000;
int prime[ primeUpper ];

bool inConj( int n ) {
    for ( int i = 0; i < primeUpper && prime[ i ] < n; ++i ) {
        float gold = sqrt( ( float )( -prime[ i ] + n ) / 2.0 );
        if ( floor( gold ) == gold ) {
            return true;
        }
    }
    return false;
}

int main() {
    int primeCnt = 0;
    prime[ primeCnt++ ] = 2;

    bool isPrime;
    for ( int i = 3; primeCnt < primeUpper; ++i ) {
        isPrime = true;
        for ( int j = 0; j < primeCnt; ++j ) {
            if ( i % prime[ j ] == 0 ) {
                isPrime = false;
                break;
            }
        }

        if ( isPrime ) {
            prime[ primeCnt++ ] = i;
        }
    }

    const int maxPrime = prime[ primeCnt - 1 ] + 1;
    bool bPrime[ maxPrime ];
    for ( int i = 0; i < primeCnt; ++i ) {
        bPrime[ prime[ i ] ] = true;
    }

    for ( int i = 33; i < maxPrime; i += 2 ) {
        if ( !bPrime[ i ] && !inConj( i ) ) {
            printf( "%d\n", i );
            break;
        }
    }

    return 0;
}
