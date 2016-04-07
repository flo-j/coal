// architecture (= algorithme) de la coalescence 


vector<Node> simulate(Demography& demo){
	collection<lieu ; vector<Node&> > availableSpace; // les lieux et qui il y a 
	// initialisation A METTRE DABS inistantiates_roots() 
	for(auto & demo_case : demo.space){ // demo.space étant les cases pleines à la fin de la demographie (ou les cases où il y a des alleles au niveau genetique)
		pop_size=N(demo_case,t=0); // pour la case en cours on trouve sa contenance au temps 0 (cad le temps qui nous interesse et qui sera le debut de la coalescence)
		availableSpace.add(demo_case,pop_size); // dans chaque case on a le nombre de pers et sa case
		// indetermination : qui sait où sont les noeud..
		for(int i=0; i < pop_size; i++){
			new Node; // creation d'un nouveau noeud
			rootHolder.add(Node);
			availableSpace.vec.add(Node&);
		}
	}

	while(rootHolder.size()!=1 || !demo.end_time()){ // rootholder est un attribut de la class Coalescence et demo.end_time() parcours les temps 
		 // les espaces dans lesquels je dispatche des individus

		


		for(auto& space : availableSpace){
			// algo de coalescence
		}


	}
}
bool demo_validy(){
	// pour chaque coord de la genetique
	// si elle n'existe pas dans la demo ou que pas assez de frelon (= allele)
	// return false
	//fdp
	// return true
}

vector<Nodes> instantiates_roots(){ // retourne le vecteur des racines possibles pour la coalescence
	if(!demo_validy()){} // erreur genre try catch mais voir comment ça marche..
	collection < lieu; vector<Node>> ; // on y passe les node par reference, voir si ça peut marcher
	

}



class CoalescenceSimulator{
private:
		m_dataSet
		m_demography
		m_roots

public:
	Simulator(Genetics genet, Demography demo) : m_dataSet(genet), m_demography(demo), m_roots(inistantiates_roots()/*evite d'avoir le bordel en public */){
		/*if(...)
			throw ...

		 //roots_type rootHodler = ... */
	}

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
