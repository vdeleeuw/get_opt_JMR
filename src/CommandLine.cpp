#include "CommandLine.h"

#include <sstream>
#include <iostream>
#include <string>
#include <string.h>
#include <stdexcept>
#include <typeinfo>

#define underline "\33[4m"
#define end_underline "\033[0m"
#define bold "\033[1m"
#define end_bold "\033[0m"

/**
 * @file CommandLine.cpp
 * @brief Code C++ de la classe CommandLine
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

CommandLine::CommandLine()	
	:m_argc(0), m_argv(NULL){
}

CommandLine::CommandLine(unsigned int argc, char** argv)	
	:m_argc(argc), m_argv(argv){
}

Argument* CommandLine::find(char* name){	
	//argument long
	if((name[0] == '-') && (name[1] == '-')){
		std::string nameStr(name);
		std::size_t found = nameStr.find("=");
		nameStr=nameStr.substr(2,found-2);

		for(unsigned int i=0; i<m_vecArg.size(); ++i)
			if(strcmp(nameStr.c_str(), m_vecArg[i]->getLongName().c_str()) == 0){
				m_vecArg[i]->setWasFound(true);
				return m_vecArg[i];
			}
	}

	//argument court
	if(name[0] == '-'){
		for(unsigned int i=0; i<m_vecArg.size(); ++i)
			if(name[1] == m_vecArg[i]->getShortName()){
				m_vecArg[i]->setWasFound(true);
				return m_vecArg[i];
			}
	}
	return NULL;
}

void CommandLine::add(Argument *a){
	m_vecArg.push_back(a);
}

bool CommandLine::parse(){
	bool tmpRes,res=true;
	for(unsigned int i=1; i<m_argc; ++i){
		Argument *tmpArg = find(m_argv[i]);
		if(tmpArg != NULL){
			//argument long
			if((m_argv[i][0] == '-') && (m_argv[i][1] == '-')){
				std::string tmpTestFlag(m_argv[i]);
				if(typeid(*tmpArg) == typeid(FlagArgument) && (tmpTestFlag.find("=")!=std::string::npos)) {
					std::string err = "Invalid use of flag argument '" + std::string(m_argv[i]) + "'.";
					throw std::logic_error(err);
				}else if(typeid(*tmpArg) == typeid(FlagArgument)) 
					tmpRes=tmpArg->testValue("true");
				else{
					std::string tmpArgvI(m_argv[i]);
					tmpRes=tmpArg->testValue(tmpArgvI.substr(3+tmpArg->getLongName().length()));
				}
			//argument court
			}else{
				if((typeid(*tmpArg) == typeid(FlagArgument))){
					tmpRes=tmpArg->testValue("true");	
				} else
					tmpRes=tmpArg->testValue(m_argv[++i]);
			}
			//erreur valeur argument
			if(!tmpRes){
				res = tmpRes;
				std::string err = "Invalid value for argument " + tmpArg->getName("") + ".";
				throw std::logic_error(err);
			}
		}else{
			std::string err = "Invalid argument '" + std::string(m_argv[i]) + "'.";
			throw std::logic_error(err);
		}
	}
	if(!res)
		throw std::logic_error("Parsing failed.");
	return res;
}

void CommandLine::display(){
	for(unsigned int i=0; i<m_vecArg.size(); ++i)
		if(m_vecArg[i]->getWasFound())
			m_vecArg[i]->display();	
}

void CommandLine::displayAll(){
	for(unsigned int i=0; i<m_vecArg.size(); ++i)
			m_vecArg[i]->display();	
}

CommandLine::~CommandLine(){
	for(unsigned int i=0; i<m_vecArg.size(); ++i)
		delete m_vecArg[i];
}

std::string CommandLine::getChoixArg(Argument* arg){
	if(typeid(*arg)==typeid(BoolArgument))
 			return "BOOL";
	else if(typeid(*arg)==typeid(FlagArgument))
 			return "";
	else if(typeid(*arg)==typeid(IntArgument))
			return "INTEGER";
	else if(typeid(*arg)==typeid(UnsignedIntArgument))
			return "UNSIGNED INT";
	else if(typeid(*arg)==typeid(FloatArgument))
			return "FLOAT";
	else if(typeid(*arg)==typeid(VecArgument)){
		VecArgument* tmpVec=dynamic_cast<VecArgument*>(arg);
		std::string tmpListe;
		unsigned int tmpVecSize = tmpVec->getVect().size();
		for(unsigned int j=0; j<tmpVecSize; j++) {
			tmpListe += underline + tmpVec->getVect()[j] + end_underline;
			if(j!=tmpVecSize-1) 
				tmpListe += "|";
		}
		return tmpListe;
	}
	else return "";
}

void CommandLine::ReturnAtLine(std::string s, unsigned int nb_tabulation){
	std::istringstream stream(s);
        std::string word;
        int col = 0;
	for(unsigned int i=0; i<nb_tabulation; ++i)
		std::cout << "\t";
        while (stream >> word) {
                if (col + word.length() >= 60) {
                        std::cout << std::endl; 
			for(unsigned int i=0; i<nb_tabulation; ++i)
				std::cout << "\t";
                        col = 0;
                }
                std::cout << word << " ";
                col += (word.length() + 1);
        }
        std::cout << std::endl;	
}


void CommandLine::print_synopsis(std::string command, std::string description){
	//description globale
	std::string Str_name = command+" - "+description;
	std::cout << bold << "\nNAME" << end_bold << std::endl;
	ReturnAtLine(Str_name, 1);
	std::cout << bold << "\nSYNOPSIS" << std::endl;
	std::cout << "\t" << "./bin/" << command << end_bold << " [" << underline << "OPTION"<< end_underline <<"] ..." << std::endl;
	std::cout << bold << "\nDESCRIPTION" << end_bold << std::endl;
	std::cout << "\t" << "Liste des arguments possibles lors de l'exécution :\n" << std::endl;

	//description des arguments
	for(unsigned int i=0; i<m_vecArg.size(); ++i){
		std::string descr = m_vecArg[i]->getDescription();
		std::cout << "\t" << m_vecArg[i]->getName(getChoixArg(m_vecArg[i])) << std::endl;
		ReturnAtLine(descr, 2);
		std::cout << std::endl;
	}

	//fin
	std::cout << "Fin du manuel. \n" << std::endl;
}
