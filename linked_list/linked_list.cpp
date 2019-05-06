#include<iostream>
#include "list.h"
using namespace std;

template<class T>
void list<T>::insert(T dato)
{  
	node<T>*tmp;	node<T>*new_;
	if(!head){head=new node<T>(dato);}
	if(find(dato,tmp,1)==false){
	    if(!tmp){//or tmp==nullptr
			tmp=head;
			new_=new node<T>(dato);
			new_->next=tmp;      head=new_;
		}
		else{new_=new node<T>(dato);
			 new_->next=tmp->next;
			 tmp->next=new_;}
	}
}


template<class T>
bool list<T>::find(T dato, node<T> *&tmp, int op)
{
	tmp=head;
	switch(op)
	{
		case 1: 
		        if(tmp->date >= dato and tmp->date!=dato){
			    tmp=nullptr; 	 return false;}
				
				while(tmp->date != dato){
					if( tmp->date < dato and (tmp->next==nullptr or tmp->next->date > dato)){ return false;}	
					tmp=tmp->next;
				}
				return true;
		//break;
		case 2: 
		        if(tmp->date==dato){ //????envio su misma posicion NOT el anterior[head]
		        tmp=nullptr;    return true;}
				
				while(tmp){
					if(tmp->date < dato and (tmp->next->next==nullptr or tmp->next->next->date > dato)){//buscamos the last && other
					   return tmp;}
					tmp=tmp->next;
				}
		//break;
	}
}

template<typename T>
void list<T>::remove(T dato)
{
	node<T> *tmp;	node<T> *tmp2;
	if(find(dato,tmp,2)==true){
		if(tmp==nullptr){//head
			tmp2=tmp=head;
			tmp=tmp2->next;
			head=tmp;
			delete tmp2;
		}
		else{	
		tmp2=tmp->next;
		tmp->next=tmp2->next;
		delete tmp2;}
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
	node<int> *aux;
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
	lista.insert(5);
	lista.insert(3);
	lista.insert(6);
	lista.insert(7);
	lista.insert(8);
	lista.insert(10);*/
	cout<<endl<<"insert list ordenada: "<<endl;
	lista.print();
	
	int num;
	cout<<endl<<"NUM: "<<endl;		cin>>num;
	if(lista.find(num, aux, 1))cout<<"existe"<<endl;
	else lista.insert(num);
	lista.print();
	
	lista.remove(0);
	lista.remove(10);
	lista.remove(7);
	cout<<endl<<"list elimina valor: "<<endl;
	lista.print();
}

/*
template<class T>
bool list<T>::find(T dato, node<T> *&tmp, int op)
{
	tmp=head;
	if(tmp->date >= dato and tmp->date!=dato){
			tmp=nullptr;	
			return false;
	}	
	while(tmp->date != dato){
		if( tmp->date < dato and(tmp->next==nullptr or tmp->next->date > dato)){
			cout<<"||||// "<<dato<<" - "<<tmp<<endl;
			 return false;
		}	
		tmp=tmp->next;
	}
	cout<<endl<<"+++// "<<dato<<" - "<<tmp<<endl;
	return true;
}
*/
