#include "CommandeMap.h"

void ProjetPOOMappage::CommandeMap::setIdCommande(String^ id)
{
	this->idCommande = id;
}

String^ ProjetPOOMappage::CommandeMap::getIdCommande()
{
	return this->idCommande;
}

void ProjetPOOMappage::CommandeMap::setDateLivraison(DateTime^ date)
{
	this->dateLivraison = date;
}

DateTime^ ProjetPOOMappage::CommandeMap::getDateLivraison()
{
	return this->dateLivraison;
}

void ProjetPOOMappage::CommandeMap::setDateEmission(DateTime^ date)
{
	this->dateEmission = date;
}

DateTime^ ProjetPOOMappage::CommandeMap::getDateEmission()
{
	return this->dateEmission;
}

void ProjetPOOMappage::CommandeMap::setMoyenPaiement(String^ moyen)
{
	this->moyenPaiement = moyen;
}

String^ ProjetPOOMappage::CommandeMap::getMoyenPaiement()
{
	return this->moyenPaiement;
}

void ProjetPOOMappage::CommandeMap::setDatePaiement(DateTime^ date)
{
	this->datePaiement = date;
}

DateTime^ ProjetPOOMappage::CommandeMap::getDatePaiement()
{
	return this->datePaiement;
}

void ProjetPOOMappage::CommandeMap::setIdClient(int id)
{
	this->idClient = id;
}

int ProjetPOOMappage::CommandeMap::getIdClient()
{
	return this->idClient;
}

void ProjetPOOMappage::CommandeMap::setListeArticles(Collections::ArrayList^ liste)
{
	this->listeArticles = liste;
}

Collections::ArrayList^ ProjetPOOMappage::CommandeMap::getListeArticles()
{
	return this->listeArticles;
}

void ProjetPOOMappage::CommandeMap::setDerniereListeArticles(Collections::ArrayList^ list)
{
	this->derniereListeArticles = list;
}

Collections::ArrayList^ ProjetPOOMappage::CommandeMap::getDerniereListeArticles()
{
	return this->derniereListeArticles;
}

ProjetPOOMappage::CommandeMap^ ProjetPOOMappage::CommandeMap::from(String^ id)
{
	CommandeMap^ commande = gcnew CommandeMap();
	commande->setIdCommande(id);
	return commande;
}
