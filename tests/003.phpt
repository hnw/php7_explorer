--TEST--
Check for dump_class_table()
--SKIPIF--
<?php
	extension_loaded('php7_explorer') or die('skip php7_explorer not available');
    $required_func = array("dump_class_table");
	foreach ($required_func as $func_name) {
		if (!function_exists($func_name)) {
			die("skip $func_name() function is not available.");
		}
	}
?>
--FILE--
<?php
dump_class_table();
--EXPECTREGEX--
.*stdClass::.*
