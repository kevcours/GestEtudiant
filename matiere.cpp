#include "matiere.h"

string Matiere::getNomMat()
{
	return nomMatiere;
}

void Matiere::inputMatiere()
{
	cout<< "Saisir le nom de la matiere:"<<endl;
	getline(cin,nomMatiere);
}
void Matiere::displayMatiere()
{
	cout<<"-> "<<nomMatiere<<endl;
}