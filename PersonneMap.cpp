#include "PersonneMap.h"

using namespace ProjetPOOMappage;

void PersonneMap::setId(int id)
{
	this->id = id;
}

int PersonneMap::getId()
{
	return this->id;
}

void PersonneMap::setNom(String^ nom)
{
	this->nom = nom;
}

String^ PersonneMap::getNom()
{
	return this->nom;
}

void PersonneMap::setPrenom(String^ prenom)
{
	this->prenom = prenom;
}

String^ PersonneMap::getPrenom()
{
	return this->prenom;
}