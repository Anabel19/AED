#ifndef LCDE_H
#define LCDE_H

template<class T>
class node
{
	public:
	T date;
	node<T>* next;
	node<T>* prev;
	node<T> (T dato,node<T>*sgte=nullptr){
		this->date=dato;
		this->next=sgte;
	}
};

template<class T, class C>
class list
{
	public:
    node<T>*head;
	C comp;
    list<T,C>(){
		head=nullptr;
	}
	~list<T,C>(){
		node<T> *clear=head;
	   do{
		   clear=head->next;
		   delete head;
		   head=clear;
	   }while(clear!=head);
	   head=nullptr;
	}
	bool find(T,node<T>**&);
	bool insert(T);
	bool remove(T);
	void print();
};

#endif //LCDE_H