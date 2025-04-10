//CAP2

#define ex1

#ifdef ex1

#include <stdio.h>

int main(){
    char resposta;
    int minimo = 1, maximo = 99, chute,finalizador;

    do{
    do{
        chute = (minimo + maximo) / 2;
        do{
            printf("O numero que voce esta pensando e %d? \n", chute);
            scanf("%c", &resposta);
            getchar();
            if(resposta!='=' && resposta!='>' && resposta!='<'){
                printf("Simbolo errado, digite novamente!!!\n");
            }
        }while(resposta!='=' && resposta!='>' && resposta!='<');

        if(resposta == '='){
            printf("Acertei o seu numero!!!\n");
        }
        else if(resposta == '>'){
            minimo = chute + 1;
        }
        else{
            maximo = chute - 1;
        }

    }while(resposta != '=');

    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);
    getchar();
    }while(finalizador!=0);
    return 0;
}

#endif // ex1

#ifdef ex2

#include <stdio.h>
#include <locale.h>

int main(){

    char resposta;
    int minimo = 1, maximo = 99, chute, cont, finalizador;


    setlocale(LC_ALL,"Portuguese");

    do{
            cont=0;
    do{
        chute = (minimo + maximo) / 2;
        do{
            printf("O número que você digitou foi %d?\n", chute);
            scanf(" %c", &resposta);
            if(resposta != '=' && resposta != '>' && resposta != '<'){
                printf("Sinal desconhecido!!!\n");
            }

        }while(resposta != '=' && resposta != '>' && resposta != '<');

        switch(resposta){
            case '=':
            {
                printf("Acertei seu número!!!\n");
                break;
            }
            case '>':
            {
                minimo = chute + 1;
                break;
            }
            case '<':
            {
                maximo = chute - 1;
                break;
            }
        }

        cont++;

    }while(resposta != '=');

    printf("Foi necessário %d tentativas!!!\n", cont);

    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);
    getchar();
    }while(finalizador!=0);
    return 0;
}

#endif // ex2

#ifdef ex3

#include <stdio.h>
#include <locale.h>

int main(){

    int n, soma = 0, cont = 0, i, finalizador;
    float media = 0;
    setlocale(LC_ALL,"Portuguese");

    do{
    do{
        printf("Digite numeros inteiros positivos: \n");
        do{
            scanf("%d", &n);
            if(n == 0){
                printf("Não digite o zero!!! \n");
            }

        }while(n == 0);
        for(i = 0; i < 1; i++){
            if(n > 0){
                soma += n;
                cont++;
            }
        }
    }while(n > 0);

    for(i = 0; i < cont; i++){
        media = soma / cont;
    }

    printf("A média dos números positivos digitados foi: %.2f\n", media);

    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
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
   int km, litros, finalizador;
   float consumo;
   setlocale(LC_ALL,"Portuguese");

   do{

   printf("Digite a distância em km:\n");
   scanf("%d", &km);

   printf("Digite a quantidade de litros:\n");
   scanf("%d", &litros);

   consumo = km/litros;
   if(consumo>14)
   {
       printf("CONSUMO (km/l) MENSAGEM\n%-14f Super econômico\n", consumo);
   }
   else if(consumo > 8 && consumo < 14)
   {
       printf("CONSUMO (km/l) MENSAGEM\n%-14f Econômico\n", consumo);
   }

   else
   {
       printf("CONSUMO (km/l) MENSAGEM\n%-14f Venda seu carro!\n", consumo);
   }

   printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
   scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex4

#ifdef ex5

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int horasUm,minutosUm, segundosUm, instanteUm, instanteDois, horasDois, minutosDois, segundosDois;
    int segundosHorasUm,segundosMinUm, segundostotaisUm, segundosHorasDois,segundosMinDois, segundostotaisDois, segundostotais;
    int horasdif, mindif, segdif, finalizador;
    setlocale(LC_ALL,"Portuguese");

    do{

    printf("Digite em horas:\n");
    scanf("%d", &horasUm);

    printf("Digite em minutos:\n");
    scanf("%d", &minutosUm);

    printf("Digite em segundos:\n");
    scanf("%d", &segundosUm);

    printf("Digite em horas:\n");
    scanf("%d", &horasDois);

    printf("Digite em minutos:\n");
    scanf("%d", &minutosDois);

    printf("Digite em horas:\n");
    scanf("%d", &segundosDois);


    segundosHorasUm = horasUm*3600;
    segundosMinUm =  minutosUm*60;
    segundostotaisUm = segundosUm+segundosHorasUm+segundosMinUm;

    segundosHorasDois = horasDois*3600;
    segundosMinDois =  minutosDois*60;
    segundostotaisDois = segundosDois+segundosHorasDois+segundosMinDois;

    if(segundostotaisUm>segundostotaisDois)
    {
    segundostotais = segundostotaisUm-segundostotaisDois;
    }

     if(segundostotaisUm<segundostotaisDois)
    {
    segundostotais = segundostotaisDois-segundostotaisUm;
    }
    horasdif = segundostotais/3600;
    mindif = (segundostotais%3600)/60;
    segdif = (segundostotais%60);

    printf("Primeiro instante: %d h %d min %d segundos\n", horasUm, minutosUm, segundosUm);
    printf("Segundo instante: %d h %d min %d segundos\n", horasDois, minutosDois, segundosDois);
    printf("Diferença de instantes: %d h %d min %d segundos\n", horasdif, mindif, segdif);

    printf("Deseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex5
