#include <iostream>
#include "List.h"
#include <vector>
using namespace std;



int main(){

    int arr[5] = {1,2,3,4,5};
    List<int> lista{arr,5};
    cout<<lista;


    return 0;
}