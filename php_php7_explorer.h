/*
The MIT License

Copyright (c) 2015 Yoshio HANAWA

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef PHP_PHP7_EXPLORER_H
#define PHP_PHP7_EXPLORER_H

extern zend_module_entry php7_explorer_module_entry;
#define phpext_php7_explorer_ptr &php7_explorer_module_entry

#define PHP_PHP7_EXPLORER_VERSION "0.1.0"

#ifdef PHP_WIN32
#	define PHP_PHP7_EXPLORER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_PHP7_EXPLORER_API __attribute__ ((visibility("default")))
#else
#	define PHP_PHP7_EXPLORER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define PHP7_EXPLORER_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(php7_explorer, v)

#if defined(ZTS) && defined(COMPILE_DL_PHP7_EXPLORER)
ZEND_TSRMLS_CACHE_EXTERN();
#endif

#endif	/* PHP_PHP7_EXPLORER_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
