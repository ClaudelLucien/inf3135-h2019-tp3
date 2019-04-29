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





void afficherASC(noeud *arbre, FILE * sortie)
{
	if(!arbre)
	{
	return;
	}

	if(arbre->gauche)
	{
	afficherASC(arbre->gauche,sortie);
	}

	afficherU128(arbre->valeur,sortie);

	if(arbre->droit)
	{
	afficherASC(arbre->droit,sortie);
	}
}

//FIN afficherASC//






void afficherDES(noeud *arbre, FILE * sortie)
{
	if(!arbre)
	{
	return;
	}

	if(arbre->droit)
	{
	afficherDES(arbre->droit,sortie);
	}

    	afficherU128(arbre->valeur,sortie);

    	if(arbre->gauche)
	{
	afficherDES(arbre->gauche,sortie);
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




void afficherU128(U128_t nombre, FILE * sortie){

        int string[50];
        short indiceTab=0;
        U128_t diviseur=10;


        while(nombre!=0)
        {
	string[indiceTab]=(nombre%diviseur);

        nombre =nombre/diviseur;
        indiceTab++;
        }


	for(int i = indiceTab-1; i>=0; i--)
        {
	fprintf(sortie,"%d",string[i]);
        }
	fprintf(sortie,"\n");
}

