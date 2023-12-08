#pragma once
#include "SqlQuery.h"
#include "PersonnelMap.h"

using namespace ProjetPOOMappage;

namespace ProjetPOOServices
{
	ref class SqlQueries
	{
	public:
		static String^ listePersonnel();
		static String^ AjouterPersonnel(PersonnelMap^);
	};
}

using namespace ProjetPOOServices;