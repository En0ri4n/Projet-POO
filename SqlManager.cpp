#include "SqlManager.h"
#include <iostream>

SqlManager::SqlManager()
{
	this->connectionCmd = "Data Source=ENO-LAPTOP;Initial Catalog=bdd;Integrated Security=True;User ID=sa;Password=a";

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
	lastCount = this->dataAdapter->Fill(this->dataSet, table);

	return this->dataSet;
}

System::Data::DataSet^ SqlManager::getRows(SqlQuery^ query, Table^ table)
{
	return getRows(query, table->getName());
}

int SqlManager::actionRows(SqlQuery^ query)
{
	this->command->CommandText = query->toQuery();
	this->dataAdapter->SelectCommand = this->command;
	this->connection->Open();
	int action = this->command->ExecuteNonQuery();
	this->connection->Close();
	return action;
}