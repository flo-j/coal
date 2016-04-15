
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <typeinfo>

using std::string;
using std::vector;

template<typename T>
class Holder{

private:

public:
	std::list<T> stocked_elements; 

	T& create(){
		T new_elem;
		std::cout << "created " << new_elem << "\n";
		stocked_elements.push_back(new_elem);
		return stocked_elements.back();
	}
};

int main(){

	Holder<int> hold;
	auto& r = hold.create();
	std::cout << "retrieved " << r << std::endl;
	++r;

	std::cout << r << std::endl;
	std::cout << hold.stocked_elements.back() << "\n" ;
	std::cout << typeid(r).name() << '\n';
	int a = int(5);
	std::cout << a << std::endl;
/*
	using coord_type = unsigned int;
	using Genetics = vector<coord_type>;

	Genetics sample {0,1,2,3,4,5};
	//Demography demo;

	Holder<Node<int>> holder1;
	Coalescor<Node<int>> simulator1(sample, demo, holder1);
	vector<Node<int>> coal1 = simulator.simul();

	Holder<Node<string>> holder2;
	Coalescor<Node<string>> simulator2(sample, demo, holder2);
	vector<Node<string>> coal2 = simulator.simul();
*/
	return 0;
}