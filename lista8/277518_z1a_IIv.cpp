#include<iostream>
#include<vector>


template <typename T = int>
class Element
{


    public:
        T what;
        int count;

        Element(T what = 0, int count = 0)
        {
            this->what = what;
            this->count = count;
        }

        void print_element()
        //Metoda ta wypisuje element w postaci "(what, count)"
        {
            std::cout << "(" << what << ", " << count << ")";
        }

        void change_element(int count = 1)
        //Metoda ta pozwala zmienić dany element, zarówno jego wartość jak i to co się w nim znajduje.
        {
            T what;
            std::cin >> what;
            this->what = what;
            this->count = count;
        }

        bool operator ==(Element<T> e)
        {
            if(this->what == e.what && this->count == e.count)
            {
                return true;
            }
            return false;
        }

};

template <typename T = int>
class Multiset : public Element<T>
{
    protected:
        std::vector<Element<T>> mset;
    
    public:

        Multiset(std::vector<Element<T>> mset = {})
        //Konstruktor
        {
            this->mset = mset;    
        }

        void print_multiset()
        //Wypisuje w terminalu multiset na którym wywolana została ta metoda
        {
            std::cout << "{";
            for(int i = 0; i< mset.size() - 1; i++)
            {
                if(mset[i].count != 0)
                {
                    mset[i].print_element();
                    std::cout << ", ";
                } 
            }
            if(mset[mset.size()-1].count != 0)
            {
                mset[mset.size()-1].print_element();
                std::cout << "}";
            }
            else
            {
                std::cout << "}";
            }
        }

        void add_element(Element<T> e)
        //Dodaje element podany jako argument metody do multizbioru na którym została wykonana metoda
        {
            int test =1;
            for(int i = 0; i < mset.size(); i++)
            {
                if(mset[i].what == e.what)
                {
                    mset[i].count += e.count;
                    test = 0;
                    break;
                }
            }
            if(test)
            {
                mset.push_back(e);
            }
        }  

        void substarct_element(Element<T> e)
        //Odejmuje element podany jako argument od multizbioru na którym została wykonana metoda
        {
            for(int i = 0; i < mset.size(); i++)
            {
                if(mset[i].what == e.what)
                {
                    if(mset[i].count >= e.count)
                    {
                        mset[i].count = mset[i].count - e.count;
                    }
                    else
                    {
                        mset.erase(mset.begin() + i);
                    }
                }
            
            }
        }

        Multiset diffrence(Multiset B)
        // Odejmuje od zbioru B zbior na którym została wywołana metoda, modyfikując go w trakcie (trochę poprzestawiane rozwiązanie ale deadline się zbliża)
        {
            for(int i = 0; i < mset.size();i++)
            {
                B.substarct_element(mset[i]);
            }
            return B;
        }
        
        Multiset sum_sets(Multiset B)
        //Dodaje do zbioru bedacego argumentem zbior na ktorym zostala wykonana metoda, modyfikujac go w trakcie
            {
                for(int i = 0; i < mset.size();i++)
                {
                    B.add_element(mset[i]);
                }
                return B;
            }

        bool is_in(Element<T> e)
        //Metoda ta sprawdza czy element (what, count) jest w multizbiorze. UWAGA NIE DBA O WARTOSC COUNT!
        {
            for(int i = 0; i < mset.size();i++)
            {
                if(mset[i].what==e.what)
                {
                    return true;
                }
            }
            return false;
        }

        Multiset intersection(Multiset B)
        //cross jest do poprawienia
        {
            Multiset C,D;
            int test;
            C.mset = this->mset;
            for (int i = 0; i < B.mset.size(); i++)
            {
                if(C.is_in(B.mset[i]))
                {
                    if(B.mset[i].count <= C.mset[i].count)
                    {
                        D.add_element(B.mset[i]);
                    }
                    else
                    {
                        for(int t = 0; t < C.mset.size(); t++)
                        {
                            if(C.mset[t].what == B.mset[i].what)
                            {
                                test = t;
                                break;
                            }
                        }
                        D.add_element(C.mset[t]);
                    }
                }
            }
            
            return D;
            
        }

        bool operator ==(Multiset B)
        {
            if(mset.size() != B.mset.size())
            {
                return false;
            }
            for(int i = 0; i < mset.size(); i++)
            {
                for (int t = 0; t < mset.size(); t++)
                {
                    if(mset[i] == B.mset[t])
                    {
                        goto place;
                    }
                }
                return false;
                place:
            }
            return true;
        }

        //Trzeba jeszcze dopisać zawieranie sie
        bool subset(Multiset B)
        //Metoda ta sprawdza czy multizbior przekazany jako argument jest podzbiorem multizbioru na ktorym wywolana zostala metoda
        {
            Multiset C;
            C.mset = this->mset;
            int test;
            for(int i = 0; i < B.mset.size(); i++)
            {
                test = 0;
                if(not C.is_in(B.mset[i]))
                {
                    return false;
                }
                for(int t = 0; t < C.mset.size(); t++)
                {
                    if(C.mset[t].what == B.mset[i].what && C.mset[t].count >= B.mset[i].count)
                    {
                        break;
                    }
                    test +=1;
                }
                if(test == C.mset )
            }

        }
};


int main()
{

   Multiset M1, M2, B, B1,D, D1, E, E1, F, F1;
   Element e;
   int n, k;
   std::cin >> n;
   std::cin >> k;


    for(int i = 0; i < n; i++)
    {
        e.change_element();
        M1.add_element(e);
    }
    for(int i = 0; i < k; i++)
    {
        e.change_element();
        M2.add_element(e);
    }
    M1.print_multiset();
    std::cout<<std::endl;
    M2.print_multiset();
    std::cout<<std::endl;
    B = M1;
    B1 = M2;
    E = M1;
    E1 = M2;
    F = M1;
    F1 = M2;
    D = M1.sum_sets(M2);
    D.print_multiset();
    std::cout<<std::endl;
    D1 = B.intersection(B);
    std::cout<<std::endl;
    (E.diffrence(E1).print_multiset());
    std::cout<<std::endl;
    if(F1.subset(F))
    {
        std::cout<<"Podzbior";
    }
    else
    {
        std::cout<<"Nie podzbior"
    }
    

    return 0;
}