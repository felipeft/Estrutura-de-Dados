#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <stdexcept>

template <typename Item>
class List{

private:
    Node<Item> *inicio;
    int tam;

public:
List(){
    inicio = new Node<Item>;
    inicio->prox = inicio;
    inicio->ant = inicio;
    tam = 0;
    return;
}

List(const List<Item>& lst){
    tam = lst.tam;
    inicio = lst.inicio;
}

~List(){
    delete inicio;
    tam = 0;
}

bool empty() const{
    return inicio->prox == inicio;
}

size_t size() const{
    return tam;
}

void clear(){
    Node<Item> *aux = inicio->ant;
    while(aux->ant != inicio->ant){
        inicio->ant = aux->ant;
        aux->ant->prox = inicio;
        aux = aux->ant;
        tam--;
    }
}

Item front(){
    return inicio->prox->data;
}

Item back(){
    return inicio->ant->data;
}

void push_front(const Item& data){
    Node<Item> *newNode = new Node<Item>;
    if(newNode){
        //caso a lista esteja vazia
        if(tam == 0){
            inicio->prox = newNode;
            newNode->data = data;
            newNode->prox = inicio;
            inicio->ant = newNode;
            newNode->ant = inicio;
            tam++;
        }else{
            Node<Item> *aux = inicio->prox;   //aux recebe o proximo da lista (apos o inicio)
            newNode->data = data;       
            inicio->prox = newNode;     
            newNode->prox = aux;
            tam++;
        }
    }else{
        throw std::underflow_error("nao foi possivel alocar memoria.");
    }
}

void push_back(const Item& data){
    Node<Item> *newNode = new Node<Item>;
    if(newNode){
        inicio->ant->prox = newNode;
        newNode->data = data;
        newNode->prox = inicio;
        newNode->ant = inicio->ant;
        inicio->ant = newNode;
        tam++;
        
    }else{
        throw std::underflow_error("nao foi possivel alocar memoria.");
    }
}

void pop_front(){
    if(!empty()){
        Node<Item> *aux = inicio->prox; //recebe o primeiro da lista
        inicio->prox = inicio->prox->prox; //segundo se torna o primeiro
        inicio->prox->ant = inicio->ant; //primeiro(antigo segundo) passa a apontar para o fim
        delete aux;
        tam--;
    }else{
        throw std::underflow_error("a lista esta vazia!");
    }
}

void pop_back(){
    if(!empty()){
        Node<Item> *aux = inicio->ant;   //aux recebe o ultimo da lista
        inicio->ant = aux->ant;     //ultimo se torna o penultimo (resumindo)
        aux->ant->prox = inicio;      //penultimo passa a apontar pra cabeça
        delete aux;
        tam--;
    }
    else{
        throw std::underflow_error("a lista esta vazia!");
    }
}

void insertAt(const Item& data, int index){
    if(index > tam){
        throw std::underflow_error("nao e possivel adicionar um elemento a esta posicao.");
    }else{
        Node<Item> *newNode = new Node<Item>;      //node a ser adicionado
        Node<Item> *aux = inicio->prox;                 //node para achar o elemento da posiçao
        for(int i=0; i<index; i++){
            aux = aux->prox;
        }
        newNode->ant = aux->ant;
        aux->ant->prox = newNode;
        newNode->data = data;
        tam++;
        newNode->prox = aux;
        aux->ant = newNode;
    }
}

void removeAt(int index){
    if(index > tam-1){
        throw std::underflow_error("nao ha nada nessa posicao, nao e possivel remover.");
    }else{
            Node<Item> *aux = inicio->prox;
            int i=0;
            while(i < index){
                aux = aux->prox;
                i++;
            }
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            delete aux;
            aux = nullptr;
            tam--;
    }
}

void removeAll(const Item& data){
    Node<Item> *aux = inicio->prox;
    int i=0;                        //i serve apenas para auxiliar no laço while
    int oc=0;           //oc armazena a quantidade de ocorrencias que "data" aparece na lista
    int copy_tam = tam;
    while(i<copy_tam){ 
        if(aux->data == data){
            removeAt(i-oc);          //caso o node seja igual a data, esse node é removido alterando toda a lista
            oc++;
        }  
        aux = aux->prox;
        i++;   
    }
}

void swap(List& lst){
    Item vec[lst.tam];        //vetor auxiliar para armazenar todos os valores de lst
    Node<Item> *aux = lst.inicio->prox;
    for(int j=0; j<lst.tam; j++){     //esse laço apenas armazena o conteudo de lst no vetor
        vec[j] = aux->data;
        aux = aux->prox;
    }
    
    int remove1 = tam;           //esses int servem apenas para armazenar o tamanho das listas
    int remove2 = lst.tam;

    Node<Item> *aux2 = inicio->prox;
    for(int i=0; i<remove1; i++){   //nesse laço o conteudo da primeira lista é armazenado na segunda
        lst.push_back(aux2->data);
        aux2 = aux2->prox;
    }

    for(int i=0; i<remove2; i++){
        lst.pop_front();               //ja nesse a segunda lista se torna igual a primeira
    }

    for(int i=0; i<remove2; i++){    //nesse laço o conteudo do vetor (segunda lista) é armazenado na primeira lista
        push_back(vec[i]);
    }

    for(int i=0; i<remove1; i++){   //aqui a primeira lista se torna igual a segunda lista realizando assim a troca
        pop_front();
    }
}

void concat(List& lst){
    int t = lst.tam;
    Node<Item> *aux = lst.inicio->prox;
    for(int i=0; i<t; i++){ 
        push_back(aux->data);
        aux = aux->prox;
    }
    lst.clear();
}

List *copy(){
    List<Item> lst;              //lst é a copia
    Node<Item> *aux = inicio->prox;
    while(aux != inicio){
        lst.push_back(aux->data);
        aux = aux->prox;
    }
    return &lst;
}

void append(Item vec[], int n){
   for (int i = 1; i <=n; i++)
        push_back(vec[i]);                    // usamos a função push_back para add os elementos do vetor na lista copiada.
    std::cout << "Array copiado." << std::endl;

    /*for(int i=0; i<n; i++){
        push_back(vec[i]);
    }*/
}

bool equals(const List& lst) const{
 if(size() != lst.size())      // Aqui, verificamos se os tamanhos são iguais;
        return false;    
    
    Node<Item> *auxiliar1 = inicio->prox;
    Node<Item> *auxiliar2 = (lst.inicio)->prox;

    while (auxiliar1 != inicio && auxiliar2 != lst.inicio) {
        
        if (auxiliar1->data != auxiliar2->data) // aqui verificamos se os valores são diferentes;
            return false;
        
        auxiliar1 = auxiliar1->prox;           // aqui percorremos todas as posições das duas listas.  
        auxiliar2 = auxiliar2->prox;
    }
    return true;
}

void reverse() {
Node<Item> *auxiliar = inicio->ant; //em vez de usarmos o (inicio proximo) usamos o (inicio anterior).
  while (auxiliar != inicio) {
        std::cout << auxiliar->data << " ";
        auxiliar = auxiliar->ant; 
    }
    std::cout << std::endl;
    /*Item vec[tam];
    int i=0;
    while (auxiliar != inicio) {
        vec[i] = auxiliar->data;
        auxiliar = auxiliar->ant; 
        i++;
    }
    for(int j=0; j<i; j++){
        push_back(vec[j]);
        pop_front();
    }*/
}

void merge(List& lst) {
    List *lst2 = this;
	Node<Item> *aux1 = inicio->prox;
	Node<Item> *aux2 = lst.inicio->prox;
	int cont = 0;
	if(empty() && !lst.empty()){
		//lst2 = lst.copy(); //se 1ª vazia copia a segunda para ela;
	}
	else if(!empty() && !lst.empty()){
		while(aux1 != inicio || aux2 != lst.inicio){
			if(cont%2==0  && aux1 != inicio && aux2 != lst.inicio){
		//apos os apresa add o elemento da aux2;
		// e incrementa		
				this->insertAt(aux2->data,cont);
				aux2 = aux2->prox;
				aux1 = aux1->prox;
				
			}else if(aux1 == inicio && aux2 != lst.inicio){
				//se acabou os do aux1 continue usando os do aux2;
				this->push_back(aux2->data);
				aux2 = aux2->prox;
			}else aux1 = aux1->prox;
			cont++;
		}
	}lst.clear();
	std::cout<<"Listas misturadas com sucesso" << "\n";
}

friend std::ostream& operator<<(std::ostream& out, const List& lst){
    if(lst.tam == 0){
        throw std::underflow_error("nao e possivel imprimir a lista, pois a mesma nao existe :(");
    }else{
        Node<Item> *perc = lst.inicio->prox;
        while(perc != lst.inicio){
            out << perc->data << " ";
            perc = perc->prox;
        }
        return out;
    }
}

Item& operator[](int index){
    Node<Item> *perc = inicio->prox;
    for(int i=0; i<index; i++){
        perc = perc->prox;
    }
    return perc->data;
}

List& operator=(const Item& lst){
    if(this != &lst){
        ~List();
        List(lst);
    }
    return *this;
}

};

#endif