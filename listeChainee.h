// structure.h    
// Auteur: Lucien CLAUDEL
// INF3135 - mars 2019
#ifndef __LISTECH_H__
#define __LISTECH_H__

#include <stdbool.h>

// Strucutre Noeud utilisee par la liste.
struct Noeud
{
   // L'element contenu dans le noeud
   int element;
   // Pointeur vers l'element suivant dans la liste, NULL si le dernier
   struct Noeud* ptrSuiv;
   //Pointeur vers l'element precedent dans la liste, NULL si premier
   struct Noeud* ptrPrec;

};
typedef struct Noeud Noeud;

// Structure de la liste
typedef struct Liste
{
   // nombre d'elements presentement dans la liste
   int     taille;
   // Le noeud de tete, le debut de la liste
   struct Noeud*  tete;
   // Le moeud de queue, la fin de la liste
   struct Noeud* queue;

} Liste;

// creerListe
// Creee dynamiquement une liste et initialise ses valeurs
// Retour:
//  Liste* : la liste cree, NULL en cas d'erreur
Liste* creerListe();

// estVide
// Determine si la liste est vide
// Parametre:
//   Liste* liste : La liste a verifier
// Retour:
//   bool: true si la liste est vide
bool estVide(Liste* liste);

//inserer
// Insere un element dans la liste
// Parametres:
//   Liste* liste : la liste dans laquelle inserer l'element
//   int element  : l'element a inserer
// Retour:
//   bool: false en cas d'erreur

bool inserer(Liste* liste, int ajout);

// detruireListe
// detruit la liste
// Parametres:
//   Liste** liste : la liste a detruire
// Retour:
//   bool:false en cas d'erreur

short detruireListe(Liste** liste);

void AfficherListe(Liste *ptrListe);
#endif // __LISTECH_H__
