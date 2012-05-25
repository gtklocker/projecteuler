#include <cstdio>
#include <vector>

using namespace std;

struct num {
    short n;
    char fst;
    char end;
    char team;
};

#define ii pair< num, num >

num makeNum( short n, char fst, char end, char team ) {
    num ret;
    ret.n = n;
    ret.fst = fst;
    ret.end = end;
    ret.team = team;

    return ret;
}

num all[ 6000 ];
short numCnt = 0;

short formula( short i, short n ) {
    switch ( i ) {
        case 0:
            return n * ( n + 1 ) / 2;
        case 1:
            return n * n;
        case 2:
            return n * ( 3 * n - 1 ) / 2;
        case 3:
            return n * ( 2 * n - 1 );
        case 4:
            return n * ( 5 * n - 3 ) / 2;
        case 5:
            return n * ( 3 * n - 2 );
    }
}

bool compat( num a, num b ) {
    return a.end == b.fst && a.team != b.team;
}

bool pairCompat( ii a, ii b ) {
    if ( a.first.team == b.first.team || a.first.team == b.second.team ||
        a.second.team == b.first.team || a.second.team == b.second.team ) {
        return false;
    }
    return compat( a.second, b.first );
}

bool justOne( ii a, ii b, ii c ) {
    vector< char > V( 6 );
    V[ a.first.team ]++;
    V[ a.second.team ]++;
    V[ b.first.team ]++;
    V[ b.second.team ]++;
    V[ c.first.team ]++;
    V[ c.second.team ]++;

    for ( int i = 0; i < 6; ++i ) {
        if ( V[ i ] != 1 ) {
            return false;
        }
    }
    return true && c.second.end == a.first.fst;
}

int main() {
    for ( short mode = 0, i = 1; mode < 6; ++i ) {
        short n = formula( mode, i );
        if ( n < 1000 ) {
            continue;
        }
        if ( n > 9999 ) {
            ++mode;
            i = 1;
            continue;
        }
        all[ numCnt++ ] = makeNum( n, n / 100, n % 100, mode );
    }
    vector< ii > allpairs;
    for ( int i = 0; i < numCnt; ++i ) {
        for ( int j = 0; j < numCnt; ++j ) {
            if ( i != j && compat( all[ i ], all[ j ] ) ) {
                allpairs.push_back( ii( all[ i ], all[ j ] ) );
            }
        }
    }

    int pairSize = allpairs.size();
    for ( int i = 0; i < pairSize; ++i ) {
        for ( int j = 0; j < pairSize; ++j ) {
            for ( int k = 0; k < pairSize; ++k ) {
                if ( pairCompat( allpairs[ i ], allpairs[ j ] ) && pairCompat( allpairs[ j ], allpairs[ k ] ) ) {
                    if ( justOne( allpairs[ i ], allpairs[ j ], allpairs[ k ] ) ) {
                        int ans = allpairs[ i ].first.n + allpairs[ i ].second.n +
                            allpairs[ j ].first.n + allpairs[ j ].second.n +
                            allpairs[ k ].first.n + allpairs[ k ].second.n;
                        printf( "%d\n", ans );
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
