#include <iostream>
using namespace std;

struct node{
	bool data;
	node *prev;
	node *next;
};

class theatre{
	node *head[10];
	node *t;
	int r,s,n;
	//node[7] *temp=new node;
	public:
	theatre()
	{
		t=NULL;
		int i=0;
		do{
			head[i]=NULL;
			i++;
			
		}while(i<10);
	}
	void create()
	{	
		int j=0;
		while(j<10){
		for(int i=0;i<8;i++)
		{
			//t=head[j];
			node *temp=new node;
			temp->data=0;
			temp->prev=NULL;
			temp->next=NULL;
			if(head[j]==NULL)
			{
				head[j]=temp;
				//t=temp;
				temp->prev=head[j];
				temp->next=head[j];
			}
			else //if(head[j]!=NULL)
			{
				t=head[j];
				do
				{
					t=t->next;
				}while(t->next!=head[j]);
				t->next=temp;
				temp->prev=t;
				temp->next=head[j];
				head[j]->prev=temp;
			}
		}
		 j++;
		}
	}
	
	void display()
	{
		int j=0;
		while(j<10){
			cout<<"\nrow "<<j+1<<"-\t";
			t=head[j];
			do
			{
				cout<<"\t"<<t->data;
				t=t->next;
				
			}while(t->next!=head[j]);
		        
			j++;
		}
	}
	
	int book()
	{
		
		//int r,s,n;
		label1:
		cout<<"\nenter row(from 1 to 10)and seat(from 1 to 7)and number of seats to be booked"<<endl;
		cin>>r>>s>>n;
		if(r<1||r>10||s<1||s>7)
		{
			cout<<"please enter right values"<<endl;
			goto label1;
		}
		else
		{
			t=head[r-1];
			
			for(int i=0;i<(s-1);i++)
			{
				t=t->next;
			}
			
			node *p;
			p=t;
			for(int i=0;i<n;i++)
			{
				if(p->data==0)
				{
					p=p->next;
				}
				
				else if(t->prev->data==0)
				{
					t=t->prev;
				}
				else
				{
					if((s+i)<8)
					{
						cout<<s+i<<"\tseat is already booked"<<endl;
						return 0;
					}
					else
					{
						cout<<i<<"\tseat is already booked"<<endl;
						return 0;
					}
				}
				
			}
			for(int i=0;i<n;i++)
			{
				
				t->data=1;
				t=t->next;
			
				if(t==head[r-1])
				 	i--;
				 
			}
		}
		cout<<"\n"<<n<<"\tseats are booked"<<endl;
		display();
	}
	
	int cancel()
	{
		//int r,s,n;
		label2:
		cout<<"\nenter row(from 1 to 10)and seat(from 1 to 7)and number of seats to be cancelled"<<endl;
		cin>>r>>s>>n;
		if(r<1||r>10||s<1||s>7)
		{
			cout<<"please enter right values"<<endl;
			goto label2;
		}
		else
		{
			t=head[r-1];
			for(int i=0;i<(s-1);i++)
			{
				t=t->next;
			}
			int count=0;
			for(int i=0;i<n;i++)
			{
				if(t->data!=1)
				{
					cout<<"seat "<<i+1<<" is vacant already"<<endl;
					count++;
				}	
				else
				{
					t->data=0;
					
					t=t->next;
				
				}	
			}
			n=n-count;
			cout<<"\n"<<n<<"\tseats are cancelled"<<endl;
			//display();
			
			
		}
		display();			
	}
	 

};


main()
{
	theatre th;
	th.create();
	th.display();
	char s;
	do{
	cout<<"\nenter 1 to book the ticket\nenter 2 to cancel the booking\nenter 3 to display"<<endl;
	int x;
	label3:
	cin>>x;
	switch(x)
	{
		case 1:
			th.book();
			break;
		case 2:
			th.cancel();
			break;
		case 3:
			th.display();
			break;
		default:
			cout<<"\nenter right choice"<<endl;
			goto label3;	
				
	}
	cout<<"\nenter y to continue else enter n"<<endl;
		cin>>s;	
	}	
	while(s=='y');
	

}
