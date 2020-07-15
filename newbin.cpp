//use of doubly linked list
#include<iostream>
using namespace std;
class binary;
class node
{
bool b;
node *next;		
node *prev;

public:
   node()
{b=0;next=NULL;prev=NULL;}
friend class binary;
  // ~node();

};
class binary
{
 bool a,c=1;
 int d;
 node *head,*ptr,*ptr1,*p,*last,*temp,*cur;
 public:
 binary()
 {
   head=NULL;
 }

 void insert(node n)
 {
  cout<<"enter the number"<<endl;
  cin>>d;
  

  }
 void create(node n)
  { 
   if(d==0)
  {
      ptr=new node;
	ptr->b=0;
	ptr->next=NULL;
	ptr->prev=NULL;
	head=ptr;
   }
   else
  {
   while(d!=0)
   {
      ptr=new node;
      ptr->prev=NULL;
      ptr->next=NULL;
      ptr->b=(d%2);
      logic(n);
      d=(d/2);
   } 
  // display(n); 
  }
   
  }
    
  void logic(node n)
  {
    if(head==NULL)
     {
       head=ptr;
      
     }
      else
     {
       ptr1=head;
         while(ptr1->next!=NULL)
          {
           ptr1=ptr1->next;
          }
         ptr1->next=ptr;
         ptr->prev=ptr1;
        
      }
   }

 
  
 void one(node n)
  {
  
   ptr1=head;
    while(ptr1->next!=NULL)
     {
      ptr1=ptr1->next;
     }
   while(ptr1!=NULL)
     {
      ptr1->b=(!(ptr1->b));
      ptr1=ptr1->prev;
    
     }
   }

  void display(node n)
 {
   //cout<<"the binary is"<<endl;
   ptr1=head;
   while(ptr1->next!=NULL)
     {
      ptr1=ptr1->next;
     }
   while(ptr1!=NULL)
     {
      cout<<ptr1->b<<" ";
      ptr1=ptr1->prev;
    
     }
 }
  void display1(node n)
 {
   //cout<<"the binary is"<<endl;
   ptr1=head;
  
   while(ptr1!=NULL)
     {
      cout<<ptr1->b<<" ";
      ptr1=ptr1->next;
    
     }
 }
 void display2()
 {
   //cout<<"the binary is"<<endl;
   ptr1=head;
  
   while(ptr1!=NULL)
     {
      cout<<ptr1->b<<" ";
      ptr1=ptr1->next;
    
     }
 }
 
 
 void rev(node n)
  {
 
  temp=NULL;
  cur=head;
  while(cur!=NULL)
   {
     temp=cur->prev;
     cur->prev=cur->next;
     cur->next=temp;  
     cur=cur->prev; 
   }
   
  if(temp!=NULL)
   {
    head=temp->prev;
   
   } 
  }
 
 void two(node n)
 { 

   rev(n);
   one(n);
   bool c=1; 
  ptr=head;
   
    while(ptr->next!=NULL)
     {
      ptr=ptr->next;
     }
     while(ptr!=NULL)
     {
    
        if((c==1)&&(ptr->b==1))
          {
            ptr->b=0;c=1;
            
           }
         else if((c==1) &&(ptr->b==0))
            {
            ptr->b=1;c=0;
          
            }
          else 
          if(c==0)
            
               {
             break;}
    
       ptr=ptr->prev;
         
    
    
     }
  display1(n);
  }

  binary add(binary d)
  {
   binary sum;
   
  	node *x = head;
  	node *y = d.head;
  	node *newnode;newnode=new node;newnode->next=NULL;newnode->prev=NULL;
        sum.head=NULL;
    bool r=0;
    bool c=0;
    while(x->next!=NULL)
     {
      x=x->next;
     }
    
      while(y->next!=NULL)
     {
      y=y->next;
     }
     
     while(x!=NULL && y!=NULL)
      {
         if(c==0)
            {
             if(x->b==0 && y->b==0)
               {r=0;c=0;}
             if(x->b==1 && y->b==0)
               {r=1;c=0;}
             if(x->b==0 && y->b==1)
               {r=1;c=0;}
             if(x->b==1 && y->b==1)
               {r=0;c=1;}
		 x=x->prev;
      y=y->prev;
         if(sum.head==NULL){sum.head=newnode;newnode->b=r;ptr=sum.head;}
         else{ptr->next=newnode;newnode->b=r;ptr=ptr->next;}
             // cout<<newnode->b;
            }
            else
            //if(c==1)
            {
             if(x->b==0 && y->b==0)
               {r=1;c=0;}
             if(x->b==1 && y->b==0)
               {r=0;c=1;}
             if(x->b==0 && y->b==1)
               {r=0;c=1;}
             if(x->b==1 && y->b==1)
               {r=1;c=1;}
		 x=x->prev;
      y=y->prev;

	 if(sum.head==NULL){sum.head=newnode;newnode->b=r;ptr=sum.head;}
         else{ptr->next=newnode;newnode->b=r;ptr=ptr->next;}
             // cout<<newnode->b;
               
            }

      }
     while(x!=NULL)
     {
      if((c==1)&&(x->b==1))
          {
            r=0;c=1; x=x->prev;
       
           }
         else if((c==1) &&(x->b==0))
            {
            r=1;c=0; x=x->prev;
             
            }
          else 
          if(c==0)
            
            {
		r=x->b;c=0; x=x->prev;
             
            }
    	 if(sum.head==NULL){sum.head=newnode;newnode->b=r;ptr=sum.head;}
         else{ptr->next=newnode;newnode->b=r;ptr=ptr->next;}//cout<<newnode->b; ptr1=sum.head;
   while(ptr1->next!=NULL)
     {
      ptr1=ptr1->next;
     }
   while(ptr1!=NULL)
     {
      cout<<ptr1->b<<" ";
      ptr1=ptr1->prev;
    
     }
	 
              
               
      
      }
       while(y!=NULL)
     {
      if((c==1)&&(y->b==1))
          {
            r=0;c=1;y=y->prev;
       
           }
         else if((c==1) &&(y->b==0))
            {
            r=1;c=0;y=y->prev;
             
            }
          else 
          if(c==0)
            
            {
        	r=y->b;c=0; y=y->prev;
             
            }
		 if(sum.head==NULL){sum.head=newnode;newnode->b=r;ptr=sum.head;}
         else{ptr->next=newnode;newnode->b=r;ptr=ptr->next;}//cout<<newnode->b; ptr1=sum.head;
   while(ptr1->next!=NULL)
     {
      ptr1=ptr1->next;
     }
   while(ptr1!=NULL)
     {
      cout<<ptr1->b<<" ";
      ptr1=ptr1->prev;
    
     }
	 
              
               
         } cout<<endl;cout<<"khj";
    ptr1=sum.head;
   while(ptr1->next!=NULL)
     {
      ptr1=ptr1->next;
     }
   while(ptr1!=NULL)
     {
      cout<<ptr1->b<<" ";
      ptr1=ptr1->prev;
    
     }
	 
   
  }


// ~binary();  
 };
