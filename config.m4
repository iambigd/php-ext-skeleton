dnl config.m4 for extension

PHP_ARG_ENABLE(foo, whether to enable foo extension support, 
  [--enable-foo Enable foo extension support])

dnl 檢測extension是否已被啟動
if test $PHP_FOO != "no"; then

	AC_MSG_CHECKING("start to enable extension");

 	dnl PHP_NEW_EXTENSION(foo, php_foo.c, $ext_shared)

 	dnl 注意多引用了自定義C語言func
   	PHP_NEW_EXTENSION(foo, php_foo.c hello_world_c.c stack_lv1.c, $ext_shared)
 	

fi
