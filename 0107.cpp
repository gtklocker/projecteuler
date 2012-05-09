#include <cstdio>
#include <set>

using namespace std;

#define ii pair< int, int >

int main() {
    const int N = 40;
    int D[ N ][ N ];
    int preWeight = 0;
    FILE *fin = fopen( "network.txt", "r" );

    for ( int src = 0; src < N; ++src ) {
        for ( int dst = 0; dst < N; ++dst ) {
            fscanf( fin, "%d,", &D[ src ][ dst ] );
            preWeight += ( D[ src ][ dst ] >= 0 ) * D[ src ][ dst ];
        }
    }
    preWeight /= 2;

    bool visited[ N ] = { false };
    set< ii > S; //inserting as ii( weight, node )
    S.insert( ii( 0, 0 ) );

    int mstWeight = 0;

    while ( !S.empty() ) {
        set< ii >::iterator top = S.begin();
        int node = top->second, weight = top->first;
        S.erase( ii( weight, node ) );
        if ( visited[ node ] ) {
            continue;
        }

        for ( int i = 0; i < N; ++i ) {
            if ( D[ node ][ i ] >= 0 && !visited[ i ] ) {
                S.insert( ii( D[ node ][ i ], i ) );
            }
        }

        visited[ node ] = true;
        mstWeight += weight;
    }

    printf( "%d\n", preWeight - mstWeight );

    return 0;
}
