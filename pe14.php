<?php
    $chain = array_fill( 1, 1000001, 0 );
    $chain[ 1 ] = 1;
    function seq( $n, $t = 0 ) {
        global $chain;
        if ( $n <= 1000000 && $chain[ $n ] ) {
            return $t + $chain[ $n ];
        }
        if ( $n % 2 == 0 ) {
            return seq( $n / 2, $t + 1 );
        }
        else {
            //we know that 3 * $n + 1 will be even so we avoid one step
            return seq( ( $n * 3 + 1 ) / 2, $t + 2 );
        }
    }

    $max = 1;
    for ( $i = 1; $i <= 1000000; ++$i ) {
        $chain[ $i ] = seq( $i );
        if ( $chain[ $i ] > $chain[ $max ] ) {
            $max = $i;
        }
    }

    echo $max;
?>
