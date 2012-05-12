#include <cstdio>
#include <set>

using namespace std;

#define ii pair< int, int >

int main() {
    const int N = 1000000;
    bool primes[ N ] = { false };
    for ( int i = 2; i < N; ++i ) {
        primes[ i ] = true;
    }

    for ( int i = 2; i * i < N; ++i ) {
        for ( int j = 2 * i; j < N; j += i ) {
            primes[ j ] = false;
        }
    }

    int upper;
    int isum = 0;
    for ( int i = 0; ; ++i ) {
        if ( primes[ i ] ) {
            isum += i;
        }
        if ( isum + i >= N ) {
            upper = i;
            break;
        }
    }

    set< ii > rec;
    for ( int tr = 0, tsum = isum, i = upper; i >= 2; --i ) {
        if ( primes[ tsum ] ) {
            rec.insert( ii( tr, tsum ) );
            break;
        }
        if ( primes[ i ] ) {
            tsum -= i;
            tr++;
        }
    }
    for ( int tr = 0, tsum = isum, i = 2; i <= upper; ++i ) {
        if ( primes[ tsum ] ) {
            rec.insert( ii( tr, tsum ) );
            break;
        }
        if ( primes[ i ] ) {
            tsum -= i;
            tr++;
        }
    }

    printf( "%d\n", rec.begin()->second );

    return 0;
}
