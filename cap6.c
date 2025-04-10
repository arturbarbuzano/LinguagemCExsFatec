//CAP6

#define ex1

#ifdef ex1

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int anoNasci, mesNasci, diaNasci, anoAtual,mesAtual,diaAtual;
    int anoDif, mesDif,diaDif, finalizador;
    setlocale(LC_ALL,"Portuguese");

    do{

    printf("Digite o seu ano de nascimento:\n");
    scanf("%d", &anoNasci);

    printf("Digite o seu m�s de nascimento:\n");
    scanf("%d", &mesNasci);

    printf("Digite o seu dia de nascimento:\n");
    scanf("%d", &diaNasci);

    printf("Digite o seu ano atual:\n");
    scanf("%d", &anoAtual);

    printf("Digite o seu m�s atual:\n");
    scanf("%d", &mesAtual);

    printf("Digite o seu dia atual:\n");
    scanf("%d", &diaAtual);

    anoDif = anoAtual-anoNasci;
    mesDif = mesAtual-mesNasci;
    diaDif= diaAtual-diaNasci;

    if(mesDif<0)
    {
        anoDif--;
        mesDif+=12;
    }

    if(diaDif<0)
    {
        mesDif--;
        if(mesAtual==1 || mesAtual ==3 || mesAtual==5 || mesAtual==7 || mesAtual==8 || mesAtual==10 || mesAtual==12)
        {
            diaDif+=31;
        }
        else if(mesAtual ==4 || mesAtual==6 || mesAtual==9 || mesAtual==11)
        {
            diaDif+=30;
        }
        else
        {
            if ((anoAtual % 4 == 0 && anoAtual % 100 != 0) || (anoAtual % 400 == 0))
            {
                anoDif--;
                mesDif+=12;
                diaDif+=29;
            }
            else
            {
                anoDif--;
                mesDif+=12;
                diaDif+=28;
            }

            }
        }

    printf("Sua idade �:%d anos %d meses %d dias", anoDif, mesDif, diaDif);

    printf("\nDeseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}
#endif // ex1

#ifdef ex2

#include <stdio.h>
#include <locale.h>

int main() {
    int dia, mes, ano;
    int d, m, y, c, f;
    int diasemana, finalizador;
    setlocale(LC_ALL,"Portuguese");

    do{

    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o m�s: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);

    if (mes == 1 || mes == 2) {
        mes += 12;
        ano -= 1;
    }

    d = dia;
    m = mes;
    y = ano % 100;
    c = ano / 100;

    //f�rmula de Zeller
    f = d + (13 * (m + 1)) / 5 + y + y / 4 + c / 4 - 2 * c;
    diasemana = f % 7;


    if (diasemana < 0) {
        diasemana += 7;
    }


    switch (diasemana) {
        case 0:
            printf("S�bado\n");
            break;
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Segunda-feira\n");
            break;
        case 3:
            printf("Ter�a-feira\n");
            break;
        case 4:
            printf("Quarta-feira\n");
            break;
        case 5:
            printf("Quinta-feira\n");
            break;
        case 6:
            printf("Sexta-feira\n");
            break;
    }

    printf("\nDeseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
    scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}

#endif // ex2

#ifdef ex3

int main(){
   int a, b, finalizador;

 do{

   printf("Digite um numero qualquer: ");
   scanf("%d", &a);

   printf("Agora digite outro numero: ");
   scanf("%d", &b);

   printf("%d & %d = %3d ou 0x%x\n", a, b, a & b, a & b);
   printf("%d | %d = %3d ou 0x%x\n", a, b, a | b, a | b);
   printf("%d ^ %d = %3d ou 0x%x\n", a, b, a ^ b, a ^ b);

   printf("\nDeseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
   scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;

}

#endif // ex3

#ifdef ex4

#include <stdlib.h>
#include <locale.h>

int main()
{
  int numUm,numDois, finalizador;
  float numTres;
  setlocale(LC_ALL,"Portuguese");

 do{
  printf("Digite um n�mero inteiro qualquer:\n");
  scanf("%d", &numUm);

  printf("Digite um n�mero inteiro qualquer:\n");
  scanf("%d", &numDois);

  numTres = (float)numUm/(float)numDois;

  printf("RESULTADOS DAS OPERA��ES\n");
  printf("Soma dos dois n�meros:%d\n", numUm+numDois);
  printf("Subtra��o dos dois n�meros:%d\n", numUm-numDois);
  printf("Multiplica��o dois dois n�meros:%d\n", numUm*numDois);
  printf("Divis�o dos dois n�meros:%f\n",numTres);

  printf("\nDeseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
  scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;

}

#endif // ex4

#ifdef ex5

#include <stdlib.h>
#include <locale.h>

int main()
{
  int numUm,numDois, finalizador;
  float numTres;
  setlocale(LC_ALL,"Portuguese");

  do{

  printf("Digite um n�mero inteiro qualquer:\n");
  scanf("%d", &numUm);

  printf("Digite um n�mero inteiro qualquer:\n");
  scanf("%d", &numDois);

  numTres = (float)numUm;
  numTres /= (float)numDois;

  printf("RESULTADOS DAS OPERA��ES\n");
  printf("Soma dos dois n�meros:%d\n", numUm+=numDois);
  printf("Subtra��o dos dois n�meros:%d\n", numUm-=numDois);
  printf("Multiplica��o dois dois n�meros:%d\n", numUm*=numDois);
  printf("Divis�o dos dois n�meros:%f\n",numTres);

  printf("\nDeseja continuar o programa?\nDigite 1 para continuar ou 0 para finalizar:");
  scanf("%d",&finalizador);

    }while(finalizador!=0);
    return 0;
}
#endif // ex5
