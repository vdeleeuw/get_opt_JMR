#include "VecArgument.h"

#include <string.h>

/**
 * @file VecArgument.cpp
 * @brief Code C++ de la classe VecArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 21 avril 2015
 */


VecArgument::VecArgument(std::string lName, char sName, std::string* value, std::vector<std::string> vec, std::string descr)
	:Argument(lName, sName, descr), m_vecStr(vec), m_value(value){
}

bool VecArgument::testValue(std::string val){
	for(unsigned int i=0; i<m_vecStr.size(); ++i){
		if(strcmp(m_vecStr[i].c_str(), val.c_str()) == 0){
			setValue(m_vecStr[i]);
			return true;
		}
	} 
	return false;
}

void VecArgument::display(){
	if((strcmp(getLongName().c_str(), "") != 0) && (getShortName() != ' '))
		std::cout << "Vec (--" << getLongName() << " or -" << getShortName() << ") = " << *m_value << std::endl;
	else if(strcmp(getLongName().c_str(), "") == 0)
		std::cout << "Vec (-" << getShortName() << ") = " << *m_value << std::endl;
	else if(getShortName() == ' ')
		std::cout << "Vec (--" << getLongName() << ") = " << *m_value << std::endl;
}

std::vector<std::string> VecArgument::getVect() {
	return m_vecStr;
}

