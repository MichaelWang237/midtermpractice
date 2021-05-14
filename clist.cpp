#include <time.h>
#include "clist.h"

clist::clist() {
  rear = NULL;
}

clist::~clist() {
  node* temp = rear;
  rear = rear->next;
  temp->next = NULL;
  while (rear->next != NULL) {
    temp = rear;
    rear = rear->next;
    delete temp;
  }
  rear->next = NULL;
  delete rear;
}

void clist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  rear = current;
  node* previous = current;
  int additionalValues = (rand()%5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  current->next = rear;
}

void clist::display() {
  node* current = rear->next;
  while (current != rear) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << rear->data << " ";
  cout << endl;
}

void clist::sumEven(node* n, int & total){
  if(n == NULL){
    n = rear->next;
  }
  if((n->data % 2)  == 0){
    total = total + n->data;
  }
  if(n == rear){
    return;
  }
  else{
    sumEven(n->next, total);
  }
}

void clist::copyNot2(node* n, node*& cpyHead){
  if(n == NULL){
    n = rear->next;
  }
  if(n->data != 2){
    if(cpyHead == NULL){
      cpyHead = new node;
      cpyHead->data = n->data;
    }
    else{
      node* temp = cpyHead;
      node* newNode = new node;
      newNode->data = n->data;
      while(1){
        if(temp->next == NULL){
          break;
        }
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }
  if(n == rear){
    return;
  }
  n = n->next;
  copyNot2(n, cpyHead);
}
