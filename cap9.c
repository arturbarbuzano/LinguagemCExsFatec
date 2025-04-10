//CAP9

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex6

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

void ReceberConteudo(struct numeros *pv){

    printf("Digite um caractere do tipo char: ");
    scanf("%c", &pv->c);

    printf("Digite um numero do tipo int: ");
    scanf("%d", &pv->i);

    printf("Digite um numero do tipo long: ");
    scanf("%ld", &pv->l);

    printf("Digite um numero do tipo float: ");
    scanf("%f", &pv->f);

    printf("Digite um numero do tipo double: ");
    scanf("%lf", &pv->d);

    printf("Digite um numero do tipo unsigned char: ");
    getchar();
    scanf("%c", &pv->uc);

    printf("Digite um numero do tipo unsigned int: ");
    scanf("%u", &pv->ui);

    printf("Digite um numero do tipo unsigned long: ");
    scanf("%lu", &pv->ul);

    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-4c      %-10d%-12ld        %-8.2f            %-9.2lf \n", pv->c, pv->i, pv->l, pv->f, pv->d);
    printf("          %-3c                 %-10u          %-10lu", pv->uc, pv->ui, pv->ul);
}

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

    do{
    struct numeros valor = {c, i, l, f, d, uc, ui, ul};
    struct numeros *pv;
    pv = &valor;

    ReceberConteudo(pv);

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
    return 0;

}

#endif

#ifdef ex2

int comparar(char*p1, char*p2)
    {

        int i;
        for(i= 0; i<11; i++)
        {
            if(*(p1+i)!= *(p2+i))
            {
                return 0;
            }
            else if(*(p1+i)== '\0')
            {
                return 1;
            }

        }

    }

int main()
{
    int i, p, resposta;
    static char A[11], B[11];
    char *p1, *p2;
    setlocale(LC_ALL,"Portuguese");

    do{
    p1 = A;
    p2 = B;

    printf("Digite até 10 caracteres da string A:\n");
    gets(A);

    printf("Digite até 10 caracteres da string B:\n");
    gets(B);

    p = comparar(p1,p2);
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

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
    return 0;
}

#endif

#ifdef ex3
void operacoes(int *ponteiro)
{

int resultado, num;
char operacao, ch;

resultado = *ponteiro;

printf("Digite a operação:\n");
scanf(" %c", &operacao);

switch(operacao) {

        case '+':

          while(1) {
                printf("Digite um número para somar (ou '=' para terminar): ");
                if (scanf("%d", &num) == 1) {
                    resultado += num;
                } else {
                    // Quando o usuário digitar o caractere '=', o scanf não vai capturar um número
                    // O programa deve parar nesse momento.
                    ch = getchar(); // Consome o caractere residual
                    if (ch == '=')
                        break;
                    else {
                        printf("Entrada inválida. Tente novamente.\n");
                        while(getchar() != '\n'); // Limpa o buffer
                    }
                }
            }
            break;
        case '-':

            while(1){
                printf("Digite um número para subtrair (ou '=' para terminar): ");
                if(scanf("%d", &num) == 1) {
                   resultado -= num;
                } else {

                    ch = getchar();
                    if (ch == '=')
                        break;
                    else {
                        printf("Entrada inválida. Tente novamente.\n");
                        while(getchar() != '\n'); // Limpa o buffer
                    }
                }
            }
            break;

        case '*':

            while(1) {
                printf("Digite um número para multiplicar (ou '=' para terminar): ");
                if(scanf("%d", &num) ==1) {
            resultado *= num;
            } else{

                ch = getchar();
                if (ch == '=')
                        break;
                else {
                    printf("Entrada inválida. Tente novamente.\n");
                    while(getchar() != '\n'); // Limpa o buffer
                }
            }
            }
            break;
        case '/':

        while(1){
            printf("Digite um número para dividir (ou '=' para terminar): ");
            if(scanf("%d", &num)==1){
            if (num != 0) {
                resultado /= num;
            } else {
                printf("Erro: Divisão por zero.\n");
                return;
            }
            }
            else{

                ch = getchar();
                if (ch == '=')
                        break;
                else {
                    printf("Entrada inválida. Tente novamente.\n");
                    while(getchar() != '\n'); // Limpa o buffer
                }
            }
        }
            break;
        case '=':

            printf("Operação finalizada :D");
            break;
        default:

            printf("Operação inválida.\n");
            return;
    }
    printf("Resultado: %d", resultado);

}


void entrada(int *p1)
{

    printf("------------ENTRADA DE DADOS------------\n\n");

    printf("Digite um número:\n");
    scanf("%d", p1);

}
int main()
{
    int *p, num, resposta;
    setlocale(LC_ALL, "Portuguese");

    do{
    p = &num;

    entrada(p);
    operacoes(p);

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);

    }while(resposta == 1);

    return 0;
}

#endif

#ifdef ex4

int PesquisarLetra(char *pl, char *pv){

    int cont = 0;
    if(*pl == *pv){
        cont++;
    }

    return cont;

}

