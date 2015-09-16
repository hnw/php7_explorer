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

## LICENSE

The MIT License

Copyright (c) 2015 Yoshio HANAWA

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
