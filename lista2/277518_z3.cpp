#include <iostream>
using namespace std;

int char_to_int(char litera){
    char lit_char = litera;
    int lit_int = lit_char;
    return lit_int;
}

int main(){
    string slowo1;
    string slowo2;
    cin >> slowo1;
    cin >> slowo2;
    int test = 0;
    int dl1 = slowo1.length();
    int dl2 = slowo2.length();
    int czywystopila = 0;
    int wystapienia[26];    
    //pentla która na start ustawi wszystkie wartosci w tabeli na 0
    for(int t = 0; t < 26; t++){
        wystapienia[t] = 0;
    }
    //Jeśli słowa nie mają takiej samej ilosci liter to z pewnoscia nie mogą być anagramami
    if (dl1 == dl2){
        //Ta pentla pobiera kolejne litery slowa1
        for(int i = 0; i < dl1; i++){
            wystapienia[char_to_int(slowo1[i]) - 97]++;


            //Ta pentla sprawdza czy litera o indeksie i pojawia się w slowie 2
            for(int k = 0; k < dl2; k++){
                if(slowo1[i] == slowo2[k]){
                    //Znalezlo ze wystepuje.
                    // co zrobic kiedy jakas litera sie powtarza?
                    wystapienia[char_to_int(slowo1[i]) - 97]--;
                }
                else{
                    cout << "NIE";
                    goto endofcode;
                }
            }
        }
    }
    else{
        cout << "NIE";
    }
    for(int j = 0; j < 26; j++){
        if(wystapienia[j] == 0){
            test = test + 1;
        }
    }
    if(test == 26){
        cout << "TAK";
    }
    endofcode:
    return 0;
}