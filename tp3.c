#include "outils.h"
#include "structure.h"



  //  note : argc compte les arguments
  // le premier est toujours l'executable
char* tableauval[2];


int main(int argc, char * argv[]) {

    noeud *Arbre=NULL;
    FILE *entree=NULL;
    FILE *sortie=stdout;
    char borneInf[50];
    char borneSup[50];
   ajouterNoeud(&Arbre, 0); //On initialise un noeud a l'arbre


    if (argc==1) {
     // printf("Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
      return 1;
    }

 if (argc==3){
verifierCP(argc,argv);

U128_t* test=LireEntree();
	if(*test==-1)
	{
	printf("allo");
	}
rechercher(test,Arbre);

}

if (argc==5){
verifierCP(argc,argv);
 for (int j = 0; j < argc; j++) {
     if (strcmp(argv[j], "-i") == 0 ) {
     int indice = j+1;
        entree = fopen(argv[indice],"r+");


		while(!feof(entree))
		{
		fscanf(entree, "%s" "%s",borneInf,borneSup);
		U128_t* a =LireLigneFichier(borneInf,borneSup);
		rechercher(a,Arbre);
     		}

     fclose(entree);
     afficherASC(Arbre,sortie);
     }
     else if(strcmp(argv[j], "-o") == 0){
     rechercheFichier(LireEntree(),argv[j+1],Arbre);
     }

 }
}

if(argc==7){
verifierCP(argc,argv);
        for (int j = 0; j < argc; j++) {
             if (strcmp(argv[j], "-i") == 0 && strcmp(argv[j+1],"") != 0) {
             int indice = j+1;
                for (int k=0;k<argc;k++){
                   if(strcmp(argv[k],"-o") == 0 && strcmp(argv[k+1],"") != 0) {
     		   FILE *entree = fopen(argv[indice],"r+");
			   while(!feof(entree))
			   {
			   fscanf(entree, "%s %s",borneInf,borneSup);

                	   rechercheFichier(LireLigneFichier(borneInf,borneSup),argv[k+1],Arbre);
	                   }
		   fclose(entree);
		   }
                }
             }
	}
}
if(argc%2==0){
return 3;
}



detruireArbre(&Arbre);


}//Fin du main
