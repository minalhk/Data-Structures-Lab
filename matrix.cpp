#include<iostream>
using namespace std;

//multiplication of matrices
int mul()
{
	 int row1,col1,row2,col2,i,j,k;
	cout<<"enter no of rows and columns of matrix 1 "<<endl;
	cin>>row1>>col1;
	cout<<"enter no of rows and columns of matrix 2"<<endl;
	cin>>row2>>col2;
	if(col1==row2)
	{
		int a[row1][col1],b[row2][col2];
		cout<<"enter elements of first matrix row wise"<<endl;
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				cout<<"enter element of a"<<i+1<<j+1<<":"<<endl;
				cin>>a[i][j];
			}
		}
		
		cout<<"enter elements of second matrix row wise"<<endl;
		for(i=0;i<row2;i++)
		{
			for(j=0;j<col2;j++)
			{
					cout<<"enter element of b"<<i+1<<j+1<<":"<<endl;
				cin>>b[i][j];
			}
		}	
		int sum[row1][col2];
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				sum[i][j]=0;
			}
		}
		for(i=0;i<row1;i++)
		{
			for(k=0;k<col2;k++)
			{
				for(j=0;j<col1;j++)
				{
					sum[i][k]=sum[i][k]+(a[i][j]*b[j][k]);
				}
			}
		}
		cout<<"multiplication is"<<endl;
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				cout<<"\t"<<sum[i][j];
			}
			cout<<"\n";
		}
		
	}
	else
	{
	
	 cout<<"columns of matrix 1 and rows of matrix 2 are not equal"<<endl;
    }
}


//addition of matrices
int add()
{
int row1,col1,row2,col2,i,j,k;
	cout<<"enter no of rows and columns of matrix 1 "<<endl;
	cin>>row1>>col1;
	cout<<"enter no of rows and columns of matrix 2"<<endl;
	cin>>row2>>col2;
	if(row1==row2&&col1==col2)
	{
	  	int a[row1][col1],b[row2][col2];
		cout<<"enter elements of first matrix row wise"<<endl;
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				cout<<"enter element of a"<<i+1<<j+1<<":"<<endl;
				cin>>a[i][j];
			}
		} 
		cout<<"enter elements of second matrix row wise"<<endl;
		for(i=0;i<row2;i++)
		{
			for(j=0;j<col2;j++)
			{
				
					cout<<"enter element of b"<<i+1<<j+1<<":"<<endl;
				cin>>b[i][j];
			}
		}	
	   int sum[row1][col1];
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				sum[i][j]=0;
			}
		}
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				sum[i][j]=a[i][j]+b[i][j];
			}
		} 
		cout<<"addition is"<<endl;
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				cout<<"\t"<<sum[i][j];
			}
			cout<<"\n";
		}
			   	
	}	
	else
	cout<<"number of rows and columns are not equal of the two matrices"<<endl;
}



//subtraction of matrices
int sub()
{
int row1,col1,row2,col2,i,j,k;
	cout<<"enter no of rows and columns of matrix 1 "<<endl;
	cin>>row1>>col1;
	cout<<"enter no of rows and columns of matrix 2"<<endl;
	cin>>row2>>col2;
		if(row1==row2&&col1==col2)
	{
	  	int a[row1][col1],b[row2][col2];
		cout<<"enter elements of first matrix row wise"<<endl;
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
			cout<<"enter element of a"<<i+1<<j+1<<":"<<endl;
				cin>>a[i][j];
			}
		} 
		cout<<"enter elements of second matrix row wise"<<endl;
		for(i=0;i<row2;i++)
		{
			for(j=0;j<col2;j++)
			{	
	         	cout<<"enter element of b"<<i+1<<j+1<<":"<<endl;
				cin>>b[i][j];
			}
		}	
	   int sub[row1][col1];
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				sub[i][j]=0;
			}
		}  
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				sub[i][j]=a[i][j]-b[i][j];
			}
		} 
		cout<<"subtraction is"<<endl;
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				cout<<"\t"<<sub[i][j];
			}
			cout<<"\n";
		}
   }
    else
	cout<<"number of rows and columns of the two matrices is not equal"<<endl;	
	
}



