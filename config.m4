dnl $Id$
dnl config.m4 for extension php7_explorer

PHP_ARG_ENABLE(php7_explorer, whether to enable php7_explorer support,
Make sure that the comment is aligned:
[  --enable-php7_explorer           Enable php7_explorer support])

if test "$PHP_PHP7_EXPLORER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-php7_explorer -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/php7_explorer.h"  # you most likely want to change this
  dnl if test -r $PHP_PHP7_EXPLORER/$SEARCH_FOR; then # path given as parameter
  dnl   PHP7_EXPLORER_DIR=$PHP_PHP7_EXPLORER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for php7_explorer files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PHP7_EXPLORER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PHP7_EXPLORER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the php7_explorer distribution])
  dnl fi

  dnl # --with-php7_explorer -> add include path
  dnl PHP_ADD_INCLUDE($PHP7_EXPLORER_DIR/include)

  dnl # --with-php7_explorer -> check for lib and symbol presence
  dnl LIBNAME=php7_explorer # you may want to change this
  dnl LIBSYMBOL=php7_explorer # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PHP7_EXPLORER_DIR/$PHP_LIBDIR, PHP7_EXPLORER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PHP7_EXPLORERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong php7_explorer lib version or lib not found])
  dnl ],[
  dnl   -L$PHP7_EXPLORER_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PHP7_EXPLORER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(php7_explorer, php7_explorer.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
