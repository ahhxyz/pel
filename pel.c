/*
  +----------------------------------------------------------------------+
  | PHP 扩展                                                       |
  +----------------------------------------------------------------------+
  | 单例模式                                                              |
  +----------------------------------------------------------------------+
  | Author:      吴鑫                                                     |
  +----------------------------------------------------------------------+
*/



#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_pel.h"
#include "SingletonPattern.h"


static int le_pel;


PHP_MINIT_FUNCTION(pel)
{
    zend_class_entry ce;
    
    //初始化config类
    INIT_CLASS_ENTRY(ce, "config",config_methods);
    config_ce = zend_register_internal_class(&ce TSRMLS_CC);  
    
    
    
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(pel)
{
    return SUCCESS;
}

PHP_RINIT_FUNCTION(pel)
{
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(pel)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(pel)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "pel support", "enabled");
    php_info_print_table_end();
	
}

/**
 * 定义框架测试函数
 * @param string
 * @return string 
 */
PHP_FUNCTION(confirm_pel_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = pelprintf(&strg, 0, "<title>安装成功！</title><h1 style=\"color:#2C5EAA;margin-top:200px;margin-left:18%;\">%.78s安装成功！，这是传进来的参数： %.78s </h1>", "pel", arg);
	RETURN_STRINGL(strg, len, 0);
}

/**
 *定义获取配置的快捷方法
 */
PHP_FUNCTION(C){
    
}       

const zend_function_entry pel_functions[] = {
	PHP_FE(confirm_pel_compiled,	NULL)		/* For testing, remove later. */
        PHP_FE(C,NULL)        
	PHP_FE_END	/* Must be the last line in pel_functions[] */
};

zend_module_entry pel_module_entry = {
	STANDARD_MODULE_HEADER,
	"pel",
	pel_functions,
	PHP_MINIT(pel),
	PHP_MSHUTDOWN(pel),
	PHP_RINIT(pel),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(pel),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(pel),
	PHP_PEF_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_PEF
ZEND_GET_MODULE(pel)
#endif


