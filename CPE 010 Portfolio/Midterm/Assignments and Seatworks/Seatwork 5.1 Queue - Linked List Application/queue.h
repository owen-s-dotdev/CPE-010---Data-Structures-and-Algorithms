//Created on 09-09-25 
//by David Owen Santiago, CPE21S4

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template<typename T>
class Node{
	public:
		T data;
		Node *next;
		
		Node (T new_data){
			data = new_data;
			next = nullptr;
		}
};

template<typename T>
class Queue{
	private:
		Node<T> *front;
		Node<T> *rear;
		
	public:
		//Create an empty queue (queue constructor)
		Queue(){
			front = rear = nullptr;
			std::cout << "A queue has been created.\n";
			printQueue();
		}
		//isEmpty
		bool isEmpty(){
			return front == nullptr;
		}
		//enqueue
		void enqueue(T new_data){
			Node<T> *new_node = new Node<T>(new_data);
			if (isEmpty()){
				front = rear = new_node;
				std::cout << "Enqueued to an empty queue: " << new_data <<'\n';
				return;
			}
			rear->next = new_node;
			rear = new_node;
			std::cout << "Enqueued: " << new_data <<'\n';
		}
		
		//dequeue
		void dequeue(){
			//check if empty
			if (isEmpty()){
				std::cout << "Queue is empty.\n";
				return;
			}
			//create temporary node to store original front
			Node<T> *temp = front;
			
			//if front points to empty, then the queue is empty, therefore rear also points to null
			if (front == nullptr) {
				rear = nullptr;
			}
			
			else{
				//reassign front to the data next to the og front node
				front = front->next;
			}
			delete temp;
			std::cout << "Successfully dequeued.\n";
		}
		
		
		//getFront
		void getFront(){
			if (isEmpty()){
				std::cout << "Queue is empty.\n";
				return;
			}
			std::cout << "Front is: "<< front->data << '\n';
		}
		
		//getRear
		void getRear(){
			if (isEmpty()){
				std::cout << "Queue is empty.\n";
				return;
			}
			std::cout << "Rear is: "<< rear->data << '\n';
		}
		
		//display
		void printQueue(){
			if (isEmpty()){
				std::cout << "Queue is empty.\n";
				return;
			}
			Node<T> *temp = front;
			std::cout << "Current Queue: ";
			while (temp != nullptr){
				std::cout << temp->data << ' ';
				temp = temp->next;
			} std::cout<<'\n';	
		}	
		
		int QueueSize(){
			int count = 0;
			if (isEmpty()){
				std::cout << "Queue is empty.\n";
				return count;
			}
			
			Node<T> *temp = front;
			while (temp != nullptr){
				count += 1;
				temp = temp->next;
			}
			return count;
		}
		
		//to deallocate memory
		~Queue(){
			while(!isEmpty()){
				dequeue();
			}
		}
		
};
#endif
