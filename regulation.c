#include <stdio.h>
#include <stdlib.h> //http://www.ferdinandpiette.com/blog/2011/08/implementer-un-pid-sans-faire-de-calculs/
#include "regulation.h"

float regulationTest(int regul, float consigne, float *tabT, int nT)
{ // ce fichier permet de réguler la puissance, en fonction de régul on choisit le mode Tor ou PID
	float cmd;
	float Kp = 1;
	float Ki = 0.1;
	float Kd = 0.1;
	float integral_erreur = 0;
	float pid = 0;
	float erreur=0;
	float erreur_précédente = 0;
	float variation_erreur = 0;
	float somme_erreurs = 0;

	

	if (regul == 1)
	{ // Mode Tor
		if (consigne >= tabT[nT - 1])
		{
			cmd = 0; // on coupe le chauffage
		}
		else
		{
			cmd = 50; // on met à 50% la puissance de chauffage
		}
	}
	if (regul == 0)
	{ // Mode PID
		erreur = consigne - tabT[nT - 1];
		somme_erreurs += erreur;
		variation_erreur = erreur - erreur_précédente;
		pid = Kp * erreur + Ki * somme_erreurs + Kd * variation_erreur;
		erreur_précédente = erreur;
	}
	return cmd;
}
