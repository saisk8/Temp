#!/usr/bin/perl
use CGI qw(:standard);
print header();
print start_html();
open( IN, "<count.txt" );
$count = <IN>;
close(IN);
$count++;
print "<h1>Accessed $count time(s)</h1>";
open( OUT, ">count.txt" );
print OUT $count;
close(OUT);
print end_html();
