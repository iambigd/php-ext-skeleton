--TEST--
Check foo_hello_add
--FILE--
<?php
foo_hello_add(5,5);
?>
--EXPECT--
run foo_hello_add
val1=5
val2=5
[hello_world_c_add] is running in php-ext-skeleton
5
5
sum=10