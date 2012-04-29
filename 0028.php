<?php
    $val = 1001 * 1001;
    $col = 2;
    $fnd = 0;
    $sum = 1;
    $i = 3;
    while ( $i <= $val ) {
        if ( $fnd == 4 ) {
            $i -= $col;
            $col += 2;
            $i += $col;
            $fnd = 0;
        }
        $sum += $i;
        $i += $col;
        $fnd += 1;
    }
    echo $sum . "\n";
?>