int main()
{
  binary obb,obb1,obb2,obb3,obb4,obb5;
  node ob,ob1,ob2,ob3,ob4,ob5;
 
 int n,ch,num1,num2;
 do
  {
 
  cout<<"enter 1 to generate binary"<<endl<<"enter 2 to display one complement"<<endl<<"enter 3 to display two complement"<<endl<<"enter 4 to add two binary numbers"<<endl;
  cout<<"enter your choice"<<endl;
  cin>>ch;
  
  switch(ch)
{
  
 case 1:
  {
obb.insert(ob);
 cout<<"the binary form is"<<endl;
 obb.create(ob);
 cout<<endl;
 obb.display(ob);
  break;
  }
  case 2:
  {
  obb1.insert(ob1);
 obb1.create(ob1);
  cout<<"the binary form is"<<endl;
 cout<<endl;
 obb1.display(ob1);
 cout<<endl;
  cout<<"one's complement of given number is"<<endl;
 obb1.one(ob1);
 obb1.display(ob1);
 break;
 }

 case 3:
 {
  obb2.insert(ob2);
 obb2.create(ob2);
 cout<<"the binary form is"<<endl;
 cout<<endl;
 obb2.display(ob2);
 cout<<endl;
 cout<<"two's complement of given number is"<<endl;
 obb2.two(ob2);
 cout<<endl;
// obb2.display(ob2);
 break;
 }

case 4:
  {
   
   cout << "Enter first binary no" << endl;
				obb1.insert(ob1);
    	   			obb1.create(ob1);
				obb1.rev(ob1);
    	   			obb1.display1(ob1);

    	   			cout << "Enter second binary no" << endl;
    	   			obb2.insert(ob2);
    	   			obb2.create(ob2);
				obb2.rev(ob2);
    	   			obb2.display1(ob2);


    	   			cout << "Addition is..." << endl;
    	   			obb3 = obb1.add(obb2);

    	   			//obb3.display2();
                    break;

  }
  }
  cout<<"enter 0 to continue"<<endl;
  cin>>n;
  cout<<endl;
 }
  while(n==0);
 return 0;
}

 /*
    
    node *x=head;
   node *y=n1->head;
    bool c=0;
    while(x->next!=NULL)
     {
      x=x->next;
     }
    
      while(y->next!=NULL)
     {
      y=y->next;
     }
     
     while(x!=NULL && y!=NULL)
      {
         if(c==0)
            {
             if(x->b==0 && y->b==0)
               {x->b=0;c=0;}
             if(x->b==1 && y->b==0)
               {x->b=1;c=0;}
             if(x->b==0 && y->b==1)
               {x->b=1;c=0;}
             if(x->b==1 && y->b==1)
               {x->b=0;c=1;}
               break;
            }
            else
            if(c==1)
            {
             if(x->b==0 && y->b==0)
               {x->b=1;c=0;}
             if(x->b==1 && y->b==0)
               {x->b=0;c=1;}
             if(x->b==0 && y->b==1)
               {x->b=0;c=1;}
             if(x->b==1 && y->b==1)
               {x->b=1;c=1;}
               break;
            }
    
    
      x=x->prev;
      y=y->prev;

      }
     while(x!=NULL)
     {
      if((c==1)&&(x->b==1))
          {
            x->b=0;c=1;
       
           }
         else if((c==1) &&(x->b==0))
            {
            x->b=1;c=0;
             
            }
          else 
          if(c==0)
            
            {
             break;
            }
    
       x=x->prev;
      }
       while(y!=NULL)
     {
      if((c==1)&&(y->b==1))
          {
            x->b=0;c=1;
       
           }
         else if((c==1) &&(y->b==0))
            {
            x->b=1;c=0;
             
            }
          else 
          if(c==0)
            
            {
             break;
            }
    
       y=y->prev;
         
       }*/
         
    
