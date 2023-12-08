#include "SqlHandler.h"
#include "SqlQueries.h"

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

void ProjetPOOServices::SqlHandler::searchByColumn(Table^ table, String^ columnName, String^ value, bool isNumeric)
{
	if(isNumeric)
		this->query->newQuery(false, String::Format("SELECT * FROM {0} WHERE {1}={2}", table->getName(), columnName, value));
	else
		this->query->newQuery(false, String::Format("SELECT * FROM {0} WHERE {1} LIKE '%{2}%'", table->getName(), columnName, value));
	
	fill(table);
}

void ProjetPOOServices::SqlHandler::SelectPersonnel()
{
	this->query->newQuery(false, SqlQueries::listePersonnel());
	fill("Personnel");
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