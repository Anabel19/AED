#include "le.h"
#include <iostream>

using namespace std;

template <class T>
bool list<T>::find(T dato, node<T> **&tmp)
{
	for(tmp=&head; *tmp and (*tmp)->date< dato;tmp=&(*tmp)->next);
	return *tmp and (*tmp)->date==dato;
}

template <class T>
bool list<T>::insert(T dato)
{
	node<T>**tmp;	
	if(find(dato,tmp)){return false;}
	node<T>*new_=new node<T>(dato);
	new_->next=*tmp;
	*tmp=new_;
	return true;
}

template <class T>
bool list<T>::remove(T dato)
{
	node<T>**tmp;
	if(!find(dato, tmp)){return false;}
	node<T>*p= *tmp;
	*tmp=p->next;
	delete p;
	return true;
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
	lista.insert(5);
	lista.insert(1);
	lista.insert(7);
	lista.insert(4);
	lista.insert(6);
	lista.insert(8);
	lista.insert(10);
	lista.insert(0);
	/*
	lista.insert(1);
	lista.insert(2);
	lista.insert(6);
	lista.insert(7);
	lista.insert(8);
	lista.insert(10);
	*/
	cout<<endl<<"insert list ordenada: "<<endl;
	lista.print();
	
	cout<<endl<<"NUMBER: "<<endl;
	cin>>num;
	if (lista.find(num, aux)){cout<<endl<<"existe"<<endl;}
	else {cout<<endl<<"~ existe"<<endl;
	      lista.insert(num);}
	lista.print();	  
		  
	lista.remove(0);
	lista.remove(10);
	lista.remove(7);
	cout<<endl<<"list elimina valor: "<<endl;
	lista.print();
}