#include <iostream>

using namespace std;

void f(int * &a){
	(*a)++;
   cout<<".... "<<a;
}
int main(){
	int a=5;
	int *p=&a;
	cout<<".... "<<&p<<endl;
	cout<<".... "<<&a<<"--- "<<p<<endl;
	f(p);
	cout<<".... "<<p;
	
	
	int r[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int (*l)[3];
    l=r;
	//l++;
	int *m= (*(l+1)+1);
	//cout<<*(*(l+1)+1);
	cout<<*m;
	
	/*
  int arr=5;
  int a[5]={1,2,3,4,5};
  int *p=a;
  int *q=&a[4];
  
  //int *p=&a;
  p=p+(p-q);
  //int r[3][3];
  //int **l;
  //(*p)++;
  cout<<"### "<<p-q<<endl;
  cout<<"--- "<<q-p<<endl;
  cout<<*p<<endl;
  cout<<p;*/
};