
#include "visitor.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>
#include <queue>
void Visitor::visit( Node* node){ // const Node& node
		res.push_back(node->get_data());
}

