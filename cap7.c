//CAP7

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex4

#ifdef ex1
struct numeros{
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

int main()
{
    char c;
    int i, resposta;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;

    struct numeros valor = {c, i, l, f, d, uc, ui, ul};

    do{
    printf("Digite um caractere do tipo char: ");
    scanf("%c", &valor.c);

    printf("Digite um numero do tipo int: ");
    scanf("%d", &valor.i);

    printf("Digite um numero do tipo long: ");
    scanf("%ld", &valor.l);

    printf("Digite um numero do tipo float: ");
    scanf("%f", &valor.f);

    printf("Digite um numero do tipo double: ");
    scanf("%lf", &valor.d);

    printf("Digite um numero do tipo unsigned char: ");
    scanf("%c", &valor.uc);
    getchar();

    printf("Digite um numero do tipo unsigned int: ");
    scanf("%u", &valor.ui);

    printf("Digite um numero do tipo unsigned long: ");
    scanf("%lu", &valor.ul);

    printf("\n        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-11d         %-11ld         %-8.2f  %-9.2lf\n", valor.i, valor.l, valor.f, valor.d);
    printf("          %-10u          %-10lu          %-4c      %-3u\n", valor.ui, valor.ul, valor.c, valor.uc);

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
 return 0;
}

#endif

#ifdef ex2

struct pessoa
{
    char nome[50];
    char end[50];
    char cidade[50];
    char estado[50];
    char cep[11];
};

typedef struct pessoa pessoa;
pessoa tipo_pessoa[4];

void receba()
{
    int i;

    printf("Entrada de dados:\n\n");

    for(i=0;i<4;i++)
    {
        printf("----Pessoa %d ----\n\n", i+1);

        printf("Digite o nome:\n");
        gets(tipo_pessoa[i].nome);

        printf("Digite o endereço:\n");
        gets(tipo_pessoa[i].end);

        printf("Digite a cidade:\n");
        gets(tipo_pessoa[i].cidade);


        printf("Digite o estado:\n");
        gets(tipo_pessoa[i].estado);

        printf("Digite o cep:\n");
        gets(tipo_pessoa[i].cep);
}
}

void toma()
{
    int i;

    printf("Toma os dados:\n");
    for(i=0;i<4;i++)
    {
        printf("-------------- PESSOA %d --------------\n", i+1);

        printf("Nome: %s\n",tipo_pessoa[i].nome);

        printf("Endereço: %s\n",tipo_pessoa[i].end);

        printf("Cidade: %s\n",tipo_pessoa[i].cidade);

        printf("Estado: %s\n",tipo_pessoa[i].estado);

        printf("CEP: %s\n\n",tipo_pessoa[i].cep);
    }
}


int main()
{
    int num;
    setlocale(LC_ALL,"Portuguese");

    do{

    printf("----- MENU -----\n");
    printf("1-Entrada de dados\n");
    printf("2-Exibir dados\n");
    printf("0-Sair do programa\n\n");
    printf("----------------\n\n");




    printf("Digite um desses números:\n");
    scanf("%d", &num);
    getchar();

    switch (num)
    {

    case 1:
    receba();
    break;

    case 2:
    toma();
    break;

    case 0:
    exit(0);
    break;

    }

    }while(num!=0);

return 0;
}

#endif

#ifdef ex3
struct data {
    int dia;
    int mes;
    int ano;
};

typedef struct data data;
data calendario[2];

int calculo(data d1, data d2) {
    int diadif = 0;

    int bissexto(int ano) {
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }

    int dias_no_mes(int mes, int ano) {
        if (mes == 2) {
            return bissexto(ano) ? 29 : 28;
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    if (d1.ano > d2.ano || (d1.ano == d2.ano && d1.mes > d2.mes) ||
       (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia > d2.dia)) {
        data temp = d1;
        d1 = d2;
        d2 = temp;
    }

    while (d1.ano < d2.ano || d1.mes < d2.mes || d1.dia < d2.dia) {
        d1.dia++;
        diadif++;

        if (d1.dia > dias_no_mes(d1.mes, d1.ano)) {
            d1.dia = 1;
            d1.mes++;
        }

        if (d1.mes > 12) {
            d1.mes = 1;
            d1.ano++;
        }
    }

    return diadif;
}

int main() {
    int resposta;
    setlocale(LC_ALL, "Portuguese");

    do{
    for (int i = 0; i < 2; i++) {
        printf("Digite o dia:\n");
        scanf("%d", &calendario[i].dia);
        printf("Digite o mês:\n");
        scanf("%d", &calendario[i].mes);
        printf("Digite o ano:\n");
        scanf("%d", &calendario[i].ano);
    }

    int diferenca = calculo(calendario[0], calendario[1]);
    printf("A diferença de dias é: %d\n", diferenca);

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);

    }while(resposta == 1);
    return 0;
}
#endif

#ifdef ex4

struct registro{
    char nome[50];
    float peso;
    float altura;
};

struct registro var[4];

void opcao1()
{
    int i;

    for(i = 0; i < 4; i++){
        printf("Digite o nome da pessoa %d: ", i+1);
        gets(var[i].nome);

        printf("Agora digite o peso da pessoa %d: ", i+1);
        scanf("%f", &var[i].peso);

        printf("Agora digite a altura da pessoa %d: ", i+1);
        scanf("%f", &var[i].altura);
        getchar();
    }
}

void opcao2()
{
    int i;

    for(i = 0; i < 4; i++){
        printf("Pessoa %d --- nome: %s, peso: %.2f, altura: %.2f\n", i+1, var[i].nome, var[i].peso, var[i].altura);
    }
}

void opcao3()
{
    float imc[4];
    int i;

    for(i = 0; i < 4; i++){
        imc[i] = var[i].peso / (var[i].altura * var[i].altura);
        printf("IMC de %s = %.2f \n", var[i].nome, imc[i]);
    }
}

void opcao4()
{
    exit(0);
}

int main()
{
    int num;

    do{
        printf("----------MENU----------\n\n");
        printf("1 - Receber todos os dados.\n");
        printf("2 - Imprime todos os dados.\n");
        printf("3 - Calcula o IMC de todas as pessoas.\n");
        printf("4 - Sair.\n\n");
        printf("------------------------\n");

        do{
            printf("Digite um numero para continuar: ");
            scanf("%d", &num);
            getchar();
            if(num != 1 && num != 2 && num != 3 && num != 4){
                printf("Numero invalido, digite novamente!\n");
            }
        }while(num != 1 && num != 2 && num != 3 && num != 4);

        switch(num)
        {
            case 1:
                opcao1();
                break;
            case 2:
                opcao2();
                break;
            case 3:
                opcao3();
                break;
            case 4:
                opcao4();
                break;
        }

    }while(num != 4);
    return 0;
}

#endif
