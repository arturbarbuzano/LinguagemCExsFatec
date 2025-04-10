#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char filme1[20], filme2[20], filme3[20];
int qt1, qt2, qt3;


void valor1(){

    int i=0, iguais=0;
    printf("\n----------ENTRADA----------\n");

    printf("Digite o nome do primeiro filme: ");
    gets(filme1);
    printf("Agora digite a quantidade de filmes: ");
    scanf("%d", &qt1);
    getchar();

 do {
        printf("Digite o nome do segundo filme: ");
        gets(filme2);  // Usando gets para leitura sem limite de tamanho

        // Comparação manual entre filme1 e filme2
        i = 0;
        while (filme1[i] != '\0' || filme2[i] != '\0') {
            if (filme1[i] != filme2[i]) {
                iguais = 0;  // As strings são diferentes
                break;
            }
            i++;
            if (filme1[i] == '\0' && filme2[i] == '\0') {
                iguais = 1;  // As strings são iguais
            }
        }

        if (iguais) {
            printf("Erro: o segundo filme não pode ter o mesmo nome que o primeiro filme.\n");
        }
    } while (iguais);



    printf("Agora digite a quantidade de filmes: ");
    scanf("%d", &qt2);
    getchar();

    // Terceiro filme
    do {
        iguais = 0;  // Reseta a variável "iguais" antes de cada comparação
        printf("Digite o nome do terceiro filme: ");
        gets(filme3);  // Leitura sem limite de tamanho

        // Comparação manual entre filme1 e filme3
        i = 0;
        while (filme1[i] != '\0' || filme3[i] != '\0') {
            if (filme1[i] != filme3[i]) {
                iguais = 0;
                break;
            }
            i++;
            if (filme1[i] == '\0' && filme3[i] == '\0') {
                iguais = 1;
            }
        }

        // Se o terceiro filme for diferente do primeiro, comparar com o segundo
        if (!iguais) {
            i = 0;
            while (filme2[i] != '\0' || filme3[i] != '\0') {
                if (filme2[i] != filme3[i]) {
                    iguais = 0;
                    break;
                }
                i++;
                if (filme2[i] == '\0' && filme3[i] == '\0') {
                    iguais = 1;
                }
            }
        }

        if (iguais) {
            printf("Erro: o terceiro filme não pode ter o mesmo nome que o primeiro ou o segundo filme.\n");
        }
    } while (iguais);  // Repete até que os nomes sejam diferentes
    printf("Agora digite a quantidade de filmes: ");
    scanf("%d", &qt3);
    getchar();

    FILE *ptr = fopen("filmes.txt", "wb");
    if(ptr == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fwrite(filme1, sizeof(filme1), 1, ptr);
    fwrite(&qt1, sizeof(qt1), 1, ptr);
    fwrite(filme2, sizeof(filme2), 1, ptr);
    fwrite(&qt2, sizeof(qt2), 1, ptr);
    fwrite(filme3, sizeof(filme3), 1, ptr);
    fwrite(&qt3, sizeof(qt3), 1, ptr);
    fclose(ptr);

}

void valor2(){
    FILE *ptr = fopen("filmes.txt", "rb");
    if(ptr == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if(filme1[0] != '*'){
            fread(filme1, sizeof(filme1), 1, ptr);
            fread(&qt1, sizeof(qt1), 1, ptr);
            printf("\n%s %d\n", filme1, qt1);
        }

        if(filme2[0] != '*'){
            fread(filme2, sizeof(filme2), 1, ptr);
            fread(&qt2, sizeof(qt2), 1, ptr);
            printf("%s %d\n", filme2, qt2);
        }

        if(filme3[0] != '*'){
            fread(filme3, sizeof(filme3), 1, ptr);
            fread(&qt3, sizeof(qt3), 1, ptr);
            printf("%s %d\n\n", filme3, qt3);
        }

        fclose(ptr);

}

void valor3(){
    char str[20];
    int i = 0;
    int resposta = 1, cont = 0;

    printf("Digite o nome completo do filme: ");
    gets(str);

    while(str[i] != '\0' || filme1[i] != '\0'){
        if(str[i] != filme1[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        printf("\n%s %d\n", filme1, qt1);
        cont++;
    }
    i = 0;
    resposta = 1;

    while(str[i] != '\0' || filme2[i] != '\0'){
        if(str[i] != filme2[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        printf("\n%s %d\n", filme2, qt2);
        cont++;
    }
    i = 0;
    resposta = 1;

    while(str[i] != '\0' || filme3[i] != '\0'){
        if(str[i] != filme3[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        printf("\n%s %d\n", filme3, qt3);
        cont++;
    }

    if(cont == 0){
        printf("\nEsse filme nao existe\n");
    }

}

void valor4(){
    char letra;
    int i = 0;

    printf("Digite a primeira letra para procura: ");
    scanf(" %c", &letra);

    if(letra == filme1[0]){
        printf("\n%s %d\n", filme1, qt1);
        i++;
    }

    if(letra == filme2[0]){
        printf("\n%s %d\n", filme2, qt2);
        i++;
    }

    if(letra == filme3[0]){
        printf("\n%s %d\n", filme3, qt3);
        i++;
    }

    if(i == 0){
        printf("\nNao existe nenhuma filme que comece com essa letra!\n");
    }

}

void valor5(){
    char str[20];
    int i = 0;
    int resposta = 1, cont = 0, iguais=0;

    printf("Digite o nome completo do filme que deseja substituir: ");
    gets(str);

    while(str[i] != '\0' || filme1[i] != '\0'){
        if(str[i] != filme1[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        do{
            printf("Digite o novo nome do filme: ");
            gets(filme1);
            i = 0;
            while (filme1[i] != '\0' || filme2[i] != '\0') {
                if (filme1[i] != filme2[i]) {
                    iguais = 0;  // As strings são diferentes
                    break;
                }
                i++;
                if (filme1[i] == '\0' && filme2[i] == '\0') {
                    iguais = 1;  // As strings são iguais
                }
            }

              // Se o terceiro filme for diferente do primeiro, comparar com o segundo
        if (!iguais) {
            i = 0;
            while (filme1[i] != '\0' || filme3[i] != '\0') {
                if (filme1[i] != filme3[i]) {
                    iguais = 0;
                    break;
                }
                i++;
                if (filme1[i] == '\0' && filme3[i] == '\0') {
                    iguais = 1;
                }
            }
        }

            if (iguais) {
            printf("Erro: o primeiro filme não pode ter o mesmo nome que o segundo filme ou o terceiro filme.\n");
        }
    } while (iguais);


        printf("Agora digite a quantidade de filmes: ");
        scanf("%d", &qt1);
        getchar();
        cont++;
    }
    iguais = 0;
    i = 0;
    resposta = 1;

    while(str[i] != '\0' || filme2[i] != '\0'){
        if(str[i] != filme2[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        do{
            printf("Digite o novo nome do filme: ");
            gets(filme2);
            i = 0;
            while (filme2[i] != '\0' || filme1[i] != '\0') {
                if (filme2[i] != filme1[i]) {
                    iguais = 0;  // As strings são diferentes
                    break;
                }
                i++;
                if (filme2[i] == '\0' && filme1[i] == '\0') {
                    iguais = 1;  // As strings são iguais
                }
            }

              // Se o terceiro filme for diferente do primeiro, comparar com o segundo
        if (!iguais) {
            i = 0;
            while (filme2[i] != '\0' || filme3[i] != '\0') {
                if (filme2[i] != filme3[i]) {
                    iguais = 0;
                    break;
                }
                i++;
                if (filme2[i] == '\0' && filme3[i] == '\0') {
                    iguais = 1;
                }
            }
        }

            if (iguais) {
            printf("Erro: o segundo filme não pode ter o mesmo nome que o primeiro filme ou o terceiro filme.\n");
        }
    } while (iguais);


        printf("Agora digite a quantidade de filmes: ");
        scanf("%d", &qt2);
        getchar();
        cont++;
    }

    i = 0;
    resposta = 1;

    while(str[i] != '\0' || filme3[i] != '\0'){
        if(str[i] != filme3[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        do{
            printf("Digite o novo nome do filme: ");
            gets(filme3);
            i = 0;
            while (filme3[i] != '\0' || filme1[i] != '\0') {
                if (filme3[i] != filme1[i]) {
                    iguais = 0;  // As strings são diferentes
                    break;
                }
                i++;
                if (filme3[i] == '\0' && filme1[i] == '\0') {
                    iguais = 1;  // As strings são iguais
                }
            }

            // Se o terceiro filme for diferente do primeiro, comparar com o segundo
        if (!iguais) {
            i = 0;
            while (filme3[i] != '\0' || filme2[i] != '\0') {
                if (filme3[i] != filme2[i]) {
                    iguais = 0;
                    break;
                }
                i++;
                if (filme3[i] == '\0' && filme2[i] == '\0') {
                    iguais = 1;
                }
            }
        }

            if (iguais) {
            printf("Erro: o terceiro filme não pode ter o mesmo nome que o primeiro filme ou o segundo filme.\n");
        }
    } while (iguais);


        printf("Agora digite a quantidade de filmes: ");
        scanf("%d", &qt3);
        getchar();
        cont++;
    }

    if(cont == 0){
        printf("\nEsse filme nao existe\n");
    }else{
        FILE *ptr = fopen("filmes.txt", "wb");
        if(ptr == NULL){
            printf("Erro ao abrir o arquivo!\n");
            return;
        }

        fwrite(filme1, sizeof(filme1), 1, ptr);
        fwrite(&qt1, sizeof(qt1), 1, ptr);
        fwrite(filme2, sizeof(filme2), 1, ptr);
        fwrite(&qt2, sizeof(qt2), 1, ptr);
        fwrite(filme3, sizeof(filme3), 1, ptr);
        fwrite(&qt3, sizeof(qt3), 1, ptr);
        fclose(ptr);
    }

}

void valor6(){
    //Pesquisa o nome completo e altere o primeiro termo para * (para excluir)
    char str[20];
    int i = 0;
    int resposta = 1, cont = 0;

    printf("Digite o nome completo do filme que deseja excluir: ");
    gets(str);

    while(str[i] != '\0' || filme1[i] != '\0'){
        if(str[i] != filme1[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        filme1[0] = '*';
        cont++;
    }

    i = 0;
    resposta = 1;

    while(str[i] != '\0' || filme2[i] != '\0'){
        if(str[i] != filme2[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        filme2[0] = '*';
        cont++;
    }

    i = 0;
    resposta = 1;

    while(str[i] != '\0' || filme3[i] != '\0'){
        if(str[i] != filme3[i]){
            resposta = 0;
            break;
        }
        i++;
    }
    if(resposta == 1){
        filme3[0] = '*';
        cont++;
    }

    if(cont == 0){
        printf("\nEsse filme nao existe\n");
    }else{
        FILE *ptr = fopen("filmes.txt", "wb");
        if(ptr == NULL){
            printf("Erro ao abrir o arquivo!\n");
            return;
        }

        if(filme1[0] != '*'){
            fwrite(filme1, sizeof(filme1), 1, ptr);
            fwrite(&qt1, sizeof(qt1), 1, ptr);
        }

        if(filme2[0] != '*'){
            fwrite(filme2, sizeof(filme2), 1, ptr);
            fwrite(&qt2, sizeof(qt2), 1, ptr);
        }

        if(filme3[0] != '*'){
            fwrite(filme3, sizeof(filme3), 1, ptr);
            fwrite(&qt3, sizeof(qt3), 1, ptr);
        }

        fclose(ptr);
    }

}

void valor7(){
exit(0);
}


int main()
{
    setlocale(LC_ALL,"Portuguese");
    int valor;

    do{
        printf("----------MENU----------\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Lista todos os dados na tela\n");
        printf("3 - Pesquisa um filme pelo nome completo e mostrar todos os dados na tela\n");
        printf("4 - Pesquisa os filmes pela 1º letra e mostrar todos na tela.\n");
        printf("5 - Altera dados. Pesquisa pelo nome completo.\n");
        printf("6 - Exclui dados. Pesquisa pelo nome completo.\n");
        printf("7 - Sair\n");
        printf("------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &valor);
        getchar();

        switch(valor){
            case 1:
                valor1();
                break;
            case 2:
                valor2();
                break;
            case 3:
                valor3();
                break;
            case 4:
                valor4();
                break;
            case 5:
                valor5();
                break;
            case 6:
                valor6();
                break;
            case 7:
                valor7();
                break;
            default:
                printf("Valor invalido!");

        }

    }while(valor != 7);
}
