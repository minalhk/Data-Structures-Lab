
#include<iostream>
using namespace std;
const int MAX=20;
class stack
{
 char a[MAX];//for string input
 char b[MAX];//for stack array
 int top,i;
 public:
 stack()
  {
   top=-1;
   i=0;
  }
  bool empty()
   {
    if(top==(-1))
    {
    return 1;
    }
    else
    {
    return 0;
    }
   }
  bool full()
   {
    if(top==(MAX-1))
    {
    cout<<"stack is full"<<endl;
    return 1;
    }

    else
    {
    return 0;
    }
   }
   void display()
   {
    if(top==(-1))
     {
      cout<<"stack is empty"<<endl;
     }
     else
     {
       for(i=0;i<top;i++)
         {
          cout<<b[i]<<" ";
         }
     }
   }

  void push(char ch)
  {
	if(!full())
	{
		top++;
		b[top]=ch;
	}
  }
  char pop()
  {

	if(top!=(-1))
	{
		char ch=b[top];
		top--;
		return ch;
	}
	else
	{
		return '\0';
	}

  }
  void input()
  {

   cout<<"Enter # after expression at the end"<<endl;;
   cout<<"Enter Expression: "<<endl;
    cin.getline(a,MAX,'#');
   }

  void parenthesis()
  {

	  char c;
	     bool flag=0;
	     for(i=0;a[i]!='\0';i++)
	  	{

	  		if(a[i]=='(' || a[i]=='[' || a[i]=='{')
	  			{
	                           push(a[i]);
	            }

	  		if(a[i]==')'||a[i]==']'||a[i]=='}')
	  				{
	  					c=pop();
	  					if((a[i]==')'&& c!='(') ||(a[i]==']'&& c!='[')||(a[i]=='}'&& c!='{'))
	  					{
	  						cout<<"\nNot parenthesized At index   "<<i<<"     =    "<<a[i]<<endl;
	  						flag=1;
	  						break;
	  					}

	  		               }





  }
	     if((top==(-1)) && (flag==0))
	     		{
	                      cout<<"Expression is well parenthesized."<<endl;
	                     }
	     	else
	     		{
	                     cout<<"Expression is not Well parenthesized."<<endl;
	                     }
  }

};

int main()
{
int n;

 do
  {
   stack s;
   s.input();
   s.parenthesis();
   cout<<"press 0 to continue"<<endl;
   cin>>n;
  }
  while(n==0);




return 0;
}
