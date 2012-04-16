<?php
    $lim = 2000001;
    $prime = array_fill( 2, $lim, true );

    $tlim = ( int )sqrt( $lim );
    for ( $i = 2; $i <= $tlim; ++$i ) {
        for ( $j = 2; $i * $j <= $lim; ++$j ) {
            $prime[ $i * $j ] = false;
        }
    }

    $sum = 0;
    for ( $i = 2; $i < $lim - 1; ++$i ) {
        if ( $prime[ $i ] ) {
            $sum += $i;
        }
    }

    echo $sum;
?>
