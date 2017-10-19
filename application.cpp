#include "application.h"
#include "matiere.h"
#include "section.h"

void Application::run()
{
	char sonChoix;
	do
	{
		afficheMenuAppli();
		sonChoix=saisieChoixAppli();
		appliquerLeChoix(sonChoix);
	}
	while(!(sonChoix=='q'));
}

void Application::afficheMenuAppli()
{
	int nbSection=vectLesSections.size();
	int nbMatiere=vectLesMatieres.size();
	if ((nbSection==0)&&(nbMatiere==0))
	{
		
		cout<<endl<<endl<< "Vous etes dans le menu Application "<<endl<<endl;
		cout<<"Que voulais vous faire : "<<endl
			<<" 's' pour ajouter une section "<<"	"<<" 'm' pour ajouter une matiere "<<endl
			<<" 'q' pour quitter"<<endl;
	}
	else if ((nbSection==0)&&(nbMatiere!=0))
	{
		
		cout<<endl<<endl<< "Vous etes dans le menu Application "<<endl<<endl;
		cout<<"Que voulais vous faire : "<<endl
			<<" 's' pour ajouter une section "<<"	"<<" 'm' pour ajouter une matiere "<<endl
			<<"'M' pour afficher les matieres "<<"	"<<" 'q' pour quitter"<<endl;
	}
	else if ((nbSection!=0)&&(nbMatiere==0))
	{
	
		cout<<endl<<endl<< "Vous etes dans le menu Application "<<endl<<endl;
		cout<<"Que voulais vous faire : "<<endl
			<<" 's' pour ajouter une section "<<"	"<<" 'm' pour ajouter une matiere "<<endl
			<<"'S' pour afficher les sections "<<"	"<<" 'g' pour selectionner une Section "<<endl
			<<" 'q' pour quitter"<<endl;
	}
	else
	{
		cout<<endl<<endl<< "Vous etes dans le menu Application "<<endl<<endl;
		cout<<"Que voulais vous faire : "<<endl
			<<" 's' pour ajouter une section "<<"	"<<" 'm' pour ajouter une matiere "<<endl
			<<"'S' pour afficher les sections "<<"	"<<"'M' pour afficher les matieres "<<endl
			<<" 'g' pour selectionner une Section "<<"	"<<" 'q' pour quitter"<<endl;

	}
}
char Application::saisieChoixAppli()                           //Enregistrer le choix dans une variable
{
	char leChoix;
	cin>>leChoix;
	cin.ignore(1);
	int nbSection=vectLesSections.size();
	int nbMatiere=vectLesMatieres.size();
	
	if ((nbSection==0)&&(nbMatiere==0))
	{
		while(!(leChoix=='s' or leChoix=='q' or leChoix=='m'))
		{
			cout<<"Erreur lors du choix veuiller recommencer (attention au majuscule): "<<endl;
			afficheMenuAppli();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	else if ((nbSection==0)&&(nbMatiere!=0))
	{
		while(!(leChoix=='s' or leChoix=='m' or leChoix=='M' or leChoix=='q'))
		{
			cout<<"Erreur lors du choix veuiller recommencer (attention au majuscule): "<<endl;
			afficheMenuAppli();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	else if ((nbSection!=0)&&(nbMatiere==0))
	{
		while(!(leChoix=='s' or leChoix=='S' or leChoix=='m' or leChoix=='q' or leChoix=='g'))
		{
			cout<<"Erreur lors du choix veuiller recommencer (attention au majuscule): "<<endl;
			afficheMenuAppli();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	else if ((nbSection==0)&&(nbMatiere!=0))
	{
		while(!(leChoix=='S' or leChoix=='s' or leChoix=='m' or leChoix=='M' or leChoix=='q' or leChoix=='g'))
		{
			cout<<"Erreur lors du choix veuiller recommencer (attention au majuscule): "<<endl;
			afficheMenuAppli();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	return leChoix;
}


void Application::creerMatiere()
{
	int verif =0;
	Matiere newMatiere;
	newMatiere.inputMatiere();
	int nbMat=vectLesMatieres.size();
	if (nbMat==0)
	{
		vectLesMatieres.push_back(newMatiere);
	}
	else
	{
		for(int i=0 ; i<nbMat ;i++)
		{
			if(newMatiere.getNomMat()==vectLesMatieres[i].getNomMat())
			{
				verif +=0;
			}
			else
			{
				verif+=1;
			}
		}
		if (verif == nbMat)
		{
			//La matiere n'éxiste pas 
			vectLesMatieres.push_back(newMatiere);
		}
		else 
		{
			//Si vérif a vu que la matiere existait déjà :
			cout<<"La matiere existe deja!"<<endl;
			
		}
	}
	
	
}
void Application::creerSection()
{
	int verif =0;
		Section newSection(this);
		newSection.inputSection();
		int nbSect=vectLesSections.size();
		if (nbSect==0)
		{
			vectLesSections.push_back(newSection);
		}
		else
		{
			for(int i=0 ; i<nbSect ;i++)
			{
				if(newSection.getSectNom()==vectLesSections[i].getSectNom())
				{
					verif +=0;
				}
				else
				{
					verif+=1;
				}
			}
			if (verif == nbSect)
			{
				//La Section n'éxiste pas 
				vectLesSections.push_back(newSection);
			}
			else 
			{
				//Si vérif a vu que la Section existait déjà :
				cout<<"La Section existe deja!"<<endl;
				
			}
		}
}

void Application::appliquerLeChoix(char leChoix)
{

	switch (leChoix)
	{
		case 'm':
		{
			creerMatiere();
			break;
		}
		case 'M':
		{
			afficherMatiere();
			break;
		}
		case 's':
		{
			creerSection();
			break;
		}
		case 'S':
		{
			afficherSection();
			break;
		}
		case 'g':
		{
			selectionnerSection();
		}
		
	}

}

void Application::afficherMatiere()
{
	cout<<"La/Les matiere()s enregistrée(s): "<<endl;
	int nbMat= vectLesMatieres.size();
	for (int i=0 ; i<nbMat ; i++)
	{
		vectLesMatieres[i].displayMatiere();
	}
}

void Application::afficherSection()
{
	cout<<"La/Les Section enregistrée(s): "<<endl;
	int nbSection= vectLesSections.size();
	for (int i=0 ; i<nbSection ; i++)
	{
		vectLesSections[i].displaySection();
	}
}

void Application::selectionnerSection()
{
	int verif=0;
	int nbSection= vectLesSections.size();
	string section;
	afficherSection();
	cout<<"Choisir une section: "<<endl;
	getline(cin,section);
	for (int i=0; i<nbSection;i++)
	{
		if (section==vectLesSections[i].getSectNom())
		{
			cout<<"vous etes bien dans la section: "<<vectLesSections[i].getSectNom()<<endl;
			vectLesSections[i].runSection();

			verif++;
		}
	}
	if(verif==0)
	{
		cout<<"Aucune section correspond a votre choix"<<endl;
		
	}
}
vector<Matiere*> Application::getVectMatieres()
{
	vector<Matiere*> resultat;
	int nbMat=vectLesMatieres.size();
	for (int numMat=0 ; numMat<nbMat; numMat++)
	{
		resultat.push_back(&vectLesMatieres[numMat]);
	}
	return resultat;
}0