#include<iostream>
using namespace std;

template <typename T>
struct node 
{
	T data;
	struct node *next;

};

template<class T>
class GenericQueue
{
   private:
   	        node <T> * first;
   	       int size;

   	public:

            GenericQueue();
        

   		     void Enqueue(T);
   		     int Dequeue();

   		     void Display();
   		     int Count();

};

template<class T>
GenericQueue <T> :: GenericQueue()
{
	first = NULL;
	size = 0;
}


template<class T>
void GenericQueue <T> :: Enqueue(T no)
{
  
    node <T> * temp = first;

    node <T> * newn = new node <T>;
   newn -> data = no;
   newn -> next = NULL;

   if(first == NULL)
   {
    
     first = newn;

   }
   else
   {
      while(temp -> next != NULL)
      {
      	temp = temp -> next;
      }

       temp -> next = newn;

   }

  size++;

}


template<class T>
int GenericQueue <T> :: Dequeue()
{
	 node <T> * temp = first;
	int iData = 0;

	if(first == NULL)
	{
		return -1;
	}
	else if(first -> next == NULL)
	{
		iData = first -> data;
		delete first;
		first = NULL;
	}
	else
	{
		iData = first -> data;
		first = first -> next;
		delete temp;
	}
	size--;
	return iData;
}

template<class T>
void GenericQueue <T> :: Display()
{
	 node <T> * temp = first;
	cout<<"\n";

	while(temp != NULL)
	{
		cout<<"|"<<temp -> data<<"|"<<"\n";
		temp = temp -> next;
	}

	cout<<"\n";

}

template<class T>
int GenericQueue <T> :: Count()
{
	return size;
}

int main()
{
    GenericQueue <int> obj;
    
    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);
    
    cout<<"Elements of Queue :\n";
    
    obj.Display();
    cout<<"\n";

    int iret = obj.Dequeue();       
    cout<<"Removed element from queue : "<<iret<<"\n";                   
    
    cout<<"\n";

    cout<<"Elements from queue : \n";
    obj.Display();
    cout<<"\n";
                    
    iret = obj.Count();         
    cout<<"Size of queue is : "<<iret<<"\n";     

    cout<<"\n--------------------------------------------\n";

       GenericQueue <char> Cobj;
    
    Cobj.Enqueue('B');
    Cobj.Enqueue('A');
    Cobj.Enqueue('C');
    Cobj.Enqueue('D');
    
    cout<<"Elements of Queue :\n";
    
    Cobj.Display();
    cout<<"\n";

    char iret2 = Cobj.Dequeue();       
    cout<<"Removed element from queue : "<<iret2<<"\n";                   
    
    cout<<"\n";

    cout<<"Elements from queue : \n";
    Cobj.Display();
    cout<<"\n";
                    
    int iret1 = Cobj.Count();         
    cout<<"Size of queue is : "<<iret1<<"\n";  
    
    return 0;
}

