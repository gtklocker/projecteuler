#include <cstdio>
#include <algorithm>

using namespace std;

FILE *fi = fopen( "input/pe82.txt", "r" );
const int N = 80;
const int INF = 987654321;
int W[ N ][ N ], V[ N ][ N ];

int main() {
    int tdist, res = INF;
    for ( int i = 0; i < N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            fscanf( fi, "%d,", &V[ i ][ j ] );
            if ( !j ) {
                W[ i ][ j ] = V[ i ][ j ];
            }
            else {
                W[ i ][ j ] = INF;
            }
        }
    }

    for ( int j = 1; j < N; ++j ) {
        for ( int i = 0; i < N; ++i ) {
            //W[ i ][ j ] = min( W[ k ][ j - 1 ] + V[ k..i ][ j ] )
            for ( int k = 0; k < N; ++k ) {
                tdist = W[ k ][ j - 1 ];
                for ( int l = k; ( k > i ) ? i <= l : i >= l; ( k > i ) ? --l : ++l ) {
                    tdist += V[ l ][ j ];
                }

                W[ i ][ j ] = min( W[ i ][ j ], tdist );
                if ( j == N - 1 ) {
                    res = min( res, W[ i ][ j ] );
                }
            }
        }
    }

    printf( "%d\n", res );

    return 0;
}
