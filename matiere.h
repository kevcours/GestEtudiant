#ifndef MATIERE
 #define MATIERE
#include <iostream>
#include <vector>
using namespace std;

class Matiere
{
private:
	string nomMatiere;
public:
	string getNomMat();
	void displayMatiere();
	void inputMatiere();

};
#endif