#ifndef DATA_STRUCTURES_DOUBLELINKEDLIST_H
#define DATA_STRUCTURES_DOUBLELINKEDLIST_H

#include <iostream>
#include <ostream>
using namespace std;

namespace edu{

    template <typename T>
    struct node{
        T valor;
        node <T>* prevnode;
        node<T>* nextnode;

    };

    template <typename T>
    class Iterator{
    private:
        typedef node<T> Node;
        Node* iterator;
    public:
        Iterator(){iterator = nullptr;}
        Iterator(Node * itr){ this->iterator = itr;}

        void operator ++(){
            this->iterator = this->iterator->prevnode;
        }

        void operator--(){
            this->iterator = this->iterator->nextnode;
        }
        T& operator *(){
            return iterator->valor;
        }
        bool operator ==(const Iterator& itr){
                return iterator == itr.iterator;
        }
        bool operator !=(const Iterator& itr){
            return iterator != itr.iterator;
        }
        Node *get_itr(){
            return iterator;
        }


    };

    template<typename T>
    class Doublelinked{
    private:
        typedef node<T> dllnode;
        dllnode* head ;
        dllnode * tail ;
    public:
        typedef Iterator<T> iterator;
        Doublelinked(){
            head = nullptr;
            tail = nullptr;
        }
        int size(){
            dllnode* pointer = head;
            int counter = 0;
            while(pointer != nullptr){
                counter ++;
                pointer = pointer->prevnode;
            }
            return counter;
        }

        //insertion
        void push_back(const T& data){
            if(head == nullptr){//c *1
                dllnode *new_node = new dllnode{data, nullptr, nullptr};//c2*1
                head = new_node;//c3*1
                tail = head;//c4*1
            }
            else{
                dllnode* new_node = new dllnode{data, nullptr, tail};//c5*1
                tail->prevnode = new_node;//c6*1
                tail = new_node;//c7*1
            }
            //best case: = c5 + c6 + c7 ; worst case = c + c2 + c3 + c4
        }
        void push_front(const T& data){
            if(head == nullptr){//c * 1
                dllnode *new_node = new dllnode{data, nullptr, nullptr};//c2*1
                tail = new_node;//c3*1
                head = tail;//c4*1
            }
            else{
                dllnode *new_node = new dllnode{data, head, nullptr};//c5*1
                head->nextnode = new_node;//c6*1
                head = new_node;//c7*1
            }
            //T(n) : best case= c5 + c6 + c7 ; worst case = c + c2 + c3 + c4
        }

        void push_bnode(unsigned int pos , const T& data){
            dllnode* pointer = head;// c * 1
            dllnode*pointer2 = head;// c2 *1
            if(pos == 0){// c3*1
                push_front(data);//c4*1
            }
            else {
                for (int i = 0; i < size(); i++) {//c5*n+1
                    if (i == pos - 1) {//c6*(n-1)
                        pointer2 = pointer2->prevnode;//c7*1
                        dllnode *new_node = new dllnode{data, pointer2, pointer};//c8*1
                        pointer2->nextnode = new_node;//c9*1
                        pointer->prevnode = new_node;//c10*1
                        break;//c11*1
                    }
                    pointer2 = pointer2->prevnode;//c12*n
                    pointer = pointer->prevnode;//c13*n
                }
            }
            //T(n) best case : = c3 + c4 ; worst case = c + c2 + c3 + c5(n+1) + c6*(n-1) + c7 + c8 + c9 + c10+ c11 + c12*n + c13*n
        }
        void push_afnode(unsigned int pos , const T& data){
            dllnode* pointer = head;//c*1
            dllnode* pointer2 = head;//c2*1
            if(pos == size() - 1){//c3*1
                push_back(data);//c4*1
            }
            else{
                for(int i = 0 ; i < size() ; i++){//c5*(n+1)
                    if(i == pos){//c6*n
                        pointer2 = pointer2->prevnode;//c7*1
                        dllnode* new_node = new dllnode{data,pointer2,pointer};//c8*1
                        pointer->prevnode = new_node;//c9*1
                        pointer2->nextnode = new_node;//c10*1
                        break;//c11*1
                    }
                    pointer = pointer->prevnode;//c12*(n-1)
                    pointer2 = pointer2->prevnode;//c13*(n-1)

                }

            }
            //best case: c3+c4 ; worst case = c1+c2+c3+c5*(n+1)+c6*n+c7+c8+c9+c10+c11+c12*(n-1)+c13*(n-1)

        }

