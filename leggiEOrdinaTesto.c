#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXY 1024

void stampa(char **c){
	for(int i=0; c[i]; i++)
		printf("%s\n", c[i]);	
}

void ordina(char **t){
	int i, j;
	char *dep;
	for(i = 0; t[i+1]; i++)
		for(j=i+1; t[j]; j++)
			if(strcmp(t[i], t[j]) > 0)
				{
					dep = t[i];
					t[i] = t[j];
					t[j] = dep;
				}	
}

int main() {
	char **testo;
	FILE *fr;
	char riga[MAXY + 1];
	char str[255];
	printf("Inserisci nome file di testo.txt: ");
	scanf("%s", str);
	fr = fopen(str, "r");
	if (fr == NULL)
		exit(1);
	int c, i, righe = 0;
	while ((c = getc(fr)) != EOF)
		if (c == '\n')
			righe++;
	fclose(fr);

	fr = fopen(str, "r");
	if (fr == NULL)
		exit(1);
	testo = malloc((righe + 1) * sizeof(char*));
	for (i = 0; i < righe; i++) {
		fgets(riga, MAXY, fr);
		riga[strlen(riga) - 1] = '\0';
		testo[i] = malloc(strlen(riga) +1);
		strcpy(testo[i], riga);
	}
	testo[i] = NULL;

	ordina(testo);
	stampa(testo);
	
	system("pause");

	return 0;
}
