#include <iostream>
#include "stack.h"
#include "doublelinkedlist.h"
#include "queue.h"
#include "singlelinkedlist.h"
#include "circularlinkedlist.h"
#include <ctime>

using namespace std;

int main(){

    /*Linked_List_Tail<int> list;
    list.push_back(3);
    list.push_back(5);
    list.push_back(8);
    list.pop_back();
    list.pop_front();
    cout<<list;
*/
    queue::Queue<int> st;
    st.enqueue(1);
    st.enqueue(4);
    st.enqueue(2);
    st.enqueue(13);
    cout<<st;

    /*Linked_List_Tail<int> llt;
    llt.push_back(4);
    cout<<llt.max();*/

   /* circ::cllouttail<int> cll;
    cll.push_front(4);
    cll.push_front(3);
    cll.push_front(2);
    cll.push_back(4);
    cll.pop_front();
    cout<<cll[1];*/
    /*circ::cllouttail<int> cll;
    cll.push_front(4);
    cll.push_front(3);
    cll.push_front(2);*/
    /*::Doubleouttail<int> dll;
    dll.push_front(4);
    dll.push_front(5);
    dll.push_front(6);
    dll.push_back(9);
    dll.push_bnode(2,3);
    dll.push_afnode(4,2);
    dll.pop_back();
    dll.erase(2);
    cout<<dll;
    */

    /*edub::Queue<int> q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout<<q1;*/

    /*
    edu::Doublelinked<int> l1;
    l1.push_back(10);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(9);
    l1.push_front(4);
    l1.push_bnode(3,2);
    l1.erase(5);



    cout<<l1.min();
*/
    return 0;
}
