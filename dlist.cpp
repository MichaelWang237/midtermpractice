#include "dlist.h"

dlist::dlist() {
  head = NULL;
  tail = NULL;
}

dlist::~dlist() {
  while (head != NULL) {
    node* temp = head;
    head = head->next;
    delete temp;
  }
}

void dlist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  head = current;
  current->previous = NULL;
  node* previous = current;
  int additionalValues = (rand()&5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->previous = previous;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  tail = current;
  current->next = NULL;
}

void dlist::display() {
  node* current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void dlist::removeG9(node* n){
  if(n == NULL){
    n = head;
  }
  if(n->data > 9){
    if(n == head){
      head = n->next;
      delete n;
      n = head;
    }
    else{
      n->previous->next = n->next;
      node* p = n->previous;
      delete n;
      n = p;
    }
  }
  if(n->next != NULL){
    n = n->next;
    removeG9(n);
  }
  
}
