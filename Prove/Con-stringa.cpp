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

char* readinput()
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

void contacaratteri(char* arr, int freq[])
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
