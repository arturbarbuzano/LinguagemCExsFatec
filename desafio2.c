#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct dados
{
   char filme[50];
   int quantidade;
   float preco;
   char datalancamento[11];
}dados;

void valor1(dados *ponteiro)
{
    FILE *p;
    int i, existe = 0;
    dados tamanho;


    if((p = fopen("arq.txt","a+"))==NULL)
    {
        printf("Erro na abertura do arquivo \n");
        exit(0);
    }

    printf("Digite o nome do filme:\n");
    gets(ponteiro->filme);

    while(fread(&tamanho, sizeof(tamanho), 1, p)){
        i = 0;

        while(tamanho.filme[i] != '\0' && ponteiro->filme[i] != '\0'){
            if(tamanho.filme[i] != ponteiro->filme[i]){
                break;
            }
            i++;
        }

        if(tamanho.filme[i] == '\0' && ponteiro->filme[i] == '\0'){
            existe = 1;
            break;
        }
    }

    if(existe == 1){
        printf("Esse filme já existe no banco de dados!\n");
    }
    else{

        printf("Digite a quantidade:\n");
        scanf("%d", &ponteiro->quantidade);
        printf("Digite o preço do filme:\n");
        scanf("%f", &ponteiro->preco);
        getchar();
        printf("Digite a data de lançamento:\n");
        gets(ponteiro->datalancamento);

        fwrite(ponteiro,sizeof(*ponteiro),1,p);


    }
    fclose(p);

}

void valor2(dados *ponteiro)
{
    FILE *p;

    if((p = fopen("arq.txt","r"))==NULL)
    {
           printf("Erro na abertura do arquivo \n");
           exit(0);
    }

    while(fread(ponteiro, sizeof(*ponteiro), 1, p)) {
        if(ponteiro->filme[0] != '*')
        {
            printf("Nome do filme: %s\n", ponteiro->filme);
            printf("Quantidade: %d\n", ponteiro->quantidade);
            printf("Preço: R$ %.2f\n", ponteiro->preco);
            printf("Data de lançamento: %s\n\n", ponteiro->datalancamento);
        }
    }

    fclose(p);

}

void valor3(dados *ponteiro)
{
    FILE *p;
    int i=0, igual=1, encontrado=0;
    char nome[100];

    if((p = fopen("arq.txt","r"))==NULL)
      {
           printf("Erro na abertura do arquivo \n");
           exit(0);
      }
      printf("Digite o nome do filme:\n");
      gets(nome);

      while (fread(ponteiro, sizeof(*ponteiro),1, p)) {
        while (nome[i] && ponteiro->filme[i]) {
            if (nome[i] != ponteiro->filme[i]) {
                igual=0;
                break;
            }
            i++;
        }
        if(ponteiro->filme[0] != '*'){
            if (nome[i] == '\0' && ponteiro->filme[i] == '\0') {
                printf("\n\nFilme encontrado:\n");
                printf("Nome: %s\n", ponteiro->filme);
                printf("Quantidade: %d\n", ponteiro->quantidade);
                printf("Preço: R$ %.2f\n", ponteiro->preco);
                printf("Data de lançamento: %s\n\n", ponteiro->datalancamento);
                encontrado = 1;
                break;
            }
        }
    }

    if (encontrado != 1) {
        printf("Registro não encontrado.\n");
    }
    fclose(p);
}

void valor4(dados *ponteiro)
{
    FILE *p;
    int i, existe = 0;
    dados tamanho;

    if((p = fopen("arq.txt","r"))==NULL)
    {
        printf("Erro na abertura do arquivo \n");
        exit(0);
    }

    printf("Digite o nome do filme: \n");
    gets(ponteiro->filme);

    while(fread(&tamanho, sizeof(tamanho), 1, p)){
        i = 0;
        while(tamanho.filme[i] != '\0' && ponteiro->filme[i] != '\0'){
            if(tamanho.filme[i] != ponteiro->filme[i]){
                break;
            }
            i++;
        }

        if(tamanho.filme[i] == '\0' && ponteiro->filme[i] == '\0'){
            existe = 1;
            break;
        }
    }
    fclose(p);

    if(existe == 1){
        printf("Data de lançamento do %s: ", ponteiro->filme);
        for(i = 3; i < 10; i++){
            printf("%c", tamanho.datalancamento[i]);
        }
        printf("\n");
    }
    else{
        printf("Filme não encontrado no banco de dados!!!\n\n");
    }

}

