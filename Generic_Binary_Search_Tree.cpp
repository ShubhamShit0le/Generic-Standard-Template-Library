#include<iostream>
using namespace std;

typedef struct node
{
   int data;
   struct node *lchild;
   struct node *rchild;
	
}NODE,*PNODE;


class GenericBST
{
	private : 

	         PNODE first;
	         

	public :

	          GenericBST();
	          void Insert(int no);
	          bool Search(int no);

	          void DisplayInOrder();
	          void DisplayPreOrder();
	          void DisplayPostOrder();
	          int Count();

};

GenericBST :: GenericBST()
{
	first = NULL;
}

void GenericBST :: Insert(int no)
{
   PNODE newn = new NODE;
   newn -> data = no;
   newn -> lchild = NULL;
   newn -> rchild = NULL;

   if(first == NULL)
   {
  
     first = newn;

   }
   else
   {
     PNODE temp = first;

       while(1)
       {

           if(temp -> data == no)
           {

              delete newn;
              break;


           }
           else if((no < (temp -> data)))
           {
             if((temp -> lchild ) == NULL )
             {
             	temp -> lchild = newn;
             	break;
             }
            
             temp = temp -> lchild;

           }
           else if((no > (temp -> data)))
           {

                if((temp -> rchild) == NULL)
                {
                	temp -> rchild = newn;
                	break;
                }

                temp = temp -> rchild;

           }
    

       }



   }



}

void GenericBST :: DisplayInOrder()
{
  




}

void GenericBST :: DisplayPreOrder()
{
   

   if(first != NULL)
   {
      
      cout<<first -> data<<"\t";
      first = first -> lchild;
      first = first -> rchild;
      DisplayPreOrder();


   }


}


void GenericBST :: DisplayPostOrder()
{
   

   if(first != NULL)
   {
      first = first -> lchild;
      DisplayPostOrder();
      first = first -> rchild;
      DisplayPostOrder();
      cout<<first -> data<<"\t";


   }


}

bool GenericBST :: Search(int no)
{
   bool bFlag = false;

   PNODE temp = first;

   if( temp == NULL)
   {
   	return bFlag;
   }
   else
   {
       while(temp != NULL)
       {
       	 if((temp -> data) == no)
       	 {
       	 	bFlag = true;
       	 	break;
       	 }
       	 else if((no < (temp -> data)))
       	 {

             temp = temp -> lchild;

       	 }
       	 else if((no > (temp -> data)))
       	 {

       	 	temp = temp -> rchild;
       	 }


       }

       return bFlag;

   }


}

int GenericBST :: Count()
{
   static int iCnt = 0;

   if(first != NULL)
   {
      iCnt++;

      first = first -> lchild;
      Count();
      first = first -> rchild;
      Count();

   }

   return iCnt;
}



int main()
{
   GenericBST obj;

  bool bRet = false;
  int iNo = 0;
  int iRet1 = 0;


  obj.Insert(51);
  obj.Insert(21);
  obj.Insert(101); 

  //  cout<<"\nEnter Number To Search : ";
  //  cin>>iNo;

  // // bRet = obj.Search(iNo);

  // // if(bRet == true)     
  // // {
  // //   cout<<"\nNumber is present"<<"\n";
  // // }
  // // else                 
  // // {
     
  // //    cout<<"\nNumber is absent"<<"\n";

  // // }

 obj.DisplayInOrder();

 cout<<"\n";

 obj.DisplayPreOrder();

  cout<<"\n";


 obj.DisplayPostOrder();

 cout<<"\n";


   iRet1 = obj.Count();

  cout<<"\nNumber Of Nodes Are : "<<iRet1;
  cout<<"\n";


 return 0;




}


