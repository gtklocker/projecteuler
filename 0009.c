#include <stdio.h>
#include <math.h>

int main( void ) {
    unsigned a, b, c;

    for ( b = 1; b < 1000; ++b ) {
        a = ( 500000 - 1000 * b ) / ( 1000 - b );
        c = 1000 - a - b;
        if ( pow( a, 2 ) + pow( b, 2 ) == pow( c, 2 ) ) {
            break;
        }
    }
    printf( "%d\n", a * b * c );

    return 0;
}
