#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "visualisationC.h"


void visualisationC(float puissance) // Cette fonction permet de récupérer la consigne, elle est affectée par le verrou et elle write true/false dans le fichier data
{
   if (access(".verrouData", F_OK)) 
   {
    // .verrouData n'existe pas, donc on peut écrire dans data
      FILE *fverrou;
      fverrou = fopen (".verrouData", "w"); // on créé le fichier verrou

      
      FILE *fdata;
      fdata = fopen ("data.txt", "r+"); // on ouvre le fichier data


      char lines[3][10];// on crée un tableau de 2 lignes de 10 caractères max, pour stocker temporairment les lignes du fichier data.txt

      int numero_ligne = 0;
      while (fgets(lines[numero_ligne], 10, fdata) != NULL) {
         /*if (numero_ligne == 3) {
               break;
         }*/
         numero_ligne++;
      }
      fclose (fdata);
      fdata= fopen("data.txt", "w");


      if (puissance == 0.0) // si puissance = 0, on écrit 'false' à la fin du 'data.txt'
      {
         fprintf(fdata, "%s", "false\n");
      }
      else if ((puissance > 0.0)&&(puissance<=100.0)) // si puissance entre 0 et 100, témoin de chauffe allumé (true)
      {
         fprintf(fdata, "%s", "true\n");  
      }

      
      fprintf(fdata, "%s", lines[1]);
      fprintf(fdata, "%s", lines[2]);
      printf("%s", lines[2]);
      fclose (fdata);
      fclose (fverrou); //on ferme les fichiers data.txt et verrou
      remove(".verrouData"); // on supprime le fichier verrou
   }
}