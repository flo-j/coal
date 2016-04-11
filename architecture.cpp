// architecture (= algorithme) de la coalescence 

vector<Node> simulate(Demography& demo){
	collection<lieu ; vector<Node&> > availableSpace; // les lieux et qui il y a ESTCE QUE CA SERAIT M_ROOTS ?? 
	
	// initialisation A METTRE DABS inistantiates_roots() 
	/*for(auto & demo_case : demo.space){ // demo.space étant les cases pleines à la fin de la demographie (ou les cases où il y a des alleles au niveau genetique)
		pop_size=N(demo_case,t=0); // pour la case en cours on trouve sa contenance au temps 0 (cad le temps qui nous interesse et qui sera le debut de la coalescence)
		availableSpace.add(demo_case,pop_size); // dans chaque case on a le nombre de pers et sa case
		// indetermination : qui sait où sont les noeud..
		papa c'est quoi l'inceste?
		tais toi et suce
		for(int i=0; i < pop_size; i++){
			new Node; // creation d'un nouveau noeud
			rootHolder.add(Node);
			availableSpace.vec.add(Node&);
		}
	}*/
		// UN DES SOUCIS DE CE WHILE, C'EST LE RISQUE DE BOUCLE INFINI SI DEUX TRUCS TRES LOIN DANS LESPACE.. ENFIN PAS INFINI DANS LE SENS INFINI MAIS INCOMPATIBLE AVEC UNE REALITÉ

		// dans ce while surement qu'il faut plutot mettre directement la deuxieme condition d'arret que de mettre 
	while(m_roots.size()!=1 || !m_demography.end_time()){ // m_roots est un attribut de la class Coalescence et m_demography.end_time() verifie si le temps doit s'arreter 
		// on dispatche les individus (on modifie roots)
		
		//pour chaque case de roots => on itere sur les clés .. COMMENT ON FAIT AAAAAH
			map<coord,int> pop_flux=demo.pop_flux("AAAAAA c'est quoi les argu ??!"); // on recupere une map avec en clé les coord et en valeurs le nb d'ind 
			vector<int> flux;
			vector<COORD> coord; // type à definir ...
			for(std::map<coord,int>::iterator it=pop_flux.begin(); it!=pop_flux.end(); ++it){
        		coord.push_back(it->first);
        		flux.push_back(it->second);
    		} 
    		std::pair <std::multimap<coord,int>::iterator, std::multimap<coord,int>::iterator> trouver_un_nom; // des itetor pour iterer sur m_roots
    		trouver_un_nom = m_roots.equal_range(coord); 
    		multimap<coord,Node> roots_temp; // roots en construction 
    		std::random_device rd;
   			std::mt19937 gen(rd());
    		std::discrete_distribution <int> d(flux.begin(),flux.end());
			//pour chaque ind de roots dans la case 
    		for (std::multimap<coord,int>::iterator it=trouver_un_nom.first; it!=trouver_un_nom.second; ++it){
    			auto x=d(gen); // x correspond à la coordonné d'arrivée
    			// prendre en compte le cas où il n'y a qu'une case...
    			roots_temp.insert(make_pair(coord[x],it->second)); 
    		}
		}
		m_roots.clear();
		m_roots=roots_temp;
		roots_temp.clear();
			//fdp
		//fdp
		// ici il faut faire écrire les individus dans un nouveau vecteur comme il serait dans m_roots et ensuite il faudra remplacer l'ancien de m_root par celui la
		

		for(auto& space : m_roots.lieu){ // m_roots.lieu c'est le vecteur des endroits où il y a qqch.. ATTENTION IL FAUT VOIR COMMENT LE CODER
			// algo de coalescence
			int N = m_demography.N(space,t); // on demande à la démo le nombre de gens present au temps t dans la case où on est
			// pour chaque racine presente dans l'espace
			for(auto& root : m_roots.ind){
				// tirage d'un nombre aléatoire
				// rangement de ce nombre et de root dans une multimap
			}
			// pour chaque id de la map si elle a plus de deux roots 
			// creation d'un pere (nouveau noeud via le nodeholder)
			// modification des enfants
			// attribution du pere
			// on retire les enfants du vecteur roots et on y ajoute le pere
		}


	}
}
bool demo_validity() const{ 
	// pour chaque coord de la genetique
	// si elle n'existe pas dans la demo ou que pas assez de frelon (= allele) dispo
	// return false
	//fdp
	// return true
	//VERIFIER LE TEMPS AUSSI ! ( MEME AVANT!!) => si qu'un seul temps mm pas la peine d'aller plus loin
	// le fdp est evidemment un "fin du pour" et pas le code qui t'insulte ... >< 
}



// FAUT IL DISTINGUER ROOTS ET UN TRUC QUI A ROOTS+ POSITION
vector<Node> instantiates_roots(){ // retourne le vecteur des racines possibles pour la coalescence
	if(!demo_validity()){throw String("AAAH")} // erreur genre try catch mais voir comment ça marche..
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
	collection < lieu; vector<Node>> m_roots; // surement une multimap <lieu, node>
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

