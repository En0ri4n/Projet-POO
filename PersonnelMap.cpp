#include "PersonnelMap.h"

ProjetPOOMappage::PersonnelMap::PersonnelMap()
{
    this->idPersonnel = -1;
    this->nom = "";
    this->prenom = "";
    this->dateEmbauche = DateTime::Now;
}

void ProjetPOOMappage::PersonnelMap::setIdPersonnel(int idPersonne)
{
    this->idPersonnel = idPersonne;
}

int ProjetPOOMappage::PersonnelMap::getIdPersonnel()
{
    return this->idPersonnel;
}

void ProjetPOOMappage::PersonnelMap::setNom(String^ nom)
{
    this->nom = nom;
}

String^ ProjetPOOMappage::PersonnelMap::getNom()
{
    return this->nom;
}

void ProjetPOOMappage::PersonnelMap::setPrenom(String^ prenom)
{
    this->prenom = prenom;
}

String^ ProjetPOOMappage::PersonnelMap::getPrenom()
{
    return this->prenom;
}

void ProjetPOOMappage::PersonnelMap::setDateEmbauche(DateTime^ date)
{
    this->dateEmbauche = date;
}

DateTime^ ProjetPOOMappage::PersonnelMap::getDateEmbauche()
{
    return this->dateEmbauche;
}
