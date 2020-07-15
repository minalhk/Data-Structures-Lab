#include<iostream>
using namespace std;
float average(int n,int *a);
int maxmin(int n,int *a);
int highest(int n,int *a);
int absent(int n,int *a);

int main()
{	int n,i,choice=0;
	cout<<"Enter the no. of students"<<"\n";
	cin>>n;
	int b[n];
	cout<<"Enter the marks of the student and if student is absent enter negative marks"<<"\n";
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	cout<<"Enter 1 to find average of the students"<<endl;
	cout<<"Enter 2 to find max and min of the marks"<<endl;
	cout<<"Enter 3 to find marks scored by maximum number of students"<<endl;
	cout<<"Enter 4 to find number of absent sudents"<<endl;
	while(true)
{	
	cout<<"Enter your choice"<<endl;
	cin>>choice;
	switch(choice)
{
	case 1:
		average(n,b);
		break;
		
	case 2:	maxmin(n,b);
		break;
		
	case 3:highest(n,b);
		break;
		
	case 4:absent(n,b);
		break;
		
	default : cout<<"invalid choice";
		break;
}
	cout<<"Do you want to continue if yes enter Y and if no enter N"<<endl;
	char input;
	cin>>input;
	if(input=='Y')
	{ continue;}
	if(input=='N')
	{ break;}
}
}
float average(int n,int *a)
{	int i,count=0;
	float sum=0;
	for(i=0;i<n;i++)
	{	if(a[i]>0)
		sum=sum+a[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>0)
		{  count++;
		}
	}
	float ag=sum/count;
	cout<<"Average of students is "<<"\t"<<ag<<"\n";
}
int maxmin(int n,int *a)
{	
	int i;
 	int max=a[0];
	int min=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{ max=a[i];}
		
	}
	for(i=0;i<n;i++)
	{	if(a[i]>=0)
		if(a[i]<min)
		{ min=a[i];}
		
	}
	cout<<"Max marks are"<<"\t"<<max<<endl;
	cout<<"Min marks are"<<"\t"<<min<<endl;
}
int highest(int n,int *a)
{
	int i,j;
	int freq[n];
	for(i=0;i<n;i++)
	{
		freq[i]=-1;
	}
	for(i=0;i<n;i++)
	{ int count=1;
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{	count++;
				freq[j]=0;
			}
		}
	if(freq[i]!=0)
	{	freq[i]=count;
	}
	}
	int max=-1;
	for(i=0;i<n;i++)
	{ 
		if(freq[i]>max)
		max=freq[i];
	}
	for(i=0;i<n;i++)
	{	
		
		if(freq[i]==max)
		{
		cout<<"Marks scored by maximum no. of students="<<"\t"<<a[i]<<endl;
		
		}
		
	}
	
}
int absent(int n,int *a)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{ if(a[i]<0)
		{	count++;
                        cout<<"absent roll no"<<i+1<<endl;
		}
	}
	cout<<"Number of students absent for the test="<<"\t"<<count<<endl;
}








	

























