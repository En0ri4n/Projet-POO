#include "AdresseMap.h"

void ProjetPOOMappage::AdresseMap::setIdAdresse(int id)
{
	this->idAdresse = id;
}

int ProjetPOOMappage::AdresseMap::getIdAdresse()
{
	return this->idAdresse;
}

void ProjetPOOMappage::AdresseMap::setVille(VilleMap^ ville)
{
	this->ville = ville;
}

ProjetPOOMappage::VilleMap^ ProjetPOOMappage::AdresseMap::getVille()
{
	return this->ville;
}

void ProjetPOOMappage::AdresseMap::setRue(String^ rue)
{
	this->rue = rue;
}

String^ ProjetPOOMappage::AdresseMap::getRue()
{
	return this->rue;
}

void ProjetPOOMappage::AdresseMap::setNumero(int numero)
{
	this->numero = numero;
}

int ProjetPOOMappage::AdresseMap::getNumero()
{
	return this->numero;
}
