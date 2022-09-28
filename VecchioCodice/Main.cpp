#include <bits/stdc++.h>

#include "include/geco.cpp"							//Genera Entità numeriche Converti e Ottieni
#include "include/matrice.cpp"						//Operazioni sulle matrici

struct posizione									//Numeri a 4-bit
{
	unsigned p:4;
	unsigned p2:4;
}errore;


int main()
{
	int t[11]={}, r[11]={}, i=0, err=0, trov=0, giusto=0;
	int **ht=0, **hr=0;	
	
	errore.p=0, errore.p2=0;
	
	srand(time(NULL));
	
	//Punto 1
	printf("Il numero generato e':\n");
	binario(t);
	
	//Punto 2
	ht=creamat(ht);
	riempi(ht,t);
	
	//Punto 3
	for(i=0;i<4;i++)
	{
		mettibitp(pow(2,i), ht);
	}
	
	//Punto 4
	mettibitp(0,ht);
	
	//Punto 5
	printf("\n");
	stampamat(ht);
	
	//Punto 6
	hr=creamat(hr);
	copiamat(ht,hr);
	errore.p=creaerr(hr);
	
	//Punto 7
	err=conbitg(hr);
	
	//Punto 8
	for(i=0;i<4;i++)
	{		
		trov=trovaerr(pow(2,i), hr);
		if(trov)
		{
			errore.p2+=pow(2,i);
		}
	}
	if(errore.p==errore.p2)
	{
		//Punto 9
		correrr(errore.p2, hr);
		
		//Punto 10
		ottieni(r, hr);
		for(i=0;i<11;i++)
		{
			if(t[i]==r[i])
			{
				giusto++;	
			}
		}
		if(giusto==11)
		{
			printf("Programma eseguito correttamente\n");
		}
		else
		{
			printf("Il programma ha riscontrato un errore\n");
			return 411;
		}
	}
	else
	{
		printf("Errore non trovato\n");
		return 404;
	}
	
	//Fine
	printf("\nCleaning up memory...\n");
    for (int h=0; h<4; h++)
	{
    	delete [] ht[h];
	}
	for (int h=0; h<4; h++)
	{
    	delete [] hr[h];
	}
	delete [] ht;
	delete [] hr;
	ht=0;
	hr=0;
	printf("Done...");
	return 200;
}
