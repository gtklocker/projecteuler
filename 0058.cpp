#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

int sideLength( set< int > diag ) {
    return ( ( diag.size() - 1 ) / 2 ) + 1;
}

bool isOddSquare( int n ) {
    float x;
    x = ( n + 1 ) / 2.0;
    return floor( x ) == x;
}

bool isPrime( int n ) {
    for ( int i = 2; i * i <= n; ++i ) {
        if ( n % i == 0 ) {
            return false;
        }
    }
    return n >= 2;
}

int oddSquarePrimeCnt( set< int > diag ) {
    set< int >::iterator it;
    int cnt = 0;
    for ( it = diag.begin(); it != diag.end(); ++it ) {
        if ( isPrime( *it ) && isOddSquare( *it ) ) {
            ++cnt;
        }
    }

    return cnt;
}

int main() {
    set< int > diagonals;
    diagonals.insert( 1 );
    int n = 3, smallCnt = 2, diagFound = 1;

    while ( true ) {
        diagonals.insert( n );
        n += smallCnt;
        diagFound += 1;
        if ( diagFound == 4 ) {
            smallCnt += 2;
            diagFound = 0;

            float ratio = oddSquarePrimeCnt( diagonals ) / ( float )diagonals.size();
            printf( "\r%f", ratio );
            fflush( stdout );
            if ( ratio < 0.1 ) {
                printf( "\n%d\n", sideLength( diagonals ) );
                break;
            }
        }
    }

    return 0;
}
