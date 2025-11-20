#include <iostream>
#include "queue.h"

void line(){
	std::cout<<"------------------------------\n";
}
int main(){
	
	Queue<int> q1;
	
	if(q1.isEmpty()){
		std::cout << "Queue is empty.\n";
	}
	
	line();
	
	for (int i = 1; i <= 5; i++){
		q1.enqueue(i);
	}
	q1.printQueue();
	std::cout << "Queue size: " << q1.QueueSize() << '\n';
	
	line();
	
	q1.getFront();
	q1.getRear();
	
	line();
	for (int j = 5; j > 0; j--){
		q1.dequeue();
	}
	std::cout << "Queue size: " << q1.QueueSize() << '\n';
	line();
	q1.getFront();
	q1.getRear();
	return 0;
}

