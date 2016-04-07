// architecture (= algorithme) de la coalescence 


vector<Node> simulate(Demography& demo){
	collection<lieu ; vector<Node&> > availableSpace; // les lieux et qui il y a ESTCE QUE CA SERAIT M_ROOTS ?? 
	
	// initialisation A METTRE DABS inistantiates_roots() 
	/*for(auto & demo_case : demo.space){ // demo.space étant les cases pleines à la fin de la demographie (ou les cases où il y a des alleles au niveau genetique)
		pop_size=N(demo_case,t=0); // pour la case en cours on trouve sa contenance au temps 0 (cad le temps qui nous interesse et qui sera le debut de la coalescence)
		availableSpace.add(demo_case,pop_size); // dans chaque case on a le nombre de pers et sa case
		// indetermination : qui sait où sont les noeud..
		
		for(int i=0; i < pop_size; i++){
			new Node; // creation d'un nouveau noeud
			rootHolder.add(Node);
			availableSpace.vec.add(Node&);
		}
	}*/

		// dans ce while surement qu'il faut plutot mettre directement la deuxieme condition d'arret que de mettre 
	while(m_roots.size()!=1 || !m_demography.end_time()){ // m_roots est un attribut de la class Coalescence et m_demography.end_time() verifie si le temps doit s'arreter 
		 // on dispatche les individus (on modifie roots)
		


		for(auto& space : availableSpace){
			// algo de coalescence
		}


	}
}
bool demo_validity() const{
	// pour chaque coord de la genetique
	// si elle n'existe pas dans la demo ou que pas assez de frelon (= allele)
	// return false
	//fdp
	// return true
	//VERIFIER LE TEMPS AUSSI ! ( MEME AVANT!!)
}

// FAUT IL DISTINGUER ROOTS ET UN TRUC QUI A ROOTS+ POSITION
vector<Node> instantiates_roots(){ // retourne le vecteur des racines possibles pour la coalescence
	if(!demo_validity()){} // erreur genre try catch mais voir comment ça marche..
	collection < lieu; vector<Node>> roots; // => contient pour chaque position les racines disponibles | on y passe les node par reference, voir si ça peut marcher 
	for(auto& pos : gen.position){ // pour tous les positions disponibles via le jeu de données genet
		roots.lieu.add(lieu); // PAS UN ADD MAIS POUR VISUALISER QU'ON AJOUTE LE LIEU AU VECTEUR !!
		//auto pop_size=gen.position.NbInd; // le nombre de gens pour chaque case A METTRE LIMITE DIRECT DANS LA BOUCLE SUIVANTE!!
		for(auto ind : gen.position.NbInd){
			new Node; // creation d'un nouveau noeud
			roots.vec.add(Node&); // au passage ne pas oublier de l'ajouter dans le nodeholder (limite ca doit se faire avec le new ..)	
		}
	}
	return roots;
}



class CoalescenceSimulator{
private:
	m_dataSet
	m_demography
	collection < lieu; vector<Node>> m_roots;
public:
	Simulator(Genetics genet, Demography demo) : m_dataSet(genet), m_demography(demo), m_roots(inistantiates_roots()/*evite d'avoir le bordel en public */){
		/*if(...)
			throw ...

		 //roots_type rootHodler = ... */
	}

main :
Demography demo = DemoSimul.simul()
DatSet = read.dat(file)

CoalescenceSimulator simulator1(data, demo1);
CoalescenceSimulator simulator2(data, demo2);
auto coal = simulator1.simul();

using Coalescent = Node<tuple<int, string, coords> >

// Deuxieme solution
CoalescenceSimulator simulator();
Coalescent coal1 = simulator.simul(data, demo1)
Coalescent coal2 = simulator.simul(data, demo2)

// Troisieme solution
Coalescent coal1 = Simulator::simul(data, demo1)
Coalescent coal2 = Simulator::simul(data, demo2)


}

