#include <stdio.h>
#include <stdlib.h>

struct Noeud {
	int cle;
	Noeud *droit, *gauche;
};

struct Arbre {
	struct Noeud* racine;
};
