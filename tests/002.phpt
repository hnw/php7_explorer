--TEST--
Check for dump_function_table()
--SKIPIF--
<?php
	extension_loaded('php7_explorer') or die('skip php7_explorer not available');
    $required_func = array("dump_function_table");
	foreach ($required_func as $func_name) {
		if (!function_exists($func_name)) {
			die("skip $func_name() function is not available.");
		}
	}
?>
--FILE--
<?php
dump_function_table();
--EXPECTREGEX--
.*dump_function_table\(\).*
