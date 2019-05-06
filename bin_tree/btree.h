#ifndef BTREE
#define BTREE
#include <queue>
template<class T>
class node
{
	public:
    T date;
	node<T>* hnode[2];
    node<T>(T dato){
      date=dato;
      hnode[0]=hnode[1]=nullptr;
    }
};

template<class T, class C>
class BTree
{
	public:
    node<T> *root;
	C cmp;
	BTree(){
		root=nullptr;
	}
	~BTree(){
		
		std::queue<node<T> *> *a = new std::queue<node<T> *>();
		a->push(root);
		while(!a->empty()){
			if((a->front())->hnode[0])	a->push((a->front())->hnode[0]);
			if((a->front())->hnode[1])	a->push((a->front())->hnode[1]);
			delete a->front();
			a->pop();
		}
		delete a;
	}
	node<T>** rep(node<T>** & );
	bool find(T,node<T>**&);
	bool insert(T);
	bool remove(T);
	void InOrden(node <T> *);
	void PreOrden(node <T> *);
	void PosOrden(node <T> *);
	void print();
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