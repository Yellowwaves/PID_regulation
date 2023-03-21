#include "visualisationT.h"

void visualisationT(temp_t myTemp) // ce fichier permet d'écrire les données dans le fichier data, il est affecté par le verrou
{
     if (access(".verrouData", F_OK))
     {
          // .verrouData n'existe pas, donc on peut écrire dans data
          FILE *fverrou;
          fverrou = fopen(".verrouData", "w"); // on créé le fichier verrou

          FILE *fdata;
          fdata = fopen("data.txt", "r+"); // on ouvre le fichier data

          char lines[3][10]; // on crée un tableau de 2 lignes de 10 caractères max, pour stocker temporairment les lignes du fichier data.txt

          int numero_ligne = 0;
          while (fgets(lines[numero_ligne], 10, fdata) != NULL)
          {
               /*if (numero_ligne == 3) {
                     break;
               }*/
               numero_ligne++;
          }
          fclose(fdata);
          fdata = fopen("data.txt", "w");


          fprintf(fdata, "%s", lines[0]);
          fprintf(fdata, "%.1f\n", myTemp.interieure);
          fprintf(fdata, "%.1f", myTemp.exterieure);
          fclose(fdata);
          fclose(fverrou);       // on ferme les fichiers data.txt et verrou
          remove(".verrouData"); // on supprime le fichier verrou
     }
}
