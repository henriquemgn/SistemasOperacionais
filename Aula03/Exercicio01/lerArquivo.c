#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *arquivo;

	char nomeArquivo[100], c;

	printf("Digite o nome do arquivo \n");
	scanf("%s", nomeArquivo);

	arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	c = fgetc(arquivo);
	while (c != EOF)
	{
		printf ("%c", c);
		c = fgetc(arquivo);
	}

	fclose(arquivo);
	return 0;
}
