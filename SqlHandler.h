#pragma once
#include "SqlQuery.h"
#include "SqlManager.h"

namespace ProjetPOOServices
{
	ref class SqlHandler
	{
	private:
		ProjetPOO::SqlManager^ manager;
		ProjetPOOMappage::SqlQuery^ query;
	public:
		SqlHandler(void);
		Data::DataSet^ selectionnerToutesLesPersonnes(String^);
		void ajouterUnePersonne(String^, String^);
		void supprimerUnePersonne(int);
		void mettreAJourUnePersonne(int, String^, String^);
	};
}
