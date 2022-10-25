#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#include <bits/stdc++.h>
#define COUNT 10
#define N 255

using namespace std;

typedef struct Nodo{
    int freq;	//Somma dei nodi nel nodo intermedio
    char lett;  //Vale (char)3 nel nodo intermedio
    int codifica[255];
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
void codificacaratteri(Nodo* f, char lettera, int i, int codi[]);
//Stampa albero
void print2DUtil(Nodo * root, int space);
void Stampaalbero(Nodo * tree);
int _print_t(Nodo * tree, int is_left, int offset, int depth, char s[20][255]);


Nodo **p = new Nodo *[N];

int main()
{	
    int i=0, freq[N], codifica[N], lettere[N];
	char *stringa;
	for(i=0; i<N; i++)
	{
		p[i]=NULL;
		freq[i]=0;
		codifica[i]=2;
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
	//printf("Stampa albero\n");
	//Stampaalbero(p[0]);
	print2DUtil(p[0],0);
	for(i=0; i<N; i++)
	{
		if(lettere[i]==1)
		{
			codificacaratteri(p[0], (char)i, 0, codifica);
			printf("%c -> ", char(i));
			for(i=0; i<N; i++)
			{
				if(codifica[i]>1)
					printf("%d", codifica[i]);
			}
			printf("\n");
		}
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
	
	for(i=0; i<N; i++)
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

void codificacaratteri(Nodo* f, char lettera, int i, int codi[])
{
	if(f!=NULL)
	{
		if(f->lett==lettera)
		{
			for(int j=0; j<N; j++)
			{
				f->codifica[j]=codi[j];
			}
		}
		else
		{
			if(f->sx->lett==lettera)
			{
				codi[i]=0;
			}
			else
			{
				codi[i]=1;
				i++;
				codificacaratteri(f->dx, lettera, i, codi);
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

void Stampaalbero(Nodo * tree) 
{
    char s[20][N];
    int i;
    
    for (i=0; i<20; i++)
    {
   		sprintf(s[i], "%80s", " ");
	}
        

    _print_t(tree, 0, 0, 0, s);

    for (i=0; i<20; i++)
    {
        printf("%s\n", s[i]);
	}
}

int _print_t(Nodo * tree, int is_left, int offset, int depth, char s[20][N]) 
{
    char b[20];
    int width=3, left, right, i;

    if (!tree)
	{
    	return 0;	
	}

    sprintf(b, "(%c)", tree -> lett);

    left = _print_t(tree -> sx, 1, offset, depth + 1, s);
    right = _print_t(tree -> dx, 0, offset + left + width, depth + 1, s);

    for (i=0; i<width; i++)
    {
    	s[2 * depth][offset + left + i] = b[i];
	}
	
    if (depth && is_left) 
	{

        for (i=0; i<width+right; i++)
        {
        	s[2 * depth - 1][offset + left + width / 2 + i] = '-';
		}
		
        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';
    } 
	else if (depth && !is_left) 
	{

        for ( i=0; i<left+width; i++)
        {
        	s[2 * depth - 1][offset - width / 2 + i] = '-';	
		}

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }

    return left + width + right;
}
