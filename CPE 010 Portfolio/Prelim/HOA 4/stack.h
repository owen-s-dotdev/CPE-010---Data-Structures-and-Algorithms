#ifndef STACK_H
#define STACK_H
#define MAX 10
#include <iostream>

template<typename T>
class stack{
	private:
		int top = -1;
		T arr[MAX];
	
	public:
		//isEmpty
		bool isEmpty(){
			return(top < 0);
		}
		
		//isFull
		bool isFull(){
			return(top >= MAX-1);
		}
		
		//peek
		
		void peek(){
			if (isEmpty()){
				std::cout << "Stack is empty\n";
			}
			else{
				std::cout << "The top element of the stack is: "<< arr[top] << std::endl;
			}
		}
		
		//push
		void push(T value){
			if (isFull()){
				std::cout << "Stack overflow" << std::endl;
			}
			else{
				arr[++top] = value;
				std::cout << "Successfully pushed the value " << value <<" into the stack\n";
			}
		}
		
		//pop
		void pop(){
			if(isEmpty()){
				std::cout << "Stack is empty\n";
			}
			else{
				std::cout << "Successfully popped " << arr[top--] << std::endl;	
			}
		}
		
		//display
		void display(){
			if(isEmpty()){
				std::cout << "Stack is empty\n";
			}
			else{
				std::cout << "The elements of the stack are: ";
				for(int i = top; i >= 0; i--){
					std::cout << arr[i] << " ";
				}std::cout<<'\n';
			}
		}
	
};



#endif

