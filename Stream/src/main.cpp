#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream myfile;
	
	myfile.open("out/example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();
	
	return 0;
}