
#include <iostream>
using namespace std;

class A{

	public:
		A();
		A(int);
	private:
		int data;
				
};

A::A(){
	data = 0;
}

A::A(int n){
	data = n;
}



int main(){
	
	A test;
	A test2();
	A test3(2);
	
}


