#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *arquivo;
	FILE *saida;

	char nomeArquivo[100], c;

	saida = fopen("saida.txt" ,"a");

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
		 fprintf(saida,"%c",c);
		c = fgetc(arquivo);
	}

	fclose(saida);
	fclose(arquivo);
	return 0;
}
