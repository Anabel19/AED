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
bool list<T,C>::find(T dato, node<T>**&tmp)
{
	tmp=&head;
	cout<<"dat "<<dato<<endl;
	cout<<"---- "<<(*tmp)<<endl;
	if(!(*tmp)) {cout<<"not here"<<endl; cout<<"<<<< "<<(*tmp)<<endl; return 0;}
	//tmp=&(*tmp)->next;
	int i=0;
	do{
		cout<<"hhhh"<<&(*tmp)->next<<"##"<<endl;
		tmp= &(*tmp)->next; i++;
		cout<<"hi: "<<(*tmp)<<" - "<<endl;
	}while(i<6);//(*tmp)!=head);// && (*tmp)->date < dato);
	
	/*while(*tmp and (*tmp)->date < dato){
		tmp=&(*tmp)->next;
	}*/
	cout<<"not here"<<endl;
	return !!((*tmp)->date==dato); 
}

template<class T, class C>
bool list<T,C>::insert(T dato)
{
	cout<<"dat "<<dato<<endl;
	node<T> **tmp;  
	if(find(dato, tmp)) return 0;
	cout<<"....dat "<<(*tmp)<<endl;
	if(!(*tmp) or (dato > (*tmp)->date)){
		(*tmp)=head;  
	}
	//l=*tmp;
	
	node<T> *n= new node<T>(dato);
	n->next=(*tmp);
	*tmp=n;
	return 1;
}

template<class T, class C>
bool list<T,C>::remove(T dato)
{
	node<T> **tmp;
	if(!find(dato,tmp)) return 0;
	node<T> *d= *tmp;
	(*tmp) = d->next;
	delete d;
	return 1;
}

template<class T, class C>
void list<T,C>::print()
{
	node<T> *tmp=head;
	do{		
		cout<<"&:"<<tmp<<" "<<tmp->date<<" ";
		tmp=tmp->next;
	}
	while(tmp!=head);
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
	
	//lista.remove(5);
	lista.print();
	
}