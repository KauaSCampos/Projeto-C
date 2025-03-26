#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100  

// Definicao da estrutura do aluno
typedef struct {
    int matricula;
    char nome[50];
    char curso[50];
} Aluno;

Aluno alunos[MAX_ALUNOS];  
int totalAlunos = 0;  

// Funcao para cadastrar um aluno
void cadastrarAluno() {
    if (totalAlunos < MAX_ALUNOS) {
        printf("\n--- Cadastro de Aluno ---\n");
        printf("Matricula: ");
        scanf("%d", &alunos[totalAlunos].matricula);
        getchar();  
        printf("Nome: ");
        fgets(alunos[totalAlunos].nome, 50, stdin);
        printf("Curso: ");
        fgets(alunos[totalAlunos].curso, 50, stdin);
        
        totalAlunos++;
        printf("\nAluno cadastrado com sucesso!\n");
    } else {
        printf("\nLimite de alunos atingido!\n");
    }
}

// Funcao para listar todos os alunos cadastrados
void listarAlunos() {
    if (totalAlunos == 0) {
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }

    printf("\n--- Lista de Alunos ---\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nome: %s", alunos[i].nome);
        printf("Curso: %s", alunos[i].curso);
        printf("---------------------\n");
    }
}

// Funcao para buscar aluno por matricula
void buscarAluno() {
    int matricula;
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &matricula);

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("\nAluno encontrado!\n");
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Nome: %s", alunos[i].nome);
            printf("Curso: %s", alunos[i].curso);
            return;
        }
    }

    printf("\nAluno nao encontrado!\n");
}

// Funcao para excluir um aluno por matricula
void excluirAluno() {
    int matricula, encontrado = 0;
    printf("\nDigite a matricula do aluno a ser excluido: ");
    scanf("%d", &matricula);

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            encontrado = 1;
            for (int j = i; j < totalAlunos - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            totalAlunos--;
            printf("\nAluno excluido com sucesso!\n");
            return;
        }
    }

    if (!encontrado) {
        printf("\nAluno nao encontrado!\n");
    }
}

// Funcao principal (menu do sistema)
int main() {
    int opcao;
    do {
        printf("\n=== Sistema de Cadastro de Alunos ===\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Buscar Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  

        switch (opcao) {
            case 1: cadastrarAluno(); break;
            case 2: listarAlunos(); break;
            case 3: buscarAluno(); break;
            case 4: excluirAluno(); break;
            case 5: printf("\nSaindo...\n"); break;
            default: printf("\nOpcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
