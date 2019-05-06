#include<iostream>
#include<thread>
class compara
{
	public:
	inline bool operator()(int a, int b){
		return a<b;
	}
};
template<class T, class C>
class ordenamiento
{
	private:
	C cmp;
	public:
	ordenamiento(int *, int*);
	void BubbleSort(int*, int*);
	void SelectionSort();
};

void swap( int *a, int *b ){

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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
	ordenamiento<compara> sort;
	int nthr=4;	t=124;
	int arr[t];

    for (int i=0; i<t;i++){
        arr[i]= ((rand()%100)-(rand()%100));
        print(arr,t);
    }
	thread A[nthr];
	int longi=sizeof(arr)/nthr;
	
	for(int i=0; i<t; i++){
		if(i%longi==0){
			A[indice]=thread(sort.SelectionSort,arr,t);
			indice++;
		}
	}
	for (int th=0; th< nThreads; th++)
        A[th].join();
}