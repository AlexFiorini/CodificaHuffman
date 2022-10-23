#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#define COUNT 10
#define N 255

typedef struct Nodo{
    int freq;	//Somma dei nodi nel nodo intermedio
    char lett; //Non c'e^ nel nodo intermedio
    char *codifica;
    struct Nodo *sx;
    struct Nodo *dx;
}Nodo;

Nodo* Crea(char lett, int freq);
char* readinput();
void contacaratteri(char* arr, int freq[]);
void swap(Nodo* xp, Nodo* yp);
void selectionSort();
void sommanodi(Nodo* f, Nodo* q);
void inorder(Nodo * f);
void print2DUtil(Nodo * root, int space);
void spostanull();

Nodo **p = new Nodo *[N];

int main()
{	
    int i=0, freq[255];
	
	for(i=0; i<N; i++)
	{
		p[i]=NULL;
		freq[i]=0;
	}
	
	contacaratteri(readinput(), freq);
	
	for(i=0; i<255; i++)
	{			
		if(freq[i]!=0)
		{
			p[i]=Crea((char)i, freq[i]);
		}
		else
		{
			p[i]=NULL;
		}
	}
	spostanull();
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
	printf("Stampa albero\n");
	inorder(p[0]);
}

Nodo* Crea(char lett, int freq)
{
	Nodo *p;
	p=(Nodo*)malloc(sizeof(Nodo));
	p->freq=freq;
	p->lett=lett;
	p->sx=NULL;
	p->dx=NULL;
	return p;
}

char* readinput()		//Leggi stringa in ingresso da tastiera
{
#define CHUNK 200
   char* input = NULL;
   char tempbuf[CHUNK];
   size_t inputlen = 0, templen = 0;
   do {
       fgets(tempbuf, CHUNK, stdin);
       templen = strlen(tempbuf);
       input = (char*)realloc(input, inputlen+templen+1);
       strcpy(input+inputlen, tempbuf);
       inputlen += templen;
    } while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');
    return input;
}

void contacaratteri(char* arr, int freq[])		//Calcola frequenza lettere
{
	int i=0, j=0;
	
	for(i=0;i<=255;i++)
	{
		if(i!=10 && i!=13)
		{
			do
			{
				if((char)i==arr[j])
				{
					freq[i]++;
				}
				j++;
			}while(arr[j]!='\0');
			j=0;
		}
	}
}

void selectionSort()					//Riordina array p
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

void spostanull()						//Metti i null alla fine di array p
{
	int i, j;
	for(j=0;j<255;j++)
	{
		for(i=0;i<255;i++)
		{
			if(p[i]==NULL)
			{
				p[i]=p[i+1];
				p[i+1]=NULL;
			}
		}
	}
}

void sommanodi(Nodo* f, Nodo* q)		//Somma i nodi e metti in nodo intermedio
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
	inte->lett=(char)3;
	
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
		if(f->lett!=(char)3)
		printf("lettera: %c\n", f->lett);
		inorder(f->dx);
	}
}

void print2DUtil(Nodo * root, int space) {
    if (root == NULL)
        return;

	space += COUNT;

	print2DUtil(root -> dx, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");

    if(root->lett!=(char)3)
    printf("%c\n", root -> lett);
    
    print2DUtil(root -> sx, space);
}