        //getters

        T get_head(){
            return head->valor;
        }
        T get_tail(){
            return tail->valor;
        }

        //deletion

        void pop_back(){
            dllnode* pointer = tail;//c*1
            tail = tail->nextnode;//c2*1
            delete pointer;//c3*1
            tail->prevnode = nullptr;//c4*1
        }//T(n) = c + c2 + c3 + c4

        void erase(int pos){

            if(pos == size()- 1){
                pop_back();
            }
            else {
                dllnode* help = head;
                dllnode* pointer = head;
                for (int i = 0; i < size(); i++) {
                    if(pos == 0){
                        pop_front();
                        break;
                    }
                    if(i == pos){
                        dllnode* temp = help;
                        help = help->nextnode;
                        pointer = pointer->prevnode;
                        pointer->nextnode = help;
                        help ->prevnode = pointer;
                        delete temp;
                        break;
                    }
                    help = help->prevnode;
                    pointer = pointer->prevnode;
                }
            }
        }

        void pop_front(){
            dllnode* pointer = head;//c*1
            head = head->prevnode;//c2*1
            delete pointer;//c3*1
            head->nextnode = nullptr;//c4*1
        }//T(n) = c + c2 + c3 + c4

        //Maximo

        T& max(){
            dllnode * max_node = head;
            for(iterator i(head); i != end() ; ++i){
                if(max_node->valor < *i){
                    max_node = i.get_itr();
                }
                else{

                    continue;
                }

            }
            return max_node->valor;
        }

        //Minimo

        T& min(){
            dllnode * min_node = head;
            for(iterator i(head); i != end() ; ++i ){
                if(*i<min_node->valor)
                    min_node = i.get_itr();
                else
                    continue;
            }

            return min_node->valor;
        }
        //iterators
        iterator begin(){
            return iterator(head);
        }
        iterator end(){
            return iterator(nullptr);
        }


        //sobrecarga de operadores
         friend ostream& operator << (ostream &os, const Doublelinked & dll){
            dllnode * pointer = dll.head;
            while( pointer != nullptr ){
                os << pointer->valor << " ";
                pointer = pointer->prevnode;
            }
            return os;
        }


        T& operator [](int pos){
            int counter = 0;
            for(iterator i(head) ; i!= end() ; ++i){
                if(counter == pos){
                    return *i;
                }
                else{
                    counter++;
                }
            }
        }

    };

    template<typename T>
    class Doubleouttail{
    private:
        typedef node<T> Node;
        Node* head;
    public:
        typedef Iterator<T> iterator;
        Doubleouttail(){head = nullptr;}
        int size(){
            Node* pointer = head;
            int counter = 0;
            while(pointer != nullptr){
                counter ++;
                pointer = pointer->prevnode;
            }
            return counter;
        }

        //insertion
        void push_back(const T& data){
            if(head == nullptr){//c*1
                Node *new_node = new Node{data, nullptr, nullptr};//c2 * 1
                head = new_node;//c3 *1
            }
            else{
                Node* temp = head;//c4*1
                for(int i = 0; ; i++){//c5*n
                    if(temp->prevnode == nullptr){//c6*n
                        break;//c7*1
                    }
                    temp = temp->prevnode;//c8*(n-1)
                }
                Node* new_node = new Node{data, nullptr, temp};//c9*1
                temp->prevnode = new_node;//c10*1
                temp = new_node;//c11*1
            }
            //T(n) = worst case= c + c4+ c5*n + c6*n + c7 + c8*(n-1) + c9*1 + c10*1 + c11*1
        }
        void push_front(const T& data){
            if(head == nullptr){//c*1
                Node *new_node = new Node{data, nullptr, nullptr};//c2*1
                head = new_node;//c3*1

            }
            else{
                Node *new_node = new Node{data, head, nullptr};//c4*1
                head->nextnode = new_node;//c5*1
                head = new_node;//c6*1
            }
            //T(n) best case: = c + c2 + c3 ; worst case = c + c4+ c5+ c6
        }

