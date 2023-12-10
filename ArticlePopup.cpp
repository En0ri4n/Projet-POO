#include "ArticlePopup.h"
#include "ArticleMap.h"
#include "Projet.h"

System::Void ProjetPOO::ArticlePopup::OnFormLoad(System::Object^ sender, System::EventArgs^ e)
{
	SqlHandler::fillGrid(Table::ARTICLES, articlesDataGridView);

	addColumns();

	for each(ArticleMap^ article in articles)
	{
		String^ reference = article->getIdArticle();
		String^ nom = article->getNom();
		String^ couleur = article->getCouleur();
		int taxe = article->getTaxe();
		double prix = article->getPrix();
		prix += prix * taxe / 100.0;
		int quantite = article->getQuantite() <= 0 ? 0 : article->getQuantite();
		double total = prix * quantite;
		int remise = article->getRemise();
		total *= 1 - remise / 100.0;
		listeArticlesVouluDataGridView->Rows->Add(reference, nom, prix, couleur, quantite, remise, total);
	}

	bool active = Projet::instance->getMode() == SqlMode::AFFICHER || Projet::instance->getMode() == SqlMode::SUPPRIMER;

	this->ajouterArticleBouton->Enabled = !active;
	this->retirerArticleBouton->Enabled = false;
	this->quantiteArticleLabel->Enabled = !active;
	this->quantiteArticleBox->Enabled = !active;
	this->remiseArticleLabel->Enabled = !active;
	this->remiseArticleBox->Enabled = !active;
}
System::Void ProjetPOO::ArticlePopup::clickOnAjouter(System::Object^ sender, System::EventArgs^ e)
{
	if(this->articlesDataGridView->SelectedRows->Count > 0)
	{
		DataGridViewRow^ row = this->articlesDataGridView->SelectedRows[0];
		String^ reference = row->Cells[0]->Value->ToString();
		String^ nom = row->Cells[1]->Value->ToString();
		double prix = Convert::ToDouble(row->Cells[2]->Value);
		String^ nature = row->Cells[3]->Value->ToString();
		String^ couleur = row->Cells[4]->Value->ToString();
		int seuil = Convert::ToInt32(row->Cells[5]->Value);
		int taxe = Convert::ToInt32(row->Cells[7]->Value);
		int quantite = Convert::ToInt32(this->quantiteArticleBox->Value);
		int remise = Convert::ToInt32(this->remiseArticleBox->Value);
		double total = prix * quantite;
		total *= 1 - remise / 100.0;
		listeArticlesVouluDataGridView->Rows->Add(reference, nom, prix * taxe / 100.0 + prix, couleur, quantite, remise, total);

		articles->Add(gcnew ArticleMap(reference, nom, prix, row->Cells[3]->Value->ToString(), row->Cells[4]->Value->ToString(), Convert::ToInt32(row->Cells[5]->Value), Convert::ToInt32(this->quantiteArticleBox->Value), taxe, Convert::ToInt32(this->remiseArticleBox->Value)));
	}
}
System::Void ProjetPOO::ArticlePopup::clickOnRetirer(System::Object^ sender, System::EventArgs^ e)
{
	if(this->listeArticlesVouluDataGridView->Rows->Count > 0)
	{
		for each(DataGridViewRow ^ row in this->listeArticlesVouluDataGridView->SelectedRows)
		{
			this->listeArticlesVouluDataGridView->Rows->Remove(row);
			for(int i = 0; i < articles->Count; i++)
				if(((ArticleMap^) articles[i])->getIdArticle() == row->Cells[0]->Value->ToString())
				{
					articles->RemoveAt(i);
					break;
				}
		}
	}
}
System::Void ProjetPOO::ArticlePopup::clickOnCell(System::Object^, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if(e->RowIndex >= 0)
	{
		try
		{
			int quantite = Convert::ToInt32(this->articlesDataGridView->Rows[e->RowIndex]->Cells[6]->Value);
			this->quantiteArticleBox->Maximum = quantite;

			bool active = Projet::instance->getMode() == SqlMode::AFFICHER || Projet::instance->getMode() == SqlMode::SUPPRIMER;

			if(active)
				return;

			if(quantite <= 0)
			{
				this->remiseArticleBox->Enabled = false;
				this->remiseArticleLabel->Enabled = false;
				this->quantiteArticleBox->Enabled = false;
				this->ajouterArticleBouton->Enabled = false;
			}
			else
			{
				this->remiseArticleBox->Enabled = true;
				this->remiseArticleLabel->Enabled = true;
				this->quantiteArticleBox->Enabled = true;
				this->ajouterArticleBouton->Enabled = true;
			}
		}
		catch(System::Exception^ e)
		{
			this->quantiteArticleBox->Maximum = 0;
		}
	}
}
System::Void ProjetPOO::ArticlePopup::clickOnValider(System::Object^ sender, System::EventArgs^ e)
{
	Projet::instance->updateArticlesCommande(articles);
	this->Close();
}
System::Void ProjetPOO::ArticlePopup::addColumns()
{
	if(listeArticlesVouluDataGridView->Columns->Count > 0)
		return;

	listeArticlesVouluDataGridView->Columns->Add("reference", "Reference");
	listeArticlesVouluDataGridView->Columns->Add("nom", "Nom");
	listeArticlesVouluDataGridView->Columns->Add("prix", "Prix TTC");
	listeArticlesVouluDataGridView->Columns->Add("couleur", "Couleur");
	listeArticlesVouluDataGridView->Columns->Add("quantite", "Quantite");
	listeArticlesVouluDataGridView->Columns->Add("remise", "Remise");
	listeArticlesVouluDataGridView->Columns->Add("total", "Total TTC Remise");
}

System::Void ProjetPOO::ArticlePopup::clickOnCellPanier(System::Object^, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	bool active = Projet::instance->getMode() == SqlMode::AFFICHER || Projet::instance->getMode() == SqlMode::SUPPRIMER;

	if(active)
		return;

	bool active1 = listeArticlesVouluDataGridView->SelectedRows->Count > 0;
	this->retirerArticleBouton->Enabled = active1;
}
