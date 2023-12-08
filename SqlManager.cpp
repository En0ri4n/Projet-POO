#include "SqlManager.h"
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

	return this->dataSet;
}

System::Data::DataSet^ SqlManager::getRows(SqlQuery^ query, Table^ table)
{
	return getRows(query, table->getName());
}

void SqlManager::actionRows(SqlQuery^ query)
{
	this->command->CommandText = query->toQuery();
	this->dataAdapter->SelectCommand = this->command;
	this->connection->Open();
	lastCount = this->command->ExecuteNonQuery();
	this->connection->Close();
}