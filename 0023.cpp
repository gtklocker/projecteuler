#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

bool abundant( int n ) {
    set< int > div;
    for ( int i = 1; i < n; ++i ) {
        if ( n % i == 0 ) {
            div.insert( i );
        }
    }

    set< int >::iterator it;
    int sum = 0;
    for ( it = div.begin(); it != div.end(); ++it ) {
        sum += *it;
    }
    return n >= 12 && sum > n;
}

int main() {
    const int upper = 28123;
    set< int > ab;
    for ( int i = 1; i <= upper; ++i ) {
        if ( abundant( i ) ) {
            ab.insert( i );
        }
    }

    set< int >::iterator it1, it2;
    set< int > absum;
    for ( it1 = ab.begin(); it1 != ab.end(); ++it1 ) {
        for ( it2 = ab.begin(); it2 != ab.end(); ++it2 ) {
            absum.insert( *it1 + *it2 );
        }
    }

    int sum = 0;
    int m = 0;
    set< int >::iterator it;
    for ( it = absum.begin(); it != absum.end(); ++it ) {
        if ( *it <= upper ) {
            m = max( m, *it );
            sum += *it;
        }
    }

    int allsum = 0;
    for ( int i = 1; i <= m; ++i ) {
        allsum += i;
    }
    printf( "%d\n", allsum - sum );

    return 0;
}
