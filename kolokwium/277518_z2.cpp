#include <iostream>
using namespace std;

class Konto
{
    protected:
        string imie;
        string nazwisko;
        float stan_konta;
    public:

    Konto(string x="jakies imie", string y = "jakies nazwisko", float z = 0)
    {
        imie = x;
        nazwisko = y;
        stan_konta = z;
    }

    void wplata(float x)
    {
        stan_konta = stan_konta + x;
    }

    void wyplata(float x)
    {
        stan_konta = stan_konta - x;
    }

    void sprawdz()
    {
        cout << stan_konta;
    }
};

class Premium : public Konto
{
    private:
    
    int bonus;

    public:
    Premium():Konto(){

    }
    Premium(string x, string y, float z =0, int b = 0):Konto(x, y, z){
        bonus = b;
    }

    void wplata(float x)
    {
        stan_konta += x;
        bonus += 1;
    }

    void wyplata(float x)
    {
        stan_konta += x;
        bonus += 1;
    }

    void sprawdz()
    {
        cout << "Szanowny " << imie << " " << nazwisko << ", Twoj balans to " << stan_konta << " i bonus to " << bonus << endl;
    }
};

class Sub_Premium : public Konto
{
    private:
    
    public:
    Sub_Premium():Konto(){

    }
    Sub_Premium(string x, string y, float z =0) :Konto(x, y, z){

    }
        void wplata(float x)
    {
        stan_konta += x;
    }

    void wyplata(float x)
    {
        stan_konta += x;
    }

    void sprawdz()
    {
        cout << "Czesc " << imie << " " << nazwisko << ", Twoj balans to " << stan_konta;
    }
};



int main(){

    string s1, s2;
    float w1, w2, w3;
    cin >> s1;
    cin >> s2;
    cin >> w1;
    cin >> w2;
    cin >> w3;
    Premium op(s1,s2);
    Sub_Premium os(s1, s2);
    op.wplata(w1);
    os.wplata(w1);
    op.wplata(w2);
    os.wplata(w2);
    op.wyplata(w3);
    os.wyplata(w3);

    op.sprawdz();
    os.sprawdz();
    return 0;
}