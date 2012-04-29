#include <cstdio>
#include <algorithm>

using namespace std;
typedef unsigned long long int llu;

int three( int a, int b, int c ) {
    return ( a * 10 + b ) * 10 + c;
}

llu form( int a[] ) {
    llu ret = 0;
    for ( int i = 0; i < 10; ++i ) {
        ret *= 10;
        ret += a[ i ];
    }
    return ret;
}

int main() {
    llu SUM = 0;
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int div[] = { 2, 3, 5, 7, 11, 13, 17 };
    do {
        for ( int i = 1; i <= 7; ++i ) {
            int t = three( a[ i ], a[ i + 1 ], a[ i + 2 ] );
            if ( t % div[ i - 1 ] != 0 ) {
                break;
            }
            if ( i == 7 ) {
                SUM += form( a );
            }
        }
    } while ( next_permutation( a, a + 10 ) );

    printf( "%llu\n", SUM );

    return 0;
}
