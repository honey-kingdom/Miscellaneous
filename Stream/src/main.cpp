#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream myfile("out/example.txt", std::ios::out | std::ios::app);
	// Given option overrides the default value of fstream but is combined with the default value of ofstream/ifstream.
	
	if (myfile.is_open())
	{
		myfile << "This is a line.\n";
		myfile << "This is another line.\n";
		myfile.close();		
	}
	else std::cout << "Unable to open file";

	std::cin.get();	
	return 0;
}