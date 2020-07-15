#include <iostream>
using namespace std;
class str{
char s[100];
int i,length,j;
public:
int choice;
void storeStr(){
	cout<<"\nEnter the string"<<endl;
	cin>>s;
	for(i=0;s[i]!='\0';i++);
	length=i;
}
void displayStr(){
	cout<<"\nThe string is "<<s<<endl;
}
void lengthdisp(){
	for(i=0;s[i]!='\0';i++);
	cout<<"\nLength of string is "<<i<<endl;
	length=i;
}
void copy(){
	str s2;
	for(i=0;i<length;i++)
	{
		s2.s[i]=s[i];
	}
	s2.s[length]='\0';
	cout<<"The string is copied. "<<s2.s;
}
void concatenate(){
	str s2;
	s2.storeStr();
	str s3;
	s3.length=length+s2.length;
	for(i=0;i<=s3.length;i++)
	{	if(i<length)
		{
			s3.s[i]=s[i];
		}
		else{
			s3.s[i]=s2.s[i-length];
			
		}
	}
	s3.displayStr();

}
void reverse(){
	str s2;
	for(i=0;i<length;i++)
	{
		s2.s[i]=s[length-i-1];
	}
	s2.s[i]='\0';
	s2.displayStr();
}
void substring(){
	str s2;
	s2.storeStr();
	int cnt=0;
	if(s2.length>length)
	{
		cout<<"Substring does not exist"<<endl;
	}
	else
	{	
		for(i=0;i<=length-s2.length;i++)
		{	int count=0;
			for(j=0;j<s2.length;j++)
			{
				if(s[i+j]==s2.s[j])
				{
					count++;
				}
			}

			if(count==s2.length)
			{	cnt++;
				cout<<"Substring exists at index "<<i+1;
			}
		}
			if(cnt==0)
			{
				cout<<"Substring does not exist"<<endl;
			}
		
	}
}
void equal(){
	str s2;
	s2.storeStr();
	if(s2.length!=length)
	{
		cout<<"Strings are not equal"<<endl;
	}
	else
	{	int count=0;
		for(i=0;i<length;i++)
		{
			if(s2.s[i]==s[i])
			{
				count++;
			}
		}
		if(count==length)
		{
			cout<<"Strings are equal"<<endl;
		}
		else
		{
			cout<<"strings are not equal"<<endl;
		}
	}
}
void palindrome(){
	int count=0;
	for(i=0;i<length;i++)
	{
		if(s[i]==s[length-i-1])
		{
			count++;
		}
	}
	if(count==length)
	{
		cout<<"String is palindrome"<<endl;
	}
	else
	{
		cout<<"String is not a palindrome"<<endl;
	}

	
}
void freq(){
	char p;
	int count=0;
	cout<<"Enter the character whose frequency is to be determined"<<endl;
	cin>>p;
	for(i=0;i<length;i++)
	{
		if(s[i]==p)
		{
			count++;
		}
	}
	cout<<"The character "<<p<<" appears "<<count<<" number of times"<<endl;
}
void chardelete(){
	char p;
	str s2;
	int count=0;
	cout<<"Enter the character which is to be deleted"<<endl;
	cin>>p;
	for(i=0;i<length;i++)
	{
		if(s[i]==p)
		{
			count++;
		}
	}
	j=0;
	for(i=0;i<length;i++)
	{	
		if(s[i]!=p)
		{
			s2.s[j]=s[i];
			j++;
		}
	}
	s2.s[length-count]='\0';
	s2.displayStr();
}
void del(){
	int start,len;
	cout<<"Enter the start and number of integers to be deleted"<<endl;
	cin>>start>>len;
	if(length<start+len-1)
	{
		cout<<"Operation not valid since length falls short"<<endl;
	}
	else
	{
		str s2;
		for(i=0;i<start-1;i++)
		{
			s2.s[i]=s[i];
		}
		j=start-1;
		for(i=start+len-1;i<length;i++)
		{
			s2.s[j]=s[i];
			j++;
		}
		s2.s[length-len]='\0';
		s2.displayStr();
	}
}
void replace(){
	str s2,s3,s4;
	cout<<"Enter the substring"<<endl;
	s2.storeStr();
	cout<<"Enter the string which will replace the substring"<<endl;
	s3.storeStr();
	int cnt=0;
	if(s2.length>length)
	{
		cout<<"Substring does not exist"<<endl;
	}
	else
	{	
		for(i=0;i<=length-s2.length;i++)
		{	int count=0;
			for(j=0;j<s2.length;j++)
			{
				if(s[i+j]==s2.s[j])
				{
					count++;
				}
			}
			if(count==s2.length)
			{	cnt++;
				int start=i;
				int len=s3.length;
				for(i=0;i<start;i++)
				{
					s4.s[i]=s[i];
				}
				j=0;
				for(i=start;i<start+len;i++)
				{
					s4.s[i]=s3.s[j];
					j++;
				}
				j=start+len;
				for(i=start+len;i<length;i++)
				{
					s4.s[j]=s[i];
					j++;
				}
				s4.s[length-s2.length+len]='\0';
				s4.displayStr();
				
				
			}
		}
			if(cnt==0)
			{
				cout<<"Substring does not exist"<<endl;
			}
		
	}
}
	
	
	

					
};
int main(){
char p;
str s1;
s1.storeStr();
s1.displayStr();
s1.lengthdisp();

do{
	cout<<"\nEnter 1 concatenate two strings.\nEnter 2 to reverse a string.\nEnter 3 to find a substring.\nEnter 4 to check whether two strings are equal.\nEnter 5 to find whether a string is a palindrome.\nEnter 6 to find the frequency of a character.\nEnter 7 to delete a specific character.\nEnter 8 to delete a substring starting at a specific index and of a specific length\nEnter 9 to replace a substring with another string.\nEnter 10 to copy the string "<<endl;
	cout<<"\n enter your choice"<<endl;
	cin>>s1.choice;
	switch(s1.choice)
{
 case 1:{s1.concatenate();
	break;}
case 2 : {s1.reverse();
	break;}
case 3 : {s1.substring();
	break;}
case 4: {s1.equal();
	break;}
case 5 : {s1.palindrome();
	break;}
case 6 :{s1.freq();
	break;}
case 7:{s1.chardelete();
	break;}
case 8:{s1.del();
	break;}
case 9: {s1.replace();
	break;}
case 10:{s1.copy();
	break;}
default:
    cout<<"enter right choice"<<endl;	
}
cout<<"\nDo you want to continue. Enter y or n";
	cin>>p;
	}while(p=='y');	
}