//transpose of matrix
int trans()
{
	int row,col,i,j;
    cout<<"enter no of rows and columns"<<endl;
    cin>>row>>col;
    int a[row][col];
    cout<<"enter elements of  matrix row wise"<<endl;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<"enter element of a"<<i+1<<j+1<<":"<<endl;
				cin>>a[i][j];
			}
		}
		
	int t[col][row];
       for(i=0;i<row;i++)
         { 
             for(j=0;j<col;j++)
              {
                  t[j][i]=a[i][j];
              }    
         }
      cout<<"transpose matrix is"<<endl;
       for(i=0;i<col;i++)
         {
            for(j=0;j<row;j++)
             {
                   cout<<"\t"<<t[i][j];   
              }
          cout<<"\n";
         }

}



//sum of diagonal elements
int diag()
{
	int d=0;
		int row,col,i,j;
    cout<<"enter no of rows and columns"<<endl;
    cin>>row>>col;
    if(row==col)
    {
	
    int a[row][col];
    cout<<"enter elements of  matrix row wise"<<endl;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<"enter element of a"<<i+1<<j+1<<":"<<endl;
				cin>>a[i][j];
			}
		}
        for(i=0;i<row;i++)
         {
            d=d+a[i][i];
          }
        cout<<"sum of diagonal elements is"<<d<<endl;

     }
    else
    {
    	cout<<"for addition of diagonal elements number of rows and columns should be equal"<<endl;
	}

	
}

//to check wheather a matrix is upper triangular or not
int uppertri()
{
   int n,i,j;
   cout<<"enter dimension of square matrix"<<endl;
   cin>>n;
   int a[n][n];	
    cout<<"enter elements of  matrix row wise"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<"enter element of a"<<i+1<<j+1<<":"<<endl;
				cin>>a[i][j];
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
               if(a[i][j]!=0)
               {
			   
                  cout<<"matrix is not upper triangular matrix"<<endl;
                  return 0;
               }
           }
       }
	  cout<<"matrix is  upper tringular"<<endl;  
      

}

//to check saddle point
int saddle()
{
	int row,col;
    cout<<"enter no of rows and columns"<<endl;
    cin>>row>>col;
    int a[row][col];
    cout<<"enter elements of  matrix row wise"<<endl;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				cout<<"enter element of a"<<i+1<<j+1<<":"<<endl;
				cin>>a[i][j];
			}
		}	
	
	/*int currcol=0;
	for(i=0;i<row;i++)
	{
		int min=a[i][0];
		for(j=0;j<col;j++)
		{
		   if(min>a[i][j])
            {
			  min=a[i][j];
			  currcol=j;
			  
		    }
	    }
	    for(int k=0;k<row;k++)
	    {
	    	if(min<a[k][currcol])
            {
			     cout<<"no saddle point found"<<endl;
			     return 0;
		    }	
		    if(k==row-1)
		    {
		         cout<<"saddle point is"<<min;	
			}
	    }
   }*/
   int small[row],big[col],max,min;
   for(int i=0;i<row;i++)
   {
   	   small[i]=a[i][0];
   	    for(int j=0;j<col;j++)
   	    if(a[i][j]<small[i])
   	     small[i]=a[i][j];
   }
   for(int j=0;j<col;j++)
   {
   	big[j]=a[0][j];
   	for(int i=0;i<row;i++)
   	  if(a[i][j]>big[j])
   	  big[j]=a[i][j];
   }
   min=big[0];
   for(int i=0;i<row;i++)
      if(big[i]<min)
      min=big[i];
    max=small[0];
	for(int j=0;j<col;j++)
	 if(small[j]>max)
	   max=small[j];
	if(max==min)
	  cout<<"saddle point is-\t"<<min<<endl;
	else
	  cout<<"saddle point not found"<<endl;       
}

//main
int main()
{
    int ch;
    char x;
	cout<<"enter 1 for addition of matrix\nenter 2 for subtraction of matrix\nenter 3 for multilication of matrix\nenter 4 to find transpose of the matrix\nenter 5 to find sum of diagonal elements\nenter 6 to check wheather matrix is upper triangular or not\nenter 7 to find saddle point"<<endl;
	do
	{
	cout<<"enter your choice"<<endl; 	
	cin>>ch;
	switch(ch)
	{
		case 1:
			add();
			break;
		case 2:
		    sub();
			break;
		case 3:
		    mul();
			break;
		case 4:
		    trans();
			break;
		case 5:
			diag();
			break;
		case 6:
		    uppertri();
			break;
		case 7:
			saddle();
			break;
		default :
		   cout<<"enter right choice"<<endl;	 				
	 } 
	 cout<<"enter Y to continue else enter N"<<endl;
	 cin>>x;
}while(x=='Y');
	return 0;
}
