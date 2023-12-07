#pragma once
#include "ArticlePopup.h"
#include "SqlQuery.h"
#include "SqlManager.h"
#include "SqlHandler.h"

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
		static Projet^ instance;

		Projet(void)
		{
			instance = this;
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
	private: System::Windows::Forms::Label^ personnelTitreLabel;
	private: System::Windows::Forms::TabPage^ tabAccueil;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::TextBox^ passwordBox;
	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ descriptionLabel;

	private: System::Windows::Forms::Label^ welcomeTitleLabel;
	private: System::Windows::Forms::TabControl^ tabController;
	private: System::Windows::Forms::Label^ dateEmbauchePersonnelLabel;
	private: System::Windows::Forms::DateTimePicker^ dateEmbauchePersonnelPicker;
	private: System::Windows::Forms::Label^ prenomPersonnelLabel;
	private: System::Windows::Forms::TextBox^ prenomPersonnelBox;
	private: System::Windows::Forms::Label^ nomPersonnelLabel;
	private: System::Windows::Forms::Label^ idPersonnelLabel;
	private: System::Windows::Forms::TextBox^ nomPersonnelBox;

	private:
		bool connected;
		SqlHandler^ sqlHandler;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

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
	private: System::Windows::Forms::ComboBox^ moyenPayementCommandeBox;



	private: System::Windows::Forms::Label^ dateLivraisonCommandeLabel;
	private: System::Windows::Forms::TextBox^ idCommandeBox;

	private: System::Windows::Forms::Label^ label6;


	private: System::Windows::Forms::DateTimePicker^ dateEmissionCommandePicker;

	private: System::Windows::Forms::DateTimePicker^ dateLivraisonCommandePicker;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::DateTimePicker^ dateSoldeCommandePicker;

	private: System::Windows::Forms::DateTimePicker^ datePayementCommandePicker;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ boutonAfficherTout;
	private: System::Windows::Forms::Button^ boutonChercher;
	private: System::Windows::Forms::ComboBox^ rechercheColonnesBox;
	private: System::Windows::Forms::TextBox^ textBox1;



	private: SqlMode currentMode;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Projet::typeid));
			   this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
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
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->dateSoldeCommandePicker = (gcnew System::Windows::Forms::DateTimePicker());
			   this->datePayementCommandePicker = (gcnew System::Windows::Forms::DateTimePicker());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->dateEmissionCommandePicker = (gcnew System::Windows::Forms::DateTimePicker());
			   this->dateLivraisonCommandePicker = (gcnew System::Windows::Forms::DateTimePicker());
			   this->moyenPayementCommandeBox = (gcnew System::Windows::Forms::ComboBox());
			   this->commandesLabel = (gcnew System::Windows::Forms::Label());
			   this->dateLivraisonCommandeLabel = (gcnew System::Windows::Forms::Label());
			   this->idCommandeBox = (gcnew System::Windows::Forms::TextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
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
			   this->personnelTitreLabel = (gcnew System::Windows::Forms::Label());
			   this->boutonValider = (gcnew System::Windows::Forms::Button());
			   this->tabAccueil = (gcnew System::Windows::Forms::TabPage());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->passwordLabel = (gcnew System::Windows::Forms::Label());
			   this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			   this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			   this->usernameLabel = (gcnew System::Windows::Forms::Label());
			   this->descriptionLabel = (gcnew System::Windows::Forms::Label());
			   this->welcomeTitleLabel = (gcnew System::Windows::Forms::Label());
			   this->tabController = (gcnew System::Windows::Forms::TabControl());
			   this->boutonAfficherTout = (gcnew System::Windows::Forms::Button());
			   this->boutonChercher = (gcnew System::Windows::Forms::Button());
			   this->rechercheColonnesBox = (gcnew System::Windows::Forms::ComboBox());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
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
			   this->dataGridView->GridColor = System::Drawing::SystemColors::ActiveBorder;
			   this->dataGridView->Location = System::Drawing::Point(598, 11);
			   this->dataGridView->Margin = System::Windows::Forms::Padding(2);
			   this->dataGridView->Name = L"dataGridView";
			   this->dataGridView->ReadOnly = true;
			   this->dataGridView->Size = System::Drawing::Size(581, 551);
			   this->dataGridView->TabIndex = 3;
			   this->dataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ProjetPOO::Projet::clickOnCellule);
			   // 
			   // boutonAfficher
			   // 
			   this->boutonAfficher->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->boutonAfficher->Location = System::Drawing::Point(13, 400);
			   this->boutonAfficher->Margin = System::Windows::Forms::Padding(2);
			   this->boutonAfficher->Name = L"boutonAfficher";
			   this->boutonAfficher->Size = System::Drawing::Size(143, 38);
			   this->boutonAfficher->TabIndex = 8;
			   this->boutonAfficher->Text = L"Afficher";
			   this->boutonAfficher->UseVisualStyleBackColor = true;
			   this->boutonAfficher->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonAfficher);
			   // 
			   // boutonSupprimer
			   // 
			   this->boutonSupprimer->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->boutonSupprimer->Location = System::Drawing::Point(160, 400);
			   this->boutonSupprimer->Margin = System::Windows::Forms::Padding(2);
			   this->boutonSupprimer->Name = L"boutonSupprimer";
			   this->boutonSupprimer->Size = System::Drawing::Size(143, 38);
			   this->boutonSupprimer->TabIndex = 7;
			   this->boutonSupprimer->Text = L"Supprimer";
			   this->boutonSupprimer->UseVisualStyleBackColor = true;
			   this->boutonSupprimer->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonSupprimer);
			   // 
			   // boutonModifier
			   // 
			   this->boutonModifier->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->boutonModifier->Location = System::Drawing::Point(454, 400);
			   this->boutonModifier->Margin = System::Windows::Forms::Padding(2);
			   this->boutonModifier->Name = L"boutonModifier";
			   this->boutonModifier->Size = System::Drawing::Size(140, 38);
			   this->boutonModifier->TabIndex = 6;
			   this->boutonModifier->Text = L"Modifier";
			   this->boutonModifier->UseVisualStyleBackColor = true;
			   this->boutonModifier->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonModifier);
			   // 
			   // boutonAjouter
			   // 
			   this->boutonAjouter->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->boutonAjouter->Location = System::Drawing::Point(307, 400);
			   this->boutonAjouter->Margin = System::Windows::Forms::Padding(2);
			   this->boutonAjouter->Name = L"boutonAjouter";
			   this->boutonAjouter->Size = System::Drawing::Size(143, 38);
			   this->boutonAjouter->TabIndex = 5;
			   this->boutonAjouter->Text = L"Ajouter";
			   this->boutonAjouter->UseVisualStyleBackColor = true;
			   this->boutonAjouter->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonAjouter);
			   // 
			   // historiqueBox
			   // 
			   this->historiqueBox->Location = System::Drawing::Point(9, 459);
			   this->historiqueBox->Margin = System::Windows::Forms::Padding(2);
			   this->historiqueBox->Name = L"historiqueBox";
			   this->historiqueBox->ReadOnly = true;
			   this->historiqueBox->Size = System::Drawing::Size(585, 103);
			   this->historiqueBox->TabIndex = 5;
			   this->historiqueBox->Text = L"";
			   // 
			   // historiqueLabel
			   // 
			   this->historiqueLabel->AutoSize = true;
			   this->historiqueLabel->Font = (gcnew System::Drawing::Font(L"Minecraft", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->historiqueLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			   this->historiqueLabel->Location = System::Drawing::Point(11, 446);
			   this->historiqueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->historiqueLabel->Name = L"historiqueLabel";
			   this->historiqueLabel->Size = System::Drawing::Size(73, 11);
			   this->historiqueLabel->TabIndex = 6;
			   this->historiqueLabel->Text = L"Historique";
			   // 
			   // tabStatistiques
			   // 
			   this->tabStatistiques->Location = System::Drawing::Point(4, 22);
			   this->tabStatistiques->Margin = System::Windows::Forms::Padding(2);
			   this->tabStatistiques->Name = L"tabStatistiques";
			   this->tabStatistiques->Size = System::Drawing::Size(577, 324);
			   this->tabStatistiques->TabIndex = 5;
			   this->tabStatistiques->Text = L"Statistique";
			   this->tabStatistiques->UseVisualStyleBackColor = true;
			   // 
			   // tabClients
			   // 
			   this->tabClients->Location = System::Drawing::Point(4, 22);
			   this->tabClients->Margin = System::Windows::Forms::Padding(2);
			   this->tabClients->Name = L"tabClients";
			   this->tabClients->Size = System::Drawing::Size(577, 324);
			   this->tabClients->TabIndex = 4;
			   this->tabClients->Text = L"Client";
			   this->tabClients->UseVisualStyleBackColor = true;
			   // 
			   // tabCommandes
			   // 
			   this->tabCommandes->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->tabCommandes->Controls->Add(this->button1);
			   this->tabCommandes->Controls->Add(this->label10);
			   this->tabCommandes->Controls->Add(this->dateSoldeCommandePicker);
			   this->tabCommandes->Controls->Add(this->datePayementCommandePicker);
			   this->tabCommandes->Controls->Add(this->label9);
			   this->tabCommandes->Controls->Add(this->label5);
			   this->tabCommandes->Controls->Add(this->label7);
			   this->tabCommandes->Controls->Add(this->dateEmissionCommandePicker);
			   this->tabCommandes->Controls->Add(this->dateLivraisonCommandePicker);
			   this->tabCommandes->Controls->Add(this->moyenPayementCommandeBox);
			   this->tabCommandes->Controls->Add(this->commandesLabel);
			   this->tabCommandes->Controls->Add(this->dateLivraisonCommandeLabel);
			   this->tabCommandes->Controls->Add(this->idCommandeBox);
			   this->tabCommandes->Controls->Add(this->label6);
			   this->tabCommandes->Location = System::Drawing::Point(4, 22);
			   this->tabCommandes->Margin = System::Windows::Forms::Padding(2);
			   this->tabCommandes->Name = L"tabCommandes";
			   this->tabCommandes->Size = System::Drawing::Size(577, 324);
			   this->tabCommandes->TabIndex = 3;
			   this->tabCommandes->Text = L"Commande";
			   this->tabCommandes->UseVisualStyleBackColor = true;
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(183, 276);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(244, 35);
			   this->button1->TabIndex = 42;
			   this->button1->Text = L"Choisir articles";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonArticlesCommandes);
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label10->Location = System::Drawing::Point(32, 219);
			   this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(146, 20);
			   this->label10->TabIndex = 41;
			   this->label10->Text = L"Date solde enreg. :";
			   // 
			   // dateSoldeCommandePicker
			   // 
			   this->dateSoldeCommandePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateSoldeCommandePicker->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateSoldeCommandePicker->Location = System::Drawing::Point(183, 214);
			   this->dateSoldeCommandePicker->Name = L"dateSoldeCommandePicker";
			   this->dateSoldeCommandePicker->Size = System::Drawing::Size(244, 27);
			   this->dateSoldeCommandePicker->TabIndex = 40;
			   // 
			   // datePayementCommandePicker
			   // 
			   this->datePayementCommandePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->datePayementCommandePicker->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->datePayementCommandePicker->Location = System::Drawing::Point(183, 181);
			   this->datePayementCommandePicker->Name = L"datePayementCommandePicker";
			   this->datePayementCommandePicker->Size = System::Drawing::Size(244, 27);
			   this->datePayementCommandePicker->TabIndex = 39;
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label9->Location = System::Drawing::Point(50, 186);
			   this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(128, 20);
			   this->label9->TabIndex = 38;
			   this->label9->Text = L"Date payement :";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(11, 151);
			   this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(168, 20);
			   this->label5->TabIndex = 37;
			   this->label5->Text = L"Moyen de payement :";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label7->Location = System::Drawing::Point(30, 122);
			   this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(149, 20);
			   this->label7->TabIndex = 35;
			   this->label7->Text = L"Date emission est. :";
			   // 
			   // dateEmissionCommandePicker
			   // 
			   this->dateEmissionCommandePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateEmissionCommandePicker->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateEmissionCommandePicker->Location = System::Drawing::Point(183, 117);
			   this->dateEmissionCommandePicker->Name = L"dateEmissionCommandePicker";
			   this->dateEmissionCommandePicker->Size = System::Drawing::Size(244, 27);
			   this->dateEmissionCommandePicker->TabIndex = 33;
			   // 
			   // dateLivraisonCommandePicker
			   // 
			   this->dateLivraisonCommandePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateLivraisonCommandePicker->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateLivraisonCommandePicker->Location = System::Drawing::Point(183, 84);
			   this->dateLivraisonCommandePicker->Name = L"dateLivraisonCommandePicker";
			   this->dateLivraisonCommandePicker->Size = System::Drawing::Size(244, 27);
			   this->dateLivraisonCommandePicker->TabIndex = 32;
			   // 
			   // moyenPayementCommandeBox
			   // 
			   this->moyenPayementCommandeBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->moyenPayementCommandeBox->FormattingEnabled = true;
			   this->moyenPayementCommandeBox->Items->AddRange(gcnew cli::array< System::Object^  >(4)
			   {
				   L"Carte", L"Paypal", L"Cash", L"Bitcoin"
			   });
			   this->moyenPayementCommandeBox->Location = System::Drawing::Point(183, 148);
			   this->moyenPayementCommandeBox->Margin = System::Windows::Forms::Padding(2);
			   this->moyenPayementCommandeBox->Name = L"moyenPayementCommandeBox";
			   this->moyenPayementCommandeBox->Size = System::Drawing::Size(244, 28);
			   this->moyenPayementCommandeBox->TabIndex = 28;
			   // 
			   // commandesLabel
			   // 
			   this->commandesLabel->AutoSize = true;
			   this->commandesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->commandesLabel->Location = System::Drawing::Point(172, 3);
			   this->commandesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->commandesLabel->Name = L"commandesLabel";
			   this->commandesLabel->Size = System::Drawing::Size(218, 42);
			   this->commandesLabel->TabIndex = 26;
			   this->commandesLabel->Text = L"Commandes";
			   // 
			   // dateLivraisonCommandeLabel
			   // 
			   this->dateLivraisonCommandeLabel->AutoSize = true;
			   this->dateLivraisonCommandeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateLivraisonCommandeLabel->Location = System::Drawing::Point(33, 89);
			   this->dateLivraisonCommandeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->dateLivraisonCommandeLabel->Name = L"dateLivraisonCommandeLabel";
			   this->dateLivraisonCommandeLabel->Size = System::Drawing::Size(145, 20);
			   this->dateLivraisonCommandeLabel->TabIndex = 29;
			   this->dateLivraisonCommandeLabel->Text = L"Date livraison est. :";
			   // 
			   // idCommandeBox
			   // 
			   this->idCommandeBox->BackColor = System::Drawing::SystemColors::Window;
			   this->idCommandeBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->idCommandeBox->Location = System::Drawing::Point(183, 52);
			   this->idCommandeBox->Margin = System::Windows::Forms::Padding(2);
			   this->idCommandeBox->Name = L"idCommandeBox";
			   this->idCommandeBox->Size = System::Drawing::Size(244, 27);
			   this->idCommandeBox->TabIndex = 26;
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(146, 55);
			   this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(32, 20);
			   this->label6->TabIndex = 27;
			   this->label6->Text = L"ID :";
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
			   this->tabStocks->Margin = System::Windows::Forms::Padding(2);
			   this->tabStocks->Name = L"tabStocks";
			   this->tabStocks->Size = System::Drawing::Size(577, 324);
			   this->tabStocks->TabIndex = 2;
			   this->tabStocks->Text = L"Stock";
			   this->tabStocks->UseVisualStyleBackColor = true;
			   // 
			   // quantiteStockLabel
			   // 
			   this->quantiteStockLabel->AutoSize = true;
			   this->quantiteStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->quantiteStockLabel->Location = System::Drawing::Point(98, 254);
			   this->quantiteStockLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->seuilStockLabel->Location = System::Drawing::Point(85, 223);
			   this->seuilStockLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->couleurStockLabel->Location = System::Drawing::Point(104, 193);
			   this->couleurStockLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->natureStockLabel->Location = System::Drawing::Point(111, 162);
			   this->natureStockLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->natureStockLabel->Name = L"natureStockLabel";
			   this->natureStockLabel->Size = System::Drawing::Size(67, 20);
			   this->natureStockLabel->TabIndex = 22;
			   this->natureStockLabel->Text = L"Nature :";
			   // 
			   // quantiteStockBox
			   // 
			   this->quantiteStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->quantiteStockBox->Location = System::Drawing::Point(196, 252);
			   this->quantiteStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->quantiteStockBox->Name = L"quantiteStockBox";
			   this->quantiteStockBox->Size = System::Drawing::Size(244, 27);
			   this->quantiteStockBox->TabIndex = 21;
			   // 
			   // seuilStockBox
			   // 
			   this->seuilStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->seuilStockBox->Location = System::Drawing::Point(196, 221);
			   this->seuilStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->seuilStockBox->Name = L"seuilStockBox";
			   this->seuilStockBox->Size = System::Drawing::Size(244, 27);
			   this->seuilStockBox->TabIndex = 20;
			   // 
			   // couleurStockBox
			   // 
			   this->couleurStockBox->BackColor = System::Drawing::SystemColors::Window;
			   this->couleurStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->couleurStockBox->Location = System::Drawing::Point(196, 190);
			   this->couleurStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->couleurStockBox->Name = L"couleurStockBox";
			   this->couleurStockBox->Size = System::Drawing::Size(244, 27);
			   this->couleurStockBox->TabIndex = 19;
			   // 
			   // natureStockBox
			   // 
			   this->natureStockBox->BackColor = System::Drawing::SystemColors::Window;
			   this->natureStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->natureStockBox->Location = System::Drawing::Point(196, 159);
			   this->natureStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->natureStockBox->Name = L"natureStockBox";
			   this->natureStockBox->Size = System::Drawing::Size(244, 27);
			   this->natureStockBox->TabIndex = 18;
			   // 
			   // prixStockBox
			   // 
			   this->prixStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->prixStockBox->Location = System::Drawing::Point(196, 128);
			   this->prixStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->prixStockBox->Name = L"prixStockBox";
			   this->prixStockBox->Size = System::Drawing::Size(244, 27);
			   this->prixStockBox->TabIndex = 17;
			   // 
			   // nomStockBox
			   // 
			   this->nomStockBox->BackColor = System::Drawing::SystemColors::Window;
			   this->nomStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->nomStockBox->Location = System::Drawing::Point(196, 97);
			   this->nomStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->nomStockBox->Name = L"nomStockBox";
			   this->nomStockBox->Size = System::Drawing::Size(244, 27);
			   this->nomStockBox->TabIndex = 16;
			   // 
			   // prixStockLabel
			   // 
			   this->prixStockLabel->AutoSize = true;
			   this->prixStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->prixStockLabel->Location = System::Drawing::Point(134, 130);
			   this->prixStockLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->nomStockLabel->Location = System::Drawing::Point(125, 100);
			   this->nomStockLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->idStockLabel->Location = System::Drawing::Point(146, 69);
			   this->idStockLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->label2->Location = System::Drawing::Point(217, 3);
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
			   this->idStockBox->Location = System::Drawing::Point(196, 66);
			   this->idStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->idStockBox->Name = L"idStockBox";
			   this->idStockBox->Size = System::Drawing::Size(244, 27);
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
			   this->tabPersonnel->Controls->Add(this->personnelTitreLabel);
			   this->tabPersonnel->Location = System::Drawing::Point(4, 22);
			   this->tabPersonnel->Margin = System::Windows::Forms::Padding(2);
			   this->tabPersonnel->Name = L"tabPersonnel";
			   this->tabPersonnel->Padding = System::Windows::Forms::Padding(2);
			   this->tabPersonnel->Size = System::Drawing::Size(577, 324);
			   this->tabPersonnel->TabIndex = 1;
			   this->tabPersonnel->Text = L"Personnel";
			   this->tabPersonnel->UseVisualStyleBackColor = true;
			   // 
			   // dateEmbauchePersonnelLabel
			   // 
			   this->dateEmbauchePersonnelLabel->AutoSize = true;
			   this->dateEmbauchePersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateEmbauchePersonnelLabel->Location = System::Drawing::Point(29, 158);
			   this->dateEmbauchePersonnelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->dateEmbauchePersonnelPicker->Location = System::Drawing::Point(205, 153);
			   this->dateEmbauchePersonnelPicker->Margin = System::Windows::Forms::Padding(2);
			   this->dateEmbauchePersonnelPicker->Name = L"dateEmbauchePersonnelPicker";
			   this->dateEmbauchePersonnelPicker->Size = System::Drawing::Size(244, 27);
			   this->dateEmbauchePersonnelPicker->TabIndex = 10;
			   // 
			   // prenomPersonnelLabel
			   // 
			   this->prenomPersonnelLabel->AutoSize = true;
			   this->prenomPersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->prenomPersonnelLabel->Location = System::Drawing::Point(100, 125);
			   this->prenomPersonnelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->prenomPersonnelLabel->Name = L"prenomPersonnelLabel";
			   this->prenomPersonnelLabel->Size = System::Drawing::Size(74, 20);
			   this->prenomPersonnelLabel->TabIndex = 9;
			   this->prenomPersonnelLabel->Text = L"Prénom :";
			   // 
			   // prenomPersonnelBox
			   // 
			   this->prenomPersonnelBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->prenomPersonnelBox->Location = System::Drawing::Point(205, 122);
			   this->prenomPersonnelBox->Margin = System::Windows::Forms::Padding(2);
			   this->prenomPersonnelBox->Name = L"prenomPersonnelBox";
			   this->prenomPersonnelBox->Size = System::Drawing::Size(244, 27);
			   this->prenomPersonnelBox->TabIndex = 8;
			   // 
			   // nomPersonnelLabel
			   // 
			   this->nomPersonnelLabel->AutoSize = true;
			   this->nomPersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->nomPersonnelLabel->Location = System::Drawing::Point(121, 94);
			   this->nomPersonnelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->idPersonnelLabel->Location = System::Drawing::Point(142, 62);
			   this->idPersonnelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->nomPersonnelBox->Location = System::Drawing::Point(205, 91);
			   this->nomPersonnelBox->Margin = System::Windows::Forms::Padding(2);
			   this->nomPersonnelBox->Name = L"nomPersonnelBox";
			   this->nomPersonnelBox->Size = System::Drawing::Size(243, 27);
			   this->nomPersonnelBox->TabIndex = 5;
			   // 
			   // idPersonnelBox
			   // 
			   this->idPersonnelBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->idPersonnelBox->Location = System::Drawing::Point(205, 60);
			   this->idPersonnelBox->Margin = System::Windows::Forms::Padding(2);
			   this->idPersonnelBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			   {
				   999999999, 0, 0, 0
			   });
			   this->idPersonnelBox->Name = L"idPersonnelBox";
			   this->idPersonnelBox->Size = System::Drawing::Size(243, 27);
			   this->idPersonnelBox->TabIndex = 4;
			   // 
			   // label1
			   // 
			   this->personnelTitreLabel->AutoSize = true;
			   this->personnelTitreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->personnelTitreLabel->Location = System::Drawing::Point(208, 3);
			   this->personnelTitreLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->personnelTitreLabel->Name = L"label1";
			   this->personnelTitreLabel->Size = System::Drawing::Size(179, 42);
			   this->personnelTitreLabel->TabIndex = 2;
			   this->personnelTitreLabel->Text = L"Personnel";
			   // 
			   // boutonValider
			   // 
			   this->boutonValider->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->boutonValider->ForeColor = System::Drawing::Color::Green;
			   this->boutonValider->Location = System::Drawing::Point(454, 364);
			   this->boutonValider->Margin = System::Windows::Forms::Padding(2);
			   this->boutonValider->Name = L"boutonValider";
			   this->boutonValider->Size = System::Drawing::Size(140, 32);
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
			   this->tabAccueil->Controls->Add(this->descriptionLabel);
			   this->tabAccueil->Controls->Add(this->welcomeTitleLabel);
			   this->tabAccueil->Location = System::Drawing::Point(4, 22);
			   this->tabAccueil->Margin = System::Windows::Forms::Padding(2);
			   this->tabAccueil->Name = L"tabAccueil";
			   this->tabAccueil->Padding = System::Windows::Forms::Padding(2);
			   this->tabAccueil->Size = System::Drawing::Size(577, 324);
			   this->tabAccueil->TabIndex = 0;
			   this->tabAccueil->Text = L"Accueil";
			   this->tabAccueil->UseVisualStyleBackColor = true;
			   // 
			   // button8
			   // 
			   this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button8->Location = System::Drawing::Point(186, 237);
			   this->button8->Margin = System::Windows::Forms::Padding(2);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(208, 24);
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
			   this->passwordLabel->Location = System::Drawing::Point(127, 199);
			   this->passwordLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->passwordLabel->Name = L"passwordLabel";
			   this->passwordLabel->Size = System::Drawing::Size(89, 16);
			   this->passwordLabel->TabIndex = 11;
			   this->passwordLabel->Text = L"Mot de passe";
			   // 
			   // passwordBox
			   // 
			   this->passwordBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->passwordBox->Location = System::Drawing::Point(226, 199);
			   this->passwordBox->Margin = System::Windows::Forms::Padding(2);
			   this->passwordBox->Name = L"passwordBox";
			   this->passwordBox->PasswordChar = '*';
			   this->passwordBox->Size = System::Drawing::Size(210, 22);
			   this->passwordBox->TabIndex = 10;
			   this->passwordBox->UseSystemPasswordChar = true;
			   // 
			   // usernameBox
			   // 
			   this->usernameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->usernameBox->Location = System::Drawing::Point(226, 166);
			   this->usernameBox->Margin = System::Windows::Forms::Padding(2);
			   this->usernameBox->Name = L"usernameBox";
			   this->usernameBox->Size = System::Drawing::Size(210, 22);
			   this->usernameBox->TabIndex = 8;
			   // 
			   // usernameLabel
			   // 
			   this->usernameLabel->AutoSize = true;
			   this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->usernameLabel->Location = System::Drawing::Point(110, 168);
			   this->usernameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->usernameLabel->Name = L"usernameLabel";
			   this->usernameLabel->Size = System::Drawing::Size(106, 16);
			   this->usernameLabel->TabIndex = 9;
			   this->usernameLabel->Text = L"Nom d\'utilisateur";
			   // 
			   // descriptionLabel
			   // 
			   this->descriptionLabel->AutoSize = true;
			   this->descriptionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->descriptionLabel->Location = System::Drawing::Point(43, 54);
			   this->descriptionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->descriptionLabel->Name = L"descriptionLabel";
			   this->descriptionLabel->Size = System::Drawing::Size(485, 90);
			   this->descriptionLabel->TabIndex = 7;
			   this->descriptionLabel->Text = resources->GetString(L"descriptionLabel.Text");
			   this->descriptionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // welcomeTitleLabel
			   // 
			   this->welcomeTitleLabel->AutoSize = true;
			   this->welcomeTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->welcomeTitleLabel->Location = System::Drawing::Point(26, 11);
			   this->welcomeTitleLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			   this->tabController->Location = System::Drawing::Point(9, 10);
			   this->tabController->Margin = System::Windows::Forms::Padding(2);
			   this->tabController->Name = L"tabController";
			   this->tabController->SelectedIndex = 0;
			   this->tabController->Size = System::Drawing::Size(585, 350);
			   this->tabController->TabIndex = 4;
			   this->tabController->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &Projet::onChangeTab);
			   // 
			   // boutonAfficherTout
			   // 
			   this->boutonAfficherTout->Location = System::Drawing::Point(13, 367);
			   this->boutonAfficherTout->Name = L"boutonAfficherTout";
			   this->boutonAfficherTout->Size = System::Drawing::Size(143, 26);
			   this->boutonAfficherTout->TabIndex = 9;
			   this->boutonAfficherTout->Text = L"Afficher tout";
			   this->boutonAfficherTout->UseVisualStyleBackColor = true;
			   this->boutonAfficherTout->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonAfficherTout);
			   // 
			   // boutonChercher
			   // 
			   this->boutonChercher->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->boutonChercher->Location = System::Drawing::Point(423, 368);
			   this->boutonChercher->Name = L"boutonChercher";
			   this->boutonChercher->Size = System::Drawing::Size(27, 26);
			   this->boutonChercher->TabIndex = 10;
			   this->boutonChercher->Text = L"🔍";
			   this->boutonChercher->UseVisualStyleBackColor = true;
			   this->boutonChercher->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonChercher);
			   // 
			   // rechercheColonnesBox
			   // 
			   this->rechercheColonnesBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->rechercheColonnesBox->FormattingEnabled = true;
			   this->rechercheColonnesBox->Location = System::Drawing::Point(307, 368);
			   this->rechercheColonnesBox->Name = L"rechercheColonnesBox";
			   this->rechercheColonnesBox->Size = System::Drawing::Size(112, 25);
			   this->rechercheColonnesBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->rechercheColonnesBox->TabIndex = 11;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox1->Location = System::Drawing::Point(162, 369);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(141, 23);
			   this->textBox1->TabIndex = 12;
			   // 
			   // Projet
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoSize = true;
			   this->BackColor = System::Drawing::SystemColors::ScrollBar;
			   this->ClientSize = System::Drawing::Size(1190, 573);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->rechercheColonnesBox);
			   this->Controls->Add(this->boutonChercher);
			   this->Controls->Add(this->boutonAfficherTout);
			   this->Controls->Add(this->boutonAfficher);
			   this->Controls->Add(this->historiqueLabel);
			   this->Controls->Add(this->boutonSupprimer);
			   this->Controls->Add(this->boutonAjouter);
			   this->Controls->Add(this->boutonModifier);
			   this->Controls->Add(this->historiqueBox);
			   this->Controls->Add(this->tabController);
			   this->Controls->Add(this->dataGridView);
			   this->Controls->Add(this->boutonValider);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->MaximizeBox = false;
			   this->Name = L"Projet";
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
		sqlHandler = gcnew SqlHandler(this->dataGridView);
		setConnected(false);
	}

	private: System::Void setConnected(bool connected)
	{
		this->connected = connected;

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
	private: System::Void clickOnBoutonValider(System::Object^ sender, System::EventArgs^ e)
	{
		if(isActive(tabPersonnel))
		{
			switch(currentMode)
			{
				case ProjetPOO::AFFICHER:
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
	private: System::Boolean isActive(System::Windows::Forms::TabPage^ tab)
	{
		return this->tabController->SelectedTab == tab;
	}
	private: System::Void clickOnConnexionBDD(System::Object^ sender, System::EventArgs^ e)
	{
		addHistorique(L"Connexion en cours...");
		setConnected(true);
		changeMode(currentMode);

		sqlHandler->fillGrid(Table::PERSONNES);
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
	private: System::Void clickOnBoutonArticlesCommandes(System::Object^ sender, System::EventArgs^ e)
	{
		ArticlePopup^ popup = gcnew ArticlePopup();
		popup->Show();
	}
	private: System::Void clickOnBoutonAfficherTout(System::Object^ sender, System::EventArgs^ e)
	{
		afficherTable();
	}
	private: System::Void onChangeTab(System::Object^ sender, System::Windows::Forms::TabControlEventArgs^ e)
	{
		afficherTable();
	}
	private: System::Void afficherTable()
	{
		if(isActive(tabPersonnel))
			sqlHandler->fillGrid(Table::PERSONNELS);
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
	private: System::Void clickOnBoutonChercher(System::Object^ sender, System::EventArgs^ e)
	{
		if(isActive(tabPersonnel))
			sqlHandler->searchByColumn(Table::PERSONNELS, "Id_personne", this->idPersonnelBox->Text, true);
		else if(isActive(tabCommandes))
			sqlHandler->searchByColumn(Table::COMMANDES, "Reference_commande", this->idCommandeBox->Text, false);
	}
	private: System::Void clickOnCellule(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if(isActive(tabPersonnel))
		{
			idPersonnelBox->Text = L"" + this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value;
			nomPersonnelBox->Text = L"" + this->dataGridView->Rows[e->RowIndex]->Cells[1]->Value;
			idPersonnelBox->Text = L"" + this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value;
			idPersonnelBox->Text = L"" + this->dataGridView->Rows[e->RowIndex]->Cells[0]->Value;
		}
	}

	public: System::Void updateRechercheColonneBox()
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
	};
}
