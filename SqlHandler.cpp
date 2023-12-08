#include "SqlHandler.h"

using namespace ProjetPOOServices;

ProjetPOOServices::SqlHandler::SqlHandler(DataGridView^ dgv)
{
	this->manager = gcnew SqlManager();
	this->query = gcnew ProjetPOOMappage::SqlQuery();
	this->dataGridView = dgv;
}

void ProjetPOOServices::SqlHandler::fill(String^ table)
{
	dataGridView->DataSource = this->manager->getRows(this->query, table);
	dataGridView->DataMember = table;
}

void ProjetPOOServices::SqlHandler::fill(Table^ table)
{
	fill(table->getName());
}

/*
* Remplis la DataGridView avec tous les éléments de la table donnée
*/
void ProjetPOOServices::SqlHandler::fillGrid(Table^ table)
{
	this->query->newQuery(false, "SELECT * FROM " + table->getName());
	fill(table);
}

/*
* Remplis la DataGridView avec le résultat de la requête donnée
*/
void ProjetPOOServices::SqlHandler::fillGrid(String^ query, String^ tableName)
{
	this->query->newQuery(false, query);
	fill(tableName);
}

void ProjetPOOServices::SqlHandler::action(String^)
{
	this->manager->actionRows(this->query);
}

void ProjetPOOServices::SqlHandler::action(Table^ table)
{
	action(table->getName());
}

void ProjetPOOServices::SqlHandler::AfficherPersonnel()
{
	this->query->newQuery(false, SqlQueries::listePersonnel());
	fill(Table::PERSONNELS);
}

void ProjetPOOServices::SqlHandler::AjouterPersonnel(PersonnelMap^ personnel)
{
	this->query->newQuery(false, SqlQueries::AjouterPersonnel(personnel));
	action(Table::PERSONNELS);
}

void ProjetPOOServices::SqlHandler::ModifierPersonnel(PersonnelMap^ personnel)
{
	this->query->newQuery(false, SqlQueries::ModifierPersonnel(personnel));
	action(Table::PERSONNELS);
}

void ProjetPOOServices::SqlHandler::SupprimerPersonnel(PersonnelMap^ personnel)
{
	this->query->newQuery(false, SqlQueries::SupprimerPersonnel(personnel));
	action(Table::PERSONNELS);
}

void ProjetPOOServices::SqlHandler::AfficherCommande()
{
	this->query->newQuery(false, SqlQueries::listeCommande());
	fill(Table::COMMANDES);
}

void ProjetPOOServices::SqlHandler::AjouterCommande(CommandeMap^ commande)
{
	this->query->newQuery(false, SqlQueries::AjouterCommande(commande));
	action(Table::COMMANDES);
}

void ProjetPOOServices::SqlHandler::ModifierCommande(CommandeMap^ commande)
{
	this->query->newQuery(false, SqlQueries::ModifierCommande(commande));
	action(Table::COMMANDES);
}

void ProjetPOOServices::SqlHandler::SupprimerCommande(CommandeMap^ commande)
{
	this->query->newQuery(false, SqlQueries::SupprimerCommande(commande));
	action(Table::COMMANDES);
}

void ProjetPOOServices::SqlHandler::AfficherArticle()
{
	this->query->newQuery(false, SqlQueries::listeArticles());
	fill(Table::ARTICLES);
}

void ProjetPOOServices::SqlHandler::AjouterArticle(ArticleMap^ article)
{
	this->query->newQuery(false, SqlQueries::AjouterArticle(article));
	action(Table::ARTICLES);
}

void ProjetPOOServices::SqlHandler::ModifierArticle(ArticleMap^ article)
{
	this->query->newQuery(false, SqlQueries::ModifierArticle(article));
	action(Table::ARTICLES);
}

void ProjetPOOServices::SqlHandler::SupprimerArticle(ArticleMap^ article)
{
	this->query->newQuery(false, SqlQueries::SupprimerArticle(article));
	action(Table::ARTICLES);
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