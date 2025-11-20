#include <iostream>
#include <cstdlib>

class BinaryTree{

	private:
		char key;
		BinaryTree *leftChild;

		BinaryTree *rightChild;

		public:
			BinaryTree(char rootObj){
				this->key = rootObj;
				this->leftChild = NULL;
				this->rightChild = NULL; // "this" keyword is a pointer exclusive inside the class
			}

			void insertLeft(char newNode){
				if (this->leftChild == NULL){
					this->leftChild = new BinaryTree(newNode);
				}

				else{
					BinaryTree *t = new BinaryTree(newNode);
					t->leftChild = this->leftChild;
					this->leftChild = t;
				}
			}

			void insertRight(char newNode){
				if (this->rightChild == NULL){
					this->rightChild = new BinaryTree(newNode);
				}

				else{
					BinaryTree *t = new BinaryTree(newNode);
					t->rightChild = this->rightChild;
					this->rightChild = t;
				}
			}

			BinaryTree *getLeftChild(){
				return this->leftChild;
			}

			BinaryTree *getRightChild(){
				return this->rightChild;
			}

			char getRootVal(){
				return this->key;
			}

			void setRootVal(char obj){
				this->key = obj;
			}
};

void visit(BinaryTree* node) {
	std::cout << node->getRootVal() << " ";
}

void preOrder(BinaryTree* node) {
	if (!node) return;
	visit(node);
	preOrder(node->getLeftChild());
	preOrder(node->getRightChild());
}

void inOrder(BinaryTree* node) {
	if (!node) return;
	inOrder(node->getLeftChild());
	visit(node);
	inOrder(node->getRightChild());
}

void postOrder(BinaryTree* node) {
	if (!node) return;
	postOrder(node->getLeftChild());
	postOrder(node->getRightChild());
	visit(node);
}

void line(){
	std::cout <<"------------------------\n";
}
int main(){

	// Initializing the Binary Tree
	std::cout << "Initializing the Binary Tree\n";
	BinaryTree *x = new BinaryTree('1');
	std::cout << "Root: " << x->getRootVal() << '\n';

	line();

	// Inserting a child to the left of the tree
	std::cout << "Inserting a child to the left of the tree\n";
	x->insertLeft('2');
	std::cout << "Left child of root: " << x->getLeftChild()->getRootVal() << '\n';

	line();

	// Inserting a child to the right of the tree
	std::cout << "Inserting a child to the right of the tree\n";
	x->insertRight('3');
	std::cout << "Right child of root " << x->getRightChild()->getRootVal() << '\n';

	line();

	// Inserting left child and right child to node 2
	std::cout << "Inserting left child and right child to node "<< x->getLeftChild()->getRootVal() << '\n';
	x->getLeftChild()->insertLeft('4');
	x->getLeftChild()->insertRight('5');

	std::cout << "Left child of 2: " << x->getLeftChild()->getLeftChild()->getRootVal() << '\n'; //4

	std::cout << "Right child of 2: " << x->getLeftChild()->getRightChild()->getRootVal() << '\n'; //5

	line();

	// Inserting child to node 3
	std::cout << "Inserting child to node 3\n";
	x->getRightChild()->insertLeft('6');
	std::cout << "Child of 3: "<< x->getRightChild()->getLeftChild()->getRootVal() << '\n';

	line();

	std::cout << "DFS Traversal: \n";
	std::cout << "Pre-order: "; preOrder(x); std::cout << "\n";
	std::cout << "In-order: "; inOrder(x); std::cout << "\n";
	std::cout << "Post-order: "; postOrder(x); std::cout << "\n";

	return 0;
}
