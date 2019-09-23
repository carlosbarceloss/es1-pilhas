//
//  main.c
//  Filas
//
//  Created by Carlos Barcelos on 20/09/19.
//  Copyright © 2019 Carlos Barcelos. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char string[100];
} String;

typedef struct {
    String stringPile[10];
    int top;
} Pile;

Pile* initPile(void);
void insertInTop(Pile* p, String str);
void removeFromTop(Pile* p);
void printPile(Pile* p);
String readString(String str);

int main() {
    int option;
    Pile* pilha = NULL;
    String string;
    
    do {
        printf("\n*---- MENU PRINCIPAL ----*\n");
        printf("1 - Iniciar uma pilha\n2 - Inserir nova string\n3 - Remover string\n4 - Mostrar pilha\n5 - Sair\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                pilha = initPile();
                printf("Uma nova pilha foi iniciada!\n");
                break;
            case 2:
                if (pilha == NULL) {
                    printf("Você deve criar uma pilha para inserir elementos!\n");
                    break;
                } else if (pilha -> top == 9){
                    printf("Você já chegou ao limite dessa pilha! Para adicionar mais, crie outra.\n");
                    break;
                } else {
                    printf("*---- Inserir nova string ----*\n");
                    insertInTop(pilha, readString(string));
                    printf("Sua string foi adicionada com sucesso!\n");
                    break;
                }
            case 3:
                if (pilha == NULL || pilha -> top < 0) {
                    printf("Impossível remover elementos, a pilha está vazia!\n");
                    break;
                } else {
                    removeFromTop(pilha);
                    printf("A string do topo foi removida com sucesso!\n");
                    break;
                }
            case 4:
                if (pilha == NULL || pilha -> top < 0) {
                    printf("A pilha está vazia!\n");
                } else {
                    printPile(pilha);
                    break;
                }
            case 5:
                break;
            default:
                fpurge(stdin);
                printf("Opção inválida! (1 - 5)\n");
                break;
        }
        
    } while (option != 5);
    
}

Pile* initPile(void) {
    Pile* p = (Pile*)malloc(sizeof(Pile));
    if (p != NULL){
        p -> top = -1;
    }
    return p;
}

void insertInTop(Pile* p, String str) {
    p -> top++;
    p -> stringPile[p -> top] = str;
}

void removeFromTop(Pile* p) {
    String emptyString;
    strcpy(p -> stringPile[p -> top].string, emptyString.string);
    p -> top--;
}

void printPile(Pile* p) {
    int i, j = 1;
    for (i = p -> top; i >= 0 ; i--) {
        printf("Posição: %d | String: %s\n", j, p -> stringPile[i].string);
        j++;
    }
}

String readString(String str) {
    printf("Insira sua string: ");
    fpurge(stdin);
    fgets(str.string, 100, stdin);
    return str;
}
