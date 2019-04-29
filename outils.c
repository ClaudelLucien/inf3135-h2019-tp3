#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "outils.h"
#include <math.h>
#include "structure.h"

//Début des Fonctions



U128_t* LireLigneFichier(char * borneInf, char * borneSup){
        static U128_t tableau[2];

	U128_t a = lireU128(borneInf);
        U128_t b = lireU128(borneSup);
	tableau[0] = a;
        tableau[1] = b;

        return tableau;
}

U128_t* LireEntree(){

       	char borneInf[50];
       	char borneSup[50];
       	scanf("%s %s",borneInf,borneSup);
       	U128_t a = lireU128(borneInf);
       	U128_t b = lireU128(borneSup);
       	static U128_t tableauval[2];
	tableauval[0] = a;
	tableauval[1] = b;


	return tableauval;
}




void rechercheFichier(U128_t tableau[], char argv[], noeud * Arbre,FILE * sortie){

        if(sortie==NULL){
        exit(6);
        }

	U128_t borneInf = tableau[0];
        U128_t borneSup = tableau[1];
	U128_t premier=0;

	if(borneInf>borneSup)
	{
	swap(&borneInf,&borneSup);
	}

		for(U128_t i = 2 ; i<=65 && premier<borneSup ; i++){

                	if (EstPremier(i)==0){

                	U128_t dep=puiss(2,i)-1;
                		if(EstPremier(dep)==0)
				{
                		premier=puiss(2,(i-1))*(puiss(2,i)-1);

					if(premier<=borneSup && premier>=borneInf)
					{
						if(chercherVal(Arbre,premier)==0)
						{
                        			ajouterNoeud(&Arbre,premier);
						}
					}

                        	}
                	}
		}
}

int verifierCP(int argc, char * argv[]){
 for (int i = 0; i < argc; i++)

    {
     	if (strcmp(argv[i], "-c") == 0 && strlen(argv[i + 1]) == 12) {
        FILE * code = NULL;
        code = fopen("code.txt","w+");
        fprintf(code,"%s\n",argv[i+1]);
        fclose(code);
        return 0;
        }
	else if (strcmp(argv[i], "-c") == 0 && strlen(argv[i + 1]) != 12) {
         exit(2);
        }
    }
return 0;
}
int EstPremier(U128_t nombre){

        if(nombre ==1){
        return 1;
        }
	if(nombre==2){
        return 0;
        }
	U128_t rac_nombre=sqrt(nombre)+1;
                for (U128_t i =2 ; i<=rac_nombre-1;i++){
                        if (nombre%i==0){
                        return 1;
                        }
                }
return 0;
}

void rechercher(U128_t* tableau,noeud * Arbre){
        U128_t borneInf = tableau[0];
        U128_t borneSup = tableau[1];
	U128_t premier = 0;
	if(borneInf>borneSup)
        {
	swap(&borneInf,&borneSup);
        }
        for(U128_t i = 2 ; i<=65 && premier<borneSup ; i++){

                if (EstPremier(i)==0){

                U128_t dep=puiss(2,i)-1;
                	if(EstPremier(dep)==0){
                	premier=puiss(2,(i-1))*(puiss(2,i)-1);
                       		if(premier<borneSup && premier>borneInf)
				{
					if(chercherVal(Arbre,premier)==0)
                                        {
                                        ajouterNoeud(&Arbre,premier);
					}
                       		}
                	}
		}
        }
}

U128_t puiss (U128_t x, U128_t n){
   U128_t y = 1;
   U128_t m = 1;
   while (m <= n) {
      y *= x;
      m++;
   }
   return y;
}







U128_t lireU128(char *ligne){

	int longueur=strlen(ligne);
	U128_t modulo=1;
	U128_t facteur=10;
	U128_t nbrFinal =0;
	U128_t ascii =48;
	for(int j = longueur-1; j>=0; j--)
	{
	U128_t chiffre =(U128_t) ligne[j]-ascii; //on convertit le char en int
	chiffre = chiffre * modulo; //On multiplie le chiffre par 1,10,100,1000... selon sa position dans la chaine
	nbrFinal = nbrFinal + chiffre; // On l'additionne au nombre final
	modulo = modulo*facteur;

	}
	return nbrFinal;
}


void afficherFichierU128(U128_t nombre, FILE * fichier){

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
        fprintf(fichier,"%d",string[i]);
        }
	fprintf(fichier,"\n");

}


void swap(U128_t * min,U128_t * max){

U128_t temp= *max;
*max = *min;
*min = temp;


}

