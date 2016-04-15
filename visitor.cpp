/* 	florence jornod
	aucune garantie
	g++ -Wall -std=c++11 node_test.cpp visitor.cpp node.cpp
*/
#include "visitor.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>
#include <queue>
void Visitor::visit(const Node* node){ // const Node& node
		res.push_back(node->get_data());
}

