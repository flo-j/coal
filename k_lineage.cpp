//test de la poo ... 
#include <iostream>
#include <random>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;  
class Coal{
	// attributs
private:
	unsigned int m_pere; // reflechir aux noms des variables .. 
	unsigned int m_id;
	unsigned int m_gen; // nb de generation avant de coalescer
	// methodes
public:	
	void affi(){
		//cout << " douze" << endl ;
		cout << "id :" << m_id << " pere : " << m_pere << " temps :" << m_gen << endl;
	}

	//constructeur 
	Coal(){} // pourquoi c'est necessaire ? a chercher

	Coal(unsigned int id) :
	m_pere(0),
	m_id(id),
	m_gen(0)
	{	}

	// les méthodes 
	void set_pere(unsigned int pere){
		m_pere=pere;
	}
	void set_gen(unsigned int gen){
		m_gen=gen;
	}
	unsigned int get_id(){
		return m_id;
	}
};


int find_coal(vector<Coal> vec,unsigned int id){
	unsigned int i=0;
	while(vec[i].get_id()!=id){
		i++;
	}
	//vec[i].affi();
	return i;
}
void affi_vec_coal(vector<Coal> res){
	for(unsigned int i=0;i<res.size();i++){
		res[i].affi();
	}
}

int random_nb(int N){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1,N);
	return dis(gen);
}
void init_vec(vector<int>& vec,int k){ // initialise le vecteur des possibles 
	//cout << "initialise" << endl;
	for(int i=0; i<k;i++){
		vec.push_back(i);
	}
	//cout << "fin initialise" << endl;
}
void aff_vec(vector<int>& vec){
	for(unsigned int i=0;i<vec.size();i++){
		cout << vec[i] << "\t";
	}
	cout << endl;
}

int simulate(int N){
	int lineage_1;
	int lineage_2;
	int compt=0;
	lineage_1=random_nb(N);
	lineage_2=random_nb(N);

	while(lineage_1!=lineage_2){
		//lineage_1=random_nb(N);
		lineage_2=random_nb(N);
		compt++;
	}
	return compt+1;
}

void trouve_2suiv(vector<int>& vec,vector<Coal>& res, unsigned& k,unsigned int& nb_gen,unsigned int N){
	unsigned int first;
	unsigned int second;
	int c_first;
	int c_second;
	//cout << k << endl;
	first=random_nb(vec.size())-1;
	c_first=find_coal(res,first);
	cout << " c_first " << c_first << " first " << first << endl;
	cout << " res[c_first]" << endl;
	res[c_first].affi();
	res[c_first].set_pere(k);
	cout << "res[c_first].setpere" << endl;
	res[c_first].affi();
	//cout << " c_first " << c_first << " first " << first << endl;
	cout << "affichage vecteur des possibles" << endl;
	aff_vec(vec);
	//cout << "dans trouve_2 " << vec.size() << endl;
	vec.erase(vec.begin()+first);
	aff_vec(vec);
	//cout << "dans trouve_2 " << vec.size() << endl;
	second=random_nb(vec.size())-1;
	c_second=find_coal(res,second);
	cout << " c_second " << c_second << " second " << second << endl;
	cout << " res[c_second]" << endl;
	res[c_second].affi();
	res[c_second].set_pere(k);
	res[c_second].affi();
	aff_vec(vec);
	vec.erase(vec.begin()+second);
	aff_vec(vec);
	vec.push_back(k);
	aff_vec(vec);
	k++;
	nb_gen+=simulate(N);
	res[c_first].set_gen(nb_gen);
	//c_first.affi();
	res[c_second].set_gen(nb_gen);
	//c_second.affi();

}

int main(){
	unsigned int k=4;
	unsigned int N=k;
	vector<Coal> res;
	res.size();
	vector<int> vec_possible;
	init_vec(vec_possible,k);
	unsigned int nb_gen=0;
	for(unsigned int i=0;i<2*k-1;i++){
		Coal obj(i);
		res.push_back(obj);
		//obj.affi();
			}
	while(vec_possible.size()>=2){
	//for(int i=0;i<4;i++){
		//cout << "taille du vecteur des possibles" << vec_possible.size() << endl;
		trouve_2suiv(vec_possible,res,k,nb_gen,N);
		//affi_vec_coal(res);

	}
	cout << " le vecteur "<<endl;
	affi_vec_coal(res);

}