#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
    int i;
    int j;
    int w;
};

priority_queue< node > Q;

node makeNode( int i, int j, int w ) {
    node ret;
    ret.i = i;
    ret.j = j;
    ret.w = w;
    return ret;
}

bool operator<( const node a, const node b ) {
    return a.w > b.w;
}

const int N = 80;
bool visited[ N ][ N ];
int V[ N ][ N ], D[ N ][ N ];
void visit( int i, int j, int w ) {
    if ( i >= 0 && i < N && j >= 0 && j < N && !visited[ i ][ j ] ) {
        Q.push( makeNode( i, j, w + V[ i ][ j ] ) );
        visited[ i ][ j ] = true;
    }
}

int main() {
    FILE *fin = fopen( "matrix.txt", "r" );

    for ( int i = 0; i < N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            fscanf( fin, "%d,", &V[ i ][ j ] );
        }
    }

    Q.push( makeNode( 0, 0, V[ 0 ][ 0 ] ) );
    while ( !Q.empty() ) {
        node cur = Q.top();
        int i, j, w;
        i = cur.i;
        j = cur.j;
        w = cur.w;
        D[ i ][ j ] = w;
        if ( i == N - 1 && j == N - 1 ) {
            break;
        }
        Q.pop();

        visit( i - 1, j, w );
        visit( i + 1, j, w );
        visit( i, j + 1, w );
        visit( i, j - 1, w );
    }
    printf( "%d\n", D[ N - 1 ][ N - 1 ] );

    return 0;
}
