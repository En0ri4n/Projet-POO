#include "SqlManager.h"
#include <iostream>

ProjetPOO::SqlManager::SqlManager(void)
{
	this->connectionCmd = "Data Source=ENO-LAPTOP;Initial Catalog=bdd;Integrated Security=True;User ID=sa;Password=a";

	this->sqlCmd = "EMPTY";

	this->connection = gcnew Data::SqlClient::SqlConnection(this->connectionCmd);
	this->command = gcnew Data::SqlClient::SqlCommand(this->sqlCmd, this->connection);
	this->dataAdapter = gcnew Data::SqlClient::SqlDataAdapter();
	this->dataSet = gcnew Data::DataSet();

	this->command->CommandType = Data::CommandType::Text;
}

System::Data::DataSet^ ProjetPOO::SqlManager::getRows(String^ sSql, String^ sDataTableName)
{
	this->dataSet->Clear();
	this->sqlCmd = sSql;
	this->command->CommandText = this->sqlCmd;
	this->dataAdapter->SelectCommand = this->command;
	this->dataAdapter->Fill(this->dataSet, sDataTableName);

	return this->dataSet;
}

void ProjetPOO::SqlManager::actionRows(String^ sqlQuery)
{
	this->sqlCmd = sqlQuery;
	this->command->CommandText = this->sqlCmd;
	this->dataAdapter->SelectCommand = this->command;
	this->connection->Open();
	this->command->ExecuteNonQuery();
	this->connection->Close();
}

bool ProjetPOO::SqlManager::exists(int id)
{
	this->sqlCmd = String::Format("SELECT * FROM rsl WHERE id={0}", id);
	this->command->CommandText = this->sqlCmd;
	this->dataAdapter->SelectCommand = this->command;
	this->connection->Open();
	int count = this->command->ExecuteNonQuery();
	this->connection->Close();
	return count > 0;
}
