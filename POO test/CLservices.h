#pragma once

#include "CLmapTB.h"
#include "CLcad.h"

namespace NS_Comp_Svc
{
	ref class CLservices
	{
	private:
		NS_Comp_Data::CLcad^ oCad;
		NS_Comp_Mappage::CLmapTB^ oMappTB;
	public:
		CLservices(void);
		System::Data::DataSet^ selectionnerTousLesArticles(System::String^);
		void ajouterUnArticle(System::String^ référence, System::String^ prix_produit_ht, int taux_tva, System::String^ nature, int quantite_stock, int seuil_reaprovisionnement, System::String^ désignation, System::String^ couleur);
		void supprimerUnArticle(System::String^ référence);
		void modifierUnArticle(System::String^ référence, System::String^ prix_produit_ht, int taux_tva, System::String^ nature, int quantite_stock, int seuil_reaprovisionnement, System::String^ désignation, System::String^ couleur);
	};
}