void valor5(dados *ponteiro)
{
    FILE *p;
    float valorMin, valorMax;
    int cont = 0;

    if((p = fopen("arq.txt","r"))==NULL)
      {
           printf("Erro na abertura do arquivo \n");
           exit(0);
      }

    printf("Digite o valor mínimo para a criação da faixa de preço:");
    scanf("%f", &valorMin);
    printf("Agora digite o valor máximo: ");
    scanf("%f", &valorMax);

    while (fread(ponteiro, sizeof(*ponteiro), 1, p)) {
        if(ponteiro->filme[0] != '*')
        {
            if (ponteiro->preco >= valorMin && ponteiro->preco <= valorMax) {
                printf("Nome: %s (R$ %.2f)\n", ponteiro->filme, ponteiro->preco);
                cont++;
            }
        }
    }

    if(cont == 0){
        printf("\n\nNão há nenhum filme nessa faixa de preço dentro do banco de dados!!!\n\n");
    }

    fclose(p);
}

void valor6(dados *ponteiro)
{
    FILE *p;
    int encontrado = 0, i, igual;
    char nome[100];

    if((p = fopen("arq.txt","r+"))==NULL)
      {
           printf("Erro na abertura do arquivo \n");
           exit(0);
      }

      printf("Digite o nome completo do filme que deseja alterar a quantidade:\n");
      gets(nome);

      while (fread(ponteiro, sizeof(*ponteiro), 1, p)) {
        i = 0, igual = 1;

        while (nome[i] != '\0' && ponteiro->filme[i] != '\0') {
            if (nome[i] != ponteiro->filme[i]) {
                igual = 0;
                break;
            }
            i++;
        }
        if (nome[i] != '\0' || ponteiro->filme[i] != '\0') {
            igual = 0;
        }

        if (igual == 1) {
            printf("Filme encontrado.\nInsira a nova quantidade:\n");
            scanf("%d",&ponteiro->quantidade);

            fseek(p, -sizeof(*ponteiro), 1);
            fwrite(ponteiro, sizeof(*ponteiro), 1, p);

            encontrado = 1;
            break;
        }
    }

     if (encontrado==1) {
        printf("Quantidade alterada com sucesso.\n");
    } else {
        printf("Filme não encontrado.\n");
    }
    fclose(p);

}

void valor7(dados *ponteiro)
{
     FILE *p;
    int encontrado=0, i, igual;
    char nome[100];

    if((p = fopen("arq.txt","r+"))==NULL)
      {
           printf("Erro na abertura do arquivo \n");
           exit(0);
      }

      printf("Digite o nome completo do filme que deseja alterar o preço:\n");
      gets(nome);

      while (fread(ponteiro, sizeof(*ponteiro), 1, p)) {
        i = 0, igual = 1;


        while (nome[i] != '\0' && ponteiro->filme[i] != '\0') {
            if (nome[i] != ponteiro->filme[i]) {
                igual = 0;
                break;
            }
            i++;
        }
        if (nome[i] != '\0' || ponteiro->filme[i] != '\0') {
            igual = 0;
        }

        if (igual) {
            printf("Filme encontrado.\nInsira o novo preço:\n");
            scanf("%f",&ponteiro->preco);

            fseek(p, -sizeof(*ponteiro), 1);
            fwrite(ponteiro, sizeof(*ponteiro), 1, p);

            encontrado = 1;
            break;
        }
    }

     if (encontrado==1) {
        printf("Preço alterado com sucesso.\n");
    } else {
        printf("Filme não encontrado.\n");
    }
    fclose(p);
}

