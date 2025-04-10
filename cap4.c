//CAP4

#define ex1

#ifdef ex1

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int vetor1[10], vetor2[10],i, j,temp, finalizador;
    setlocale(LC_ALL,"Portuguese");

    do{
    for(i=0;i<10;i++)
    {
        printf("Digite um número inteiro:\n");
        scanf("%d", &vetor1[i]);
    }


   for(i=0;i<10;i++)
   {
       vetor2[i]=vetor1[i];
   }

   for (i = 0; i < 9; i++)
{
    for (j = 0; j < 9 - i; j++)
    {
        if (vetor2[j] > vetor2[j + 1])
        {

            temp = vetor2[j];
            vetor2[j] = vetor2[j + 1];
            vetor2[j + 1] = temp;
        }
    }
}

   printf("Vetor 1:\n");

   for(i=0;i<10;i++)
    {
        printf("%d\n", vetor1[i]);
    }

   printf("Vetor 2:\n");

   for(i=0;i<10;i++)
   {
        printf("%d\n", vetor2[i]);
   }
    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex1

#ifdef ex2

#include <stdio.h>
#include <stdlib.h>

int main(){
   int IN[3], i, finalizador; //11
   float FL[3]; //8
   long LO[3]; // 11
   double DO[3]; //9
   unsigned UN[3]; //10

   do{

   printf("Digite 3 valores do tipo Int: \n");
   for(i = 0; i < 3; i++){
        scanf("%i", &IN[i]);
   }

   printf("Agora digite 3 valores do tipo Float: \n");
   for(i = 0; i < 3; i++){
        scanf("%f", &FL[i]);
   }

   printf("Agora digite 3 valores do tipo Long: \n");
   for(i = 0; i < 3; i++){
        scanf("%ld", &LO[i]);
   }

   printf("Agora digite 3 valores do tipo Double: \n");
   for(i = 0; i < 3; i++){
        scanf("%lf", &DO[i]);
   }

   printf("Por fim digite mais 3 valores do tipo Unsigned: \n");
   for(i = 0; i < 3; i++){
        scanf("%u", &UN[i]);
   }

   printf("\n        10        20        30        40        50\n");
   printf("12345678901234567890123456789012345678901234567890\n");

   for(i = 0; i < 3; i++){
        printf("  %-11d         %-11ld         %-10u\n", IN[i], LO[i], UN[i]);
        printf("            %-8.2f            %-9.2lf\n", FL[i], DO[i]);
   }
    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex2

#ifdef ex3

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int vet[10],vetImpar[5],vetPar[5],i,y=0,z=0, finalizador;
    setlocale(LC_ALL, "Portuguese");

    do{

    for(i=0;i<10;i++)
    {
        printf("Digite um número:\n");
        scanf("%d", &vet[i]);
    }
    printf("Vetor principal:");
    for(i=0;i<10;i++)
    {
        printf("%d", vet[i]);
    }

    for(i=0;i<10;i++)
    {
            if(i%2==0)
            {
                vetPar[y] = vet[i];
                y++;
            }
            else
            {
                vetImpar[z] = vet[i];
                z++;
            }
        }

    printf("\nVetor Ímpar:");

    for(z=0;z<5;z++)
    {
        printf("\n%d", vetImpar[z]);
    }

    printf("\nVetor Par:");

    for(y=0;y<5;y++)
    {
        printf("\n%d", vetPar[y]);
    }

    printf("\nDeseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;

}

#endif // ex3

#ifdef ex4

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int vet[10],vetImpar[5],vetPar[5],i,y=0,z=0, finalizador;
    setlocale(LC_ALL, "Portuguese");

    do{
    for(i=0;i<10;i++)
    {
        printf("Digite um número:\n");
        scanf("%d", &vet[i]);
    }
    printf("Vetor principal:");
    for(i=0;i<10;i++)
    {
        printf("\n%d", vet[i]);
    }

    for(i=0;i<10;i++)
    {
            if(vet[i]%2==0)
            {
                vetPar[y] = vet[i];
                y++;
            }
            else
            {
                vetImpar[z] = vet[i];
                z++;
            }
        }

    printf("\nVetor Ímpar:");

    for(z=0;z<5;z++)
    {
        printf("\n%d", vetImpar[z]);
    }

    printf("\nVetor Par:");

    for(y=0;y<5;y++)
    {
        printf("\n%d", vetPar[y]);
    }
    printf("\nDeseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}
#endif // ex4

#ifdef ex5

int main(){
   int A[2][3], B[2][3], i, j, soma[2][3], finalizador;

   do{
   printf("Digite os valores do vetor A:\n");
   for(i = 0; i < 2; i++){
       for(j = 0; j < 3; j++){
           scanf("%d", &A[i][j]);
       }
   }

   printf("Agora digite os valores do vetor B:\n");
   for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &B[i][j]);
        }
   }

   for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            soma[i][j] = A[i][j] + B[i][j];
        }
   }

   printf("\n\tRESULTADO\n");
   for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            printf("%d + %d = %d (Indice[%d][%d])\n", A[i][j], B[i][j], soma[i][j], i, j);
        }
   }
    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex5
