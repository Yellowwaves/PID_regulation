#include <stdio.h>
#include <stdlib.h> 
#include "visualisationC.h"
#include "define.h"
#include "visualisationT.h"
#include "consigne.h"
#include "regulation.h"
#include "autotests.h" 
int main(){
float score1=0,score2=0,score3=0,score4=0,score5=0;
score1 = testVisualisationT();
score2 = testConsigne();
score3 = testVisualisationC();
score4 = testRegulationTOR();
score5 = testRegulationPID(); 

printf("Test de visualisation T=%g%%\n",score1*100);
printf("Test de consigne =%g %%\n",score2*100);
printf("Test de visu C=%g %%\n",score3*100);
printf("Test de TOR=%g %%\n",score4*100);
printf("Test de PID=%g %%\n",score5*100);
return EXIT_SUCCESS; 
}