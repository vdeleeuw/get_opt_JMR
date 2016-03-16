#include "IntArgument.h"

#include <boost/lexical_cast.hpp>
#include <string.h>

/**
 * @file IntArgument.cpp
 * @brief Code C++ de la classe IntArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

IntArgument::IntArgument(std::string lName, char sName, int* value, std::string descr)
	:Argument(lName, sName, descr), m_value(value){
}

bool IntArgument::testValue(std::string val){
	try{
		setValue(boost::lexical_cast<int>(val));
	}catch(boost::bad_lexical_cast const&){
		return false;
	}
	return true;	
}

void IntArgument::display(){
	if((strcmp(getLongName().c_str(), "") != 0) && (getShortName() != ' '))
		std::cout << "Int (--" << getLongName() << " or -" << getShortName() << ") = " << *m_value << std::endl;
	else if(strcmp(getLongName().c_str(), "") == 0)
		std::cout << "Int (-" << getShortName() << ") = " << *m_value << std::endl;
	else if(getShortName() == ' ')
		std::cout << "Int (--" << getLongName() << ") = " << *m_value << std::endl;
};
