/* 	florence jornod
	aucune garantie
	g++ -Wall -std=c++11 node_test.cpp visitor.cpp node.cpp
*/
#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <queue>

template<typename T>
class Visitor;

template <typename T>
class Node{

private:
	Node<T>* pParent = nullptr; 
	std::vector<Node<T>*> m_children;
	T m_data;


public:

	Node(){} // constructeur par defaut

	Node(T data) : pParent(nullptr), m_data(data)
	{} 

	Node<T> get_parent() const{
		if(hasParent()){
			return *pParent;
		}else{
			throw std::string("no existing parent, please check current instance of Node has parent.");
		}
	}
	
	T get_data() const{
		return m_data;
	}

	void AddAChild(Node<T>& node1){
		m_children.push_back(&node1);
	}

	void AddChildren(Node<T> &node1, Node<T> &node2){
		//
		node1.pParent=this; // normalement this correspond au pointeur qui pointe sur le pere ..
		node2.pParent=this;
		AddAChild(node1);
		AddAChild(node2);
	}

	bool hasChildren() const{
		return !m_children.empty();
	}

	bool hasParent() const{
		if(pParent){
			return true;
		}else{
			return false;
		}
	}

	Visitor<T> Bfs(Visitor<T>& v) const ;
	Visitor<T> Bfs(Visitor<T>& v) ;

	void print_node() const{
		std::cout << " le noeud :" ;
		std::cout << m_data ;
		std::cout << " et l'adresse est :";
		std::cout << this;

		if(pParent!=0){
			std::cout <<" a pour parent :";
			std::cout << pParent << " de valeur : " ;
			std::cout << pParent->m_data ;
		}else{	
			std::cout << " n'a pas de parents";
		}
		std::cout << " et pour enfants " ;

		for(unsigned int i=0; i<m_children.size();i++){
			std::cout << m_children[i]->m_data << " ";
		}

		std::cout << std::endl;
	}
};

template<typename T>
class Visitor{

private:

	std::vector<T> res;

public:

	void visit(const Node<T>* node){
		res.push_back(node->get_data());
	}

	std::vector<T> get_vect()  {
		return res;
	}
};


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

#endif

