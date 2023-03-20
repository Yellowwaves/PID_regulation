#include "visualisationT.h"

void visualisationT(temp_t myTemp) // ce fichier permet d'écrire les données dans le fichier data, il est affecté par le verrou
{
   if(access(".verrouData", F_OK) != -1) // si le fichier existe
   {
        //verrou data existe, on écrit rien
   }
   else
   {
        //on crée verrou data
        fopen(".verrouData", "w");
        
   }
}
