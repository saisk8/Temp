<?php
	session_start();
	if(!isset($_SESSION["count"]))
	{
		print "<h1>You are visiting for the first time</h1>";
		$_SESSION["count"]=1;
	}
	else
	{
		print "<center><h1>Visit count:".$_SESSION["count"]++."</h1></center>";
	}
?>
