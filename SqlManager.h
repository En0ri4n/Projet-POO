#pragma once

using namespace System;

namespace ProjetPOO
{
	ref class SqlManager
	{
	private:
		String^ sqlCmd;
		String^ connectionCmd;
		Data::SqlClient::SqlConnection^ connection;
		Data::SqlClient::SqlCommand^ command;
		Data::SqlClient::SqlDataAdapter^ dataAdapter;
		Data::DataSet^ dataSet;
	public:
		SqlManager(void);
		Data::DataSet^ getRows(String^, String^);
		void actionRows(String^);
		bool exists(int);
	};
}