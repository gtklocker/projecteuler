<?php
    $sqsum = 0;
    $sumsq = 0;
    for ( $i = 1; $i <= 100; ++$i ) {
        $sqsum += $i * $i;
        $sumsq += $i;
    }

    $sumsq *= $sumsq;
    echo $sumsq - $sqsum;
?>
