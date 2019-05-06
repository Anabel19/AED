#ifndef LE_H
#define LE_H
template<class T>
class node{
	public:
	    T date;
		node<T> *next;
		node<T> (T valor, node<T> *sgte= nullptr){
		   date= valor;
		   next=sgte;
		}
};

template<class T> 
class list{
    private:
		node<T> *head;
	public:		
		list<T> (){
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
		bool find(T, node<T>**&);
		void insert(T);
		void remove(T);
		void print();
};

#endif //LE_H