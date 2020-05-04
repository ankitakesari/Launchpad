// find HCF of N numbers

#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;
	}

	return gcd(b, a%b);
}

int main() {
	int n;
	cin>>n;
	int arr[n];

	for(int i=0 ; i<n ;i++){
		cin>>arr[i];
	}

	int result= arr[0];

	for(int i=1; i<n ;i++){
		result= gcd(arr[i],result);
	}

	cout<<result;
	return 0;
}
