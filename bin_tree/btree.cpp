#include <iostream>
#include "btree.h"

using namespace std;

class compare
{
	public:
		inline int operator()(int a, int b){
			return a<b;
		}
};

template<class T, class C>
node<T>** BTree<T, C>::rep(node<T>** &q ){
	for(q=&(*q)->hnode[0]; (*q)->hnode[1]; q=&(*q)->hnode[1]);
	return q;
}

template<class T, class C>
bool BTree<T, C>::find(T dato, node<T>**&tmp)
{
	for(tmp=&root; *tmp && (*tmp)->date!=dato; tmp=&(*tmp)->hnode[cmp((*tmp)->date,dato)]);
    return (*tmp);
	//return 	!!*tmp;
}

template<class T, class C>
bool BTree<T, C>::insert(T dato)
{
	node<T>**tmp;
	if(find(dato,tmp)) return 0;
	(*tmp)=new node<T>(dato);

	return 1;
}

template<class T, class C>
bool BTree<T, C>::remove(T dato)
{
	node<T>**tmp;	
	if(!find(dato,tmp)) return 0;
	if((*tmp)->hnode[0] and (*tmp)->hnode[1]){ //case 2[involved to case 0-1]
		node<T> **q=tmp;
		rep(q);//partial reemplazo[aleat] 
		(*tmp)->date=(*q)->date;//no es need swap[only need ocupar reemplazar un valor] 
		tmp=q; 
	}
	node<T> *t=*tmp;
	(*tmp)= (*tmp)->hnode[!(*tmp)->hnode[0]];
	delete t;
	return 1;
}
template<class T, class C>
void BTree<T, C>::InOrden(node<T> *tmp)
{
	if(!tmp) return;
	InOrden(tmp->hnode[0]);
	cout<<tmp->date;
	InOrden(tmp->hnode[1]);
}
template<class T, class C>
void BTree<T, C>::PreOrden(node<T> *tmp)
{
	if(!tmp) return;
	cout<<tmp->date;
	InOrden(tmp->hnode[0]);
	InOrden(tmp->hnode[1]);
}

template<class T, class C>
void BTree<T, C>::PosOrden(node<T> *tmp)
{
	if(!tmp) return;
	InOrden(tmp->hnode[0]);
	InOrden(tmp->hnode[1]);
	cout<<tmp->date;
}
/*
template<class T, class C>
void BTree<T, C>::print()
{
	vector<node<T>* >c;
	c.push_back(root);
	int tam;
	while(c.size()!=0){
		tam=c.size();
		for(int i=0; i<tam; i++){
			if(c[i]){
				cout<<c[i]->date<<" ";
				c.push_back(c[i]->hnode[0]);
				c.push_back(c[i]->hnode[1]);
			}
			else cout<<"-";
		}
		cout<<endl;
		c.erase(c.begin(), c.begin()+tam);
	}
}*/
int main()
{
	BTree<int,compare> btree;
	btree.insert(1);
	btree.insert(8);
	btree.insert(3);
	btree.insert(7);
	btree.insert(2);
	btree.insert(9);
	btree.insert(5);
	btree.insert(6);
	btree.insert(4);
	/*
	btree.insert(7);
	btree.insert(11);
	btree.insert(9);
	btree.insert(1);
	btree.insert(3);
	btree.insert(2);
	btree.insert(6);
	*/
	btree.InOrden(btree.root);
	//btree.print();
	int num;
	cout<<endl<<"remueve "<<endl;
	cout<<endl<<"Ingresa el numero: "<<endl;
	cin>>num;
	//btree.remove(3);
	btree.remove(num);
	btree.InOrden(btree.root);
	//btree.print();
}