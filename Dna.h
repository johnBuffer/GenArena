#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>


class Dna
{
public:
	Dna();
    Dna(std::string& fileName);

	//genetics
	void crossOver(Dna &a, Dna &b);
	void mutate();

	//attributes
    void showListOfIds();
    void showDna();
    void showBinaryPacket(std::vector<bool> packet);
    std::vector<bool> getPacketByID(std::string id);

    //accessors
    std::vector<bool> getDnaVector(){return m_dna;};
    std::vector<std::string> getIds(){return m_id;};
    std::vector<int> getpacketSizes(){return m_packetSizes;};
    int getDnaSize(){return m_dnaSize;};


private:

	int m_dnaSize;
	double m_crossOverChance, m_mutationChance;
	std::vector<bool> m_dna;
	std::vector<int> m_packetSizes;
	std::vector<std::string> m_id;
	void generateDna(std::ifstream& fileName);
};

#endif // DNA_H_INCLUDED


