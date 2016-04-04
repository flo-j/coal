#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

class Visitor;
#include "visitor.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>
#include <queue>
class Node{

//private:
private:
	Node* pParent = nullptr; 
	std::vector<Node*> m_children; // vecteur de reference sur les enfants : evite la copie.. 
	// std::reference_wrapper
	int m_data; // attention à terme ça devrait etre autre chose qu'un int.. voir comment utiliser les using !


public:

	Node(){} // constructeur par defaut 

	Node(int data){ // si on y ajoute des données
		pParent=nullptr;
		m_data=data;
	} 
	Node* get_parent() const{
		return pParent;
	}
	std::vector<Node*> get_children() const{
		return m_children;
	}
	int get_data() const{
		return m_data;
	}

	void AddAChild(Node* node1){
		m_children.push_back(node1);
	}

	void AddChildren(Node &node1, Node &node2){
		//
		node1.pParent=this; // normalement this correspond au pointeur qui pointe sur le pere ..
		node2.pParent=this;
		AddAChild(&node1);
		AddAChild(&node2);
	}

	bool hasChildren(){
		return !m_children.empty();
	}
	void RemoveNode(){
		// tant qu'il a des fils
		while(this.hasChildren()){
			this.get_children()[1].RemoveNode();
		}
		delete this;
	}

	Visitor Bfs(Visitor& v) const ;
	Visitor Bfs(Visitor& v) ;

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
