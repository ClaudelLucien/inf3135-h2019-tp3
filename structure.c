#include <stdio.h>
#include <stdlib.h>
#include "structure.h"


void ajouterNoeud(noeud **arbre, U128_t valeur)
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
    else  *arbre = elem;
}

//FIN ajouterNoeud//



int chercherVal(noeud *arbre, U128_t valeur)
{
    while(arbre)
    {
        if(valeur == arbre->valeur)
	{
	return 1;
	}
        if(valeur > arbre->valeur )
	{
	arbre = arbre->droit;
	}
        else arbre = arbre->gauche;
    }
    return 0;
}

//FIN chercherVal//





void afficherASC(noeud *arbre)
{
	if(!arbre)
	{
	return;
	}

	if(arbre->gauche)
	{
	afficherASC(arbre->gauche);
	}

	afficherU128(arbre->valeur);

	if(arbre->droit)
	{
	afficherASC(arbre->droit);
	}
}

//FIN afficherASC//






void afficherDES(noeud *arbre)
{
	if(!arbre)
	{
	return;
	}

	if(arbre->droit)
	{
	afficherDES(arbre->droit);
	}

    	afficherU128(arbre->valeur);

    	if(arbre->gauche)
	{
	afficherDES(arbre->gauche);
	}
}

//FIN afficherDES//

void detruireArbre(noeud **arbre)
{
	noeud *arbreTmp = *arbre;

	if(!arbre)
	{
	return;
	}

	if(arbreTmp->gauche)
	{
	detruireArbre(&arbreTmp->gauche);
	}

	if(arbreTmp->droit)
	{
	detruireArbre(&arbreTmp->droit);
	}

	free(arbreTmp);

	*arbre = NULL;
}
