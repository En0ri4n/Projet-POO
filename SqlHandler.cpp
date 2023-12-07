#include "SqlHandler.h"

ProjetPOOServices::SqlHandler::SqlHandler(DataGridView^ dgv)
{
	this->manager = gcnew ProjetPOO::SqlManager();
	this->query = gcnew ProjetPOOMappage::SqlQuery();
	this->dataGridView = dgv;
}

void ProjetPOOServices::SqlHandler::fill(String^ table)
{
	dataGridView->DataSource = this->manager->getRows(this->query, table);
	dataGridView->DataMember = table;
}

/*
* Remplis la DataGridView avec tous les éléments de la table donnée
*/
void ProjetPOOServices::SqlHandler::fillGrid(Table^ table)
{
	this->query->newQuery(false, "SELECT * FROM " + table->getName());
	fill(table->getName());
}

/*
* Remplis la DataGridView avec le résultat de la requête donnée
*/
void ProjetPOOServices::SqlHandler::fillGrid(String^ query, String^ tableName)
{
	this->query->newQuery(false, query);
	fill(tableName);
}

void ProjetPOOServices::SqlHandler::searchByColumn(Table^ table, String^ columnName, String^ value, bool isNumeric)
{
	if(isNumeric)
		this->query->newQuery(false, String::Format("SELECT * FROM {0} WHERE {1}={2}", table->getName(), columnName, value));
	else
		this->query->newQuery(false, String::Format("SELECT * FROM {0} WHERE {1} LIKE '%{2}%'", table->getName(), columnName, value));
	fill(table->getName());
}

void ProjetPOOServices::SqlHandler::fillGrid(Table^ table, DataGridView^ grid)
{
	SqlQuery^ query = gcnew SqlQuery();
	SqlManager^ manager = gcnew SqlManager();
	query->newQuery(false, "SELECT * FROM " + table->getName());
	grid->DataSource = manager->getRows(query, table->getName());
	grid->DataMember = table->getName();
}

void ProjetPOOServices::SqlHandler::fillGrid(String^ query, String^ table, DataGridView^ grid)
{
	SqlQuery^ sqlQuery = gcnew SqlQuery();
	SqlManager^ manager = gcnew SqlManager();
	sqlQuery->newQuery(false, query);
	grid->DataSource = manager->getRows(sqlQuery, table);
	grid->DataMember = table;
}
/*
void ProjetPOOServices::SqlHandler::ajouterUnePersonne(String^ nom, String^ prenom)
{
	this->query->setNom(nom);
	this->query->setPrenom(prenom);
	String^ sql = this->query->addInsert();

	this->manager->actionRows(sql);
}

void ProjetPOOServices::SqlHandler::supprimerUnePersonne(int id)
{
	this->query->setId(id);
	String^ sql = this->query->addDelete();

	this->manager->actionRows(sql);
}

void ProjetPOOServices::SqlHandler::mettreAJourUnePersonne(int id, String^ nom, String^ prenom)
{
	this->query->setId(id);
	this->query->setNom(nom);
	this->query->setPrenom(prenom);
	String^ sql = this->query->addUpdate();

	this->manager->actionRows(sql);
}
*/