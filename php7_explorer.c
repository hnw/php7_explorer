/*
The MIT License

Copyright (c) 2015 Yoshio HANAWA

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_php7_explorer.h"
#include "ext/standard/php_var.h"

static int le_php7_explorer;

static void _dump_function_table(const HashTable *function_table, int level);
static void _dump_class_table(const HashTable *class_table, int level);
static void _dump_properties_info(const HashTable *properties_info, int level);
static void _dump_constants_table(const HashTable *constants_table, int level);

/* {{{ proto void dump_function_table() */
PHP_FUNCTION(dump_function_table)
{
	_dump_function_table(EG(function_table), 0);
	return;
}
/* }}} */

/* {{{ proto void dump_class_table() */
PHP_FUNCTION(dump_class_table)
{
	_dump_class_table(EG(class_table), 0);
	return;
}
/* }}} */

/* {{{ _dump_function_table
 */
static void _dump_function_table(const HashTable *function_table, int level)
{
	zend_function *func;

	ZEND_HASH_FOREACH_PTR(function_table, func) {
		if (level > 0) {
			php_printf("%*c", level, ' ');
		}
		zend_string *function_name = func->common.function_name;
		if (function_name) {
			php_printf("%s()", ZSTR_VAL(function_name));
		} else {
			php_printf("**unknown function**()");
		}
		php_printf("\n");
	} ZEND_HASH_FOREACH_END();

	return;
}
/* }}} */

/* {{{ _dump_class_table
 */
static void _dump_class_table(const HashTable *class_table, int level)
{
	zend_class_entry *ce;

	ZEND_HASH_FOREACH_PTR(class_table, ce) {
		if (level > 0) {
			php_printf("%*c", level, ' ');
		}
		zend_string *class_name = ce->name;
		if (class_name) {
			php_printf("%s::", ZSTR_VAL(class_name));
		} else {
			php_printf("**unknown class**::");
		}
		php_printf("\n");

		_dump_function_table(&ce->function_table, 4);
		_dump_properties_info(&ce->properties_info, 4);
		_dump_constants_table(&ce->constants_table, 4);
	} ZEND_HASH_FOREACH_END();
							
	return;
}
/* }}} */

/* {{{ _dump_function_table
 */
static void _dump_properties_info(const HashTable *properties_info, int level)
{
	zend_property_info *prop_info;
	zend_string *key;
	zval *zv;

	ZEND_HASH_FOREACH_STR_KEY_VAL(properties_info, key, zv) {
		prop_info = Z_PTR_P(zv);
		zend_string *prop_name = prop_info->name;
		if (level > 0) {
			php_printf("%*c", level, ' ');
		}
		if (prop_name) {
			php_printf("%s", ZSTR_VAL(key));
		} else {
			php_printf("**unknown property**");
		}
		php_printf("\n");
	} ZEND_HASH_FOREACH_END();

	return;
}
/* }}} */

/* {{{ _dump_function_table
 */
static void _dump_constants_table(const HashTable *constants_table, int level)
{
	zend_string *key;
	zval *zv;

	ZEND_HASH_FOREACH_STR_KEY_VAL(constants_table, key, zv) {
		if (level > 0) {
			php_printf("%*c", level, ' ');
		}
		if (key) {
			php_printf("%s: ", ZSTR_VAL(key));
			php_var_dump(zv, 1);
		} else {
			php_printf("**unknown property**\n");
		}
	} ZEND_HASH_FOREACH_END();

	return;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(php7_explorer)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php7_explorer)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php7_explorer)
{
#if defined(COMPILE_DL_PHP7_EXPLORER) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(php7_explorer)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php7_explorer)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "php7_explorer support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ php7_explorer_functions[]
 *
 * Every user visible function must have an entry in php7_explorer_functions[].
 */
const zend_function_entry php7_explorer_functions[] = {
	PHP_FE(dump_function_table, NULL)
	PHP_FE(dump_class_table, NULL)
	PHP_FE_END	/* Must be the last line in php7_explorer_functions[] */
};
/* }}} */

/* {{{ php7_explorer_module_entry
 */
zend_module_entry php7_explorer_module_entry = {
	STANDARD_MODULE_HEADER,
	"php7_explorer",
	php7_explorer_functions,
	PHP_MINIT(php7_explorer),
	PHP_MSHUTDOWN(php7_explorer),
	PHP_RINIT(php7_explorer),
	PHP_RSHUTDOWN(php7_explorer),
	PHP_MINFO(php7_explorer),
	PHP_PHP7_EXPLORER_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP7_EXPLORER
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(php7_explorer)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
