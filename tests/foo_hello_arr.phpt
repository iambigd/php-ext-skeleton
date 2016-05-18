--TEST--
Check foo_hello_arr
--FILE--
<?php
echo foo_hello_arr(Array('I','am','bigd'));
?>
--EXPECT--
The array passed contains 3 elements 0 => I 1 => am 2 => bigd 1