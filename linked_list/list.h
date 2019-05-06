#ifndef LIST_H
#define LIST_H
template<typename T>
class node
{
	public:
	T date;
	node<T> *next;
	node<T>(T dato, node *sgte=nullptr){
		date=dato;
		next=sgte;
	}
};

template<typename T>
class list
{
	public:
   node<T> *head;
   list<T>(){
       //head=nullptr;
	   head=nullptr;
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
   bool find(T, node<T> *&,int);
   void remove(T);
   void print();
};
#endif //LIST_H