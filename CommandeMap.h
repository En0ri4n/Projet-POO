#pragma once

using namespace System;

namespace ProjetPOOMappage
{
	ref class CommandeMap
	{
	private:
		String^ idCommande;
		DateTime^ dateLivraison;
		DateTime^ dateEmission;
		String^ moyenPaiement;
		DateTime^ datePaiement;
		int idClient;
		Collections::ArrayList^ listeArticles;

		Collections::ArrayList^ derniereListeArticles;
	public:
		CommandeMap(String^ idCommande, DateTime^ dateLivraison, DateTime^ dateEmission, String^ moyenPaiement, DateTime^ datePaiement, int idClient, Collections::ArrayList^ listeArticles) : idCommande(idCommande), dateLivraison(dateLivraison), dateEmission(dateEmission), moyenPaiement(moyenPaiement), datePaiement(datePaiement), idClient(idClient), listeArticles(listeArticles) {}
		CommandeMap() : CommandeMap("", gcnew DateTime(), gcnew DateTime(), "", gcnew DateTime(), -1, gcnew Collections::ArrayList()) {}

		void setIdCommande(String^);
		String^ getIdCommande();
		void setDateLivraison(DateTime^);
		DateTime^ getDateLivraison();
		void setDateEmission(DateTime^);
		DateTime^ getDateEmission();
		void setMoyenPaiement(String^);
		String^ getMoyenPaiement();
		void setDatePaiement(DateTime^);
		DateTime^ getDatePaiement();
		void setIdClient(int);
		int getIdClient();
		void setListeArticles(Collections::ArrayList^);
		Collections::ArrayList^ getListeArticles();
		void setDerniereListeArticles(Collections::ArrayList^);
		Collections::ArrayList^ getDerniereListeArticles();

		static CommandeMap^ from(String^);
	};
}