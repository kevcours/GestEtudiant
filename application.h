	#ifndef APPLICATION
 #define APPLICATION

/**
*\file application.h
*\author Courtial Kevin
*\version 0.1
*/

#include "section.h"
#include "matiere.h"

/**
*\class Section
*/
class Section;

/**
*\class Application
*/
class Application
{
private:
/**
*\brief Conteneur des sections
* contient l'ensemble section ajouter par l'utilisateur
*/
	vector<Section>vectLesSections;
/**
*\brief Conteneur des matieres
* contient toute les matieres enregistrées par l'utilisateurs
*/
	vector<Matiere>vectLesMatieres;
public:
/**
*\fn d'execution de toute les taches
*\brief permet de regrouper et d'exectuter les action dans le main
*/
	void run();
/**
*\fn vector<Matiere> getVectLesMatiere()
*\return vectLesMatiere
*\brief Permet a la classe section de recuperer les differente matiere de l'application
*/
	vector<Matiere*> getVectMatieres();
/**
*\fn afficheMenuAppli()
*\brief Afficher les menu de l'application en fonction des matieres et des sections enregistrées
*/
	void afficheMenuAppli();
/**
*\fn saisieChoixAppli
*\return Le choix saisie pas l'utilisateur
*/
	char saisieChoixAppli();
/**
*\fn appliquerLeChoix(char Lechoix)
*\brief Exectute l'action lier au choix de l'utilisateur
*/
	void appliquerLeChoix(char leChoix);
/**
*\fn creerSection()
*\brief Permet a l'utilisateur de créer une nouvelle section dans l'application
*/
	void creerSection();
/**
*\fn creerMatiere()
*\brief Permet a l'utilisateur de créer une nouvelle matiere dans l'application
*/
	void creerMatiere();
/**
*\fn afficherSection()
*\brief Permet a l'utilisateur d'afficher toute les sections stocker dans l'application
*/
	void afficherSection();
/**
*\fn afficherMatiere()
*\brief Permet a l'utilisateur d'afficher toute les matieres stocker dans l'application
*/
	void afficherMatiere();
/**
*\fn selectionnerSection()
*\brief Permet a l'utilisateur de selectionner une section parmis toute celle renseigner dans l'application afin d'acceder a son menu
*/
	void selectionnerSection();

};
#endif