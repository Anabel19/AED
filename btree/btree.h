#ifndef BTREE_H
#define BTREE_H
template<class T, unsigned long z>
class CNode
{
	T date;
	CNode *hnode[2];
	CNode(T dato){
		this->date=dato;
		hnode[0]=nullptr;	hnode[1]=nullptr;
	}
};
class CPage
{
	public:
		T keys[z];
		CNode nodes[z];
		CNode(){
		}
	    
};

class CBTree
{
};
#endif //BTREE_H