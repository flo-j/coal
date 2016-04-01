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
#include "visitor.h"

	Visitor Node::Bfs(Visitor& v) {
		Node* r;
		Node* voisin;
		queue<Node*> st;
		st.push(this);
		while(!st.empty()){
			r=st.front();
			st.pop();
			v.visit(r);
			cout << r->m_data << " " ;
			for(unsigned int i=0;i<r->m_children.size();i++){
				voisin=r->m_children[i];
				st.push(voisin);
			}
		}
		return v;
	}

void aff_vec(vector<int> vec){ // surcharge opérateur <<
	for(int i=0;i<vec.size();i++){
		cout << vec[i] << "\t";
	}
}
int main(){
	// par defaut un noeud est une racine => pointeur null pour le pere
	// dans les parentheses : on a la valeur contenu par le noeud
	Node node0(0);
	Node node1(1);
	Node node2(3);
	Node node3(2);
	Node node4(4);
	Visitor v;
	
	//node2=node0.mergeWith(node1);
	//node4=node2.mergeWith(node3);

	node2.AddChildren(node0,node1);
	node4.AddChildren(node2,node3);
	node0.print_node();
	cout <<" adresse node0 :" << &node0 << endl;
	node1.print_node();
	node2.print_node();
	node3.print_node();
	node4.print_node();
	v=node4.Bfs(v);
	v=node4.Bfs(v);
	v.get_vect();
	aff_vec(v.get_vect());
	//construit un arbre avec node0 et node1 qui ont pour pere node2
	// node2 et node3 qui ont pour pere node4

	
	//node4.isRoot();
	// parcours de l'arbre 
	//node4.Dfs();
}