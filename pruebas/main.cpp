#include <iostream>
#include <vector>
using namespace std;

/*template<class T>
void Insertion_sort(vector<T> * disorder_vec){
    for(int i = 1 ; i < disorder_vec->size() ; i++){
        T help = disorder_vec->at(i);
        for( int j = i-1 ; j >= 0; j--){
            if(disorder_vec->at(j) > help ){
                disorder_vec->at(j+1) = disorder_vec->at(j);
                disorder_vec->at(j) = help;
            }
            else{ continue;}
        }

        }
    }*/

template<class T>
void print_array(vector<T> * disorder_vec){
    for(int i  = 0 ; i < disorder_vec->size() ; i++){
        cout<<disorder_vec->at(i)<<endl;
    }
}

int main(){
    vector<int> * desorden = new vector<int>();
    *desorden = {5,8,2,4,1,3};
    //Insertion_sort(desorden);
    print_array(desorden);
    return 0 ;

}