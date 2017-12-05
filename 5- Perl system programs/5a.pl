#!/usr/bin/perl
use CGI qw(:standard);
print header();
print start_html();
foreach $x ( sort keys %ENV ) {
    print "<b> $x: </b> $ENV{$x}<br>";
}
print end_html();
