#include "SqlManager.h"
#include "Projet.h"
#include <iostream>

SqlManager::SqlManager(String^ user, String^ passw)
{
	username = user;
	password = passw;

	this->connectionCmd = String::Format("Data Source=localhost;Initial Catalog={2};User ID={0};Password={1}", username, password, DATABASE_NAME);

	this->connection = gcnew Data::SqlClient::SqlConnection(this->connectionCmd);
	this->command = gcnew Data::SqlClient::SqlCommand("EMPTY", this->connection);
	this->dataAdapter = gcnew Data::SqlClient::SqlDataAdapter();
	this->dataSet = gcnew Data::DataSet();

	this->command->CommandType = Data::CommandType::Text;
}

bool ProjetPOOServices::SqlManager::isConnected()
{
	try
	{
		this->connection->Open();
		this->connection->Close();
		return true;
	}
	catch(System::Exception^ e)
	{
		return false;
	}
}

System::Data::DataSet^ SqlManager::getRows(SqlQuery^ query, String^ table)
{
	try
	{
		this->dataSet->Clear();
		this->command->CommandText = query->toQuery();
		this->dataAdapter->SelectCommand = this->command;
		this->dataAdapter->Fill(this->dataSet, table);
		ProjetPOO::Projet::instance->addQueryHistorique(query->toQuery());
	}
	catch(System::Exception^ e)
	{
		ProjetPOO::Projet::instance->addQueryHistorique(e->Message);
	}

	return this->dataSet;
}

System::Data::DataSet^ SqlManager::getRows(SqlQuery^ query, Table^ table)
{
	return getRows(query, table->getName());
}

void SqlManager::actionRows(SqlQuery^ query)
{
	this->connection->Open();

	lastCount = 0;

	for each(String ^ strQuery in query->getQueries())
	{
		ProjetPOO::Projet::instance->addQueryHistorique(strQuery);
		this->command->CommandText = strQuery;
		this->dataAdapter->SelectCommand = this->command;
		try
		{
			this->lastCount += this->command->ExecuteNonQuery();
		}
		catch(System::Exception^ e)
		{
			ProjetPOO::Projet::instance->addQueryHistorique(e->Message);
		}

		ProjetPOO::Projet::instance->addQueryHistorique(query->toQuery());
	}

	this->connection->Close();
}