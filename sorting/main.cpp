#include <iostream>
#include <vector>
#include "sorts.cpp"
using namespace std;
template<class T>
void print_array(vector<T> * v){
    for(auto i : *v){
        cout<<i<<',';
    }
}
/*
template <class T>
void merge(vector<T>* disorder_vec ,T l, T m, T r)
{
    T i, j, k;
    T n1 = m - l + 1;
    T n2 =  r - m;
    auto * L = new vector<T>(), *R = new vector<T>();
    for (i = 0; i < n1; i++)
        L->push_back(disorder_vec->at(l+i));
    for (j = 0; j < n2; j++)
        R->push_back(disorder_vec->at(m + 1 + j));
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L->at(i) <= R->at(j)){
            disorder_vec->at(k) = L->at(i);
            i++;
        }
        else{
            disorder_vec->at(k) = R->at(j);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        disorder_vec->at(k) = L->at(i);
        i++;
        k++;
    }
    while (j < n2)
    {
        disorder_vec->at(k) = R->at(j);
        j++;
        k++;
    }
}
template<class T>
void Merge_sort(vector<T>* disorder_vec,T l , T r) {
    if (l < r)
    {
        T m = l+(r-l)/2;
        Merge_sort(disorder_vec,l, m);
        Merge_sort(disorder_vec,m+1, r);

        merge(disorder_vec,l, m, r);
    }
}

int main(){
    auto*prueba = new vector<int>();
    *prueba = {3,8,5,1,6};
    Merge_sort(prueba,0,4);
    print_array(prueba);


    return 0;
}*/
int main() {
    auto*prueba = new vector<char>();
    *prueba = {'e','o','d','a','f'};
    sorting<char> p(prueba);
    p.Shell_sort();
    print_array(prueba);
    return 0;
}
