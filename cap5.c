//CAP5

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex1

#ifdef ex1

char A[10], B[10];
int Comparacao()
{
    for(int i=0; i<10;i++)
    {
        if(A[i]!=B[i])
        {
            return 0;
        }

    }
     return 1;
}
int main()
{
    setlocale(LC_ALL,"Portuguese");
    int K;
    int i, resposta;


    do{

    printf("Digite 10 caracteres:\n");
    gets(A);


    printf("Digite 10 caracteres:\n");
    gets(B);

    K = Comparacao();
    printf("\n%d", K);

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
    return 0;
}

#endif // ex1

#ifdef ex2

char n1[7], n2[7], n3[7], n4[7], n5[7];

int main(){
 int resposta;
 setlocale(LC_ALL,"Portuguese");

    do{
    printf("Digite o primeiro nome(até sete letras): \n");
    scanf("%s", &n1);

    printf("Agora o segundo(até sete letras): \n");
    scanf("%s", &n2);

    printf("Agora o terceiro(até sete letras): \n");
    scanf("%s", &n3);

    printf("Agora o quarto(até sete letras): \n");
    scanf("%s", &n4);

    printf("Por fim digite o quinto nome(até sete letras): \n");
    scanf("%s", &n5);

    printf("\n--------------------NOMES-----------------------\n");
    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %-7s", n1);
    printf("                                 %-7s", n5);
    printf("\n            %-7s", n2);
    printf("             %-7s", n4);
    printf("\n                      %-7s\n", n3);

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
    return 0;
}

#endif // ex2

#ifdef ex3

char str[51];

int ComprimentoString(){
    int i = 0;

    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, comprimento, resposta;

    do{
    printf("Digite uma String qualquer (Até 50 caracteres): \n");
    scanf("%s", &str[0]);

    comprimento = ComprimentoString();

    printf("O comprimento é %d ", comprimento);

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
    return 0;
}

#endif // ex3

#ifdef ex4

int main()
{
    char minusculos[10], maiusculos[10];
    int i, resposta;

    setlocale(LC_ALL,"Portuguese");

 do{
    printf("Digite 10 caracteres minúsculos: \n");
    for(i = 0; i < 10; i++){
        do{
            scanf(" %c", &minusculos[i]);
            if(minusculos[i] >= 'a' && minusculos[i] <= 'z'){
                maiusculos[i] = minusculos[i] - 32;
            }
            else{
                printf("Esse caractere não é minúsculo!!!\n");
            }

        }while(minusculos[i] >= 'A' && minusculos[i] <= 'Z');

    }


    for(i = 0; i < 10; i++){
        printf("Minúsculo = %c .... Maiúsculo = %c\n", minusculos[i], maiusculos[i]);
    }

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
    return 0;
}

#endif // ex4

#ifdef ex5

int main()
{
    char minusculos[10], maiusculos[10];
    int i, resposta;

    setlocale(LC_ALL,"Portuguese");

    do{
    printf("Digite 10 caracteres maiúsculos: \n");
    for(i = 0; i < 10; i++){
        do{
            scanf(" %c", &maiusculos[i]);
            if(maiusculos[i] >= 'A' && maiusculos[i] <= 'Z'){
                minusculos[i] = maiusculos[i] + 32;
            }
            else{
                printf("Esse caractere não é maiúsculo!!!\n");
            }

        }while(maiusculos[i] >= 'a' && maiusculos[i] <= 'z');

    }


    for(i = 0; i < 10; i++){
        printf("Maiúsculo = %c .... Minúsculo = %c\n", maiusculos[i], minusculos[i]);
    }

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
    return 0;
}
#endif // ex5
