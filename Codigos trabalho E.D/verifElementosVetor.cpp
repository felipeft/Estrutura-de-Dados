#include <iostream>

bool verificarOrdem(int n, int v[]){
    for(int i=1;i<n;i++){
        if(v[i-1] > v[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    std::cin >> t;
    int v[t];
    for(int i=0;i<t;i++){
        std::cin >> v[i];
    }
    if(verificarOrdem(t,v) == true){
        std::cout << "o vetor esta em ordem crescente" << std::endl;
    }
    else{
        std::cout << "o vetor nao esta em ordem crescente" << std::endl;
    }
}