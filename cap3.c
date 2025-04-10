//CAP3

#define ex1

#ifdef ex1

#include <stdio.h>

int somaAlgarismos(int n){
    int fatN = 1, i, unidade, dezena, centena, uMilhar, dMilhar, cMilhar, uMilhao, dMilhao;


    for(i = 1; i <= n; i++){
        fatN = fatN * i;
    }

    unidade = fatN % 10;
    dezena = (fatN / 10) % 10;
    centena = (fatN / 100) % 10;
    uMilhar = (fatN / 1000) % 10;
    dMilhar = (fatN / 10000) % 10;
    cMilhar = (fatN / 100000) % 10;
    uMilhao = (fatN / 1000000) % 10;


    if(fatN <= 6){
        return fatN;
    }
    else if(fatN == 24){
        return unidade + dezena;
    }
    else if(fatN == 120){
        return unidade + dezena + centena;
    }
    else if(fatN == 720){
        return unidade + dezena + centena;
    }
    else if(fatN == 5040){
        return unidade + dezena + centena + uMilhar;
    }
    else if(fatN == 40320){
        return unidade + dezena + centena + uMilhar + dMilhar;
    }
    else if(fatN == 362880){
        return unidade + dezena + centena + uMilhar + dMilhar + cMilhar;
    }
    else{
        return unidade + dezena + centena + uMilhar + dMilhar + cMilhar + uMilhao;
    }

}

