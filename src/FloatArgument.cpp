#include "FloatArgument.h"

#include <boost/lexical_cast.hpp>
#include <string.h>

/**
 * @file FloatArgument.cpp
 * @brief Code C++ de la classe FloatArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

FloatArgument::FloatArgument(std::string lName, char sName, float* value, std::string descr)
	:Argument(lName, sName, descr), m_value(value){
}

bool FloatArgument::testValue(std::string val){
	try{
		setValue(boost::lexical_cast<float>(val));
	}catch(boost::bad_lexical_cast const&){
		return false;
	}
	return true;	
}

void FloatArgument::display(){
	if((strcmp(getLongName().c_str(), "") != 0) && (getShortName() != ' '))
		std::cout << "Float (--" << getLongName() << " or -" << getShortName() << ") = " << *m_value << std::endl;
	else if(strcmp(getLongName().c_str(), "") == 0)
		std::cout << "Float (-" << getShortName() << ") = " << *m_value << std::endl;
	else if(getShortName() == ' ')
		std::cout << "Float (--" << getLongName() << ") = " << *m_value << std::endl;
};
