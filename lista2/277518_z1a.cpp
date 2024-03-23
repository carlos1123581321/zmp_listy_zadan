#include <iostream>
using namespace std;

int pentla(int k){
    int a = 0;
    int b = 1;
    int pom;
    while (k > 1){
        pom = a;
        a = b;
        b = pom + b;
        k = k -1;
    }
    cout << b;
    return b;
}

int main(){
    int t = 0;
    cin >> t;
    cout << pentla(t);
    return 0;
}