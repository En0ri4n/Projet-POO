#include "VilleMap.h"

void ProjetPOOMappage::VilleMap::setIdVille(int id)
{
	this->idVille = id;
}

int ProjetPOOMappage::VilleMap::getIdVille()
{
	return this->idVille;
}

void ProjetPOOMappage::VilleMap::setNom(String^ nom)
{
	this->nom = nom;
}

String^ ProjetPOOMappage::VilleMap::getNom()
{
	return this->nom;
}

void ProjetPOOMappage::VilleMap::setCodePostal(String^ codePostal)
{
	this->codePostal = codePostal;
}

String^ ProjetPOOMappage::VilleMap::getCodePostal()
{
	return this->codePostal;
}