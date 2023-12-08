#pragma once

namespace NS_Comp_Mappage
{
	ref class CLmapTB
	{
	private:
		System::String^ sSql;
		System::String^ référence;
		System::String^ prix_produit_ht;
		int taux_tva;
		System::String^ nature;
		int quantite_stock;
		int seuil_reaprovisionnement;
		System::String^ désignation;
		System::String^ couleur;
	public:
		System::String^ Select(void);
		System::String^ Insert(void);
		System::String^ Delete(void);
		System::String^ Update(void);
		void setRéférence(System::String^);
		void setPrixProduitHT(System::String^);
		void setTauxTva(int);
		void setNature(System::String^);
		void setQuantiteStock(int);
		void setSeuilReaprovisionnement(int);
		void setDésignation(System::String^);
		void setCouleur(System::String^);


		System::String^ getRéférence(void);
		System::String^ getPrixProduitHT(void);
		int getTauxTva(int);
		System::String^ getNature(void);
		int getQuantiteStock(int);
		int getSeuilReaprovisionnement(int);
		System::String^ getDésignation(void);
		System::String^ getCouleur(void);
	};
}