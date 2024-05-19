#include <iostream>
using namespace std;

//Wektory w R^{3}. klasa ma składać się z pól oznaczających współrzędne wektora
// oraz metod do wyświetlania dodawania, mnożenia przez skalar, obliczania iloczynu skalarnego
//oraz sprawdzania równoległości i prostopadłości wektorów.



class Vector3d {
private:
    float OX, OY, OZ; //Pola
public:
//Ustawienie współrzędnych wektora
    void SetCords(float x, float y, float z){
        OX = x;
        OY = y;
        OZ = z;
    }
//Iloczyn skalarny dwóch wektorów, Zwraca float'a
    float skalar(Vector3d V){
        return (OX * V.OX) + (OY * V.OY) + (OZ * V.OZ);
    }
//Dodawanie dwóch wektorów zwraca nowy wektor aby nie nadpisywać poprzednich w przypadku chęci ich dalszego użycia.
    Vector3d Addition(Vector3d V){
        Vector3d W;
        W.SetCords(OX + V.OX, OY + V.OY, OZ + V.OZ);
        return W;
    }
//Mnożenie dwóch wektorów zwraca nowy wektor aby nie nadpisywać poprzednich w przypadku chęci ich dalszego użycia
    Vector3d Multiplication(float a){
        Vector3d W;
        W.SetCords(OX * a, OY * a, OZ * a);
        return W;
    }
//Zwraca stringa
    string PerP_ParA(Vector3d V){
        if(((OX/V.OX) == (OY/V.OY)) and ((OY/V.OY) == (OZ/V.OZ))){
            return "Rownolegle";
        }
        else if ((OX * V.OX) + (OY * V.OY) + (OZ * V.OZ) == 0){
            return "Prostopadle";
        }
        else{
            return "nie rownolegle i nie prostopadle";
        }
        
    }
//Wyświetla wektor
    void Show(){
        cout << "(" << OX << "," << OY << "," << OZ << ")" << "\n";
        
    }
};



int main(){
Vector3d v;
Vector3d w;
Vector3d s;
int tab[6];
float k;
for(int t = 0; t < 6;t++){
    cin >> k;
    tab[t] = k; 
}
float a;
cin >> a;
v.SetCords(tab[0],tab[1],tab[2]);
w.SetCords(tab[3],tab[4],tab[5]);
s = v.Multiplication(a);
s.Show();
s = v.Addition(w);
s.Show();
cout << v.skalar(w) << "\n";
cout << v.PerP_ParA(w);
 

return 0;
}

//Mogę sobie zrobić klasę iloczyn