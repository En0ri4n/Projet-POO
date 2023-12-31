#pragma once
#include "SqlQuery.h"

using namespace System;

namespace ProjetPOOServices
{
	ref class SqlManager
	{
	public:
		static String^ username;
		static String^ password;
	private:
		bool connected;
		int lastCount;
		String^ connectionCmd;
		Data::SqlClient::SqlConnection^ connection;
		Data::SqlClient::SqlCommand^ command;
		Data::SqlClient::SqlDataAdapter^ dataAdapter;
		Data::DataSet^ dataSet;
	public:
		static String^ DATABASE_NAME = "Projet";
	public:
		SqlManager(String^, String^);
		bool isConnected();
		Data::DataSet^ getRows(SqlQuery^, Table^);
		Data::DataSet^ getRows(SqlQuery^, String^);
		void actionRows(SqlQuery^);
		int getLastCount() { return lastCount; }
	};
}

using namespace ProjetPOOServices;