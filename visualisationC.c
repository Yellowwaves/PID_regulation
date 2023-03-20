#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
//#include "visualisationC.h"


void visualisationC(float puissance) // Cette fonction permet de récupérer la consigne, elle est affectée par le verrou et elle write true/false dans le fichier data
{
   printf("%d", 1);
   if (access(".verrouData", F_OK)) 
   {
    // .verrouData n'existe pas, donc on peut écrire dans data
      FILE *fverrou;
      fverrou = fopen (".verrouData", "w"); // on créé le fichier verrou

      
      FILE *fdata_in;
      fdata_in = fopen ("exemple.txt", "r+"); // on ouvre le fichier data



      char new_line[] = "true";
      char lines[2][10];

      int current_line_number = 0;
      while (fgets(lines[current_line_number], 10, fdata_in) != NULL) {
         if (current_line_number == 1) {
               break;
         }
         current_line_number++;
      }
      FILE* fdata_out;
      fdata_out= fopen("exemple.txt", "w");

      fprintf(fdata_out, "%s", lines[0]);
      fprintf(fdata_out, "%s", lines[1]);

      if (puissance == 0.0) // si puissance = 0, on écrit 'false' à la ligne 3 du fichier 'data.txt'
      {
         fprintf(fdata_out, "%s", "false");
      }
      else if ((puissance > 0.0)&&(puissance<=100.0)) // si puissance entre 0 et 100, témoin de chauffe allumé
      {
         fprintf(fdata_out, "%s", "true");  
      }

      fclose (fdata_in);
      fclose (fdata_out);
      fclose (fverrou);
      remove(".verrouData"); // on supprime le fichier verrou
   }
}



int main(){
visualisationC(0);
return 0;
}