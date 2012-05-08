#include <cstdio>

using namespace std;

typedef unsigned long long ull;

int div( ull n ) {
    int ret = 0;
    for ( ull i = 1; i <= n; ++i ) {
        ret += ( n % i == 0 );
    }
    return ret;
}

int main() {
    ull i, n;
    for ( n = 1, i = 1; div( n ) <= 500; ++i, n += i ) {
        printf( "\rCurrent: %d", n );
        fflush( stdout );
    }

    printf( "\rSolution: %llu\n", n );

    return 0;
}
