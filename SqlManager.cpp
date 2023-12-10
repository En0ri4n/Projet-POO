#include "SqlManager.h"
#include "Projet.h"
#include <iostream>

SqlManager::SqlManager()
{
	this->connectionCmd = "Data Source=localhost;Initial Catalog=Projet;Integrated Security=True;User ID=Utilisateur_projet;Password=EVAL2023";

	this->connection = gcnew Data::SqlClient::SqlConnection(this->connectionCmd);
	this->command = gcnew Data::SqlClient::SqlCommand(L"EMPTY", this->connection);
	this->dataAdapter = gcnew Data::SqlClient::SqlDataAdapter();
	this->dataSet = gcnew Data::DataSet();

	this->command->CommandType = Data::CommandType::Text;
}

System::Data::DataSet^ SqlManager::getRows(SqlQuery^ query, String^ table)
{
	this->dataSet->Clear();
	this->command->CommandText = query->toQuery();
	this->dataAdapter->SelectCommand = this->command;
	this->dataAdapter->Fill(this->dataSet, table);
	ProjetPOO::Projet::instance->addQueryHistorique(query->toQuery());

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
	}

	this->connection->Close();
}