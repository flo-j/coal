#include <iostream>
#include <map>
#include <random>

int main(){

	std::map<int,int> pop_flux;
	pop_flux[1]=4;
	pop_flux[2]=7;
	pop_flux[4]=3;
	std::multimap<int,int> m_roots;
	std::pair <std::multimap<int,int>::iterator, std::multimap<int,int>::iterator> roots_it;
	m_roots.insert(std::make_pair(0,0));
	m_roots.insert(std::make_pair(0,1));
	m_roots.insert(std::make_pair(0,2));
	std::vector<int> flux;
	std::vector<int> coord;
	std::multimap<int,int>::iterator it=roots_it.first;
	//for(std::multimap<int,int>::iterator it=roots_it.first;it==roots_it.second;it++){
	do{
		for(std::map<int,int>::iterator it=pop_flux.begin(); it!=pop_flux.end(); ++it){
			std::cout << "coord : " << it->first << " nb_ind : " << it->second << std::endl;
	        coord.push_back(it->first);
	        flux.push_back(it->second);
	    } 
	    if(it==roots_it.second){
	    	break;
	    }
	 //}   
	}while(0);
}