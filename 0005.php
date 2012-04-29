<?php
    for ( $i = 20; ; $i += 20 ) {
        for ( $j = 2; $j <= 20; ++$j ) {
            if ( $i % $j != 0 ) {
                break;
            }
        }
        if ( $j >= 20 ) {
            break;
        }
    }

    echo $i;
?>
