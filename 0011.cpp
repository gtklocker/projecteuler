#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

FILE *fi = fopen( "pe11.txt", "r" );

const int N = 20;
const int INF = -1;
ll M[ N ][ N ];
ll W[ N ][ N ];

int okay( int i, int j ) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

int main() {
    for ( int i = 0; i < N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            fscanf( fi, "%d ", &M[ i ][ j ] );
            W[ i ][ j ] = INF;
        }
    }

    int lay[ 4 ][ 2 ];
    ll curmax = INF;
    for ( int i = 0; i < N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            //lines
            if ( okay( i + 3, j ) ) {
                W[ i ][ j ] = max( W[ i ][ j ],
                    M[ i ][ j ] * M[ i + 1 ][ j ] * M[ i + 2 ][ j ] * M[ i + 3 ][ j ] );
            }
            if ( okay( i - 3, j ) ) {
                W[ i ][ j ] = max( W[ i ][ j ],
                    M[ i ][ j ] * M[ i - 1 ][ j ] * M[ i - 2 ][ j ] * M[ i - 3 ][ j ] );
            }
            if ( okay( i, j + 3 ) ) {
                W[ i ][ j ] = max( W[ i ][ j ],
                    M[ i ][ j ] * M[ i ][ j + 1 ] * M[ i ][ j + 2 ] * M[ i ][ j + 3 ] );
            }
            if ( okay( i, j - 3 ) ) {
                W[ i ][ j ] = max( W[ i ][ j ],
                    M[ i ][ j ] * M[ i ][ j - 1 ] * M[ i ][ j - 2 ] * M[ i ][ j - 3 ] );
            }
            //diagonals
            if ( okay( i + 3, j + 3 ) ) {
                W[ i ][ j ] = max( W[ i ][ j ],
                    M[ i ][ j ] * M[ i + 1 ][ j + 1 ] * M[ i + 2 ][ j + 2 ] * M[ i + 3 ][ j + 3 ] );
            }
            if ( okay( i - 3, j - 3 ) ) {
                W[ i ][ j ] = max( W[ i ][ j ],
                    M[ i ][ j ] * M[ i - 1 ][ j - 1 ] * M[ i - 2 ][ j - 2 ] * M[ i - 3 ][ j - 3 ] );
            }
            if ( okay( i + 3, j - 3 ) ) {
                W[ i ][ j ] = max( W[ i ][ j ],
                    M[ i ][ j ] * M[ i + 1 ][ j - 1 ] * M[ i + 2 ][ j - 2 ] * M[ i + 3 ][ j - 3 ] );
            }
            if ( okay( i - 3, j + 3 ) ) {
                W[ i ][ j ] = max( W[ i ][ j ],
                    M[ i ][ j ] * M[ i - 1 ][ j + 1 ] * M[ i - 2 ][ j + 2 ] * M[ i - 3 ][ j + 3 ] );
            }
            curmax = max( curmax, W[ i ][ j ] );
        }
    }
    printf( "%lld\n", curmax );

    return 0;
}
