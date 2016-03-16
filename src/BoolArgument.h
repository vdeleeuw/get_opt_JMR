#ifndef BOOLARGUMENT_H
#define BOOLARGUMENT_H

#include "Argument.h"

/**
 * @file BoolArgument.h
 * @brief Header de la classe BoolArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */


/**
 * @class BoolArgument
 *
 * La classe BoolArgument hérite de la classe Argument. Les objets de cette classe stockent les informations d'un arguments de type booléen, elle posséde une 
 * variable qui contient sa valeur (m_value). Elle dispose d'un constructeur et des méthodes qui permettent de définir et de tester la valeur d'une instance (testValue()),
 * d'afficher les informations liées à une instance (display()), d'un accesseur (getValue()) et d'un mutateur (setValue(bool)).
 */
class BoolArgument
	:public Argument{

	private:
		bool* m_value; /**< Valeur de l'argument */

	public:
		/**
		 * @brief Constructeur
		 * @param lName : Nom long de l'argument
		 * @param sName : Nom court de l'argument
		 * @param value : Pointeur sur le booléen à modifier
		 * @param descr : Description de l'argument
		 *
		 * Constructeur de la classe BoolArgument.
		 */
		BoolArgument(std::string lName, char sName, bool* value, std::string descr);

		/**
		 * @brief Accesseur
		 * @fn bool getValue()
		 * @return Valeur de l'argument
		 *
		 * Accesseur de m_value.
		 */
		bool getValue(){
			return *m_value;
		};

		/**
		 * @brief Mutateur
		 * @fn void setValue(bool)
		 * @param val : Booléen qui donnera sa valeur à la variable m_value.
		 *
		 * Mutateur de m_value.
		 */
		void setValue(bool val){
			*m_value = val;
		};

		/**
		 * @brief Mutateur et testeur
		 * @fn bool testValue(string)
		 * @param val : valeur d'un argument
		 * @return Vrai si la valeur est du bon type, faux sinon.
		 *
		 * C'est une méthode qui prend en paramètre la valeur d'un argument via la ligne de commande et qui test si elle correspond bien à un booléen.
		 * Si c'est le cas, la méthode met la valeur dans l'instance et retourne vrai, sinon faux.
		 */
		bool testValue(std::string val);

		/**
		 * @fn void display()
		 * @brief Afficheur
		 * 
		 * C'est une méthode d'affichage d'un argument, l'affichage est sous la forme : Bool <nom> = <valeur> 
		 */
		void display();	

		/**
		 * @fn ~BoolArgument()
		 * @brief Destructeur
		 * 
		 * Destructeur de la classe BoolArgument
		 */
		~BoolArgument(){};
};

#endif	
