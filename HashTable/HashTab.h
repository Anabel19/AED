#ifndef HASHTAB_H
#define HASHTAB_H
#include <iostream>

using namespace std;
template<class T, class F, class E, unsigned long Z>
class CHash
{
	public:
	E *tab;
	F f;
	CHash(){//unsigned long s 	
		tab= new E[Z];
	}
	~CHash(){
		delete[] tab;
	}
	bool insert(T date){
		long id= f(date)%Z;
		return tab[id].inser(date);
	}
	bool remove(T date){
		long id= f(date)%Z;
		return tab[id].rem(date);
	}
	bool find(T date){
		long id= f(date)%Z;
		return tab[id].findd(date);
	}
	
	void print(unsigned i){
		this->tab[i].pri();
		cout << endl;
	}
};


#endif //HASHTAB_H