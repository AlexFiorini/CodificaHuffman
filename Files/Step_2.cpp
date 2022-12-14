#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#define COUNT 10
#define N 255

using namespace std;

typedef struct Nodo{
    int freq;						//Somma dei nodi nel nodo intermedio
    char lett;  					//Vale (char)3 nel nodo intermedio
    char codifica[N];
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
void codificacaratteri(Nodo* f, char lettera, char* codi);
void salvacod(Nodo* f);
//Step 2.3
char* codificapar(char *stringa);
char* recuperacod(char lettera);
//Step 2.4
void decodepar(Nodo *f, char *stringa);
//Stampa albero
void Stampaalbero(Nodo * root, int space);



Nodo **p = new Nodo *[N];

int main()
{	
    int i=0, j=0, freq[N], lettere[N];
	char *stringa, *parola, codi[N];
	FILE *fp=fopen("Codifiche.txt", "wt");
	
	for(i=0; i<N; i++)
	{
		p[i]=NULL;
		freq[i]=0;
		lettere[i]=0;
	}
	printf("Inserisci stringa\n");
	stringa=readinput();
	
	system("pause");
	system("cls");

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

	Stampaalbero(p[0],0);
	
	printf("\n");
	
	for(i=0; i<N; i++)
	{
		strcpy(codi, "");
		if(lettere[i]==1)
		{
			
			codificacaratteri(p[0], (char)i, codi);
			printf("%c ", (char)i);
			printf("%s\n", codi);
			fprintf(fp, "%c ", char(i));
			fprintf(fp,"%s", codi);
			fprintf(fp, "\n");	
		}
	}
	fclose(fp);
	
	salvacod(p[0]);
	parola=codificapar(stringa);
	printf("\n");
	printf("Parola codificata: %s\n", parola);
	printf("Stringa originale: ");
	decodepar(p[0], parola);
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
		
			min_idx=i; // min_idx = posizione del minore

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
}

void codificacaratteri(Nodo* f, char lettera, char* codi)
{
	int j;
	
	if(f!=NULL)
	{
		if(f->lett!=lettera)
		{
			if(f->sx->lett==lettera)
			{
				strcat(codi, "0");
			}
			else
			{
				strcat(codi,"1");
				codificacaratteri(f->dx, lettera, codi);
			}
		}
	}
}

void salvacod(Nodo* f)
{
	char lett, c, nul[N];
	FILE *fp=fopen("Codifiche.txt", "r");
	int i, flag=0;
	fseek(fp, 0, SEEK_END);
	unsigned long position, end=ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	if(f!=NULL)
	{
		if(f->lett==(char)3)
		{
			fclose(fp);
			salvacod(f->sx);
			salvacod(f->dx);	
		}
		else
		{
			do
			{
				i=-1;
				fscanf(fp, "%c", &lett);						//Leggi lettera
				if(lett!=f->lett)
				{
						fscanf(fp, "%c", &c);		//Leggi spazio
						fgets(nul, N, fp);			//Leggi stringa
				}
				else
				{
					c=fgetc(fp);					//Spazio
					position=ftell(fp);				//Salva posizione prima cifra
					do
					{
						c=fgetc(fp);
						i++;
					}while(c=='1' || c=='0');		//Calcola dimensioni codifica
					fseek(fp, position, SEEK_SET);	//Torna alla prima cifra
					
					char codifica[i];				//Crea array
					fgets(codifica, N, fp);			//Leggi codifica
					//f->codifica=codifica;
					strcpy(f->codifica, codifica);
					fclose(fp);
					salvacod(f->sx);
					salvacod(f->dx);
					flag=1;
				}
			}while(ftell(fp)!=end && flag!=1);
		}
	}
	fclose(fp);
}

char* codificapar(char *stringa)
{
	char parola[N]="", codifica[N];
	int i=0, j=strlen(stringa);
	do
	{
		char *codi=recuperacod(stringa[i]);
		strcpy(codifica, codi);
		strcat(parola, codi);
		i++;
	}while(i<j-1);
	return parola;
}

char* recuperacod(char lettera)
{
    char lett, c, nul[N], car[N], *six=NULL, *dix=NULL;
    FILE *fp=fopen("Codifiche.txt", "r");
	while(!feof(fp))
	{
		fscanf(fp, "%c", &lett);            //Leggi lettera
		if(lett==lettera)
		{
			fscanf(fp, "%c", &c);         //Leggi spazio
			fgets(car, N, fp);            //Leggi stringa
			fclose(fp);
			for(int i = 0; i < N; i++)
			{
				if(car[i]==char(10) || car[i]==char(13))
				{
					car[i] = (char) 0;
				}
			}
			return car;
		}
		else
		{
			fscanf(fp, "%c", &c);         //Leggi spazio
			fgets(car, N, fp);            //Leggi stringa
		}
	}
}

void decodepar(Nodo *f, char *stringa)
{
	int i=0;
	do
	{
		if(stringa[i]=='0')
		{
			f=f->sx;
			printf("%c", f->lett);
			f=p[0];
		}
		else if(stringa[i]=='1')
		{
			if(f->dx!=NULL)
			{
				f=f->dx;
				if(f->lett!=(char)3)
				{
					printf("%c", f->lett);
					f=p[0];
				}
			}
		}
		i++;
	} while(stringa[i]!='\0');
	
}

void Stampaalbero(Nodo * root, int space) 
{
    if (root == NULL)
        return;

	space += COUNT;

	Stampaalbero(root -> dx, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");

    printf("%c\n", root -> lett);
    
    Stampaalbero(root -> sx, space);
}