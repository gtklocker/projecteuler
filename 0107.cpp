#include <cstdio>
#include <set>

using namespace std;

#define ii pair< int, int >

int main() {
    const int N = 40;
    int D[ N ][ N ];
    int preWeight = 0;
    bool added[ N ][ N ] = { false };
    FILE *fin = fopen( "network.txt", "r" );

    for ( int src = 0; src < N; ++src ) {
        for ( int dst = 0; dst < N; ++dst ) {
            fscanf( fin, "%d,", &D[ src ][ dst ] );
            if ( !added[ src ][ dst ] && D[ src ][ dst ] >= 0 ) {
                preWeight += D[ src ][ dst ];
            }
            added[ dst ][ src ] = true;
        }
    }

    bool visited[ N ] = { false };
    set< ii > S; // inserting as ii( weight, node )
    set< ii > mst;
    S.insert( ii( 0, 0 ) );

    int mstWeight = 0;

    while ( !S.empty() ) {
        set< ii >::iterator top = S.begin();
        int node = top->second, weight = top->first;
        if ( visited[ node ] ) {
            S.erase( ii( weight, node ) );
            continue;
        }

        for ( int i = 0; i < N; ++i ) {
            if ( D[ node ][ i ] >= 0 && !visited[ i ] ) {
                S.insert( ii( D[ node ][ i ], i ) );
            }
        }

        visited[ node ] = true;
        S.erase( ii( weight, node ) );
        mst.insert( ii( weight, node ) );
        mstWeight += weight;
    }

    printf( "%d\n", preWeight - mstWeight );

    return 0;
}
