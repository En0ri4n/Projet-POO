#include "ArticlePopup.h"
#include "ArticleMap.h"
#include "Projet.h"

System::Void ProjetPOO::ArticlePopup::OnFormLoad(System::Object^ sender, System::EventArgs^ e)
{
	SqlHandler::fillGrid(Table::ARTICLES, articlesDataGridView);

	addColumns();

	for each(DataGridViewRow ^ row in this->articlesDataGridView->Rows)
	{
		if(row->Cells[0]->Value == nullptr)
			continue;

		if(articles->Count > 0)
			label1->Text = ((ArticleMap^) articles[0])->getIdArticle();

		if(ArticleMap::isInList(row->Cells[0]->Value->ToString(), articles))
		{
			String^ reference = row->Cells[0]->Value->ToString();
			String^ nom = row->Cells[1]->Value->ToString();
			String^ couleur = row->Cells[4]->Value->ToString();
			int taxe = Convert::ToInt32(row->Cells[7]->Value);
			double prix = Convert::ToDouble(row->Cells[2]->Value);
			prix += prix * taxe / 100.0;
			int quantite = ArticleMap::byId(reference, articles)->getQuantite();
			double total = prix * quantite;
			listeArticlesVouluDataGridView->Rows->Add(reference, nom, prix, couleur, quantite, total);
		}
	}
}
System::Void ProjetPOO::ArticlePopup::clickOnAjouter(System::Object^ sender, System::EventArgs^ e)
{
	if(this->articlesDataGridView->SelectedRows->Count > 0)
	{
		DataGridViewRow^ row = this->articlesDataGridView->SelectedRows[0];
		String^ reference = row->Cells[0]->Value->ToString();
		String^ nom = row->Cells[1]->Value->ToString();
		String^ couleur = row->Cells[4]->Value->ToString();
		int taxe = Convert::ToInt32(row->Cells[7]->Value);
		double prix = Convert::ToDouble(row->Cells[2]->Value);
		prix += prix * taxe / 100.0;
		int quantite = Convert::ToInt32(this->quantiteArticleBox->Value);
		int remise = 0;
		double total = prix * quantite;
		listeArticlesVouluDataGridView->Rows->Add(reference, nom, prix, couleur, quantite, remise, total);

		articles->Add(ArticleMap::from(reference, quantite, remise));
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
				if(((ArticleMap^) articles[i])->getIdArticle() == row->Cells["reference"]->Value->ToString())
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
		this->quantiteArticleBox->Maximum = Convert::ToInt32(this->articlesDataGridView->Rows[e->RowIndex]->Cells[6]->Value);
	}
}
System::Void ProjetPOO::ArticlePopup::clickOnValider(System::Object^ sender, System::EventArgs^ e)
{
	Projet::instance->updateArticlesCommande(articles);
	this->Close();
}

System::Void ProjetPOO::ArticlePopup::onRowAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e)
{
}

System::Void ProjetPOO::ArticlePopup::addColumns()
{
	if(listeArticlesVouluDataGridView->Columns->Count > 0)
		return;

	listeArticlesVouluDataGridView->Columns->Add("reference", "Reference");
	listeArticlesVouluDataGridView->Columns->Add("nom", "Nom");
	listeArticlesVouluDataGridView->Columns->Add("prix", "Prix");
	listeArticlesVouluDataGridView->Columns->Add("couleur", "Couleur");
	listeArticlesVouluDataGridView->Columns->Add("quantite", "Quantite");
	listeArticlesVouluDataGridView->Columns->Add("remise", "Remise");
	listeArticlesVouluDataGridView->Columns->Add("total", "Total");
}
