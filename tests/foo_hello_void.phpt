--TEST--
Check foo_hello_void
--FILE--
<?php
echo foo_hello_void(); 
?>
--EXPECT--
call hello_world_c_noreturn1[hello_world_c_noreturn] is running in php-ext-skeleton