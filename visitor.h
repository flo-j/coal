/* 	florence jornod
	aucune garantie
	g++ -Wall -std=c++11 node_test.cpp visitor.cpp node.cpp
*/
#ifndef __VISITOR_H_INCLUDED__
#define __VISITOR_H_INCLUDED__

#include "Node.h"
#include <vector>

template<typename T>
class Node;

template<typename T>
class Visitor{

private:

	std::vector<T> res;

public:

	void visit(const Node<T>* node);

	std::vector<T> get_vect()  {
		return res;
	}



};

#endif