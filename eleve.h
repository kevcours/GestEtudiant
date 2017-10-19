#ifndef ELEVE
 #define ELEVE
#include "bulletin.h"

class Eleve
{
private:
	string nom;
	string prenom;
	string ddn;
	string adresse;
	string tel;
	string mail;
	vector <Bulletin> vectbulletin;
public:
	string getNom();
	string getPrenom();
	string getDdn();
	string getAdresse();
	string getTel();
	string getMail();
	void setNom(string leNom);
	void setPrenom(string lePrenom);
	void setDdn(string laDdn);
	void setTel(string leTel);
	void setMail(string leMail);
	void displayEleve();
	void displayInfoPerso();
	void inputEleve();

};
#endif