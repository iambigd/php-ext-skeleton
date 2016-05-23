// #include "hello_world_c/hello_world_c.h"//內部的c func

#include "php_foo.h"
#include "hello_world_c.h"

// #include "ext/standard/info.h"

#if COMPILE_DL_FOO
ZEND_GET_MODULE(foo)
#endif

static const zend_function_entry foo_functions[] = {
  //定義你這個外掛可以用的php function，用了此宣告要多實作PHP_FUNCTION(如果有多個函式的話請多加即可)
  PHP_FE(foo_hello, NULL)
  PHP_FE(foo_hello_str, NULL)
  PHP_FE(foo_hello_arr, NULL)
  PHP_FE(foo_hello_add, NULL)
  PHP_FE(foo_hello_void, NULL)
  PHP_FE_END
};

zend_module_entry foo_module_entry = {
  STANDARD_MODULE_HEADER,
  "Foo",                       // your extension name
  foo_functions,               // where you define your functions
  NULL, // PHP_MINIT(foo),     // for module initialization
  NULL, // PHP_MSHUTDOWN(foo), // for module shutdown process
  NULL, // PHP_RINIT(foo)      // for request initialization
  NULL, // PHP_RSHUTDOWN(foo)  // for reqeust shutdown process
  PHP_MINFO(foo),              // for providing module information
  "0.1",
  STANDARD_MODULE_PROPERTIES
};
 
/*
Remove the comment if you want to initiazlie something (class entry, resource entry, constants ... etc)
*/

// 每一次執行php時，會先載入 extension，這時須要執行的程式寫在這裡。
PHP_MINIT_FUNCTION(foo) {
  return SUCCESS;
}
// PHP執行結束時，會執行的程式。
PHP_MSHUTDOWN_FUNCTION(foo) {
  return SUCCESS;
}

//extension說明資料，會出現在 phpinfo
PHP_MINFO_FUNCTION(foo) {
    
    // 產生表格
    php_info_print_table_start();

    php_info_print_table_header(2,"header1", "header2");
    php_info_print_table_row(2, "row col-1", "row col-2");
    php_info_print_table_end();
}

// Your functions here...
PHP_FUNCTION(foo_hello) {
  
  // RETURN_TRUE;
  RETURN_STRING("Hello World", 1);
}

//輸入字串
PHP_FUNCTION(foo_hello_str) {

  char *name;
  int name_len;

  //parse parameters
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name,&name_len ) == FAILURE) {
      RETURN_FALSE;
  }
  // php_printf("%s",name);
  RETURN_STRINGL(name,name_len,1);//字串要多補一個結尾長度
}

//輸入陣列
PHP_FUNCTION(foo_hello_arr) {

  zval *arr, **data;
  HashTable *arr_hash;
  HashPosition pointer;
  int array_count;

  //parse parameters
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &arr ) == FAILURE) {
      RETURN_FALSE;
  }
  
  arr_hash = Z_ARRVAL_P(arr);
  array_count = zend_hash_num_elements(arr_hash);
  php_printf("The array passed contains %d elements ", array_count);

  //for each
   for(zend_hash_internal_pointer_reset_ex(arr_hash, &pointer); 
      zend_hash_get_current_data_ex(arr_hash, 
        (void**) &data, &pointer) == SUCCESS; 
      zend_hash_move_forward_ex(arr_hash, &pointer)) {

        zval temp;
        char *key;
        int key_len;
        long index;

        if (zend_hash_get_current_key_ex(arr_hash, &key, &key_len, &index, 0, &pointer) == HASH_KEY_IS_STRING) {
            PHPWRITE(key, key_len);
        } else {
            php_printf("%ld", index);
        }

        php_printf(" => ");

        temp = **data;
        zval_copy_ctor(&temp);
        convert_to_string(&temp);
        PHPWRITE(Z_STRVAL(temp), Z_STRLEN(temp));
        php_printf(" ");
        zval_dtor(&temp);
    }

    RETURN_TRUE;

}

//呼叫自定義的c函數
PHP_FUNCTION(foo_hello_add) {

  php_printf("run foo_hello_add\n");

  int val1;
  int val2;
  int sum;  

  //parse parameters
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &val1,&val2 ) == FAILURE) {
      RETURN_FALSE;
  }

  php_printf("val1=%d\n",val1);
  php_printf("val2=%d\n",val2);

  sum = hello_world_c_add(val1,val2);
 
  RETURN_DOUBLE(sum);
}

PHP_FUNCTION(foo_hello_void) {
  php_printf("call hello_world_c_noreturn");
  hello_world_c_noreturn(); 
  RETURN_TRUE;
}
