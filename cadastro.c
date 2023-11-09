#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_LISTA 3
//declaracao do registro
typedef struct{
    char nome[20];
    int idade;
    int id;
    int status;
}Pessoa;

void cadastrar(Pessoa p[], int indice) {
    p[indice].status = 1; //ativo no momento do cadastro
    p[indice].id = rand() % 100; //gerar id automatico
    fflush(stdin);
    printf("\n Digite o nome da pessoa: ");
    fflush(stdin);
    fgets(p[indice].nome, sizeof(p[indice].nome), stdin);
    fflush(stdin);
    printf("\n Digite a idade da pessoa: ");
    scanf("%d", &p[indice].idade);
}

void imprimirLista(Pessoa p[], int tamanhoLista) {
    if(tamanhoLista == 0) {
        printf("lista vazia");
    } else {
        for(int i = 0; i < tamanhoLista; i++) {
            printf("\n Nome: %s", p[i].nome);
            printf("\n Idade: %d", p[i].idade);
            printf("\n ID: %s", p[i].id);
            if(p[i].status == 1) {
                printf("\n Status: ativo \n");
            } else {
                printf("\n Status: inativo \n");
            }
        }
    }
}

void buscar(Pessoa p[], int tamanhoLista, int id) {
    if (tamanhoLista == 0) {
        printf("Lista vazia");
        return;
    } else {
        for(int i = 0; i < tamanhoLista; i++) {
            if(p[i].id == id) {
                printf("\n Registro encontrado");
                printf("\n Nome: %s", p[i].nome);
                printf("\n Idade: %d", p[i].idade);
                return;
            }
        }
    }
    
    printf("\n Registro nao existe na lista");

}

void alterar(Pessoa p[], int tamanhoLista, int id, int opcao) {
    if(tamanhoLista == 0) {
        printf("Lista vazia");
        return;
    } else {
        for(int i = 0; i < tamanhoLista; i++) {
            if(p[i].id == id) {
                printf("\n Registro encontrado: ");
                printf("\n Nome: %s", p[i].nome);
                printf("\n Idade: %d", p[i].idade);
                printf("\n");
                
                printf("\n Digite 1 para alterar nome");
                printf("\n Digite 2 para alterar idade");
                printf("\n Digite 3 para alterar status");
                printf("\n Digite 1 para alterar todos \n");
                scanf("%d", opcao);
                
                switch(opcao) {
                    case 1:
                        printf("\n \n Alteracao do nome: ");
                        fgets(p[i].nome, sizeof(p[i].nome), stdin);
                    break;
                        
                    case 2:
                        printf("\n\n Alteracao da idade: ");
                        scanf("%d", &p[i].idade);
                    break;
                        
                    case 3:
                        printf("\n\n Alteracao do status: 1 - Ativo / 0 - Inativo");
                        scanf("%d", &p[i].status);
                    break;

                    case 4:
                        printf("\n \n Alteracao do nome: ");
                        fgets(p[i].nome, sizeof(p[i].nome), stdin);

                        printf("\n\n Alteracao da idade: ");
                        scanf("%d", &p[i].idade);

                        printf("\n\n Alteracao do status: 1 - Ativo / 0 - Inativo");
                        scanf("%d", &p[i].status);
                    break;

                    //case 5:
                }
            }
        }
    }
}

void excluir(Pessoa p[], int tamanhoLista, int id) {
    if(tamanhoLista == 0) {
        printf("Lista vazia");
        return;
    } else {
        for(int i = 0; i < tamanhoLista; i++) {
            if(p[i].id == id) { //registro encontrado
                for(int j = i; j < tamanhoLista-1 ; j++) {
                    p[j] = p[j - 1]; 
                }
                printf("\n Deletado com sucesso!");
                return;
            }
        }
    }
    printf("ID nao encontrado");
}


int main(){
    Pessoa p[TAM_LISTA];
    int totalCadastro = 0, opcao, buscaID;

    do{
        printf("\n Digite 1 para cadastrar");
        printf("\n Digite 2 para mostrar lista");
        printf("\n Digite 3 para buscar");
        printf("\n Digite 4 para alterar");
        printf("\n Digite 5 para excluir");
        printf("\n Digite 0 para sair do sistema \n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                //cadastrar
                if(totalCadastro < TAM_LISTA) {
                    cadastrar(p, totalCadastro);
                    totalCadastro++;
                } else {
                    printf("Total de cadastros atingido");
                }
            break;
            
            case 2:
                //mostrar/imprimir lista
                imprimirLista(p, totalCadastro);
            break;
            
            case 3:
                //buscar
                printf("\n Digite o ID para buscar: ");
                scanf("%d", &buscaID);
                buscar(p, totalCadastro, buscaID);
            break;
            
            case 4:
                //alterar
                printf("\n Digite o ID para alteracao: ");
                scanf("%d", &buscaID);
                buscar(p, totalCadastro, buscaID);
            break;
            
            case 5:
                //excluir
                printf("\n Digite a ID para alterar: ");
                scanf("%d", &buscaID);
                excluir(p, totalCadastro, buscaID);
                totalCadastro++;
            break;

        }

    }while(opcao != 0);

    return 0;

}