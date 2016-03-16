#include "BoolArgument.h"

#include <boost/lexical_cast.hpp>
#include <string.h>

/**
 * @file BoolArgument.cpp
 * @brief Code C++ de la classe BoolArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

BoolArgument::BoolArgument(std::string lName, char sName, bool* value, std::string descr)
	:Argument(lName, sName, descr), m_value(value){
}

bool BoolArgument::testValue(std::string val){
	//test si true or false	
	const char* chVal = val.c_str();
	if(strcmp(chVal, "false") == 0){
		setValue(false);
		return true;
	}else if(strcmp(chVal, "true") == 0){
		setValue(true);	
		return true;	
	}
	
	//test cast avec boost
	try{
		setValue(boost::lexical_cast<bool>(val));
	}catch(boost::bad_lexical_cast const&){
		return false;
	}
	return true;	
}

void BoolArgument::display(){
	if((strcmp(getLongName().c_str(), "") != 0) && (getShortName() != ' '))
		std::cout << "Bool (--" << getLongName() << " or -" << getShortName() << ") = " << *m_value << std::endl;
	else if(strcmp(getLongName().c_str(), "") == 0)
		std::cout << "Bool (-" << getShortName() << ") = " << *m_value << std::endl;
	else if(getShortName() == ' ')
		std::cout << "Bool (--" << getLongName() << ") = " << *m_value << std::endl;
};
