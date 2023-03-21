#include <stdio.h>
#include <stdlib.h> //http://www.ferdinandpiette.com/blog/2011/08/implementer-un-pid-sans-faire-de-calculs/
#include "regulation.h"

float regulationTest(int regul, float consigne, float *tabT, int nT)
{ // ce fichier permet de réguler la puissance, en fonction de régul on choisit le mode Tor ou PID
	float cmd;
	float Kp = 1.1;
	float Ki = 0.2;
	float Kd = 0.15;
	float P = 0;
	float I = 0;
	float D = 0;
	float derivative = 0;
	float error = 0;
	float last_error = 0;
	float somme_erreur = 0;
	float integral = 0;

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
		for (int compteur = 1; compteur < nT; compteur++)
		{
			error = consigne - tabT[compteur];

			// if(compteur == 0)
			// {
			// 	break;
			// }
			// Calculate integral
			integral += error;
			// Calculate derivative
			derivative = (error - tabT[compteur - 1]);
			P = Kp * error;
			I= Ki * integral;
			D = Kd * derivative;

			// Calculate output
			cmd = P + I + D;
		}
	}
	if (cmd > 100.0)
	{
		cmd = 100.0;
	}
	else if (cmd < 0.0)
	{
		cmd = 0.0;
	}
	return cmd;
}
