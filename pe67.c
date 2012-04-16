#include <stdio.h>

#define N 100
inline int max( int a, int b ) {
    return ( ( a > b ) ? a : b );
}

int G[ N ][ N ], C[ N ][ N ];
int explore( int i, int j ) {
    if ( C[ i ][ j ] == -1 ) {
        if ( j == 0 ) {
            C[ i ][ j ] = explore( i - 1, j ) + G[ i ][ j ];
        }
        else if ( j == i ) {
            C[ i ][ j ] = explore( i - 1, j - 1 ) + G[ i ][ j ];
        }
        else {
            C[ i - 1 ][ j - 1 ] = explore( i - 1, j - 1 );
            C[ i - 1 ][ j ] = explore( i - 1, j );
            C[ i ][ j ] = max( C[ i - 1 ][ j ], C[ i - 1 ][ j - 1 ] ) + G[ i ][ j ];
        }
    }
    return C[ i ][ j ];
}

int main( void ) {
    int i, j;
    FILE *fin = fopen( "triangle.txt", "r" );
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j <= i; ++j ) {
            fscanf( fin, "%d ", &G[ i ][ j ] );
            C[ i ][ j ] = -1;
        }
    }
    C[ 0 ][ 0 ] = G[ 0 ][ 0 ];
    fclose( fin );

    int max = -1;
    for ( i = 0; i < N; ++i ) {
        explore( N - 1, i );
        if ( C[ N - 1 ][ i ] > max ) {
            max = C[ N - 1 ][ i ];
        }
    }
    printf( "%d\n", max );

    return 0;
}
