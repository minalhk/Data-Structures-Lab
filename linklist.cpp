//link list
#include<iostream>
using namespace std;


struct node
{
	int prn;
	string name;
	node *next;
};

class linklist{
	int count;
	

public:
	node *head,*t;
	linklist()
	{
		head=NULL;
		t=NULL;
		count=0;
	}
	

	void create()
	{
		label1:
		count++;
		node *temp=new node;
		t=head;
		
		cout<<"enter PRN number and name"<<endl;
		int n;string str;
		cin>>n>>str;
		temp->prn=n;
		temp->name=str;
		temp->next=NULL;
		
		
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			while(t->next!=NULL)
			{
				t=t->next;

			}		
			t->next=temp;
		}	
		cout<<"enter y to add node else enter n"<<endl;
		char x;
		cin>>x;
		if(x=='y')
		    {goto label1;}
		else
			display();	
		
	}

	void display()
	{
		if(head==NULL)
    		{
			cout<<"list is empty"<<endl;
		}
		else
		{
			cout<<"entered list is"<<endl;
			t=head;
		
			while(t->next!=NULL)
			{
				cout<<t->prn<<"\t"<<t->name<<endl;
				t=t->next;
			}
			cout<<t->prn<<"\t"<<t->name<<endl;
		}
	}
	

	void listcount()
	{
		
		if(count==0)
		{
			cout<<"list is empty"<<endl;
		}
		else
		{
			cout<<"no of nodes in the list=\t"<<count<<endl;
		}
	}
	
	int insert()
	{
		cout<<"enter position at which you want to insert a node"<<endl;
		int pos;
		cin>>pos;
		//if list is smaller than the position given
		if(pos>(count+1)||pos<1)
		{
			cout<<"please enter right position "<<endl;
			return 0;
		}
		t=head;
		node *temp=new node;
		cout<<"enter PRN number and name"<<endl;
		int n;string str;
		cin>>n>>str;
		temp->prn=n;
		temp->name=str;
		temp->next=NULL;
		//insreting node at begining
		if(pos==1)
		{
			if(head==NULL)
			{
				head=temp;
			
				count++;	
			}
			else{
				head=temp;
				temp->next=t;
				count++;
				cout<<"after inserting a node ";
				
				
			}
			
			display();
		}
		
		//inserting node at last
		else if(pos==(count+1))
		{
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->next=temp;
			count++;
			cout<<"after inserting a node ";
			
				display();
		}
		//inserting node at any given position
		else
		{
			for(int i=1;i<(pos-1);i++)
			{
				t=t->next;	
			}
			temp->next=t->next;
			t->next=temp;
			count++;
			cout<<"after inserting a node ";
				display();
		}
		
	}
	int deleteNode()
	{
		cout<<"enter position at which node to be deleted"<<endl;
		int pos;
		cin>>pos;
		t=head;	
		if(head==NULL)
		{
			cout<<"list is empty"<<endl;
			return 0;
		}
		else if(pos>count||pos<1)
		{
			cout<<"please enter right position"<<endl;
			return 0;
		}
		
		//deleting first node
		else if(pos==1)
		{
			
			head=head->next;
			delete t;
			
			cout<<"after deleting first node ";
			count--;
			display();
			
		}
		//deleting last node
		else if(pos==count)
		{
			node *t1;
			for(int i=1;i<(pos-1);i++)
			{
				t=t->next;	
			}	
			t1=t->next;
			t->next=NULL;
			delete t1;
			count--;
			cout<<"after deleting the last node ";
			display();
		}
		//deleting node from the given position
		else
		{
			node *t1;
			for(int i=1;i<(pos-1);i++)
			{
				t=t->next;	
			}	
			t1=t->next;
			t->next=t1->next;
			delete t1;
			count--;
			cout<<"after deleting the node ";
			display();	
		}
		
	}
	
	int reverse(node *x)
	{
		if(x==NULL)
		{
			cout<<"list is empty"<<endl;
			return 0;
		}
		else if(x->next!=NULL)
		{
			reverse(x->next);
			
		}
		cout<<x->prn<<"\t"<<x->name<<endl;
	}
	
	int concat(linklist x)
	{
		if(x.head==NULL && head==NULL)
		{
			cout<<"first you have to enter the link list"<<endl;
			return 0;
		}
		else{
			t=head;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->next=x.head;
			//count=count+x.count;
			display();
			
		}
	}
	
	int sort()
	{
		if(head==NULL)
		{
			cout<<"first you have to enter the link list"<<endl;
			return 0;
		}
		else{
			node *t1;
			for(int i=0;i<count;i++){
				t=head;
				t1=t->next;
				for(int j=0;j<count;j++){
					if(t->prn > t1->prn){
						t->next=t1->next;
						t1->next=t;
					}
				}
			}
		}
	}
	
	
};
main()
{
	int z;char x;
	linklist l,l1;
	do{
	cout<<"enter 1 to append the list\nenter 2 to display node\nenter 3 to count no of nodes in the list\nenter 4 to insert a new node\nenter 5 to delete node\nenter 6 to print list in reverse order\nenter 7 to create second link list\nenter 8 to concatenate two link lists\nenter 9 to sort link list"<<endl;

	cin>>z;
	switch(z)
	{
		case 1:
		  l.create();
		  break;
		case 2:
		   l.display();
		   break;
		case 3:
		   l.listcount();
		   break;
		case 4:
		   l.insert();
		   break;   
		case 5:
		   l.deleteNode();   
		   break;
		case 6:
		   l.reverse(l.head);
		   break;   
		case 7:
		   l1.create();   
		   break;
		case 8:
		   l.concat(l1);
		   break;
		case 9:
		   l.sort();
		   break;     
		default:
		   cout<<"enter right choice"<<endl;
	}

	cout<<"if you want to continue enter y else enter n"<<endl;
	cin>>x;
	}while(x=='y');
	

}

