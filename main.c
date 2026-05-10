#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

void calc_seg(const long long valor_usuario[2], long long *horas, long long *minutos, long long *restante){

    *horas = valor_usuario[0] / 3600;
    *restante = valor_usuario[0] % 3600;
    *minutos = *restante / 60;
    *restante = *restante % 60;

}

void calc_media(const long long valor_usuario[2], long long *media) {

    *media = (valor_usuario[0] + valor_usuario[1]) / 2;

}

void maior_menor(const long long valor_usuario[2], long long *maior, long long *menor) {

    if (valor_usuario[0] < valor_usuario[1]) {
        *maior = valor_usuario[1];
        *menor = valor_usuario[0];
    }
    else {
        *maior = valor_usuario[0];
        *menor = valor_usuario[1];
    }
}

bool impar_ou_par(const long long valor_usuario[2]) {
    return valor_usuario[0] % 2 == 0;
}


int main(void) {
    SetConsoleOutputCP(65001);
    char selecao;
    long long valor_usuario[2];

    printf("Pressione o respectivo numero para usar a funçao:\n"
           "------------------------------------------------------------------------------------\n"
           "[1] Para usar a calculadora de segundos\n"
           "[2] Para usar a calculadora de media entre dois numeros\n"
           "[3] Para saber qual é o maior numero e o menor numero entre dois numeros digitados\n"
           "[4] Para saber se seu numero é par ou impar\n"
           "------------------------------------------------------------------------------------\n");

    selecao = _getch();

    while (selecao != '1' && selecao != '2' && selecao != '3' && selecao != '4') {
        int i;
        i++;
        printf("\rNumero invalido! Tente novamente[%d] ", i);
        selecao = _getch();
    }
    system("cls");

    if(selecao == '1') {

        long long horas, minutos, restante;

        printf("\n----------------CALCULADORA DE SEGUNDOS----------------\n\n"
               "Digite o valor de segundos: ");
        scanf("%lld", &valor_usuario[0]);

        calc_seg(valor_usuario, &horas, &minutos, &restante);

        printf("\n-----------------------RESULTADO-----------------------\n"
               "\n%lld Segundos dá:\n", valor_usuario[0]);

        if (horas > 0) {
            printf("%lld Horas, ", horas);
        }
        if (minutos > 0) {
            printf("%lld Minutos e ", minutos);
        }
        if (restante > 0) {
            printf("%lld Segundos\n", restante);
        }
        if (horas == 0 && minutos == 0 && restante== 0) {
            printf("O calculo retornou 0! Coloque um valor maior que 0 para que o calculo aconteça!\n");
        }
        printf("\n-------------------------------------------------------\n");
    }

    if (selecao == '2') {

        long long media;

        printf("\n----------------CALCULADORA DE MÉDIA----------------\n\n");

        printf("Escreva o primeiro valor: ");
        scanf("%lld", &valor_usuario[0]);
        printf("\nEscreva o segundo valor: ");
        scanf("%lld", &valor_usuario[1]);

        calc_media(valor_usuario, &media);

        printf("\n-----------------------RESULTADO-----------------------\n");

        printf("\nA Média entre %lld e %lld é: %lld\n", valor_usuario[0], valor_usuario[1], media);

        printf("\n-------------------------------------------------------\n");

    }

    if (selecao == '3') {
        long long maior, menor;

        printf("\n---------------------MAIOR E MENOR---------------------\n");

        printf("\nEscreva o primeiro valor: ");
        scanf("%lld", &valor_usuario[0]);
        printf("\nEscreva o segundo valor: ");
        scanf("%lld", &valor_usuario[1]);

        maior_menor(valor_usuario, &maior, &menor);

        printf("\n-----------------------RESULTADO----------------------\n");

        printf("\nO Maior número é: %lld\n", maior);
        printf("O Menor número é: %lld\n", menor);

        printf("\n-------------------------------------------------------\n");
    }

    if (selecao == '4') {

        printf("---------------------ÍMPAR OU PAR?---------------------\n\n"
               "Digite o numero que deseja checar:");
        scanf("%lld", &valor_usuario[0]);

        printf("\n-----------------------RESULTADO----------------------\n");
        if (impar_ou_par(valor_usuario)){
            printf("\nO Seu número é par!\n");
        }
        else{
            printf("\nO Seu número é impar!\n");
        }
        printf("\n-------------------------------------------------------\n");
    }

    system("pause");
    return 0;
}