#include "evaluation.h"

//accesseur semestre
int Evalutation::getSemestre()
{
	return semestre;
}
//accesseur date
string Evaluation::getDate()
{
	return date;
}
//accesseur sujet
string Evaluation::getsujet()
{
	return sujet;
}
//affichage des infos de l'eval
void Evaluation::displayInfoEval()
{
	cout<<"Semestre :"<<semestre<<endl
		<<"Date de l'evaluation: "<<date<<endl<<
		<<"Sujet de l'evaluation: "<<sujet<<endl;
}
//remplir l'evaluation
void Evaluation::inputInfoEval()
{
	cout<<"Saisir le semestre de l'evaluation: "<<endl;
	cin>>semestre;
	cin.ignore(1);
	cout<<"Saisir la date de l'évaluation: "<<endl;
	getline(cin,date);
	cout<<"Saisir le sujet de l'evaluation"<<endl;
	getline(cin,sujet);
}