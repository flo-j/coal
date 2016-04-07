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
using namespace std;


int random_nb(int N){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1,N);
	return dis(gen);
}

void write_file(vector<unsigned int> res, int N, string fileName){
	ofstream file("res_N1000.txt", ios::out | ios::trunc);
	if(file){
    	std::copy(res.begin(), res.end(),std::ostream_iterator<int> (file,"\n"));
	}else{
		cerr << " =( " << endl;
	}
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
	//cout << compt << endl;
}


int main(){
	std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2;
    start = std::chrono::system_clock::now();
	vector<int> res;
	int nb_simul=100000;
	string fileName;
	unsigned int N=1000;
	vector<unsigned int> tcoal(nb_simul);
	for(auto&t:tcoal){
		t=simulate(N);
	}
	end = std::chrono::system_clock::now();
	start2 = std::chrono::system_clock::now();
	write_file(tcoal,N,fileName);
	
	// elapsed time 
	end2 = std::chrono::system_clock::now();
	int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                             (end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    int elapsed_seconds2 = std::chrono::duration_cast<std::chrono::seconds>
                             (end2-start2).count();
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds << "s\n";
	std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds2 << "s\n";
}