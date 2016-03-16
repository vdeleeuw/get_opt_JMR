#ifndef VECARGUMENT_H
#define VECARGUMENT_H

#include "Argument.h"

#include <vector>

/**
 * @file VecArgument.h
 * @brief Header de la classe VecArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 21 avril 2015
 */

/**
 * @class VecArgument
 * 
 * La classe VecArgument hérite de la classe Argument. Les objets de cette classe stockent les informations d'un arguments de type vecteur, elle possède une 
 * variable qui contient sa valeur (m_value) et une autre qui contient le vecteur de choix (m_vecStr).
 * Elle dispose d'un constructeur et des méthodes qui permettent de définir et de tester la valeur d'une instance (testValue()),
 * d'afficher les informations liées à une instance (display()), d'un accesseur (getValue()) et d'un mutateur (setValue(std::string)).
 */
class VecArgument
	:public Argument{

	private:
		std::vector<std::string> m_vecStr;  /**< Vecteur des valeurs possibles */
		std::string *m_value;  		    /**< Valeur de l'argument */

	public:
		/**
		 * @brief Constructeur
		 * @param lName : Nom long de l'argument
		 * @param sName : Nom court de l'argument
		 * @param value : Pointeur sur la chaîne de caractères à modifier
		 * @param vec : Vecteur de chaîne de caractères des choix possibles
		 * @param descr : Description de l'argument
		 *
		 * Constructeur de la classe VecArgument.
		 */
		VecArgument(std::string lName, char sName, std::string* value, std::vector<std::string> vec, std::string descr);

		/**
		 * @brief Accesseur
		 * @fn bool getValue()
		 * @return Valeur de l'argument
		 *
		 * Accesseur de m_value.
		 */
		std::string getValue(){
			return *m_value;
		};

		/**
		 * @brief Mutateur
		 * @fn void setValue(string)
		 * @param val : Chaîne de caractère qui donnera sa valeur à la variable m_value.
		 *
		 * Mutateur de m_value.
		 */
		void setValue(std::string val){
			*m_value = val;	
		};

		/**
		 * @brief Mutateur et testeurstring> VecArgument::get
		 * @fn bool testValue(string)
		 * @param val : valeur d'un argument
		 * @return Vrai si la valeur est du bon type, faux sinon.
		 *
		 * C'est une méthode qui prend en paramètre la valeur d'un argument via la ligne de commande et qui test si elle est bien incluse dans le vecteur de l'instance.
		 * Si c'est le cas, la méthode met la valeur dans l'instance et retourne vrai, sinon faux.
		 */
		bool testValue(std::string val);

		/**
		 * @fn void display()
		 * @brief Afficheur
		 * 
		 * C'est une méthode d'affichage d'un argument, l'affichage est sous la forme : Tab <nom> = <valeur> 
		 */
		void display();	

		/**
		 * @fn ~VecArgument()
		 * @brief Destructeur
		 * 
		 * Destructeur de la classe VecArgument
		 */
		~VecArgument(){};
	
		/**
		 * @brief Accesseur
		 * @fn vector<string> getVect()
		 * @return Le vecteur de valeur en chaîne de caractère
		 *
		 *  Accesseur de m_vecStr
		 */
		std::vector<std::string> getVect();		
};

#endif	
