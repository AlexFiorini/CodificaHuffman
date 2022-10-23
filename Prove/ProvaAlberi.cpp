#include <stdio.h>
#include <malloc.h>
#define COUNT 10
#define N 255

typedef struct Nodo{
    int freq;	//Somma dei nodi nel nodo intermedio
    char *lett; //Non c'e^ nel nodo intermedio
    char *codifica;
    struct Nodo *sx;
    struct Nodo *dx;
}Nodo;

Nodo* Crea();
void swap(Nodo* xp, Nodo* yp);
void selectionSort();
void sommanodi(Nodo* f, Nodo* q);
void inorder(Nodo * f);
void print2DUtil(Nodo * root, int space);
void print2D(Nodo * root);

Nodo **p = new Nodo *[N];

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
		if(p[i]!=NULL);
	}

	
	while(p[1]!=NULL)
	{
		
		sommanodi(p[0], p[1]);
		
		for(i=0; i<N; i++)
		{
			if(p[i]!=NULL)
			if(p[i]!=NULL && (p[i]->sx!=NULL && p[i]->dx!=NULL));
		}	
	}
	print2D(p[0]);
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

void spostanull()
{
	int i=0;
	
	do
	{		
		p[i]=p[i+1];
		p[i+1]=NULL;
		i++;
	}while(p[i+1]!=NULL);
}

void sommanodi(Nodo* f, Nodo* q)
{
	Nodo* inte=(Nodo*)malloc(sizeof(Nodo));
	inte->dx=(Nodo*)malloc(sizeof(Nodo));
	inte->sx=(Nodo*)malloc(sizeof(Nodo));
	inte->freq=f->freq+q->freq;
	
	if(f->freq>=q->freq)
	{
		inte->dx=f;
		inte->sx=q;
	}
	else
	{
		inte->dx=q;
		inte->sx=f;
	}
	
	p[1]=inte; //p[1] mettici il nuovo puntatore
	p[0]=NULL; //p[0] mettici NULL
	
	spostanull();
	selectionSort();
}

void inorder(Nodo *f)
{
	if(f!=NULL)
	{
		inorder(f->sx);
		printf("numero: %d\n", f->freq);
		inorder(f->dx);
	}
}

void print2DUtil(Nodo * root, int space) {
  // Base case
  if (root == NULL)
    return;

  // Increase distance between levels
  space += COUNT;

  // Process right child first
  print2DUtil(root -> dx, space);

  // Print current node after space
  // count
  printf("\n");
  for (int i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", root -> freq);

  // Process left child
  print2DUtil(root -> sx, space);
}

void print2D(Nodo * root) {
  // Pass initial space count as 0
  print2DUtil(root, 0);
}


