#ifndef SECTION
 #define SECTION
/**
*\file application.h
*\author Courtial Kevin
*\version 0.1
*/

#include "eleve.h"
#include "evaluation.h"
#include "application.h"

/**
*\class Application
*/
class Application;

/**
*\class Section
*/
class Section
{
private:
	string sectNom;
	Application* pMonApplic;
	vector<Matiere*>vectLesMatieresS;
	vector<int>vectLecoeff;
	vector<Eleve>vectLesEleves;
	vector<Evaluation>vectLesEval;
public:
	Section(Application* Matiere);
	string getSectNom();
	void AfficherMenuSect();
	void ajouterEleve();
	void afficherEleve();
	void affecterMatiere();
	void afficherTotalInfo();
	void afficherMatieresSec();
	void creerEval();
	void rentrerLesnotes();
	void afficherEvalEtNotes();
	void creationBulletin();
	void afficheMenuSection();
	char saisieChoixSection();
	void executionDuChoix(char leChoix);
	void displaySection();
	void inputSection();
	void runSection();
	

};
#endif