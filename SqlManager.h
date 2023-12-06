#pragma once
#include "SqlQuery.h"

using namespace System;

namespace ProjetPOO
{
	ref class SqlManager
	{
	private:
		int lastCount;
		String^ connectionCmd;
		Data::SqlClient::SqlConnection^ connection;
		Data::SqlClient::SqlCommand^ command;
		Data::SqlClient::SqlDataAdapter^ dataAdapter;
		Data::DataSet^ dataSet;
	public:
		SqlManager();
		Data::DataSet^ getRows(SqlQuery^, Table^);
		Data::DataSet^ getRows(SqlQuery^, String^);
		int actionRows(SqlQuery^);
		int getLastCount() { return lastCount; }
	};
}

using namespace ProjetPOO;