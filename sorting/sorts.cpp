//
// Created by edublo on 25/03/20.
//
#include "sorts.h"
template<class T>
void sorting<T>::Bubble_sort() {
    for (int i = 0; i < disorder_vec->size()-1; i++){
        for (int j = 0; j < disorder_vec->size()-i-1; j++){
            if (disorder_vec->at(j) > disorder_vec->at(j+1))
                swap(&disorder_vec->at(j), &disorder_vec->at(j+1));
        }
    }
}




template<class T>
void sorting<T>::Insertion_sort() {
    for(int i = 1 ; i < disorder_vec->size() ; i++){
        T help = disorder_vec->at(i);
        int j = i-1;
        while(j >=0 && disorder_vec->at(j)>help) {
            disorder_vec->at(j+1) = disorder_vec->at(j);
            j = j - 1;

        }
        disorder_vec->at(j+1) = help;
    }
}

template<class T>
void sorting<T>::Selection_sort() {
    for(int i = 0; i < disorder_vec->size() -1 ; i++){
        int min = i;
        for(int j = i + 1 ; j < disorder_vec->size() ; j++){
            if(disorder_vec->at(j) < disorder_vec->at(min)){
                min = j;
            }
        }
        swap(&disorder_vec->at(min), &disorder_vec->at(i));
    }
}

template<class T>
void sorting<T>::Merge_sort(T l , T r) {
    if (l < r)
    {
        T m = l+(r-l)/2;
        Merge_sort(l, m);
        Merge_sort(m+1, r);

        merge(l, m, r);
    }
}

template <class T>
void sorting<T>::Heap_sort(){

    for(int i = disorder_vec->size() / 2 - 1; i >= 0; i--)
        Hippy(disorder_vec->size(), i);

    for(int i = disorder_vec->size() - 1; i >= 0; i--) {
        swap(&disorder_vec->at(0), &disorder_vec->at(i));
        Hippy(i,0);
    }
}

template<class T>
void sorting<T>::Quick_sort(int prim, int ult){

    if(prim < ult)
    {
        int indice = DivideyVenceras(prim, ult);
        Quick_sort(prim, indice - 1);
        Quick_sort(indice + 1, ult);
    }
}

template <class T>
void sorting<T>::Shell_sort(){

    for(int dif = disorder_vec->size()/2; dif > 0; dif /= 2){
        for(int i = dif; i < disorder_vec->size(); i += 1){
            T temp = disorder_vec->at(i);
            int j;
            for(j = i; j >= dif and disorder_vec->at(j-dif) > temp; j -= dif )
                disorder_vec->at(j) = disorder_vec->at(j-dif);
            disorder_vec->at(j) = temp;
        }
    }
}
