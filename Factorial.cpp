//#include"stdafx.h"
#include"iostream"
#include <algorithm>  
#include <string>

using namespace std;

string Multiply(string pr, int m)
{
  string temp_product;
	int carry=0;
	for(int i=(pr.size()-1); i>=0; i--)
	{
		int pr_elem = pr[i] - '0';
		int prod = (pr_elem * m) + carry;
		temp_product.push_back(prod%10 + '0');
		carry = prod/10;
	}
	while(carry) {
		temp_product.push_back(carry%10 + '0'); 
		carry = carry/10;
	}
	reverse(temp_product.begin(), temp_product.end());
	return temp_product;
}

string factorial(int n)
{
	string product("1");
	if((n==0) || (n==1)) return product;
	for(int i=2; i<=n; i++)
	{
		product = Multiply(product, i);
	}
	return product;

}

int main()
{
	cout<<"Program finds factorial of an integer"<<endl;
	int n(0);
	cout<<"Enter a positive integer"<<endl;
	cin>>n;
	if(n<0) 
		cout << "Enter only positive number"<<endl;
	else
		cout<<factorial(n)<<endl;
	return 0;
}
