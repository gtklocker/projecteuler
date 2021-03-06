#include <cstdio>

struct point {
    int x;
    int y;
};

struct triangle {
    point a;
    point b;
    point c;
};

point makePoint( int x, int y ) {
    point ret;
    ret.x = x;
    ret.y = y;

    return ret;
}

triangle makeTriangle( point a, point b, point c ) {
    triangle ret;
    ret.a = a;
    ret.b = b;
    ret.c = c;

    return ret;
}

long long int ccw( point a, point b, point c ) {
    return ( b.x - a.x ) * ( c.y - a.y ) -
        ( b.y - a.y ) * ( c.x - a.x );
}

bool inTriangle( triangle t, point o ) {
    return ccw( t.a, t.b, o ) * ccw( t.a, t.c, o ) < 0 &&
        ccw( t.b, t.c, o ) * ccw( t.b, t.a, o ) < 0;
}

int main() {
    int ans = 0;
    FILE *fin = fopen( "triangles.txt", "r" );
    for ( int i = 0; i < 1000; ++i ) {
        point p[ 3 ];
        for ( int j = 0; j < 3; ++j ) {
            int x, y;
            fscanf( fin, "%d,%d,", &x, &y );
            p[ j ] = makePoint( x, y );
        }

        triangle t = makeTriangle( p[ 0 ], p[ 1 ], p[ 2 ] );
        ans += inTriangle( t, makePoint( 0, 0 ) );
    }
    printf( "%d\n", ans );

    return 0;
}
