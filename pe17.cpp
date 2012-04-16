#include <cstdio>

using namespace std;

char let[ 1001 ];

int num( int n ) {
    if ( n <= 20 ) {
        return let[ n ];
    }

    int ret = 0;
    if ( n < 100 ) {
        ret += let[ n % 10 ];

        n /= 10;
        ret += let[ n * 10 ];
        return ret;
    }

    int haveAND = 3;
    if ( n < 1000 ) {
        //printf( "Added %d\n", n % 100 );
        if ( n % 100 != 0 ) {
            ret += num( n % 100 );
        }
        else {
            haveAND = 0;
        }

        n /= 100;
        //printf( "Added %d + %d + %d\n", n, 100, haveAND );
        ret += num( n ) + let[ 100 ] + haveAND;
        return ret;
    }

    if ( n == 1000 ) {
        return let[ n ];
    }
}

int main() {
    let[ 0 ] = 0;
    let[ 1 ] = 3;
    let[ 2 ] = 3;
    let[ 3 ] = 5;
    let[ 4 ] = 4;
    let[ 5 ] = 4;
    let[ 6 ] = 3;
    let[ 7 ] = 5;
    let[ 8 ] = 5;
    let[ 9 ] = 4;
    let[ 10 ] = 3;
    let[ 11 ] = 6;
    let[ 12 ] = 6;
    let[ 13 ] = 8;
    let[ 14 ] = 8;
    let[ 15 ] = 7;
    let[ 16 ] = 7;
    let[ 17 ] = 9;
    let[ 18 ] = 8;
    let[ 19 ] = 8;
    let[ 20 ] = 6;
    let[ 30 ] = 6;
    let[ 40 ] = 5;
    let[ 50 ] = 5;
    let[ 60 ] = 5;
    let[ 70 ] = 7;
    let[ 80 ] = 6;
    let[ 90 ] = 6;
    let[ 100 ] = 7;
    let[ 1000 ] = 11;

    int sum = 0;
    for ( int i = 1; i <= 1000; ++i ) {
        sum += num( i );
    }
    printf( "%d\n", sum );

    return 0;
}
