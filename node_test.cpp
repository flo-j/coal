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
#include <cassert> // include "assert.h"

#include "visitor.h"

	Visitor Node::Bfs(Visitor& v){

		Node* next;
		std::queue<Node*> waiting;
		waiting.push(this);

		while(!waiting.empty()){

			Node* current = waiting.front();
			waiting.pop();
			v.visit(current);

			for(auto child : current->m_children){
				next = child;
				waiting.push(next);
			}
		}
		return v;
	}

	Visitor Node::Bfs(Visitor& v) const{
		
		const Node* next;
		std::queue<const Node*> waiting;
		waiting.push(this);

		while(!waiting.empty()){

			const auto current_Node = waiting.front();
			waiting.pop();
			v.visit(current_Node);

			for(auto child : current_Node->get_children()){
				next = child;
				waiting.push(next);
			}
		}
		return v;
	}

	// XXX
void aff_vec(std::vector<int> vec) { // surcharge opérateur <<

	for(auto v : vec){
		std::cout << v << " ";
	}
	std::cout << std::endl;
}


int main(){
	using std::cout;
	using std::endl;
	// par defaut un noeud est une racine => pointeur null pour le pere
	// dans les parentheses : on a la valeur contenu par le noeud
	Node node0(0);
	Node node1(1);
	Node node2(3);
	Node node3(2);
	Node node4(4);

	node2.AddChildren(node0,node1);
	node4.AddChildren(node2,node3);
	
	std::vector<int> test;

	test.push_back(4);
	test.push_back(3);
	test.push_back(2);
	test.push_back(0);
	test.push_back(1);


	Visitor v;
	v=node4.Bfs(v); 
	
	// test 
	aff_vec(v.get_vect());
	aff_vec(test);
	assert(v.get_vect()==test);
	node4.print_node();
	try{
		node4.get_parent();
	}
	catch(std::string e){
		cout << e << endl;
	}
	cout << "douze" << endl;
}