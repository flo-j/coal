/* 	florence jornod
	aucune garantie
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>
#include <queue>
using namespace std;
class Node{
//public:
	Node* pParent; // a terme une paire? vu que deux parents.. mais louche.. 
	vector<Node*> m_children; // vecteur de reference sur les enfants : evite la copie.. 
	int m_data; // attention à terme ça devrait etre autre chose qu'un int.. voir comment utiliser les using !


public:
	Node(Node* pParent=nullptr){} // constructeur par defaut 
	Node(int data){ // si on y ajoute des données
		pParent=nullptr;
		m_data=data;
	} 
	void AddAChild(Node &node1){
		m_children.push_back(&node1);
	}

	void hasForChildren(Node &node1, Node &node2){
		//
		node1.pParent=this; // normalement this correspond au pointeur qui pointe sur le pere ..
		node2.pParent=this;
		AddAChild(node1);
		AddAChild(node2);
	}

	void Dfs(){
		Node* r;
		Node* voisin;
		queue<Node*> st;
		st.push(this);
		while(!st.empty()){
			r=st.front();
			st.pop();
			cout << r->m_data << " " ;
			for(unsigned int i=0;i<r->m_children.size();i++){
				voisin=r->m_children[i];
				st.push(voisin);
			}
		}
	}

	void print_node(){
		cout << " le noeud :" ;
		cout << m_data ;
		cout << " et l'adresse est :";
		cout << this;
		if(pParent!=0){
			cout <<" a pour parent :";
			cout << pParent << " de valeur : " ;
			cout << pParent->m_data ;
		}else{	
			cout << " n'a pas de parents";
		}
		cout << " et pour enfants " ;
		for(unsigned int i=0; i<m_children.size();i++){

			cout << m_children[i]->m_data << " ";
		}
		cout << endl;
	}
};

int main(){
	// par defaut un noeud est une racine => pointeur null pour le pere
	// dans les parentheses : on a la valeur contenu par le noeud
	Node node0(0);
	Node node1(1);
	Node node2(3);
	Node node3(2);
	Node node4(4);
	
	//node2=node0.mergeWith(node1);
	//node4=node2.mergeWith(node3);

	node2.hasForChildren(node0,node1);
	node4.hasForChildren(node2,node3);
	/*node0.print_node();
	cout <<" adresse node0 :" << &node0 << endl;
	node1.print_node();
	node2.print_node();
	node3.print_node();
	node4.print_node();*/
	node4.Dfs();

	//construit un arbre avec node0 et node1 qui ont pour pere node2
	// node2 et node3 qui ont pour pere node4

	
	//node4.isRoot();
	// parcours de l'arbre 
	//node4.Dfs();
}