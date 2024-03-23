#include <iostream>
using namespace std;

int* tabela(){
    static int tab[1001];
    int k = 0;
    for(int i = 0; i < 1001; i++){
        cin >> k;
        tab[i] = k;
    }
    return tab;
}

int main(){
    int* tablica = tabela(); 
    int check = 0;
    for(int t = 0; t < 1000; t++){ 
        if(tablica[t] == tablica[1000]){
            check = 1;
            break;
        }
    }
    if(check == 1){
        cout << "TAK";
    }
    else{
        cout << "NIE";
    }
    return 0;
}
