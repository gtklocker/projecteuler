<?php
    function isLeap( $year ) {
        return ( $year % 1000 == 0 && $year % 400 == 0 ) || ( $year % 1000 != 0 && $year % 4 == 0 );
    }
    function daysInYear( $year ) {
        $ret = array();
        for ( $i = 1; $i <= 12; ++$i ) {
            if ( in_array( $i, array( 4, 6, 9, 11 ) ) ) {
                $ret[ $i ] = 30;
            }
            else if ( $i == 2 ) {
                $ret[ $i ] = 28 + isLeap( $year );
            }
            else {
                $ret[ $i ] = 31;
            }
        }
        return $ret;
    }

    $days = array();
    $day = 1;
    $sundays = 0;

    for ( $i = 1901; $i <= 2000; ++$i ) {
        $days[ $i ] = daysInYear( $i );

        for ( $j = 1; $j <= 12; ++$j ) {
            for ( $k = 1; $k <= $days[ $i ][ $j ]; ++$k ) {
                $day = ( $day + 1 ) % 7;
                if ( $day == 6 && $k == 1 ) {
                    ++$sundays;
                }
            }
        }
    }
    echo $sundays;
?>
