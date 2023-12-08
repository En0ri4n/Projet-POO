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

		void AfficherCommandes();
		void AjouterCommande(CommandeMap^);
		void ModifierCommande(CommandeMap^);
		void SupprimerCommande(CommandeMap^);

		void AfficherArticles();
		void AjouterArticle(ArticleMap^);
		void ModifierArticle(ArticleMap^);
		void SupprimerArticle(ArticleMap^);

		void AfficherClients();
		void AjouterClient(ClientMap^);
		void ModifierClient(ClientMap^);
		void SupprimerClient(ClientMap^);

		void remplirArticlesCommande(CommandeMap^);

		void afficherPanierMoyen();
		void afficherChiffreAffaire(DateTime^);
		void afficherProduitSousSeuilReapprovisionnement();
		void afficherMontantTotalClient(ClientMap^);
		void afficherProduitPlusVendu();
		void afficherProduitMoinsVendu();
		void afficherValeurCommercialStock();
		void afficherValeurAchatStock();



		static void fillGrid(Table^, DataGridView^);
		static void fillGrid(String^, String^, DataGridView^);
	};
}
