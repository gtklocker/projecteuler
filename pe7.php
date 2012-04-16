<?php
    $lim = 1000000;
    $prime = array_fill( 2, $lim, true );

    $tlim = ( int )sqrt( $lim );
    for ( $i = 2; $i <= $tlim; ++$i ) {
        for ( $j = 2; $i * $j <= $lim; ++$j ) {
            $prime[ $i * $j ] = false;
        }
    }

    for ( $p = 0, $i = 2; ; ++$i ) {
        $p += $prime[ $i ];
        if ( $p == 10001 ) {
            echo $i;
            break;
        }
    }
?>
