// Learning C++ 
// Challenge Solution 02_11
// Calculate an Average, by Eduardo Corpeño 

#include <iostream>

int main(){
	int nums[5] = {1,23,32,24,337};
	float average;

	average = (float)(nums[0]+nums[1]+nums[2]+nums[3]+nums[4])/5;

	std::cout << "The average of " << nums[0] << ", " << nums[1] << ", " <<  nums[2] << ", " << nums[3] << " and " << nums[4] << " is " << average << std::endl;

	return 0; 
}