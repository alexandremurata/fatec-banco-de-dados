/*
 ============================================================================
 Name        : Exercicio01.c
 Author      : alexandre.murata
 Date		 : 05.2018
 Description : elabore um programa para cadastrar 10 pessoas.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[31];
	int idade;
} PESSOA;

int sizeList = 10;

int main(void) {

	PESSOA person[10];
	char name[31];
	int age;

	for(int i = 0 ; i < sizeList ; i++) {
		printf("\nInforme o nome: ");
		fflush(stdin);
		scanf("%s", name);
		strcpy(person[i].nome, name);
		printf("\nInforme a idade: ");
		fflush(stdin);
		scanf("%i", &age);
		person[i].idade = age;

	}

	for(int i = 0 ; i < sizeList ; i++) {
		printf("\n#####");
		printf("\nNome: %s \nIdade: %d", person[i].nome, person[i].idade);
		printf("\n#####");
	}

	system("pause");
	return 0;
}
