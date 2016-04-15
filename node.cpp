/* 	florence jornod
	aucune garantie
	g++ -Wall -std=c++11 node_test.cpp visitor.cpp node.cpp
*/
#include "visitor.h"

template<typename T>
Visitor<T> Node<T>::Bfs(Visitor<T>& v){

		Node<T>* next;
		std::queue<Node<T>*> waiting;
		waiting.push(this);

		while(!waiting.empty()){

			Node<T>* current = waiting.front();
			waiting.pop();
			v.visit(current);

			for(auto child : current->m_children){
				next = child;
				waiting.push(next);
			}
		}
		return v;
	}

template<typename T>
Visitor<T> Node<T>::Bfs(Visitor<T>& v) const{
		const Node<T>* next;
		std::queue<const Node<T>*> waiting;
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