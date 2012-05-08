#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <queue>

using namespace std;

typedef struct {
    int source, target, weight;
} edge_t;

const int N = 40; //TODO: Change this for different inputs.
typedef vector< list< edge_t > > vl;

bool operator<( const edge_t &a, const edge_t &b ) {
    return a.weight > b.weight;
}

/* Returns the sum of a vector, much like python's sum(). */
int vectorSum( vector< int > a ) {
    int ret = 0, vsize = a.size();
    for ( int i = 0; i < vsize; ++i ) {
        ret += a[ i ];
    }

    return ret;
}

/* Returns the sum of all weights of edges. */
int edgeSum( vl edges ) {
    bool added[ N ][ N ];
    for ( int i = 0; i < N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            added[ i ][ j ] = false;
        }
    }

    int ret = 0;
    for ( int node = 0; node < N; ++node ) {
        for ( list< edge_t >::iterator it = edges[ node ].begin(); it != edges[ node ].end(); ++it ) {
            if ( added[ it->target ][ it->source ] || added[ it->source ][ it->target ] ) {
                continue;
            }
            ret += it->weight;
            added[ it->source ][ it->target ] = true;
        }
    }
    return ret;
}

int main() {
    FILE *fin = fopen( "network.txt", "r" );
    vl neighbors( N );

    edge_t tempEdge;
    for ( int source = 0; source < N; ++source ) {
        for ( int target = 0; target < N; ++target ) {
            fscanf( fin, "%d,", &tempEdge.weight );
            if ( tempEdge.weight == -1 ) {
                continue;
            }

            tempEdge.source = source;
            tempEdge.target = target;
            neighbors[ source ].push_back( tempEdge );
        }
    }

    fclose( fin );

    set< edge_t > seenEdges;
    bool seen[ N ];
    priority_queue< edge_t > visit;

    vector< int > distance( N );

    for ( int i = 0; i < N; ++i ) {
        if ( i ) {
            distance[ i ] = -1;
        }
        else {
            distance[ i ] = 0;
        }
        seen[ i ] = false;
    }

    tempEdge.weight = 0;
    tempEdge.target = 0;
    visit.push( tempEdge );

    while ( !visit.empty() ) {
        int node = visit.top().target;

        if ( seen[ node ] ) {
            visit.pop();
            continue;
        }

        for ( list< edge_t >::iterator it = neighbors[ node ].begin(); it != neighbors[ node ].end(); ++it ) {
            if ( ( distance[ it->target ] < 0 || distance[ it->target ] > it->weight ) && distance[ it->source ] != it->weight ) {
                distance[ it->target ] = it->weight;
            }
            visit.push( *it );
        }

        seen[ node ] = true;
        visit.pop();
    }

    printf( "%d\n", edgeSum( neighbors ) - vectorSum( distance ) );

    return 0;
}
