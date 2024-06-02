/*
Dla drzewa binarnego przechowującego w każdym węźle liczbę całkowitą
przeciąż operatory arytmetyczne: unarny -, binarne +, - oraz operator []. ”Dodawanie”
drzew powinno odbyć się po węzłach, tzn. wartości w korzeniach dodajemy do siebie i wynik stanowi wartość w korzeniu drzewa wynikowego, suma wartości w lewych potomkach
jest wartością w lewym potomku drzewa wynikowego, itd.1
. Dla poprawnego działania
operatora [] zaproponuj odpowiednie kodowanie węzłów drzewa za pomocą liczb naturalnych2
.Dla testów przyjmijmy, że na standardowym wejściu przyjdą liczby naturalne n i k
oznaczająca wielkość nadchodzących drzew, a następnie n + k liczb naturalnych, które
powinny zostać rozsądnie3 umieszczone w drzewach. Następnie program wyświetli drzewa
-t1, t1+t2, t2-t1 oraz wypisze kolejne wartości drzewa t1 za pomocą [].
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
    Tree *left;
    Tree *right;
    int info;

    Tree(int info) : left(NULL), right(NULL), info(info) {}

    Tree(int info, Tree *left, Tree *right) : left(left), right(right), info(info) {}

    Tree(Tree* t) {
        this->info = t->info;
        if (t->left) this->left = new Tree(t->left);
        if (t->right) this->right = new Tree(t->right);
    }

    Tree(int info[], int n) {
        sort(info, info + n);
        this->info = info[n / 2];
        this->left = NULL;
        this->right = NULL;

        for (int i = 0; i < n; i++) {
            if (i == n / 2) continue;
            this->insert(info[i]);
        }
    }

    Tree *insert(int info) {
        if (info < this->info) {
            if (this->left)
                this->left->insert(info);
            else
                this->left = new Tree(info);
        } else {
            if (this->right)
                this->right->insert(info);
            else
                this->right = new Tree(info);
        }
        return this;
    }

    Tree* operator-() {
        this->info = -this->info;
        if (this->left) -(*this->left);
        if (this->right) -(*this->right);
        return this;
    }

    Tree* operator+(Tree *t) {
        this->info += t->info;

        if (this->left && t->left) *this->left + t->left;
        else if (t->left) this->left = new Tree(*t->left);

        if (this->right && t->right) *this->right + t->right;
        else if (t->right) this->right = new Tree(*t->right);

        return this;
    }

    Tree* operator-(Tree *t) {
        return *this + -*t;
    }

    ~Tree() {
        delete this->left;
        delete this->right;
    }


    int operator[](int pos) {
        int* curr_pos = new int(0);
        return this->get(pos, curr_pos);
    }

    int get(int pos, int* curr_pos) {
        if (this->left) {
            int left = this->left->get(pos, curr_pos);
            if (left != -1) return left;
        }

        if (*curr_pos == pos) return this->info;
        (*curr_pos)++;

        if (this->right) {
            int right = this->right->get(pos, curr_pos);
            if (right != -1) return right;
        }

        return -1;
    }



    friend ostream &operator<<(ostream &os, Tree *t);
};

ostream &operator<<(ostream &os, Tree *t) {
    os << t->info << " ";
    if (t->left) os << t->left;
    if (t->right) os << t->right;
    return os;
}

int main() {
    Tree *t1 = new Tree(3);
    t1->insert(5)->insert(2);

    Tree *t2 = new Tree(3);
    t2->insert(5)->insert(2);

    int info[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tree *t3 = new Tree(info, 10);



    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;
    cout << "t3: " << t3 << endl;

    cout << "t1-t2: " << *t1 - t2 << endl;
    cout << "t1+t2: " << *t1 + t2 << endl;
    cout << "t1: " << t1 << endl;

    cout << "t3: " << t3 << endl;
    cout << "t3[0]: " << (*t3)[0] << endl;
    cout << "t3[5]: " << (*t3)[5] << endl;

    delete t1;
    delete t2;
    delete t3;

    return 0;
}
