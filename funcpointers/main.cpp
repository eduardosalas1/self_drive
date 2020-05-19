#include <iostream>
using namespace std;

template <typename T>
void print_array(T &array){
    for(auto i : array){
        cout<<i<<endl;
    }
}


void * _bubblesort_(
        void * _array_,
        void (*_puntero_) (void *, int _i, int _k),
        int _tam_){

    for (int i = 0; i < _tam_ ; i ++)
        for(int k = 0; k < _tam_-1-i; k++)
            _puntero_(_array_,k,k+1);
    return _array_;
}

void  _b_int_ (void * _vector_, int _i,int _k){

    int*vector = (int*)_vector_;
    int temp = 0;
    if(vector[_i] > vector[_k]){
        temp = vector[_i];
        vector[_i] = vector[_k];
        vector[_k] = temp;
    }

}


void  _b_float_ (void * _vector_, int _i,int _k){
    float*vector = (float*)_vector_;
    float temp;
    if(vector[_i] > vector[_k]){
        temp = vector[_i];
        vector[_i] = vector[_k];
        vector[_k] = temp;
    }
}


void  _b_double_ (void * _vector_, int _i,int _k){
    double* vector = (double*)_vector_;
    double temp ;
    if(vector[_i] > vector[_k]){
        temp = vector[_i];
        vector[_i] = vector[_k];
        vector[_k] = temp;
    }
}


void  _b_char_ (void * _vector_, int _i,int _k){
    char *vector = (char*)_vector_;
    char temp;
    if(vector[_i] > vector[_k]){
        temp = vector[_i];
        vector[_i] = vector[_k];
        vector[_k] = temp;
    }
}


int main(){

    int _array_1 [5] = {2,20,7,108,9}; // RANDOMS
    float _array_2 [5] = {4.4,5.4,9.1,7.4,2.2};
    double _array_3 [5] = {3.0,8.0,2.0,4.0,15.0};
    char _array_4 [6] = {'k','a','r','l','o','s'};

    _bubblesort_(_array_1,_b_int_,5);
    //print_array(_array_1);
    _bubblesort_(_array_2,_b_float_,5);
    //print_array(_array_2);
    _bubblesort_(_array_3,_b_double_,5);
    print_array(_array_3);
    _bubblesort_(_array_4,_b_char_,6);
    //print_array(_array_4);

    return 0;
}


