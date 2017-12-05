<?php
	$name=$_REQUEST["name"];
	$addr1=$_REQUEST["addr1"];
	$addr2=$_REQUEST["addr2"];
	$email=$_REQUEST["email"];
	$con = mysql_connect("localhost","root","") or die('Could not connect: ' . mysql_error());
	mysql_select_db("test",$con);
	if(mysql_query("insert into student values('$name','$addr1','$addr2','$email')"))
		print "<h3>Data inserted successfully</h3>";
	mysql_close($con);
?>
