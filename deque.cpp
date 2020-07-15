#include<iostream>
#define MAX 10
using namespace std;

class deque{
	int f,r,count;
	int q[MAX];
	
	public:
		deque(){
			f=r=-1;
			count=0;
		}
	
		bool empty(){
			if(r==-1)
			   return 1;
			return 0;   
		}
		
		bool full(){
			if((r+1)%MAX==f)
				return 1;
			return 0;	
		}
		
		int enquef(int x){
			if(full()){
			   cout<<"queue is full already(overflow condition)"<<endl;
			   return 0;
			}
			else{
				if(empty()){
					r=f=0;
					count++;
					q[f]=x;
				}
				else{
					f=(f-1+MAX)%MAX;
					q[f]=x;
					count++;
				}
			}
		}
		int enqueR(int x){
			if(full()){
				cout<<"queue is full already(overflow condition)"<<endl;
				return 0;
			}
			else{
				if(empty()){
					r=f=0;
					count++;
					q[f]=x;
				}
				else{
					int i;
					count++;
					i=(r+1)%MAX;
					q[i]=x;
					r=(r+1)%MAX;
					
				}
			}
		}
		
		int dequef(){
			if(empty()){
				cout<<"queue is empty already(underflow condition)"<<endl;
				return 0;
			}
			else{
				if(f==r){
				   f=r=-1;
				   count--;
				}
				else{
				   f=(f+1)%MAX;	
				   count--;
				}
			}
		}
		
		int dequeR(){
			if(empty()){
				cout<<"queue is empty already(underflow condition)"<<endl;
				return 0;
			}
			else{
				if(f==r){
				   f=r=-1;
				   count--;
				 }  
				else{
				  r=(r-1)%MAX;
				  count--;
				}   
			}
		}
		
		int size(){
			return count;
		}
		
		int display(){
			if(empty()){
				cout<<"queue is empty.. no queue to display"<<endl;
				return 0;
			}
			else{
				int i;
				i=f;
				while(i!=r){
					cout<<q[i]<<" ";
					i=(i+1)%MAX;
				}
				cout<<q[i]<<endl;
			}
		}
};

int main(){
	deque q;
	int x;char c;
	do{
		cout<<"1)Enqueuq elements from front\n2)Enqueue elements from rear\n3)Deque elements from front\n4)Dequeue elements from rear\n5)To display size of the queue\n6)Display queue"<<endl;
		cin>>x;
		switch(x){
			case 1:{
				int z;
				cout<<"enter element to be added"<<endl;
				cin>>z;
				q.enquef(z);
			      	
			      }
				break;
			case 2:
		           {
		           	int z;
		           	cout<<"enter element to be added"<<endl;
				cin>>z;
				q.enqueR(z);
			      	
		           }
		           break;
		        case 3:
		           q.dequef();
		           break;
		        case 4:
		           q.dequeR();
		           break;
		        case 5:
		            cout<<"size of the queue is "<<q.size()<<endl;  
		            break;
		        case 6:
		            q.display();
		            break;     
		        default:
		           cout<<"enter right choice"<<endl;         	
		}
		cout<<"enter y to continue...."<<endl;
		cin>>c;
	}while(c=='y');
}
