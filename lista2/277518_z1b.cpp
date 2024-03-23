#include <iostream>
using namespace std;



int rekurencja(int n){
    if (n < 2){
        return n;
    }
    return rekurencja(n-1) + rekurencja(n-2);
}

int main(){
    int t = 0;
    cin >> t;
    cout << rekurencja(t);
    return 0;
}

