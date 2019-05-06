#include<iostream>
#include <stdlib.h> //srand, rand
#include <time.h>
#include <fstream>
using namespace std;

void swap( int *a, int *b ){

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

class comparisons
{
    public:
	    virtual int compara(int a, int b){return 0;}
        //void BubbleSort(int *arr, int *n);
};

class comparacion_Asc: public comparisons
{
    public:
        int compara(int a, int b){
            return b-a;//return a-b;
        }
};
class comparacion_Desc: public comparisons
{
    public:
        int compara(int a, int b){
            return a-b;//return b-a;
        }
};

class comparacion_AscAbs: public comparisons
{
	public:
        int compara(int a,int b){
            return abs(b)-abs(a);//return a-b;
        }
};

template<class C>
void BubbleSort(int *arr, int *n, C c_sort)
{
	int *inic=arr;
    bool swapped = true;
    int j = 0;	
    while ( swapped ) {
          swapped = false;
          while(arr < (n - j)) {
                if (c_sort->compara(*arr , *(arr+1))<0) {
                    swap(*arr,*(arr+1));
                        swapped = true;
                  }
                  arr++;
            }
            j++;
            arr=inic;
      }
	
}

template<class C>
void SelectionSort( int *first, int *last, C c_sort)
{  //Remember that the interval of our array is [first, last]
	while( first <= last )
	{
		int *ptr_to_min = first;
		for( int *aux = (first+1); aux <= last; aux++){
			if( c_sort->compara(*aux, *ptr_to_min)>0 ){
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
	for(int i=0; i<tam; i++){
		cout<<*p<<"\t";
		*p++;
	}
}

int main()
{
	srand(time(NULL));
	time_t timer, timer2;
	
    int t=10;
    //int arr[t]={-15,10,-2,-3,8,13,15};
    int *arr= new int[t];
    for (int i=0; i< t; i++){
		arr[i]= ((rand()%t)-(rand()%t));
	}
	int *y;
    y=&arr[ t-1];//Fin
	//print(arr,t);
	
//cout<<"arr: "<<int(arr)<<" "<<*arr<<"y: "<<int(y)<<" "<<*y<<endl;
//
    comparacion_Asc AC;
	comparacion_Desc DC;
	//comparisons *S = &AC;
	comparisons *S = new comparacion_Asc;
/*	
    BubbleSort(arr,y,S);
    cout<<"bubble: "<<endl;
    print(arr,t);
*/
    ofstream a;
    timer= clock();
    SelectionSort(arr,y,S);
	timer2= clock();
    cout<<endl<<"selection: "<<endl;
    //print(arr,t);
	a.open("arr.txt");
	for (int i=0; i< t; i++){
		a<<arr[i]<<" ";
	}
	cout<<"MMMMM...  "<<timer<<"-----"<<timer2<<endl;
	cout<<endl<<"TIEMPO: "<<double(timer2-timer)/CLOCKS_PER_SEC<<endl;
	
	delete []arr;
	arr= NULL;
	
    return 0;
}