/* florence jornod
aucune garantie !
*/


#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;  

class Node{
private:
	bool m_status=false; // si le noeud est plein ou vide
	unsigned int m_position=12; // position du noeud dans le vecteur
	unsigned int m_parent; // la position du parent
	vector<int> m_children; // la position des enfants
	// un truc avec l'interieur du noeud.. genre les info des lignées
public:
	Node(){}
	/*Node(unsigned int position , unsigned int m_parent){
		m_status=true;
		m_position=position;
		m_parent=0;
	}*/
	void aff_status(){
		cout << m_status << endl;
		cout << "aff pos" << m_position << endl;
	}
	bool change_status(){
		if(m_status){
			m_status=false;
		}else{
			m_status=true;
		}
		return m_status;
	}
	int get_pos(){
		return m_position;
	}
	void set_parent(unsigned int parent){
		m_parent=parent;
	}

	void addAChild(int child_pos){
		m_children.push_back(child_pos);
	}
	void modif_node(){
		
	}
	//void create_new_node()
};

int main(){
	unsigned int k=4;
	vector<Node> res(2*k-1);
	stack<int> i;
	for(int j=2*k-1-1;j>=0;j--){ // on remplit la pile avec les differentes positions possible. ATTENTION a bien remplir en sens inverse!
		//cout << j <<endl;
		i.push(j);
	}
	res[i.top()].modif_node();

}