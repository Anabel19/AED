#include <iostream>
#include "avl.h"

using namespace std;

class compare
{
	public:
		inline int operator()(int a, int b){
			return a<b;
		}
};

template<class T, class C>
int Avl<T,C>::height(Node<T>* tmp){ 
	if (!tmp)	return 0;
        
        //ESTA LINEA COMENTE POR ERROR
        tmp->balan_fac= height(tmp->hnode[1])-height(tmp->hnode[0]);
        return max(height(tmp->hnode[0]),height(tmp->hnode[1]))+1;;
}
template<class T, class C>
bool Avl<T,C>::balance()
{
	while(!recorrido.empty())
	{
		Node<T>**tmp;
		tmp=this->recorrido.top();
		this->recorrido.pop();
                
		(*tmp)->balan_fac= height((*tmp)->hnode[1])-height((*tmp)->hnode[0]);
                
		if((*tmp)->balan_fac==-2 && (*tmp)->hnode[0]->balan_fac== 1) {
			cout<<"LL - RR"<<endl;	
			LR(tmp);}
		else if((*tmp)->balan_fac== 2 && (*tmp)->hnode[1]->balan_fac==-1) {cout<<"RR - LL"<<endl;
                        cout<<(*tmp)->hnode[1]->balan_fac<<endl;
			RL(tmp);}
		else if((*tmp)->balan_fac== 2) {cout<<"RR"<<endl;
			RR(tmp);}
		else if((*tmp)->balan_fac==-2) {cout<<"LL"<<endl;	
			LL(tmp);}
	}

	return 1;
}

template<class T, class C>
Node<T>** Avl<T, C>::rep(Node<T>** &q ){
        //varia la prfundidad(aleatoria)
	//for(q=&(*q)->hnode[0]; (*q)->hnode[1]; q=&(*q)->hnode[1]);
	for(q=&((*q)->hnode[1]); (*q)->hnode[0]; q=&((*q)->hnode[0]));
	return q;
}

template<class T, class C>
bool Avl<T, C>::find(T dato, Node<T>**&tmp)
{
	for(tmp=&root; *tmp && (*tmp)->date!=dato; tmp=&(*tmp)->hnode[cmp((*tmp)->date,dato)])
		recorrido.push(tmp);
	return 	!!*tmp;
}

template<class T, class C> 
bool Avl<T, C>::insert(T dato)
{
	Node<T>**tmp;
	if(find(dato,tmp)) return 0;
	(*tmp)=new Node<T>(dato);
	balance();
	return 1;
}

template<class T, class C>
bool Avl<T, C>::remove(T dato)
{
	Node<T>**tmp;	Node<T>*d;
	if(!find(dato,tmp)) return 0;
	if((*tmp)->hnode[0] and (*tmp)->hnode[1]){ //case 2[involved to case 0-1]
		//Node<T> **q=rep(tmp); //malmal
		Node<T> **q=tmp;
		rep(q);//partial reemplazo[aleat] 
		(*tmp)->date=(*q)->date;
		tmp=q;
	}
	Node<T> *t=*tmp;
	(*tmp)= (*tmp)->hnode[!(*tmp)->hnode[0]];
	balance();
	
	delete t;
	return 1;
}

//ROTACIONES
/*
void Avl<T, C>::RR(Node<T> **&r)
{
	Node <T>* tmp=*r->hnode[1];
	tmp->hnode[0]=*r;
	tmp->hnode[1]=*r->hnode[1]->hnode[1];
	*r=tmp;
}*/

template<class T, class C>
void Avl<T, C>::RR(Node<T> **&r)
{
	Node <T>* tmp=*r;
	*r=(*r)->hnode[1];
	tmp->hnode[1]=(*r)->hnode[0];
	(*r)->hnode[0]=tmp;
}

template<class T, class C>
void Avl<T, C>::LL(Node<T> **&r)
{
	Node <T>* tmp=*r;
	*r=(*r)->hnode[0];
	tmp->hnode[0]=(*r)->hnode[1];
	(*r)->hnode[1]=tmp;
}

template<class T, class C>
void Avl<T, C>::RL(Node<T> **&r)
{
	Node <T>** tmp=&(*r)->hnode[1];
	LL(tmp);
	RR(r);
}

template<class T, class C>
void Avl<T, C>::LR(Node<T> **&r)
{
	Node <T>** tmp=&(*r)->hnode[0];
	RR(tmp);
	LL(r);
}

//RECORRIDOS DEL ARBOL
template<class T, class C>
void Avl<T, C>::InOrden(Node<T> *tmp)
{
	if(!tmp) return;
	InOrden(tmp->hnode[0]);
	cout<<tmp->date;
	InOrden(tmp->hnode[1]);
}
template<class T, class C>
void Avl<T, C>::PreOrden(Node<T> *tmp)
{
	if(!tmp) return;
	cout<<tmp->date;
	InOrden(tmp->hnode[0]);
	InOrden(tmp->hnode[1]);
}

template<class T, class C>
void Avl<T, C>::PosOrden(Node<T> *tmp)
{
	if(!tmp) return;
	InOrden(tmp->hnode[0]);
	InOrden(tmp->hnode[1]);
	cout<<tmp->date;
}

template<class T, class C>
void Avl<T, C>::print_A()
{
	queue<Node<T> *> cola;
    Node<T> *temp;
    cola.push(root);
    while (! cola.empty())
    {
        temp = cola.front();
        cola.pop();
        cout << temp->date <<",";
        if (temp->hnode[0])
            cola.push(temp->hnode[0]);
        if (temp->hnode[1])
            cola.push(temp->hnode[1]);
    }
}

int main()
{
	Avl<int,compare> avl;
	/*
	avl.insert(1);
    avl.insert(2);
    avl.insert(3);
    avl.insert(4);
    avl.insert(5);
    avl.insert(6);
    avl.insert(7);
    avl.insert(8);
    avl.insert(9);
    avl.insert(10);
	*/
	
	avl.insert(1);
	avl.insert(8);
	avl.insert(3);
	avl.insert(7);
	avl.insert(2);
	avl.insert(9);
	avl.insert(5);
	avl.insert(6);
	avl.insert(4);
	/*
	avl.insert(7);
	avl.insert(11);
	avl.insert(9);
	avl.insert(1);
	avl.insert(3);
	avl.insert(2);
	avl.insert(6);
	*/
	//avl.InOrden(avl.root);
	avl.print_A();
	
	cout<<endl<<endl<<"remueve 3 y 1"<<endl;
	avl.remove(3);
	avl.remove(1);
	//avl.InOrden(avl.root);
	avl.print_A();
}