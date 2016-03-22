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
	Coal(){}

	Coal(unsigned int id) :
	m_pere(0),
	m_id(id),
	m_gen(0)
	{	}

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
Coal find_coal(vector<Coal> vec,unsigned int id){
	unsigned int i=0;
	while(vec[i].get_id()!=id){
		i++;
	}
	//vec[i].affi();
	return vec[i];
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
int simulate(int N,int& compt){
	int lineage_1;
	int lineage_2;
	
	lineage_1=random_nb(N);
	lineage_2=random_nb(N);

	while(lineage_1!=lineage_2){
		//lineage_1=random_nb(N);
		lineage_2=random_nb(N);
		compt++;
	}
	return compt+1;
}



int main(){
	int k=4;
	vector<Coal> res;
	res.size();
	vector<int> vec_possible;
	for(int i=0;i<2*k-1;i++){
		Coal obj(i);
		res.push_back(obj);
		obj.affi();
	}
	while(vec_possible.size()>=2){

	}
	cout << " le vecteur "<<endl;
	affi_vec_coal(res);

}