#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef outih
#define outih
#include "structure.h"
__extension__ typedef unsigned __int128 U128_t;

U128_t* LireLigneFichier(int indice, char * argv[]);
U128_t* LireEntree();
void rechercheFichier(U128_t tableau[],char argv[],noeud *arbre);
void rechercher(U128_t* tableau, noeud * Arbre);
int verifierCP(int argc, char * argv[]);
int EstPremier(U128_t nombre);
U128_t puiss(U128_t x, U128_t n );
U128_t lireU128(char *ligne);
void afficherU128(U128_t nombre);
int lireInt(char *ligne);
void afficherInt(int nombre);
void swap(U128_t * min,U128_t * max);
void afficherFichierU128(U128_t nombre, FILE * fichier);
void afficherFichierU128inverser(U128_t nombre, FILE * fichier);
#endif



