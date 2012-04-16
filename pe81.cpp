#include <cstdio>
#include <algorithm>

typedef unsigned long long llu;

using namespace std;

const int N = 80, INF = 987654321;
int M[ N ][ N ];
llu W[ N ][ N ];
FILE *fi = fopen( "matrix.txt", "r" );

llu go( int i, int j ) {
    if ( W[ i ][ j ] != INF ) {
        return W[ i ][ j ];
    }
    if ( j == N - 1 && i != N - 1 ) {
        W[ i ][ j ] = M[ i ][ j ] + go( i + 1, j );
        return W[ i ][ j ];
    }
    if ( i == N - 1 && j != N - 1 ) {
        W[ i ][ j ] = M[ i ][ j ] + go( i, j + 1 );
        return W[ i ][ j ];
    }
    W[ i ][ j ] = M[ i ][ j ] + min( go( i + 1, j ), go( i, j + 1 ) );
    return W[ i ][ j ];
}

int main() {
    W[ N - 1 ][ N - 1 ] = 0;
    for ( int i = 0; i < N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            fscanf( fi, "%d,", &M[ i ][ j ] );
            W[ i ][ j ] = INF;
        }
    }
    W[ N - 1 ][ N - 1 ] = M[ N - 1 ][ N - 1 ];

    printf( "%llu\n", go( 0, 0 ) );

    return 0;
}
