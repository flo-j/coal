#include <iostream>
#include <map>
#include <random>
// version avec une map de vecteur 

int main(){

	using coord_type = unsigned int;
	using nb_ind_type = unsigned int;
	using lineage_type = unsigned int;

	// pop_flux describes the individuals going from different demes to the deme of interest
	std::map<coord_type, nb_ind_type> pop_flux;
	pop_flux[1]=4;
	pop_flux[2]=7;
	pop_flux[4]=3;


	std::map<coord_type, std::vector<lineage_type>> m_roots;
	m_roots[0].push_back(0);
	m_roots[0].push_back(1);
	m_roots[0].push_back(2);
	m_roots[1].push_back(3);
	m_roots[1].push_back(4);
	m_roots[1].push_back(5);
	
	// Isolating the key coords and the flux values. Caution : indices CAN NOT change
	std::vector<nb_ind_type> flux;
	std::vector<coord_type> coords;

	for( auto i_flux = pop_flux.begin(); i_flux != pop_flux.end(); ++i_flux){
			std::cout << "coord : " << i_flux->first << " nb_ind : " << i_flux->second << std::endl;
			coords.push_back(i_flux->first);
        	flux.push_back(i_flux->second);
    }

    // Create a new temporary roots holder to move lineages into
	std::map<coord_type, std::vector<lineage_type>> roots_temp;

	// Iterate over couples demes/lineages
	for(auto it = m_roots.begin(); it != m_roots.end(); ++it){
		std::cout << it->first << "\n" ;
		// appel de la fonction pop_flux;
		// XXX; A REMETTRE ICI! CAR A TERME POP_FLUX SERA DEFINI ICI AUSSI!!
		/*for( auto it2=pop_flux.begin(); it2!=pop_flux.end();++it2){
			std::cout << "coord : " << it2->first << " nb_ind : " << it2->second << std::endl;
			coords.push_back(it2->first);
        	flux.push_back(it2->second);
        }*/

        std::random_device rd;
   		std::mt19937 gen(rd());
    	std::discrete_distribution <int> dist(flux.begin(),flux.end());

    	for(auto lineage : it->second){
    		unsigned int arrival_ID = dist(gen);
    		coord_type arrival = coords[arrival_ID];
    		std::cout << lineage << "\t" ;
    		std::cout << "arrival " << arrival << "arrival coordinates" << arrival << std::endl;
    		roots_temp[arrival].push_back(lineage);
    	}

    	std::cout << std::endl;
	}

	for(auto it = roots_temp.begin(); it != roots_temp.end(); ++it){
		std::cout << it->first << "\t";
		for(auto root : it->second){
			std::cout << root << "\t";
		}
		std::cout << std::endl;
	}


}