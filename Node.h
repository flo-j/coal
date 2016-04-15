/* 	florence jornod
	aucune garantie
	g++ -Wall -std=c++11 node_test.cpp visitor.cpp node.cpp
*/
#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

//class Visitor;
//#include "visitor.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>
#include <queue>

template <typename T> 
class Node{

//private:
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

	//Visitor Bfs(Visitor& v) const ;
	//Visitor Bfs(Visitor& v) ;

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

#endif
