#include <iostream>
#include "grapho.h"
#include <fstream>

using namespace std;
int main() {
    
    CGraph<char,int> GA;
    GA.InsNode('A');
    GA.InsNode('B');

    GA.InsEdge(GA.mnodes[0], GA.mnodes[1],4,1);

    GA.InsNode('C');
    GA.InsNode('D');

    GA.InsEdge(GA.mnodes[2], GA.mnodes[3],19,1);   
    GA.InsEdge(GA.mnodes[1], GA.mnodes[2],10,1);
     
    GA.printGraph();	 
	cout<<"elimino la arista B--C\n";
    GA.RemEdge('B', 'C');
     GA.printGraph();
    
    ///cout<<"Voy a eliminar el nodo D \n";

    ///A.RemNode('D');
	
	//GA.printGraph();
}
  