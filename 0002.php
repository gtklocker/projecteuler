<?php
    $a = 1;
    $b = 2;
    $c = $a + $b;
    $sum = 0;
    while ( $a <= 4000000 ) {
        if ( $a % 2 == 0 ) {
            $sum += $a;
        }
        $a = $b;
        $b = $c;
        $c = $a + $b;
    }

    echo $sum;
?>
