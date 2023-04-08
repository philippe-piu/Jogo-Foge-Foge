#include<stdio.h>
#include<stdlib.h>
#include "foge.h"

//Variaveis Global
char** matmapa;
int linhas;
int colunas;

int main()
{
	int i;
	apresentacao();
	lermapa();

	//Impress�o
	for(i = 0; i < TAMANHO_SEGUNDO; i++)
	{
		printf("%s\n", matmapa[i]);
	}

	liberamapa();

	return(0);
}

//Fun��o de apresenta��o do Jogo
void apresentacao()
{
	printf("****************************************\n");
	printf("*Seja bem vindo ao nosso Jogo Foge Foge*\n");
	printf("****************************************\n");
	printf("\n");
}


//Fun��o LEitura do Mapa
void lermapa()
{
	//Matriz de 5 por 10
	int i;

	//Abrindo Arquivo com o mapa
	FILE *f;
	//fopen pega o arquivo e o r � para ele somente ler o arquivo
	f = fopen("mapa.txt", "r");
	//Se por acaso der erro no abrir o aquivo para leitura
	if(f == 0)
	{
		printf("Arquivo com problema tente novamente mais tarde\n");
		//Fecho o programa se der o erro
		exit(1);
	}

	//Ler os dois inteiros no arquivo e guardar na variavel linnhas e colunas
	fscanf(f, "%d %d", &linhas, &colunas);
	printf("Linhas %d colunas %d\n", linhas, colunas);

	alocamapa();

	//Leitura das informa��es do mapa
	for(i = 0; i < TAMANHO_SEGUNDO; i++)
	{
		fscanf(f, "%s", matmapa[i]);
	}

	//Fechamento do arquivo aberto no fopen
	fclose(f);

}

//Fun��o de Aloca��o do mapa
void alocamapa(){
	int i;
	//Alocando a Matriz o mapa no caso
	matmapa = malloc(sizeof(char*) * linhas);
	for(i = 0; i < linhas; i++)
	{
		matmapa[i]  = malloc(sizeof(char) * (colunas + 1));
	}
}

//Fun��o de liberar o mapa
void liberamapa()
{
	int i;
	//Liberando a Memoria
	for(i = 0; i < linhas; i++)
	{
		free(matmapa[i]);
	}
	free(matmapa);
}
