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


int main(void) {

	PESSOA person[10];
	char name[31];
	int age;

	for(int i = 0 ; i < 10 ; i++) {
		printf("\nInforme o nome: ");
		fflush(stdin);
		scanf("%s", name);
		strcpy(person[i].nome, name);
		printf("\nInforme a idade: ");
		fflush(stdin);
		scanf("%i", &age);
		person[i].idade = age;

	}
	system("pause");
	return 0;
}
