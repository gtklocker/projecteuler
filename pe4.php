<?php
    function palin( $n ) {
        return strrev( strval( $n ) ) == strval( $n );
    }

    $max = 0;
    for ( $i = 100; $i < 1000; ++$i ) {
        for ( $j = 100; $j < 1000; ++$j ) {
            if ( palin( $i * $j ) ) {
                $max = max( $i * $j, $max );
            }
        }
    }

    echo $max;
?>
