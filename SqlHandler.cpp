#include "SqlHandler.h"

ProjetPOOServices::SqlHandler::SqlHandler(void)
{
	this->manager = gcnew ProjetPOO::SqlManager();
	this->query = gcnew ProjetPOOMappage::SqlQuery();
}

Data::DataSet^ ProjetPOOServices::SqlHandler::selectionnerToutesLesPersonnes(String^ dataTableName)
{
	String^ sql = this->query->Select();
	return this->manager->getRows(sql, dataTableName);
}

void ProjetPOOServices::SqlHandler::ajouterUnePersonne(String^ nom, String^ prenom)
{
	String^ sql;

	this->query->setNom(nom);
	this->query->setPrenom(prenom);
	sql = this->query->Insert();

	this->manager->actionRows(sql);
}

void ProjetPOOServices::SqlHandler::supprimerUnePersonne(int id)
{
	String^ sql;
	this->query->setId(id);
	sql = this->query->Delete();

	this->manager->actionRows(sql);
}

void ProjetPOOServices::SqlHandler::mettreAJourUnePersonne(int id, String^ nom, String^ prenom)
{
	String^ sql;

	this->query->setId(id);
	this->query->setNom(nom);
	this->query->setPrenom(prenom);
	sql = this->query->Update();

	this->manager->actionRows(sql);
}
