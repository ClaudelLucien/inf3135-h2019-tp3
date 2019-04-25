// structure.h    
// Auteur: Lucien CLAUDEL
// INF3135 - mars 2019
#include "outils.h"
__extension__ typedef unsigned __int128 U128_t;


#ifndef CGI_RBTREE_H
#define CGI_RBTREE_H

typedef struct noeud
{
    U128_t valeur;
    struct noeud *gauche;
    struct noeud *droit;
} noeud ;

//#ifdef __cplusplus
//extern "C" {
//#endif

    void ajouterNoeud(noeud **arbre, U128_t valeur);

    int chercherVal(noeud *arbre, U128_t valeur);

    void afficherASC(noeud *arbre);

    void afficherDES(noeud *arbre);

    void detruireArbre(noeud **arbre);

//#ifdef __cplusplus
//}
//#endif

#endif //CGI_RBTREE_H

