#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>
#include <fstream>
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
	srand(time(NULL));
	double timer, timer2;
	//probar con-> big numbers
    int t=100;//1000000;
	int *arr= new int[t];
    //int arr[t]={-15,10,-2,-3,8,13,15};
	for (int i=0; i< t; i++){
		arr[i]= ((rand()%t)-(rand()%t));
	}
    
	int *y;
    y=&arr[t-1];//Fin
	//print(arr,t);
    
	ordenamiento<comparacion_Asc> S;
/*	
    S.BubbleSort(arr,y);
    cout<<"bubble: "<<endl;
    print(arr,t);
*/
    ofstream a;
    timer= clock();
	S.SelectionSort(arr,y);
	timer2= clock();
    cout<<endl<<"selection: "<<endl;
    print(arr,t); //big numbers only comment is slown
	a.open("arr.txt");
	for (int i=0; i< t; i++){
		a<<arr[i]<<" ";
	}
	cout<<endl<<"TIEMPO: "<<double(timer2-timer)/CLOCKS_PER_SEC<<endl;
	
	delete []arr;
	arr= NULL;
	
    return 0;
}