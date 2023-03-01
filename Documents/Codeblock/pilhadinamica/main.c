#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dado;
    struct Node *next;
};

struct Pilha {
    struct Node *top;
};

void initialize(struct Pilha *pilha) {
    pilha->top = NULL;
}

int isEmpty(struct Pilha *pilha) {
    return pilha->top == NULL;
}

void push(struct Pilha *pilha, int item) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->dado = item;
    newNode->next = pilha->top;
    pilha->top = newNode;
}

int pop(struct Pilha *pilha) {
    if (isEmpty(pilha)) {
        printf("Pilha vazia\n");
        return -1;
    }
    struct Node *temp = pilha->top;
    int item = temp->dado;
    pilha->top = temp->next;
    free(temp);
    return item;
}

void display(struct Pilha *pilha) {
    if (isEmpty(pilha)) {
        printf("Pilha ta vazia\n");
        return;
    }
    struct Node *temp = pilha->top;
    int i = 1;
    int pilhaDado[100];
    while (temp != NULL) {
        pilhaDado[i] = temp->dado;
        temp = temp->next;
        i++;
    }
    int x = 1;
    printf("\nExibindo o vetor\n");
    for (int j = i - 1; j >= 1; j--) {
        printf("Vetor:%d || item:%d\n", x, pilhaDado[j]);
        x++;
    }
}

int main() {
    struct Pilha pilha;
    initialize(&pilha);

    int escolha, item;

    while (1) {
        printf("\n=========Menu do vetor=========\n");
        printf("Somente numeros inteiros\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Exibir o vetor\n");
        printf("4. Sair\n");
        printf("Entre com sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Entre com o item a ser inserido: ");
                scanf("%d", &item);
                push(&pilha, item);
                break;
            case 2:
                item = pop(&pilha);
                if (item != -1) {
                    printf("Removido o item: %d\n", item);
                }
                break;
            case 3:
                display(&pilha);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Escolha invalida\n");
                break;
        }
    }

    return 0;
}


/*
Nesta implementação, a pilha é representada por uma
estrutura Stack que contém um ponteiro para o topo da pilha.
A estrutura Node representa cada elemento da pilha e contém um
valor data e um ponteiro next para o próximo elemento na pilha.
A função initialize inicializa a pilha, definindo o valor de top
como NULL para indicar que a pilha está vazia. A função isEmpty
verifica se a pilha está vazia. A função push adiciona um item à
pilha, criando um novo nó e atualizando o ponteiro top para apontar
para o novo nó. A função pop remove o item do topo da pilha, liberando
 a memória alocada para o nó removido.*/
