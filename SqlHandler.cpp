#include "SqlHandler.h"
#include "Projet.h"

using namespace ProjetPOOServices;

ProjetPOOServices::SqlHandler::SqlHandler(DataGridView^ dgv)
{
	this->manager = gcnew SqlManager();
	this->query = gcnew ProjetPOOMappage::SqlQuery();
	this->dataGridView = dgv;
}

void ProjetPOOServices::SqlHandler::fill(String^ table)
{
	dataGridView->DataSource = this->manager->getRows(this->query, table);
	dataGridView->DataMember = table;
}

void ProjetPOOServices::SqlHandler::fill(Table^ table)
{
	fill(table->getName());
}

/*
* Remplis la DataGridView avec tous les éléments de la table donnée
*/
void ProjetPOOServices::SqlHandler::fillGrid(Table^ table)
{
	this->query->newQuery(false, "SELECT * FROM " + table->getName());
	fill(table);
}

/*
* Remplis la DataGridView avec le résultat de la requête donnée
*/
void ProjetPOOServices::SqlHandler::fillGrid(String^ query, String^ tableName)
{
	this->query->newQuery(false, query);
	fill(tableName);
}

void ProjetPOOServices::SqlHandler::action(String^)
{
	this->manager->actionRows(this->query);
}

void ProjetPOOServices::SqlHandler::action(Table^ table)
{
	action(table->getName());
}

void ProjetPOOServices::SqlHandler::AfficherPersonnel()
{
	this->query->newQuery(false, SqlQueries::listePersonnel());
	fill(Table::PERSONNELS);
}

void ProjetPOOServices::SqlHandler::AjouterPersonnel(PersonnelMap^ personnel)
{
	this->query->newQuery(false, SqlQueries::AjouterPersonnel(personnel));
	action(Table::PERSONNELS);
}

void ProjetPOOServices::SqlHandler::ModifierPersonnel(PersonnelMap^ personnel)
{
	this->query->newQuery(false, SqlQueries::ModifierPersonnel(personnel));
	action(Table::PERSONNELS);
}

void ProjetPOOServices::SqlHandler::SupprimerPersonnel(PersonnelMap^ personnel)
{
	this->query->newQuery(false, SqlQueries::SupprimerPersonnel(personnel));
	action(Table::PERSONNELS);
}

void ProjetPOOServices::SqlHandler::AfficherCommandes()
{
	this->query->newQuery(false, SqlQueries::listeCommande());
	fill(Table::COMMANDES);
}

void ProjetPOOServices::SqlHandler::AjouterCommande(CommandeMap^ commande)
{
	this->query->newQuery(false, SqlQueries::AjouterCommande(commande));
	SqlQueries::AjouterCommandeArticle(query, commande);
	action(Table::COMMANDES);
}

void ProjetPOOServices::SqlHandler::ModifierCommande(CommandeMap^ commande)
{
	this->query->newQuery(false, SqlQueries::ModifierCommande(commande));
	SqlQueries::ModifierCommandeArticle(query, commande);
	action(Table::COMMANDES);
}

void ProjetPOOServices::SqlHandler::SupprimerCommande(CommandeMap^ commande)
{
	this->query->newQuery(false, SqlQueries::SupprimerCommande(commande));
	SqlQueries::SupprimerCommandeArticle(query, commande);
	action(Table::COMMANDES);
}

void ProjetPOOServices::SqlHandler::AfficherArticles()
{
	this->query->newQuery(false, SqlQueries::listeArticles());
	fill(Table::ARTICLES);
}

void ProjetPOOServices::SqlHandler::AjouterArticle(ArticleMap^ article)
{
	this->query->newQuery(false, SqlQueries::AjouterArticle(article));
	action(Table::ARTICLES);
}

void ProjetPOOServices::SqlHandler::ModifierArticle(ArticleMap^ article)
{
	this->query->newQuery(false, SqlQueries::ModifierArticle(article));
	action(Table::ARTICLES);
}

void ProjetPOOServices::SqlHandler::SupprimerArticle(ArticleMap^ article)
{
	this->query->newQuery(false, SqlQueries::SupprimerArticle(article));
	action(Table::ARTICLES);
}

void ProjetPOOServices::SqlHandler::AfficherClients()
{
	this->query->newQuery(false, SqlQueries::listeClients());
	fill(Table::CLIENTS);
}

void ProjetPOOServices::SqlHandler::AjouterClient(ClientMap^ client)
{
	this->query->newQuery(false, SqlQueries::AjouterClient(client));
	action(Table::CLIENTS);
}

