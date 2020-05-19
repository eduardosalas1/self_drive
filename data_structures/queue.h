//
// Created by edublo on 9/04/20.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H
#include <iostream>
#include <ostream>
#include "stack.h"
using namespace std;

namespace queue{
template<typename T>
struct Node{
    T data;
    Node<T> * next;

};

    template <typename T>
    class iterator {
    private:
        typedef Node<T> node;
        node * pointer;

    public:
        iterator(){ pointer = nullptr; }
        iterator(node * ptr) { this->pointer = ptr; }

        void operator ++(){
            this->pointer = this->pointer->next;
        }

        T operator * (){
            return this->pointer->data;
        }

        bool operator == (const iterator & it){
            return this->pointer == it.pointer;
        }

        bool operator != (const iterator & it){
            return this->pointer != it.pointer;
        }
        node* get_ptr(){
            return pointer;
        }
    };


template <typename T>
class Queue{
private:
    typedef Node<T> node;
    node* head;
    node*tail;
public:
    typedef iterator<T> _iterator;
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    T get_head(){
        return head->data;
    }
    T get_tail(){
        return tail->data;
    }
    int size(){
        int counter = 0;
        node* pointer = tail;
        while(pointer != nullptr){
            counter++;
            pointer = pointer->next;
        }
        return counter;
    }
    bool isEmpty(){return head == nullptr;}

    //insertion

    void enqueue(const T& data){
        //best case : T(n) = c5 + c6
       if(head == nullptr){                             //c1 * 1
           node* new_node = new node{data, nullptr};    //c2 * 1
           head = new_node;                             //c3 * 1
           tail = head;                                 //c4 * 1
       }    //worst case: T(n) c1+c1+c3+c4
       else{
           node* new_node = new node{data , tail};      //c5 *1
           tail = new_node;                             //c6 * 1
       }
    }

    //deletion
    void dequeue(){
            node* pointer = tail;  //c1

            while (pointer != nullptr) { //c2 * (n+1)
                if (pointer->next == head) { //c3 * n
                    head = pointer;          //c4*1
                }
                if (pointer->next == nullptr) {// c5 * n
                    head->next = nullptr;      //c6*1
                    pointer = nullptr;         //c7*1
                }
                pointer = pointer->next;      //c8*n

                //T(n) = c1 + c2(n+1) + c4 + c5*n + c6 + c7 + c8*n
        }

    }
    //iterators

    _iterator begin(){return _iterator(tail);}

    _iterator end(){return _iterator(nullptr);}

    //Maximos y minimos
    T max(){
        node* temp = tail;
        for(iterator i(tail) ; i != end() ; ++i){
            if(temp->data < *i){
                temp = i.get_ptr();
            }
            else{
                continue;
            }
        }
        return temp->data;
    }

    T min(){
        node* temp = tail;
        for(_iterator i(tail) ; i != end() ; ++i){
            if(temp->data > *i){
                temp = i.get_ptr();
            }
            else{
                continue;
            }
        }
        return temp->data;
    }
    friend ostream& operator <<(ostream& os , const Queue & queue){
        node * pointer = queue.tail;
        while (pointer != nullptr) {
            os << pointer->data << " ";
            pointer = pointer->next;
        }

    }


    ~Queue(){

    }




};





}


#endif //DATA_STRUCTURES_QUEUE_H
