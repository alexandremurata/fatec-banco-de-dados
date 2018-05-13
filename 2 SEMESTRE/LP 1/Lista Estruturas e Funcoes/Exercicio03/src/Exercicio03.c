/*
 ============================================================================
 Name        : Exercicio03.c
 Author      : alexandre.murata
 Date		 : 05.2018
 Description : Faça um programa que use uma estrutura para armazenar os
 	 	 	   atributos de uma circunferência C,isto é, raio e centro.
 	 	 	   O programa deve permitir as seguintes funcionalidades:
 	 	 	   a) calcular comprimento da circunferência
 	 	 	   b) calcular a área do círculo envolto pela circunferência.
 	 	 	   Use funções.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

typedef struct circunferencia {
	float raio;
	float centro;
} *CIRCUNFERENCIA;

void calcularComprimentoCircunferencia(CIRCUNFERENCIA c) {
	printf("\n### CALCULAR COMPRIMENTO ###\n");

	float comprimento = 2 * M_PI * c->raio;

	printf("\nComprimento do circulo: %f", comprimento);
}

void calcularAreaCirculo(CIRCUNFERENCIA c) {
	printf("\n### CALCULAR AREA ###\n");
	float area = M_PI * pow(c->raio, 2);

	printf("\nArea do circulo: %f", area);
}


int main(void) {

	float raio, centro;

	printf("Informe o raio: ");
	fflush(stdin);
	scanf("%f", &raio);

	printf("Informe o centro: ");
	fflush(stdin);
	scanf("%f", &centro);

	CIRCUNFERENCIA temp = malloc(sizeof(struct circunferencia));
	if(temp != NULL) {
		temp->raio=raio;
		temp->centro=centro;
	}


	calcularComprimentoCircunferencia(temp);
	calcularAreaCirculo(temp);
	return 0;
}


