#include "lcde.h"
#include<iostream>

using namespace std;
/*
template<class T, class C>
bool find(T dato, node<T>**&tmp)
{
	for(tmp->&head; tmp && tmp!=&head && (*tmp)->date<dato; tmp=&(*tmp)->next)
	return tmp and (*tmp)->date==dato; 
}
*/
class compare
{
	public:
		inline bool operator()(int a, int b){
			return a<b;
		}
};	

template<class T, class C>
bool find(T dato, node<T>**&tmp)
{
	tmp=&head;
	if(!tmp) return 0;
	do{
		tmp= &(*tmp)->next;
	}while(tmp!=&head && (*tmp)->dato < dato);
	return((*tmp)->date==dato); 
}

template<class T, class C>
bool insert(T dato)
{
	node<T> **tmp;  
	if(find(dato, tmp)) return 0;
	node<T> *n= new node<T>(dato);
	n->next=(*tmp);
	*tmp=n;
	return 1;
}

template<class T, class C>
bool remove(T dato)
{
	node<T> **tmp;
	if(!find(dato,tmp)) return 0;
	node<T> *d= *tmp;
	(*tmp) = d->next;
	delete d;
	return 1;
}

template<class T, class C>
void list<T>::print()
{
	node<T> *tmp=head;
	while(tmp){
		cout<<"&:"<<tmp<<" "<<tmp->date<<" ";
		tmp=tmp->next;
	}
}
int main()
{
	list <int,compare> lista;
	lista.insert(5);
	lista.insert(2);
	lista.insert(9);
	lista.insert(0);
	lista.insert(18);
	lista.insert(1);
	
	lista.print();
	
}