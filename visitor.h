#ifndef __VISITOR_H_INCLUDED__
#define __VISITOR_H_INCLUDED__

#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>
#include <queue>
class Node;

class Visitor{

public:

	void visit(const Node* node);

	std::vector<int> get_vect()  {
		return res;
	}

private:

	std::vector<int> res;

};

#endif