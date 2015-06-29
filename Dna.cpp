#include "Dna.h"

//Constructor from fileName, use structure.dna
Dna::Dna(std::string& fileName)
{
	m_dnaSize = 0;
	std::ifstream file(fileName.c_str());
	if(file)
	{
		generateDna(file);
		file.close();
	}else
		std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

//Randomly generate dna from structure.dna file, stores string attributes and their corresponding packet size
void Dna::generateDna(std::ifstream& file)
{
	m_packetSizes.push_back(0);
	int nbBits;
	std::string id;
	while(!file.eof()){
		file >> id >> nbBits; //See structure.dna formatting
		m_dnaSize+=nbBits;
		m_id.push_back(id);
		m_packetSizes.push_back(nbBits);
	}
	m_dna.resize(m_dnaSize);
	for (int i(0); i<m_dnaSize; ++i) m_dna[i] = rand()%2;
}

// Returns binary value associated in structure.dna with the attribute string
std::vector<bool> Dna::getPacketByID(std::string id){
	std::vector<bool> packet;
	for(unsigned int i(0);i<m_id.size();++i)
	{
		if(!m_id[i].compare(id))
		{
			packet.resize(m_packetSizes[i+1]);
			for(unsigned int j(0);j<packet.size();++j)
			{
				packet[j]=m_dna[m_packetSizes[i]+j]; //Fill packet with right bits
			}
		}
	}
	return packet;
}

// Prints a list of attributes stored in program (.dna read in constructor)
void Dna::showListOfIds()
{
	for (unsigned int i(0); i<m_id.size(); ++i) std::cout<<m_id[i]<<std::endl;
}

//Prints whole dna
void Dna::showDna()
{
	for (int i(0); i<m_dnaSize; ++i) std::cout<<m_dna[i];
	std::cout<<""<<std::endl;
}

//Prints any vector<bool>
void Dna::showBinaryPacket(std::vector<bool> packet)
{
	for (unsigned int i(0); i<packet.size(); ++i) std::cout<<packet[i];
	std::cout<<""<<std::endl;
}

//One point crossover with two parents a & b
void Dna::crossOver(Dna &a, Dna &b)
{
	m_dna.clear();
	m_crossOverChance = 0.8;
    if (rand()/(double)RAND_MAX < m_crossOverChance)
    {
        int crossOverPoint = rand()%m_dnaSize;
        for (int i(0); i<crossOverPoint; ++i) m_dna.push_back(a.m_dna[i]);
        for (int i(crossOverPoint); i<m_dnaSize; ++i) m_dna.push_back(b.m_dna[i]);
    }
    else if (rand()%2)
        m_dna = a.m_dna;
    else
        m_dna = b.m_dna;
}

//Random mutation of dna array
void Dna::mutate()
{
	m_mutationChance = 0.1;
    for (int i(0); i<m_dnaSize; ++i) if (rand()/(double)RAND_MAX < m_mutationChance) m_dna[i] = !m_dna[i];
}
