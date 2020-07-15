#include<iostream>
using namespace std;
class poly
{
  //int n1,n2,n3;
  public:
/*  poly(int a,int b,int c)
{
    n1=a;
    n2=b;
    n3=c;
}*/
  void display(float *e,int n)
  {
      cout<<" equation is-"<<endl;
     
       for(int i=0;i<n;i++)
       {
         if(i%2==0&&e[i]>0)
         {
           if(i!=n-2&&e[i+2]>0)
             cout<<e[i]<<"x^"<<e[i+1]<<"+";
           else
             cout<<e[i]<<"x^"<<e[i+1]; 
         }
        if(i%2==0&&e[i]<0)
        {
          if(e[i+2]>0)
            cout<<e[i]<<"x^"<<e[i+1]<<"+";
          else
             cout<<e[i]<<"x^"<<e[i+1];   
         }
       }
   }

  float add(float *a,float *b,float *c,int n,int m,int l)
   {
        if(n==m)
       { for(int i=0;i<n;i++)
        {
               if(i%2==0)
               {
                   if(a[i+1]==b[i+1])
                   {c[i]=a[i]+b[i];
                     c[i+1]=a[i+1];}
                   else if(a[i+1]>b[i+1])
                    {c[i]=a[i];
                       c[i+1]=a[i+1]; }
                   else if(a[i+1]<b[i+1])
                     {c[i]=b[i];
                       c[i+1]=b[i+1];}
               }
        }
       
           cout<<"\nafter addition ";
              display(c,l);
      }    
     if(n>m)
    { for(int i=0;i<l;i++)
         {
               
               if(i%2==0)
               {
                  if(i<m)
                   {
                      if(a[i+1]==b[i+1])
                      { 
                       c[i]=a[i]+b[i];
                       c[i+1]=a[i+1];}
                   else if(a[i+1]>b[i+1])
                    {c[i]=a[i];
                       c[i+1]=a[i+1]; }
                   else if(a[i+1]<b[i+1])
                     {c[i]=b[i];
                       c[i+1]=b[i+1];}
                   }
                  if(i>m)
                  {
                       c[i]=a[i];
                       c[i+1]=a[i+1];    
                      
                   }     
              }

          }
     }
   cout<<"\nafter addition ";
              display(c,l);
}

};
int main()
{
  int no1,no2;

  //accepting equation one
  cout<<"enter no of non zero terms in the eqn1"<<endl;
  cin>>no1;
  int n1;
  n1=no1*2;
  float eqn1[n1];
  cout<<"enter coeff and its degree sequentially with their signs and increasing order of degree of eqn 1"<<endl;
   for(int i=0;i<n1;i++)
   {
      cin>>eqn1[i];
   }
  poly p1,p2,p3;
  p1.display(eqn1,n1);

  //accepting equation 2
  
  cout<<"\nenter no of non zero terms in the eqn2"<<endl;
  cin>>no2;
  int n2;
  n2=no2*2;
  float eqn2[n2];
  cout<<"enter coeff and its degree sequentially with their signs and increasing order of degree of eqn 2"<<endl;
   for(int i=0;i<n2;i++)
   {
      cin>>eqn2[i];
   } 
  p2.display(eqn2,n2);


//addition of two equations
 
   int n3;
   n3=n1+n2;
    float eqn3[n3];
    for(int i=0;i<n3;i++)
    {
        eqn3[i]=0;
    }
        
            p3.add(eqn1,eqn2,eqn3,n1,n2,n3);
     

return 0;
}
 
