#ifndef INTARGUMENT_H
#define INTARGUMENT_H

#include "Argument.h"

/**
 * @file IntArgument.h
 * @brief Header de la classe IntArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

/**
 * @class IntArgument
 * 
 * La classe IntArgument hérite de la classe Argument. Les objets de cette classe stockent les informations d'un arguments de type entier, elle posséde une 
 * variable qui contient sa valeur (m_value). Elle dispose d'un constructeur et des méthodes qui permettent de définir et de tester la valeur d'une instance (testValue()),
 * d'afficher les informations liées à une instance (display()), d'un accesseur (getValue()) et d'un mutateur (setValue(int)).
 */
class IntArgument
	:public Argument{

	private:
		int* m_value; /**< Valeur de l'argument */

	public:
		/**
		 * @brief Constructeur
		 * @param lName : Nom long de l'argument
		 * @param sName : Nom court de l'argument
		 * @param value : Pointeur sur l'entier à modifier
		 * @param descr : Description de l'argument
		 * 
		 * Constructeur de la classe IntArgument.
		 */
		IntArgument(std::string lName, char sName, int* value, std::string descr);

		/**
		 * @brief Accesseur
		 * @fn int getValue()
		 * @return Valeur de l'Argument
		 *
		 * Accesseur de m_value.
		 */
		int getValue(){
			return *m_value;
		};

		/**
		 * @brief Mutateur
		 * @fn void setValue(int)
		 * @param val : Entier qui donnera sa valeur à la variable m_value.
		 *
		 * Mutateur de m_value.
		 */
		void setValue(int val){
			*m_value = val;
		};

		/**
		 * @fn bool testValue(string)
		 * @param val : valeur de  l'argument
		 * @return Vrai si la valeur est du bon type, faux sinon.
		 * @brief Mutateur et testeur
		 *
		 * C'est une méthode qui prend en paramètre la valeur d'un argument via la ligne de commande et qui test si elle correspond bien à un entier.
		 * Si c'est le cas, la méthode met la valeur dans l'instance et retourne vrai, sinon faux.
		 */
		bool testValue(std::string val);

		/**
		 * @fn void display()
		 * @brief Afficheur
		 * 
		 * C'est une méthode d'affichage d'un argument, l'affichage est sous la forme : Int <nom> = <valeur> 
		 */
		void display();	

		/**
		 * @fn ~IntArgument()
		 * @brief Destructeur
		 * 
		 * Destructeur de la classe IntArgument
		 */
		~IntArgument(){};
};

#endif	
