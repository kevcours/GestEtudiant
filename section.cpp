
#include "section.h"

string Section::getSectNom()
{
	return sectNom;
}
void Section::inputSection()
{
	cout<< "Saisir le nom de la section:"<<endl;
	getline(cin,sectNom);
}
void Section::displaySection()
{
	cout<<"-> "<<sectNom<<endl;
}
void Section::runSection()
{
	char sonChoix;
	do
	{
		afficheMenuSection();
		sonChoix=saisieChoixSection();
		executionDuChoix(sonChoix);
	}
	while(!(sonChoix=='q'));
}
void Section::afficheMenuSection()
{
	int nbEleve=vectLesEleves.size();
	int nbMatiere=vectLesMatieresS.size();
	if ((nbEleve==0)&&(nbMatiere==0))
	{
		cout<<endl<<endl;
		cout<< "Vous etes dans le menu Section "<<endl<<endl;
		cout<<"Que voulais vous faire : "<<endl
			<<" 'e' pour ajouter un(e) Eleve "<<"	"<<" 'm' pour ajouter une matiere a la section "<<endl
			<<" 'q' pour quitter"<<endl;
	}
	else if ((nbEleve==0)&&(nbMatiere!=0))
	{
		cout<<endl<<endl;
		cout<< "Vous etes dans le menu Section "<<endl<<endl;
		cout<<"Que voulais vous faire : "<<endl
			<<" 'e' pour ajouter un(e) Eleve "<<"	"<<" 'm' pour ajouter une matiere a la section "<<endl
			<<"'M' pour afficher les matieres de la section "<<"	"<<" 'q' pour quitter"<<endl;
	}
	else if ((nbEleve!=0)&&(nbMatiere==0))
	{
		cout<<endl<<endl;
		cout<< "Vous etes dans le menu Section "<<endl<<endl;
		cout<<"Que voulais vous faire : "<<endl
			<<" 'e' pour ajouter un(e) Eleve "<<"	"<<" 'm' pour ajouter une matiere a la section "<<endl
			<<"'E' pour afficher les Eleves "<<"	"<<" 'g' pour Afficher toute les info d'un eleve "<<endl
			<<" 'q' pour quitter"<<endl;
	}
	else
	{
		cout<<endl<<endl;
		cout<< "Vous etes dans le menu Section "<<endl<<endl;
		cout<<"Que voulais vous faire : "<<endl
			<<" 'e' pour ajouter un(e) Eleve "<<"	"<<" 'm' pour ajouter une matiere a le section "<<endl
			<<"'E' pour afficher les Eleves "<<"	"<<"'M' pour afficher les matieres de la section "<<endl
			<<" 'g' pour selectionner les info d'un Eleve "<<"	"<<" 'q' pour quitter"<<endl;

	}
}
char Section::saisieChoixSection()
{

	char leChoix;
	cin>>leChoix;
	cin.ignore(1);
	int nbEleve=vectLesEleves.size();
	int nbMatiere=vectLesMatieresS.size();
	
	if ((nbEleve==0)&&(nbMatiere==0))
	{
		while(!(leChoix=='e' or leChoix=='q' or leChoix=='m'))
		{
			cout<<"Erreur lors du choix veuiller recommencer (attention au majuscule): "<<endl;
			afficheMenuSection();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	else if ((nbEleve==0)&&(nbMatiere!=0))
	{
		while(!(leChoix=='e' or leChoix=='m' or leChoix=='M' or leChoix=='q'))
		{
			cout<<"Erreur lors du choix veuiller recommencer (attention au majuscule): "<<endl;
			afficheMenuSection();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	else if ((nbEleve!=0)&&(nbMatiere==0))
	{
		while(!(leChoix=='e' or leChoix=='E' or leChoix=='m' or leChoix=='q' or leChoix=='g'))
		{
			cout<<"Erreur lors du choix veuiller recommencer (attention au majuscule): "<<endl;
			afficheMenuSection();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	else if ((nbEleve==0)&&(nbMatiere!=0))
	{
		while(!(leChoix=='e' or leChoix=='E' or leChoix=='m' or leChoix=='M' or leChoix=='q' or leChoix=='g'))
		{
			cout<<"Erreur lors du choix veuiller recommencer (attention au majuscule): "<<endl;
			afficheMenuSection();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	return leChoix;
}

void Section::executionDuChoix(char leChoix)
{
	switch (leChoix)
	{
		case 'm':
		{
			affecterMatiere();
			break;
		}
		case 'M':
		{
			afficherMatieresSec();
			break;
		}
		case 'e':
		{
			ajouterEleve();
			break;
		}
		case 'E':
		{
			afficherEleve();
			break;
		}
		case 'g':
		{
			afficherTotalInfo();
		}
		
	}
}
void Section::afficherMatieresSec()
{
	cout<<"La/Les matiere()s enregistrée(s)dans la section: "<<endl;
	int nbMat= vectLesMatieresS.size();
	for (int i=0 ; i<nbMat ; i++)
	{
		vectLesMatieresS[i]->displayMatiere();
	}
}
void Section::afficherEleve()
{
	cout<<"Les ELeve(s) enregistré(s): "<<endl;
	int nbEleve= vectLesEleves.size();
	for (int i=0 ; i<nbEleve ; i++)
	{
		vectLesEleves[i].displayEleve();
	}
}
void Section::ajouterEleve()
{
	int verif =0;
	Eleve newEleve;
	newEleve.inputEleve();
	int nbEleve=vectLesEleves.size();
	if (nbEleve==0)
	{
		vectLesEleves.push_back(newEleve);
	}
	else
	{
		for(int i=0 ; i<nbEleve ;i++)
		{
			if(newEleve.getNom()==vectLesEleves[i].getNom())
			{
				verif +=0;
			}
			else
			{
				verif+=1;
			}
		}
		if (verif == nbEleve)
		{
			//La matiere n'éxiste pas 
			vectLesEleves.push_back(newEleve);
		}
		else 
		{
			//Si vérif a vu que la matiere existait déjà :
			cout<<"La matiere existe deja!"<<endl;
			
		}
	}
}
void Section::afficherTotalInfo()
{	
	int nbEleve=vectLesEleves.size();
	string newPrenom;
	string newNom;
	cout<<"Prenom: ";
	getline(cin,newPrenom);
	cout<<"Nom: ";
	getline(cin,newNom);
	for (int i=0; i<nbEleve; i++ )
	{
		if((newPrenom==vectLesEleves[i].getPrenom())and(newNom==vectLesEleves[i].getNom()))
			vectLesEleves[i].displayInfoPerso();
	}
}
void Section::affecterMatiere()
{	
	int coef;
	int verif=0;
	vector<Matiere*> vectMat= pMonApplic->getVectMatieres();
	
	int nbmatTotal=vectMat.size();
	int nbMatDeLaSection=vectLesMatieresS.size();
	if (nbmatTotal==0)
	{
		cout<<"Il n'y a pas de matieres Enregistée";
	}
	else//il y a des matières
	{
		int numero;
		cout<<"Matieres: "<<endl;
		//affichage de toutes les matières de l'application
		for (int i=0 ;i<nbmatTotal; i++)
		{
			
				cout<<i+1<<"-"<<vectMat[i]->getNomMat()<<endl;
		}
		cout<<endl<<"Choisir la matiere à ajouter a la section: (numéro)"<<endl;
		cin>>numero;
		cin.ignore(1);
		if(( numero<=nbmatTotal)&&(numero>0))
		{
			if(nbMatDeLaSection==0)
			{
				vectLesMatieresS.push_back(vectMat[numero-1]);
				cout<<" saisir le coefficient: "<<endl;
					cin>>coef;
					cin.ignore(1);
					vectLecoeff.push_back(coef);
			}
			else
			{
				for(int n=0;n<nbMatDeLaSection;n++)
				{
					if(vectMat[numero-1]->getNomMat()==vectLesMatieresS[n]->getNomMat())
						verif++;
					
				}
				//matière non présente
				if (verif==0)
				{
					vectLesMatieresS.push_back(vectMat[numero-1]);
					cout<<" saisir le coefficient: "<<endl;
					cin>>coef;
					cin.ignore(1);
					vectLecoeff.push_back(coef);

				}
				else // Matiere deja existante
				{
					cout<<"La Matiere existe deja !"<<endl;

				}
			}
		}
		else //Numero de saisir incorrect
		{
			cout<<"Choix de matiere incorrect !"<<endl;
		}
	}
}
Section::Section(Application* appli)
{
	pMonApplic=appli;
}
