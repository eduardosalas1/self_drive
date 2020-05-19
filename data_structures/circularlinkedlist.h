
#ifndef DATA_STRUCTURES_CIRCULARLINKEDLIST_H
#define DATA_STRUCTURES_CIRCULARLINKEDLIST_H
#include <iostream>
#include <ostream>
using namespace std;

namespace circ{

    template <typename T>
    struct Node{
        int data;
        Node<T>* next;
    };

    template <typename T>
    class circularll{
    private:
        typedef Node<T> node;
        node* head;
        node* tail;
    public:

        circularll(){
            head = nullptr;
            tail = nullptr;
        }
        int size(){
            node* pointer = head;
            int counter = 1;
            while(pointer != tail){
                counter ++;
                pointer = pointer->next;
            }
            return counter;
        }


        void push_front(T data){
            if(head == nullptr){//c*1
                node *Node = new node{data, nullptr};//c2*1
                head = Node;//c3*1
                tail = head;//c4*1
            }
            else{
                node * new_node = new node{data , head};//c5*1
                head = new_node;//c6*1
                tail->next = head;//c7*1
            }
        }//T(n):c + c2 + c3 + c4 ; = c1 + c5 + c6 + c7

        void push_back(T data){
            if(head == nullptr){//c*1
                node *Node = new node{data , nullptr};//c2*1
                head = Node;//c3*1
                tail = head;//c4*1
            }
            else{
                node* new_node = new node{data , head};//c5*1
                tail->next = new_node;//c6*1
                tail = new_node;//c7*1
            }
        }//T(n) = c + c2 + c3 + c4; = c + c5 +c6 + c7
        //deletion

        void pop_back(){
            node* pointer = tail;//c*1
            node* temp = head;//c2*!
            for(int i = 0 ; ; i++){//c3*n
                if(temp->next == tail){//c4*n
                    break;//c5*1
                }
                else temp = temp->next;//c6*(n-1)
            }
            temp->next = head;//c7*1
            delete pointer;//c8*1
            tail = temp;//c9*1
        }//T(n) c + c2 + c3*n + c4*n + c5 + c6(n-1) + c7 + c8 + c9

        void pop_front(){
            node* pointer = head;//c*1
            head = head->next;//c2*1
            delete pointer;//c3*1
            tail->next = head;//c4*1
        }//T(n)= c+ c2 + c3+ c4
        void erase(int pos){

            if(pos == size()- 1){
                pop_back();
            }
            else {
                node* help = head;
                node* pointer = head;
                node*temp = head;
                for (int i = 0; i < size(); i++) {
                    if(pos == 0){
                        pop_front();
                        break;
                    }
                    if(i == pos-1){
                        pointer = pointer->next;
                        pointer = pointer->next;
                        temp = temp->next;
                        help->next = pointer;
                        delete temp;
                        break;
                    }
                    help = help->next;
                    pointer = pointer->next;
                    temp = temp->next;
                }
            }
        }

        //Getters

        T get_head(){
            return head->data;
        }

        T get_tail(){
            return tail->data;
        }
        //Maximos y minimos


        T max(){
            node* temp = head;
            node* ayuda = head;
            for(int i = 0 ; i < size() ; i++){
                if(temp->data < ayuda->data){
                    temp = ayuda;
                }
                ayuda = ayuda->next;
            }
            return temp->data;
        }

        T min(){
            node* temp = head;
            node* ayuda = head;
            for(int i = 0 ; i <size() ; i++){
                if(temp->data > ayuda->data){
                    temp = ayuda;
                }
                ayuda = ayuda->next;
            }
            return temp->data;
        }

        friend ostream& operator << (ostream &os, const circularll & cll){
            node * pointer = cll.head;
            do{
                os << pointer->data << " ";
                pointer = pointer->next;
            }while(pointer != cll.head);

            return os;
        }


        T& operator [](int pos){
            node* pointer = head;//c*1
            for(int i = 0 ; i < size() ; i++){//c2*(n+1)
                if(i == pos){//c3*n
                    return pointer->data;//c4*1
                }
                pointer = pointer->next;//c5*(n-1)
            }
        }//T(n) = c + c2(n+1) + c3*n + c4 + c5*(n-1)
    };


    template <typename T>
    class cllouttail{
    private:
        typedef Node<T> node;
        node* head;
    public:
        cllouttail(){ head = nullptr;}

