#pragma once
#include "SqlQuery.h"
#include "SqlManager.h"
#include "PersonnelMap.h"
#include "CommandeMap.h"
#include "SqlQueries.h"

using namespace System;
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
		void fill(Table^);
	public:
		SqlHandler(DataGridView^);
		void fillGrid(Table^);
		void fillGrid(String^, String^);
		void action(String^);
		void action(Table^);
		int getLastCount() { return manager->getLastCount(); }

		void AfficherPersonnel();
		void AjouterPersonnel(PersonnelMap^);
		void ModifierPersonnel(PersonnelMap^);
		void SupprimerPersonnel(PersonnelMap^);

		void AfficherCommande();
		void AjouterCommande(CommandeMap^);
		void ModifierCommande(CommandeMap^);
		void SupprimerCommande(CommandeMap^);

		void AfficherArticle();
		void AjouterArticle(ArticleMap^);
		void ModifierArticle(ArticleMap^);
		void SupprimerArticle(ArticleMap^);


		static void fillGrid(Table^, DataGridView^);
		static void fillGrid(String^, String^, DataGridView^);
	};
}
