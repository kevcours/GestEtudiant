#include "eleve.h"

string Eleve::getNom()
{
	return nom;
}
string Eleve::getPrenom()
{
	return prenom;
}
string Eleve::getDdn()
{
	return ddn;
}
string Eleve::getTel()
{
	return tel;
}
string Eleve::getMail()
{
	return mail;
}
string Eleve::getAdresse()
{
	return adresse;
}
void Eleve::displayEleve()
{
	cout<<nom<<"	"<<prenom<<"	"<<ddn<<endl;
}
void Eleve::inputEleve()
{
	cout<<"Nom de l'eleve: ";
	getline(cin,nom);
	cout<<"Prenom de l'eleve: ";
	getline(cin,prenom);
	cout<<"Date de naissance de l'eleve: ";
	getline(cin,ddn);
	cout<<"Adresse de l'eleve: ";
	getline(cin,adresse);
	cout<<"telephone de l'eleve: ";
	getline(cin,tel);
	cout<<"Email de l'eleve: ";
	getline(cin,mail);
	
}
void Eleve::displayInfoPerso()
{
	cout<<endl<<"Nom: "<<nom<<endl
	  	<<"Prenom: "<<prenom<<endl
	  	<<"Date de naissance: "<<ddn<<endl
	  	<<"Adresse: "<<adresse<<endl
	  	<<"Telephone: "<<tel<<endl
	  	<<"Mail: "<<mail;
}