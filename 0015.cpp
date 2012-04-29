#include <stdio.h>

const int GRID = 20 + 1;

typedef unsigned long long ull;
using namespace std;

int main( void ) {
   ull W[ GRID ][ GRID ];
   for ( ull i = 0; i < GRID; ++i ) {
       for ( ull j = 0; j < GRID; ++j ) {
           if ( !i || !j ) {
               W[ i ][ j ] = 1;
           }
           else {
               W[ i ][ j ] = W[ i ][ j - 1 ] + W[ i - 1 ][ j ];
           }
       }
   }

   printf( "%llu\n", W[ GRID - 1 ][ GRID - 1 ] );

   return 0;
}
