//include library
#include<iostream>

using namespace std;

//create class for node
class Node
{
	public:
	  //data
	  int data;
	  //pointer to the next Node
    	  Node * next;
    	  //construct that makes the ptr to NULL
    	  Node()
	  {
        	next = NULL;
    	  }

};

class LINKEDLIST
{
    	public:
    	  //head -> Node type ptr
    	  Node * head;
    	  Node * tail;

    	  //constructor
    	  LINKEDLIST()
	  {
          	head = NULL;
          	tail = NULL;
	  } 

    	  //function to insert variable
    	  void INSERT(int value)
	  {
       	  	//if 1st Node is added
       	  	Node * temp = new Node; 
       	  	//insert value in the node
       	  	temp->data = value;
       	  	//1st Node only.
       	  	if(head == NULL)
	  	{
          	  	head = temp;
       	  	}
       	  	//any other Node only.
       	  	else
	  	{
           	 	tail->next = temp;
       	  	}
       		tail = temp;
	} 	

    	void INSERTAT(int pos, int value)
	{
	        //reach the place before the pos
	        Node * current = head;
	        int i=1;
	        while(i < pos-1)
		{
			if(current->next==NULL)
			{
				cout<<"Linked List does not have that many elements";
			}
	            	i++;
	            	current = current->next;
	        }

	        //create a node
	        Node * temp = new Node;
	        temp -> data = value;


	        //moving ptrs if not head
	        temp->next = current->next;
	        current->next = temp;

	}

       	//deletion of last element
    	void DELETE()
	{
	        //store the tail in temp
	        Node * temp = tail;
	        //before tail has to point to null
	        Node * current = head;
	        while(current->next != tail)
		{
        		current = current->next;
        	}
        	current->next = NULL; 

        	//update tail
        	tail = current;
        	//delete temp
        	delete temp;
    	}

	//deletion at the given position
	void DELETEAT(int pos)
	{
		//reach the pos
	        Node * current = head;
	        int i=1;
	        while(i < pos)
		{
			if(current->next==NULL)
			{
				cout<<"Linked List does not have that many elements";
			}
	            	i++;
	            	current = current->next;
	        }
		//store the next element in temp
		Node * temp = current;
		//update 
		current = current ->next;
		//delete temp
		delete temp;
	}

	int COUNTITEMS()
	{
		Node * current = head;
		//condition to check the no. of elements in linked list
		int i=1;
		while(current -> next!=NULL)
		{
			i++;
		}
		//returns the no. of elements in linked list
		return i-1;
	}

    	//display
    	void DISPLAY()
	{
	        Node * current = head;
	        while(current != NULL)
		{
            		cout << current->data << "->";
            		current = current->next;
        	}
        	cout << endl;
    	}
};


int main()
{
	LINKEDLIST l1;
	l1.INSERT(1);
	l1.INSERT(2);
	l1.INSERT(3);
	l1.DISPLAY();
	l1.DELETE();
	l1.DISPLAY();
	l1.INSERTAT(2,8);
	l1.DISPLAY();
	l1.DELETEAT(2);
	l1.DISPLAY();    
	return 0;
}