void ProjetPOOServices::SqlHandler::ModifierClient(ClientMap^ client)
{
	this->query->newQuery(false, SqlQueries::ModifierClient(client));
	action(Table::CLIENTS);
}

void ProjetPOOServices::SqlHandler::SupprimerClient(ClientMap^ client)
{
	this->query->newQuery(false, SqlQueries::SupprimerClient(client));
	action(Table::CLIENTS);
}

void ProjetPOOServices::SqlHandler::remplirArticlesCommande(CommandeMap^ commande, System::Collections::ArrayList^ liste)
{
	liste->Clear();
	this->query->newQuery(false, SqlQueries::listeCommandeArticles(commande));
	SqlManager^ manager = gcnew SqlManager();
	System::Data::DataSet^ dataset = manager->getRows(query, Table::CONSITUTER_LIEN_COMMANDES_ARTICLES);
	for each(System::Data::DataRow ^ row in dataset->Tables[Table::CONSITUTER_LIEN_COMMANDES_ARTICLES->getName()]->Rows)
	{
		ArticleMap^ article = gcnew ArticleMap();
		article->setIdArticle(row["Reference_article"]->ToString());
		article->setNom(row["Nom_article"]->ToString());
		article->setPrix(Convert::ToDouble(row["Prix_article_HT"]));
		article->setCouleur(row["Couleur_article"]->ToString());
		article->setTaxe(Convert::ToInt32(row["Pourcentage_taxe"]));
		article->setNature(row["Nature_article"]->ToString());
		article->setSeuilReapprovisionnement(Convert::ToInt32(row["Seuil_reapprovisionnement"]));
		article->setQuantite(Convert::ToInt32(row["Quantite_article_commande"]));
		article->setRemise(Convert::ToInt32(row["Pourcentage_remise_article"]));
		liste->Add(article);
	}
}

void ProjetPOOServices::SqlHandler::afficherPanierMoyen()
{
	this->query->newQuery(false, SqlQueries::getPanierMoyen());
	fill(Table::STATISTIQUES);
}

void ProjetPOOServices::SqlHandler::afficherChiffreAffaire(DateTime^ date)
{
	this->query->newQuery(false, SqlQueries::getChiffreAffaire(date));
	fill(Table::STATISTIQUES);
}

void ProjetPOOServices::SqlHandler::afficherArticlesSousSeuilReapprovisionnement()
{
	this->query->newQuery(false, SqlQueries::getProduitSousSeuilReapprovisionnement());
	fill(Table::STATISTIQUES);
}

void ProjetPOOServices::SqlHandler::afficherMontantTotalClient(ClientMap^ client)
{
	this->query->newQuery(false, SqlQueries::getMontantTotalClient(client));
	fill(Table::STATISTIQUES);
}

void ProjetPOOServices::SqlHandler::afficherArticlesPlusVendu()
{
	this->query->newQuery(false, SqlQueries::getProduitPlusVendu());
	fill(Table::STATISTIQUES);
}

void ProjetPOOServices::SqlHandler::afficherArticlesMoinsVendu()
{
	this->query->newQuery(false, SqlQueries::getProduitMoinsVendu());
	fill(Table::STATISTIQUES);
}

void ProjetPOOServices::SqlHandler::afficherValeurCommercialStock()
{
	this->query->newQuery(false, SqlQueries::getValeurCommercialStock());
	fill(Table::STATISTIQUES);
}

void ProjetPOOServices::SqlHandler::afficherValeurAchatStock()
{
	this->query->newQuery(false, SqlQueries::getValeurAchatStock());
	fill(Table::STATISTIQUES);
}

void ProjetPOOServices::SqlHandler::fillGrid(Table^ table, DataGridView^ grid)
{
	SqlQuery^ query = gcnew SqlQuery();
	SqlManager^ manager = gcnew SqlManager();
	query->newQuery(false, "SELECT * FROM " + table->getName());
	grid->DataSource = manager->getRows(query, table->getName());
	grid->DataMember = table->getName();
}

void ProjetPOOServices::SqlHandler::fillGrid(String^ query, String^ table, DataGridView^ grid)
{
	SqlQuery^ sqlQuery = gcnew SqlQuery();
	SqlManager^ manager = gcnew SqlManager();
	sqlQuery->newQuery(false, query);
	grid->DataSource = manager->getRows(sqlQuery, table);
	grid->DataMember = table;
}