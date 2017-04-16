// BinaryRepresentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<cassert>
void binaryRep(unsigned int n, std::string & rep)
{
	if (n > 1)
		binaryRep(n / 2, rep);

	rep.append(std::to_string(n % 2));
}
int main()
{
	std::string rep; 
	unsigned int i, pos;
	std::cout << "Enter the number" << std::endl;
	std::cin >> i;
	binaryRep(i, rep);
	std::cout << "Binary Representation of number " << i << " is " << rep << std::endl;

	std::cout << "The Binary Representation of number" << i << " has " << rep.length() <<" bits." << std::endl;
	std::cout << "Enter position of the bit ( <" << rep.length() << " ) to check as on or off " << std::endl;
	std::cin >> pos;
	std::string temp(rep.rbegin(), rep.rend());
	std::cout << "Bit at position " << pos << " is " << temp.at(pos) <<std::endl;
	return 0;
}