int main(){
    int n, soma, finalizador;

    do{
    do{
        printf("Digite um numero entre entre 1 e 10: ");
        scanf("%d", &n);
        if(n <= 0 || n > 10){
            printf("Numero invalido, digite novamente!!!\n");
        }
    }while(n <= 0 || n > 10);

    soma = somaAlgarismos(n);

    printf("SOMA = %d\n", soma);

    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex1

#ifdef ex2

int VerificaSinal(int numero){
    if(numero > 0){
        return 1;
    }
    else if(numero < 0){
        return 0;
    }
    else{
        return -1;
    }
}

int AmbosPositivos(int sinalN1, int n1, int sinalN2, int n2){
    int sucessorMenorNumero, antecessorMaiorNumero, i, soma=0;

    if(sinalN1  == 1 && sinalN2 == 1){
        if(n1 > n2){
            sucessorMenorNumero = n2 + 1;
            antecessorMaiorNumero = n1 - 1;
        }
        else{
            sucessorMenorNumero = n1 + 1;
            antecessorMaiorNumero = n2 - 1;
        }

        for(i = sucessorMenorNumero; i <= antecessorMaiorNumero; i++){
            soma += i;
        }
        return soma;
    }
    return 0;
}

int AmbosNegativos(int sinalN1, int n1, int sinalN2, int n2){
    int sucessorMenorNumero, antecessorMaiorNumero, i, multiplicacao = 1;

    if(sinalN1 == 0 && sinalN2 == 0){
        if(n1 > n2){
            sucessorMenorNumero = n2 + 1;
            antecessorMaiorNumero = n1 - 1;
        }
        else{
            sucessorMenorNumero = n1 + 1;
            antecessorMaiorNumero = n2 - 1;
        }

        for(i = sucessorMenorNumero; i <= antecessorMaiorNumero; i++){
            multiplicacao *= i;
        }
        return multiplicacao;
    }
    return 0;
}

float SinaisAlternados(int sinalN1, int n1, int sinalN2, int n2){
    if(sinalN1 == 1 && sinalN2 == 0){
        return (float) n1/n2;
    }
    return 0;
}

int main()
{
   int n1, n2, sinalN1, sinalN2, soma, multiplicacao, finalizador;
   float divisao;

   do{

   printf("Digite um numero inteiro: ");
   scanf("%d", &n1);

   printf("Agora digite outro numero inteiro: ");
   scanf("%d", &n2);

   sinalN1 = VerificaSinal(n1);
   sinalN2 = VerificaSinal(n2);

   soma = AmbosPositivos(sinalN1, n1, sinalN2, n2);
   multiplicacao = AmbosNegativos(sinalN1, n1, sinalN2, n2);
   divisao = SinaisAlternados(sinalN1, n1, sinalN2, n2);

   if(soma != 0){
        printf("A soma foi: %d\n", soma);
   }
   else if(multiplicacao != 0){
        printf("A multiplicacao foi: %d\n", multiplicacao);
   }
   else if(divisao != 0){
        printf("A divisao foi: %.2f\n", divisao);
   }
   else{
        printf("Nenhum dos numeros digitados atendem as decisoes das funcoes!!!\n");
   }

    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex2

#ifdef ex3

#include <stdio.h>

int Adicao(int n1, int n2){
    return n1 + n2;
}

int Subtracao(int n1, int n2){
    return n1 - n2;
}

int Multiplicacao(int n1, int n2){
    return n1 * n2;
}

float Divisao(int n1, int n2){
    return (float) n1 / n2;
}

int main(){
    int n1, n2, adicao, subtracao, multiplicacao, finalizador;
    float divisao;

 do{
    printf("Digite um numero inteiro: ");
    scanf("%d", &n1);

    printf("Agora digite mais um: ");
    scanf("%d", &n2);

    adicao = Adicao(n1, n2);
    subtracao = Subtracao(n1, n2);
    multiplicacao = Multiplicacao(n1, n2);

    printf("%d + %d = %d\n", n1, n2, adicao);
    printf("%d - %d = %d\n", n1, n2, subtracao);
    printf("%d x %d = %d\n", n1, n2, multiplicacao);

    if(n2 == 0){
        printf("Nao foi possivel fazer a divisao, pois o segundo numero digitado e igual a zero!!!");
    }
    else{
        divisao = Divisao(n1, n2);
        printf("%d / %d = %.2f\n", n1, n2, divisao);
    }


    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex3

#ifdef ex4



    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    if(finalizador=0)
    {
        return 0;
    }
}

#endif // ex4

#ifdef ex5

#include <stdio.h>

int Adicao(int n1, int n2){
    return n1 + n2;
}

int Subtracao(int n1, int n2){
    return n1 - n2;
}

int Multiplicacao(int n1, int n2){
    return n1 * n2;
}

float Divisao(int n1, int n2){
    return (float) n1 / n2;
}

int main(){
    int n1, n2, adicao, subtracao, multiplicacao, finalizador;
    float divisao;

        do{
        printf("Digite um numero inteiro: ");
        scanf("%d", &n1);

        printf("Agora digite mais um: ");
        scanf("%d", &n2);

        adicao = Adicao(n1, n2);
        subtracao = Subtracao(n1, n2);
        multiplicacao = Multiplicacao(n1, n2);

        printf("\nAdicao = %d\n", adicao);
        printf("Subtracao = %d\n", subtracao);
        printf("Multiplicacao = %d\n", multiplicacao);
        if(n2 == 0){
            printf("\nNao foi possivel fazer a divisao, pois o ultimo numero digitado e igual a zero!!!\n");
        }
        else{
            divisao = Divisao(n1, n2);
            printf("Divisao = %.2f\n", divisao);

            do{
                printf("\nDigite mais um numero: ");
                scanf("%d", &n2);

                if(n2 != 0){
                    adicao += n2;
                    subtracao -= n2;
                    multiplicacao *= n2;
                    divisao /= n2;

                    printf("\nAdicao = %d\n", adicao);
                    printf("Subtracao = %d\n", subtracao);
                    printf("Multiplicacao = %d\n", multiplicacao);
                    printf("Divisao = %.2f\n", divisao);
                }
                else{
                    printf("\nNao foi possivel fazer a divisao, pois o ultimo numero digitado e igual a zero!!!\n");
                }
            }while(n2 != 0);

        }
    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;

}

#endif // ex5
