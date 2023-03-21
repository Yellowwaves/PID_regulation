#include "consigne.h"
#include <unistd.h>

float consigne(float thermostatPrec_f) // consigne ecrit la consigne dans consigne.txt, affecré par verrouConsigne
{

   float thermostat_f = 0;
   FILE *lock = NULL;
   if (access(".verrouConsigne", F_OK)) // si le fichier existe
   {
      // verrou data n'existe pas, on peut lire et le créer
      lock = fopen(".verrouConsigne", "w");
      FILE *consigne = fopen("consigne.txt", "r");
      fscanf(consigne, "%f", &thermostat_f);
      fclose(consigne);
      fclose(lock);
      remove(".verrouConsigne");
   }
   else
   {
      //verrou data existe, on écrit rien
      thermostat_f = thermostatPrec_f;
   }


   return thermostat_f;
}