    int Size(){
        node* current = head;
        int contador = 1;

        while(current->next != head){
            if(head == nullptr) {
                return 0;
            }
            current = current->next;
            if(current == nullptr)
                return 1;
            contador++;
        }
        return contador;
    }
        //insertion

        void push_front(const T &data){
            if(head == nullptr){//c*1
                node* Node = new node{data, nullptr};//c2*1
                head = Node;//c3*1
            }
            else{
                node* Node = new node{data, head};//c4*1
                node* temp = head;//c5*1
                for(int i = 0; i < Size(); i++) {//c6*(n+1)
                    if(i == Size() - 1) {//c7*n
                        temp->next = Node;//c8*1
                        head = Node;//c9*1
                        break;//c10*1
                    }
                    temp = temp->next;//c11*(n-1)
                }
            }
        }//T(n) best case: = c + c2 + c3 ; worst case : = c + c4 + c5 + c6(n+1) + c7*n + c8 + c9 + c10 + c11(n-1)


        void push_back(const T &data){
            if(head == nullptr){//c*1
                node* Node = new node{data, nullptr};//c2*1
                head = Node;//c3*1
            }
            else{
                node* Node = new node{data, head};//c4*1
                node* temp = head;//c5*1
                for(int i = 0; i < Size(); i++) {//c6*(n+1)
                    if(i == Size() - 1) {//c7*n
                        temp->next = Node;//c8*1
                        break;//c9*1
                    }
                    temp = temp->next;//c10*(n-1)
                }
            }
        }//T(n) best case: = c + c2 + c3 ; worst case: = c + c4 + c5 + c6(n+1) + c7 + c8 + c9 + c10(n-1)

        //deletion
        void pop_back(){
            node* tail = head;//c*1
            for(int i = 0 ; i < Size()-1 ; i++){//c2 *(n-1)
                tail = tail->next;//c3*(n-2)
            }
            node* pointer = tail;//c4*1
            node* temp = head;//c5*1
            for(int i = 0 ; ; i++){//c6*(n+1)
                if(temp->next == tail){//c7*n
                    break;//c8*1
                }
                else temp = temp->next;//c9*(n-1)
            }
            temp->next = head;//c10
            delete pointer;//c11
        }//T(n) = c + c2(n-1) + c3(n-1) + c4 + c5 + c6(n+1) + c7*n + c8 + c9(n-1) + c10 + c11

        void pop_front(){
            node* tail = head;//c*1
            for(int i = 0 ; i < Size()-1 ; i++){//c2*(n-1)
                tail = tail->next;//c3*1
            }
            node* pointer = head;//c4*1
            head = head->next;//c5*1
            delete pointer;//c6*1
            tail->next = head;//c7*1
        }//T(n) = c + c2(n-1) + c3 + c4 + c5 + c6 + c7

        void erase(int pos){

            if(pos == Size()- 1){
                pop_back();
            }
            else {
                node* help = head;
                node* pointer = head;
                node*temp = head;
                for (int i = 0; i < Size(); i++) {
                    if(pos == 0){
                        pop_front();
                        break;
                    }
                    if(i == pos-1){
                        pointer = pointer->next;
                        pointer = pointer->next;
                        temp = temp->next;
                        help->next = pointer;
                        delete temp;
                        break;
                    }
                    help = help->next;
                    pointer = pointer->next;
                    temp = temp->next;
                }
            }
        }

        //Getters

        T get_head(){
            return head->data;
        }

        //Maximos y minimos

        T max(){
            node* temp = head;
            node* ayuda = head;
            for(int i = 0 ; i < Size() ; i++){
                if(temp->data < ayuda->data){
                    temp = ayuda;
                }
                ayuda = ayuda->next;
            }
            return temp->data;
        }

        T min(){
            node* temp = head;
            node* ayuda = head;
            for(int i = 0 ; i <Size() ; i++){
                if(temp->data > ayuda->data){
                    temp = ayuda;
                }
                ayuda = ayuda->next;
            }
            return temp->data;
        }


        //sobrecarga

        friend ostream& operator << (ostream &os, const cllouttail & cll){
            node * pointer = cll.head;
            do{
                os << pointer->data << " ";
                pointer = pointer->next;
            }while(pointer != cll.head);

            return os;
        }


        T& operator [](int pos){
            node* pointer = head;
            for(int i = 0 ; i < Size() ; i++){
                if(i == pos){
                    return pointer->data;
                }
                pointer = pointer->next;
            }
        }








    };










}

#endif //DATA_STRUCTURES_CIRCULARLINKEDLIST_H
