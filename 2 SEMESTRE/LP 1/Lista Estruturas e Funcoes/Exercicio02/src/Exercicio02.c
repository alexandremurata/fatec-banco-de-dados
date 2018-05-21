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
#include <ctype.h> /*Biblioteca para usar o tolower*/

typedef struct {
	char nome[31];
	char rg[10];
	int anoNascimento;
} PESSOA;

PESSOA *person[10];
int contadorPessoa = 0;

void cadastrar();
void calcularIdade();
void listarApartir();
void listarAntes();
void pesquisarRg();

int main(void) {

	char option;

	do {
		printf("\na-Cadastrar "
				"\nb-Calcular idade "
				"\nc-Listar Pessoas Nascidas A Partir "
				"\nd-Listar Pessoas Nascidas Antes "
				"\ne-Pesquisar por RG "
				"\ns-Sair\n");
		fflush(stdin);
		scanf("%s", &option);

		switch (tolower(option)) {
		case 'a':
			cadastrar();
			break;
		case 'b':
			calcularIdade();
			break;
		case 'c':
			listarApartir();
			break;
		case 'd':
			listarAntes();
			break;
		case 'e':
			pesquisarRg();
			break;
		case 's':
			break;
		default:
			printf("\nOpcao Invalida");
		}

	} while (option != 's');

	return 0;
}

void cadastrar() {

	printf("\n #### CADASTRAR ####\n");

	person[contadorPessoa] = malloc(sizeof(PESSOA));

	char name[31];
	char rg[10];

	printf("\nInforme o nome: ");
	scanf(" %[^\n]s", name);
	strcpy(person[contadorPessoa]->nome, name);
	printf("\nInforme o rg: ");
	scanf(" %[^\n]s", rg);
	strcpy(person[contadorPessoa]->rg, rg);
	printf("\nInforme o ano de nascimento: ");
	scanf(" %d", &person[contadorPessoa]->anoNascimento);

	contadorPessoa++;

}

void calcularIdade() {
	printf("\n #### CALCULAR IDADE ####\n");
	char name[31];
	int age;

	for (int i = 0; i < contadorPessoa; i++) {
		printf("\n %s", person[i]->nome);
	}

	printf("\Escolha um nome: ");
	scanf(" %[^\n]s", name);

	for (int i = 0; i < contadorPessoa; i++) {
		if (strcmp(name, person[i]->nome) == 0) {
			age = 2018 - person[i]->anoNascimento;
			printf("\nIdade: %d", age);
		}
	}

}

void listarApartir() {
	printf("\n #### CALCULAR IDADE ####\n");
	int year;

	printf("\nInforme um ano: ");
	scanf("%d", &year);
	for (int i = 0; i < contadorPessoa; i++) {
		if (year < person[i]->anoNascimento) {
			printf("\n %s", person[i]->nome);
		}
	}
}

void listarAntes() {
	printf("\n #### CALCULAR IDADE ####\n");
	int year;

	printf("\nInforme um ano: ");
	scanf("%d", &year);
	for (int i = 0; i < contadorPessoa; i++) {
		if (year > person[i]->anoNascimento) {
			printf("\n %s", person[i]->nome);
		}
	}

}

void pesquisarRg() {
	printf("\n #### CALCULAR IDADE ####\n");
	char rg[10];

	printf("\nInforme um RG: ");
	scanf(" %[^\n]s", &rg);

	for (int i = 0; i < contadorPessoa; i++) {
		if (rg == person[i]->rg) {
			printf("\n %s", person[i]->nome);
		}
	}

}
