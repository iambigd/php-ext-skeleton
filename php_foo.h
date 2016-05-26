#ifndef _PHP_FOO_H
  #define _PHP_FOO_H
  #ifdef HAVE_CONFIG_H
  #include "config.h"
#endif


#ifdef ZTS
  #include <TSRM.h>
#endif


#include <php.h>
#include "SAPI.h"
#include "zend_compile.h"
#include "zend_execute.h"
#include "php_ini.h"
#include "ext/standard/info.h"

/*
宣告全域變數
*/
ZEND_BEGIN_MODULE_GLOBALS(foo)
 char *str;
 int strlen;
 long counter;
ZEND_END_MODULE_GLOBALS(foo)

/*
Zend Thread Safety(ZTS)
處理thread-safe
*/


// #ifdef ZTS
// # define FOO_G(v) TSRMG(foo_globals_id, zend_foo_globals*, v)
// extern int foo_globals_id;
// #else
// # define FOO_G(v) (foo_globals.v)
// extern zend_foo_globals foo_globals;
// #endif 

#ifdef ZTS
#define FOO_G(v) TSRMG(foo_globals_id, zend_foo_globals *, v)
#else
#define FOO_G(v) (foo_globals.v)
#endif


/*
定義foo module
*/
extern zend_module_entry foo_module_entry;

//module 初始與結束
PHP_MINIT_FUNCTION(foo);
PHP_MSHUTDOWN_FUNCTION(foo);

//request 初始與結束
PHP_RINIT_FUNCTION(foo);
PHP_RSHUTDOWN_FUNCTION(foo);

PHP_MINFO_FUNCTION(foo);

PHP_FUNCTION(foo_hello);
PHP_FUNCTION(foo_hello_str);
PHP_FUNCTION(foo_hello_arr);
PHP_FUNCTION(foo_hello_add);
PHP_FUNCTION(foo_hello_void);

//global testing
PHP_FUNCTION(foo_set_global_counter);
PHP_FUNCTION(foo_get_global_counter);
PHP_FUNCTION(foo_set_global_string);
PHP_FUNCTION(foo_get_global_string);
PHP_FUNCTION(foo_get_global_unsafe_counter);

#endif
