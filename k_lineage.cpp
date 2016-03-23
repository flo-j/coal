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


int find_coal(vector<unsigned int> vec,unsigned int id){
	unsigned int i=0;
	cout << "douze" << endl;
	while(vec[i]!=id){
		cout << vec[i] << " " << id << endl;
		i++;
	}
	//vec[i].affi();
	return i;
}
int find_c(vector<Coal> vec, unsigned int id){
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
void init_vec(vector<unsigned int>& vec,int k){ // initialise le vecteur des possibles 
	//cout << "initialise" << endl;
	for(int i=0; i<k;i++){
		vec.push_back(i);
	}
	//cout << "fin initialise" << endl;
}
void aff_vec(vector<unsigned int>& vec){
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
void trouve_test(vector<unsigned int>& vec,vector<Coal>& res,unsigned int& k,unsigned int& nb_gen,unsigned int N) {
	int coal_a_modifier;
	int place_coal_a_modifier;
	int nb_ale;
	int celui_quon_veut;
	nb_ale=random_nb(vec.size()-1);
	cout << "nombre aleatoire" << nb_ale << endl;
	place_coal_a_modifier=vec[nb_ale];
	cout << "le coal n°" << nb_ale <<" se trouve en postion " << place_coal_a_modifier << endl;
	aff_vec(vec);
	coal_a_modifier=vec[place_coal_a_modifier];
	cout << "celui qu'on veut " << nb_ale << endl;
	celui_quon_veut=find_c(res,coal_a_modifier);
	//cout << "coal a modifier " << coal_a_modifier << "a la base " << nb_ale << endl;
	res[celui_quon_veut].affi();
	res[celui_quon_veut].set_pere(k);
	res[celui_quon_veut].set_gen(nb_gen);
	res[celui_quon_veut].affi();
	vec.erase(vec.begin()+place_coal_a_modifier);
	aff_vec(vec);

}

void fait_tout(vector<unsigned int>& vec,vector<Coal>& res,unsigned int& k,unsigned int& nb_gen,unsigned int N,unsigned int nb_coal){
	nb_gen+=simulate(N);
	for(unsigned int i=0;i<nb_coal;i++){
		trouve_test(vec,res,k,nb_gen,N);
	}
	k++;
	vec.push_back(k);
	
}

int main(){
	unsigned int k=4;
	unsigned int N=k;
	vector<Coal> res;
	res.size();
	vector<unsigned int> vec_possible;
	init_vec(vec_possible,k);
	unsigned int nb_gen=0;
	vector<unsigned int> vec_test;
	int var_test;
	vec_test.push_back(3);
	vec_test.push_back(0);
	vec_test.push_back(1);
	vec_test.push_back(2);
	aff_vec(vec_test);
	var_test=find_coal(vec_test,1);
	cout << "var test : " << var_test << endl;
	
	for(unsigned int i=0;i<2*k-1;i++){
		Coal obj(i);
		res.push_back(obj);
		//obj.affi();
			}
	/*while(vec_possible.size()>=2){
		cout << "dans le while " << endl;
	//for(int i=0;i<4;i++){
		//cout << "taille du vecteur des possibles" << vec_possible.size() << endl;
		trouve_2suiv(vec_possible,res,k,nb_gen,N);
		//affi_vec_coal(res);

	}*/
	fait_tout(vec_test,res,k,nb_gen,N,2);
	//trouve_2suiv(vec_possible,res,k,nb_gen,N);	

	//cout << " le vecteur "<<endl;
	//affi_vec_coal(res);

}