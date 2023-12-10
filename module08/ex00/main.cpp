#include <iostream>
#include "easyfind.h"
#include <vector>
#include <list>

int main() {
	std::vector<int> v(5);
	for (int i = 0; i < 5; i++)
		v[i] = i;
	std::vector<int>::iterator it = easyfind(v, 3);
	if (it != v.end())
		std::cout << "Found " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;
	std::vector<int>::iterator it2 = easyfind(v, 100);
	if (it2 != v.end())
		std::cout << "Found " << *it2 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	std::list<int> l(5);
	for (int i = 0; i < 5; i++)
		l.push_back(i);
	std::list<int>::iterator it3 = easyfind(l, 3);
	if (it3 != l.end())
		std::cout << "Found " << *it3 << std::endl;
	else
		std::cout << "Not found" << std::endl;
	std::list<int>::iterator it4 = easyfind(l, 100);
	if (it4 != l.end())
		std::cout << "Found " << *it2 << std::endl;
	else
		std::cout << "Not found" << std::endl;
}
