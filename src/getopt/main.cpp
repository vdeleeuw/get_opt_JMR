#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <getopt.h>

static int inversion_signe; 

int main (int argc, char **argv){
	
	std::string operateur("add");
	int operande = 2;
	unsigned nb_iteration = 10;
	float resultat = 0;
	bool deroulement = true;
	opterr = 0; 
	int index;
  	int c; 

	while (1){
	
		static struct option long_options[] = {
          	{"inversion_signe", no_argument, &inversion_signe, 0},
          	{"operande", required_argument, 0, 'i'},
          	{"nb_iteration", required_argument, 0, 'u'},
          	{"resultat", required_argument, 0, 'f'},
          	{"deroulement", required_argument, 0, 'v'},
          	{"operateur", required_argument, 0, 'o'},
          	{0, 0, 0, 0}
        };

		int option_index = 0;
		c = getopt_long (argc, argv, "i:u:f:b:o:", long_options, &option_index);

		if (c == -1)
			break;

		switch (c){

			//flag
			case 0:
		     	inversion_signe = true;
		    break;

		    case 'i':
    		    operande = atoi(optarg);
    	    break;

      		case 'u':
        		nb_iteration = atoi(optarg);
        	break;

			case 'f':
				resultat = atof(optarg);
			break;

			case 'b':
				if(strcmp(optarg, "true") == 0)
					deroulement = true;					
				else if (strcmp(optarg, "false") == 0)
					deroulement = false;
			break;

			case 'o':
				operateur = optarg;
			break;

      		case '?':
		   		if (optopt == 'c')
		      		fprintf (stderr, "Option -%c requires an argument.\n", optopt);
		    	else if (isprint (optopt))
		      		fprintf (stderr, "Unknown option `-%c'.\n", optopt);
		    	else
		      		fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
		    	return 1;

      		default:
        		abort ();
		}
    }

	for (index = optind; index < argc; index++)
		printf ("Non-option argument %s\n", argv[index]);

	for(unsigned int i=0; i<nb_iteration; i++){
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
