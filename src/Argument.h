#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <iostream>

/**
 * @file Argument.h
 * @brief Header de la classe Argument
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

/**
 * @class Argument
 * 
 * Les objets de la classe Argument stocke les informations d'un arguments d'une ligne de commande dans plusieurs variables qui sont le nom long de l'argument
 * (m_longName), le nom court de l'argument (m_shortName), la description de l'argument (m_description) et une variable booléenne (m_wasFound) qui indique la
 * présence de l'argument dans la ligne de commande. Elle dispose d'un constructeur et de méthodes virtuelles pures qui seront redéfinies dans les sous-classes qui 
 * permettent de donner la valeur d'un argument (setValue()), et d'afficher les informations liées à un argument (display()).
 */
class Argument{

	private:
		std::string m_longName;			/**< Nom long de l'argument */
		char m_shortName;				/**< Nom court de l'argument */
		std::string m_description;		/**< Description de la fonction de l'argument */
		bool m_wasFound;				/**< Presence ou non de l'argument dans la ligne de commande */

	public:
		/**
		 * @brief Constructeur
		 * @param lName : Nom long de l'argument.
		 * @param sName : Nom court de l'argument.
		 * @param descr : Description de l'argument.
		 * 
		 * Constructeur de la classe Argument.
		 */
		Argument(std::string lName, char sName, std::string descr);

		/**
		 * @brief Accesseur
		 * @fn string getShortName()
		 * @return Le nom court de l'argument
		 *
		 * Accesseur de m_shortName.
		 */
		char getShortName(){
			return m_shortName;	
		};

		/**
		 * @brief Accesseur
		 * @fn string getLongName()
		 * @return Le nom long de l'argument
		 *
		 * Accesseur de m_longName.
		 */
		std::string getLongName(){
			return m_longName;	
		};

		/**
		 * @brief Accesseur
		 * @fn string getDescription()
		 * @return La description de l'argument
		 *
		 * Accesseur de m_description.
		 */
		std::string getDescription(){
			return m_description;	
		};

		/**
		 * @brief Accesseur
		 * @fn string getWasFound()
		 * @return Vrai si l'argument est présent dans la ligne de commande, faux sinon
		 *
		 *  Accesseur de m_wasFound.
		 */
		bool getWasFound(){
			return m_wasFound;
		};

		/**
		 * @brief Mutateur
		 * @fn void setWasFound(bool)
		 * @param val : Booléen indiquant la présence de l'argument ou non dans la ligne de commande
		 *
		 * Mutateur de m_wasFound.
		 */ 
		void setWasFound(bool val){
			m_wasFound=val;
		};

		/**
	 	 * @fn std::string getName(std::string type)
		 * @brief Afficheur
		 * @param type : le type à afficher, "" pour aucun type
		 * @return le nom de l'argument sous la forme : "-nomCourt [type], --nomLong=[type]"
		 *
		 * C'est une fonction qui retourne les noms de l'argument sous la forme : "nomCourt, nomLong" si type n'est pas précisé.
		 * Si un type est précisé cela affiche "-nomCourt type, --nomLong=type".
		 */
		std::string getName(std::string type);

		/**
		 * @brief Mutateur et testeur pour m_value 
		 * @fn void testValue(string) = 0
		 * @param string val : valeur à tester
		 * @return Vrai si la valeur est du bon type, faux sinon
		 *
		 * testValue est une méthode virtuelle pure redéfinie dans les sous-classes de la classe Argument.
		 * C'est une méthode qui prend en paramètre la valeur d'un argument dans la ligne de commande et qui qui place la valeur dans la variable m_value et 		
		 * retourne vrai si la valeur est du bon type, faux sinon.
		 */
		virtual bool testValue(std::string val) = 0;

		/**
		 * @fn void display() = 0
		 * @brief Afficheur
		 * 
		 * display est une méthode virtuelle pure redéfinie dans les sous-classes de la classe Argument.
		 * C'est une méthode d'affichage d'un argument, l'affichage est sous la forme : <type> <nom> = <valeur> 
		 */
		virtual void display() = 0;

		/**
		 * @fn ~Argument()
		 * @brief Destructeur
		 * 
		 * Destructeur de la classe Argument
		 */
		virtual ~Argument(){};
};

#endif
