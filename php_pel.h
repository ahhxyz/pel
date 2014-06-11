#ifndef PHP_PEL_H
#define PHP_PEL_H

extern zend_module_entry pel_module_entry;
#define phpext_pel_ptr &pel_module_entry

#define PHP_PEL_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_PEL_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_PEL_API __attribute__ ((visibility("default")))
#else
#	define PHP_PEL_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(pel)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(pel)
*/

/* In every utility function you add that needs to use variables 
   in php_pel_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PEL_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PEL_G(v) TSRMG(pel_globals_id, zend_pel_globals *, v)
#else
#define PEL_G(v) (pel_globals.v)
#endif

#endif	/* PHP_PEL_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
