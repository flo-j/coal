/* 	florence jornod
	aucune garantie
*/
class Node{
	Node* pParent; // a terme une paire? vu que deux parents.. mais louche.. 
	vector <Node&> m_children; // vecteur de reference sur les enfants : evite la copie.. 
	String m_status; // pour les parcours!
	int m_data; // attention à terme ça devrait etre autre chose qu'un int.. voir comment utiliser les using !

	Node(pParent=nullptr,m_status="non atteint"){} // constructeur par defaut 
	Node(pParent=nullptr,m_status="non atteint",int data){ // si on y ajoute des données
		m_data=data;
	} 


void mergeWith(Node node1){

}

};

int main(){
	// par defaut un noeud est une racine => pointeur null pour le pere
	// dans les parentheses : on a la valeur contenu par le noeud
	Node node0(0);
	Node node1(1);
	Node node2(3);
	Node node3(2);
	Node node4(4);
	
	node2=node0.mergeWith(node1);
	node4=node2.mergeWith(node3);
	//construit un arbre avec node0 et node1 qui ont pour pere node2
	// node2 et node3 qui ont pour pere node4

	
	node4.isRoot();
	// parcours de l'arbre 
	node4.Dfs();
}