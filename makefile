#variables de compilation
CC=g++
CFLAGS=-Wall -std=c++0x
LDFLAGS=
LDFLAGSTEST= -lcppunit
EXEC=projet
EXECEXAMPLE=example_$(EXEC)
EXECTEST=test_$(EXEC)
EXECGETOPT=getopt_$(EXEC)

#variables de librairie
LIBFLAG=-r -v
LIBNAME=libprojet.a			#lire la remarque ci dessous.
LIBSHORTNAME=projet 			#attention mettre le meme nom que ci-dessus sans "lib" et l'extension.
LIBREPH=/usr/include/
LIBREP=/usr/lib/

#variable de documentation
DOC=doxygen
DOCSETUP=DoxyMake.mk
DOCERR=DoxyLog.err

#compilation
all: ./bin/$(EXEC)

./bin/$(EXEC): ./obj/main.o ./obj/CommandLine.o ./obj/Argument.o ./obj/IntArgument.o ./obj/UnsignedIntArgument.o ./obj/FloatArgument.o ./obj/BoolArgument.o ./obj/VecArgument.o ./obj/FlagArgument.o
	$(CC) -o $@ $^ $(LDFLAGS)

./obj/CommandLine.o: ./src/CommandLine.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

./obj/Argument.o: ./src/Argument.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

./obj/BoolArgument.o: ./src/BoolArgument.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

./obj/IntArgument.o: ./src/IntArgument.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

./obj/UnsignedIntArgument.o: ./src/UnsignedIntArgument.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

./obj/FloatArgument.o: ./src/FloatArgument.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

./obj/VecArgument.o: ./src/VecArgument.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

./obj/FlagArgument.o: ./src/FlagArgument.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

./obj/main.o: ./src/main.cpp ./src/CommandLine.h ./src/Argument.h ./src/IntArgument.h ./src/UnsignedIntArgument.h ./src/FloatArgument.h ./src/BoolArgument.h ./src/VecArgument.h ./src/FlagArgument.h
	$(CC) -o $@ -c $< $(CFLAGS)

#documentation
.PHONY: doc
doc :
	$(DOC) ./$(DOCSETUP) 2>./doc/$(DOCERR)

#test
test: ./obj/test_CL.o ./obj/CommandLine.o ./obj/Argument.o ./obj/IntArgument.o ./obj/UnsignedIntArgument.o ./obj/FloatArgument.o ./obj/BoolArgument.o ./obj/VecArgument.o ./obj/FlagArgument.o
	$(CC) -o ./bin/$(EXECTEST) $^ $(LDFLAGS) $(LDFLAGSTEST) 

./obj/test_CL.o: ./src/cppunit/test_CL.cpp 
	$(CC) -o $@ -c $< $(CFLAGS)

#lib
lib: ./obj/CommandLine.o ./obj/Argument.o ./obj/IntArgument.o ./obj/UnsignedIntArgument.o ./obj/FloatArgument.o ./obj/BoolArgument.o ./obj/VecArgument.o ./obj/FlagArgument.o
	ar $(LIBFLAG) ./lib/$(LIBNAME) $^

install: ./src/CommandLine.h ./src/Argument.h ./src/IntArgument.h ./src/UnsignedIntArgument.h ./src/FloatArgument.h ./src/BoolArgument.h ./src/VecArgument.h ./src/FlagArgument.h 
	sudo cp $^ $(LIBREPH)
	sudo cp ./lib/$(LIBNAME) $(LIBREP)

#example
example: ./src/example/main.cpp
	$(CC) $^ -o ./bin/$(EXECEXAMPLE) -l$(LIBSHORTNAME) $(CFLAGS)

#getopt
getopt: ./src/getopt/main.cpp
	$(CC) $^ -o ./bin/$(EXECGETOPT)

#nettoyeur
clean:
	rm -rf ./obj/*.o
	rm -rf ./doc/$(DOCERR)

mrproper: clean
	rm -rf ./bin/*
	rm -rf ./lib/*
	rm -rf ./doc/*
	
#help
help:	
	@echo 
	@echo Les commandes utiles :
	@echo
	@echo make : Compile le programme $(EXEC) dans le répertoire bin.
	@echo make doc : Génère une documentation dans le répertoire doc avec $(DOC).
	@echo make lib : Génère une librairie statique $(LIBNAME) dans le répertoire lib.
	@echo make install : Installe la librairie préalablement créée dans le répertoire $(LIBREPH) et $(LIBREP).
	@echo
	@echo
	@echo Les commandes de tests :
	@echo
	@echo make test : Compile un programme de test unitaire $(EXECTEST) pour la classe CommandLine.
	@echo make example : Compile un programme d\'exemple $(EXECEXAMPLE) utilisant la librairie, qui doit être installée.
	@echo make getopt : Compile un programme d\'exemple $(EXECGETOPT) utilisant la librairie getopt.
	@echo
	@echo
	@echo Les commandes de nettoyage : 
	@echo
	@echo make clean : Supprime les fichiers objets, et le fichier d\'erreur de la documentation $(DOCERR).
	@echo make mrproper : Execute clean + Supprime les exécutablesn, la librairie générée et la documentation.
	@echo
	@echo N\'hésitez pas à consulter le ReadMe.txt !
	@echo
