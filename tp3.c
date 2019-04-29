#include "outils.h"
#include "structure.h"



  //  note : argc compte les arguments
  // le premier est toujours l'executable
//char* tableauval[2];


int main(int argc, char * argv[]) {

    noeud *Arbre=NULL;
    FILE *entree=NULL;
    FILE *sortie=stdout;
    char borneInf[50];
    char borneSup[50];
   ajouterNoeud(&Arbre, 0); //On initialise un noeud a l'arbre


////////ANCIEN MAIN////////////////
    if (argc==1) {
     // printf("Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
      return 1;
    }

 if (argc==3){
verifierCP(argc,argv);

U128_t* test=LireEntree();
rechercher(test,Arbre);
afficherDES(Arbre,sortie);
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
     afficherDES(Arbre,sortie);
     }
     else if(strcmp(argv[j], "-o") == 0){
     sortie = fopen(argv[j+1], "w+");
     rechercheFichier(LireEntree(),argv[j+1],Arbre,sortie);
     afficherDES(Arbre,sortie);
     }
     else if(strcmp(argv[j], "-d") == 0)
     {
     	if(strcmp(argv[j+1], "ASC") == 0)
	{

	U128_t* test=LireEntree();
	rechercher(test,Arbre);
	afficherASC(Arbre,sortie);
	}
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
     		   entree = fopen(argv[indice],"r+");
		   sortie = fopen(argv[k+1],"w+");
			   while(!feof(entree))
			   {
			   fscanf(entree, "%s %s",borneInf,borneSup);

                	   rechercheFichier(LireLigneFichier(borneInf,borneSup),argv[k+1],Arbre,sortie);
	                   }
		   afficherDES(Arbre,sortie);
		   fclose(entree);
		   fclose(sortie);
		   }
                }
             }
	}
	for (int j = 0; j < argc; j++) {
             if (strcmp(argv[j], "-i") == 0 && strcmp(argv[j+1],"") != 0) {
             int indice = j+1;
                for (int k=0;k<argc;k++){
                   if(strcmp(argv[k],"-d") == 0 && strcmp(argv[k+1],"ASC") == 0) {
                   entree = fopen(argv[indice],"r+");
                           while(!feof(entree))
                           {
                           fscanf(entree, "%s %s",borneInf,borneSup);

                           rechercheFichier(LireLigneFichier(borneInf,borneSup),argv[k+1],Arbre,sortie);
                           }
                   afficherASC(Arbre,sortie);
                   fclose(entree);
                   }
		   if(strcmp(argv[k],"-d") == 0 && strcmp(argv[k+1],"DES") == 0) {
                   entree = fopen(argv[indice],"r+");
                           while(!feof(entree))
                           {
                           fscanf(entree, "%s %s",borneInf,borneSup);

                           rechercheFichier(LireLigneFichier(borneInf,borneSup),argv[k+1],Arbre,sortie);
                           }
                   afficherDES(Arbre,sortie);
                   fclose(entree);
		   }
                 }
               }
	}
	for (int j = 0; j < argc; j++) {
             if (strcmp(argv[j], "-d") == 0 && strcmp(argv[j+1],"ASC") != 0) {
                for (int k=0;k<argc;k++){
                   if(strcmp(argv[k],"-o") == 0 && strcmp(argv[k+1],"") != 0) {
                   entree = stdin;
                   sortie = fopen(argv[k+1],"w+");
                           while(!feof(entree))
                           {
                           fscanf(entree, "%s %s",borneInf,borneSup);

                           rechercheFichier(LireLigneFichier(borneInf,borneSup),argv[k+1],Arbre,sortie);
                           }
                   afficherASC(Arbre,sortie);
                   fclose(sortie);
                   }
                }
             }
	    if (strcmp(argv[j], "-d") == 0 && strcmp(argv[j+1],"DES") != 0) {
                for (int k=0;k<argc;k++){
                   if(strcmp(argv[k],"-o") == 0 && strcmp(argv[k+1],"") != 0) {
                   entree = stdin;
                   sortie = fopen(argv[k+1],"w+");
                           while(!feof(entree))
                           {
                           fscanf(entree, "%s %s",borneInf,borneSup);

                           rechercheFichier(LireLigneFichier(borneInf,borneSup),argv[k+1],Arbre,sortie);
                           }
                   afficherDES(Arbre,sortie);
                   fclose(sortie);
                   }
                }
             }

        }
}


if(argc==9)
{
for (int j = 0; j < argc; j++) {
             if (strcmp(argv[j], "-d") == 0 && strcmp(argv[j+1],"ASC") == 0) {
              	for (int k=0;k<argc;k++){
                   if(strcmp(argv[k],"-o") == 0 && strcmp(argv[k+1],"") != 0) {
			for (int i=0;i<argc;i++){
				if(strcmp(argv[i],"-i") == 0 && strcmp(argv[i+1],"") != 0) {
				entree = fopen(argv[i+1],"r+");
 	                        sortie = fopen(argv[k+1],"w+");
                        	        while(!feof(entree))
         	     			{
                		        fscanf(entree, "%s %s",borneInf,borneSup);

                           		rechercheFichier(LireLigneFichier(borneInf,borneSup),argv[k+1],Arbre,sortie);
                           		}
                   		afficherASC(Arbre,sortie);
                   		fclose(sortie);
				fclose(entree);
				}
			}
		   }
		}
	     }
}
for (int j = 0; j < argc; j++) {
             if (strcmp(argv[j], "-d") == 0 && strcmp(argv[j+1],"DES") == 0) {
                for (int k=0;k<argc;k++){
                   if(strcmp(argv[k],"-o") == 0 && strcmp(argv[k+1],"") != 0) {
                        for (int i=0;i<argc;i++){
                                if(strcmp(argv[i],"-i") == 0 && strcmp(argv[i+1],"") != 0) {
                                entree = fopen(argv[i+1],"r+");
                                sortie = fopen(argv[k+1],"w+");
                                        while(!feof(entree))
                                        {
                                        fscanf(entree, "%s %s",borneInf,borneSup);

                                        rechercheFichier(LireLigneFichier(borneInf,borneSup),argv[k+1],Arbre,sortie);
                                        }
                                afficherDES(Arbre,sortie);
                                fclose(sortie);
                                fclose(entree);
                                }
                        }
                   }
                }
             }
}
}






if(argc%2==0){
return 3;
}

/////////////ANCIEN MAIN////////

detruireArbre(&Arbre);


}//Fin du main
