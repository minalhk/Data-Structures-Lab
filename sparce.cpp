//sparce matrix
#include<iostream>
#define MAX 20
using namespace std;

class sparce
{
   int **p;
   int r,c,t;
   public:

  void getdata()
  {
      cout<<"enter number of rows, columns and non zero terms in the sparce matrix:\t"<<endl;
      cin>>r>>c>>t;
       
       p=new int *[t];
      for(int i=0;i<t;i++)
      {
              p[i]=new int [3];

      }
       cout<<"enter row column and the non zero term sequentially"<<endl;
        for(int i=0;i<t;i++)
        {
		label:
		 cin>>p[i][0]>>p[i][1]>>p[i][2];
            
	if(i==0)
        {
        if(p[i][2]==0||p[i][0]<0||p[i][1]<0||p[i][0]>r-1||p[i][1]>c-1)
           	{cout<<"invalid input"<<endl;
              cout<<"enter right input again"<<endl;
		goto label;}
             cout<<"\n";
          }
            
          else if(i>0)
            {
            if(p[i][2]==0|| p[i][0]<0|| p[i][1]<0|| p[i][0]>r-1|| p[i][1]>c-1||p[i-1][0]>p[i][0])
            {cout<<"invalid input"<<endl;
              cout<<"enter right input again"<<endl;
		goto label;}
             cout<<"\n";
          }
        } 

       
       
   }
  void display()
  {
      cout<<"sparce matrix is"<<endl;
      for(int i=0;i<t;i++)
         { 
            cout<<p[i][0]<<"\t"<<p[i][1]<<"\t"<<p[i][2]<<endl;
         }
  }

  void add()
  {
     //int d;
      sparce s2;
     //d=s2.getdata();
    //if(d!=0)
    //{ s2.display();}
     s2.getdata();
     s2.display();
   
   sparce s3;
  if(r==s2.r&&c==s2.c)
   {

    s3.r=r;
    s3.c=c;
   
   int c1=0,c2=0,c3=0,term3=0,count=0;
   term3=t+s2.t;
     /* while(c1<t && c2<s2.t)
       {
              
                   if(p[i][0]==s2.p[j][0]&& p[i][1]==s2.p[j][1])
                    {
                        
                	 count++;
			 
              	     }
                
              i++;
              c1++;
              c2++;
       }*/

    for(int i=0;i<t;i++)
     {
	  for(int j=0;j<s2.t;j++)
          {
             if(p[i][0]==s2.p[j][0]&& p[i][1]==s2.p[j][1])
		{
			count++;
		}
	   }
	}

    term3=term3-count;
   // cout<<"\nterm3,count\t="<<term3<<"\t"<<count<<endl;
 
  s3.t=term3;  
   s3.p=new int *[s3.t];  
    

    for(int i=0;i<s3.t;i++)
      {
              s3.p[i]=new int [3];

      }
    


    /* s3.p=new int *[MAX];
	for(int i=0; i<MAX;i++)
	{
	   s3.p[i]=new int[3];
	}*/

    while(c1<t && c2<s2.t)
	{
	  if(p[c1][0]==s2.p[c2][0] && p[c1][1]==s2.p[c2][1])
	   {
		s3.p[c3][2]=p[c1][2]+s2.p[c2][2];
		c1++;
		c2++;
		c3++;
	   }
          else if(p[c1][0]<s2.p[c2][0])
	   {
		s3.p[c3][0]=p[c1][0];
		s3.p[c3][1]=p[c1][1];
		s3.p[c3][2]=p[c1][2];
		c1++;
		c3++;
	   }
	   else if(p[c1][0]>s2.p[c2][0])
	   {
		s3.p[c3][0]=s2.p[c2][0];
		s3.p[c3][1]=s2.p[c2][1];
		s3.p[c3][2]=s2.p[c2][2];
	         c2++;
	  	 c3++;
           }
	 else if(p[c1][0]==s2.p[c2][0]&&p[c1][1]<s2.p[c2][1])
	   {
		s3.p[c3][0]=p[c1][0];
		s3.p[c3][1]=p[c1][1];
		s3.p[c3][2]=p[c1][2];
		c1++;
		c3++;
	   }
	 else if(p[c1][0]==s2.p[c2][0]&& p[c1][1]>s2.p[c2][1])
	   {
		s3.p[c3][0]=s2.p[c2][0];
		s3.p[c3][1]=s2.p[c2][1];
		s3.p[c3][2]=s2.p[c2][2];
	         c2++;
	  	 c3++;
	   }
	}

     while(c1<t)
	{
	      s3.p[c3][0]=p[c1][0];
		s3.p[c3][1]=p[c1][1];
		s3.p[c3][2]=p[c1][2];
		c1++;
		c3++;	
	}
     while(c2<s2.t)
	{
		s3.p[c3][0]=s2.p[c2][0];
		s3.p[c3][1]=s2.p[c2][1];
		s3.p[c3][2]=s2.p[c2][2];
	         c2++;
	  	 c3++;
	}
     // s3.t=c3;
   cout<<"addition of ";
   s3.display();
   
   }
   else
      cout<<"number of rows and columns of two matrices should be equal"<<endl; 
   }
  



  void fastTrans()
  {
    
     int col_num,location,row,col,term;
     int total[MAX],index[MAX];
	row=r;
	col=c;
	term=t;
     sparce s2;
	s2.r=col;
	s2.c=row;
	s2.t=term;

	s2.p=new int *[MAX];
	for(int i=0; i<MAX;i++)
	{
	   s2.p[i]=new int[3];
	}

	for(int i=0;i<c;i++)
	{
		total[i]=0;
	}
	for(int i=0;i<t;i++)
	{
		col_num=p[i][1];
		total[col_num]++;
	}
	index[0]=1;
	for(int i=1;i<c;i++)
	{
		index[i]=index[i-1]+total[i-1];
	}
	for(int i=0;i<t;i++)
	{
		col_num=p[i][1];
		location=index[col_num];
		index[col_num]++;
		s2.p[location][0]=p[i][1];
		s2.p[location][1]=p[i][0];
		s2.p[location][2]=p[i][2];
	}
     cout<<"fast transpose of the ";
       s2.display();
   }
};

int main()
{
  int choice;
   char x;
  sparce s1,s3;
// c=s1.getdata();
 //if(c!=0)
 //s1.display();
s1.getdata();
s1.display();
 do
 { 
   xyz:
  cout<<"enter 1 to add two sparce matrices\nenter 2 to find transpose of sparce matrix(fast transpose)\nenter 3 to exit"<<endl;
  cin>>choice;
  switch(choice)
  {
    case 1:
         s1.add();
  	 break;
    case 2:
         s1.fastTrans();
          break;
    case 3:
         return 0;
          break;
     default:
        cout<<"enter right choice"<<endl;
          goto xyz;
   }
 
 cout<<"enter y to continue else enter n"<<endl;
  cin>>x;
  }while(x=='y');
  return 0;
}
