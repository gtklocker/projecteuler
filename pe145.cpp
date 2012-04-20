#include <cstdio>
#include <cstdlib>

using namespace std;

int rev( int n ) {
    int t = 0;
    while ( n ) {
        t *= 10;
        t += n % 10;
        n /= 10;
    }
    return t;
}

bool reversible( int n ) {
    if ( n % 10 == 0 ) {
        return false;
    }

    int newn = rev( n ) + n;
    while ( newn ) {
        if ( ( newn % 10 ) % 2 == 0 ) {
            return false;
        }
        newn /= 10;
    }
    return true;
}

int main() {
    int found = 0;
    for ( int i = 1; i <= 1000000000; ++i ) {
        found += reversible( i );
    }

    printf( "%d\n", found );

    return 0;
}
