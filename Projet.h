#pragma once

namespace ProjetPOO
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public enum SqlMode
	{
		AFFICHER,
		SUPPRIMER,
		AJOUTER,
		MODIFIER
	};

	/// <summary>
	/// Summary for Projet
	/// </summary>
	public ref class Projet : public System::Windows::Forms::Form
	{
	public:
		Projet(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Projet()
		{
			if(components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::RichTextBox^ historiqueBox;
	private: System::Windows::Forms::Label^ historiqueLabel;


	private: System::Windows::Forms::Button^ boutonAfficher;
	private: System::Windows::Forms::Button^ boutonSupprimer;
	private: System::Windows::Forms::Button^ boutonModifier;
	private: System::Windows::Forms::Button^ boutonAjouter;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::TabPage^ tabStatistiques;
	private: System::Windows::Forms::TabPage^ tabClients;
	private: System::Windows::Forms::TabPage^ tabCommandes;
	private: System::Windows::Forms::TabPage^ tabStocks;
	private: System::Windows::Forms::TabPage^ tabPersonnel;
	private: System::Windows::Forms::NumericUpDown^ idPersonnelBox;
	private: System::Windows::Forms::Button^ boutonValider;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabPage^ tabAccueil;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::TextBox^ passwordBox;
	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ welcomeTitleLabel;
	private: System::Windows::Forms::TabControl^ tabController;
	private: System::Windows::Forms::Label^ dateEmbauchePersonnelLabel;
	private: System::Windows::Forms::DateTimePicker^ dateEmbauchePersonnelPicker;
	private: System::Windows::Forms::Label^ prenomPersonnelLabel;
	private: System::Windows::Forms::TextBox^ prenomPersonnelBox;
	private: System::Windows::Forms::Label^ nomPersonnelLabel;
	private: System::Windows::Forms::Label^ idPersonnelLabel;
	private: System::Windows::Forms::TextBox^ nomPersonnelBox;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		bool connected;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ prixStockBox;

	private: System::Windows::Forms::TextBox^ nomStockBox;

	private: System::Windows::Forms::Label^ prixStockLabel;

	private: System::Windows::Forms::Label^ nomStockLabel;

	private: System::Windows::Forms::Label^ idStockLabel;

	private: System::Windows::Forms::TextBox^ idStockBox;
	private: System::Windows::Forms::Label^ quantiteStockLabel;
	private: System::Windows::Forms::Label^ seuilStockLabel;
	private: System::Windows::Forms::Label^ couleurStockLabel;



	private: System::Windows::Forms::Label^ natureStockLabel;
	private: System::Windows::Forms::NumericUpDown^ quantiteStockBox;

	private: System::Windows::Forms::NumericUpDown^ seuilStockBox;

	private: System::Windows::Forms::TextBox^ couleurStockBox;

	private: System::Windows::Forms::TextBox^ natureStockBox;
	private: System::Windows::Forms::Label^ commandesLabel;
	private: System::Windows::Forms::ComboBox^ comboBox1;






		   SqlMode currentMode;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Projet::typeid));
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->boutonAfficher = (gcnew System::Windows::Forms::Button());
			this->boutonSupprimer = (gcnew System::Windows::Forms::Button());
			this->boutonModifier = (gcnew System::Windows::Forms::Button());
			this->boutonAjouter = (gcnew System::Windows::Forms::Button());
			this->historiqueBox = (gcnew System::Windows::Forms::RichTextBox());
			this->historiqueLabel = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabStatistiques = (gcnew System::Windows::Forms::TabPage());
			this->tabClients = (gcnew System::Windows::Forms::TabPage());
			this->tabCommandes = (gcnew System::Windows::Forms::TabPage());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->commandesLabel = (gcnew System::Windows::Forms::Label());
			this->tabStocks = (gcnew System::Windows::Forms::TabPage());
			this->quantiteStockLabel = (gcnew System::Windows::Forms::Label());
			this->seuilStockLabel = (gcnew System::Windows::Forms::Label());
			this->couleurStockLabel = (gcnew System::Windows::Forms::Label());
			this->natureStockLabel = (gcnew System::Windows::Forms::Label());
			this->quantiteStockBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->seuilStockBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->couleurStockBox = (gcnew System::Windows::Forms::TextBox());
			this->natureStockBox = (gcnew System::Windows::Forms::TextBox());
			this->prixStockBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->nomStockBox = (gcnew System::Windows::Forms::TextBox());
			this->prixStockLabel = (gcnew System::Windows::Forms::Label());
			this->nomStockLabel = (gcnew System::Windows::Forms::Label());
			this->idStockLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->idStockBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPersonnel = (gcnew System::Windows::Forms::TabPage());
			this->dateEmbauchePersonnelLabel = (gcnew System::Windows::Forms::Label());
			this->dateEmbauchePersonnelPicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->prenomPersonnelLabel = (gcnew System::Windows::Forms::Label());
			this->prenomPersonnelBox = (gcnew System::Windows::Forms::TextBox());
			this->nomPersonnelLabel = (gcnew System::Windows::Forms::Label());
			this->idPersonnelLabel = (gcnew System::Windows::Forms::Label());
			this->nomPersonnelBox = (gcnew System::Windows::Forms::TextBox());
			this->idPersonnelBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->boutonValider = (gcnew System::Windows::Forms::Button());
			this->tabAccueil = (gcnew System::Windows::Forms::TabPage());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->welcomeTitleLabel = (gcnew System::Windows::Forms::Label());
			this->tabController = (gcnew System::Windows::Forms::TabControl());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->tabCommandes->SuspendLayout();
			this->tabStocks->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quantiteStockBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seuilStockBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prixStockBox))->BeginInit();
			this->tabPersonnel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idPersonnelBox))->BeginInit();
			this->tabAccueil->SuspendLayout();
			this->tabController->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToOrderColumns = true;
			this->dataGridView->BackgroundColor = System::Drawing::SystemColors::ActiveBorder;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2)
			{
				this->Name, this->id
			});
			this->dataGridView->GridColor = System::Drawing::SystemColors::ActiveBorder;
			this->dataGridView->Location = System::Drawing::Point(582, 12);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->Size = System::Drawing::Size(657, 548);
			this->dataGridView->TabIndex = 3;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Projet";
			this->Name->Name = L"Name";
			this->Name->ReadOnly = true;
			// 
			// id
			// 
			this->id->HeaderText = L"Id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			// 
			// boutonAfficher
			// 
			this->boutonAfficher->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boutonAfficher->Location = System::Drawing::Point(16, 397);
			this->boutonAfficher->Name = L"boutonAfficher";
			this->boutonAfficher->Size = System::Drawing::Size(123, 47);
			this->boutonAfficher->TabIndex = 8;
			this->boutonAfficher->Text = L"Afficher";
			this->boutonAfficher->UseVisualStyleBackColor = true;
			this->boutonAfficher->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonAfficher);
			// 
			// boutonSupprimer
			// 
			this->boutonSupprimer->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boutonSupprimer->Location = System::Drawing::Point(145, 397);
			this->boutonSupprimer->Name = L"boutonSupprimer";
			this->boutonSupprimer->Size = System::Drawing::Size(131, 47);
			this->boutonSupprimer->TabIndex = 7;
			this->boutonSupprimer->Text = L"Supprimer";
			this->boutonSupprimer->UseVisualStyleBackColor = true;
			this->boutonSupprimer->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonSupprimer);
			// 
			// boutonModifier
			// 
			this->boutonModifier->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boutonModifier->Location = System::Drawing::Point(430, 397);
			this->boutonModifier->Name = L"boutonModifier";
			this->boutonModifier->Size = System::Drawing::Size(142, 47);
			this->boutonModifier->TabIndex = 6;
			this->boutonModifier->Text = L"Modifier";
			this->boutonModifier->UseVisualStyleBackColor = true;
			this->boutonModifier->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonModifier);
			// 
			// boutonAjouter
			// 
			this->boutonAjouter->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boutonAjouter->Location = System::Drawing::Point(282, 397);
			this->boutonAjouter->Name = L"boutonAjouter";
			this->boutonAjouter->Size = System::Drawing::Size(142, 47);
			this->boutonAjouter->TabIndex = 5;
			this->boutonAjouter->Text = L"Ajouter";
			this->boutonAjouter->UseVisualStyleBackColor = true;
			this->boutonAjouter->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonAjouter);
			// 
			// historiqueBox
			// 
			this->historiqueBox->Location = System::Drawing::Point(16, 464);
			this->historiqueBox->Name = L"historiqueBox";
			this->historiqueBox->ReadOnly = true;
			this->historiqueBox->Size = System::Drawing::Size(552, 96);
			this->historiqueBox->TabIndex = 5;
			this->historiqueBox->Text = L"";
			// 
			// historiqueLabel
			// 
			this->historiqueLabel->AutoSize = true;
			this->historiqueLabel->Font = (gcnew System::Drawing::Font(L"Minecraft", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->historiqueLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->historiqueLabel->Location = System::Drawing::Point(16, 448);
			this->historiqueLabel->Name = L"historiqueLabel";
			this->historiqueLabel->Size = System::Drawing::Size(73, 11);
			this->historiqueLabel->TabIndex = 6;
			this->historiqueLabel->Text = L"Historique";
			// 
			// tabStatistiques
			// 
			this->tabStatistiques->Location = System::Drawing::Point(4, 22);
			this->tabStatistiques->Name = L"tabStatistiques";
			this->tabStatistiques->Size = System::Drawing::Size(556, 307);
			this->tabStatistiques->TabIndex = 5;
			this->tabStatistiques->Text = L"Statistiques";
			this->tabStatistiques->UseVisualStyleBackColor = true;
			// 
			// tabClients
			// 
			this->tabClients->Location = System::Drawing::Point(4, 22);
			this->tabClients->Name = L"tabClients";
			this->tabClients->Size = System::Drawing::Size(556, 307);
			this->tabClients->TabIndex = 4;
			this->tabClients->Text = L"Clients";
			this->tabClients->UseVisualStyleBackColor = true;
			// 
			// tabCommandes
			// 
			this->tabCommandes->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->tabCommandes->Controls->Add(this->comboBox1);
			this->tabCommandes->Controls->Add(this->commandesLabel);
			this->tabCommandes->Location = System::Drawing::Point(4, 22);
			this->tabCommandes->Name = L"tabCommandes";
			this->tabCommandes->Size = System::Drawing::Size(556, 307);
			this->tabCommandes->TabIndex = 3;
			this->tabCommandes->Text = L"Commandes";
			this->tabCommandes->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8)
			{
				L"a", L"b", L"c", L"d", L"e", L"f", L"g", L"h"
			});
			this->comboBox1->Location = System::Drawing::Point(303, 216);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 28;
			// 
			// commandesLabel
			// 
			this->commandesLabel->AutoSize = true;
			this->commandesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->commandesLabel->Location = System::Drawing::Point(182, 3);
			this->commandesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->commandesLabel->Name = L"commandesLabel";
			this->commandesLabel->Size = System::Drawing::Size(218, 42);
			this->commandesLabel->TabIndex = 26;
			this->commandesLabel->Text = L"Commandes";
			// 
			// tabStocks
			// 
			this->tabStocks->Controls->Add(this->quantiteStockLabel);
			this->tabStocks->Controls->Add(this->seuilStockLabel);
			this->tabStocks->Controls->Add(this->couleurStockLabel);
			this->tabStocks->Controls->Add(this->natureStockLabel);
			this->tabStocks->Controls->Add(this->quantiteStockBox);
			this->tabStocks->Controls->Add(this->seuilStockBox);
			this->tabStocks->Controls->Add(this->couleurStockBox);
			this->tabStocks->Controls->Add(this->natureStockBox);
			this->tabStocks->Controls->Add(this->prixStockBox);
			this->tabStocks->Controls->Add(this->nomStockBox);
			this->tabStocks->Controls->Add(this->prixStockLabel);
			this->tabStocks->Controls->Add(this->nomStockLabel);
			this->tabStocks->Controls->Add(this->idStockLabel);
			this->tabStocks->Controls->Add(this->label2);
			this->tabStocks->Controls->Add(this->idStockBox);
			this->tabStocks->Location = System::Drawing::Point(4, 22);
			this->tabStocks->Name = L"tabStocks";
			this->tabStocks->Size = System::Drawing::Size(556, 307);
			this->tabStocks->TabIndex = 2;
			this->tabStocks->Text = L"Stocks";
			this->tabStocks->UseVisualStyleBackColor = true;
			// 
			// quantiteStockLabel
			// 
			this->quantiteStockLabel->AutoSize = true;
			this->quantiteStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->quantiteStockLabel->Location = System::Drawing::Point(80, 258);
			this->quantiteStockLabel->Name = L"quantiteStockLabel";
			this->quantiteStockLabel->Size = System::Drawing::Size(80, 20);
			this->quantiteStockLabel->TabIndex = 25;
			this->quantiteStockLabel->Text = L"Quantité :";
			// 
			// seuilStockLabel
			// 
			this->seuilStockLabel->AutoSize = true;
			this->seuilStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seuilStockLabel->Location = System::Drawing::Point(67, 226);
			this->seuilStockLabel->Name = L"seuilStockLabel";
			this->seuilStockLabel->Size = System::Drawing::Size(93, 20);
			this->seuilStockLabel->TabIndex = 24;
			this->seuilStockLabel->Text = L"Seuil réap. :";
			// 
			// couleurStockLabel
			// 
			this->couleurStockLabel->AutoSize = true;
			this->couleurStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->couleurStockLabel->Location = System::Drawing::Point(86, 194);
			this->couleurStockLabel->Name = L"couleurStockLabel";
			this->couleurStockLabel->Size = System::Drawing::Size(74, 20);
			this->couleurStockLabel->TabIndex = 23;
			this->couleurStockLabel->Text = L"Couleur :";
			// 
			// natureStockLabel
			// 
			this->natureStockLabel->AutoSize = true;
			this->natureStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->natureStockLabel->Location = System::Drawing::Point(93, 161);
			this->natureStockLabel->Name = L"natureStockLabel";
			this->natureStockLabel->Size = System::Drawing::Size(67, 20);
			this->natureStockLabel->TabIndex = 22;
			this->natureStockLabel->Text = L"Nature :";
			// 
			// quantiteStockBox
			// 
			this->quantiteStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quantiteStockBox->Location = System::Drawing::Point(182, 256);
			this->quantiteStockBox->Name = L"quantiteStockBox";
			this->quantiteStockBox->Size = System::Drawing::Size(324, 27);
			this->quantiteStockBox->TabIndex = 21;
			// 
			// seuilStockBox
			// 
			this->seuilStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seuilStockBox->Location = System::Drawing::Point(182, 224);
			this->seuilStockBox->Name = L"seuilStockBox";
			this->seuilStockBox->Size = System::Drawing::Size(324, 27);
			this->seuilStockBox->TabIndex = 20;
			// 
			// couleurStockBox
			// 
			this->couleurStockBox->BackColor = System::Drawing::SystemColors::Window;
			this->couleurStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->couleurStockBox->Location = System::Drawing::Point(182, 191);
			this->couleurStockBox->Name = L"couleurStockBox";
			this->couleurStockBox->Size = System::Drawing::Size(324, 27);
			this->couleurStockBox->TabIndex = 19;
			// 
			// natureStockBox
			// 
			this->natureStockBox->BackColor = System::Drawing::SystemColors::Window;
			this->natureStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->natureStockBox->Location = System::Drawing::Point(182, 158);
			this->natureStockBox->Name = L"natureStockBox";
			this->natureStockBox->Size = System::Drawing::Size(324, 27);
			this->natureStockBox->TabIndex = 18;
			// 
			// prixStockBox
			// 
			this->prixStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->prixStockBox->Location = System::Drawing::Point(182, 125);
			this->prixStockBox->Name = L"prixStockBox";
			this->prixStockBox->Size = System::Drawing::Size(324, 27);
			this->prixStockBox->TabIndex = 17;
			// 
			// nomStockBox
			// 
			this->nomStockBox->BackColor = System::Drawing::SystemColors::Window;
			this->nomStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nomStockBox->Location = System::Drawing::Point(182, 92);
			this->nomStockBox->Name = L"nomStockBox";
			this->nomStockBox->Size = System::Drawing::Size(324, 27);
			this->nomStockBox->TabIndex = 16;
			// 
			// prixStockLabel
			// 
			this->prixStockLabel->AutoSize = true;
			this->prixStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->prixStockLabel->Location = System::Drawing::Point(116, 126);
			this->prixStockLabel->Name = L"prixStockLabel";
			this->prixStockLabel->Size = System::Drawing::Size(44, 20);
			this->prixStockLabel->TabIndex = 15;
			this->prixStockLabel->Text = L"Prix :";
			// 
			// nomStockLabel
			// 
			this->nomStockLabel->AutoSize = true;
			this->nomStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nomStockLabel->Location = System::Drawing::Point(107, 94);
			this->nomStockLabel->Name = L"nomStockLabel";
			this->nomStockLabel->Size = System::Drawing::Size(53, 20);
			this->nomStockLabel->TabIndex = 14;
			this->nomStockLabel->Text = L"Nom :";
			// 
			// idStockLabel
			// 
			this->idStockLabel->AutoSize = true;
			this->idStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idStockLabel->Location = System::Drawing::Point(128, 60);
			this->idStockLabel->Name = L"idStockLabel";
			this->idStockLabel->Size = System::Drawing::Size(32, 20);
			this->idStockLabel->TabIndex = 13;
			this->idStockLabel->Text = L"ID :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(225, 4);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 42);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Stocks";
			// 
			// idStockBox
			// 
			this->idStockBox->BackColor = System::Drawing::SystemColors::Window;
			this->idStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idStockBox->Location = System::Drawing::Point(182, 59);
			this->idStockBox->Name = L"idStockBox";
			this->idStockBox->Size = System::Drawing::Size(324, 27);
			this->idStockBox->TabIndex = 12;
			// 
			// tabPersonnel
			// 
			this->tabPersonnel->Controls->Add(this->dateEmbauchePersonnelLabel);
			this->tabPersonnel->Controls->Add(this->dateEmbauchePersonnelPicker);
			this->tabPersonnel->Controls->Add(this->prenomPersonnelLabel);
			this->tabPersonnel->Controls->Add(this->prenomPersonnelBox);
			this->tabPersonnel->Controls->Add(this->nomPersonnelLabel);
			this->tabPersonnel->Controls->Add(this->idPersonnelLabel);
			this->tabPersonnel->Controls->Add(this->nomPersonnelBox);
			this->tabPersonnel->Controls->Add(this->idPersonnelBox);
			this->tabPersonnel->Controls->Add(this->label1);
			this->tabPersonnel->Location = System::Drawing::Point(4, 22);
			this->tabPersonnel->Name = L"tabPersonnel";
			this->tabPersonnel->Padding = System::Windows::Forms::Padding(3);
			this->tabPersonnel->Size = System::Drawing::Size(556, 307);
			this->tabPersonnel->TabIndex = 1;
			this->tabPersonnel->Text = L"Personnel";
			this->tabPersonnel->UseVisualStyleBackColor = true;
			// 
			// dateEmbauchePersonnelLabel
			// 
			this->dateEmbauchePersonnelLabel->AutoSize = true;
			this->dateEmbauchePersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateEmbauchePersonnelLabel->Location = System::Drawing::Point(15, 164);
			this->dateEmbauchePersonnelLabel->Name = L"dateEmbauchePersonnelLabel";
			this->dateEmbauchePersonnelLabel->Size = System::Drawing::Size(145, 20);
			this->dateEmbauchePersonnelLabel->TabIndex = 11;
			this->dateEmbauchePersonnelLabel->Text = L"Date d\'embauche :";
			// 
			// dateEmbauchePersonnelPicker
			// 
			this->dateEmbauchePersonnelPicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateEmbauchePersonnelPicker->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateEmbauchePersonnelPicker->Location = System::Drawing::Point(182, 159);
			this->dateEmbauchePersonnelPicker->Name = L"dateEmbauchePersonnelPicker";
			this->dateEmbauchePersonnelPicker->Size = System::Drawing::Size(324, 27);
			this->dateEmbauchePersonnelPicker->TabIndex = 10;
			// 
			// prenomPersonnelLabel
			// 
			this->prenomPersonnelLabel->AutoSize = true;
			this->prenomPersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->prenomPersonnelLabel->Location = System::Drawing::Point(86, 126);
			this->prenomPersonnelLabel->Name = L"prenomPersonnelLabel";
			this->prenomPersonnelLabel->Size = System::Drawing::Size(74, 20);
			this->prenomPersonnelLabel->TabIndex = 9;
			this->prenomPersonnelLabel->Text = L"Prénom :";
			// 
			// prenomPersonnelBox
			// 
			this->prenomPersonnelBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->prenomPersonnelBox->Location = System::Drawing::Point(182, 126);
			this->prenomPersonnelBox->Name = L"prenomPersonnelBox";
			this->prenomPersonnelBox->Size = System::Drawing::Size(324, 27);
			this->prenomPersonnelBox->TabIndex = 8;
			// 
			// nomPersonnelLabel
			// 
			this->nomPersonnelLabel->AutoSize = true;
			this->nomPersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nomPersonnelLabel->Location = System::Drawing::Point(107, 94);
			this->nomPersonnelLabel->Name = L"nomPersonnelLabel";
			this->nomPersonnelLabel->Size = System::Drawing::Size(53, 20);
			this->nomPersonnelLabel->TabIndex = 7;
			this->nomPersonnelLabel->Text = L"Nom :";
			// 
			// idPersonnelLabel
			// 
			this->idPersonnelLabel->AutoSize = true;
			this->idPersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idPersonnelLabel->Location = System::Drawing::Point(128, 60);
			this->idPersonnelLabel->Name = L"idPersonnelLabel";
			this->idPersonnelLabel->Size = System::Drawing::Size(32, 20);
			this->idPersonnelLabel->TabIndex = 6;
			this->idPersonnelLabel->Text = L"ID :";
			// 
			// nomPersonnelBox
			// 
			this->nomPersonnelBox->BackColor = System::Drawing::SystemColors::Window;
			this->nomPersonnelBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nomPersonnelBox->Location = System::Drawing::Point(182, 93);
			this->nomPersonnelBox->Name = L"nomPersonnelBox";
			this->nomPersonnelBox->Size = System::Drawing::Size(324, 27);
			this->nomPersonnelBox->TabIndex = 5;
			// 
			// idPersonnelBox
			// 
			this->idPersonnelBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idPersonnelBox->Location = System::Drawing::Point(182, 60);
			this->idPersonnelBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			{
				999999999, 0, 0, 0
			});
			this->idPersonnelBox->Name = L"idPersonnelBox";
			this->idPersonnelBox->Size = System::Drawing::Size(324, 27);
			this->idPersonnelBox->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(189, 4);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 42);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Personnel";
			// 
			// boutonValider
			// 
			this->boutonValider->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boutonValider->ForeColor = System::Drawing::Color::Green;
			this->boutonValider->Location = System::Drawing::Point(192, 351);
			this->boutonValider->Name = L"boutonValider";
			this->boutonValider->Size = System::Drawing::Size(172, 40);
			this->boutonValider->TabIndex = 0;
			this->boutonValider->Text = L"Valider";
			this->boutonValider->UseVisualStyleBackColor = true;
			this->boutonValider->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonValider);
			// 
			// tabAccueil
			// 
			this->tabAccueil->Controls->Add(this->button8);
			this->tabAccueil->Controls->Add(this->passwordLabel);
			this->tabAccueil->Controls->Add(this->passwordBox);
			this->tabAccueil->Controls->Add(this->usernameBox);
			this->tabAccueil->Controls->Add(this->usernameLabel);
			this->tabAccueil->Controls->Add(this->label4);
			this->tabAccueil->Controls->Add(this->welcomeTitleLabel);
			this->tabAccueil->Location = System::Drawing::Point(4, 22);
			this->tabAccueil->Name = L"tabAccueil";
			this->tabAccueil->Padding = System::Windows::Forms::Padding(3);
			this->tabAccueil->Size = System::Drawing::Size(556, 307);
			this->tabAccueil->TabIndex = 0;
			this->tabAccueil->Text = L"Accueil";
			this->tabAccueil->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(186, 266);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(278, 30);
			this->button8->TabIndex = 12;
			this->button8->Text = L"Connexion";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Projet::clickOnConnexionBDD);
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordLabel->Location = System::Drawing::Point(91, 226);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(89, 16);
			this->passwordLabel->TabIndex = 11;
			this->passwordLabel->Text = L"Mot de passe";
			// 
			// passwordBox
			// 
			this->passwordBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordBox->Location = System::Drawing::Point(186, 223);
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->PasswordChar = '*';
			this->passwordBox->Size = System::Drawing::Size(278, 22);
			this->passwordBox->TabIndex = 10;
			this->passwordBox->UseSystemPasswordChar = true;
			// 
			// usernameBox
			// 
			this->usernameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameBox->Location = System::Drawing::Point(186, 182);
			this->usernameBox->Name = L"usernameBox";
			this->usernameBox->Size = System::Drawing::Size(278, 22);
			this->usernameBox->TabIndex = 8;
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLabel->Location = System::Drawing::Point(74, 185);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(106, 16);
			this->usernameLabel->TabIndex = 9;
			this->usernameLabel->Text = L"Nom d\'utilisateur";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(36, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(485, 90);
			this->label4->TabIndex = 7;
			this->label4->Text = resources->GetString(L"label4.Text");
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// welcomeTitleLabel
			// 
			this->welcomeTitleLabel->AutoSize = true;
			this->welcomeTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->welcomeTitleLabel->Location = System::Drawing::Point(18, 14);
			this->welcomeTitleLabel->Name = L"welcomeTitleLabel";
			this->welcomeTitleLabel->Size = System::Drawing::Size(522, 37);
			this->welcomeTitleLabel->TabIndex = 0;
			this->welcomeTitleLabel->Text = L"Bienvenue sur Business Manager";
			// 
			// tabController
			// 
			this->tabController->Controls->Add(this->tabAccueil);
			this->tabController->Controls->Add(this->tabPersonnel);
			this->tabController->Controls->Add(this->tabStocks);
			this->tabController->Controls->Add(this->tabCommandes);
			this->tabController->Controls->Add(this->tabClients);
			this->tabController->Controls->Add(this->tabStatistiques);
			this->tabController->Location = System::Drawing::Point(12, 12);
			this->tabController->Name = L"tabController";
			this->tabController->SelectedIndex = 0;
			this->tabController->Size = System::Drawing::Size(564, 333);
			this->tabController->TabIndex = 4;
			// 
			// Projet
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(1251, 572);
			this->Controls->Add(this->boutonAfficher);
			this->Controls->Add(this->historiqueLabel);
			this->Controls->Add(this->boutonSupprimer);
			this->Controls->Add(this->boutonAjouter);
			this->Controls->Add(this->boutonModifier);
			this->Controls->Add(this->historiqueBox);
			this->Controls->Add(this->tabController);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->boutonValider);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			// this->Name = L"Projet";
			this->Text = L"Business Manager - Powered by EVAL";
			this->Load += gcnew System::EventHandler(this, &Projet::onFormLoad);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->tabCommandes->ResumeLayout(false);
			this->tabCommandes->PerformLayout();
			this->tabStocks->ResumeLayout(false);
			this->tabStocks->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quantiteStockBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seuilStockBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prixStockBox))->EndInit();
			this->tabPersonnel->ResumeLayout(false);
			this->tabPersonnel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idPersonnelBox))->EndInit();
			this->tabAccueil->ResumeLayout(false);
			this->tabAccueil->PerformLayout();
			this->tabController->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void onFormLoad(System::Object^ sender, System::EventArgs^ e)
	{
		setConnected(false);
	}

	private: System::Void setConnected(bool connected)
	{
		this->connected = connected;

		this->boutonValider->Visible = connected;
		this->boutonAfficher->Visible = connected;
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

	private: System::Void clickOnBoutonValider(System::Object^ sender, System::EventArgs^ e)
	{
		this->label1->Text = "BIEN JOUE";
	}

	private: System::Void clickOnConnexionBDD(System::Object^ sender, System::EventArgs^ e)
	{
		addHistorique(L"Connexion en cours...");
		setConnected(true);
		changeMode(currentMode);
	}
	private: System::Void addHistorique(System::String^ historique)
	{
		System::DateTime date = System::DateTime::Now;
		this->historiqueBox->Text += "[" + date.ToLongTimeString() + "] " + historique + "\r\n";
		this->historiqueBox->SelectionStart = this->historiqueBox->Text->Length - 1;
		this->historiqueBox->ScrollToCaret();
	}

	private: System::Void clickOnBoutonAfficher(System::Object^ sender, System::EventArgs^ e)
	{
		changeMode(AFFICHER);
	}
	private: System::Void clickOnBoutonSupprimer(System::Object^ sender, System::EventArgs^ e)
	{
		changeMode(SUPPRIMER);
	}
	private: System::Void clickOnBoutonAjouter(System::Object^ sender, System::EventArgs^ e)
	{
		changeMode(AJOUTER);
	}
	private: System::Void clickOnBoutonModifier(System::Object^ sender, System::EventArgs^ e)
	{
		changeMode(MODIFIER);
	}
	private: System::Void changeMode(SqlMode mode)
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

				name = L"Modification";
				break;
			default:
				break;
		}

		addHistorique("Mode : " + name);
	}
	};
}
