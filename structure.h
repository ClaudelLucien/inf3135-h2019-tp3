// structure.h    
// Auteur: Lucien CLAUDEL
// INF3135 - mars 2019

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

    void afficherASC(noeud *arbre,FILE * sortie);

    void afficherDES(noeud *arbre,FILE * sortie);

    void detruireArbre(noeud **arbre);

    void afficherU128(U128_t nombre, FILE * sortie);

//#ifdef __cplusplus
//}
//#endif

#endif //CGI_RBTREE_H

