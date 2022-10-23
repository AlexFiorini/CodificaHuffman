#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    char* result = readinput();
    FILE *fp=fopen("file.txt", "w");
    fprintf(fp, "%s", result);
    free(result);
    return 0;
}
