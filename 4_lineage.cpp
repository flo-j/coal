/* 
Florence JORNOD
Ce script est fourni sans aucune garantie.
sous licence cidre :
si tu l'utilises, tu me dois un cidre.
*/
//g++ -Wall -std=c++11 2_lineage.cpp




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
using namespace std; // sert surement à terme à rien 


int random_nb(int N){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1,N);
	return dis(gen);
}

int simulate(int N){
	int lineage_1;
	int lineage_2;
	
	lineage_1=random_nb(N);
	lineage_2=random_nb(N);

	int compt=0;
	while(lineage_1!=lineage_2){
		//lineage_1=random_nb(N);
		lineage_2=random_nb(N);
		compt++;
	}
	return compt+1;
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

void aff_map(map<int,int>& m){ // trouvé sur internet
	map<int,int>::iterator p;
	cout << "interieur de la map" << endl;
	for(p=m.begin();p!=m.end();p++){
		cout << " id : " <<p->first<< " pere : " << p->second <<endl;
	}
}

void trouve_2suiv(vector<int>& vec, map<int,int> &res,unsigned int& k){
	int first;
	int second;
	cout << k << endl;
	first=random_nb(vec.size())-1;// -1 pour indexer à 0
	res[vec[first]]=k;
	vec.erase(vec.begin()+first);
	second=random_nb(vec.size())-1;
	res[vec[second]]=k;
	vec.erase(vec.begin()+second);
	vec.push_back(k);
	k++;
}

int main(){
	unsigned int k=5;
	unsigned int N=k;
	vector <int> vec; // vecteur des possibles
	//cout << "douze" << endl;
	init_vec(vec,k);
	//cout << vec.size() << endl;
	//cout << "douze" << endl;
	map<int,int> res; // tableau de map
	vector<int> vec_gen;
 	//trouve_2suiv(vec,res,k)
	while(vec.size()>=2){
		trouve_2suiv(vec,res,k);
		vec_gen.push_back(simulate(N));
		N--;	
	}
	cout << "affichage du vecteur de temps " << endl;
 	aff_vec(vec_gen);
	aff_map(res);
}
