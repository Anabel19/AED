#ifndef LIST_H
#define LIST_H
template<typename T>
class node
{
	public:
	T value;
	node<T> *next;
	node<T>(T dato, node *sgte=nullptr){
		value=dato;
		next=sgte;
	}
};

template<typename T>
class list
{
	public:
   node<T> *head, *tail;
   list<T>(){
       //head=nullptr;
	   head=tail=nullptr;
   }
   ~list<T>(){
	   node<T> *clear=head;
	   while(clear){
		   clear=head->next;
		   delete head;
		   head=clear;
	   }
   }
   void insert(T);
   void print();
};

template<typename T>
void list<T>::insert(T element)
{   node<T>*tmp;
	if(!head){
		head=new node<T>(element);
		tail=head;
	}
	//else if(find_(element)==false){ //insert after tail
	else{ 
		tail->next=new node<T>(element);
		tail=tail->next;
		
	}	
}
#endif //LIST_H