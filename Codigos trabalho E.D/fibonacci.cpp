#include <iostream>

int fibonacci(int fn){
    int f1=0,f2=1,sum;
    for(int i=3;i<=fn;i++){   // O(n-3) a complexidade é linear pois o valor de f(n) = n-3 cresce linearmente em função do tamanho da entrada n
        sum = f1+f2;
        f1 = f2;
        f2 = sum;
    }
    return f2;
}

int main(){
    int fn;
    std::cin >> fn;
    std::cout << fibonacci(fn) << std::endl;
}