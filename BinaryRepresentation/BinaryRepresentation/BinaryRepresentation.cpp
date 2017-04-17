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

bool compareRep(const std::string rep1, const std::string rep2,int len)
{
	int count =1;
	if (rep1.length() == rep2.length())
		count = 0;
	for (int i=0;i<len;i++)
	{
		if (rep1.at(i) != rep2.at(i))
			count++;
	}
	if (count == 1)
		return true;
	else
		return false;

}
bool checkIfDiffer(const std::string rep1, const std::string rep2)
{
	int len1 = rep1.length();
	int len2 = rep2.length();

	if (std::abs(len1 - len2) > 1)
		return false;
	else
	{
		if (len1 < len2 || len1 == len2)
			return (compareRep(rep1, rep2, len1));
		else
		{
			if (len2 < len1)
				return(compareRep(rep1, rep2, len2));
		}
	}

}
int main()
{
	std::string rep1, rep2;
	unsigned int i, pos;
	std::cout << "Enter the first number" << std::endl;
	std::cin >> i;
	binaryRep(i, rep1);
	std::cout << "Binary Representation of first number " << i << " is " << rep1 << std::endl;
	std::cout << "Enter the second number" << std::endl;
	std::cin >> i;
	binaryRep(i, rep2);
	std::cout << "Binary Representation of second number " << i << " is " << rep2 << std::endl;
	bool issingleBit= checkIfDiffer(rep1,rep2);
	if(issingleBit)
		std::cout << "Binary Representation of the two numbers differ by one bit "<< std::endl;
	else 
		std::cout << "Binary Representation of the two numbers does not differ by one bit " << std::endl;
	return 0;
}

