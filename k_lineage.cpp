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

int find_coal_in_vec(vector<Coal> vec, unsigned int id){
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
	for(int i=0; i<k;i++){
		vec.push_back(i);
	}
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

void update_coal(vector<unsigned int>& vec,vector<Coal>& res,unsigned int& k,unsigned int& nb_gen,unsigned int N) {
	int position_in_res;
	int position_in_vec;
	int coal_target;
	
	position_in_vec=random_nb(vec.size())-1;
	position_in_res=vec[position_in_vec];
	coal_target=find_coal_in_vec(res,position_in_res);


	res[coal_target].set_pere(k);
	res[coal_target].set_gen(nb_gen);

	vec.erase(vec.begin()+position_in_vec);
}

void find_filiation(vector<unsigned int>& vec,vector<Coal>& res,unsigned int& k,unsigned int& nb_gen,unsigned int N,unsigned int nb_coal){
	nb_gen+=simulate(N);
	for(unsigned int i=0;i<nb_coal;i++){
		update_coal(vec,res,k,nb_gen,N);
	}
	vec.push_back(k);
	k++;
}
.
int main(){
	unsigned int k=10;
	unsigned int N=k;
	vector<Coal> res;
	res.size();
	vector<unsigned int> vec_possible;
	init_vec(vec_possible,k);
	unsigned int nb_gen=0;
	for(unsigned int i=0;i<2*k-1;i++){
		Coal obj(i);
		res.push_back(obj);
	}
	while(vec_possible.size()>=2){
		find_filiation(vec_possible,res,k,nb_gen,N,2);
	}
	affi_vec_coal(res);
}