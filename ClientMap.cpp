#include "ClientMap.h"

DateTime^ ProjetPOOMappage::ClientMap::getDateNaissance()
{
    return this->dateNaissance;
}

void ProjetPOOMappage::ClientMap::setDateNaissance(DateTime^ dateNaissance)
{
	this->dateNaissance = dateNaissance;
}

DateTime^ ProjetPOOMappage::ClientMap::getDatePremierAchat()
{
	return this->datePremierAchat;
}

void ProjetPOOMappage::ClientMap::setDatePremierAchat(DateTime^ datePremierAchat)
{
	this->datePremierAchat = datePremierAchat;
}

AdresseMap^ ProjetPOOMappage::ClientMap::getAdresseLivraison()
{
	return this->adresseLivraison;
}

void ProjetPOOMappage::ClientMap::setAdresseLivraison(AdresseMap^ adresseLivraison)
{
	this->adresseLivraison = adresseLivraison;
}

AdresseMap^ ProjetPOOMappage::ClientMap::getAdresseFacturation()
{
	return this->adresseFacturation;
}

void ProjetPOOMappage::ClientMap::setAdresseFacturation(AdresseMap^ adresseFacturation)
{
	this->adresseFacturation = adresseFacturation;
}
