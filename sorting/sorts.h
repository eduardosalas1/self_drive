//
// Created by edublo on 25/03/20.
//
#ifndef SORTING_SORTS_H
#define SORTING_SORTS_H
#include <iostream>
#include<vector>
using namespace std;

template<class T>
class sorting{
private:
    vector<T>* disorder_vec = new vector<T>();
    void swap(T *x , T *y){
        T temp = *x;
        *x = *y;
        *y = temp;
    }
    void merge(T l, T m, T r)
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
    void Hippy(int n, int raiz){

        T mayor = raiz;
        T izq = 2*raiz + 1;
        T der = 2*raiz + 2;

        if(izq < n and disorder_vec->at(izq) > disorder_vec->at(mayor))
            mayor = izq;
        if(der < n and disorder_vec->at(der) > disorder_vec->at(mayor))
            mayor =  der;
        if(mayor != raiz)
        {
            swap(&disorder_vec->at(raiz), &disorder_vec->at(mayor));
            Hippy(n, mayor);
        }
    }
    int DivideyVenceras(int prim, int ult){

        int pivote = disorder_vec->at(ult);
        int i = prim - 1;

        for(int j = prim; j <= ult - 1; j++){

            if(disorder_vec->at(j) < pivote){
                i++;
                swap(&disorder_vec->at(i), &disorder_vec->at(j));
            }
        }

        swap(&disorder_vec->at(i+1), &disorder_vec->at(ult));

        return (i+1);
    }
public:
    sorting(vector<T>* disorder_vec){
        this->disorder_vec = disorder_vec;
    }

    void Insertion_sort();
    void Selection_sort();
    void Bubble_sort();
    void Merge_sort(T l , T r);
    void Heap_sort();
    void Quick_sort(int prim, int ult);
    void Shell_sort();



};

#endif //SORTING_SORTS_H
