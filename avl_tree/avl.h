#ifndef BTREE
#define BTREE
#include <stack>
#include <queue>
template<class T>
class Node
{
	public:
    T date;
	T balan_fac; //balance_factor
	T high;
	Node<T>* hnode[2];
    Node<T>(T dato){	
      date=dato;
      hnode[0]=nullptr;
	  hnode[1]=nullptr;
	  balan_fac=0;
	  high=0;
    }
};

template<class T, class C>
class Avl
{
	public:
    Node<T> *root;
	std::stack<Node<T>**> recorrido;
	C cmp;
	Avl(){
		root=nullptr;
	}
	~Avl(){
		std::queue<Node<T> *> *a = new std::queue<Node<T> *>();
		a->push(root);
		while(!a->empty()){
			if((a->front())->hnode[0])	a->push((a->front())->hnode[0]);
			if((a->front())->hnode[1])	a->push((a->front())->hnode[1]);
			delete a->front();
			a->pop();
		}
		delete a;
	}
	int height(Node<T>* );
	bool balance();
	Node<T>** rep(Node<T>** & );
	bool find(T,Node<T>**&);
	bool insert(T);
	bool remove(T);
	void RR(Node<T>**&);
	void LL(Node<T>**&);
	void RL(Node<T>**&);
	void LR(Node<T>**&);
	void InOrden(Node <T> *);
	void PreOrden(Node <T> *);
	void PosOrden(Node <T> *);
	void print();
	void print_A();
};
/*
btree<T,C>::~btree(){
	queue<bnode<T> *> *a = new queue<bnode<T> *>();
	a->push(m_root);
	while(!a->empty()){
		if((a->front())->m_node[0])	a->push((a->front())->m_node[0]);
		if((a->front())->m_node[1])	a->push((a->front())->m_node[1]);
		delete a->front();
		a->pop();
	}
	delete a;
}
*/
#endif //BTREE