#ifndef FLOATARGUMENT_H
#define FLOATARGUMENT_H

#include "Argument.h"

/**
 * @file FloatArgument.h
 * @brief Header de la classe FloatArgument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

/**
 * @class FloatArgument
 * 
 * La classe FloatArgument hérite de la classe Argument. Les objets de cette classe stockent les informations d'un argument de type float, elle posséde une 
 * variable qui contient sa valeur (m_value). Elle dispose d'un constructeur et des méthodes qui permettent de tester et de définir la valeur d'une instance (testValue()),
 * d'afficher les informations liées à une instance (display()), d'un accesseur (getValue()) et d'un mutateur (setValue(float)).
 */
class FloatArgument
	:public Argument{

	private:
		float* m_value; /**< Valeur de l'argument */

	public:
		/**
		 * @brief Constructeur
		 * @param lName : Nom long de l'argument
		 * @param sName : Nom court de l'argument
		 * @param value : Pointeur sur le float à modifier
		 * @param descr : Description de l'argument
		 * 
		 * Constructeur de la classe FloatArgument.
		 */
		FloatArgument(std::string lName, char sName, float* value, std::string descr);

		/**
		 * @brief Accesseur
		 * @fn bool getValue()
		 * @return Valeur de l'argument
		 *
		 * Accesseur de m_value.
		 */
		float getValue(){
			return *m_value;
		};

		/**
		 * @brief Mutateur
		 * @fn void setValue(float)
		 * @param val : Float qui donnera sa valeur à la variable m_value.
		 *
		 * Mutateur de m_value.
		 */
		void setValue(float val){
			*m_value = val;
		};

		/**
		 * @fn bool testValue(string)
		 * @param val : valeur d'un argument
		 * @return Vrai si la valeur est du bon type, faux sinon.
		 * @brief Mutateur et testeur
		 *
		 * C'est une méthode qui prend en paramètre la valeur d'un argument via la ligne de commande et qui test si elle correspond bien à un float.
		 * Si c'est le cas, la méthode met la valeur dans l'instance et retourne vrai, sinon faux.
		 */
		bool testValue(std::string val);

		/**
		 * @fn void display()
		 * @brief Afficheur
		 * 
		 * C'est une méthode d'affichage d'un argument, l'affichage est sous la forme : Float <nom> = <valeur> 
		 */
		void display();	

		/**
		 * @fn ~FloatArgument()
		 * @brief Destructeur
		 * 
		 * Destructeur de la classe FloatArgument
		 */
		~FloatArgument(){};
};

#endif	
