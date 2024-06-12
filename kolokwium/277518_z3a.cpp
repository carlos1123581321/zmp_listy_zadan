#include <iostream>
#include <cmath>
using namespace std;

class Wielomian
{   private:
        int stopien;
        int *wspolczynniki;
    public:
    float argument;
        Wielomian(int st = 0, float arg= 1){
            stopien = st;
            argument = arg;
            wspolczynniki = new int [st + 1];
        }
        void wypelnij()
        {
            int t;
            cin >> stopien;
            for (int i = 0; i < (stopien + 1); i++)
            {
                cin >> t;
                wspolczynniki[i] = t;
            }
        }
        float ewaluacja(){
            int eval;
            int cos;
            for (int i = 0; i < stopien + 1; i++)
            {
                cos = wspolczynniki[i]*pow(argument, i);
                eval += cos;
            }
            return eval;
            
        }

        Wielomian operator+(Wielomian a)
        {
            Wielomian b;
            if(a.stopien >= b.stopien)
            {
                for (int i = 0; i < b.stopien + 1; i++)
                {
                    a.wspolczynniki[i] += b.wspolczynniki[i];
                }
                return a;
                
            }
            else
            {
               for (int i = 0; i < a.stopien + 1; i++)
                {
                    b.wspolczynniki[i] += a.wspolczynniki[i];
                }  
                return b;
            }

        }
        Wielomian operator-(Wielomian a)
        {
            Wielomian b;
            if(a.stopien >= b.stopien)
            {
                for (int i = 0; i < b.stopien + 1; i++)
                {
                    a.wspolczynniki[i] -= b.wspolczynniki[i];
                }
                return a;
                
            }
            else
            {
               for (int i = 0; i < a.stopien + 1; i++)
                {
                    b.wspolczynniki[i] -= a.wspolczynniki[i];
                }  
                return b;
            }
        }
        Wielomian pochodna()
        //mienia wielomian na jego pochodną
        {
            for(int i = 2; i >stopien+1; i++)
            {
                wspolczynniki[i-1] = wspolczynniki[i]*i;
            }
            wspolczynniki[0] = 0;
            wspolczynniki[stopien +1] = 0;
            
            int wspn[stopien];
            for (int i = 0; i < stopien; i++)
            {
                wspn[i] = wspolczynniki[i];
            }
            wspolczynniki = wspn;
            
        }
        void show()
        {
            for(int t = 0; t < stopien +1; t++)
            if(t != stopien){
            {
                cout << wspolczynniki[t] << "x^" << t << " + ";
            }}
            else{
                cout << wspolczynniki[t] << "x^" << t;
            }
        }
};

int main()
{
    Wielomian a,b,c, d,e;
    float cos;
    a.wypelnij();
    b.wypelnij();
    cin >> cos;
    a.argument = cos;
    b.argument = cos;
    e = a;
    b.show();
    cout << endl;
    a.show();
    c = a + b;
    c.show();
    cout << endl;
    d = a-b;
    d.show();
    (a.pochodna()).show();
    cout << e.ewaluacja() << endl;
    return 0;
}