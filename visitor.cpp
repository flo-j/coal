/* 	florence jornod
	aucune garantie
	g++ -Wall -std=c++11 node_test.cpp visitor.cpp node.cpp
*/
#include "visitor.h"

template<typename T>
void Visitor<T>::visit(const Node<T>* node){ // const Node& node
		res.push_back(node->get_data());
}

