#include "lista.h"
#include <stdlib.h>
#include "node.h"

struct Lista_ {
    Node *inicio;
    Node *fim;
    int quantidade;
};

Lista* cria_lista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if(lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->quantidade = 0;
    }
    return lista;


}

int inserir_inicio(Lista *lista, int valor){
    Node *node = cria_node(valor);
    if(lista->quantidade == 0){
        lista->fim = node;

    }else{
        set_next(node, lista->inicio);

    }
    lista->inicio = node;
    lista->quantidade++;
    return TRUE;

}

int inserir_fim(Lista *lista, int valor){
    Node *node = cria_node(valor);
    if(lista->quantidade == 0){
        lista->inicio = node;

    }else{
        set_next(lista->fim, node);

    }
     lista->fim = node;
     lista->quantidade++;
    return TRUE;

}

int remove_inicio(Lista *lista, int *valor){
    if(lista->quantidade > 0) {
    *valor = get_d(lista->inicio);
    lista->inicio = get_next(lista->inicio);
    lista->quantidade--;
    return TRUE;
    }
    return FALSE;
}


int remove_fim(Lista *lista, int *valor){
    Node *removed;
if(lista->quantidade > 0){
    if(lista->quantidade == 1){
        *valor = get_d(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;

    } else {
        Node *cursor = lista->inicio;
        int i;
        for(i = 1; i < (lista->quantidade)-1; i++) {
            cursor = get_next(cursor);
        }
        removed = get_next(cursor);
        *valor = get_d(removed);
        set_next(cursor, NULL);
        lista->fim = cursor;

    }
    lista->quantidade--;
    free(removed);
    return TRUE;
}
    return FALSE;
}

int get_quantidade(Lista *lista) {
   return lista->quantidade;
}
Node* get_inicio(Lista *lista) {
    return lista->inicio;
}