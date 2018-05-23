/*
 ============================================================================
 Name        : Colaborador.c
 Author      : alexandre.murata
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> /*Biblioteca para usar o tolower*/
#include <math.h>
#define MAX 10000

typedef struct colaborador {
	char nome[21];
	float salario;
} COLABOR;

COLABOR *c[MAX];
int contador = 0;

void cadastrar();
void listarPorNome(char nome[21]);
char listarPorSalario(float salario);

int main(void) {
	char option;
	char name[21];
	float salario;
	do {
		printf(
				"\na - Cadastrar"
				"\nb - Listar por nome"
				"\nc - Listar por salario"
				"\ns - SAIR");
		scanf("%s", &option);
		switch (tolower(option)) {
		case 'a':
			cadastrar();
			break;

		case 'b':
			printf("\nInforme o nome do colaborador: ");
			scanf(" %[^\n]s", name);
			listarPorNome(name);
			break;

		case 'c':
			printf("\Informe o salario do colaborador: ");
			scanf("%f", &salario);
			printf("\nNome: %s", listarPorSalario(salario));
			break;

		case 's':
			break;

		default:
			printf("\nOperacao invalida");

		}
	} while (option != 's');
	return 0;
}

void cadastrar() {
	char name[21];
	c[contador] = malloc(sizeof(COLABOR));

	printf("\nNome: ");
	scanf(" %[^\n]s", name);
	strcpy(c[contador]->nome, name);
	printf("\nSalario: ");
	scanf("%f", &c[contador]->salario);
	contador++;
}

void listarPorNome(char nome[21]) {
	for (int i = 0; i < contador; i++) {
		if (strcmp(c[i]->nome, nome) == 0) {
			printf("\nNome: %s\nSalario: %.2f", c[i]->nome, c[i]->salario);
		}
	}
}

char listarPorSalario(float salario) {
	char no;
	for (int i = 0; i < contador; i++) {
		if (salario == c[i]->salario) {
			strcpy(no, c[i]->nome);
			return no;
		}
	}
}
