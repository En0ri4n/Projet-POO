#include "PersonnelMap.h"

void ProjetPOOMappage::PersonnelMap::setAdresse(AdresseMap^ adresse)
{
	this->adresse = adresse;
}

ProjetPOOMappage::AdresseMap^ ProjetPOOMappage::PersonnelMap::getAdresse()
{
	return this->adresse;
}

void ProjetPOOMappage::PersonnelMap::setDateEmbauche(DateTime^ date)
{
    this->dateEmbauche = date;
}

DateTime^ ProjetPOOMappage::PersonnelMap::getDateEmbauche()
{
    return this->dateEmbauche;
}

void ProjetPOOMappage::PersonnelMap::setIdSuperviseur(int id)
{
    this->idSuperviseur = id;
}

int ProjetPOOMappage::PersonnelMap::getIdSuperviseur()
{
	return this->idSuperviseur;
}