void valor8(dados *ponteiro)
{
    FILE *p;
    char nome[100], novoNome[100];
    int i, igual, novoIgual, encontrado = 0, registroAtual = 0, registroAlterar = -1;

    if ((p = fopen("arq.txt", "r+")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    printf("Digite o nome completo do filme que deseja alterar:\n");
    gets(nome);


    while (fread(ponteiro, sizeof(*ponteiro), 1, p)) {
        i = 0;
        igual = 1;


        while (nome[i] != '\0' && ponteiro->filme[i] != '\0') {
            if (nome[i] != ponteiro->filme[i]) {
                igual = 0;
                break;
            }
            i++;
        }
        if (nome[i] != '\0' || ponteiro->filme[i] != '\0') {
            igual = 0;
        }

        if (igual == 1) {
            encontrado = 1;
            registroAlterar = registroAtual;
            break;
        }
        registroAtual++;
    }

    if (!encontrado) {
        printf("Filme não encontrado.\n");
        fclose(p);
        return;
    }

    printf("Filme encontrado. Insira os novos dados:\n");
    printf("Digite o novo nome do filme:\n");
    gets(novoNome);

    fseek(p,0,0);

    while (fread(ponteiro, sizeof(*ponteiro), 1, p)) {
        i = 0;
        novoIgual = 1;

        while (novoNome[i] != '\0' && ponteiro->filme[i] != '\0') {
            if (novoNome[i] != ponteiro->filme[i]) {
                novoIgual = 0;
                break;
            }
            i++;
        }
        if (novoNome[i] != '\0' || ponteiro->filme[i] != '\0') {
            novoIgual = 0;
        }

        if (novoIgual == 1) {
            printf("Esse filme já existe no arquivo. Operação cancelada.\n");
            fclose(p);
            return;
        }
    }

    printf("Digite a nova quantidade:\n");
    scanf("%d", &ponteiro->quantidade);

    printf("Digite o novo preço:\n");
    scanf("%f", &ponteiro->preco);
    getchar();

    printf("Digite a nova data de lançamento (mês/ano):\n");
    gets(ponteiro->datalancamento);


    i = 0;
    while (novoNome[i] != '\0') {
        ponteiro->filme[i] = novoNome[i];
        i++;
    }
    ponteiro->filme[i] = '\0';

    fseek(p, registroAlterar * sizeof(*ponteiro), 0);

    fwrite(ponteiro, sizeof(*ponteiro), 1, p);

    printf("Dados alterados com sucesso.\n");

    fclose(p);
}

void valor9(dados *ponteiro)
{
    FILE*p;
    int i, igual;
    char nome[100];

     if((p = fopen("arq.txt","r+"))==NULL)
      {
           printf("Erro na abertura do arquivo \n");
           exit(0);
      }

      printf("Digite o nome do filme que deseja excluir:\n");
      gets(nome);

     while (fread(ponteiro, sizeof(*ponteiro), 1, p)) {
        i = 0, igual = 1;
        while (nome[i] != '\0' && ponteiro->filme[i] != '\0') {
            if (nome[i] != ponteiro->filme[i]) {
                igual = 0;
                break;
            }
            i++;
        }
        if (nome[i] != '\0' || ponteiro->filme[i] != '\0') {
            igual = 0;
        }

        if (igual == 1) {
            ponteiro->filme[0] = '*';
            fseek(p, -sizeof(*ponteiro), 1);
            fwrite(ponteiro, sizeof(*ponteiro), 1, p);
            printf("Registro excluído logicamente com sucesso!\n");
            break;
        }
     }
     if(igual == 0){
        printf("Filme não encontrado!\n\n");

     }
    fclose(p);
}

int main()
{
setlocale(LC_ALL,"Portuguese");

    int valor;

    dados dadosFilme;
    dados *ponteiro;

    ponteiro = &dadosFilme;

    do{
        printf("----------MENU----------\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Lista todos os filmes na tela\n");
        printf("3 - Pesquisar um filme pelo nome completo e mostra todos os dados na tela\n");
        printf("4 - Pesquisar data de lançamento do filme(mês/ano)\n");
        printf("5 - Listar filmes por faixa de preço\n");
        printf("6 - Altera quantidade em estoque (entrada e saída)\n");
        printf("7 - Altera preço de um filme pesquisado pelo nome completo\n");
        printf("8 - Altera todos os dados do filme pesquisado pelo nome completo\n");
        printf("9 - Exclui filme pesquisado pelo nome completo\n");
        printf("10 - Saída\n");
        printf("------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &valor);
        getchar();

        switch(valor){

            case 1:
                valor1(ponteiro);
                break;
            case 2:
                valor2(ponteiro);
                break;
            case 3:
                valor3(ponteiro);
                break;
            case 4:
                valor4(ponteiro);
                break;
            case 5:
                valor5(ponteiro);
                break;
            case 6:
                valor6(ponteiro);
                break;
            case 7:
                valor7(ponteiro);
                break;
            case 8:
                valor8(ponteiro);
                break;
            case 9:
                valor9(ponteiro);
                break;
            case 10:
                exit(0);
            default:
                printf("Valor inválido!");
        }
    }while(valor!=10);

    return 0;
}
