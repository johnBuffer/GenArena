#include "utils.h"


int bin2dec(std::vector<bool> bin)
{
	int decValue = 0;
	for(int i(bin.size()-1); i>=0; --i)
	{
		if(bin[i]){
			decValue+=pow(2.0,(double)i);
		}
	}
	return decValue;
}

std::vector<bool> dec2bin(int dec)
{
	std::vector<bool> res;
	while(dec)
	{
		res.push_back(dec%2);
		dec/=2;
	}
	std::reverse(res.begin(),res.end());
	return res;
}
