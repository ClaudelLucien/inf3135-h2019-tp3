// structure.c
// Auteur: Lucien CLAUDEL
// INF3135 - mars 2019


#include "structure.h"
#include <stdlib.h>
#include <stdio.h>
Liste* creerListe()
{
Liste *nouvelleListe=malloc(sizeof(*nouvelleListe));


  if (nouvelleListe == NULL)
    {
     	exit(EXIT_FAILURE);
    }

nouvelleListe->taille = 0;
nouvelleListe->tete = NULL;
nouvelleListe->queue = NULL;

return nouvelleListe;
}

bool estVide(Liste* liste)
{
if(liste->taille=0){
return 0;
}
else{
return1;
}

}


liste *inserer(Liste* liste, int element)
{
  if(estVide(liste))
  {
  struct Noeud *NouvNoeud = malloc(sizeof *NouvNoeud);
      if (NouvNoeud != NULL)
      {
      NouvNoeud->element = element;
      NouvNoeud->ptrSuiv= NULL;
      NouvNoeud->ptrPrec= NULL;
      liste->tete = NouvNoeud;
      liste->queue = NouvNoeud;
      liste->taille++;
      }
  }
  else{
  struct Noeud *ptrTemp = liste->tete;
    while(ptrTemp !=NULL)
    {
     	if(ptrTemp->element < element && ptrTemp->ptrSuiv->element > element)
        {
	struct Noeud *NouvNoeud = malloc(sizeof *NouvNoeud); 
                if (NouvNoeud != NULL)
                {
                NouvNoeud->element = element;
                NouvNoeud->ptrSuiv = ptrTemp->ptrSuiv;
                NouvNoeud->ptrPrec = ptrTemp;
                prtTemp->ptrSuiv->ptrPrec = NouvNoeud;
                prtTemp->ptrPrec->ptrSuiv = NouvNoeud;
                liste->taille++;
                }

        }
    }
    ptrTemp = ptrTemp->ptrSuiv;

  }
return liste;
}



bool detruireListe(Liste** liste)
{
if (*liste != NULL)
    {
     	struct node *ptrTemp = (*liste)->tete;
        while (ptrTemp != NULL)
        {
            struct node *ptrSuppr = prtTemp;
            ptrTemp = ptrTemp->ptrSuiv;
            free(ptrSuppr);
        }
	free(*liste), *liste = NULL;
    }
}
