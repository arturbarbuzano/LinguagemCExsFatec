//CAP1

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex1

#ifdef ex1




int main()
{
    int a=10;
    int b=50;

    printf("ANTES \n");

    printf("A: %d       B: %d", a,b);

    a = a+b;
    b = a-b;
    a = a-b;

    printf("\nDEPOIS \n");

    printf("A: %d       B: %d", a,b);


}

#endif // ex1

#ifdef ex2

int main()
{
    short a;
    long b;
    int c, resposta;
    float d;
    double e;
    char f;

    setlocale(LC_ALL,"Portuguese");

    do{
    printf("Digite um valor do tipo short: ");
    scanf("%hd", &a);
    printf("Digite um valor do tipo long: ");
    scanf("%ld", &b);
    printf("Digite um valor do tipo int: ");
    scanf("%d", &c);
    printf("Digite um valor do tipo float: ");
    scanf("%f", &d);
    printf("Digite um valor do tipo double: ");
    scanf("%lf", &e);
    printf("Digite um valor do tipo char: ");
    scanf(" %c", &f);

    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("    %-5hd", a);
    printf("               %-11ld", b);
    printf("         %-11d\n", c);
    printf("              %-8.2f", d);
    printf("            %-9.2lf", e);
    printf("           %-7c", f);
    getchar();


    printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
    scanf("%d", &resposta);

    }while(resposta == 1);
    return 0;
}

#endif // ex2

#ifdef ex3

int main()
{
    int resposta;

    do{
        int tempo, horas, minutos, segundos;
        setlocale(LC_ALL,"Portuguese");

        printf("Digite um tempo em segundos:\n");
        scanf("%d", &tempo);

        horas = tempo/3600;
        minutos = (tempo%3600)/60;
        segundos = (tempo%60);

        printf("CONVERTENDO...\n");
        printf("Seu tempo é: %dh %dmin %dsegundos", horas, minutos, segundos);

        printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
        scanf("%d", &resposta);

    }while(resposta == 1);
    return 0;
}

#endif // ex3

#ifdef ex4

int main(){
    int resposta;
    do{
        int numeroLido, primeiro, segundo, terceiro, numeroGerado;

        printf("Digite um numero de 3 digitos: ");
        do{
            scanf("%d", &numeroLido);
            if(numeroLido < 100 || numeroLido > 999){
                printf("Esse numero não tem 3 digitos. Digite novamente: ");
            }
        }while(numeroLido < 100 || numeroLido > 999);

        primeiro = numeroLido / 100;
        segundo = (numeroLido / 10) % 10;
        terceiro = numeroLido % 10;

        numeroGerado = (terceiro * 100) + (segundo * 10) + primeiro;

        printf("Numero Lido = %d .... Numero Gerado = %d\n", numeroLido, numeroGerado);

        printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
        scanf("%d", &resposta);


    }while(resposta == 1);
    return 0;
}

#endif // ex4

#ifdef ex5

int main()
{
    int resposta;
    do{
        int num, lim, resultado, resultadototal;
        setlocale(LC_ALL,"Portuguese");

        printf("Digite um número:\n");
        scanf("%d", &num);

        printf("Digite um número limite (maior que o número):\n");
        scanf("%d", &lim);


        if(lim%num==0)
        {
           resultado = lim/num;
           resultadototal = ((resultado+1)*num);
        }

        else{
            resultado = (lim/num)+1;
            resultadototal = resultado*num;
        }
        printf("Menor múltiplo de %d maior que %d. Resultado:%d",num,lim,resultadototal);
        printf("\nDigite 1 para refazer ou qualquer outro numero para encerrar o programa: ");
        scanf("%d", &resposta);


    }while(resposta == 1);
}

#endif // ex5
