#!/usr/bin/perl
use CGI qw(:standard);
use DBI;
print header();
print start_html();

$name = param("name");
$age  = param("age");
$con  = DBI->connect( "DBI:mysql:test", "root", "" );

$query1 = $con->prepare("insert into student values(?,?)");
$query1->execute( $name, $age );

$query2 = $con->prepare("select * from student");
$query2->execute();
print "Data in table:<br>";
print "<table>";
while ( ( $name, $age ) = $query2->fetchrow() ) {
    print "<tr><td> $name </td><td> $age </td></tr>";
}
print "</table>";
print end_html();
