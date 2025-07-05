#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int number);

int main(){
	
	cout<<isprime(511);
	cout<<isprime(9);
	cout<<isprime(256);
	
	return 0;
}

bool isprime(int number){
	
	int limit = sqrt(number);
	
	if(number<2)
		return false;
	
	for(int i=2;i<=limit;i++){
		if (number%i==0)
			return false;
	}
	return true;
}