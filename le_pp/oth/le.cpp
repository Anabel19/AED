#include "le.h"
#include <iostream>

using namespace std;

template <class T>
bool list<T>::find(T dato, node<T> **&tmp)
{
	tmp= &head;
	while(*tmp){
	  tmp= &(*tmp)->next;
	}
	return *tmp and (*tmp)->date==dato;
}

template <class T>
void list<T>::insert(T dato)
{
	node<T>**tmp;
	if(!find(dato,tmp)){
		node<T> *_new= new node<T>(dato);
		_new->next= *tmp;
		*tmp=_new;
	}		
}

template <class T>
void list<T>::remove(T dato)
{
	 node<T> **tmp;
	 if(find(dato, ptr)){
	    node<T>* p= *tmp;
		*tmp= p->next;
		delete p;
	 }
}

template<typename T>
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
	int num;
	node<int> **aux;
	list<int> lista;
	lista.insert(1);
	lista.insert(2);
	lista.insert(6);
	lista.insert(7);
	lista.insert(8);
	lista.insert(10);
	cout<<endl<<"insert list ordenada: "<<endl;
	lista.print();
	cout<<endl<<"NUMBER: "<<endl;
	cin>>num;
	if (lista.find(num, aux)){cout<<endl<<"existe"<<endl;}
	else {cout<<endl<<"~ existe"<<endl;
	      lista.insert(num);}
	//lista.remove(1);
	cout<<endl<<"list elimina valor: "<<endl;
	lista.print();
}