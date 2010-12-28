#			TP2. Analyseur Syntaxique
#
#	Makefile donné à titre d'exemple
#
#
#	Der. Rev. : 03 Oct. 08		par : Benoît Boyer
#
#


# Indiquer ici la liste des fichiers.
# Pour chaque fichier source *.ml que vous allez créer, 
# ajouter les fichiers *.cmo correspondants.
# Exemple : 
#	sources : file_1.ml file_2.ml main.ml
# CMO=file_1.cmo file_2.cmo file_3.cmo
CMO=fichier_1.cmo fichier_2.cmo fichier_3.cmo

######################################################################
# pour utilizer l'analyseur lexical de secours, décommentez la ligne #
# suivante (retirez le # devant LEX)				     #
######################################################################
# LEX=analex.cma
#
# Informations pour utiliser l'analyseur lexical de secours
DIR=lib/

# Nom de l'exécutable produit (vous pouvez le changer à votre guise)
OUT=tp2


CFLAGS=-dtypes -I $(DIR)
CC=ocamlc $(CFLAGS)
RM=rm -rf

.PHONY: clean all

# Pour compiler sans la librairie 
all: $(OUT)

$(OUT): $(CMO)
	$(CC) $(LEX) $^ -o $@
	@echo "===> $@ est compilé avec succès!!!"


-include .depend

%.cmo:	%.ml 
	$(CC) -c $<

clean:
	$(RM) $(OUT) *~ $(CMO) .depend \
	$(CMO:.cmo=.cmi) $(CMO:.cmo=.annot)

.depend:$(shell *.ml *.mli)
	ocamldep $(CMO) > .depend
