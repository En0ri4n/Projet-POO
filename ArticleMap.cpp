#include "ArticleMap.h"

void ArticleMap::setIdArticle(String^ id)
{
    this->idArticle = id;
}

String^ ArticleMap::getIdArticle()
{
	return this->idArticle;
}

void ArticleMap::setNom(String^ nom)
{
	this->nom = nom;
}

String^ ArticleMap::getNom()
{
	return this->nom;
}

void ArticleMap::setPrix(double prix)
{
	this->prix = prix;
}

double ArticleMap::getPrix()
{
	return this->prix;
}

void ArticleMap::setNature(String^ nature)
{
	this->nature = nature;
}

String^ ArticleMap::getNature()
{
	return this->nature;
}

void ArticleMap::setCouleur(String^ couleur)
{
	this->couleur = couleur;
}

String^ ArticleMap::getCouleur()
{
	return this->couleur;
}

void ArticleMap::setSeuilReapprovisionnement(int seuil)
{
	this->seuilReapprovisionnement = seuil;
}

int ArticleMap::getSeuilReapprovisionnement()
{
	return this->seuilReapprovisionnement;
}

void ArticleMap::setQuantite(int quantite)
{
	this->quantite = quantite;
}

int ArticleMap::getQuantite()
{
	return this->quantite;
}

void ArticleMap::setTaxe(int taxe)
{
	this->taxe = taxe;
}

int ArticleMap::getTaxe()
{
	return this->taxe;
}

ArticleMap^ ArticleMap::from(String^ id, int quantite)
{
	ArticleMap^ article = gcnew ArticleMap();
	article->setIdArticle(id);
	article->setQuantite(quantite);
	return article;
}

bool ProjetPOOMappage::ArticleMap::isInList(String^ ref, System::Collections::ArrayList^ list)
{
	for each (ArticleMap^ article in list)
		if (article->getIdArticle()->Equals(ref))
			return true;

	return false;
}

ArticleMap^ ProjetPOOMappage::ArticleMap::byId(String^ ref, System::Collections::ArrayList^ list)
{
	for each (ArticleMap^ article in list)
		if (article->getIdArticle()->Equals(ref))
			return article;

	return nullptr;
}
