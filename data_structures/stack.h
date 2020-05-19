//
// Created by edublo on 9/04/20.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H
#include <ctime>
#include <iostream>
#include <ostream>
using namespace std;

namespace cs2100 {

    template <typename T>
    struct stackNode {
        T content;
        stackNode<T> * nextNode;
    };

    template <typename T>
    class iterator {
    private:
        typedef stackNode<T> stacknode;
        stacknode * pointer;

    public:
        iterator(){ pointer = nullptr; }
        iterator(stacknode * ptr) { this->pointer = ptr; }

        void operator ++(){
            this->pointer = this->pointer->nextNode;
        }

        T operator * (){
            return this->pointer->content;
        }

        bool operator == (const iterator & it){
            return this->pointer == it.pointer;
        }

        bool operator != (const iterator & it){
            return this->pointer != it.pointer;
        }
        stacknode* get_ptr(){
            return pointer;
        }
    };


    template <typename T>
    class stack {
    private:
        typedef stackNode<T> stacknode;

        stacknode * top;

    public:
        typedef iterator<T> _iterator;

        stack(){ top = nullptr; }
        ~stack(){
            while(!isEmpty()){ pop(); }
        }

        // Stack related functions

        bool isEmpty(){ return top == nullptr; }


        void push(const T & new_content){                           // O(1)
            stacknode * new_node = new stacknode{new_content, top}; // c* 1
            top = new_node;                                         // c2*1         T(n) = c + c2
        }


        void pop() {                    //best case: top = is empty -> 0
            if (top != nullptr) {           //c*1
                stacknode * holder = top;   //c2*1
                top = holder->nextNode;     //c3*1
                holder->nextNode = nullptr; //c4*1
                delete holder;              //c5*1
            }                               //T(n) = c + c2 + c3 + c4 + c5
        }

        // Iterator functions

        _iterator begin(){
            return iterator(top);
        }

        _iterator end() {
            return _iterator(nullptr);
        }

        // std::ostream overloading (cout, ofstream, ...)

        T operator[](int pos){      //best case : is empty : T(n) = c + c2
            int counter = 0;        //c*1
            for(_iterator i(top) ; i!=end() ; ++i){ //c2 * n
                if(counter == pos){ //c3 * n
                    return *i;      // c4* 1
                }
                counter++;          //c5 * n
            }
        }                           // T(n) = c + c2*n + c3*n + c4 + c5*n

        //Maximos y minimos

        T max(){
            stacknode* temp = top;
            for(_iterator i(top) ; i != end() ; ++i){
                if(temp->content < *i){
                    temp = i.get_ptr();
                }
                else{
                    continue;
                }
            }
            return temp->content;
        }

        T min(){
            stacknode* temp = top;
            for(_iterator i(top) ; i != end() ; ++i){
                if(temp->content > *i){
                    temp = i.get_ptr();
                }
                else{
                    continue;
                }
            }
            return temp->content;
        }

        friend ostream& operator << (ostream &os, const stack & stack){
            stacknode * pointer = stack.top;
            while( pointer != nullptr ){
                os << pointer->content << " ";
                pointer = pointer->nextNode;
            }
            return os;
        }

    };

}























#endif //DATA_STRUCTURES_STACK_H
