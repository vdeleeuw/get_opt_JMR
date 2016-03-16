#include <CommandLine.h>

#include <stdexcept>
#include <vector>
#include <string.h>

/**
 * @file main.c
 * @brief Programme de test
 * @author1 Valérian De Leeuw"\033[0m"
 * @author2 Robin Couasnet
 * @date 20 avril 2015
 *
 * Programme de test pour arguments en ligne de commande C++
 */

int operande = 2;
unsigned nb_iteration = 10;
float resultat = 15.8;
bool deroulement = true;
bool inversion_signe = false;
std::string operateur("add");
std::vector<std::string> liste_operateurs = {"div", "mult", "add", "sub"};

int main(int argc, char** argv) {

	CommandLine cl(argc, argv);

	cl.add(new IntArgument("operande", 'i', &operande, "Entier : Nombre avec lequel on effectuera l'operation sur le resultat."));
	cl.add(new UnsignedIntArgument("nb_iteration", 'u', &nb_iteration, "Entier non signé : Nombre d'itération de la boucle."));
	cl.add(new FloatArgument("resultat", 'f', &resultat, "Flottant : Resultat des calculs."));
	cl.add(new FlagArgument("inversion_signe",  'b', &inversion_signe, "Flag : Si présent n'affiche pas le détail des tours."));
	cl.add(new BoolArgument("deroulement",  'v', &deroulement, "Booléen : Si vrai cela inverse le signe du resultat."));
	cl.add(new VecArgument("operateur", ' ', &operateur, liste_operateurs, "Vecteur : Collection d'opérateurs appliquable sur le resultat."));

	try{
		cl.parse();
	}
	catch(std::logic_error &e){
		cl.print_synopsis("sol3", "Programme de test pour la gestion des arguments en ligne de commandes en C++");
		std::cout << "ERROR(S) : " << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	 
	cl.displayAll();
	
	for(unsigned int i=0; i<nb_iteration; i++)
	{
		if(strcmp(operateur.c_str(), "div") == 0) 
			resultat = resultat / operande;
		else if(strcmp(operateur.c_str(), "mult") == 0) 
			resultat = resultat * operande;
		else if(strcmp(operateur.c_str(), "add") == 0) 
			resultat = resultat + operande;
		else if(strcmp(operateur.c_str(), "sub") == 0) 
			resultat = resultat - operande;
		if(inversion_signe)
			resultat *= -1;
		if(deroulement)
			std::cout << "tour[" << i << "] = " << resultat << std::endl;
	}
	std::cout << "Resultat = " << resultat << std::endl;
	
	

	return 0;
}
