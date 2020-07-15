#include <iostream>
using namespace std;
struct node{
int i;
node *next;
node *prev;
};
class number{
int n1;
node *head;
node *ptr;
node *ptr1;
public:
number(){
	head=NULL;
}
number comp(){
	number n2;
    	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->i==1)
		{
            		n2.insertend(0);
		}
		else{
            		n2.insertend(1);
		}
		ptr=ptr->next;
    	}
	return n2;
}
number comptwo(){
	number n2,n3;
	n2=comp();
	ptr=n2.head;
	ptr1=NULL;
	while(ptr->next!=NULL)
	{
		ptr1=ptr;
		ptr=ptr->next;
	}
	if(this->n1==0)
	{
		n3.insert(0);
	}
	else if(ptr->i==1)
	{
		n3.insert(0);
		while(ptr1->i!=0 && ptr1!=NULL)
		{
			n3.insert(0);
			ptr1=ptr1->prev;
		}
		if(ptr1==NULL)
		{
			n3.insert(1);
		}
		else if(ptr1->i==0)
		{
			n3.insert(1);
			ptr1=ptr1->prev;
			while(ptr1!=NULL)
			{
				n3.insert(ptr1->i);
				ptr1=ptr1->prev;
			}
		}
	}
	else{
		n3.insert(1);
		while(ptr1!=NULL)
		{
			n3.insert(ptr1->i);
			ptr1=ptr1->prev;
		}
	}
	
	return n3;
}
void insertend(int p){
    ptr=new node;
    ptr->i=p;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(head==NULL)
    {
        head=ptr;
    }
    else{
        ptr1=head;
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
        }
        ptr1->next=ptr;
        ptr->prev=ptr1;
    }

}
void display(){
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->i;
		ptr=ptr->next;
	}
	cout<<endl;
}
void insert(int p){
	ptr=new node;
	ptr->i=p;
	ptr->next=NULL;
	ptr->prev=NULL;
	if(head==NULL)
	{
		head=ptr;		
	}
	else{	
		ptr1=head;
		head=ptr;
		head->next=ptr1;
		ptr1->prev=head;
	}
}
void accept()
{	
	int a,j;
	cout<<"Enter the number"<<endl;
	cin>>n1;
	a=n1;
	head=NULL;
	if(n1==0 || n1==1)
	{
		insert(n1);
	}
	else{
	while(a!=0)
	{	
		j=a%2;
		a=a/2;
		if(n1<0)
		{
			insert(-j);
		}
		else{
			insert(j);
		}
	}
	}
	cout<<"The binary number is: " ;
	if(n1>=0){
	display();
	}
	else{
		head=comptwo().head;
		display();
	}
	
}

void add(){
	number n1,n2;
	n2.accept();
	ptr1=n2.head;
	ptr=head;
	int carry=0;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	while(ptr1->next!=NULL)
	{
		ptr1=ptr1->next;
	}
	
	while(ptr!=NULL && ptr1!=NULL)
	{
		
		
		n1.insert((((!ptr->i)&&carry) || ptr->i&&(!carry))&&(!ptr1->i) || (!(((!ptr->i)&&carry) || ptr->i&&(!carry)))&&(ptr1->i));
		carry=((ptr->i==1 && ptr1->i==1) || (ptr->i==1 && carry==1) || (carry==1 && ptr1->i==1));
	ptr=ptr->prev;
	ptr1=ptr1->prev;
}
if(ptr==NULL)
		{	
			while(ptr1!=NULL){
			if(carry==1 && ptr1->i==1){
			n1.insert(0);
			}
			else{
			n1.insert((ptr1->i)+carry);
			}
			if(carry==1 && ptr1->i==1)
			{
				carry=1;	
			}
			else{
				carry=0;
			}
			ptr1=ptr1->prev;
			}
		}
		else if(ptr1==NULL)
		{	while(ptr!=NULL){
			if(carry==1 && ptr->i==1){
			n1.insert(0);
			}
			else{
			n1.insert((ptr->i)+carry);
			}
			if(carry==1 && ptr->i==1)
			{
				carry=1;	
			}
			else{
				carry=0;
			}
			ptr=ptr->prev;
			}
		}	
if(carry==1 && this->n1>=0 && n2.n1>=0)
{
	n1.insert(1);
}
cout<<"The addition is: ";
n1.display();
}
};
int main()
{
	char p;
	int choice;
	number n,n1,n2;
	
    	do{
	cout<<"\nEnter 1 to find 1's complement of a binary number.\nEnter 2 to find 2's complement of a binary number.\nEnter 3 to add two binary numbers.";
	cin>>choice;
	switch(choice)
	{
	case 1 : {
		n.accept();
		cout<<"The 1's complement is: ";
		(n.comp()).display();
		break;}
	case 2 : {
		n1.accept();
		cout<<"The 2's complement is: ";
		(n1.comptwo()).display();
		break;}
	case 3 : {n2.accept();
		n2.add();
		break;}
	}
	cout<<"\nDo you want to continue. Enter y or n";
	cin>>p;
	}while(p=='y');	
}	
