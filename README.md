# php7_explorer

[![Build Status](https://travis-ci.org/hnw/php7_explorer.png)](https://travis-ci.org/hnw/php7_explorer)

PHP extension for exploring the PHP7 internals

## INSTALL

```
git clone https://github.com/hnw/php7_explorer.git
cd php-timecop
phpize
./configure
make
make install
```

After install, add these lines to your php.ini

```ini
extension=php7_explorer.so
```

## SYSTEM REQUIREMENTS

- PHP: 7.0.0+

## USAGE

```php
<?php
dump_class_table();
dump_function_table();
```
