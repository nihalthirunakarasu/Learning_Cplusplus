// Learning C++ 
// Challenge Solution 01_05
// Console Interaction, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Hi " << name << ".\nHappy coding!!\n";
	return 0;
}