#include "CLmapTB.h"

System::String^ NS_Comp_Mappage::CLmapTB::Select(void)
{
	return "SELECT [r�f�rence], [prix_produit_ht], [taux_tva], [nature], [quantite_stock], [seuil_reaprovisionnement], [d�signation], [couleur] FROM [ProjetPOO].[dbo].[Articles]";
}
System::String^ NS_Comp_Mappage::CLmapTB::Insert(void)
{
	return "INSERT INTO [ProjetPOO].[dbo].[Articles] (r�f�rence, prix_produit_ht, taux_tva, nature, quantite_stock, seuil_reaprovisionnement, d�signation, couleur) VALUES('" + this->r�f�rence + "','" + this->prix_produit_ht + "','" + this->taux_tva + "','" + this->nature + "','" + this->quantite_stock + "','" + this->seuil_reaprovisionnement + "','" + this->d�signation + "','" + this->couleur + "');";

}
System::String^ NS_Comp_Mappage::CLmapTB::Delete(void)
{
	return "DELETE FROM [ProjetPOO].[dbo].[Articles] WHERE r�f�rence='" + this->r�f�rence +"';";

}
System::String^ NS_Comp_Mappage::CLmapTB::Update(void)
{
	return "UPDATE [ProjetPOO].[dbo].[Articles] SET r�f�rence='" + this->r�f�rence + "', prix_produit_ht='" + this->prix_produit_ht + "', taux_tva='" + this->taux_tva + "', nature='" + this->nature + "', quantite_stock='" + this->quantite_stock + "', seuil_reaprovisionnement='" + this->seuil_reaprovisionnement + "', d�signation='" + this->d�signation + "', couleur='" + this->couleur + "' WHERE r�f�rence='" + this->r�f�rence + "';";
}

void NS_Comp_Mappage::CLmapTB::setR�f�rence(System::String^ r�f�rence)
{
	this->r�f�rence = r�f�rence;
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


void NS_Comp_Mappage::CLmapTB::setD�signation(System::String^ d�signation)
{
	this->d�signation = d�signation;
}

void NS_Comp_Mappage::CLmapTB::setCouleur(System::String^ couleur)
{
	this->couleur = couleur;
}





System::String^ NS_Comp_Mappage::CLmapTB::getR�f�rence(void) { return this->r�f�rence; }
System::String^ NS_Comp_Mappage::CLmapTB::getPrixProduitHT(void) { return this->prix_produit_ht; }
int NS_Comp_Mappage::CLmapTB::getTauxTva(int){ return this->taux_tva;}
System::String^ NS_Comp_Mappage::CLmapTB::getNature(void){ return this->nature; }
int NS_Comp_Mappage::CLmapTB::getQuantiteStock(int){ return this->quantite_stock; }
int NS_Comp_Mappage::CLmapTB::getSeuilReaprovisionnement(int){ return this->seuil_reaprovisionnement; }
System::String^ NS_Comp_Mappage::CLmapTB::getD�signation(void) { return this->d�signation; }
System::String^ NS_Comp_Mappage::CLmapTB::getCouleur(void) { return this->couleur; }
