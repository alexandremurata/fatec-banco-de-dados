/*
 ============================================================================
 Name        : Exercicio04.c
 Author      : alexandre.murata
 Date		 : 05.2018
 Description : Usando o programa do WiFi apresentado em aula, melhore-o de
 forma que ele leia  três roteadores e calcule se algum deles
 permite que seu sinal seja captado por um dispositivo na posição (x,y)
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

typedef struct wifi {
	char cor[20];
	float xo;
	float yo;
	float raio;
} WF;

WF eq;
WF tabW[3];

void ler_equi() {
	printf("\nDigite cor do equipamento:\n");
	fgets(eq.cor, 20, stdin);
	printf("\nDigite o raio de equipamento:\n");
	scanf("%f", &eq.raio);
	printf("\nDigite a posiÁ„o no eixo x:\n");
	scanf("%f", &eq.xo);
	printf("\nDigite a posiÁ„o no eixo y:\n");
	scanf("%f", &eq.yo);
}

void ler_varios() {
	int i;
	char n[20];
	for (i = 0; i < 3; i++) {
		printf("\nDigite cor do equipamento:\n");
		fflush(stdin);
		gets(n);
		strcpy(tabW[i].cor, n);
		printf("\nDigite o raio de equipamento:\n");
		scanf("%f", &tabW[i].raio);
		printf("\nDigite a posicao no eixo x:\n");
		scanf("%f", &tabW[i].xo);
		printf("\nDigite a posicao no eixo y:\n");
		scanf("%f", &tabW[i].yo);
	}
}

float calcular_area_Wifi() {
	return (M_PI * eq.raio * eq.raio);
}

int main(void) {
	puts(""); /* prints  */
	return EXIT_SUCCESS;
}

int capta_sinal(float x1, float y1) {
	float b, c, a;
	b = eq.xo - x1;
	c = eq.yo - y1;
	a = sqrt(pow(b, 2) + pow(c, 2));
	printf("\na=%.2f,b=%.2f,c=%.2f", a, b, c);
	if (a <= eq.raio) {
		return 1;
	}
	return 0;
}

void sinal_de_3(float x1, float y1) {
	float b, c, a;
	int i;
	ler_varios();
	for (i = 0; i < 3; i++) {
		b = tabW[i].xo - x1;
		c = tabW[i].yo - y1;
		a = sqrt((b * b) + (c * c));
		printf("\na=%.2f,b=%.2f,c=%.2f", a, b, c);
		if (a <= tabW[i].raio) {
			printf("\n%s, dentro da area\n", tabW[i].cor);
		} else
			printf("\n%s, fora da area\n", tabW[i].cor);
	}
}

int main() {
	char option;
	float h, v;
	//  setlocale(LC_ALL,"Portuguese");
	do {
		printf(
				"\n1-ler atributos"
				"\n2-area"
				"\n3-capta?"
				"\n4-sair"
				"\n5-ler tres roteadores"
				"\n6-Ler tres e analisar sinal\n");
		option = getche();
		switch (option) {
		case '1':
			ler_equi();
			break;
		case '2':
			printf("\nArea: %.2f", calcular_area_Wifi());
			break;
		case '3':
			printf("\nDigite a posicao do dispositivo(x,y)\n");
			scanf("%f,%f", &h, &v);
			if (capta_sinal(h, v) == 1)
				printf("\nDentro da area\n");
			else
				printf("\nFora da area\n");
			break;
		case '4':
			printf("Saindo");
			break;
		case '5':
			ler_varios();
			break;
		case '6':
			printf("\nDigite a posicao do dispositivo(x,y)\n");
			scanf("%f,%f", &h, &v);
			sinal_de_3(h, v);
		default:
			printf("\nOp invalida\n");
		}
	} while (option != '4');

	return 0;
}
