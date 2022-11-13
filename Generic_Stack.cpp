#include<iostream>
using namespace std;

template<typename T>
struct node
{
	T data;
	struct node *next;

};

template<class T>
class GenericStack
{
   private:

   	    node <T> * first;
   	    int size;

   	public:

   		    GenericStack();
   		 
   		    void push(T);
   		    T pop();

             void Display();
             int Count();
          
};


template<class T>
GenericStack <T> :: GenericStack()
{
	first = NULL;
	size = 0;
}


template<class T>
void GenericStack <T> :: push(T no)
{
	node <T> * newn = new node <T> ;
	newn -> data = no;
	newn -> next = NULL;

	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn -> next = first;
		first = newn;
	}

	size++;
}

template<class T>
T GenericStack <T> :: pop()
{ 
   T iData = 0 ;
   node <T> * temp = first;

   if(first == NULL)
   {
      return -1;
   }

   if(first -> next == NULL)
   {
      iData = first -> data;
       delete first;
       first = NULL;
   }
   else
   {
       iData = temp -> data;
       first = temp -> next;
       delete temp;
   }

   size--;
   return iData;

}

template<class T>
void GenericStack <T> :: Display()
{   
    node <T> * temp = first;
    
    cout<<"\n";

    while(temp != NULL)
    {
      
      cout<<"|"<<temp -> data <<"|"<<"\n";
      temp = temp -> next;

    }

    cout<<"\n";
}


template<class T>
int GenericStack <T> :: Count()
{
   return size;
}




int main()
{
   GenericStack <int> obj;
   int iret = 0; 



    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);
     
     cout<<"\n";
   
    cout<<"Elements of stack : "<<"\n";
    obj.Display();

    cout<<"\n";

    iret = obj.Count();
    cout<<"Size of stack is : "<<iret<<"\n";

    cout<<"\n";

     iret = obj.pop();       
    cout<<"Poped element is : "<<iret<<"\n";    

    cout<<"\n";

    
    cout<<"Elements of stack\n";
    obj.Display();  
   
     cout<<"\n";
     
    iret = obj.Count();
    cout<<"Size of stack is : "<<iret<<"\n";  


   cout<<"\n";


   cout<<"\n----------------------------------------------\n";

   GenericStack <char> Cobj;
   int iret2 = 0;
   char ch = '\0'; 



    Cobj.push('A');
    Cobj.push('B');
    Cobj.push('C');
    Cobj.push('D');
     
     cout<<"\n";
   
    cout<<"Elements of stack : "<<"\n";
    Cobj.Display();

    cout<<"\n";

    iret2 = Cobj.Count();
    cout<<"Size of stack is : "<<iret2<<"\n";

    cout<<"\n";

     ch = Cobj.pop();       
    cout<<"Poped element is : "<<ch<<"\n";    

    cout<<"\n";

    
    cout<<"Elements of stack\n";
    Cobj.Display();  
   
     cout<<"\n";
     
    iret2 = Cobj.Count();
    cout<<"Size of stack is : "<<iret2<<"\n";  


   cout<<"\n";

   return 0;


}

