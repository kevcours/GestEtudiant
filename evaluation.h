#ifndef EVALUATION
 #define EVALUATION
#include "note.h"
#include "matiere.h"

class Evaluation
{
private:
	int semestre;
	string date;
	string sujet;
	vector <Matiere*>laMatiere;
	vector<Note> vectNote;
public:
	int getSemestre();
	string getDate();
	string getSujet();
	void displayEval();
	void remplirNote(); 
	void inputEval();
	
};
#endif