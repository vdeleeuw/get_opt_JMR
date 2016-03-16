#include "FlagArgument.h"

#include <boost/lexical_cast.hpp>
#include <string.h>

/**
 * @file FlagArgument.cpp
 * @brief Code C++ de la classe FlagArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 27 avril 2015
 */

FlagArgument::FlagArgument(std::string lName, char sName, bool* value, std::string descr)
	:Argument(lName, sName, descr), m_value(value){
}

bool FlagArgument::testValue(std::string val){
	//test si true or false	
	const char* chVal = val.c_str();
	if(strcmp(chVal, "true") == 0){
		setValue(true);
		return true;
	}else 
		setValue(false);	
		return true;	
	
	//test cast avec boost
	try{
		setValue(boost::lexical_cast<bool>(val));
	}catch(boost::bad_lexical_cast const&){
		return false;
	}
	return true;	
}

void FlagArgument::display(){
	if((strcmp(getLongName().c_str(), "") != 0) && (getShortName() != ' '))
		std::cout << "Flag (--" << getLongName() << " or -" << getShortName() << ") = " << *m_value << std::endl;
	else if(strcmp(getLongName().c_str(), "") == 0)
		std::cout << "Flag (-" << getShortName() << ") = " << *m_value << std::endl;
	else if(getShortName() == ' ')
		std::cout << "Flag (--" << getLongName() << ") = " << *m_value << std::endl;
};
