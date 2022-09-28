// Learning C++ 
// Exercise 01_03
// Hello World, by Eduardo Corpeño 

#include <iostream>
// Change this to 0 to use the std::<command> set it to 1 to use <command> without specifying the std:: at every instance
#define USING_NAMESPACE 0

#if USING_NAMESPACE
using namespace std;
#else
#endif

int main()
{
    #if USING_NAMESPACE
	cout << "Hi There!" << endl;
    #else
    std::cout << "Hi There!" << std::endl;
    #endif
	return(0);
}
