/*
 ============================================================================
 Name        : Exercicio02.c
 Author      : alexandre.murata
 Date		 : 05.2018
 Description : Crie um programa, utilizando um vetor de struct que guarda o
 	 	 	   nome, RG e ano de nascimento de,no máximo, 10 pessoas.
 	 	 	   O programa permite as seguintes funcionalidades, conforme
 	 	 	   escolha do usuário:
 	 	 	   a - Cadastrar uma pessoa;
 	 	 	   b - Calcular a idade de uma pessoa selecionada pelo usuário;
 	 	 	   c - Listar pessoas que nasceram a partir de um determinado ano;
 	 	 	   d - Listar pessoas que nasceram antes de um determinado ano;
 	 	 	   e- Encontrar o nome de uma pessoa com determinado RG;
 	 	 	   s- Sair.
 	 	 	   O programa deverá ser executado em loop até o usuário digitar
 	 	 	   a opção s. Implemente funções para as opções disponíveis
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[31];
	char rg[10];
	int anoNascimento;
} PESSOA;


PESSOA person[10];
int contadorPessoa = 0;



void cadastrar();

int main(void) {

	char option;

	do {
		printf("\na-Cadastrar \nb-Calcular idade \nc-Listar Pessoas Nascidas A Partir \nd-Listar Pessoas Nascidas Antes \ne-Pesquisar por RG \ns-Sair\n");
		fflush(stdin);
		scanf("%s", &option);

		switch(option) {
		case 'a' : cadastrar();

		}

	} while (option != 's');



	system("pause");
	return 0;
}

void cadastrar() {

	char name[31];
	char rg[10];
	int birthday;

	printf("\nInforme o nome: ");
	fflush(stdin);
	scanf("%s", name);
	strcpy(person[contadorPessoa].nome, name);

	printf("\nInforme o rg: ");
	fflush(stdin);
	scanf("%s", rg);
	strcpy(person[contadorPessoa].rg, rg);

	printf("\nInforme o ano de nascimento: ");
	fflush(stdin);
	scanf("%i", &birthday);
	person[contadorPessoa].anoNascimento = birthday;

	contadorPessoa++;
}
