#include <cstdio>

using namespace std;

typedef unsigned long long int llu;

bool correct( llu n ) {
    for ( int i = 10; i > 0; --i ) {
        if ( n % 10 != i % 10 ) {
            return false;
        }
        n /= 100;
    }
    return true;
}

int main() {
    //Lower bound: ~sqrt( 1020304050607080900 )
    llu low = 1010101009;
    for ( llu i = low; ; ++i ) {
        if ( correct( i * i ) ) {
            printf( "%llu\n", i );
            return 0;
        }
    }
}
