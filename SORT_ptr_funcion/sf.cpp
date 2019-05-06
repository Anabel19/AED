#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>
#include <fstream>
using namespace std;

typedef int (*fun)(int , int );
//typedef int (*fun)(int , int );
void swap( int *a, int *b ){

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
int comparacion_Asc(int a,int b)
{
    return b-a;//return a-b;

}
int comparacion_Desc(int a,int b)
{
    return a-b;//return b-a;

}
int comparacion_AscAbs(int a,int b)
{
    return abs(b)-abs(a);//return a-b;

}

	void BubbleSort(int *arr, int *n, fun compara) {
		  int *inic=arr;
		  bool swapped = true;
		  int j = 0;
		  while ( swapped) {
				swapped = false;
				while(arr < (n - j)) {
					  if (compara(*arr , *(arr+1))<0) {
							swap(*arr,*(arr+1));
							swapped = true;
					  }
					  arr++;
				}
				j++;
				arr=inic;
		  }
	}

	void SelectionSort( int *first, int *last, fun compara)
	{  //Remember that the interval of our array is [first, last]
		while( first <= last )
		{
			int *ptr_to_min = first;
			for( int *aux = (first+1); aux <= last; aux++){
				if( compara(*aux, *ptr_to_min)>0 ){
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
    int t=10; //1000000;
	//int arr[t]={-15,10,-2,-3,8,13,15};
	int *arr= new int[t];
    for (int i=0; i< t; i++){
		arr[i]= ((rand()%t)-(rand()%t));
	}
	
    int *y;
    y=&arr[t-1];//Fin
    //print(arr, t);
/*
    BubbleSort(arr,y,comparacion_Asc);
    cout<<endl<<"bubble: "<<endl;
    print(arr,t);
*/
/*
    InsertionSort(arr,y,comparacion_Asc);
    cout<<"insert: "<<endl;
    print(arr,t);
*/
    ofstream a;
    timer= clock();
    SelectionSort(arr,y, comparacion_Asc);
	timer2= clock();
    cout<<endl<<"selection: "<<endl;
    //print(arr,t);
	a.open("arr.txt");
	for (int i=0; i< t; i++){
		a<<arr[i]<<" ";
	}
	
	cout<<"MMMMM...  "<<timer<<"-----"<<timer2<<endl;
	cout<<endl<<"TIEMPO: "<<double(timer2-timer)/CLOCKS_PER_SEC<<endl;

/*
    CocktailSort(arr,y, comparacion_Desc);
    cout<<"cocktail: "<<endl;
    print(arr,t);
*/
/*
    quicksort(arr,y,comparacion_Desc);
    cout<<"Selection: "<<endl;
    print(arr,t);
*/
	delete []arr;
	arr= NULL;
	
    return 0;
}