int main()
{
    char *pv, vet[13] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
    int resultado, i, cont = 0, resposta;
    char *pl, letra;
    pl = &letra;

    do{
    printf("Digite uma letra (minuscula): ");
    scanf("%c", pl);

    for(i = 0; i < 13; i++){
        pv = &vet[i];
        resultado = PesquisarLetra(pl, pv);

        if(resultado == 1){
            cont = 1;
            printf("A letra digitada existe!\n");
        }
    }
    if(cont == 0){
        printf("A letra digitada NAO existe!\n");
    }

    printf("\nDigite 1 para refazer ou qualquer outro número para encerrar o programa: ");
    scanf("%d", &resposta);
    getchar();

    }while(resposta == 1);
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


void Receba(struct pessoa *p){
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

void Toma(struct pessoa *p){
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
    struct pessoa elementos[4];
    struct pessoa *p;
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
                Receba(p);
                break;
            case 2:
                Toma(p);
                break;
            case 3:
                exit(0);
        }
    }while(opcao != 3);
}

#endif

#ifdef ex6

struct pessoa {
    char nome[50];
    char end[50];
    char cidade[50];
    char estado[50];
    char cep[11];
};

void Receba(struct pessoa *p) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("\n\tPESSOA %d\n", i + 1);
        printf("Digite o nome:\n");
        gets(p[i].nome);
        printf("Digite o endereço:\n");
        gets(p[i].end);
        printf("Digite a cidade:\n");
        gets(p[i].cidade);
        printf("Digite o estado:\n");
        gets(p[i].estado);
        printf("Digite o cep:\n");
        gets(p[i].cep);
    }
}

void Toma(struct pessoa *p) {
    int i, algumRegistro = 0;

    for (i = 0; i < 4; i++) {
        if (p[i].nome[0] != '\0') {
            printf("\n\tPESSOA %d\n", i + 1);
            printf("Nome: %s\n", p[i].nome);
            printf("Endereço: %s\n", p[i].end);
            printf("Cidade: %s\n", p[i].cidade);
            printf("Estado: %s\n", p[i].estado);
            printf("Cep: %s\n", p[i].cep);
            algumRegistro = 1;
        }
    }

    if (!algumRegistro) {
        printf("\nNao ha registros para exibir.\n");
    }
}


void Procurar(struct pessoa *p) {
    char nomeBusca[50];
    int i, encontrado = 0;

    printf("Digite o nome da pessoa que deseja procurar:\n");
    gets(nomeBusca);

    for (i = 0; i < 4; i++) {

        int j = 0;
        while (p[i].nome[j] == nomeBusca[j] && p[i].nome[j] != '\0' && nomeBusca[j] != '\0') {
            j++;
        }
        if (p[i].nome[j] == '\0' && nomeBusca[j] == '\0') {
            printf("\nPessoa encontrada:\n");
            printf("Nome: %s\n", p[i].nome);
            printf("Endereço: %s\n", p[i].end);
            printf("Cidade: %s\n", p[i].cidade);
            printf("Estado: %s\n", p[i].estado);
            printf("Cep: %s\n", p[i].cep);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Pessoa não encontrada.\n");
    }
}


void Alterar(struct pessoa *p) {
    char nomeBusca[50];
    int i, encontrado = 0;

    printf("Digite o nome da pessoa que deseja alterar:\n");
    gets(nomeBusca);

    for (i = 0; i < 4; i++) {
        int j = 0;
        while (p[i].nome[j] == nomeBusca[j] && p[i].nome[j] != '\0' && nomeBusca[j] != '\0') {
            j++;
        }
        if (p[i].nome[j] == '\0' && nomeBusca[j] == '\0') {
            printf("\nPessoa encontrada. Digite os novos dados:\n");
            printf("Digite o nome:\n");
            gets(p[i].nome);
            printf("Digite o endereço:\n");
            gets(p[i].end);
            printf("Digite a cidade:\n");
            gets(p[i].cidade);
            printf("Digite o estado:\n");
            gets(p[i].estado);
            printf("Digite o cep:\n");
            gets(p[i].cep);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Pessoa não encontrada.\n");
    }
}


void Excluir(struct pessoa *p) {
    char nomeBusca[50];
    int i, encontrado = 0;

    printf("Digite o nome da pessoa que deseja excluir:\n");
    gets(nomeBusca);

    for (i = 0; i < 4; i++) {
        int j = 0;
        while (p[i].nome[j] == nomeBusca[j] && p[i].nome[j] != '\0' && nomeBusca[j] != '\0') {
            j++;
        }
        if (p[i].nome[j] == '\0' && nomeBusca[j] == '\0') {
            printf("\nPessoa encontrada. Excluindo...\n");

            p[i].nome[0] = '\0';
            p[i].end[0] = '\0';
            p[i].cidade[0] = '\0';
            p[i].estado[0] = '\0';
            p[i].cep[0] = '\0';
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Pessoa nao encontrada.\n");
    }
}


int main() {
    int opcao;
    struct pessoa elementos[4];
    struct pessoa *p;
    p = &elementos[0];
    setlocale(LC_ALL,"Portuguese");

    do {
        printf("\n---------------MENU---------------\n");
        printf("1 - Entrada de Dados.\n");
        printf("2 - Exibir Dados.\n");
        printf("3 - Procurar Registro.\n");
        printf("4 - Alterar Registro.\n");
        printf("5 - Excluir Registro.\n");
        printf("6 - Sair\n");

        printf("\nDigite uma das opções acima:\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                Receba(p);
                break;
            case 2:
                Toma(p);
                break;
            case 3:
                Procurar(p);
                break;
            case 4:
                Alterar(p);
                break;
            case 5:
                Excluir(p);
                break;
            case 6:
                exit(0);
            default:
                printf("Opcão inválida.\n");
        }
    } while (opcao != 6);

    return 0;
}

#endif





