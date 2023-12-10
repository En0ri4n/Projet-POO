#pragma once
#include "SqlHandler.h"
#include "Projet.h"

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
		ArticlePopup(ArrayList^ articles)
		{
			InitializeComponent();
			this->articles = articles;
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
	private: System::Windows::Forms::NumericUpDown^ remiseArticleBox;

	private: System::Windows::Forms::DataGridView^ listeArticlesVouluDataGridView;
	private: System::Windows::Forms::Label^ quantiteArticleLabel;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		ArrayList^ articles;
	private: System::Windows::Forms::NumericUpDown^ quantiteArticleBox;

	private: System::Windows::Forms::Label^ remiseArticleLabel;
	private: System::Windows::Forms::Button^ modifierArticleBouton;
	private:
		System::Windows::Forms::Button^ retirerArticleBouton;

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
			this->remiseArticleBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->listeArticlesVouluDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->quantiteArticleLabel = (gcnew System::Windows::Forms::Label());
			this->retirerArticleBouton = (gcnew System::Windows::Forms::Button());
			this->quantiteArticleBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->remiseArticleLabel = (gcnew System::Windows::Forms::Label());
			this->modifierArticleBouton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->articlesDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->remiseArticleBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->listeArticlesVouluDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quantiteArticleBox))->BeginInit();
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
			this->validerBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->validerBouton->ForeColor = System::Drawing::Color::Green;
			this->validerBouton->Location = System::Drawing::Point(715, 485);
			this->validerBouton->Name = L"validerBouton";
			this->validerBouton->Size = System::Drawing::Size(154, 41);
			this->validerBouton->TabIndex = 1;
			this->validerBouton->Text = L"Valider";
			this->validerBouton->UseVisualStyleBackColor = true;
			this->validerBouton->Click += gcnew System::EventHandler(this, &ArticlePopup::clickOnValider);
			// 
			// ajouterArticleBouton
			// 
			this->ajouterArticleBouton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ajouterArticleBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ajouterArticleBouton->Location = System::Drawing::Point(334, 493);
			this->ajouterArticleBouton->Name = L"ajouterArticleBouton";
			this->ajouterArticleBouton->Size = System::Drawing::Size(121, 27);
			this->ajouterArticleBouton->TabIndex = 2;
			this->ajouterArticleBouton->Text = L"Ajouter article";
			this->ajouterArticleBouton->UseVisualStyleBackColor = true;
			this->ajouterArticleBouton->Click += gcnew System::EventHandler(this, &ArticlePopup::clickOnAjouter);
			// 
			// remiseArticleBox
			// 
			this->remiseArticleBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->remiseArticleBox->Location = System::Drawing::Point(174, 493);
			this->remiseArticleBox->Name = L"remiseArticleBox";
			this->remiseArticleBox->Size = System::Drawing::Size(156, 27);
			this->remiseArticleBox->TabIndex = 3;
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
			this->listeArticlesVouluDataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ArticlePopup::clickOnCellPanier);
			// 
			// quantiteArticleLabel
			// 
			this->quantiteArticleLabel->AutoSize = true;
			this->quantiteArticleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->quantiteArticleLabel->Location = System::Drawing::Point(12, 470);
			this->quantiteArticleLabel->Name = L"quantiteArticleLabel";
			this->quantiteArticleLabel->Size = System::Drawing::Size(80, 20);
			this->quantiteArticleLabel->TabIndex = 5;
			this->quantiteArticleLabel->Text = L"Quantite :";
			// 
			// retirerArticleBouton
			// 
			this->retirerArticleBouton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->retirerArticleBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->retirerArticleBouton->Location = System::Drawing::Point(461, 494);
			this->retirerArticleBouton->Name = L"retirerArticleBouton";
			this->retirerArticleBouton->Size = System::Drawing::Size(121, 27);
			this->retirerArticleBouton->TabIndex = 6;
			this->retirerArticleBouton->Text = L"Retirer article";
			this->retirerArticleBouton->UseVisualStyleBackColor = true;
			this->retirerArticleBouton->Click += gcnew System::EventHandler(this, &ArticlePopup::clickOnRetirer);
			// 
			// quantiteArticleBox
			// 
			this->quantiteArticleBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->quantiteArticleBox->Location = System::Drawing::Point(12, 494);
			this->quantiteArticleBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			{
				1, 0, 0, 0
			});
			this->quantiteArticleBox->Name = L"quantiteArticleBox";
			this->quantiteArticleBox->Size = System::Drawing::Size(156, 27);
			this->quantiteArticleBox->TabIndex = 7;
			this->quantiteArticleBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4)
			{
				1, 0, 0, 0
			});
			// 
			// remiseArticleLabel
			// 
			this->remiseArticleLabel->AutoSize = true;
			this->remiseArticleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->remiseArticleLabel->Location = System::Drawing::Point(170, 470);
			this->remiseArticleLabel->Name = L"remiseArticleLabel";
			this->remiseArticleLabel->Size = System::Drawing::Size(97, 20);
			this->remiseArticleLabel->TabIndex = 8;
			this->remiseArticleLabel->Text = L"Remise (%) :";
			// 
			// modifierArticleBouton
			// 
			this->modifierArticleBouton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->modifierArticleBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->modifierArticleBouton->Location = System::Drawing::Point(588, 493);
			this->modifierArticleBouton->Name = L"modifierArticleBouton";
			this->modifierArticleBouton->Size = System::Drawing::Size(121, 27);
			this->modifierArticleBouton->TabIndex = 9;
			this->modifierArticleBouton->Text = L"Modifier article";
			this->modifierArticleBouton->UseVisualStyleBackColor = true;
			// 
			// ArticlePopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(881, 538);
			this->Controls->Add(this->modifierArticleBouton);
			this->Controls->Add(this->remiseArticleLabel);
			this->Controls->Add(this->quantiteArticleBox);
			this->Controls->Add(this->retirerArticleBouton);
			this->Controls->Add(this->quantiteArticleLabel);
			this->Controls->Add(this->listeArticlesVouluDataGridView);
			this->Controls->Add(this->remiseArticleBox);
			this->Controls->Add(this->ajouterArticleBouton);
			this->Controls->Add(this->validerBouton);
			this->Controls->Add(this->articlesDataGridView);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ArticlePopup";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Articles";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ArticlePopup::OnFormLoad);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->articlesDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->remiseArticleBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->listeArticlesVouluDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quantiteArticleBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private:
		System::Void OnFormLoad(System::Object^ sender, System::EventArgs^ e);
		System::Void clickOnAjouter(System::Object^ sender, System::EventArgs^ e);
		System::Void clickOnRetirer(System::Object^ sender, System::EventArgs^ e);
		System::Void clickOnCell(System::Object^, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void clickOnValider(System::Object^ sender, System::EventArgs^ e);
		System::Void addColumns();
		System::Void clickOnCellPanier(System::Object^, System::Windows::Forms::DataGridViewCellEventArgs^ e);

};
}
#pragma endregion
