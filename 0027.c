#include <stdio.h>

int prime( int n ) {
    int i;
    for ( i = 2; i * i <= n; ++i ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    return n >= 2 && 1;
}

int main() {
    int a, b, n;
    int maxprod, maxn = 0;
    for ( a = -999; a < 1000; ++a ) {
        for ( b = -999; b < 1000; ++b ) {
            for ( n = 0; prime( n * n + a * n + b ); ++n );
            if ( n > maxn ) {
                maxprod = a * b;
                maxn = n;
            }
        }
    }

    printf( "%d\n", maxprod );

    return 0;
}
