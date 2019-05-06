#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>
#include "list.h"
using namespace std;

//typedef int (*fun)(int *, int *);
void swap( int *a, int *b ){

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
class comparacion_Asc
{
    public:
        inline int operator()(int a,int b){
            return b-a;//return a-b;
        }
};
class comparacion_Desc
{
    public:
        inline int operator()(int a,int b){
            return a-b;//return b-a;
        }
};
template<class compara>
class ordenamiento
{
    private:
        compara c_sort;
    public:
        void BubbleSort(int *arr, int *n);
		void SelectionSort(int *arr, int *n);
};

template<class compara>
void ordenamiento<compara>::BubbleSort(int *arr, int *n) {
      int *inic=arr;
      bool swapped = true;
      int j = 0;
      while ( swapped) {
            swapped = false;
            while(arr < (n - j)) {
                  if (c_sort(*arr , *(arr+1))<0) {
                        swap(*arr,*(arr+1));
                        swapped = true;
                  }
                  arr++;
            }
            j++;
            arr=inic;
      }
}

template<class compara>
void ordenamiento<compara>::SelectionSort( int *first, int *last)
{  //Remember that the interval of our array is [first, last]
	while( first <= last )
	{
		int *ptr_to_min = first;
		for( int *aux = (first+1); aux <= last; aux++){
			if( c_sort(*aux, *ptr_to_min)>0 ){
				ptr_to_min = aux;
            }
		}

		if(ptr_to_min != first ){        //evaluamos si es que se encontro un numero menor que el actual, a traves de sus direcciones
            swap( first, ptr_to_min);
		}
		first++;
	}

}

template<typename T>	
void list<T>::print()
{
	node<T> *tmp=head;
	while(tmp){
		cout<<"&:"<<tmp<<" "<<tmp->value<<" ";
		tmp=tmp->next;
	}
}	
	
int main()
{
	srand(time(NULL));
	time_t timer, timer2;
    int t=10000;
	//int arr[t];
	list<int > arr;
    //int arr[t]={-15,10,-2,-3,8,13,15};
	for (int i=0; i< t; i++){
		arr.insert((rand()%t)-(rand()%t));
	}
    
	int *y;
    y=&arr[t-1];//Fin
	arr.print();
	
    
//	ordenamiento<comparacion_Asc> S;
/*	
    S.BubbleSort(arr,y);
    cout<<"bubble: "<<endl;
    print(arr,t);
*/
/*
    timer= clock();
	S.SelectionSort(arr,y);
	timer2= clock();
    cout<<endl<<"selection: "<<endl;
    arr.print();
	cout<<"MMMMM...  "<<timer<<"-----"<<timer2<<endl;
	cout<<endl<<"TIEMPO: "<<double((timer2-timer)/CLOCKS_PER_SEC)<<endl;
*/	
    return 0;
}

/*
int main()
{
	srand(time(NULL));
	time_t timer, timer2;
    int t=10000;
	int arr[t];
    //int arr[t]={-15,10,-2,-3,8,13,15};
	for (int i=0; i< t; i++){
		arr[i]= new c_int((rand()%t)-(rand()%t));
	}
    
	int *y;
    y=&arr[t-1];//Fin
	print(arr,t);
	
//cout<<"arr: "<<int(arr)<<" "<<*arr<<"y: "<<int(y)<<" "<<*y<<endl;
    
	ordenamiento<comparacion_Asc> S;
/*	
    S.BubbleSort(arr,y);
    cout<<"bubble: "<<endl;
    print(arr,t);
*/
/*
    timer= clock();
	S.SelectionSort(arr,y);
	timer2= clock();
    cout<<endl<<"selection: "<<endl;
    print(arr,t);
	cout<<"MMMMM...  "<<timer<<"-----"<<timer2<<endl;
	cout<<endl<<"TIEMPO: "<<double((timer2-timer)/CLOCKS_PER_SEC)<<endl;
	
    return 0;
}
*/

