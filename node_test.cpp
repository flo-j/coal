/* 	florence jornod
	aucune garantie
	g++ -Wall -std=c++11 node_test.cpp visitor.cpp node.cpp
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
	Node node1(10);
	Node node2(30);
	Node node3(20);
	Node node4(40);

	//node2.AddChildren(node0,node1);
	node2.AddAChild(node0);
	node2.AddAChild(node1);
	node4.AddChildren(node2,node3);
	
	/* tree :
			40
		   /  \
		  30   30
		 /  \
	    0    10
	*/
	std::vector<int> test;

	test.push_back(40);
	test.push_back(30);
	test.push_back(20);
	test.push_back(0);
	test.push_back(10);


	Visitor v;
	v=node4.Bfs(v); 
	
	// test 
	aff_vec(v.get_vect());
	aff_vec(test);
	assert(v.get_vect()==test);

	try{
		node4.get_parent();
	}
	catch(std::string e){
		cout << e << endl;
	}
}