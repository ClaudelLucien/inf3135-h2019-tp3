#include "outils.h"
#include "structure.h"



  //  note : argc compte les arguments
  // le premier est toujours l'executable
char* tableauval[2];


int main(int argc, char * argv[]) {

    noeud *Arbre = NULL;

ajouterNoeud(&Arbre, 0);
/*    ajouterNoeud(&Arbre, 20);
    ajouterNoeud(&Arbre, 50);
    ajouterNoeud(&Arbre, 45);
    ajouterNoeud(&Arbre, 25);
    ajouterNoeud(&Arbre, 80);
    ajouterNoeud(&Arbre, 40);
    ajouterNoeud(&Arbre, 70);
    ajouterNoeud(&Arbre, 25);
    ajouterNoeud(&Arbre, 10);
    ajouterNoeud(&Arbre, 60);
*/
    puts("-------------------------------");

   // afficherASC(Arbre);

    puts("-------------------------------");

   // afficherDES(Arbre);

    detruireArbre(&Arbre);

    char essai[] =  "1834898797994343477037485";
    U128_t n =0;
    n=~n;
    afficherU128(n);
    U128_t a=lireU128(essai);
    afficherU128(a);
    printf("\n");


    if (argc==1) {
     // printf("Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
      return 1;
    }

 if (argc==3){
verifierCP(argc,argv);

U128_t* test=LireEntree();
rechercher(test,Arbre);
}

if (argc==5){
verifierCP(argc,argv);

 for (int j = 0; j < argc; j++) {
     if (strcmp(argv[j], "-i") == 0 ) {
     int indice = j+1;
     rechercher(LireLigneFichier(indice,argv),Arbre);
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
                   rechercheFichier(LireLigneFichier(indice,argv),argv[k+1],Arbre);
		   afficherASC(Arbre);
                   }
                }
             }
            
	}
}
if(argc%2==0){
return 3;
}










}//Fin du main
