<?php
    $n = 600851475143;
    $lim = ( int )sqrt( $n );
    $prime = array_fill( 2, ++$lim, true );

    $tlim = ( int )sqrt( $lim );
    for ( $i = 2; $i <= $tlim; ++$i ) {
        for ( $j = 2; $i * $j <= $lim; ++$j ) {
            $prime[ $i * $j ] = false;
        }
    }

    function factor( $n, $ctors = array() ) {
        global $prime;
        if ( $n < count( $prime ) && $prime[ $n ] ) {
            $ctors[] = $n;
            return $ctors;
        }

        $lim = ( int )sqrt( $n );
        for ( $i = 2; $i <= $lim; ++$i ) {
            if ( $n % $i == 0 ) {
                $ctors[] = $i;
                return factor( $n / $i, $ctors );
            }
        }
    }

    echo( max( factor( $n ) ) );
?>
