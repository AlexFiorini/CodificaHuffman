#include <stdio.h>
#include <malloc.h>
#define COUNT 10
#define N 255

typedef struct Nodo{
    int freq;	//Somma dei nodi nel nodo intermedio
    char lett; //Non c'e^ nel nodo intermedio
    struct Nodo *sx;
    struct Nodo *dx;
}Nodo;

Nodo* Crea();
void swap(Nodo* xp, Nodo* yp);
void selectionSort();


Nodo *radice;
Nodo **p = new Nodo *[N];
//Nodo **inte = new Nodo *[128];

int main()
{   
    int i=0;
	
	for(i=0; i<N; i++)
	{
		p[i]=NULL;
	}
	
	for(i=0; i<5; i++)
	{
		p[i]=Crea();
	};
	
	selectionSort();
	
	for(i=0; i<N; i++)
	{
		if(p[i]!=NULL)
		printf("%d\n", p[i]->freq);
	}
}

Nodo* Crea()
{
	Nodo *p;
	
	p=(Nodo*)malloc(sizeof(Nodo));
	p->sx=NULL;
	p->dx=NULL;
	printf("Inserisci numero: ");
	scanf("%d", &p->freq);
	return p;
}
 
void selectionSort()
{
    int i, j, min_idx;
    
    
    for(i=0; i<N; i++) 
	{
		if(p[i]!=NULL)
		{
			// min_idx = posizione del minore
	        min_idx=i;
		
			for(j=i+1; j<N; j++)
	        {
	        	if(p[j]!=NULL)
	        	{
	        		if(p[j]->freq < p[min_idx]->freq)
		            {
		            	min_idx=j;
					}
				}
			}
	        if(min_idx!=i)
	        {
	        	Nodo* temp = p[min_idx];
				p[min_idx] =  p[i];
				p[i] = temp;
			}	
		}
    }
}
