#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#include <bits/stdc++.h>
#define COUNT 10
#define N 255

//ashdihewqiurhiuehzkjhdiasuhdiuheriuwheiurhw

using namespace std;

typedef struct Codifica{
	int val;
	struct Codifica *succ;
}Codifica;

typedef struct Nodo{
    int freq;	//Somma dei nodi nel nodo intermedio
    char lett;  //Vale (char)3 nel nodo intermedio
    Codifica *codifica;
    struct Nodo *sx;
    struct Nodo *dx;
}Nodo;

Nodo* Crea(char lett, int freq);
char* readinput();
void contacaratteri(char* arr, int freq[]);
void presenza(char* arr, int lett[]);
//Ordinamento e somma
void selectionSort();
void spostanull();
void sommanodi(Nodo* f, Nodo* q);
//Step 2.2
void codificacaratteri(Nodo* f, char lettera, int i, Codifica* codi);
//Stampa albero
void print2DUtil(Nodo * root, int space);

Nodo **p = new Nodo *[N];

int main()
{	
    int i=0, j=0, freq[N], lettere[N];
	char *stringa;
	Codifica *codi, *pointer;
	
	for(i=0; i<N; i++)
	{
		p[i]=NULL;
		freq[i]=0;
		lettere[i]=0;
	}
	
	stringa=readinput();
	contacaratteri(stringa, freq);
	presenza(stringa, lettere);
	
	for(i=0; i<N; i++)
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
	}
	
	print2DUtil(p[0],0);
	
	for(i=0; i<N; i++)
	{
		codi=(Codifica*)malloc(sizeof(Codifica));
		if(lettere[i]==1)
		{
			codificacaratteri(p[0], (char)i, 0, codi);
			printf("%c -> ", char(i));
			pointer=codi;
			do
			{
				printf("%d", pointer->val);
				pointer=pointer->succ;
			}while(pointer!=NULL);
			printf("\n");
		}
		free(codi);
	}	
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
	
	for(i=0;i<=N;i++)
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

void presenza(char* arr, int lett[])
{
	int i, j=0;
	
	for(i=0; i<=N; i++)
	{
		if(i!=10 && i!=13)
		{
			do
			{
				if((char)i==arr[j])
				{
					lett[i]=1;
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
	for(j=0;j<N;j++)
	{
		for(i=0;i<N;i++)
		{
			if(p[i]==NULL)
			{
				p[i]=p[i+1];
				p[i+1]=NULL;
			}
		}
	}
}

void spostanodiint()
{
	int k, l, i;
	Nodo *temp=NULL;
	
	for(l=0;l<N;l++)
	{
		for(k=1;k<N;k++)
		{
			if((p[l]!=NULL && p[k]!=NULL) && (p[l]->lett == (char)3) && (p[k]->freq == p[k]->freq))
			{
				temp=p[l];
				p[l]=p[k];
				p[k]=temp;
				Sleep(1);
			}
		}
	}
}

void sommanodi(Nodo* f, Nodo* q)		//Somma i nodi e metti in nodo intermedio
{
	int i;
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
	spostanodiint();
	
	for(i=0; i<N; i++)
	{
		if(p[i]!=NULL)
		printf("i=%d val=%d lett=%c\n", i, p[i]->freq, p[i]->lett);
	}
	printf("\n\n");
}

void codificacaratteri(Nodo* f, char lettera, int i, Codifica* codi)
{
	int j;
	
	if(f!=NULL)
	{
		if(f->lett==lettera)
		{
			f->codifica=codi;
		}
		else
		{
			if(f->sx->lett==lettera)
			{
				codi->val=0;
				f->codifica=codi;
			}
			else
			{
				codi->val=1;
				i++;
				codi->succ=(Codifica*)malloc(sizeof(Codifica));
				codificacaratteri(f->dx, lettera, i, codi->succ);
			}
		}
	}
}

void print2DUtil(Nodo * root, int space) 
{
    if (root == NULL)
        return;

	space += COUNT;

	print2DUtil(root -> dx, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");

    printf("%c\n", root -> lett);
    
    print2DUtil(root -> sx, space);
}
