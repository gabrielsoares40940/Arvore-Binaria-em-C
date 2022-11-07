#include <stdio.h>
#include <stdlib.h>

// Definição da struct item
struct item {
    int cod;
};

typedef struct item Item;

// Definição da struct node
struct node {
    Item item;
    struct node *esquerda;
    struct node *direita;
};

typedef struct node Node;

// Função para inicializar a árvore
Node *treeInitialize() {
    return NULL;
}

// Função para criar a árvore
Item itemCreate(int cod) {
    Item item;
    item.cod = cod;
    return item;
}

// Função para inserir filhos na árvore
Node *treeInsert(Node *root, Item x) {
    if (root == NULL) {
        Node *aux = (Node *)malloc(sizeof(Node));
        aux->item = x;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    } else {
        if (x.cod > root->item.cod) {
            root->direita = treeInsert(root->direita, x);
        } else {
            if (x.cod < root->item.cod) {
                root->esquerda = treeInsert(root->esquerda, x);
            }
        }
    }
    return root;
}

// Função para "printar" a árvore
void treePrint(Node *root) {
    if (root != NULL) {
        printf("%d ", root->item.cod);
        treePrint(root->esquerda);
        treePrint(root->direita);
    }
}

// Função para liberar valor na árvore
void treeFree(Node *root) {
    if (root != NULL) {
        treeFree(root->esquerda);
        treeFree(root->direita);
        free(root);
    }
}

// Função para procurar elemento na árvore
Node *treeSearch(Node *root, int cod) {
    if (root != NULL) {
        if (root->item.cod == cod) {
            return root;
        } else {
            if (cod > root->item.cod) {
                return treeSearch(root->direita, cod);
            } else {
                return treeSearch(root->esquerda, cod);
            }
        }
    }
    return NULL;
}

// Função para 
Node *treeMin(Node *root) {
    if (root != NULL) {
        Node *aux = root;
        while (aux->esquerda != NULL) {
            aux = aux->esquerda;
        }
        return aux;
    }
}

// Função para remover elemento da árvore
Node *treeRemove(Node *root, int cod) 
{
    if (root != NULL) {
        if (cod > root->item.cod) {
            root->direita = treeRemove(root->direita, cod);
        } else if (cod < root->item.cod) {
            root->esquerda = treeRemove(root->esquerda, cod); 
        } 
        else {
            // Encontrou o elemento a ser removido
            if (root->esquerda == NULL && root->direita == NULL) {
                free(root);
                return NULL;
            } else if (root->esquerda == NULL && root->direita == NULL) {
                Node *aux = root->direita;
                free(root);
            } else if (root->esquerda == NULL && root->direita == NULL) {
                Node *aux = root->esquerda;
                free(root);
                return aux;
            } else {
                Node *aux = treeMin(root->direita);
                Item itemAux = aux->item;
                root = treeRemove(root, itemAux.cod);
                root->item = itemAux;
            }
        }
        return root;
    }
    return NULL;
}


int main() {
    int valor;

    Node *root = treeInitialize();

    root = treeInsert(root, itemCreate(10));
    root = treeInsert(root, itemCreate(5));
    root = treeInsert(root, itemCreate(50));
    root = treeInsert(root, itemCreate(213));
    root = treeInsert(root, itemCreate(0));

    root = treeInsert(root, itemCreate(30));
    root = treeInsert(root, itemCreate(3));
    root = treeInsert(root, itemCreate(60));
    root = treeInsert(root, itemCreate(90));
    root = treeInsert(root, itemCreate(80));

    root = treeInsert(root, itemCreate(32));
    root = treeInsert(root, itemCreate(53));
    root = treeInsert(root, itemCreate(904));
    root = treeInsert(root, itemCreate(1003));
    root = treeInsert(root, itemCreate(4321));

    root = treeInsert(root, itemCreate(2456));
    root = treeInsert(root, itemCreate(89));
    root = treeInsert(root, itemCreate(235));
    root = treeInsert(root, itemCreate(361));
    root = treeInsert(root, itemCreate(839));

    root = treeInsert(root, itemCreate(395));
    root = treeInsert(root, itemCreate(165));
    root = treeInsert(root, itemCreate(6523));
    root = treeInsert(root, itemCreate(5256));
    root = treeInsert(root, itemCreate(252));

    printf(">> Valores disponíveis: \n");
    treePrint(root);
    printf("\n");

    printf(">> Qual valor deseja remover? \n");
    scanf("%d,", &valor);

    root = treeRemove(root, valor);

    printf("\n>> Remoção concluída: \n");
    treePrint(root);

    treeFree(root);
    return 0;
}
