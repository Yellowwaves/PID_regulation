#include <stdio.h>
#include <stdlib.h> //http://www.ferdinandpiette.com/blog/2011/08/implementer-un-pid-sans-faire-de-calculs/
#include "regulation.h"

float regulationTest(int regul, float consigne, float *tabT, int nT)
{ // ce fichier permet de réguler la puissance, en fonction de régul on choisit le mode Tor ou PID
	float cmd;
	float Kp = 1;
	float Ki = 0.1;
	float Kd = 0.1;
	float P = 0;
	float I = 0;
	float D = 0;
	float erreur = 0;
	

		if (regul == 1)
		{ // Mode Tor
			if (consigne >= tabT[nT - 1])
			{
				cmd = 50; // on allume le chauffage
			}
			else
			{
				cmd = 0; // on éteint le chauffage
			}
		}
		if (regul == 2)
		{ // Mode PID
			for (int compteur = 0; compteur < nT; compteur++)
		{
			P=Kp*(consigne-tabT[compteur]);
			I=Ki*10*(consigne-(tabT[compteur]-tabT[compteur-1]));
			erreur+=I;
			D=(tabT[compteur]-tabT[compteur-1])/10*Kd;
			cmd=P+erreur+D;
		}
		}
		return cmd;
	
}

