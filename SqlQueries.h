#pragma once
#include "SqlQuery.h"
#include "PersonnelMap.h"
#include "CommandeMap.h"
#include "ClientMap.h"
#include "ArticleMap.h"

using namespace ProjetPOOMappage;

namespace ProjetPOOServices
{
	ref class SqlQueries
	{
	public:
		static String^ listePersonnel();
		static String^ AjouterPersonnel(PersonnelMap^);
		static String^ ModifierPersonnel(PersonnelMap^);
		static String^ SupprimerPersonnel(PersonnelMap^);

		static String^ listeCommande();
		static String^ AjouterCommande(CommandeMap^);
		static String^ ModifierCommande(CommandeMap^);
		static String^ SupprimerCommande(CommandeMap^);

		static String^ listeArticles();
		static String^ AjouterArticle(ArticleMap^);
		static String^ ModifierArticle(ArticleMap^);
		static String^ SupprimerArticle(ArticleMap^);

		static String^ listeClients();
		static String^ AjouterClient(ClientMap^);
		static String^ ModifierClient(ClientMap^);
		static String^ SupprimerClient(ClientMap^);

		static String^ listeCommandeArticles(CommandeMap^);
		static String^ AjouterCommandeArticle(SqlQuery^, CommandeMap^);
		static String^ ModifierCommandeArticle(SqlQuery^, CommandeMap^);
		static String^ SupprimerCommandeArticle(SqlQuery^, CommandeMap^);

		static String^ getPanierMoyen();
		static String^ getChiffreAffaire(DateTime^);
		static String^ getProduitSousSeuilReapprovisionnement();
		static String^ getMontantTotalClient(ClientMap^);
		static String^ getProduitPlusVendu();
		static String^ getProduitMoinsVendu();
		static String^ getValeurCommercialStock();
		static String^ getValeurAchatStock();
	};
}

using namespace ProjetPOOServices;