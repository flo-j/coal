#include <iostream>
#include <map>
#include <random>
#include <algorithm>
// version avec une map de vecteur 
using coord_type = unsigned int;
using nb_ind_type = unsigned int;
using lineage_type = unsigned int;


void aff_map_roots(std::map<coord_type, std::vector<lineage_type>> roots){
	for(auto it = roots.begin(); it != roots.end(); ++it){
		std::cout <<"coord n° " << it->first << "\t";
		for(auto root : it->second){
			std::cout << root << "\t";
		}
		std::cout << std::endl;
	}
}
int random_nb(int N){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1,N);
	return dis(gen);
}
template<class Cle, class T> 
void AfficherMultimap(const std::multimap<Cle, T>& m) 
{ 
  typedef typename std::multimap<Cle, T>::const_iterator  Itor; 
  std::cout << "\n multi map \n" ;
  for (Itor i = m.begin(); i != m.end(); ++i) 
    std::cout << i->first << "\t" << i->second << "\n"; 
 std::cout << "\n"; 
} 

int main(){
	/*
	using coord_type = unsigned int;
	using nb_ind_type = unsigned int;
	using lineage_type = unsigned int;
	*/
	// pop_flux describes the individuals going from different demes to the deme of interest
	std::map<coord_type, nb_ind_type> pop_flux;
	pop_flux[1]=4;
	//pop_flux[2]=7;
	//pop_flux[4]=3;


	std::map<coord_type, std::vector<lineage_type>> m_roots;
	int ind=0;
	m_roots[0].push_back(ind);
	ind++;
	m_roots[0].push_back(ind);
	ind++;
	m_roots[0].push_back(ind);
	ind++;
	m_roots[1].push_back(ind);
	ind++;
	m_roots[1].push_back(ind);
	ind++;
	//m_roots[1].push_back(ind);
	ind++;
	//

		
	// Isolating the key coords and the flux values. Caution : indices CAN NOT change
	//std::vector<nb_ind_type> flux;
	//std::vector<coord_type> coords;
	

	
	int tcoal=0;
	while(!(m_roots.size()==1 && m_roots.begin()->second.size()==1)){ 
		
		// Isolating the key coords and the flux values. Caution : indices CAN NOT change
		std::vector<nb_ind_type> flux;
		std::vector<coord_type> coords;
		for( auto i_flux = pop_flux.begin(); i_flux != pop_flux.end(); ++i_flux){
				coords.push_back(i_flux->first);
	        	flux.push_back(i_flux->second);
	    }

	    // Create a new temporary roots holder to move lineages into
		std::map<coord_type, std::vector<lineage_type>> roots_temp;

		// Iterate over couples demes/lineages
		for(auto it = m_roots.begin(); it != m_roots.end(); ++it){
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
	    		roots_temp[arrival].push_back(lineage);
	    	}
		}
	
		m_roots.clear();
		m_roots=roots_temp;
		for(auto it = m_roots.begin(); it != m_roots.end(); ++it){ // pour tous les lieux de m_roots
			//on recupere la taille de pop
			nb_ind_type N=12;

			std::map<unsigned int,std::vector<lineage_type>> temp;
			for(auto root : it->second){
				int random=random_nb(N);
				temp[random].push_back(root);
			}

			for(auto it2=temp.begin();it2!=temp.end();++it2){
				if(it2->second.size()>1){
					for(auto indi : it2->second){
						auto pos=std::distance(it->second.begin(),std::find(it->second.begin(),it->second.end(),indi));
						it->second.erase(it->second.begin()+pos);

					}
					it->second.push_back(ind);
					ind++;
					
				}
			}
		}

		++tcoal;
	}
	std::cout << "bien joué ta coal est terminée !" << std::endl;
	std::cout << " ça a pris " << tcoal << " generations !" <<std::endl;
}