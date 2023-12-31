#include "SqlQuery.h"
#include "Projet.h"

SqlQuery::SqlQuery()
{
	this->isTransaction = false;
	this->queries = gcnew System::Collections::ArrayList();
}

SqlQuery::~SqlQuery()
{
	delete queries;
}

void SqlQuery::newQuery(bool isTransaction, String^ query)
{
	this->isTransaction = isTransaction;
	this->queries->Clear();
	addQuery(query);
}

void SqlQuery::addQuery(String^ query)
{
	this->queries->Add(query);
}

void SqlQuery::useTransaction()
{
	this->isTransaction = true;
}

System::Collections::ArrayList^ ProjetPOOMappage::SqlQuery::getQueries()
{
	return queries;
}

String^ SqlQuery::toQuery()
{
	String^ query = String::Format("USE {0};", SqlManager::DATABASE_NAME);

	if(isTransaction)
		query += "BEGIN TRANSACTION;";

	for each(String^ strQuery in queries)
	{
		query += String::Format("{0};", strQuery);
	}

	if(isTransaction)
		query += "COMMIT;";

	return query;
}
