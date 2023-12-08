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
		static String^ AjouterCommandeArticle(CommandeMap^);
		static String^ ModifierCommandeArticle(CommandeMap^);
		static String^ SupprimerCommandeArticle(CommandeMap^);

	};
}

using namespace ProjetPOOServices;