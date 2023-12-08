#pragma once

using namespace System;

namespace ProjetPOOMappage
{
	ref class ArticleMap
	{
	private:
		String^ idArticle;
		String^ nom;
		double prix;
		String^ nature;
		String^ couleur;
		int seuilReapprovisionnement;
		int quantite;
		int taxe;
		int remise;
	public:
		ArticleMap(String^ id, String^ nom, double prix, String^ nature, String^ couleur, int seuil, int quantite, int taxe) : idArticle(id), nom(nom), prix(prix), nature(nature), couleur(couleur), seuilReapprovisionnement(seuil), quantite(quantite), taxe(taxe), remise(0) {}
		ArticleMap() : ArticleMap("", "", 0, "", "", 0, 0, 0) {}

		void setIdArticle(String^);
		String^ getIdArticle();
		void setNom(String^);
		String^ getNom();
		void setPrix(double);
		double getPrix();
		void setNature(String^);
		String^ getNature();
		void setCouleur(String^);
		String^ getCouleur();
		void setSeuilReapprovisionnement(int);
		int getSeuilReapprovisionnement();
		void setQuantite(int);
		int getQuantite();
		void setTaxe(int);
		int getTaxe();
		void setRemise(int);
		int getRemise();

		static ArticleMap^ from(String^, int, int);
		static bool isInList(String^, System::Collections::ArrayList^);
		static ArticleMap^ byId(String^, System::Collections::ArrayList^);
	};
}

using namespace ProjetPOOMappage;