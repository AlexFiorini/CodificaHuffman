#include <stdio.h>
#include <malloc.h>
#define COUNT 10

typedef struct Nodo{
    int freq;	//Somma dei nodi nel nodo intermedio
    char lett; //Non c'è nel nodo intermedio
    struct Nodo *sx;
    struct Nodo *dx;
}Nodo;

Nodo* Crea();
Nodo* Inserisci();
void swap(int* xp, int* yp);
void selectionSort(Nodo* arr[], int n);


Nodo *radice;
Nodo **p = new Nodo *[255];
Nodo **inte = new Nodo *[128];

int main()
{   
    int i=0;
	
	for(i=0; i<5; i++)
	{
		p[i]=Crea();
	};
	
	selectionSort(p, 255);
	
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

Nodo* Inserisci()
{
	Nodo *p;
	p=(Nodo*)malloc(sizeof(Nodo));
	p->sx=NULL;
	p->dx=NULL;
	
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// Function to perform Selection Sort
void selectionSort(Nodo* arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (p[j]->freq < p[min_idx]->freq)
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
