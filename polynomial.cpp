#include <iostream>
using namespace std;


int power(int x, int y){
	int ans=1,j;
	for(j=1;j<=y;j++){
		ans *= x;
	}
	return ans;
}
int menu(){
	int choice;

	cout<<"1.Evaluate value of Polynomial for x"<<endl;
	cout<<"2.Add 2 Polynomials"<<endl;
	cout<<"3.Multiply 2 Polynomials"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	return choice;
}

class Polynomial;
class Term{
	float c;
	int exp;
	public:
		Term()
		{
			c = 0.0;
			exp = 0;
		}
		friend class Polynomial;
		friend istream & operator>>(istream &, Polynomial &);
		friend ostream & operator<<(ostream &, Polynomial &);
};

class Polynomial{
	Term *a;
	int n;
	public:
		friend istream & operator>>(istream &, Polynomial &);
		friend ostream & operator<<(ostream &, Polynomial &);
		void eval(int x)
		{
			int i;
			float value=0.0;
			for(i=0;i<n;i++)
			{
				value += a[i].c*power(x, a[i].exp);
				cout<<"Value of polynomial for x="<<x<<" is: "<<value<<endl;
			}
		}

	Polynomial operator+(Polynomial q)
	{
	Polynomial temp;
	int c1=0,c2=0,c3=0,termcount=0;	
	temp.a = new Term[(n+q.n)];
	while(c1<n && c2<q.n){
				if(a[c1].exp == q.a[c2].exp)
				{
					temp.a[c3].exp = a[c1].exp;
					temp.a[c3].c = a[c1].c + q.a[c2].c;
					c3++;
					c2++;
					c1++;
				}
				else if(a[c1].exp < q.a[c2].exp)
				{
					temp.a[c3].exp=q.a[c2].exp;
					temp.a[c3].c=q.a[c2].c;
					c3++;
					c2++;
				}
				else
				{
					temp.a[c3].exp=a[c1].exp;
					temp.a[c3].c=a[c1].c;
					c3++;
					c1++;
				}
					termcount++;
				}
				while(c1<n)
				{
					temp.a[c3].exp=a[c1].exp;
					temp.a[c3].c=a[c1].c;
					c3++;
					c1++;
					termcount++;
				}
				while(c2<q.n)
				{
					temp.a[c3].exp=q.a[c2].exp;
					temp.a[c3].c=q.a[c2].c;
					c3++;
					c2++;
					termcount++;
				}
					temp.n = termcount;
					return temp;
		}
	Polynomial operator*(Polynomial q){
			Polynomial temp,result;
			temp.a = new Term[q.n];
			temp.n = q.n;
			result.n = 0;
			if(n==0 || q.n==0){
				return result;
			}
			int i, j, k=0;
			for(i=0;i<n;i++){
				k=0;
				for(j=0;j<q.n;j++){
					
					temp.a[k].c = a[i].c * q.a[j].c;
					temp.a[k].exp = a[i].exp + q.a[j].exp;
					k++;
				}
				result = result+temp;
			}
			return result;
		}
};

istream & operator>>(istream &in, Polynomial &p){
	int i;
	cout<<"Enter total number of terms in polynomial: ";
	in>>p.n;
	p.a = new Term[p.n];
	cout<<"Enter coefficient and exponent of each term in ascending order of exponent : ";
	for(i=0;i<p.n;i++){
		in>>p.a[i].c>>p.a[i].exp;
	}
	return in;
}

ostream & operator<<(ostream &out, Polynomial &p){
	int i;
	out<<p.a[(p.n-1)].c<<"x^"<<p.a[(p.n-1)].exp;
	for(i=p.n-2;i>=0;i--){
		if(p.a[i].exp == 0 && p.a[i].c>0)
			out<<"+"<<p.a[i].c;
		else if(p.a[i].exp == 0 && p.a[i].c<0)
			out<<p.a[i].c;
		else if(p.a[i].c>0)
			out<<"+"<<p.a[i].c<<"x^"<<p.a[i].exp;
		else
			out<<p.a[i].c<<"x^"<<p.a[i].exp;
	}
	out<<endl;
	return out;
}
int main(){
	Polynomial p,q,result;
	int x,choice;
	cin>>p;
	cout<<"Polynomial 1 is: ";
	cout<<p;
	choice = menu();
	while(choice!=4){
		switch(choice){
			case 1:
				cout<<"Enter value of x for which polynomial to be evaluated: ";
				cin>>x;
				p.eval(x);
				break;
			case 2:
				cin>>q;
				cout<<"Polynomial 2 is: ";
				cout<<q;
				result = p+q;
				cout<<"Addition of 2 Polynomials is: "<<endl;
				cout<<result;
				break;
			case 3:
				cin>>q;
				cout<<"Polynomial 2 is: ";
				cout<<q;
				result=p*q;
				cout<<"Multiplication of 2 Polynomials is: "<<endl;
				cout<<result;
				break;
		}
		choice=menu();
	}
	return 0;
}

