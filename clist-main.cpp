#include "clist.h"
#include <iostream>


int main()
{
    clist object;
    object.build();		//builds a circular LL
    cout << "Before:" << endl;
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    /*
    int total = 0;
    object.sumEven(NULL, total);
    cout << "Sum of even items in the list: " << total << endl;
    */
    node* cpyHead = new node;
    cpyHead = NULL;
    object.copyNot2(NULL, cpyHead);
    node* temp = cpyHead;
    cout << "Copied: " << endl;
    while(temp!=NULL){
        cout << temp->data <<  " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "After: " << endl;
    object.display(); //resulting list after your function call!
    
    return 0;
}
