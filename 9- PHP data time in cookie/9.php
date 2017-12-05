<?php
	date_default_timezone_set('Asia/Calcutta');
	$timeframe = 90 * 60 * 24 * 60 + time();
	setcookie('cook', date("h:m:s - d/m/y"), $timeframe);
	if(!isset($_COOKIE["cook"])) {
		print "<h1>You are visiting for the first time</h1>";
	}
	else {
		print "<b>Your last visit:</b> <h1>".$_COOKIE["cook"]."</h1>";
	}
?>
