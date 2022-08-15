#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "List.h"

using namespace std;

int main() {

	vector<List<int>*> listas;
		cout << "                      |-----------------Bem vindo-------------------|" << endl;
        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
        cout << "|  00) Destruir/Sair            | 01) criar lista                                                  |" << endl;
		cout << "|__________________________________________________________________________________________________|" << endl;
	
	int lstqtd = -1;
	while(true) {
		cout << "escolha uma opçao do menu acima: ";
		int comando;
		cin >> comando;
		std::stringstream ss;
        ss << comando;
		vector<string> tokens;
		string buffer;

        cout << "$" << ss.str() << endl;

		while(ss >> buffer) 
			tokens.push_back(buffer);

		// sair
		if(tokens[0] == "0") {
			for(unsigned i = 0; i < listas.size(); i++)
				delete listas[i];
			listas.clear();
			break;
		}
		// criar lista
		else if(tokens[0] == "1") {
			List<int> *lst = new List<int>;
			listas.push_back(lst);
			lstqtd++;
			cout << "lista de numero: " << lstqtd << endl;
			cout << "                      |-----------------opcoes disponiveis-------------------|" << endl;
			cout << "|--------------------------------------------------------------------------------------------------|" << endl;
        	cout << "|  00) Destruir/Sair            | 01) criar lista               | 02) chamar menu                  |" << endl;
			cout << "|__________________________________________________________________________________________________|" << endl;
			cout << "|  03) Funcao push_front        | 04) Funcao push_back          | 05) Funcao pop_front             |" << endl;
        	cout << "|  06) Funcao pop_back          | 07) Funcao insertAt           | 08) Funcao removeAt              |" << endl;
        	cout << "|  09) Funcao removeAll         | 10) Funcao reverse            | 11) Funcao empty                 |" << endl;
        	cout << "|  12) Funcao size              | 13) Funcao clear              | 14) Funcao front                 |" << endl;
        	cout << "|  15) Funcao back              | 16) Funcao ver lista          | 17) Funcao append                |" << endl;
			cout << "|__________________________________________________________________________________________________|" << endl;
			if(lstqtd > 0){
				cout << "|   18) Funcao merge            | 19) Funcao swap               | 20) Funcao concat                |" << endl;
        		cout << "|   21) Funcao copy             | 22) Funcao equals                                                |" << endl;
				cout << "|--------------------------------------------------------------------------------------------------|" << endl;
			}
		}

		//visualizar menu
		else if(tokens[0] == "2"){
			cout << "                      |-----------------opcoes disponiveis-------------------|" << endl;
			cout << "|--------------------------------------------------------------------------------------------------|" << endl;
        	cout << "|  00) Destruir/Sair            | 01) criar lista               | 02) chamar menu                  |" << endl;
			cout << "|__________________________________________________________________________________________________|" << endl;
			cout << "|  03) Funcao push_front        | 04) Funcao push_back          | 05) Funcao pop_front             |" << endl;
        	cout << "|  06) Funcao pop_back          | 07) Funcao insertAt           | 08) Funcao removeAt              |" << endl;
        	cout << "|  09) Funcao removeAll         | 10) Funcao reverse            | 11) Funcao empty                 |" << endl;
        	cout << "|  12) Funcao size              | 13) Funcao clear              | 14) Funcao front                 |" << endl;
        	cout << "|  15) Funcao back              | 16) Funcao ver lista          | 17) Funcao append                |" << endl;
			cout << "|__________________________________________________________________________________________________|" << endl;
			if(lstqtd > 0){
				cout << "|   18) Funcao merge            | 19) Funcao swap               | 20) Funcao concat                |" << endl;
        		cout << "|   21) Funcao copy             | 22) Funcao equals                                                |" << endl;
				cout << "|--------------------------------------------------------------------------------------------------|" << endl;
			}
		}
		
		//push_front: Essa função vai adicionar um Item ao início da lista que está sendo criada. 
		else if(tokens[0] == "3") {
			int valor;
			cout << "Insira o valor a ser adicionado: ";
			cin >> valor;
			listas[lstqtd]->push_front(valor);
		}

		//push_back: Essa função vai adicionar um Item no final da lista que está sendo criada.
		else if(tokens[0] == "4") {
			int valor;
			cout << "Insira o valor a ser adicionado: ";
			cin >> valor;
			listas[lstqtd]->push_back(valor);
		}

		//pop_front: A função vai remover o primeiro elemento da lista. Caso a lista esteja vazia, a função retorna um aviso.
		else if(tokens[0] == "5") {
			listas[lstqtd]->pop_front();
		}

		//pop_back: A função vai remover o ultimo elemento da lista. Caso a lista esteja vazia, a função retorna um aviso.
		else if(tokens[0] == "6") {
			listas[lstqtd]->pop_back();
		}
		
		//insertAt: Insere um novo no com valor key apos o k-esimo no da lista.
		else if(tokens[0] == "7") {
			int valor;
            cout << "Insira o valor a ser adicionado na posicao index: ";
            cin >> valor;
            int index;
            cout << "Qual a posicao do index escolhida? index: ";
            cin >> index;
            listas[lstqtd]->insertAt(valor, index);
            cout << "\nValor adicionado!" << endl;
		}
		
		//Funcao removeAt: Remove o elemento na posiçao index da lista e retorna o seu valor. Primeiro é informado a posição que contém o elemento e depois esse elemento, 
		//nessa posição, é eliminado.
		else if(tokens[0] == "8") {
			int k;
            cout << "Insira a posicao a ser removida: ";
            cin >> k;
            listas[lstqtd]->removeAt(k);
            cout << "\nO valor na posição " << k << " foi removido!" << endl;
		}
		
		//removeAll: Remove da lista todas as ocorrencias do elemento data passado como parametro. É inserido um valor e a função removerá esse 
		//valor em qualquer posição que ele estiver.
		else if(tokens[0] == "9") {
			int key;
            cout << "Insira o valor a ser removido de toda a lista: ";
            cin >> key;
            listas[lstqtd]->removeAll(key);
		}

		//reverse: Imprime os elementos da lista em ordem reversa. Quando a função é chamada, ela inverte a lista e imprime a lsita invertida.
		else if(tokens[0] == "10") {
            listas[lstqtd]->reverse();
		}
		
		//empty:  Retorna true se a lista estiver vazia e false caso contrário.
		else if(tokens[0] == "11") {
			cout << "A lista esta vazia? " << endl;
            if(listas[lstqtd]->empty())
                    cout << "\nResposta: A lista esta vazia" << endl;
                else
                    cout << "\nResposta: A lista nao esta vazia" << endl;
		}

		//size: Retorna o numero de nos da lista. 
		else if(tokens[0] == "12") {
			cout << "A quantidade de nos na lista e: ";
            cout << listas[lstqtd]->size() << endl;
		}

		//clear: Remove todos os elementos da lista e deixa apenas o no cabeca.
		else if(tokens[0] == "13") {
			listas[lstqtd]->clear();
            cout << "\nA lista foi esvaziada! " << endl;
		}
		
		//front: Retorna uma referencia para o primeiro elemento na lista.
		else if(tokens[0] == "14") {
			cout << listas[lstqtd]->front() << endl;
		}
		
		//back: Retorna uma referencia para o ´ultimo elemento na lista.
		else if(tokens[0] == "15") {
			cout << listas[lstqtd]->back() << endl;
		}
		
		//ver lista
		else if(tokens[0] == "16") {
			cout << "digite a numeração da lista desejada para visualiza-la: ";
			int l;
			cin >> l;
			if(l > lstqtd){
				throw std::underflow_error("nao existe uma lista nessa posicao :(");
			}else{
				cout << *listas[l] << endl;
			}
		}

		//append: Copia os elementos do array v para a lista. O array arr tem n elementos. Todos os elementos anteriores da lista sao
		//mantidos e os elementos do array v devem ser adicionados apos os elementos originais. 
		else if(tokens[0] == "17") {
			cout << "Digite o numero da lista que você deseja acrescentar elementos: " << endl;
			int num1;
			cin >> num1;
			cout << "Quantos elementos serão acrescentados: " << endl;
			int quantidade;
			cin >> quantidade;
			int v[quantidade];
			for(int i = 0 ; i < quantidade; i++) {
				cout << "\nDigite o novo elemento de numero " << i+1 << ":" << endl;
				cin >> v[i];
			} 
			listas[num1]->append(v, quantidade);
		}

		//merge: Recebe uma List como parametro e constroi uma nova lista com a intercalacao dos nos da lista original com os nos da lista
                //passada por parametro. Ao final desta operacao, a segund a lista escolhida deve ficar vazia.
		else if(tokens[0] == "18") {
				int num1;
				cout << "digite a numeracao da lista que sera alterada: ";
				cin >> num1;
				int num2;
				cout << "digite a numeracao da lista que sera utilizada: "; 
				cin >> num2;
                cout << "A lista " << *listas[num1] << " sera misturada com a lista " << *listas[num2] << endl;
                listas[num1]->merge(*listas[num2]);
		}
		
		//swap: Troca o conteudo da lista com o conteudo da outra lista escolhida. Os elementos nesta lista sao aqueles que estavam na segunda lista antes da
				//chamada e os elementos da segunda lista saao aqueles que estavam nesta lista.
		else if(tokens[0] == "19") {
			cout << "digite a numeração das listas que deseja trocar: ";
			int num1, num2;
			cin >> num1 >> num2;
			listas[num1]->swap(*listas[num2]);
		}
		
		//concat: Concatena a lista atual com a lista lst passada por parametro. Apos essa operacao ser executada, lst sera uma lista vazia, ou seja, o
                //unico no de lst sera o no cabeca. 
		else if(tokens[0] == "20") {
			int num1, num2;
			cout<<"Digite duas listas para concatenar \n";
				cout<<"\tnum1: ";
				cin >> num1;
				cout<<"\tnum2: ";
				cin >> num2;

			listas[num1]->concat(*listas[num2]);	
		}
		
		//copy: Retorna um ponteiro para uma copia desta lista.  A copia desta lista deve ser umaoutra lista, que deve ser criada dinamicamente dentro da funcao
		else if(tokens[0] == "21") {
			cout << "digite a numeracao da lista que deseja copiar: ";
			int num1;
			cin >> num1;
			cout << "digite a numeracao da lista que irá receber a copia: ";
			int num2;
			cin >> num2;
			listas[num2] = listas[num1]->copy();
			cout << "a lista de numeracao: " << num2 << " eh uma copia da lista " << num1 << endl;
		}
		
		/* equals: Determina se a lista passada por parametro e igual a
                lista em questao. Duas listas sao iguais se elas possuem o mesmo tamanho e o valor
                do k-esimo elemento da primeira lista e igual ao k-esimo elemento da segunda lista */
		else if(tokens[0] == "22") {
			cout << "digite a numeracao das listas que voce deseja comparar " << endl;
			int num1;
			cout << "\nL1: " << endl;
			cin >> num1;
			int num2;
			cout <<"\nL2: " << endl;
			cin >> num2;

			 if (listas[num2]->equals(*listas[num1])){
                    cout << "\nSao iguais!" << endl;
                }else{
                    cout << "\nSao diferentes!" << endl;
                }
		}

		//entrada invalida
		else{
			cout << "Entrada invalida, Informe novamente!" << endl;
		}
    }
}