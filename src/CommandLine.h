#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "Argument.h"
#include "IntArgument.h"
#include "UnsignedIntArgument.h"
#include "FloatArgument.h"
#include "BoolArgument.h"
#include "VecArgument.h"
#include "FlagArgument.h"

#include <vector>

/**
 * @file CommandLine.h
 * @brief Header de la classe CommandLine
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 20 avril 2015
 */

/**
 * @class CommandLine
 * 
 * Les objets de la classe CommandLine stocke les informations d'une ligne de commande comme le nombre d'arguments dans la ligne (m_argc) et les arguments eux-même
 * dans un tableau (m_argv), ainsi qu'un vecteur d'argument (m_vecArg). La classe possède un constructeur, un destructeur et des méthodes de gestions d'arguments 
 * qui permettent : d'ajouter un argument dans le vecteur d'argument (add(Argument)), de trouver si un argument est court ou long et si il est présent dans le vecteur
 * (find(char*)), de tester si un argument est une option courte ou longue et si elle est suivie d'une valeur (parse()), et une méthode d'affichage des éléments du 
 * vecteurs (display()).
 */
class CommandLine{
	
	private:
		unsigned int m_argc;					/**< Nombre d'arguments */
		char** m_argv;							/**< Tableau d'arguments */
		std::vector<Argument*> m_vecArg;		/**< Vecteur d'arguments défini */

	public:
		/**
		 * @brief Constructeur 
		 *  
		 * Constructeur de la classe CommandLine
		 */
		CommandLine();
	
		/**
		 * @brief Constructeur 
		 * @param argc : nombre d'argument de la ligne de commande
		 * @param argv : tableau des arguments de la ligne de commande
		 * 
		 * Constructeur de la classe CommandLine
		 */
		CommandLine(unsigned int argc, char** argv);

		/* ! \\ POUR LES TESTS A NE PAS UTILISER SINON // ! */
		void setArgC(unsigned int val){	
			m_argc=val;
		};

		// ! \\ POUR LES TESTS A NE PAS UTILISER SINON // ! */
		void setArgV(char** val){
			m_argv=val;
		};

		/* ! \\ POUR LES TESTS A NE PAS UTILISER SINON // ! */
		std::vector<Argument*> getVecArg(){
			return m_vecArg;
		};

		/** 
		 * @fn void add(Argument *)
		 * @param *a : pointeur sur un argument.
		 * 
		 * C'est une méthode qui permet d'ajouter un argument au vecteur d'arguments (m_vecArg).
		 */
		void add(Argument *a);

		/** 
		 * @fn Argument* find(char*)
		 * @param name : nom d'un argument en chaine de caractère
		 * @return Pointeur sur argument si la méthode à trouvé cet argument, NULL sinon.
		 * 
		 * C'est une méthode qui prend le nom d'un argument en paramètre et qui recherche sa présence dans le vecteur d'arguments (m_vecArg) et qui retourne
		 * un pointeur sur cet argument si la méthode l'a trouvé, sinon elle retourne la valeur NULL.
		 */ 
		Argument* find(char* name);

		/**
		 * @fn bool parse()
		 * @return Vrai si l'argument est suivie d'une valeur du bon type, faux sinon.
		 * 
		 * C'est une méthode qui teste si un argument est une option courte ou longue et si la valeur suivant l'argument est d'un type correcte. Donc
		 * elle retourne vrai si tout c'est bien passé, ou faux si une erreur survient lors d'une opération.
		 */
		bool parse();

		/**
		 * @brief Afficheur
		 * @fn void display()
		 * 
		 * C'est une méthode d'affichage, elle parcours le vecteur d'arguments en entier pour afficher chaques éléments de celui-ci,
		 * s'ils sont présent dans la ligne de commande. 
		 */
		void display();

		/**
		 * @brief Afficheur
		 * @fn void displayAll()
		 * 
		 * C'est une méthode d'affichage, elle parcours le vecteur d'arguments en entier pour afficher chaques éléments de celui-ci. 
		 */
		void displayAll();

		/**
		 * @fn string getChoixArg(Argument*)
		 * @param arg : l'argument sur lequel on test
		 * @return Les choix correspondant à la référence d'un argument en chaîne de caractère.
		 * 
		 * C'est une méthode qui prend une référence à un argument en paramètre et qui test si le type de la classe correspond à un type existant
		 * tel que bool, int, float, unsigned int ou vector, et qui retourne les types possibles en chaîne de caractère.
		 */
		std::string getChoixArg(Argument* arg);


		/**
		 * @fn void ReturnAtLine(std::string)
		 * @param ch : La chaine de caractère contenant le nom du programme et sa description, nb_tab : le nombre de tabulation.
		 * 
		 * C'est une méthode qui prend une chaîne de caractère contenant le nom du programme et sa description en paramètre et qui permet
		 * de les mettre en page, c'est à dire qu'il insère les tabulations en début de ligne et qu'il retourne à la ligne quand la chaîne de caractère 		 * dépasse les 60 caractères par ligne (avec découpage au mot).
		 */
		void ReturnAtLine(std::string s, unsigned int nb_tab);

		/**
		 * @fn void print_synopsis(string, string);
		 * 
		 * C'est une méthode qui prend en paramètre le nom du programme et sa description et qui affiche toute les possibilités d'éxécution possibles,
		 * ainsi qu'une description pour chaques arguments possibles.
		 */
		void print_synopsis(std::string commande, std::string description);

		/**
		 * @brief Destructeur
		 * 
		 * Destructeur de la classe CommandLine.
		 */
		~CommandLine();
};

#endif
