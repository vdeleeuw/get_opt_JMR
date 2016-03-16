#include "test_CL.h"
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
#include <getopt.h>
#include <cstring>
#include <signal.h>
#include <err.h>
#include <cstdlib>
#include <cstdio>
#include <typeinfo>

/**
 * @file test_CL.cpp
 * @brief Code C++ de la classe TestFixture
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 23 avril 2015
 */
     
void signal_handler(int sig) {
	cerr << endl << "caught signal " << sig << endl;
	cerr.flush();  
	return ;
}
     
void set_signal_handler() {
	signal( SIGABRT, signal_handler);
	signal( SIGHUP, signal_handler);
	signal( SIGILL, signal_handler);
}

// ----------------------------------------------
// description of possible arguments
// that can be used in
// - short format : -m 1
// - or long format : --method=1
// ----------------------------------------------
static struct option long_options[] = {
	{"nbr-tests",     no_argument, 0, 'n'},
	{"output-format",   required_argument, 0, 'f'},
	{0,0,0,0}
};

typedef struct {
	string output_file;
	int  output_format;
	bool flag_get_nbr_tests;
} Parameters;

Parameters params;

const char *params_format_allowed[] = { "text", "xml", NULL };

int get_allowed_value(const char *s, const char *tab[]) {
	for (int i=0; tab[i] != NULL; ++i) {
		if (strcmp(s,tab[i])==0) return i;
	}
	return -1;
}

void usage(char *prog_name) {
	cout << prog_name << endl;
	cout << "--output-format=text|xml" << endl;
	cout << "--nbr-tests" << endl;

	exit(EXIT_FAILURE);
}

// ----------------------------------------------

//var
int pint;
unsigned puint;
float pfloat;
bool pbool;
bool pflag;
std::string pstr("default");
std::vector<std::string> pvec = {"test1", "test2", "test3"};
unsigned int aux_argc = 5;
char* aux_argv[5] = {"test_sol3","-i", "3","-v","--pfloat=4.3"};

//arg
IntArgument *IntArg;
UnsignedIntArgument *UnsIntArg;
FloatArgument *FloatArg; 
BoolArgument *BoolArg; 
VecArgument *VecArg;
FlagArgument *FlagArg;

/**
* setUp: function called before each test
*/
void TestFixture::setUp() {
	IntArg = new IntArgument("pint", 'i', &pint, "Entier : Nombre négatif ou positif, sans valeur décimale.");
	UnsIntArg = new UnsignedIntArgument("", 'u', &puint, "Entier non signé : Nombre positif, sans valeur décimale.");
	FloatArg = new FloatArgument("pfloat", 'f', &pfloat, "Flottant : Nombre positif ou négatif pouvant posséder une valeur décimale");
	BoolArg = new BoolArgument("pbool",  'b', &pbool, "Booléen : Uniquement deux valeurs possibles : true ou false.");
	VecArg = new VecArgument("pstr", ' ', &pstr, pvec, "Vecteur : Collection de valeur.");
	FlagArg = new FlagArgument("pflag",  'v', &pflag, "Flag : Booléen sans valeur, si présent dans la ligne de commande celle-ci sera vraie.");
	cl.setArgC(aux_argc);
	cl.setArgV(aux_argv);
	cl.add(IntArg);
	cl.add(FloatArg);
	cl.add(UnsIntArg);
	//cl.add(BoolArg);
	cl.add(VecArg);
	cl.add(FlagArg);
}

/**
* setUp: function called after each test
*/
void TestFixture::tearDown() {
	cl.setArgC(0);
	cl.setArgV(NULL);
	cl.getVecArg().clear();
}


void TestFixture::test_parse() {
	try{
		cl.parse();
		CPPUNIT_ASSERT(1==1);
	}catch(exception e){
		CPPUNIT_ASSERT(0==1);
	}
}


void TestFixture::test_find(){
	try{
		cl.find("-i");
		CPPUNIT_ASSERT(1==1);
	}catch(exception e){
		CPPUNIT_ASSERT(0==1);
	}
}


void TestFixture::test_add(){
	try{
		cl.add(BoolArg);
		CPPUNIT_ASSERT(1==1);
	}catch(exception e){
		CPPUNIT_ASSERT(0==1);
	}
}	

void TestFixture::test_display() {
	try{
		cl.display();
		CPPUNIT_ASSERT(1==1);
	}catch(exception e){
		CPPUNIT_ASSERT(0==1);
	}
}

void TestFixture::test_getChoixArg(){
	try{
		cl.getChoixArg(IntArg);
		CPPUNIT_ASSERT(1==1);
	}catch(exception e){
		CPPUNIT_ASSERT(0==1);
	}
}

void TestFixture::test_print_synopsis(){
	try{
		cl.print_synopsis("Test", "Tested with cppunit");
		CPPUNIT_ASSERT(1==1);
	}catch(exception e){
		CPPUNIT_ASSERT(0==1);
	}
}


/**
* declare suite of tests
*
*/
CppUnit::TestSuite *make_suite() {
	CppUnit::TestSuite *suite = new CppUnit::TestSuite(CLASS_NAME_STRING);
	cout << "==============================================" << endl;
	cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
	cout << "==============================================" << endl;

	
	TEST_ADD(find);
	TEST_ADD(add);
	TEST_ADD(parse);	
	TEST_ADD(display);
	TEST_ADD(getChoixArg);
	TEST_ADD(print_synopsis);

	return suite;
}

/**
* main function
*/
int main(int argc, char *argv[]) {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::XmlOutputter *xml_outputter = NULL;

	params.output_file = "";
	params.output_format = 0; // text
	params.flag_get_nbr_tests = false;

	int option_index;
	while (true) {
		option_index = 0;
		int c = getopt_long(argc, argv, "f:n", long_options, &option_index);
		if (c == -1) break;

		switch(c) {
			case 'n':
			params.flag_get_nbr_tests = true;
			break;
			case 'f':
			params.output_format = get_allowed_value(optarg, params_format_allowed);
			break;
		}
	}

	if (params.output_format == -1) {
		usage(argv[0]);
	}

	set_signal_handler();

	// create suite
	CppUnit::TestSuite *suite = make_suite();
	runner.addTest(suite);

	if (params.output_format == 1) {
		cout << "xml file=" << OUTPUT_XML_FILE << endl;
	}

	if (params.flag_get_nbr_tests == true) {
		const std::vector<CppUnit::Test *>& tests = suite->getTests();
		cout << "nbr_tests=" << tests.size() << endl;
		exit(EXIT_SUCCESS);
	}

	// set output format as text
	runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), cout));

	// run all tests
	runner.run();

	if (params.output_format == 1) {
		ofstream xml_out(OUTPUT_XML_FILE);
		xml_outputter = new CppUnit::XmlOutputter(&runner.result(), xml_out);
		xml_outputter->write();
		xml_out.close();
	}

	return 0;
}
