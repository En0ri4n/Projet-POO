#include "SqlQuery.h"
#include "SqlManager.h"
#include "PersonnelMap.h"
#include "ArticleMap.h"
#include "SqlQueries.h"
#include "Projet.h"
#include "ArticlePopup.h"
#include "AdressePopup.h"
#include "SocieteReference.h"

using namespace PdfSharp;
using namespace PdfSharp::Drawing;
using namespace PdfSharp::Pdf;
using namespace PdfSharp::Pdf::AcroForms;

using namespace System;

System::Void ProjetPOO::Projet::onFormLoad(System::Object^ sender, System::EventArgs^ e)
{
	setConnected(false);
}
System::Void ProjetPOO::Projet::setConnected(bool connected)
{
	this->connected = connected;

	this->clearBouton->Visible = connected;
	this->rechercheColonnesBox->Visible = connected;
	this->rechercheBouton->Visible = connected;
	this->rechercheBox->Visible = connected;

	this->boutonValider->Visible = connected;
	this->boutonAfficher->Visible = connected;
	this->boutonAfficherTout->Visible = connected;
	this->boutonAjouter->Visible = connected;
	this->boutonSupprimer->Visible = connected;
	this->boutonModifier->Visible = connected;

	this->statistiqueBox->SelectedIndex = 0;
	this->tvaStatistiqueBox->SelectedIndex = 0;
	this->margeCommercialeStatistiqueBox->SelectedIndex = 0;
	this->remiseCommercialeStatistiqueBox->SelectedIndex = 0;
	this->demarqueStatistiqueBox->SelectedIndex = 0;

	if(connected)
	{
		if(tabController->TabPages->Count > 1)
			return;

		estSuperviseur = this->superviseurCheckBox->Checked;
		if(estSuperviseur)
			this->tabController->Controls->Add(this->tabPersonnel);
		this->tabController->Controls->Add(this->tabStocks);
		this->tabController->Controls->Add(this->tabCommandes);
		this->tabController->Controls->Add(this->tabClients);
		this->tabController->Controls->Add(this->tabStatistiques);

		this->usernameLabel->Enabled = false;
		this->usernameBox->Enabled = false;
		this->passwordLabel->Enabled = false;
		this->passwordBox->Enabled = false;
		this->connexionBouton->Enabled = false;
		this->superviseurCheckBox->Enabled = false;

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
		PersonnelMap^ personnel = gcnew PersonnelMap();
		personnel->setId(Convert::ToInt32(idPersonnelBox->Value));
		personnel->setNom(nomPersonnelBox->Text);
		personnel->setPrenom(prenomPersonnelBox->Text);
		personnel->setAdresse(currentPersonnelAdresse);
		personnel->setDateEmbauche(dateEmbauchePersonnelPicker->Value);
		personnel->setIdSuperviseur(Convert::ToInt32(idSuperviseurPersonnelBox->Value));


		switch(currentMode)
		{
			case ProjetPOO::AFFICHER:
				sqlHandler->AfficherPersonnel();
				addHistorique("Affichage du personnel");
				break;
			case ProjetPOO::SUPPRIMER:
				sqlHandler->SupprimerPersonnel(personnel);
				addHistorique("Suppression du personnel " + personnel->getNom() + " " + personnel->getPrenom() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			case ProjetPOO::AJOUTER:
				sqlHandler->AjouterPersonnel(personnel);
				addHistorique("Ajout du personnel " + personnel->getNom() + " " + personnel->getPrenom() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			case ProjetPOO::MODIFIER:
				sqlHandler->ModifierPersonnel(personnel);
				addHistorique("Modification du personnel " + personnel->getNom() + " " + personnel->getPrenom() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			default:
				break;
		}
	}
	else if(isActive(tabCommandes))
	{
		CommandeMap^ commande = gcnew CommandeMap();
		commande->setIdCommande(idCommandeBox->Text);
		commande->setDateLivraison(dateLivraisonCommandePicker->Value);
		commande->setDateEmission(dateEmissionCommandePicker->Value);
		commande->setMoyenPaiement(moyenPayementCommandeBox->Text);
		commande->setDatePaiement(datePayementCommandePicker->Value);
		commande->setIdClient(Convert::ToInt32(idClientCommandeBox->Value));
		commande->setListeArticles(getArticlesCommande());
		commande->setDerniereListeArticles(derniersArticlesCommande);

		switch(currentMode)
		{
			case ProjetPOO::AFFICHER:
				sqlHandler->AfficherCommandes();
				addHistorique("Affichage de la commande " + commande->getIdCommande());
				break;
			case ProjetPOO::SUPPRIMER:
				sqlHandler->SupprimerCommande(commande);
				addHistorique("Suppression de la commande " + commande->getIdCommande() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			case ProjetPOO::AJOUTER:
				sqlHandler->AjouterCommande(commande);
				addHistorique("Ajout de la commande " + commande->getIdCommande() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			case ProjetPOO::MODIFIER:
				sqlHandler->ModifierCommande(commande);
				addHistorique("Modification de la commande " + commande->getIdCommande() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			default:
				break;
		}
	}
	else if(isActive(tabStocks))
	{
		ArticleMap^ article = gcnew ArticleMap();
		article->setIdArticle(idStockBox->Text);
		article->setNom(nomStockBox->Text);
		article->setPrix(Convert::ToDouble(prixStockBox->Text));
		article->setNature(natureStockBox->Text);
		article->setCouleur(couleurStockBox->Text);
		article->setSeuilReapprovisionnement(Convert::ToInt32(seuilStockBox->Text));
		article->setQuantite(Convert::ToInt32(quantiteStockBox->Text));
		article->setTaxe(Convert::ToDouble(tvaStockBox->Text));

		switch(currentMode)
		{
			case ProjetPOO::AFFICHER:
				sqlHandler->AfficherArticles();
				addHistorique("Affichage de l'article " + article->getIdArticle());
				break;
			case ProjetPOO::SUPPRIMER:
				sqlHandler->SupprimerArticle(article);
				addHistorique("Suppression de l'article " + article->getIdArticle() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			case ProjetPOO::AJOUTER:
				sqlHandler->AjouterArticle(article);
				addHistorique("Ajout de l'article " + article->getNom() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			case ProjetPOO::MODIFIER:
				sqlHandler->ModifierArticle(article);
				addHistorique("Modification de l'article " + article->getIdArticle() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			default:
				break;
		}
	}
	else if(isActive(tabClients))
	{
		ClientMap^ client = gcnew ClientMap();
		client->setId(Convert::ToInt32(idClientBox->Text));
		client->setNom(nomClientBox->Text);
		client->setPrenom(prenomClientBox->Text);
		client->setAdresseLivraison(currentClientAdresseLivraison);
		client->setAdresseFacturation(currentClientAdresseFacturation);
		client->setDateNaissance(dateNaissanceClientPicker->Value);
		client->setDatePremierAchat(datePremierAchatClientPicker->Value);

		switch(currentMode)
		{
			case ProjetPOO::AFFICHER:
				sqlHandler->AfficherClients();
				addHistorique("Affichage du client " + client->getNom() + " " + client->getPrenom());
				break;
			case ProjetPOO::SUPPRIMER:
				sqlHandler->SupprimerClient(client);
				addHistorique("Suppression du client " + client->getNom() + " " + client->getPrenom() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			case ProjetPOO::AJOUTER:
				sqlHandler->AjouterClient(client);
				addHistorique("Ajout du client " + client->getNom() + " " + client->getPrenom() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			case ProjetPOO::MODIFIER:
				sqlHandler->ModifierClient(client);
				addHistorique("Modification du client " + client->getNom() + " " + client->getPrenom() + " : " + Convert::ToInt32(sqlHandler->getLastCount()));
				break;
			default:
				break;
		}
	}

	afficherTable();
}
System::Void ProjetPOO::Projet::clickOnConnexionBDD(System::Object^ sender, System::EventArgs^ e)
{
	if(!connected)
	{
		String^ username = this->usernameBox->Text;
		String^ password = this->passwordBox->Text;

		if(username->Length == 0 || password->Length == 0)
		{
			addHistorique("Veuillez entrer un nom d'utilisateur et un mot de passe");
			return;
		}

		sqlHandler = gcnew SqlHandler(this->dataGridView, username, password);

		if(sqlHandler->getManager()->isConnected())
		{
			addHistorique("Connexion r�ussie");
			setConnected(true);
			changeMode(currentMode);
			sqlHandler->fillGrid(Table::PERSONNES);
		}
		else
		{
			addHistorique("Connexion �chou�e");
			setConnected(false);
		}
	}
}
System::Void ProjetPOO::Projet::addHistorique(System::String^ historique)
{
	System::DateTime date = System::DateTime::Now;
	this->historiqueBox->Text += "[" + date.ToLongTimeString() + "] " + historique + "\r\n";
	this->historiqueBox->SelectionStart = this->historiqueBox->Text->Length - 1;
	this->historiqueBox->ScrollToCaret();
}
System::Void ProjetPOO::Projet::addQueryHistorique(System::String^ query)
{
	if(this->voirRequetesCheckBox->Checked)
		addHistorique("[@] " + query);
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
		case ProjetPOO::SUPPRIMER:
			// Personnel
			this->idPersonnelBox->Enabled = true;
			this->nomPersonnelBox->Enabled = false;
			this->prenomPersonnelBox->Enabled = false;
			this->dateEmbauchePersonnelPicker->Enabled = false;
			this->idSuperviseurPersonnelBox->Enabled = false;
			this->superviseurPersonnelCheckBox->Enabled = false;

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
			this->idClientCommandeBox->Enabled = false;

			// Clients
			this->idClientBox->Enabled = true;
			this->nomClientBox->Enabled = false;
			this->prenomClientBox->Enabled = false;
			this->dateNaissanceClientPicker->Enabled = false;
			this->datePremierAchatClientPicker->Enabled = false;

			if(mode == AFFICHER)
			{
				this->factureCommandeBouton->Enabled = true;

				this->boutonAfficher->Enabled = false;
				name = L"Affichage";
			}
			else if(mode == SUPPRIMER)
			{
				this->factureCommandeBouton->Enabled = false;

				this->boutonSupprimer->Enabled = false;
				name = L"Suppression";
			}
			break;
		case ProjetPOO::AJOUTER:
		case ProjetPOO::MODIFIER:
			// Personnel
			this->nomPersonnelBox->Enabled = true;
			this->prenomPersonnelBox->Enabled = true;
			this->dateEmbauchePersonnelPicker->Enabled = true;
			this->idSuperviseurPersonnelBox->Enabled = this->superviseurPersonnelCheckBox->Checked;
			this->superviseurPersonnelCheckBox->Enabled = true;

			// Stocks
			this->idStockBox->Enabled = true;
			this->nomStockBox->Enabled = true;
			this->prixStockBox->Enabled = true;
			this->natureStockBox->Enabled = true;
			this->couleurStockBox->Enabled = true;
			this->seuilStockBox->Enabled = true;
			this->quantiteStockBox->Enabled = true;
			this->tvaStockBox->Enabled = true;
			this->factureCommandeBouton->Enabled = false;

			// Commandes
			this->dateLivraisonCommandePicker->Enabled = true;
			this->dateEmissionCommandePicker->Enabled = true;
			this->datePayementCommandePicker->Enabled = true;
			this->idClientCommandeBox->Enabled = true;

			this->nomClientBox->Enabled = true;
			this->prenomClientBox->Enabled = true;
			this->dateNaissanceClientPicker->Enabled = true;
			this->datePremierAchatClientPicker->Enabled = true;

			if(mode == AJOUTER)
			{
				this->idPersonnelBox->Enabled = false;
				this->idCommandeBox->Enabled = false;
				this->moyenPayementCommandeBox->Enabled = true;
				this->idClientBox->Enabled = false;

				this->boutonAjouter->Enabled = false;
				name = L"Ajout";
			}
			else if(mode == MODIFIER)
			{
				this->idPersonnelBox->Enabled = true;
				this->idCommandeBox->Enabled = true;
				this->moyenPayementCommandeBox->Enabled = false;
				this->idClientBox->Enabled = true;

				this->boutonModifier->Enabled = false;
				name = L"Modification";
			}
			break;
		default:
			break;
	}

	resetBoxes();

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
		sqlHandler->AfficherPersonnel();
	else if(isActive(tabStocks))
		sqlHandler->AfficherArticles();
	else if(isActive(tabCommandes))
		sqlHandler->AfficherCommandes();
	else if(isActive(tabClients))
		sqlHandler->AfficherClients();
	else if(isActive(tabStatistiques))
	{
		sqlHandler->fillGrid(Table::ARTICLES);
		this->idArticleStatistiqueBox->Text = this->dataGridView->Rows[0]->Cells[0]->Value->ToString();
	}
	updateRechercheColonneBox();
}
System::Void ProjetPOO::Projet::clickOnCellule(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if(isActive(tabPersonnel))
	{
		this->idPersonnelBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
		this->nomPersonnelBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[1]->Value->ToString();
		this->prenomPersonnelBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[2]->Value->ToString();
		this->dateEmbauchePersonnelPicker->Text = this->dataGridView->Rows[e->RowIndex]->Cells[3]->Value->ToString();
		currentPersonnelAdresse->setIdAdresse((int) this->dataGridView->Rows[e->RowIndex]->Cells[5]->Value);
		currentPersonnelAdresse->setNumero(Convert::ToInt32(this->dataGridView->Rows[e->RowIndex]->Cells[6]->Value->ToString()));
		currentPersonnelAdresse->setRue(this->dataGridView->Rows[e->RowIndex]->Cells[7]->Value->ToString());
		currentPersonnelAdresse->getVille()->setIdVille(Convert::ToInt32(this->dataGridView->Rows[e->RowIndex]->Cells[8]->Value->ToString()));
		currentPersonnelAdresse->getVille()->setNom(this->dataGridView->Rows[e->RowIndex]->Cells[9]->Value->ToString());
		currentPersonnelAdresse->getVille()->setCodePostal(this->dataGridView->Rows[e->RowIndex]->Cells[10]->Value->ToString());
		this->idSuperviseurPersonnelBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[4]->Value->ToString();
		bool superviseur = String::IsNullOrWhiteSpace(this->dataGridView->Rows[e->RowIndex]->Cells[4]->Value->ToString());
		this->superviseurPersonnelCheckBox->Checked = !superviseur;
		this->idSuperviseurPersonnelBox->Enabled = !superviseur;

		updateAdresseBouton(TypeAdresse::PERSONNEL);
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
		this->idClientCommandeBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[6]->Value->ToString();
		sqlHandler->remplirArticlesCommande(CommandeMap::from(this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString()), this->articlesCommande);
		updateArticlesCommande(this->articlesCommande);
		sqlHandler->remplirArticlesCommande(CommandeMap::from(this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString()), this->derniersArticlesCommande);
	}
	else if(isActive(tabClients))
	{
		this->idClientBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
		this->nomClientBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[1]->Value->ToString();
		this->prenomClientBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[2]->Value->ToString();
		this->dateNaissanceClientPicker->Text = this->dataGridView->Rows[e->RowIndex]->Cells[3]->Value->ToString();
		this->datePremierAchatClientPicker->Text = this->dataGridView->Rows[e->RowIndex]->Cells[4]->Value->ToString();
		currentClientAdresseFacturation->setIdAdresse((int) this->dataGridView->Rows[e->RowIndex]->Cells[5]->Value);
		currentClientAdresseFacturation->setNumero(Convert::ToInt32(this->dataGridView->Rows[e->RowIndex]->Cells[6]->Value->ToString()));
		currentClientAdresseFacturation->setRue(this->dataGridView->Rows[e->RowIndex]->Cells[7]->Value->ToString());
		currentClientAdresseFacturation->getVille()->setIdVille(Convert::ToInt32(this->dataGridView->Rows[e->RowIndex]->Cells[8]->Value->ToString()));
		currentClientAdresseFacturation->getVille()->setNom(this->dataGridView->Rows[e->RowIndex]->Cells[9]->Value->ToString());
		currentClientAdresseFacturation->getVille()->setCodePostal(this->dataGridView->Rows[e->RowIndex]->Cells[10]->Value->ToString());
		currentClientAdresseLivraison->setIdAdresse((int) this->dataGridView->Rows[e->RowIndex]->Cells[11]->Value);
		currentClientAdresseLivraison->setNumero(Convert::ToInt32(this->dataGridView->Rows[e->RowIndex]->Cells[12]->Value->ToString()));
		currentClientAdresseLivraison->setRue(this->dataGridView->Rows[e->RowIndex]->Cells[13]->Value->ToString());
		currentClientAdresseLivraison->getVille()->setIdVille(Convert::ToInt32(this->dataGridView->Rows[e->RowIndex]->Cells[14]->Value->ToString()));
		currentClientAdresseLivraison->getVille()->setNom(this->dataGridView->Rows[e->RowIndex]->Cells[15]->Value->ToString());
		currentClientAdresseLivraison->getVille()->setCodePostal(this->dataGridView->Rows[e->RowIndex]->Cells[16]->Value->ToString());

		updateAdresseBouton(TypeAdresse::FACTURATION);
		updateAdresseBouton(TypeAdresse::LIVRAISON);
	}
	else if(isActive(tabStatistiques))
	{
		if(this->statistiqueBox->SelectedIndex == VARIATION_PRIX_ARTICLE)
		{
			this->idArticleStatistiqueBox->Text = this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
		}
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
System::Void ProjetPOO::Projet::setAdresseValue(TypeAdresse type, AdresseMap^ adresse)
{
	switch(type)
	{
		case TypeAdresse::PERSONNEL:
			currentPersonnelAdresse = adresse;
			break;
		case TypeAdresse::LIVRAISON:
			currentClientAdresseLivraison = adresse;
			break;
		case TypeAdresse::FACTURATION:
			currentClientAdresseFacturation = adresse;
			break;
		default:
			break;
	}

	updateAdresseBouton(type);
}
System::Void ProjetPOO::Projet::clickOnBoutonAdressePersonnel(System::Object^ sender, System::EventArgs^ e)
{
	AdressePopup^ popup = gcnew AdressePopup(TypeAdresse::PERSONNEL, currentPersonnelAdresse);
	popup->Show();
}
System::Void ProjetPOO::Projet::clickOnBoutonAdresseLivraisonClient(System::Object^ sender, System::EventArgs^ e)
{
	AdressePopup^ popup = gcnew AdressePopup(TypeAdresse::LIVRAISON, currentClientAdresseLivraison);
	popup->Show();
}
System::Void ProjetPOO::Projet::clickOnBoutonAdresseFacturationClient(System::Object^ sender, System::EventArgs^ e)
{
	AdressePopup^ popup = gcnew AdressePopup(TypeAdresse::FACTURATION, currentClientAdresseFacturation);
	popup->Show();
}
System::Void ProjetPOO::Projet::updateAdresseBouton(TypeAdresse type)
{
	switch(type)
	{
		case TypeAdresse::PERSONNEL:
			if(currentPersonnelAdresse->getNumero() != -1)
				this->adressePersonnelBouton->Text = currentPersonnelAdresse->getNumero() + " " + currentPersonnelAdresse->getRue() + " " + currentPersonnelAdresse->getVille()->getNom();
			else
				this->adressePersonnelBouton->Text = "Aucune adresse";
			break;
		case TypeAdresse::LIVRAISON:
			if(currentClientAdresseLivraison->getNumero() != -1)
				this->adresseLivraisonClientBouton->Text = currentClientAdresseLivraison->getNumero() + " " + currentClientAdresseLivraison->getRue() + " " + currentClientAdresseLivraison->getVille()->getNom();
			else
				this->adresseLivraisonClientBouton->Text = "Aucune adresse";
			break;
		case TypeAdresse::FACTURATION:
			if(currentClientAdresseFacturation->getNumero() != -1)
				this->adresseFacturationClientBouton->Text = currentClientAdresseFacturation->getNumero() + " " + currentClientAdresseFacturation->getRue() + " " + currentClientAdresseFacturation->getVille()->getNom();
			else
				this->adresseFacturationClientBouton->Text = "Aucune adresse";
			break;
		default:
			break;
	}
}
System::Void ProjetPOO::Projet::clickOnClearBouton(System::Object^ sender, System::EventArgs^ e)
{
	resetBoxes();
}
System::Void ProjetPOO::Projet::clickOnCalculerStatistiques(System::Object^ sender, System::EventArgs^ e)
{
	// Supprimes toutes les colonnes de la table statistiques, sinon elles s'ajoutent � la suite
	// au lieu de remplacer les anciennes
	System::Data::DataTableCollection^ tables = ((DataSet^) this->dataGridView->DataSource)->Tables;
	if(tables->Contains(Table::STATISTIQUES->getName()))
		tables[Table::STATISTIQUES->getName()]->Columns->Clear();

	int tva = 0;
	int remise = 0;

	ArticleMap^ article = gcnew ArticleMap();
	article->setIdArticle(this->idArticleStatistiqueBox->Text);
	switch(this->tvaStatistiqueBox->SelectedIndex)
	{
		case 0:
			tva += 0;
			break;
		case 1:
			tva += 5.5;
			break;
		case 2:
			tva += 10;
			break;
		case 3:
			tva += 20;
			break;
		default:
			break;
	}
	switch(this->margeCommercialeStatistiqueBox->SelectedIndex)
	{
		case 0:
			tva += 0;
			break;
		case 1:
			tva += 5;
			break;
		case 2:
			tva += 10;
			break;
		case 3:
			tva += 15;
			break;
		default:
			break;
	}
	switch(this->remiseCommercialeStatistiqueBox->SelectedIndex)
	{
		case 0:
			remise += 0;
			break;
		case 1:
			remise += 5;
			break;
		case 2:
			remise += 6;
			break;
		default:
			break;
	}
	switch(this->demarqueStatistiqueBox->SelectedIndex)
	{
		case 0:
			remise += 0;
			break;
		case 1:
			remise += 2;
			break;
		case 2:
			remise += 3;
			break;
		case 3:
			remise += 5;
			break;
		default:
			break;
	}
	article->setTaxe(tva);
	article->setRemise(remise);

	switch(this->statistiqueBox->SelectedIndex)
	{
		case PANIER_MOYEN:
			sqlHandler->afficherPanierMoyen();
			addHistorique("Affichage du panier moyen");
			break;
		case CHIFFRE_AFFAIRE:
			sqlHandler->afficherChiffreAffaire(this->dateMoisStatistiquePicker->Value);
			addHistorique("Affichage du chiffre d'affaire du " + this->dateMoisStatistiquePicker->Value.Month + "/" + this->dateMoisStatistiquePicker->Value.Year);
			break;
		case ARTICLES_SOUS_SEUIL_REAPPROVISIONNEMENT:
			sqlHandler->afficherArticlesSousSeuilReapprovisionnement();
			addHistorique("Affichage des articles sous le seuil de r�approvisionnement");
			break;
		case MONTANT_TOTAL_ACHAT_CLIENT:
			sqlHandler->afficherMontantTotalClient(ClientMap::from(Convert::ToInt32(this->idClientStatistiqueBox->Value)));
			addHistorique("Affichage du montant total des achats pour le client " + Convert::ToInt32(this->idClientStatistiqueBox->Value));
			break;
		case ARTICLES_PLUS_VENDUS:
			sqlHandler->afficherArticlesPlusVendu();
			addHistorique("Affichage des articles les plus vendus");
			break;
		case ARTICLES_MOINS_VENDUS:
			sqlHandler->afficherArticlesMoinsVendu();
			addHistorique("Affichage des articles les moins vendus");
			break;
		case STOCK_VALEUR_COMMERCIALE:
			sqlHandler->afficherValeurCommercialStock();
			addHistorique("Affichage de la valeur commerciale du stock");
			break;
		case STOCK_VALEUR_ACHAT:
			sqlHandler->afficherValeurAchatStock();
			addHistorique("Affichage de la valeur d'achat du stock");
			break;
		case VARIATION_PRIX_ARTICLE:
			sqlHandler->afficherVariationArticle(article);
			addHistorique("Affichage de la variation du prix d'un article - TVA : " + tva + "%  - Remise : " + remise + "%");
			break;
		default:
			break;
	}
}
System::Void ProjetPOO::Projet::clickOnStatistiqueBox(System::Object^ sender, System::EventArgs^ e)
{
	this->moisStatistiquesLabel->Enabled = false;
	this->dateMoisStatistiquePicker->Enabled = false;
	this->idClientStatistiqueLabel->Enabled = false;
	this->idClientStatistiqueBox->Enabled = false;
	this->idArticleStatistiqueLabel->Enabled = false;
	this->idArticleStatistiqueBox->Enabled = false;
	this->tvaStatistiqueBox->Enabled = false;
	this->margeCommercialeStatistiqueBox->Enabled = false;
	this->remiseCommercialeStatistiqueBox->Enabled = false;
	this->demarqueStatistiqueBox->Enabled = false;
	this->tvaStatistiqueLabel->Enabled = false;
	this->margeCommercialeStatistiqueLabel->Enabled = false;
	this->remiseCommercialeStatistiqueLabel->Enabled = false;
	this->demarqueInconnueStatistiqueLabel->Enabled = false;

	switch(this->statistiqueBox->SelectedIndex)
	{
		case CHIFFRE_AFFAIRE:
			this->moisStatistiquesLabel->Enabled = true;
			this->dateMoisStatistiquePicker->Enabled = true;
			break;
		case MONTANT_TOTAL_ACHAT_CLIENT:
			this->idClientStatistiqueLabel->Enabled = true;
			this->idClientStatistiqueBox->Enabled = true;
			break;
		case VARIATION_PRIX_ARTICLE:
			this->idArticleStatistiqueLabel->Enabled = true;
			this->idArticleStatistiqueBox->Enabled = true;
			this->tvaStatistiqueBox->Enabled = true;
			this->margeCommercialeStatistiqueBox->Enabled = true;
			this->remiseCommercialeStatistiqueBox->Enabled = true;
			this->demarqueStatistiqueBox->Enabled = true;
			this->tvaStatistiqueLabel->Enabled = true;
			this->margeCommercialeStatistiqueLabel->Enabled = true;
			this->remiseCommercialeStatistiqueLabel->Enabled = true;
			this->demarqueInconnueStatistiqueLabel->Enabled = true;
			break;
		case ARTICLES_SOUS_SEUIL_REAPPROVISIONNEMENT:
		case PANIER_MOYEN:
		case ARTICLES_PLUS_VENDUS:
		case ARTICLES_MOINS_VENDUS:
		case STOCK_VALEUR_COMMERCIALE:
		case STOCK_VALEUR_ACHAT:
		default:
			break;
	}
}
System::Void ProjetPOO::Projet::clickOnSuperviseurPersonnelCheckBox(System::Object^ sender, System::EventArgs^ e)
{
	this->idSuperviseurPersonnelBox->Enabled = this->superviseurPersonnelCheckBox->Checked;
}
System::Void ProjetPOO::Projet::clickOnRechercheBouton(System::Object^ sender, System::EventArgs^ e)
{
	String^ colonne = this->rechercheColonnesBox->SelectedItem->ToString();
	String^ recherche = this->rechercheBox->Text;

	if(isActive(tabPersonnel))
		sqlHandler->filtre(Table::PERSONNELS, colonne, recherche);
	else if(isActive(tabStocks))
		sqlHandler->filtre(Table::ARTICLES, colonne, recherche);
	else if(isActive(tabCommandes))
		sqlHandler->filtre(Table::COMMANDES, colonne, recherche);
	else if(isActive(tabClients))
		sqlHandler->filtreClients(colonne, recherche);
	else if(isActive(tabStatistiques))
		sqlHandler->filtre(Table::ARTICLES, colonne, recherche);
}
System::Void ProjetPOO::Projet::resetBoxes()
{

	this->idPersonnelBox->Value = 0;
	this->nomPersonnelBox->Text = "";
	this->prenomPersonnelBox->Text = "";
	this->dateEmbauchePersonnelPicker->Value = System::DateTime::Now;
	this->idSuperviseurPersonnelBox->Value = 0;

	this->idStockBox->Text = "";
	this->nomStockBox->Text = "";
	this->prixStockBox->Text = "";
	this->natureStockBox->Text = "";
	this->couleurStockBox->Text = "";
	this->seuilStockBox->Value = 0;
	this->quantiteStockBox->Value = 0;
	this->tvaStockBox->Text = "";

	this->idCommandeBox->Text = "";
	this->dateLivraisonCommandePicker->Value = System::DateTime::Now;
	this->dateEmissionCommandePicker->Value = System::DateTime::Now;
	this->moyenPayementCommandeBox->Text = "";
	this->datePayementCommandePicker->Value = System::DateTime::Now;
	this->idClientCommandeBox->Value = 0;

	this->idClientBox->Value = 0;
	this->nomClientBox->Text = "";
	this->prenomClientBox->Text = "";
	this->dateNaissanceClientPicker->Value = System::DateTime::Now;
	this->datePremierAchatClientPicker->Value = System::DateTime::Now;

	currentPersonnelAdresse = gcnew AdresseMap();
	currentClientAdresseLivraison = gcnew AdresseMap();
	currentClientAdresseFacturation = gcnew AdresseMap();

	updateAdresseBouton(TypeAdresse::PERSONNEL);
	updateAdresseBouton(TypeAdresse::LIVRAISON);
	updateAdresseBouton(TypeAdresse::FACTURATION);
}
System::Void ProjetPOO::Projet::clickOnHistoriqueLabel(System::Object^ sender, System::EventArgs^ e)
{

}
System::Boolean ProjetPOO::Projet::isActive(System::Windows::Forms::TabPage^ tab)
{
	return this->tabController->SelectedTab == tab;
}
System::Void ProjetPOO::Projet::generatePdf(CommandeMap^ commande, ClientMap^ client)
{
	addHistorique("G�n�ration de la facture de la commande " + commande->getIdCommande() + " pour le client " + client->getNom() + " " + client->getPrenom());

	PdfDocument^ document = gcnew PdfDocument();
	PdfSharp::Pdf::PdfPage^ page = document->AddPage();
	XGraphics^ gfx = XGraphics::FromPdfPage(page);

	const int pageWidth = 610;
	int borderX = 17;
	int outBorderX = pageWidth - borderX * 2;

	gfx->DrawImage(XImage::FromFile("logo.png"), 10, 10, 120, 120);

	gfx->DrawString("EVAL", gcnew XFont("Arial", 18), XBrushes::Black, borderX, 152);

	// Draw facture below the logo
	AdresseMap^ adresseSociete = SocieteReference::ADRESSE;
	gfx->DrawString(adresseSociete->getNumero() + " " + adresseSociete->getRue(), gcnew XFont("Arial", 12), XBrushes::Black, borderX, 170);
	gfx->DrawString(adresseSociete->getVille()->getCodePostal() + " " + adresseSociete->getVille()->getNom(), gcnew XFont("Arial", 12), XBrushes::Black, borderX, 186);
	gfx->DrawString("FRANCE", gcnew XFont("Arial", 12), XBrushes::Black, borderX, 202);

	gfx->DrawString(String::Format("T�l : {0}", SocieteReference::SERVICE_CLIENT), gcnew XFont("Arial", 10), XBrushes::Black, borderX, 230);
	gfx->DrawString(SocieteReference::MAIL, gcnew XFont("Arial", 10), XBrushes::Black, borderX, 242);
	gfx->DrawString(SocieteReference::SITE, gcnew XFont("Arial", 10), XBrushes::Black, borderX, 254);

	gfx->DrawRectangle(XBrushes::Gray, outBorderX - 250, 10, 250, 30);
	gfx->DrawRectangle(XBrushes::White, outBorderX - 250 + 1, 11, 248, 28);
	gfx->DrawString("FACTURE", gcnew XFont("Arial", 20), XBrushes::Black, outBorderX - 250 + 125, 15, XStringFormat::TopCenter);

	gfx->DrawString(String::Format("R�f�rence : {0}", commande->getIdCommande()), gcnew XFont("Arial", 10, XFontStyle::Bold), XBrushes::Black, outBorderX - gfx->MeasureString(String::Format("R�f�rence : {0}", commande->getIdCommande()), gcnew XFont("Arial", 10, XFontStyle::Bold)).Width, 58);
	gfx->DrawString("Version : 1.0", gcnew XFont("Arial", 11), XBrushes::Black, outBorderX - gfx->MeasureString("Version : 1.0", gcnew XFont("Arial", 11)).Width, 72);
	gfx->DrawString(String::Format("Date de facturation : {0}", commande->getDatePaiement()->ToShortDateString()), gcnew XFont("Arial", 11), XBrushes::Black, outBorderX - gfx->MeasureString(String::Format("Date de facturation : {0}", commande->getDatePaiement()->ToShortDateString()), gcnew XFont("Arial", 11)).Width, 98);
	gfx->DrawString(String::Format("R�f�rence client : {0}", client->getId().ToString("D9")), gcnew XFont("Arial", 11), XBrushes::Black, outBorderX - gfx->MeasureString(String::Format("R�f�rence client : {0}", client->getId().ToString("D9")), gcnew XFont("Arial", 11)).Width, 112);

	gfx->DrawRectangle(XBrushes::LightBlue, outBorderX - 260, 140, 260, 26);
	gfx->DrawString(String::Format("{0} {1}", client->getNom(), client->getPrenom()), gcnew XFont("Arial", 14, XFontStyle::Bold), XBrushes::Black, outBorderX - 260 + 4, 158);

	gfx->DrawRectangle(XBrushes::LightBlue, outBorderX - 260, 169, 260, 65);
	gfx->DrawString(String::Format("{0} {1}", client->getAdresseFacturation()->getNumero(), client->getAdresseFacturation()->getRue()), gcnew XFont("Arial", 13), XBrushes::Black, outBorderX - 260 + 4, 185);
	gfx->DrawString(String::Format("{0} {1}", client->getAdresseFacturation()->getVille()->getCodePostal(), client->getAdresseFacturation()->getVille()->getNom()), gcnew XFont("Arial", 13), XBrushes::Black, outBorderX - 260 + 4, 205);
	gfx->DrawString("France", gcnew XFont("Arial", 13), XBrushes::Black, outBorderX - 260 + 4, 225);


	int yPos = 270;
	gfx->DrawLine(XPens::Gray, borderX, yPos, outBorderX, yPos);
	gfx->DrawString("Description", gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, borderX, yPos += 15);
	gfx->DrawString("Prix Unit. HT", gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, borderX + 225, yPos += 3, XStringFormat::BottomCenter);
	gfx->DrawString("Quantit�", gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, borderX + 305, yPos, XStringFormat::BottomCenter);
	gfx->DrawString("Total HT", gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, borderX + 365, yPos, XStringFormat::BottomCenter);
	gfx->DrawString("TVA", gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, borderX + 423, yPos, XStringFormat::BottomCenter);
	gfx->DrawString("Remise", gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, borderX + 475, yPos, XStringFormat::BottomCenter);
	gfx->DrawString("Total TTC", gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, borderX + 533, yPos, XStringFormat::BottomCenter);
	gfx->DrawLine(XPens::Gray, borderX, yPos += 5, outBorderX, yPos);

	double totalTTC = 0;
	double totalHT = 0;

	yPos += 15;
	for each(ArticleMap ^ article in commande->getListeArticles())
	{
		gfx->DrawString(article->getNom(), gcnew XFont("Arial", 11), XBrushes::Black, borderX, yPos);
		gfx->DrawString(String::Format("{0} | {1}", article->getNature(), article->getCouleur()), gcnew XFont("Arial", 9), XBrushes::Black, borderX, yPos + 10);
		gfx->DrawString(String::Format("{0:0.00}�", article->getPrix()), gcnew XFont("Arial", 11), XBrushes::Black, borderX + 225, yPos, XStringFormat::BottomCenter);
		gfx->DrawString(article->getQuantite().ToString(), gcnew XFont("Arial", 11), XBrushes::Black, borderX + 305, yPos, XStringFormat::BottomCenter);
		gfx->DrawString(String::Format("{0:0.00}�", article->getQuantite() * article->getPrix()), gcnew XFont("Arial", 11), XBrushes::Black, borderX + 365, yPos, XStringFormat::BottomCenter);
		gfx->DrawString(String::Format("{0}%", article->getTaxe()), gcnew XFont("Arial", 11), XBrushes::Black, borderX + 423, yPos, XStringFormat::BottomCenter);
		gfx->DrawString(String::Format("{0}�", (article->getPrix() * article->getQuantite() * (article->getTaxe() / 100.0))), gcnew XFont("Arial", 9), XBrushes::Black, borderX + 423, yPos + 10, XStringFormat::BottomCenter);
		gfx->DrawString(String::Format("{0}%", article->getRemise()), gcnew XFont("Arial", 11), XBrushes::Black, borderX + 475, yPos, XStringFormat::BottomCenter);
		gfx->DrawString(String::Format("{0}�", (article->getQuantite() * article->getPrix() * (1 + article->getTaxe() / 100.0) * (article->getRemise() / 100.0))), gcnew XFont("Arial", 9), XBrushes::Black, borderX + 475, yPos + 10, XStringFormat::BottomCenter);
		gfx->DrawString(String::Format("{0:0.00}�", (article->getQuantite() * article->getPrix() * (1 + article->getTaxe() / 100.0) * (1 - article->getRemise() / 100.0))), gcnew XFont("Arial", 11), XBrushes::Black, borderX + 533, yPos, XStringFormat::BottomCenter);

		gfx->DrawLine(XPens::Gray, borderX, yPos += 15, outBorderX, yPos);
		yPos += 20;

		totalHT += article->getQuantite() * article->getPrix();
		totalTTC += article->getQuantite() * article->getPrix() * (1 + article->getTaxe() / 100.0) * (1 - article->getRemise() / 100.0);
	}

	gfx->DrawString(String::Format("Total HT : {0:0.00} �", totalHT), gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, outBorderX - gfx->MeasureString(String::Format("Total HT : {0:0.00} �", totalHT), gcnew XFont("Arial", 11, XFontStyle::Bold)).Width, yPos);
	gfx->DrawString(String::Format("Total TTC : {0:0.00} �", totalTTC), gcnew XFont("Arial", 11, XFontStyle::Bold), XBrushes::Black, outBorderX - gfx->MeasureString(String::Format("Total TTC : {0:0.00} �", totalTTC), gcnew XFont("Arial", 11, XFontStyle::Bold)).Width, yPos += 15);

	gfx->DrawLine(XPens::Gray, borderX, yPos += 15, outBorderX, yPos);

	gfx->DrawString("Net � Payer :", gcnew XFont("Arial", 14, XFontStyle::Bold), XBrushes::Black, outBorderX - gfx->MeasureString("Net � Payer :", gcnew XFont("Arial", 14, XFontStyle::Bold)).Width, yPos += 30);
	gfx->DrawString(String::Format("{0:0.00} �", totalTTC), gcnew XFont("Arial", 14, XFontStyle::Bold), XBrushes::Black, outBorderX - gfx->MeasureString(String::Format("{0:0.00} �", totalTTC), gcnew XFont("Arial", 14, XFontStyle::Bold)).Width, yPos += 20);

	gfx->DrawString(String::Format("Moyen de paiement : {0}", commande->getMoyenPaiement()), gcnew XFont("Arial", 11), XBrushes::Black, outBorderX - gfx->MeasureString(String::Format("Moyen de paiement : {0}", commande->getMoyenPaiement()), gcnew XFont("Arial", 11)).Width, yPos += 30);

	yPos = 790;
	gfx->DrawString("Les pr�sentes conditions g�n�rales de vente r�gissent les relations contractuelles", gcnew XFont("Arial", 10), XBrushes::Black, pageWidth / 2, yPos, XStringFormat::Center);
	gfx->DrawString("entre EVAL et son client, les deux parties les acceptant sans r�serve.", gcnew XFont("Arial", 10), XBrushes::Black, pageWidth / 2, yPos += 12, XStringFormat::Center);
	gfx->DrawString("Ces conditions g�n�rales de vente pr�vaudront sur toutes autres conditions", gcnew XFont("Arial", 10), XBrushes::Black, pageWidth / 2, yPos += 12, XStringFormat::Center);
	gfx->DrawString("g�n�rales ou particuli�res non express�ment agr��es par EVAL.", gcnew XFont("Arial", 10), XBrushes::Black, pageWidth / 2, yPos += 12, XStringFormat::Center);

	String^ documentName = String::Format("FACTURE-{0}_{1}-{2}.pdf", client->getNom(), client->getPrenom(), commande->getIdCommande());

	document->Save(documentName);

	System::Diagnostics::Process::Start(documentName);
}
System::Void ProjetPOO::Projet::clickOnFactureCommandeBouton(System::Object^ sender, System::EventArgs^ e)
{
	sqlHandler->generatePdfFacture(CommandeMap::from(this->idCommandeBox->Text));
}
Collections::ArrayList^ ProjetPOO::Projet::getArticlesCommande()
{
	return articlesCommande;
}
ProjetPOO::SqlMode ProjetPOO::Projet::getMode()
{
	return currentMode;
}
AdresseMap^ ProjetPOO::Projet::getPersonnelAdresse()
{
	return currentPersonnelAdresse;
}