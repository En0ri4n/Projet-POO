#pragma once
#include "SqlHandler.h"
#include "ArticleMap.h"

using namespace ProjetPOO;


namespace ProjetPOO
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ArticlePopup
	/// </summary>
	public ref class ArticlePopup : public System::Windows::Forms::Form
	{
	public:
		ArticlePopup(/*ProjetPOO::Projet^ parent*/)
		{
			InitializeComponent();
			// this->parentWindow = parent;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ArticlePopup()
		{
			if(components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ articlesDataGridView;
	protected:


	private: System::Windows::Forms::Button^ validerBouton;
	private: System::Windows::Forms::Button^ ajouterArticleBouton;
	private: System::Windows::Forms::NumericUpDown^ quantiteArticleBox;
	private: System::Windows::Forms::DataGridView^ listeArticlesVouluDataGridView;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	private:
		System::Windows::Forms::Button^ retirerArticleBouton;
		// ProjetPOO::Projet^ parentWindow;
		DataGridViewRow^ row;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->articlesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->validerBouton = (gcnew System::Windows::Forms::Button());
			this->ajouterArticleBouton = (gcnew System::Windows::Forms::Button());
			this->quantiteArticleBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->listeArticlesVouluDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->retirerArticleBouton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->articlesDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quantiteArticleBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->listeArticlesVouluDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// articlesDataGridView
			// 
			this->articlesDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->articlesDataGridView->Location = System::Drawing::Point(12, 12);
			this->articlesDataGridView->MultiSelect = false;
			this->articlesDataGridView->Name = L"articlesDataGridView";
			this->articlesDataGridView->ReadOnly = true;
			this->articlesDataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->articlesDataGridView->Size = System::Drawing::Size(857, 285);
			this->articlesDataGridView->TabIndex = 0;
			this->articlesDataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ArticlePopup::clickOnCell);
			// 
			// validerBouton
			// 
			this->validerBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->validerBouton->Location = System::Drawing::Point(690, 484);
			this->validerBouton->Name = L"validerBouton";
			this->validerBouton->Size = System::Drawing::Size(179, 42);
			this->validerBouton->TabIndex = 1;
			this->validerBouton->Text = L"Valider";
			this->validerBouton->UseVisualStyleBackColor = true;
			this->validerBouton->Click += gcnew System::EventHandler(this, &ArticlePopup::clickOnValider);
			// 
			// ajouterArticleBouton
			// 
			this->ajouterArticleBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ajouterArticleBouton->Location = System::Drawing::Point(334, 487);
			this->ajouterArticleBouton->Name = L"ajouterArticleBouton";
			this->ajouterArticleBouton->Size = System::Drawing::Size(172, 33);
			this->ajouterArticleBouton->TabIndex = 2;
			this->ajouterArticleBouton->Text = L"Ajouter article";
			this->ajouterArticleBouton->UseVisualStyleBackColor = true;
			this->ajouterArticleBouton->Click += gcnew System::EventHandler(this, &ArticlePopup::clickOnAjouter);
			// 
			// quantiteArticleBox
			// 
			this->quantiteArticleBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->quantiteArticleBox->Location = System::Drawing::Point(208, 492);
			this->quantiteArticleBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			{
				1, 0, 0, 0
			});
			this->quantiteArticleBox->Name = L"quantiteArticleBox";
			this->quantiteArticleBox->Size = System::Drawing::Size(120, 24);
			this->quantiteArticleBox->TabIndex = 3;
			this->quantiteArticleBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4)
			{
				1, 0, 0, 0
			});
			// 
			// listeArticlesVouluDataGridView
			// 
			this->listeArticlesVouluDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->listeArticlesVouluDataGridView->Location = System::Drawing::Point(12, 303);
			this->listeArticlesVouluDataGridView->Name = L"listeArticlesVouluDataGridView";
			this->listeArticlesVouluDataGridView->ReadOnly = true;
			this->listeArticlesVouluDataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->listeArticlesVouluDataGridView->Size = System::Drawing::Size(857, 164);
			this->listeArticlesVouluDataGridView->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(61, 498);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// retirerArticleBouton
			// 
			this->retirerArticleBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->retirerArticleBouton->Location = System::Drawing::Point(512, 487);
			this->retirerArticleBouton->Name = L"retirerArticleBouton";
			this->retirerArticleBouton->Size = System::Drawing::Size(172, 33);
			this->retirerArticleBouton->TabIndex = 6;
			this->retirerArticleBouton->Text = L"Retirer article";
			this->retirerArticleBouton->UseVisualStyleBackColor = true;
			this->retirerArticleBouton->Click += gcnew System::EventHandler(this, &ArticlePopup::clickOnRetirer);
			// 
			// ArticlePopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(881, 538);
			this->Controls->Add(this->retirerArticleBouton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listeArticlesVouluDataGridView);
			this->Controls->Add(this->quantiteArticleBox);
			this->Controls->Add(this->ajouterArticleBouton);
			this->Controls->Add(this->validerBouton);
			this->Controls->Add(this->articlesDataGridView);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ArticlePopup";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"ArticlePopup";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ArticlePopup::OnFormLoad);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->articlesDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quantiteArticleBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->listeArticlesVouluDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private:
		ArrayList^ articles = gcnew ArrayList;
	private: System::Void OnFormLoad(System::Object^ sender, System::EventArgs^ e)
	{
		SqlHandler::fillGrid(Table::ARTICLES, articlesDataGridView);
		
		listeArticlesVouluDataGridView->Columns->Add("reference", "Reference");
		listeArticlesVouluDataGridView->Columns->Add("nom", "Nom");
		listeArticlesVouluDataGridView->Columns->Add("prix", "Prix");
		listeArticlesVouluDataGridView->Columns->Add("couleur", "Couleur");
		listeArticlesVouluDataGridView->Columns->Add("quantite", "Quantite");
		listeArticlesVouluDataGridView->Columns->Add("total", "Total");
	}
	private: System::Void clickOnAjouter(System::Object^ sender, System::EventArgs^ e)
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
			double total = prix * quantite;
			listeArticlesVouluDataGridView->Rows->Add(reference, nom, prix, couleur, quantite, total);
			
			articles->Add(ArticleMap::from(reference));
		}
	}
	private: System::Void clickOnRetirer(System::Object^ sender, System::EventArgs^ e)
	{
		if(this->listeArticlesVouluDataGridView->Rows->Count > 0)
		{
			for each(DataGridViewRow ^ row in this->listeArticlesVouluDataGridView->SelectedRows)
			{
				this->listeArticlesVouluDataGridView->Rows->Remove(row);
				articles->Remove(ArticleMap::from(row->Cells["reference"]->Value->ToString()));
			}
		}
	}
	private: System::Void clickOnCell(System::Object^, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if(e->RowIndex >= 0)
		{
			this->quantiteArticleBox->Maximum = Convert::ToInt32(this->articlesDataGridView->Rows[e->RowIndex]->Cells[6]->Value);
		}
	}
	private: System::Void clickOnValider(System::Object^ sender, System::EventArgs^ e)
	{
		//Projet::instance->updateAriclesCommande(articles);
		this->Close();
	}
};
}
#pragma endregion