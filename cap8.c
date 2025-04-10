//CAP8

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex6

#ifdef ex1

int main()
{
    char c;
    char *pc = &c;
    int i;
    int *pi = &i;
    long l;
    long *pl = &l;
    float f;
    float *pf = &f;
    double d;
    double *pd = &d;
    unsigned char uc;
    unsigned char *puc = &uc;
    unsigned u;
    unsigned *pu = &u;
    unsigned long ul;
    unsigned long *pul = &ul;
    int resposta;

    do{
    printf("Digite um caractere do tipo char: ");
    scanf("%c", pc);

    printf("Digite um numero do tipo int: ");
    scanf("%d", pi);

    printf("Digite um numero do tipo long: ");
    scanf("%ld", pl);

    printf("Digite um numero do tipo float: ");
    scanf("%f", pf);

    printf("Digite um numero do tipo double: ");
    scanf("%lf", pd);

    printf("Digite um numero do tipo unsigned char: ");
    getchar();
    scanf("%c", puc);

    printf("Digite um numero do tipo unsigned: ");
    scanf("%u", pu);

    printf("Digite um numero do tipo unsigned long: ");
    scanf("%lu", pul);


    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-11d         %-11ld         %-3u\n", *pi, *pl, *pu);
    printf("              %-8.2f            %-9.2lf           %-4c\n", *pf, *pd, *pc);
    printf("         %-10lu          %-3c\n", *pul, *puc);

    printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta==1);
    return 0;
}

#endif

#ifdef ex2

char A[11], B[11];

int comparar()
    {
        int i;
        char *p1, *p2;

        p1 = A;
        p2 = B;

        for(i = 0; i<11; i++)
        {
            if(*(p1+i)!= *(p2+i))
            {
                return 0;
            }
            else if(*(p1+i) =='\0')
            {
                return 1;
            }
        }
    }

int main()
{
    int p, resposta;
    setlocale(LC_ALL,"Portuguese");

    do{
    printf("Digite até 10 caracteres da string A:\n");
    gets(A);

    printf("Digite até 10 caracteres da string B:\n");
    gets(B);

    p = comparar();
    printf("Resultado:\n");

    if(p==0)
    {
        printf("Diferente\n");
    }
    else
    {
        printf("Igual\n");
    }
    printf("%d", p);

    printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta==1);

    return 0;
}

#endif

#ifdef ex3

char vet[13] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};

int PesquisarLetra(char *pl){
    int i, cont = 0;

    for(i = 0; i < 13; i++){
        if(vet[i] == *pl){
            cont++;
        }
    }

    return cont;
}

int main()
{
    int resultado, resposta;
    char *pl, letra;
    pl = &letra;

    do{
    printf("Digite uma letra (minuscula): ");
    scanf("%c", pl);

    resultado = PesquisarLetra(pl);

    if(resultado == 1){
        printf("A letra digitada existe!\n");
    }
    else{
        printf("A letra digitada NAO existe!\n");
    }

    printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta==1);
    return 0;
}
#endif

#ifdef ex4

int main()
{

    setlocale(LC_ALL, "PORTUGUESE");
    int  resposta;
    do{
    int tamanho = 0, num = 0, soma = 0, *pont,*pont2;

    float media = 0, *pont3;

    pont = &num;
    pont2 = &soma;
    pont3 = &media;


    while (1 < 2){


        printf("Digite um número positivo: \n");

        scanf("%d", pont);

        if(*pont >= 0){

            *pont2 += *pont;

            tamanho++;

        } else {

            break;

        }

    }

    if (tamanho != 0){

             *pont3 = (float)*pont2 / (float)tamanho;

            printf("\nA média dos valores digitados positivos é: %.2f\n", *pont3);

    } else {

        printf("\nNenhum número positivo foi digitado!\n");

    }

    printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
    scanf("%d", &resposta);
    }while(resposta==1);
    return 0;

}

#endif

#ifdef ex5

struct pessoa{
    char nome[50];
    char end[50];
    char cidade[50];
    char estado[50];
    char cep[11];
};

struct pessoa elementos[4];
struct pessoa *p;


void Receba(){
    int i;

    for(i = 0; i < 4; i++){
        printf("\n\tPESSOA %d\n", i+1);
        printf("Digite o nome:\n");;
        gets(p[i].nome);
        printf("Digite o endereco:\n");
        gets(p[i].end);
        printf("Digite a cidade:\n");
        gets(p[i].cidade);
        printf("Digite o estado:\n");
        gets(p[i].estado);
        printf("Digite o cep:\n");
        gets(p[i].cep);
    }

}

void Toma(){
    int i;

    for(i = 0; i < 4; i++){
        printf("\n\tPESSOA %d\n", i+1);
        printf("Nome: %s\n", p[i].nome);;
        printf("Endereco: %s\n", p[i].end);
        printf("Cidade: %s\n", p[i].cidade);
        printf("Estado: %s\n", p[i].estado);
        printf("Cep: %s\n", p[i].cep);

    }
}

int main()
{
    int opcao;
    p = &elementos[0];

    do{
        do{
            printf("\n---------------MENU---------------\n");
            printf("1 - Entrada de Dados.\n");
            printf("2 - Exibir Dados.\n");
            printf("3 - Sair\n");

            printf("\nDigite uma das opcoes acima:\n");
            scanf("%d", &opcao);
            getchar();
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        switch(opcao)
        {
            case 1:
                Receba();
                break;
            case 2:
                Toma();
                break;
            case 3:
                exit(0);
        }
    }while(opcao != 3);
    return 0;
}

#endif

#ifdef ex6

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int main() {

    int resposta;
    setlocale(LC_ALL,"Portuguese");

    do{
    Data datas[2];
    Data *pDatas = &datas;
    int i;
    int diasTotais[2] = {0, 0};
    for (i = 0; i < 2; i++) {
        printf("Digite a data %d (formato DD MM AAAA): ", i + 1);
        scanf("%d %d %d", &pDatas[i].dia, &pDatas[i].mes, &pDatas[i].ano);
    }


    for (i = 0; i < 2; i++) {

        for (int ano = 1; ano < pDatas[i].ano; ano++) {
            diasTotais[i] += (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 366 : 365;
        }


        for (int mes = 1; mes < pDatas[i].mes; mes++) {
            if (mes == 2) {
                diasTotais[i] += ((pDatas[i].ano % 4 == 0 && (pDatas[i].ano % 100 != 0 || pDatas[i].ano % 400 == 0)) ? 29 : 28);
            } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                diasTotais[i] += 30;
            } else {
                diasTotais[i] += 31;
            }
        }


        diasTotais[i] += pDatas[i].dia;
    }


    int diferenca;
    if (diasTotais[0] > diasTotais[1]) {
        diferenca = diasTotais[0] - diasTotais[1];
    } else {
        diferenca = diasTotais[1] - diasTotais[0];
    }

    printf("A diferença entre as datas é de %d dias.\n", diferenca);

    printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
    scanf("%d", &resposta);
    }while(resposta==1);
    return 0;
}

#endif
