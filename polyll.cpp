#include<iostream>
using namespace std;

struct node{
	float coeff;
	int deg;
	node *next;
};
class Polynomial{
	node *head,*t;
	int n;
	public:
	   Polynomial(){
	       head=NULL;
	       t=NULL;
	       n=0;
	       
	   }
	   
	  void createpoly(){
	  
	   	int d=0;float c=0.0;
	   	cout<<"\nenter number of non zero terms in the polynomial"<<endl;
	   	cin>>n;
	   	cout<<"\nenter polynomial in descending order of there degree"<<endl;
	   	for(int i=0;i<n;i++){
	   		cout<<"enter degree:\t";
	   		cin>>d;
	   		cout<<"\nenter coeff:\t";
	   		cin>>c;
	   		node *temp=new node;
	   		temp->coeff=c;
	   		temp->deg=d;
	   		
	   		if(head==NULL){
	   			head=temp;
	   			temp->next=head;
	   		}
	   		else{
	   			t=head;
	   			while(t->next!=head){
	   				t=t->next;
	   			}
	   			t->next=temp;
	   			temp->next=head;
	   		}
	   		
	   	}
	   	display();
	   }
	void display(){
		t=head;
		  
		do{
		     cout<<"+"<<t->coeff<<"x^"<<t->deg<<" ";
		     t=t->next;     
		
		}while(t!=head);
		
	}	
	int ans(node *temp,int x){
		int val=1;
		for(int i=0;i<temp->deg;i++)
		{
			val=val*x;
		}
		return val;
	}
	void evaluate(){
		cout<<"enter value to evaluate polynomial"<<endl;
		int x;
		cin>>x;
		float answer=0.0;
		t=head;
		do{
			answer=answer+(t->coeff*ans(t,x));
			t=t->next;
		} while(t!=head);
		
		cout<<"value after evaluation:\t"<<answer;
	}
	
	void addition(){
		Polynomial p2;
		p2.createpoly();
		t=head;
		p2.t=p2.head;
		cout<<endl;
		if(n==p2.n){
			do{
				if(t->deg==p2.t->deg){
					cout<<"+"<<((t->coeff)+(p2.t->coeff))<<"x^"<<t->deg<<" ";
					t=t->next;
					p2.t=p2.t->next;
				}
				else if(t->deg > p2.t->deg){
					cout<<"+"<<t->coeff<<"x^"<<t->deg<<" ";
					t=t->next;
				}
				else{
					cout<<"+"<<p2.t->coeff<<"x^"<<p2.t->deg<<" ";
					p2.t=p2.t->next;
				}
			}while(p2.t!=p2.head);
		}
	}
		
};


int main(){
	Polynomial p1;
	p1.createpoly();
	//p1.evaluate();
	cout<<endl;
	p1.addition();
	cout<<endl;
	p1.display();
}

