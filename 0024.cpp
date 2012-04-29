#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int i = 0;
    do {
        ++i;
        if ( i == 1000000 ) {
            for ( int j = 0; j < 10; ++j ) {
                printf( "%d", a[ j ] );
            }
            putchar( '\n' );
            break;
        }
    } while ( next_permutation( a, a + 10 ) );

    return 0;
}
