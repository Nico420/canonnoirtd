#!/usr/bin/perl
#
# owner Peggy Cellier
#
# Convertit le  fichier articles.txt vers le format de weka
# syntax: perl txt2weka.pl articles.10p.txt mots.lst 
#

#use strict;

if ($ARGV[0] eq "") {
        print " syntaxe : perl outil fichierEntree FichierSortie \n" ;
          exit(-1) ;
     }  ;
$fichText = $ARGV[0] ; # récupération du fichier texte contenant les phrases lemmatisees


if ($ARGV[1] eq "") {
        print " syntaxe : perl outil fichierEntree FichierSortie \n" ;
          exit(-1) ;
     }  ;
$fichMots = $ARGV[1] ; # récupération du fichier contenant les mots significatifs

$fichOut=$fichText.".csv";

open (FICHOUT, ">:encoding(utf8)",     $fichOut)	
			|| die "\n impossible d'ouvrir le fichier nommé $fichOut \n\n" ;
#
open (FICHTEXT, "<:encoding(iso-8859-15)",     $fichText)	
			|| die "\n impossible d'ouvrir le fichier d'entré nommé $fichIn \n\n" ;
	
open (FICHMOTS, "<:encoding(iso-8859-15)",     $fichMots)	
			|| die "\n impossible d'ouvrir le fichier d'entré nommé $fichIn2 \n\n" ;

my @tabMots = ();
my $i=0;
while($ligne = <FICHMOTS>){
	chomp($ligne);
	push(@tabMots,$ligne);
	if($i==0){	
		print FICHOUT "$ligne";
		$i=$i+1;
	}else{
		print FICHOUT ", $ligne";
	}
}
print FICHOUT "\n";
while($ligne = <FICHTEXT>){
my $b=0;	
foreach my $a (@tabMots){
	if($b==0){
		$virg="";
		$b= $b+1;
	}else{
		$virg=", ";
	}	
	if($ligne=~ ".*$a.*"){
		print FICHOUT $virg."true";
	}else{
		print FICHOUT $virg."false";
	}
	
}
print FICHOUT "\n";
}

print "Fin creation\n";
# Rappel : 
# ($line =~ m/\s$i\s/)
# ^ caractère de début de ligne
# $ caractère de fin de ligne
#
#@my @items = ();
# push(@items, $line) ; // ajoute un objet
# foreach my $i (@items) // parcours du tableau

close (FICHTEXT);
close (FICHMOTS);
close (FICHOUT);
