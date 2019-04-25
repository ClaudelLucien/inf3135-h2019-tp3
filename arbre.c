#include <stdio.h>
#include <stdlib.h>
#include "structure.h"




void ajouterNoeud(noeud **arbre, unsigned int valeur)
{
	
    noeud *noeudTmp;
    noeud *arbreTmp = *arbre;

    noeud *elem = malloc(sizeof(noeud));
    elem->valeur = valeur;
    elem->gauche = NULL;
    elem->droit = NULL;

    if(arbreTmp)
    do
    {
        noeudTmp = arbreTmp;
        if(valeur > arbreTmp->valeur )
        {
            arbreTmp = arbreTmp->droit;
            if(!arbreTmp)
	    { 
		noeudTmp->droit = elem;
	    }
        }
        else
        {
            arbreTmp = arbreTmp->gauche;
            if(!arbreTmp)
	    { 
		noeudTmp->gauche = elem;
	    }
        }
    }
    while(arbreTmp);
    else{  
	*arbre = elem;
	}
}

void afficherArbreASC(noeud *arbre){
    if(!arbre) 
    {
        return;
    }
    if(arbre->gauche)
        {
	afficherArbreASC(arbre->gauche);

        printf("valeur du noeud = %d\n", arbre->valeur);

        }

    if(arbre->droit)
        { 
	afficherArbreASC(arbre->droit);
        }
}


void afficherArbreDES(noeud *arbre)
{
    if(!arbre) 
    {
        return;
    }
    if(arbre->droit)
        {  
	afficherArbreDES(arbre->droit);

        printf("valeur du noeud = %d\n", arbre->valeur);

        }
    if(arbre->gauche)
        { 
	afficherArbreDES(arbre->gauche);
	
        }
}



void detruireArbre(noeud **arbre)
{
    noeud *arbreTmp = *arbre;

    if(!arbre){
    return ;
    }

    if(arbreTmp->gauche)
    {
    detruireArbre(&arbreTmp->gauche);
    }
    if(arbreTmp->droit)
    detruireArbre(&arbreTmp->droit);

    free(arbreTmp);      

    *arbre = NULL;
}
