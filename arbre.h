// structure.h    
// Auteur: Lucien CLAUDEL
// INF3135 - mars 2019
#ifndef __ARBRE_H__
#define __ARBRE_H__



typedef struct noeud
{
    unsigned int valeur;
    struct noeud *gauche;
    struct noeud *droit;
} noeud ;


void ajouterNoeud(noeud **arbre, unsigned int valeur);

void afficherArbreASC(noeud *arbre);
void afficherArbreDES(noeud *arbre);
void detruireArbre(noeud **arbre);
#endif // __ARBRE_H__


