#include <iostream>
#include "stack.h"



int main(){
	
	stack<int> s1;
	std::cout<<"Santiago Stacks Array Implementation \n\n";
	std::cout << "Testing push: \n";
	for(int i = 0; i < 10; i++){
		s1.push(i + 1);
	}
	std::cout<<"\nTesting Display: \n";
	s1.display();
	
	std::cout<<"\nTesting Peek: \n";
	s1.peek();
	
	std::cout<<"\nTesting Pop: \n";
	s1.pop();
	s1.peek();
	s1.display();
	
	
	return 0;
}
