#ifndef DATA_STRUCTURES_SINGLELINKEDLIST_H
#define DATA_STRUCTURES_SINGLELINKEDLIST_H
#include <iostream>
#include <ostream>
using namespace std;



template<typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class Iterator{
private:
    typedef Node<T> node;
    node* iterator;
public:
    Iterator(){iterator = nullptr;}
    Iterator(node * itr){ this->iterator = itr;}

    void operator ++(){
        this->iterator = this->iterator->next;
    }

    T& operator *(){
        return iterator->data;
    }
    bool operator ==(const Iterator& itr){
        return iterator == itr.iterator;
    }
    bool operator !=(const Iterator& itr){
        return iterator != itr.iterator;
    }
    node *get_itr(){
        return iterator;
    }

};

template <typename T>
class Linked_List {
private:
    typedef Node<T> node;
    node *head;
public:
    typedef Iterator<T> iterator;
    Linked_List(){
        head = nullptr;
    }
    int size(){
        int counter = 0 ;
        node* temp = head;
        while(temp != nullptr){
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    void push_front(const T &data) {
        if (head == nullptr) {//c*1
            node *Node = new node{data, nullptr};//c2*1
            head = Node;//c3*1
        } else {
            node *new_node = new node{data, head};//c4*1
            head = new_node;//c5*1
        }
        //Best case= c4 + c5 // worst case: = c1 + c2 + c3
    }

    void push_back(const T &data) {
        //best case: = c1+c2+c3
        if (head == nullptr) {//c1 * 1
            node *Node = new node{data, nullptr};//c2 * 1
            head = Node;//c3 * 1
        }
        else {
            node* new_node = new node{data, nullptr};//c4*1
            node* temp = head;//c5*1
            for(int i = 0 ; ; i++){//c6*n
                if(temp->next == nullptr){//c7*n
                    temp->next = new_node;//c8*1
                    break;//c9*1
                }
                temp = temp->next;//c10*(n-1)
            }
            }
        //worst case = c4 + c5 + c6*n + c7*n + c8 + c9 + c10(n-1)
        }

        //deletion

        void pop_back() {

            if(size() == 1){//c*1
                delete head;//c2*1
            }
            else {
                node* temp = head;//c3*1
                node* tail = head;//c4*1
                for (int i = 0; i < size() - 1; i++) {//c5*n
                    if(size() - 2 == i){//c6*(n-1)
                        break;//c7*1
                    }
                    temp = temp->next;//c8*n
                    tail = tail->next;//c9*n
                }
                tail = tail->next;//c10*1
                temp->next = nullptr;//c11*1
                delete tail;//c12*1
            }
            //T(n) = c + c2 + c3 + c4 + c5*n + c6*(n-1) + c7 + c8*n + c9*n + c10 + c11 + c12
        }

    void pop_front(){
        node* pointer = head;//c*1
        head = head->next;//c2*1
        delete pointer;//c3*1
    }//T(n) = c + c2 + c3

    T max() {
        node * max_node = head;
        for(iterator i(head); i != end() ; ++i){
            if(max_node->data < *i){
                max_node = i.get_itr();
            }
            else{

                continue;
            }

        }
        return max_node->data;
    }

    T min() {
        node * min_node = head;
        for(iterator i(head); i != end() ; ++i ){
            if(*i<min_node->data)
                min_node = i.get_itr();
            else
                continue;
        }

        return min_node->data;
    }

    friend ostream& operator <<(ostream& os , const Linked_List & lista){
        node * pointer = lista.head;
        while (pointer != nullptr) {
            os << pointer->data << " ";
            pointer = pointer->next;
        }

    }
    iterator begin(){return iterator(head);}
    iterator end(){return iterator(nullptr);}

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
    template<class T>
    class Linked_List_Tail {
    private:
        typedef Node<T> node;
        node *head;
        node *tail;
    public:
        typedef Iterator<T> iterator;
        Linked_List_Tail() {
            head = nullptr;
            tail = nullptr;
        }

        void push_front(const T &data) {
            //Best case = c5 + c6 ->solo else
            if (head == nullptr) { //c * 1
                node *Node = new node{data, nullptr};//c2*1
                head = Node;//c3*1
                tail = head;//c4*1
            } else {
                node *New_Head = new node{data, head}; //c5*1
                head = New_Head;//c6*1
            }//T(n)  = c + c2 + c3 + c4  -> en if
        }

        void push_back(const T &data) {
            if (head == nullptr) {//c*1
                node *Node = new node{data, nullptr};//c2*1
                head = Node;//c3*1
                tail = head;//c4*1
            } else {
                node *Node = new node{data, nullptr};//c5*1
                tail->next = Node;//c6*1
                tail = Node;//c7*1
            }//best case = c5 + c6 + c7 , wors case = c + c2 + c3 + c4
        }
            void pop_back(){
            node* temp = head;//c*1
            for(int i = 0 ; ; i++){//c2*n
                if(temp->next == tail){//c3*n
                    break;//c4*1
                }
                temp = temp->next;//c5*n
            }
            tail = temp;//c6*1
            temp = temp->next;//c7*1
            tail->next = nullptr;//c8*1
            delete temp;//c9*1
        }


        void pop_front(){
                node* pointer = head;//c*1
                head = head->next;//c2*1
                delete pointer;//c3*1

            }//T(n) = c + c2 + c3


        T max() {
            node * max_node = head;
            for(iterator i(head); i != end() ; ++i){
                if(max_node->data < *i){
                    max_node = i.get_itr();
                }
                else{

                    continue;
                }

            }
            return max_node->data;
        }

        T min() {
            node * min_node = head;
            for(iterator i(head); i != end() ; ++i ){
                if(*i<min_node->data)
                    min_node = i.get_itr();
                else
                    continue;
            }

            return min_node->data;
        }

            Iterator<T> end() {
                return (Iterator<T>(nullptr));
            }

            T &operator[](int pos) {
                int contador = 0;
                for (Iterator it(head); it != end(); ++it) {
                    if (contador == pos)
                        return *it;
                    else {
                        contador++;
                    }
                }
            }

            //Printing
            friend ostream& operator<<(ostream &os, const Linked_List_Tail &lista_tail) {
                node *current = lista_tail.head;
                while (current != nullptr) {
                    os << current->data << " ";
                    current = current->next;
                }
            }

        };


#endif //DATA_STRUCTURES_SINGLELINKEDLIST_H
