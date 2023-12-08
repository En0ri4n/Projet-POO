#include "CLservices.h"

NS_Comp_Svc::CLservices::CLservices(void)
{
	this->oCad = gcnew NS_Comp_Data::CLcad();
	this->oMappTB = gcnew NS_Comp_Mappage::CLmapTB();
}


System::Data::DataSet^ NS_Comp_Svc::CLservices::selectionnerTousLesArticles(System::String^ dataTableName)
{
	System::String^ sql;

	sql = this->oMappTB->Select();
	return this->oCad->getRows(sql, dataTableName);
}


void NS_Comp_Svc::CLservices::ajouterUnArticle(System::String^  référence, System::String^ prix_produit_ht, int taux_tva, System::String^ nature, int quantite_stock, int seuil_reaprovisionnement, System::String^ désignation, System::String^ couleur)
{
    System::String^ sql;


    this->oMappTB->setRéférence(référence);
    this->oMappTB->setPrixProduitHT(prix_produit_ht);
    this->oMappTB->setTauxTva(taux_tva);
    this->oMappTB->setNature(nature);
    this->oMappTB->setQuantiteStock(quantite_stock);
    this->oMappTB->setSeuilReaprovisionnement(seuil_reaprovisionnement);
    this->oMappTB->setDésignation(désignation);
    this->oMappTB->setCouleur(couleur);

    sql = this->oMappTB->Insert();

    this->oCad->actionRows(sql);
}


void NS_Comp_Svc::CLservices::supprimerUnArticle(System::String^ référence)
{
    System::String^ sql;
    this->oMappTB->setRéférence(référence);
    sql = this->oMappTB->Delete();
    this->oCad->actionRows(sql);
}

void NS_Comp_Svc::CLservices::modifierUnArticle(System::String^ référence, System::String^ prix_produit_ht, int taux_tva, System::String^ nature, int quantite_stock, int seuil_reaprovisionnement, System::String^ désignation, System::String^ couleur)
{
    System::String^ sql;

    this->oMappTB->setRéférence(référence);
    this->oMappTB->setPrixProduitHT(prix_produit_ht);
    this->oMappTB->setTauxTva(taux_tva);
    this->oMappTB->setNature(nature);
    this->oMappTB->setQuantiteStock(quantite_stock);
    this->oMappTB->setSeuilReaprovisionnement(seuil_reaprovisionnement);
    this->oMappTB->setDésignation(désignation);
    this->oMappTB->setCouleur(couleur);

    sql = this->oMappTB->Update();

    this->oCad->actionRows(sql);
}
