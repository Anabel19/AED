#include <math.h>
#include <list>
#include "HashTab.h"

template<class T>
class fdispersion{
	public:
		inline unsigned operator()(T n){
			return pow(n, 2);
		}
};

template<class T>
class listX{
	public:
	list<T> l;
	bool inser(T x)
    {
        l.push_back(x);
    }
    bool rem(T x)
    {
        l.remove(x);
    }
	bool findd(T x)
    {
        l.find(x);
    }
    int size()
    {
      return l.size();
    }
    void pri()
    {
         typename list<T>::iterator  pos;
         pos = l.begin();
         while( pos != l.end())
         {
             cout << *pos << " ";
             pos++;
         }
    }
};
const int tamh=10;
typedef CHash<int, fdispersion<int>, listX<int>,tamh> thash;
int main()
{
	thash *h = new thash();
	for(unsigned i=0; i<30; i++)
		h->insert(i);
	for(unsigned i=0; i<tamh; i++){
		cout<<i<<"-> ";
		h->print(i);
	}
}