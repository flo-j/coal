/* 	florence jornod
	aucune garantie
	g++ -Wall -std=c++11 node_test.cpp visitor.cpp node.cpp
*/
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

			for(auto child : current_Node->m_children){
				next = child;
				waiting.push(next);
			}
		}
		return v;
	}