#pragma once
#include "SqlQuery.h"
#include "SqlManager.h"

using namespace System::Windows::Forms;

namespace ProjetPOOServices
{
	ref class SqlHandler
	{
	private:
		SqlManager^ manager;
		SqlQuery^ query;
		DataGridView^ dataGridView;
	private:
		void fill(String^);
	public:
		SqlHandler(DataGridView^);
		void fillGrid(Table^);
		void fillGrid(String^, String^);
		void searchByColumn(Table^, String^, String^, bool);
		int getLastCount() { return manager->getLastCount(); }
	};
}

using namespace ProjetPOOServices;
