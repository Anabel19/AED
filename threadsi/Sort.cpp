#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>
#include <fstream>
#include <thread>
#include <stdio.h>

//#define NTHREADS 2;
using namespace std;

typedef int (*fun)(int *, int *);
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
class comparacion_AscAbs
{
	public:
        inline int operator()(int a,int b){
            return abs(b)-abs(a);//return a-b;
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


void print(int *p, int tam)
{
   for(int x=0; x<tam; x++)
    {
        cout<<*p<<"\t";
        *p++;
    }
}

int main()
{
    ordenamiento <comparacion_Asc> S;
    int nThreads=250, t=100000;
    int arr[t];

    for (int i=0; i<t;i++){
        arr[i]= ((rand()%100)-(rand()%100));
        print(arr,t);
    }
    
    thread A[nThreads];
    int longitud= sizeof(arr)/4;
    float gen1, gen2;
    gen1=clock();
    
    for (int i=0; i<sizeof(arr) ; ++i)
    {
        if(i%((longitud+1)/nThreads)==0){
        
            A[i/((longitud+1)/ nThreads)]= thread(S.SelectionSort,arr,longitud);
        }
    }
    
    for (int th=0; th< nThreads; th++)
        A[th].join();
    gen2=clock();
    
    for(int f=0; f<longitud;f++)
        cout<<arr[f]<<",";
    
    printf("\n");
    //cout<<"tiempo: "<<(gen2-gen1)/CLK_TCK<<endl;
    cout<<"tiempo: "<<(gen2-gen1)/CLOCKS_PER_SEC<<endl;
    //print(arr, 10);

    return 0;
}