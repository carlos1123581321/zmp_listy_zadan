#include<iostream>
using namespace std;

class Zwierz{
    protected:
        string imie;
        string rasa;
    
    public:
        virtual  void sound() = 0;

        Zwierz(string im = "UK", string ra = "UK"){
            imie = im;
            rasa = ra;
        }

        
};
class Kot : public Zwierz{

    public:
    Kot():Zwierz(){

    }
    Kot(string imi, string ras) :Zwierz(imi, ras){

    }
    virtual void sound(){
        cout << "Miau";
    }
    friend ostream &operator <<(ostream &output, Kot &k);
    friend istream &operator >>(istream &input, Kot &k);
};

ostream &operator<<(ostream &output, Kot &k){
    output << "imie kota: "<<k.imie<<" || Rasa kota: "<<k.rasa<<endl << "Dzwiek kota: ";
    /*Zwierz *wsk;
    wsk = &k;
    wsk -> sound();*/
    //k.sound();
    return output;
}

istream &operator>>(istream &input, Kot &k){
    input >> k.imie >> k.rasa;
    return input;
}

class Pies : public Zwierz{

    public:
    Pies():Zwierz(){
        
    }
    Pies(string imi, string ras) :Zwierz(imi, ras){
    
    }
    virtual void sound(){
        cout << "Hau";
    }
    friend ostream &operator <<(ostream &output, Pies &p);
    friend istream &operator >>(istream &input, Pies &p);
};

ostream &operator<<(ostream &output, Pies &p){
    output << "Imie psa: " << p.imie << " || Rasa psa: "<< p.rasa<<endl << "Dzwiek psa: ";
    Zwierz *wsk;
    wsk = &p;
    wsk -> sound();
    return output;
}

istream &operator>>(istream &input, Pies &p){
    input >> p.imie >> p.rasa;
    return input;
}

int main(){
    Kot k;
    Pies p("0","0");
    //cin >> k;
    //cin >> p;    
    cout << k<<endl;
    //cout << p;

    return 0;
}