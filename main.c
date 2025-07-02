#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50


typedef struct {
    char nome[MAX_NOME];
    int matricula;
    float nota;
} Aluno;

Aluno lista_de_alunos[MAX_ALUNOS];
int total_alunos = 0;

void adicionar_aluno();


int main() {
    int opcao;

    do {
        printf("\n--- SISTEMA DE CADASTRO DE ALUNOS ---\n");
        printf("1. Adicionar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_aluno();
                break;
            case 2:
                listar_alunos();
                break;
        }
    } while (opcao != 0);

    return 0;
}

void adicionar_aluno() {
    if (total_alunos >= MAX_ALUNOS) {
        printf("Erro: Lista de alunos cheia!\n");
        return;
    }
    printf("\n-- Adicionar Novo Aluno --\n");
    printf("Nome: ");
    scanf(" %49[^\n]", lista_de_alunos[total_alunos].nome);
    printf("Matricula: ");
    scanf("%d", &lista_de_alunos[total_alunos].matricula);
    printf("Nota: ");
    scanf("%f", &lista_de_alunos[total_alunos].nota);

    total_alunos++;
    printf("Aluno adicionado com sucesso!\n");
}

void listar_alunos() {
    if (total_alunos == 0) {
        printf("\nNenhum aluno cadastrado no sistema.\n");
        return;
    }
    printf("\n--- LISTA DE ALUNOS CADASTRADOS ---\n");
    for (int i = 0; i < total_alunos; i++) {
        printf("Nome: %s | Matricula: %d | Nota: %.2f\n",
               lista_de_alunos[i].nome,
               lista_de_alunos[i].matricula,
               lista_de_alunos[i].nota);
    }
}