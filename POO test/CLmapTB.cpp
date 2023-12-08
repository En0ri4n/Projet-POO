#include "CLmapTB.h"

System::String^ NS_Comp_Mappage::CLmapTB::Select(void)
{
	return "SELECT [référence], [prix_produit_ht], [taux_tva], [nature], [quantite_stock], [seuil_reaprovisionnement], [désignation], [couleur] FROM [ProjetPOO].[dbo].[Articles]";
}
System::String^ NS_Comp_Mappage::CLmapTB::Insert(void)
{
	return "INSERT INTO [ProjetPOO].[dbo].[Articles] (référence, prix_produit_ht, taux_tva, nature, quantite_stock, seuil_reaprovisionnement, désignation, couleur) VALUES('" + this->référence + "','" + this->prix_produit_ht + "','" + this->taux_tva + "','" + this->nature + "','" + this->quantite_stock + "','" + this->seuil_reaprovisionnement + "','" + this->désignation + "','" + this->couleur + "');";

}
System::String^ NS_Comp_Mappage::CLmapTB::Delete(void)
{
	return "DELETE FROM [ProjetPOO].[dbo].[Articles] WHERE référence='" + this->référence +"';";

}
System::String^ NS_Comp_Mappage::CLmapTB::Update(void)
{
	return "UPDATE [ProjetPOO].[dbo].[Articles] SET référence='" + this->référence + "', prix_produit_ht='" + this->prix_produit_ht + "', taux_tva='" + this->taux_tva + "', nature='" + this->nature + "', quantite_stock='" + this->quantite_stock + "', seuil_reaprovisionnement='" + this->seuil_reaprovisionnement + "', désignation='" + this->désignation + "', couleur='" + this->couleur + "' WHERE référence='" + this->référence + "';";
}

void NS_Comp_Mappage::CLmapTB::setRéférence(System::String^ référence)
{
	this->référence = référence;
}

void NS_Comp_Mappage::CLmapTB::setPrixProduitHT(System::String^ PrixProduitHT)
{
	this->prix_produit_ht = PrixProduitHT;
}

void NS_Comp_Mappage::CLmapTB::setTauxTva(int TauxTva)
{
	this->taux_tva = TauxTva;
}

void NS_Comp_Mappage::CLmapTB::setNature(System::String^ nature)
{
	this->nature = nature;
}

void NS_Comp_Mappage::CLmapTB::setQuantiteStock(int QuantiteStock)
{
	this->quantite_stock = QuantiteStock;
}

void NS_Comp_Mappage::CLmapTB::setSeuilReaprovisionnement(int SeuilReaprovisionnement)
{
	this->seuil_reaprovisionnement = SeuilReaprovisionnement;
}


void NS_Comp_Mappage::CLmapTB::setDésignation(System::String^ désignation)
{
	this->désignation = désignation;
}

void NS_Comp_Mappage::CLmapTB::setCouleur(System::String^ couleur)
{
	this->couleur = couleur;
}





System::String^ NS_Comp_Mappage::CLmapTB::getRéférence(void) { return this->référence; }
System::String^ NS_Comp_Mappage::CLmapTB::getPrixProduitHT(void) { return this->prix_produit_ht; }
int NS_Comp_Mappage::CLmapTB::getTauxTva(int){ return this->taux_tva;}
System::String^ NS_Comp_Mappage::CLmapTB::getNature(void){ return this->nature; }
int NS_Comp_Mappage::CLmapTB::getQuantiteStock(int){ return this->quantite_stock; }
int NS_Comp_Mappage::CLmapTB::getSeuilReaprovisionnement(int){ return this->seuil_reaprovisionnement; }
System::String^ NS_Comp_Mappage::CLmapTB::getDésignation(void) { return this->désignation; }
System::String^ NS_Comp_Mappage::CLmapTB::getCouleur(void) { return this->couleur; }
