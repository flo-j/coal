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
#include <cassert>

#include "visitor.h"

	Visitor Node::Dfs(Visitor& v){
		Node* root;
		Node* next;
		std::queue<Node*> waiting;
		waiting.push(this);

		while(!waiting.empty()){
			
			root = waiting.front();
			waiting.pop();
			v.visit(root);
			std::cout << root->m_data << " " ;
			for(auto child: m_children){
				next = root->m_ch;
				st.push(next);
			}
		}
		return v;
	}
void aff_vec(std::vector<int> vec){ // surcharge opérateur <<
	std::cout << std::endl;
	for(unsigned int i=0;i<vec.size();i++){
		std::cout << vec[i] << "\t";
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
	std::vector<int> test;
	test.push_back(4);
	test.push_back(3);
	test.push_back(2);
	test.push_back(0);
	test.push_back(1);

	node2.hasForChildren(node0,node1);
	node4.hasForChildren(node2,node3);
	v=node4.Dfs(v); 
	aff_vec(v.get_vect());
	aff_vec(test);
	assert(v.get_vect()==test);
}