#ifndef NOTE
 #define NOTE
#include "eleve.h"

class Note
{
private:
	int note;
public:
	vector<Eleve*>lesEleves;
	int getNote();
	void displayNote();
	void inputNote();
	

};
#endif