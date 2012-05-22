#include <cstdio>
#include <cmath>

using namespace std;

const int N = 150000;
int prime[ N ];

int primeFactors( int n ) {
    int factors = 0;
    for ( int i = 0; n != 1 && i < N; ++i ) {
        if ( n % prime[ i ] == 0 ) {
            ++factors;
            while ( n % prime[ i ] == 0 ) {
                n /= prime[ i ];
            }
        }
    }

    return factors;
}

int main() {
    prime[ 0 ] = 2;
    int primeCnt = 1;

    for ( int i = 3; primeCnt < N; ++i ) {
        bool isPrime = true;
        for ( int j = 0; j < primeCnt; ++j ) {
            if ( prime[ j ] * prime[ j ] > i ) {
                break;
            }
            if ( i % prime[ j ] == 0 ) {
                isPrime = false;
                break;
            }
        }
        if ( isPrime ) {
            prime[ primeCnt++ ] = i;
        }
    }

    for ( int i = 2; i < N; ++i ) {
        if ( primeFactors( i ) == 4 &&
            primeFactors( i + 1 ) == 4 &&
            primeFactors( i + 2 ) == 4 &&
            primeFactors( i + 3 ) == 4 ) {
            printf( "%d\n", i );
            break;
        }
    }

    return 0;
}
