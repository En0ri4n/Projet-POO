#include "SqlQuery.h"
#include "SqlManager.h"
#include "PersonnelMap.h"
#include "ArticleMap.h"
#include "SqlQueries.h"
#include "Projet.h"
#include "ArticlePopup.h"

using namespace System;

System::Void ProjetPOO::Projet::onFormLoad(System::Object^ sender, System::EventArgs^ e)
{
	sqlHandler = gcnew SqlHandler(this->dataGridView);
	setConnected(false);
}

System::Void ProjetPOO::Projet::setConnected(bool connected)
{
	this->connected = connected;

	this->rechercheColonnesBox->Visible = connected;
	this->boutonChercher->Visible = connected;
	this->rechercheBox->Visible = connected;

	this->boutonValider->Visible = connected;
	this->boutonAfficher->Visible = connected;
	this->boutonAfficherTout->Visible = connected;
	this->boutonAjouter->Visible = connected;
	this->boutonSupprimer->Visible = connected;
	this->boutonModifier->Visible = connected;

	if(connected)
	{
		this->tabController->Controls->Add(this->tabPersonnel);
		this->tabController->Controls->Add(this->tabStocks);
		this->tabController->Controls->Add(this->tabCommandes);
		this->tabController->Controls->Add(this->tabClients);
		this->tabController->Controls->Add(this->tabStatistiques);

		boutonAfficher->Enabled = false;
		currentMode = AFFICHER;
	}
	else
	{
		this->tabController->Controls->Remove(this->tabPersonnel);
		this->tabController->Controls->Remove(this->tabStocks);
		this->tabController->Controls->Remove(this->tabCommandes);
		this->tabController->Controls->Remove(this->tabClients);
		this->tabController->Controls->Remove(this->tabStatistiques);
	}
}
System::Void ProjetPOO::Projet::clickOnBoutonValider(System::Object^ sender, System::EventArgs^ e)
{
	if(isActive(tabPersonnel))
	{
		switch(currentMode)
		{
			case ProjetPOO::AFFICHER:
			{
				PersonnelMap^ personnel = gcnew PersonnelMap();
				personnel->setId((int) idPersonnelBox->Value);
				personnel->setNom(nomPersonnelBox->Text);
				personnel->setPrenom(prenomPersonnelBox->Text);
				personnel->setDateEmbauche(dateEmbauchePersonnelPicker->Value);
			}
			break;
			case ProjetPOO::SUPPRIMER:
				break;
			case ProjetPOO::AJOUTER:
				break;
			case ProjetPOO::MODIFIER:
				break;
			default:
				break;
		}
	}
}
System::Boolean ProjetPOO::Projet::isActive(System::Windows::Forms::TabPage^ tab)
{
	return this->tabController->SelectedTab == tab;
}
System::Void ProjetPOO::Projet::clickOnConnexionBDD(System::Object^ sender, System::EventArgs^ e)
{
	addHistorique(L"Connexion en cours...");
	setConnected(true);
	changeMode(currentMode);

	sqlHandler->fillGrid(Table::PERSONNES);
}
System::Void ProjetPOO::Projet::addHistorique(System::String^ historique)
{
	System::DateTime date = System::DateTime::Now;
	this->historiqueBox->Text += "[" + date.ToLongTimeString() + "] " + historique + "\r\n";
	this->historiqueBox->SelectionStart = this->historiqueBox->Text->Length - 1;
	this->historiqueBox->ScrollToCaret();
}
System::Void ProjetPOO::Projet::clickOnBoutonAfficher(System::Object^ sender, System::EventArgs^ e)
{
	changeMode(AFFICHER);
}
System::Void ProjetPOO::Projet::clickOnBoutonSupprimer(System::Object^ sender, System::EventArgs^ e)
{
	changeMode(SUPPRIMER);
}
System::Void ProjetPOO::Projet::clickOnBoutonAjouter(System::Object^ sender, System::EventArgs^ e)
{
	changeMode(AJOUTER);
}
System::Void ProjetPOO::Projet::clickOnBoutonModifier(System::Object^ sender, System::EventArgs^ e)
{
	changeMode(MODIFIER);
}
System::Void ProjetPOO::Projet::changeMode(SqlMode mode)
{
	currentMode = mode;

	this->boutonAfficher->Enabled = true;
	this->boutonAjouter->Enabled = true;
	this->boutonModifier->Enabled = true;
	this->boutonSupprimer->Enabled = true;

	System::String^ name;

	switch(mode)
	{
		case ProjetPOO::AFFICHER:
			this->boutonAfficher->Enabled = false;

			// Personnel
			this->idPersonnelBox->Enabled = true;
			this->nomPersonnelBox->Enabled = false;
			this->prenomPersonnelBox->Enabled = false;
			this->dateEmbauchePersonnelPicker->Enabled = false;

			// Stocks
			this->idStockBox->Enabled = true;
			this->nomStockBox->Enabled = false;
			this->prixStockBox->Enabled = false;
			this->natureStockBox->Enabled = false;
			this->couleurStockBox->Enabled = false;
			this->seuilStockBox->Enabled = false;
			this->quantiteStockBox->Enabled = false;
			this->tvaStockBox->Enabled = false;

			// Commandes
			this->idCommandeBox->Enabled = true;
			this->dateLivraisonCommandePicker->Enabled = false;
			this->dateEmissionCommandePicker->Enabled = false;
			this->moyenPayementCommandeBox->Enabled = false;
			this->datePayementCommandePicker->Enabled = false;


			name = L"Affichage";
			break;
		case ProjetPOO::SUPPRIMER:
			this->boutonSupprimer->Enabled = false;

			// Personnel
			this->idPersonnelBox->Enabled = true;
			this->nomPersonnelBox->Enabled = false;
			this->prenomPersonnelBox->Enabled = false;
			this->dateEmbauchePersonnelPicker->Enabled = false;

			// Stocks
			this->idStockBox->Enabled = true;
			this->nomStockBox->Enabled = false;
			this->prixStockBox->Enabled = false;
			this->natureStockBox->Enabled = false;
			this->couleurStockBox->Enabled = false;
			this->seuilStockBox->Enabled = false;
			this->quantiteStockBox->Enabled = false;
			this->tvaStockBox->Enabled = false;

			// Commandes
			this->idCommandeBox->Enabled = true;
			this->dateLivraisonCommandePicker->Enabled = false;
			this->dateEmissionCommandePicker->Enabled = false;
			this->moyenPayementCommandeBox->Enabled = false;
			this->datePayementCommandePicker->Enabled = false;


			name = L"Suppression";
			break;
		case ProjetPOO::AJOUTER:
			this->boutonAjouter->Enabled = false;

			// Personnel
			this->idPersonnelBox->Enabled = false;
			this->nomPersonnelBox->Enabled = true;
			this->prenomPersonnelBox->Enabled = true;
			this->dateEmbauchePersonnelPicker->Enabled = true;

			// Stocks
			this->idStockBox->Enabled = false;
			this->nomStockBox->Enabled = true;
			this->prixStockBox->Enabled = true;
			this->natureStockBox->Enabled = true;
			this->couleurStockBox->Enabled = true;
			this->seuilStockBox->Enabled = true;
			this->quantiteStockBox->Enabled = true;
			this->tvaStockBox->Enabled = true;

			// Commandes
			this->idCommandeBox->Enabled = false;
			this->dateLivraisonCommandePicker->Enabled = true;
			this->dateEmissionCommandePicker->Enabled = true;
			this->moyenPayementCommandeBox->Enabled = true;
			this->datePayementCommandePicker->Enabled = true;

			name = L"Ajout";
			break;
		case ProjetPOO::MODIFIER:
			this->boutonModifier->Enabled = false;

			// Personnel
			this->idPersonnelBox->Enabled = true;
			this->nomPersonnelBox->Enabled = true;
			this->prenomPersonnelBox->Enabled = true;
			this->dateEmbauchePersonnelPicker->Enabled = true;

			// Stocks
			this->idStockBox->Enabled = true;
			this->nomStockBox->Enabled = true;
			this->prixStockBox->Enabled = true;
			this->natureStockBox->Enabled = true;
			this->couleurStockBox->Enabled = true;
			this->seuilStockBox->Enabled = true;
			this->quantiteStockBox->Enabled = true;
			this->tvaStockBox->Enabled = true;

			// Commandes
			this->idCommandeBox->Enabled = true;
			this->dateLivraisonCommandePicker->Enabled = true;
			this->dateEmissionCommandePicker->Enabled = true;
			this->moyenPayementCommandeBox->Enabled = true;
			this->datePayementCommandePicker->Enabled = true;

			name = L"Modification";
			break;
		default:
			break;
	}

	addHistorique("Mode : " + name);
}

