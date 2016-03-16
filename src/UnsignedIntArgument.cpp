#include "UnsignedIntArgument.h"

#include <boost/lexical_cast.hpp>
#include <string.h>

/**
 * @file UnsignedIntArgument.cpp
 * @brief Code C++ de la classe UnsignedIntArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

UnsignedIntArgument::UnsignedIntArgument(std::string lName, char sName, unsigned int* value, std::string descr)
	:Argument(lName, sName, descr), m_value(value){
}

bool UnsignedIntArgument::testValue(std::string val){
	try{
		setValue(boost::lexical_cast<unsigned int>(val));
	}catch(boost::bad_lexical_cast const&){
		return false;
	}
	return true;	
}

void UnsignedIntArgument::display(){
	if((strcmp(getLongName().c_str(), "") != 0) && (getShortName() != ' '))
		std::cout << "Unsigned int (--" << getLongName() << " or -" << getShortName() << ") = " << *m_value << std::endl;
	else if(strcmp(getLongName().c_str(), "") == 0)
		std::cout << "Unsigned int (-" << getShortName() << ") = " << *m_value << std::endl;
	else if(getShortName() == ' ')
		std::cout << "Unsigned int (--" << getLongName() << ") = " << *m_value << std::endl;
};