        void push_bnode(unsigned int pos , const T& data){
            Node* pointer = head;
            Node*pointer2 = head;
            if(pos == 0){
                push_front(data);
            }
            else {
                for (int i = 0; i < size(); i++) {
                    if (i == pos - 1) {
                        pointer2 = pointer2->prevnode;
                        Node *new_node = new Node{data, pointer2, pointer};
                        pointer2->nextnode = new_node;
                        pointer->prevnode = new_node;
                        break;
                    }
                    pointer2 = pointer2->prevnode;
                    pointer = pointer->prevnode;
                }
            }

        }
        void push_afnode(unsigned int pos , const T& data){
            Node* pointer = head;
            Node* pointer2 = head;
            if(pos == size() - 1){
                push_back(data);
            }
            else{
                for(int i = 0 ; i < size() ; i++){
                    if(i == pos){
                        pointer2 = pointer2->prevnode;
                        Node* new_node = new Node{data,pointer2,pointer};
                        pointer->prevnode = new_node;
                        pointer2->nextnode = new_node;
                        break;
                    }
                    pointer = pointer->prevnode;
                    pointer2 = pointer2->prevnode;

                }

            }

        }

        //Deletion
        void pop_back(){
            Node* tail = head;//c*1
            for(int i = 0 ; ; i++){//c2*n
                if(tail->prevnode == nullptr){//c3*n
                    break;//c4*1
                }
                tail = tail->prevnode;//c5*n
            }
            Node* pointer = tail;//c6*1
            tail = tail->nextnode;//c7*1
            delete pointer;//c8*1
            tail->prevnode = nullptr;//c9*1
        }//T(n)  = c + c2*n + c3*n + c4 + c5*n + c6 + c7 + c8 + c9

        void erase(int pos){

            if(pos == size()- 1){
                pop_back();
            }
            else {
                Node* help = head;
                Node* pointer = head;
                for (int i = 0; i < size(); i++) {
                    if(pos == 0){
                        pop_front();
                        break;
                    }
                    if(i == pos){
                        Node* temp = help;
                        help = help->nextnode;
                        pointer = pointer->prevnode;
                        pointer->nextnode = help;
                        help ->prevnode = pointer;
                        delete temp;
                        break;
                    }
                    help = help->prevnode;
                    pointer = pointer->prevnode;
                }
            }
        }

        void pop_front(){
            Node* pointer = head;//c*1
            head = head->prevnode;//c2 *1
            delete pointer;//c3 * 1
            head->nextnode = nullptr;//c4 *1
        }//T(n) = c + c2 + c3 + c4

        //Maximo

        T& max(){
            Node * max_node = head;
            for(iterator i(head); i != end() ; ++i){
                if(max_node->valor < *i){
                    max_node = i.get_itr();
                }
                else{

                    continue;
                }

            }
            return max_node->valor;
        }

        //Minimo

        T& min(){
            Node * min_node = head;
            for(iterator i(head); i != end() ; ++i ){
                if(*i<min_node->valor)
                    min_node = i.get_itr();
                else
                    continue;
            }

            return min_node->valor;
        }
        //iterators
        iterator begin(){
            return iterator(head);
        }
        iterator end(){
            return iterator(nullptr);
        }


        //sobrecarga de operadores
        friend ostream& operator << (ostream &os, const Doubleouttail & dll){
            Node * pointer = dll.head;
            while( pointer != nullptr ){
                os << pointer->valor << " ";
                pointer = pointer->prevnode;
            }
            return os;
        }


        T& operator [](int pos){
            int counter = 0;
            for(iterator i(head) ; i!= end() ; ++i){
                if(counter == pos){
                    return *i;
                }
                else{
                    counter++;
                }
            }
        }




    };


}





#endif //DATA_STRUCTURES_DOUBLELINKEDLIST_H
