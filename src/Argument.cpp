#include "Argument.h"
#include <string.h>

#define underline "\33[4m"
#define end_underline "\033[0m"
#define bold "\033[1m"
#define end_bold "\033[0m"

/**
 * @file Argument.cpp
 * @brief Code C++ de la classe Argument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */
Argument::Argument(std::string lName, char sName, std::string descr)
	:m_longName(lName), m_shortName(sName), m_description(descr), m_wasFound(false){
}

std::string Argument::getName(std::string type){
	std::string tmpRes;
	if(strcmp(type.c_str(), "") == 0){	
		if((strcmp(getLongName().c_str(), "") != 0) && (getShortName() != ' ')){
			tmpRes = bold;			
				tmpRes += "-";
				tmpRes += getShortName();
			tmpRes += end_bold;
			tmpRes += ", ";
			tmpRes += bold;
				tmpRes += "--";
				tmpRes += getLongName(); 
			tmpRes += end_bold;
		}else if(strcmp(getLongName().c_str(), "") == 0){
			tmpRes = bold;	
				tmpRes += "-";
				tmpRes += getShortName(); 
			tmpRes += end_bold;
		}else if(getShortName() == ' '){
			tmpRes = bold;				
				tmpRes += "--" + getLongName(); 
			tmpRes += end_bold; 
		}
	}else{
		if((strcmp(getLongName().c_str(), "") != 0) && (getShortName() != ' ')){
			tmpRes = bold;			
				tmpRes += "-";
				tmpRes += getShortName();
			tmpRes += end_bold;
			tmpRes += " ";
			tmpRes += underline;
				tmpRes += type;
			tmpRes += end_underline;
			tmpRes += ", ";
			tmpRes += bold;
				tmpRes += "--";
				tmpRes += getLongName(); 
			tmpRes += end_bold;
		}else if(strcmp(getLongName().c_str(), "") == 0){
			tmpRes = bold;	
				tmpRes += "-";
				tmpRes += getShortName(); 
			tmpRes += end_bold;
			tmpRes += " ";
			tmpRes += underline;
				tmpRes += type;
			tmpRes += end_underline;
		}else if(getShortName() == ' '){
			tmpRes = bold;				
				tmpRes += "--" + getLongName(); 
			tmpRes += end_bold; 
			tmpRes += "=";
			tmpRes += underline;
				tmpRes += type;
			tmpRes += end_underline;
		}
	}
	return tmpRes;
}
