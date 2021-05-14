//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class clist
{
   public:
   		//These functions are already written
   		clist();		//supplied
   		~clist();		//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
		void sumEven(node* n, int & total);
		void copyNot2(node* n, node*& cpyHead);


	private:
		node * rear;
};
