#include <stdio.h>
#include <stdlib.h> // For exit()

int main()
{
	FILE *arquivo;

	char nomeArquivo[100], c;

	printf("Digite o nome do arquivo \n");
	scanf("%s", nomeArquivo);

	// Open file
	arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	// Read contents from file
	c = fgetc(arquivo);
	while (c != EOF)
	{
		printf ("%c", c);
		c = fgetc(arquivo);
	}

	fclose(arquivo);
	return 0;
}
