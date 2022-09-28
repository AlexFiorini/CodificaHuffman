#include <stdio.h>
#include <malloc.h>
#define COUNT 10

typedef struct Nodo{
    int freq;
    char lett;
    struct Nodo *sx;
    struct Nodo *dx;
}Nodo;

Nodo* Crea();
void Inserisci(Nodo* p, Nodo* n);
void Stampaord(Nodo* p);
void print2DUtil(struct Nodo * root, int space);

Nodo *radice;

int main()
{
    Nodo *punt;
    int i=0, cerca;
    
    radice=Crea();
	
	while(i<2)
	{
		punt=Crea();
		Inserisci(radice, punt);
		i++;	
	};
	
	i=0;
	printf("Dopo la radice\n");
	while(i<3)
	{
		punt=Crea();
		Inserisci(radice->dx, punt);
		i++;	
	};
	
	Stampaord(radice);
	printf("\n");
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

void Inserisci(Nodo* confronta, Nodo* p) 
{
	int a=confronta->freq/2;
	if(a>=(p->freq))
	{
		if(confronta->sx==NULL)		
		{
			confronta->sx=p;
		}
		else
		{
			Inserisci(confronta->sx, p);
		}
	}
	else
	{
		if(confronta->dx==NULL)
		{
			confronta->dx=p;
		}
		else
		{
			Inserisci(confronta->dx, p);
		}
	}
	
}

void print2DUtil(struct Nodo * root, int space) 
{
  if (root == NULL)
    return;

  space += COUNT;

  print2DUtil(root -> dx, space);

  printf("\n");
  for (int i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", root -> freq);

  print2DUtil(root -> sx, space);
}

void Stampaord(struct Nodo * p) {
  print2DUtil(p, 0);
}