System::Void ProjetPOO::Projet::clickOnBoutonArticlesCommandes(System::Object^ sender, System::EventArgs^ e)
{
	ArticlePopup^ popup = gcnew ArticlePopup(getArticlesCommande());
	popup->Show();
}
System::Void ProjetPOO::Projet::clickOnBoutonAfficherTout(System::Object^ sender, System::EventArgs^ e)
{
	afficherTable();
}
System::Void ProjetPOO::Projet::onChangeTab(System::Object^ sender, System::Windows::Forms::TabControlEventArgs^ e)
{
	afficherTable();
}
System::Void ProjetPOO::Projet::afficherTable()
{
	if(isActive(tabPersonnel))
		sqlHandler->SelectPersonnel();
	else if(isActive(tabStocks))
		sqlHandler->fillGrid(Table::ARTICLES);
	else if(isActive(tabCommandes))
		sqlHandler->fillGrid(Table::COMMANDES);
	else if(isActive(tabClients))
		sqlHandler->fillGrid(Table::CLIENTS);
	else if(isActive(tabStatistiques))
		sqlHandler->fillGrid(Table::ARTICLES);

	updateRechercheColonneBox();
}
System::Void ProjetPOO::Projet::clickOnBoutonChercher(System::Object^ sender, System::EventArgs^ e)
{
	if(isActive(tabPersonnel))
		sqlHandler->searchByColumn(Table::PERSONNELS, "Id_personne", this->idPersonnelBox->Text, true);
	else if(isActive(tabCommandes))
		sqlHandler->searchByColumn(Table::COMMANDES, "Reference_commande", this->idCommandeBox->Text, false);
}
System::Void ProjetPOO::Projet::clickOnCellule(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if(isActive(tabPersonnel))
	{
		this->idPersonnelBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
		this->nomPersonnelBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[1]->Value->ToString();
		this->prenomPersonnelBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[2]->Value->ToString();
		this->dateEmbauchePersonnelPicker->Text = this->dataGridView->Rows[e->RowIndex]->Cells[3]->Value->ToString();

		addHistorique(SqlQueries::AjouterPersonnel(gcnew PersonnelMap(5, "Rajo", "Eno", gcnew AdresseMap(8, gcnew VilleMap(6, "Obernai", "67210"), "Rue du landsberg", 152), DateTime::Now, 9)));
	}
	else if(isActive(tabStocks))
	{
		this->idStockBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
		this->nomStockBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[1]->Value->ToString();
		this->prixStockBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[2]->Value->ToString();
		this->natureStockBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[3]->Value->ToString();
		this->couleurStockBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[4]->Value->ToString();
		this->seuilStockBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[5]->Value->ToString();
		this->quantiteStockBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[6]->Value->ToString();
		this->tvaStockBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[7]->Value->ToString();
	}
	else if(isActive(tabCommandes))
	{
		this->idCommandeBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
		this->dateLivraisonCommandePicker->Text = this->dataGridView->Rows[e->RowIndex]->Cells[1]->Value->ToString();
		this->dateEmissionCommandePicker->Text = this->dataGridView->Rows[e->RowIndex]->Cells[2]->Value->ToString();
		this->moyenPayementCommandeBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[3]->Value->ToString();
		this->datePayementCommandePicker->Text = this->dataGridView->Rows[e->RowIndex]->Cells[4]->Value->ToString();
	}
}
System::Void ProjetPOO::Projet::updateRechercheColonneBox()
{
	array<System::Object^>^ list = gcnew array<System::Object^>(this->dataGridView->ColumnCount);
	for(int i = 0; i < this->dataGridView->ColumnCount; i++)
	{
		list[i] = this->dataGridView->Columns[i]->Name;
	}

	this->rechercheColonnesBox->Items->Clear();
	this->rechercheColonnesBox->Items->AddRange(list);
	this->rechercheColonnesBox->SelectedItem = list[0];
}
System::Void ProjetPOO::Projet::updateArticlesCommande(ArrayList^ list)
{
	articlesCommande = list;
	this->articlesCommandeLabel->Text = "Articles de la commande (" + list->Count + ")";
}

Collections::ArrayList^ ProjetPOO::Projet::getArticlesCommande()
{
	return articlesCommande;
}
