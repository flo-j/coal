/* florence jornod
aucune garantie ! (je vois....)
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
	int m_position=-1; // position du noeud dans le vecteur
	unsigned int m_parent=-1; // la position du parent
	vector<int> m_children; // la position des enfants
	// un truc avec l'interieur du noeud.. genre les info des lignées
public:
	Node(){}
	/*Node(unsigned int position , unsigned int m_parent){
		m_status=true;
		m_position=position;
		m_parent=0;
	}*/
	void aff_vec(vector<int>& vec){ // surcharge opérateur <<
	for(int i=0;i<vec.size();i++){
		cout << vec[i] << "\t";
	}
	cout << endl;
}
	void aff_node(){
		cout << "le noeud en position : " << m_position << " a pour parent le noeud en position " << m_parent << " et a pour enfants les noeuds suivants : " ;
		for(int i=0; i<m_children.size();i++){
			cout << m_children[i] << "   ";
		}
		cout << endl;
	}	
	void aff_status(){
		cout << m_status << endl;
		cout << "aff pos" << m_position << endl;
	}
	void change_status(){
		if(m_status){
			m_status=false; // m_status = !mstatus;
		}else{
			m_status=true;
		}
	}
	int get_pos(){
		return m_position;
	}
	int get_parent(){
		return m_parent;
	}
	void set_parent(unsigned int parent){
		m_parent=parent;
	}
	void set_pos(unsigned int pos){
		m_position=pos;
	}

	void addAChild(int child_pos){ // addChild(Tree child)
		cout << "taille du vecteur enfant : " << m_children.size() << endl;
		m_children.push_back(child_pos);
		cout << "taille du vecteur enfant : " << m_children.size() << endl;

	}
	void modif_node(unsigned int pos){
		set_pos(pos);
		change_status(); // attention si on le fait plusieurs fois ça va poser un pb
		set_parent(pos);
	}
	//void create_new_node()

};
void aff_racine(vector<Node> res){
	unsigned int i=0;
	while(res[i].get_pos()!=res[i].get_parent()){
		i++;
	}	
		cout << "le noeud " << res[i].get_pos() << " est la racine de l'arbre " << endl;
	}
int main(){
	unsigned int k=4;
	vector<Node> res(2*k-1);
	stack<unsigned int> i;
	for(int j=2*k-1-1;j>=0;j--){ // on remplit la pile avec les differentes positions possible. ATTENTION a bien remplir en sens inverse!
		//cout << j <<endl;
		i.push(j);
	}
	cout << res[i.top()].get_pos() << endl;
	// CREATION D'UN ARBRE À LA MAIN.. C'EST MOCHE ..
	unsigned int pos=i.top();
	res[pos].modif_node(pos);
	//res[pos].aff_node();
	i.pop();
	res[i.top()].modif_node(i.top());
	i.pop();
	res[i.top()].modif_node(i.top());
	i.pop();
	res[i.top()].modif_node(i.top());
	i.pop();
	//pos=i.top();
	res[i.top()].modif_node(i.top());
	res[0].set_parent(i.top());
	res[1].set_parent(i.top());
	res[i.top()].addAChild(0);
	res[i.top()].addAChild(1);
	i.pop();
	res[i.top()].modif_node(i.top());
	res[2].set_parent(i.top());
	res[4].set_parent(i.top());
	res[i.top()].addAChild(2);
	res[i.top()].addAChild(4);
	i.pop();
	res[i.top()].modif_node(i.top());
	res[3].set_parent(i.top());
	res[5].set_parent(i.top());
	res[i.top()].addAChild(3);
	res[i.top()].addAChild(5);

	for(int j=0; j<res.size();j++){
		res[j].aff_node();
	}
	aff_racine(res);


	//cout << res[pos].get_pos() << endl;

}