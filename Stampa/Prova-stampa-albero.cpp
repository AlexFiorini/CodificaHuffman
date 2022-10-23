#include <stdio.h>
#include <malloc.h>

typedef struct Nodo{
    int freq;	//Somma dei nodi nel nodo intermedio
    char lett; //Non c'e^ nel nodo intermedio
    char *codifica;
    struct Nodo *sx;
    struct Nodo *dx;
}Nodo;

int _print_t(Nodo * tree, int is_left, int offset, int depth, char s[20][255]) {
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%c)", tree -> lett);

    int left = _print_t(tree -> sx, 1, offset, depth + 1, s);
    int right = _print_t(tree -> dx, 0, offset + left + width, depth + 1, s);

    #ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';

        s[depth - 1][offset + left + width / 2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';

        s[depth - 1][offset + left + width / 2] = '.';
    }
    #else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }
    #endif

    return left + width + right;
}

void Stampaalbero(Nodo * tree) {
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

int main() {
    Nodo * punt;
    int i = 0, cerca;

    radice = Crea();

    while (i < 5) {
        punt = Crea();
        Inserisci(radice, punt);
        i++;
    };

    Stampaalbero(radice);
}
