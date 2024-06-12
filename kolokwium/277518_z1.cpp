#include <iostream>
using namespace std;

bool czy_pierwsza(int a)
{
    for(int i = 2; i < a; i++)
    {
        if(a % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++)
    {
        if(czy_pierwsza(i))
        {
            if(i + 2 <=n)
            {
                if(czy_pierwsza(i+2))
                {
                cout << "(" << i << ", " << i+2 << ")" << endl ;
                }
            }
        }
    }
    return 0;
}