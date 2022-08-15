#ifndef NODE_H
#define NODE_H

template <typename Item>

//um node de uma listsa dupla deve ser composto de 3 elementos
//1 elemento para armazenar o dado principal
//1 elemento para apontar para o proximo
//e 1 elemento parar apontar para o anterior

struct Node{
    Item data;   
    Node *ant;
    Node *prox;
};

#endif