#ifndef TEST_CL_H
#define TEST_CL_H
   
#include "cppunit/TestCase.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestSuite.h"
#include "cppunit/CompilerOutputter.h"
#include "cppunit/XmlOutputter.h"
#include "cppunit/ui/text/TestRunner.h"
    
#include "../CommandLine.h"
using namespace std;
     
// Use those macros and repeat the class name three times in
// CLASS_NAME, CLASS_NAME_STRING, OUTPUT_XML_FILE
#define CLASS_NAME CommandLine
#define CLASS_NAME_STRING "CommandLine"
#define OUTPUT_XML_FILE "test_cl.xml"
     
// define test in header file
#define TEST_DEF(x) void test_##x()
// add test to test suite
#define TEST_ADD(name) \
suite->addTest(new CppUnit::TestCaller<TestFixture>("test_"#name, \
&TestFixture::test_##name));
     
/**
 * @file test_CL.h
 * @brief Header de la classe TestFixture
 * @author { Valérian De Leeuw, Robin Couasnet }
 * @date 23 avril 2015
 */     

class TestFixture : public CppUnit::TestFixture {
private:
	CommandLine cl;
 
public:
	void setUp();
	void tearDown();

	TEST_DEF(parse);	
	TEST_DEF(find);
	TEST_DEF(add);
	TEST_DEF(display);
	TEST_DEF(getChoixArg);
	TEST_DEF(print_synopsis);

};
     
#endif /* TEST_CL_H */
