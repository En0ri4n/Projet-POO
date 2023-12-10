#pragma once
#include "SqlHandler.h"
#include "AdresseMap.h"
#include "AdressePopup.h"


namespace ProjetPOO
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ProjetPOO;

	enum TypeAdresse;

	public enum SqlMode
	{
		AFFICHER,
		SUPPRIMER,
		AJOUTER,
		MODIFIER
	};

	public enum Statistique
	{
		PANIER_MOYEN,
		CHIFFRE_AFFAIRE,
		ARTICLES_SOUS_SEUIL_REAPPROVISIONNEMENT,
		MONTANT_TOTAL_ACHAT_CLIENT,
		ARTICLES_PLUS_VENDUS,
		ARTICLES_MOINS_VENDUS,
		STOCK_VALEUR_COMMERCIALE,
		STOCK_VALEUR_ACHAT
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
	private: System::Windows::Forms::Button^ connexionBouton;

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
		ArrayList^ articlesCommande = gcnew ArrayList;
		AdresseMap^ currentPersonnelAdresse = gcnew AdresseMap;
		AdresseMap^ currentClientAdresseLivraison = gcnew AdresseMap;
		AdresseMap^ currentClientAdresseFacturation = gcnew AdresseMap;
		SqlMode currentMode;
		bool estSuperviseur;

	protected:
	public:
		ArrayList^ derniersArticlesCommande = gcnew ArrayList;

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



	private: System::Windows::Forms::DateTimePicker^ datePayementCommandePicker;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ boutonAfficherTout;
	private: System::Windows::Forms::Button^ boutonChercher;
	private: System::Windows::Forms::ComboBox^ rechercheColonnesBox;
private: System::Windows::Forms::TextBox^ rechercheBox;

	private: System::Windows::Forms::Label^ tvaStockLabel;
	private: System::Windows::Forms::NumericUpDown^ tvaStockBox;
	private: System::Windows::Forms::Label^ articlesCommandeLabel;
private: System::Windows::Forms::Button^ adressePersonnelBouton;
private: System::Windows::Forms::Label^ idSuperviseurPersonnelLabel;

private: System::Windows::Forms::NumericUpDown^ idSuperviseurPersonnelBox;
private: System::Windows::Forms::Label^ idClientCommandeLabel;

private: System::Windows::Forms::NumericUpDown^ idClientCommandeBox;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ prenomClientLabel;

private: System::Windows::Forms::TextBox^ prenomClientBox;

private: System::Windows::Forms::NumericUpDown^ idClientBox;
private: System::Windows::Forms::TextBox^ nomClientBox;
private: System::Windows::Forms::Label^ idClientLabel;
private: System::Windows::Forms::Label^ nomClientLabel;




private: System::Windows::Forms::DateTimePicker^ datePremierAchatClientPicker;
private: System::Windows::Forms::Label^ datePremierAchatClientLabel;


private: System::Windows::Forms::DateTimePicker^ dateNaissanceClientPicker;
private: System::Windows::Forms::Label^ dateNaissanceClientLabel;
private: System::Windows::Forms::Label^ adresseFacturationClientLabel;




private: System::Windows::Forms::Button^ adresseFacturationClientBouton;
private: System::Windows::Forms::Label^ adresseLivraisonClientLabel;


private: System::Windows::Forms::Button^ adresseLivraisonClientBouton;

private: System::Windows::Forms::CheckBox^ voirRequetesCheckBox;
private: System::Windows::Forms::Button^ clearBouton;


private: System::Windows::Forms::DateTimePicker^ dateMoisStatistiquePicker;
private: System::Windows::Forms::Label^ statistiqueTitleLabel;


private: System::Windows::Forms::ComboBox^ statistiqueBox;
private: System::Windows::Forms::Label^ moisStatistiquesLabel;
private: System::Windows::Forms::Button^ calculerStatistiqueBouton;
private: System::Windows::Forms::NumericUpDown^ idClientStatistiqueBox;
private: System::Windows::Forms::Label^ idClientStatistiqueLabel;

private: System::Windows::Forms::CheckBox^ superviseurCheckBox;
private: System::Windows::Forms::CheckBox^ superviseurPersonnelCheckBox;












private: System::Windows::Forms::Label^ adressePersonnelLabel;

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
			   this->idClientStatistiqueBox = (gcnew System::Windows::Forms::NumericUpDown());
			   this->idClientStatistiqueLabel = (gcnew System::Windows::Forms::Label());
			   this->calculerStatistiqueBouton = (gcnew System::Windows::Forms::Button());
			   this->moisStatistiquesLabel = (gcnew System::Windows::Forms::Label());
			   this->statistiqueTitleLabel = (gcnew System::Windows::Forms::Label());
			   this->statistiqueBox = (gcnew System::Windows::Forms::ComboBox());
			   this->dateMoisStatistiquePicker = (gcnew System::Windows::Forms::DateTimePicker());
			   this->tabClients = (gcnew System::Windows::Forms::TabPage());
			   this->adresseFacturationClientLabel = (gcnew System::Windows::Forms::Label());
			   this->adresseFacturationClientBouton = (gcnew System::Windows::Forms::Button());
			   this->adresseLivraisonClientLabel = (gcnew System::Windows::Forms::Label());
			   this->datePremierAchatClientPicker = (gcnew System::Windows::Forms::DateTimePicker());
			   this->datePremierAchatClientLabel = (gcnew System::Windows::Forms::Label());
			   this->adresseLivraisonClientBouton = (gcnew System::Windows::Forms::Button());
			   this->dateNaissanceClientPicker = (gcnew System::Windows::Forms::DateTimePicker());
			   this->dateNaissanceClientLabel = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->prenomClientLabel = (gcnew System::Windows::Forms::Label());
			   this->prenomClientBox = (gcnew System::Windows::Forms::TextBox());
			   this->idClientBox = (gcnew System::Windows::Forms::NumericUpDown());
			   this->nomClientBox = (gcnew System::Windows::Forms::TextBox());
			   this->idClientLabel = (gcnew System::Windows::Forms::Label());
			   this->nomClientLabel = (gcnew System::Windows::Forms::Label());
			   this->tabCommandes = (gcnew System::Windows::Forms::TabPage());
			   this->idClientCommandeLabel = (gcnew System::Windows::Forms::Label());
			   this->idClientCommandeBox = (gcnew System::Windows::Forms::NumericUpDown());
			   this->articlesCommandeLabel = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
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
			   this->tvaStockLabel = (gcnew System::Windows::Forms::Label());
			   this->tvaStockBox = (gcnew System::Windows::Forms::NumericUpDown());
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
			   this->idSuperviseurPersonnelLabel = (gcnew System::Windows::Forms::Label());
			   this->idSuperviseurPersonnelBox = (gcnew System::Windows::Forms::NumericUpDown());
			   this->adressePersonnelLabel = (gcnew System::Windows::Forms::Label());
			   this->adressePersonnelBouton = (gcnew System::Windows::Forms::Button());
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
			   this->superviseurCheckBox = (gcnew System::Windows::Forms::CheckBox());
			   this->connexionBouton = (gcnew System::Windows::Forms::Button());
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
			   this->rechercheBox = (gcnew System::Windows::Forms::TextBox());
			   this->voirRequetesCheckBox = (gcnew System::Windows::Forms::CheckBox());
			   this->clearBouton = (gcnew System::Windows::Forms::Button());
			   this->superviseurPersonnelCheckBox = (gcnew System::Windows::Forms::CheckBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			   this->tabStatistiques->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idClientStatistiqueBox))->BeginInit();
			   this->tabClients->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idClientBox))->BeginInit();
			   this->tabCommandes->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idClientCommandeBox))->BeginInit();
			   this->tabStocks->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tvaStockBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quantiteStockBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seuilStockBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prixStockBox))->BeginInit();
			   this->tabPersonnel->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idSuperviseurPersonnelBox))->BeginInit();
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
			   this->dataGridView->MultiSelect = false;
			   this->dataGridView->Name = L"dataGridView";
			   this->dataGridView->ReadOnly = true;
			   this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->dataGridView->Size = System::Drawing::Size(581, 551);
			   this->dataGridView->TabIndex = 3;
			   this->dataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Projet::clickOnCellule);
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
			   this->historiqueBox->WordWrap = false;
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
			   this->tabStatistiques->Controls->Add(this->idClientStatistiqueBox);
			   this->tabStatistiques->Controls->Add(this->idClientStatistiqueLabel);
			   this->tabStatistiques->Controls->Add(this->calculerStatistiqueBouton);
			   this->tabStatistiques->Controls->Add(this->moisStatistiquesLabel);
			   this->tabStatistiques->Controls->Add(this->statistiqueTitleLabel);
			   this->tabStatistiques->Controls->Add(this->statistiqueBox);
			   this->tabStatistiques->Controls->Add(this->dateMoisStatistiquePicker);
			   this->tabStatistiques->Location = System::Drawing::Point(4, 22);
			   this->tabStatistiques->Margin = System::Windows::Forms::Padding(2);
			   this->tabStatistiques->Name = L"tabStatistiques";
			   this->tabStatistiques->Size = System::Drawing::Size(577, 324);
			   this->tabStatistiques->TabIndex = 5;
			   this->tabStatistiques->Text = L"Statistique";
			   this->tabStatistiques->UseVisualStyleBackColor = true;
			   // 
			   // idClientStatistiqueBox
			   // 
			   this->idClientStatistiqueBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->idClientStatistiqueBox->Location = System::Drawing::Point(199, 162);
			   this->idClientStatistiqueBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			   {
				   999999999, 0, 0, 0
			   });
			   this->idClientStatistiqueBox->Name = L"idClientStatistiqueBox";
			   this->idClientStatistiqueBox->Size = System::Drawing::Size(198, 27);
			   this->idClientStatistiqueBox->TabIndex = 55;
			   // 
			   // idClientStatistiqueLabel
			   // 
			   this->idClientStatistiqueLabel->AutoSize = true;
			   this->idClientStatistiqueLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->idClientStatistiqueLabel->Location = System::Drawing::Point(115, 164);
			   this->idClientStatistiqueLabel->Name = L"idClientStatistiqueLabel";
			   this->idClientStatistiqueLabel->Size = System::Drawing::Size(78, 20);
			   this->idClientStatistiqueLabel->TabIndex = 54;
			   this->idClientStatistiqueLabel->Text = L"ID Client :";
			   // 
			   // calculerStatistiqueBouton
			   // 
			   this->calculerStatistiqueBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->calculerStatistiqueBouton->Location = System::Drawing::Point(221, 273);
			   this->calculerStatistiqueBouton->Name = L"calculerStatistiqueBouton";
			   this->calculerStatistiqueBouton->Size = System::Drawing::Size(142, 32);
			   this->calculerStatistiqueBouton->TabIndex = 53;
			   this->calculerStatistiqueBouton->Text = L"Calculer 🧮";
			   this->calculerStatistiqueBouton->UseVisualStyleBackColor = true;
			   this->calculerStatistiqueBouton->Click += gcnew System::EventHandler(this, &Projet::clickOnCalculerStatistiques);
			   // 
			   // moisStatistiquesLabel
			   // 
			   this->moisStatistiquesLabel->AutoSize = true;
			   this->moisStatistiquesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->moisStatistiquesLabel->Location = System::Drawing::Point(140, 126);
			   this->moisStatistiquesLabel->Name = L"moisStatistiquesLabel";
			   this->moisStatistiquesLabel->Size = System::Drawing::Size(53, 20);
			   this->moisStatistiquesLabel->TabIndex = 52;
			   this->moisStatistiquesLabel->Text = L"Mois :";
			   // 
			   // statistiqueTitleLabel
			   // 
			   this->statistiqueTitleLabel->AutoSize = true;
			   this->statistiqueTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->statistiqueTitleLabel->Location = System::Drawing::Point(192, 3);
			   this->statistiqueTitleLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->statistiqueTitleLabel->Name = L"statistiqueTitleLabel";
			   this->statistiqueTitleLabel->Size = System::Drawing::Size(205, 42);
			   this->statistiqueTitleLabel->TabIndex = 51;
			   this->statistiqueTitleLabel->Text = L"Statistiques";
			   // 
			   // statistiqueBox
			   // 
			   this->statistiqueBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->statistiqueBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->statistiqueBox->FormattingEnabled = true;
			   this->statistiqueBox->Items->AddRange(gcnew cli::array< System::Object^  >(8)
			   {
				   L"Panier moyen (après remise)", L"Chiffre d’affaire sur un mois en particulier",
					   L"Produits sous le seuil de réapprovisionnement", L"Montant total des achats pour un client", L"Les 10 articles les plus vendus",
					   L"Les 10 articles les moins vendus", L"Valeur commerciale du stock", L"Valeur d’achat du stock"
			   });
			   this->statistiqueBox->Location = System::Drawing::Point(73, 62);
			   this->statistiqueBox->Name = L"statistiqueBox";
			   this->statistiqueBox->Size = System::Drawing::Size(414, 28);
			   this->statistiqueBox->TabIndex = 9;
			   this->statistiqueBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Projet::clickOnStatistiqueBox);
			   this->statistiqueBox->SelectedIndex = 0;
			   // 
			   // dateMoisStatistiquePicker
			   // 
			   this->dateMoisStatistiquePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateMoisStatistiquePicker->CustomFormat = L"MMMM yyyy";
			   this->dateMoisStatistiquePicker->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateMoisStatistiquePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			   this->dateMoisStatistiquePicker->Location = System::Drawing::Point(199, 121);
			   this->dateMoisStatistiquePicker->Name = L"dateMoisStatistiquePicker";
			   this->dateMoisStatistiquePicker->Size = System::Drawing::Size(198, 27);
			   this->dateMoisStatistiquePicker->TabIndex = 0;
			   // 
			   // tabClients
			   // 
			   this->tabClients->Controls->Add(this->adresseFacturationClientLabel);
			   this->tabClients->Controls->Add(this->adresseFacturationClientBouton);
			   this->tabClients->Controls->Add(this->adresseLivraisonClientLabel);
			   this->tabClients->Controls->Add(this->datePremierAchatClientPicker);
			   this->tabClients->Controls->Add(this->datePremierAchatClientLabel);
			   this->tabClients->Controls->Add(this->adresseLivraisonClientBouton);
			   this->tabClients->Controls->Add(this->dateNaissanceClientPicker);
			   this->tabClients->Controls->Add(this->dateNaissanceClientLabel);
			   this->tabClients->Controls->Add(this->label8);
			   this->tabClients->Controls->Add(this->prenomClientLabel);
			   this->tabClients->Controls->Add(this->prenomClientBox);
			   this->tabClients->Controls->Add(this->idClientBox);
			   this->tabClients->Controls->Add(this->nomClientBox);
			   this->tabClients->Controls->Add(this->idClientLabel);
			   this->tabClients->Controls->Add(this->nomClientLabel);
			   this->tabClients->Location = System::Drawing::Point(4, 22);
			   this->tabClients->Margin = System::Windows::Forms::Padding(2);
			   this->tabClients->Name = L"tabClients";
			   this->tabClients->Size = System::Drawing::Size(577, 324);
			   this->tabClients->TabIndex = 4;
			   this->tabClients->Text = L"Client";
			   this->tabClients->UseVisualStyleBackColor = true;
			   // 
			   // adresseFacturationClientLabel
			   // 
			   this->adresseFacturationClientLabel->AutoSize = true;
			   this->adresseFacturationClientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->adresseFacturationClientLabel->Location = System::Drawing::Point(16, 251);
			   this->adresseFacturationClientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->adresseFacturationClientLabel->Name = L"adresseFacturationClientLabel";
			   this->adresseFacturationClientLabel->Size = System::Drawing::Size(162, 20);
			   this->adresseFacturationClientLabel->TabIndex = 50;
			   this->adresseFacturationClientLabel->Text = L"Adresse Facturation :";
			   // 
			   // adresseFacturationClientBouton
			   // 
			   this->adresseFacturationClientBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->adresseFacturationClientBouton->Location = System::Drawing::Point(193, 248);
			   this->adresseFacturationClientBouton->Name = L"adresseFacturationClientBouton";
			   this->adresseFacturationClientBouton->Size = System::Drawing::Size(244, 27);
			   this->adresseFacturationClientBouton->TabIndex = 49;
			   this->adresseFacturationClientBouton->Text = L"Aucune Adresse";
			   this->adresseFacturationClientBouton->UseVisualStyleBackColor = true;
			   this->adresseFacturationClientBouton->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonAdresseFacturationClient);
			   // 
			   // adresseLivraisonClientLabel
			   // 
			   this->adresseLivraisonClientLabel->AutoSize = true;
			   this->adresseLivraisonClientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->adresseLivraisonClientLabel->Location = System::Drawing::Point(34, 218);
			   this->adresseLivraisonClientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->adresseLivraisonClientLabel->Name = L"adresseLivraisonClientLabel";
			   this->adresseLivraisonClientLabel->Size = System::Drawing::Size(144, 20);
			   this->adresseLivraisonClientLabel->TabIndex = 17;
			   this->adresseLivraisonClientLabel->Text = L"Adresse Livraison :";
			   // 
			   // datePremierAchatClientPicker
			   // 
			   this->datePremierAchatClientPicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->datePremierAchatClientPicker->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->datePremierAchatClientPicker->Location = System::Drawing::Point(193, 182);
			   this->datePremierAchatClientPicker->Name = L"datePremierAchatClientPicker";
			   this->datePremierAchatClientPicker->Size = System::Drawing::Size(244, 27);
			   this->datePremierAchatClientPicker->TabIndex = 48;
			   // 
			   // datePremierAchatClientLabel
			   // 
			   this->datePremierAchatClientLabel->AutoSize = true;
			   this->datePremierAchatClientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->datePremierAchatClientLabel->Location = System::Drawing::Point(22, 187);
			   this->datePremierAchatClientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->datePremierAchatClientLabel->Name = L"datePremierAchatClientLabel";
			   this->datePremierAchatClientLabel->Size = System::Drawing::Size(156, 20);
			   this->datePremierAchatClientLabel->TabIndex = 47;
			   this->datePremierAchatClientLabel->Text = L"Date premier achat :";
			   // 
			   // adresseLivraisonClientBouton
			   // 
			   this->adresseLivraisonClientBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->adresseLivraisonClientBouton->Location = System::Drawing::Point(193, 215);
			   this->adresseLivraisonClientBouton->Name = L"adresseLivraisonClientBouton";
			   this->adresseLivraisonClientBouton->Size = System::Drawing::Size(244, 27);
			   this->adresseLivraisonClientBouton->TabIndex = 16;
			   this->adresseLivraisonClientBouton->Text = L"Aucune Adresse";
			   this->adresseLivraisonClientBouton->UseVisualStyleBackColor = true;
			   this->adresseLivraisonClientBouton->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonAdresseLivraisonClient);
			   // 
			   // dateNaissanceClientPicker
			   // 
			   this->dateNaissanceClientPicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateNaissanceClientPicker->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateNaissanceClientPicker->Location = System::Drawing::Point(193, 149);
			   this->dateNaissanceClientPicker->Name = L"dateNaissanceClientPicker";
			   this->dateNaissanceClientPicker->Size = System::Drawing::Size(244, 27);
			   this->dateNaissanceClientPicker->TabIndex = 46;
			   // 
			   // dateNaissanceClientLabel
			   // 
			   this->dateNaissanceClientLabel->AutoSize = true;
			   this->dateNaissanceClientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateNaissanceClientLabel->Location = System::Drawing::Point(31, 154);
			   this->dateNaissanceClientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->dateNaissanceClientLabel->Name = L"dateNaissanceClientLabel";
			   this->dateNaissanceClientLabel->Size = System::Drawing::Size(147, 20);
			   this->dateNaissanceClientLabel->TabIndex = 45;
			   this->dateNaissanceClientLabel->Text = L"Date de naissance :";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label8->Location = System::Drawing::Point(236, 3);
			   this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(127, 42);
			   this->label8->TabIndex = 45;
			   this->label8->Text = L"Clients";
			   // 
			   // prenomClientLabel
			   // 
			   this->prenomClientLabel->AutoSize = true;
			   this->prenomClientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->prenomClientLabel->Location = System::Drawing::Point(104, 120);
			   this->prenomClientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->prenomClientLabel->Name = L"prenomClientLabel";
			   this->prenomClientLabel->Size = System::Drawing::Size(74, 20);
			   this->prenomClientLabel->TabIndex = 21;
			   this->prenomClientLabel->Text = L"Prénom :";
			   // 
			   // prenomClientBox
			   // 
			   this->prenomClientBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->prenomClientBox->Location = System::Drawing::Point(193, 117);
			   this->prenomClientBox->Margin = System::Windows::Forms::Padding(2);
			   this->prenomClientBox->Name = L"prenomClientBox";
			   this->prenomClientBox->Size = System::Drawing::Size(244, 27);
			   this->prenomClientBox->TabIndex = 20;
			   // 
			   // idClientBox
			   // 
			   this->idClientBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->idClientBox->Location = System::Drawing::Point(193, 55);
			   this->idClientBox->Margin = System::Windows::Forms::Padding(2);
			   this->idClientBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			   {
				   999999999, 0, 0, 0
			   });
			   this->idClientBox->Name = L"idClientBox";
			   this->idClientBox->Size = System::Drawing::Size(243, 27);
			   this->idClientBox->TabIndex = 16;
			   // 
			   // nomClientBox
			   // 
			   this->nomClientBox->BackColor = System::Drawing::SystemColors::Window;
			   this->nomClientBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->nomClientBox->Location = System::Drawing::Point(193, 86);
			   this->nomClientBox->Margin = System::Windows::Forms::Padding(2);
			   this->nomClientBox->Name = L"nomClientBox";
			   this->nomClientBox->Size = System::Drawing::Size(243, 27);
			   this->nomClientBox->TabIndex = 17;
			   // 
			   // idClientLabel
			   // 
			   this->idClientLabel->AutoSize = true;
			   this->idClientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->idClientLabel->Location = System::Drawing::Point(146, 57);
			   this->idClientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->idClientLabel->Name = L"idClientLabel";
			   this->idClientLabel->Size = System::Drawing::Size(32, 20);
			   this->idClientLabel->TabIndex = 18;
			   this->idClientLabel->Text = L"ID :";
			   // 
			   // nomClientLabel
			   // 
			   this->nomClientLabel->AutoSize = true;
			   this->nomClientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->nomClientLabel->Location = System::Drawing::Point(125, 89);
			   this->nomClientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->nomClientLabel->Name = L"nomClientLabel";
			   this->nomClientLabel->Size = System::Drawing::Size(53, 20);
			   this->nomClientLabel->TabIndex = 19;
			   this->nomClientLabel->Text = L"Nom :";
			   // 
			   // tabCommandes
			   // 
			   this->tabCommandes->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->tabCommandes->Controls->Add(this->idClientCommandeLabel);
			   this->tabCommandes->Controls->Add(this->idClientCommandeBox);
			   this->tabCommandes->Controls->Add(this->articlesCommandeLabel);
			   this->tabCommandes->Controls->Add(this->button1);
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
			   // idClientCommandeLabel
			   // 
			   this->idClientCommandeLabel->AutoSize = true;
			   this->idClientCommandeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->idClientCommandeLabel->Location = System::Drawing::Point(100, 215);
			   this->idClientCommandeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->idClientCommandeLabel->Name = L"idClientCommandeLabel";
			   this->idClientCommandeLabel->Size = System::Drawing::Size(78, 20);
			   this->idClientCommandeLabel->TabIndex = 44;
			   this->idClientCommandeLabel->Text = L"Client ID :";
			   // 
			   // idClientCommandeBox
			   // 
			   this->idClientCommandeBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->idClientCommandeBox->Location = System::Drawing::Point(184, 213);
			   this->idClientCommandeBox->Margin = System::Windows::Forms::Padding(2);
			   this->idClientCommandeBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			   {
				   999999999, 0, 0, 0
			   });
			   this->idClientCommandeBox->Name = L"idClientCommandeBox";
			   this->idClientCommandeBox->Size = System::Drawing::Size(243, 27);
			   this->idClientCommandeBox->TabIndex = 16;
			   // 
			   // articlesCommandeLabel
			   // 
			   this->articlesCommandeLabel->AutoSize = true;
			   this->articlesCommandeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->articlesCommandeLabel->Location = System::Drawing::Point(210, 254);
			   this->articlesCommandeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->articlesCommandeLabel->Name = L"articlesCommandeLabel";
			   this->articlesCommandeLabel->Size = System::Drawing::Size(188, 19);
			   this->articlesCommandeLabel->TabIndex = 43;
			   this->articlesCommandeLabel->Text = L"Article(s) de la commande (0)";
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
			   this->moyenPayementCommandeBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
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
			   this->tabStocks->Controls->Add(this->tvaStockLabel);
			   this->tabStocks->Controls->Add(this->tvaStockBox);
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
			   // tvaStockLabel
			   // 
			   this->tvaStockLabel->AutoSize = true;
			   this->tvaStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->tvaStockLabel->Location = System::Drawing::Point(131, 276);
			   this->tvaStockLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->tvaStockLabel->Name = L"tvaStockLabel";
			   this->tvaStockLabel->Size = System::Drawing::Size(47, 20);
			   this->tvaStockLabel->TabIndex = 27;
			   this->tvaStockLabel->Text = L"TVA :";
			   // 
			   // tvaStockBox
			   // 
			   this->tvaStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->tvaStockBox->Location = System::Drawing::Point(196, 274);
			   this->tvaStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->tvaStockBox->Name = L"tvaStockBox";
			   this->tvaStockBox->Size = System::Drawing::Size(244, 27);
			   this->tvaStockBox->TabIndex = 26;
			   // 
			   // quantiteStockLabel
			   // 
			   this->quantiteStockLabel->AutoSize = true;
			   this->quantiteStockLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->quantiteStockLabel->Location = System::Drawing::Point(98, 245);
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
			   this->seuilStockLabel->Location = System::Drawing::Point(85, 214);
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
			   this->couleurStockLabel->Location = System::Drawing::Point(104, 184);
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
			   this->natureStockLabel->Location = System::Drawing::Point(111, 153);
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
			   this->quantiteStockBox->Location = System::Drawing::Point(196, 243);
			   this->quantiteStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->quantiteStockBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			   {
				   1410065407, 2, 0, 0
			   });
			   this->quantiteStockBox->Name = L"quantiteStockBox";
			   this->quantiteStockBox->Size = System::Drawing::Size(244, 27);
			   this->quantiteStockBox->TabIndex = 21;
			   // 
			   // seuilStockBox
			   // 
			   this->seuilStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->seuilStockBox->Location = System::Drawing::Point(196, 212);
			   this->seuilStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->seuilStockBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			   {
				   999999999, 0, 0, 0
			   });
			   this->seuilStockBox->Name = L"seuilStockBox";
			   this->seuilStockBox->Size = System::Drawing::Size(244, 27);
			   this->seuilStockBox->TabIndex = 20;
			   // 
			   // couleurStockBox
			   // 
			   this->couleurStockBox->BackColor = System::Drawing::SystemColors::Window;
			   this->couleurStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->couleurStockBox->Location = System::Drawing::Point(196, 181);
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
			   this->natureStockBox->Location = System::Drawing::Point(196, 150);
			   this->natureStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->natureStockBox->Name = L"natureStockBox";
			   this->natureStockBox->Size = System::Drawing::Size(244, 27);
			   this->natureStockBox->TabIndex = 18;
			   // 
			   // prixStockBox
			   // 
			   this->prixStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->prixStockBox->Location = System::Drawing::Point(196, 119);
			   this->prixStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->prixStockBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			   {
				   999999999, 0, 0, 0
			   });
			   this->prixStockBox->Name = L"prixStockBox";
			   this->prixStockBox->Size = System::Drawing::Size(244, 27);
			   this->prixStockBox->TabIndex = 17;
			   // 
			   // nomStockBox
			   // 
			   this->nomStockBox->BackColor = System::Drawing::SystemColors::Window;
			   this->nomStockBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->nomStockBox->Location = System::Drawing::Point(196, 88);
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
			   this->prixStockLabel->Location = System::Drawing::Point(134, 121);
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
			   this->nomStockLabel->Location = System::Drawing::Point(125, 91);
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
			   this->idStockLabel->Location = System::Drawing::Point(146, 60);
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
			   this->label2->Location = System::Drawing::Point(251, 3);
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
			   this->idStockBox->Location = System::Drawing::Point(196, 57);
			   this->idStockBox->Margin = System::Windows::Forms::Padding(2);
			   this->idStockBox->Name = L"idStockBox";
			   this->idStockBox->Size = System::Drawing::Size(244, 27);
			   this->idStockBox->TabIndex = 12;
			   // 
			   // tabPersonnel
			   // 
			   this->tabPersonnel->Controls->Add(this->superviseurPersonnelCheckBox);
			   this->tabPersonnel->Controls->Add(this->idSuperviseurPersonnelLabel);
			   this->tabPersonnel->Controls->Add(this->idSuperviseurPersonnelBox);
			   this->tabPersonnel->Controls->Add(this->adressePersonnelLabel);
			   this->tabPersonnel->Controls->Add(this->adressePersonnelBouton);
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
			   // idSuperviseurPersonnelLabel
			   // 
			   this->idSuperviseurPersonnelLabel->AutoSize = true;
			   this->idSuperviseurPersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->idSuperviseurPersonnelLabel->Location = System::Drawing::Point(68, 219);
			   this->idSuperviseurPersonnelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->idSuperviseurPersonnelLabel->Name = L"idSuperviseurPersonnelLabel";
			   this->idSuperviseurPersonnelLabel->Size = System::Drawing::Size(122, 20);
			   this->idSuperviseurPersonnelLabel->TabIndex = 15;
			   this->idSuperviseurPersonnelLabel->Text = L"ID Superviseur :";
			   // 
			   // idSuperviseurPersonnelBox
			   // 
			   this->idSuperviseurPersonnelBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->idSuperviseurPersonnelBox->Location = System::Drawing::Point(205, 217);
			   this->idSuperviseurPersonnelBox->Margin = System::Windows::Forms::Padding(2);
			   this->idSuperviseurPersonnelBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			   {
				   999999999, 0, 0, 0
			   });
			   this->idSuperviseurPersonnelBox->Name = L"idSuperviseurPersonnelBox";
			   this->idSuperviseurPersonnelBox->Size = System::Drawing::Size(243, 27);
			   this->idSuperviseurPersonnelBox->TabIndex = 14;
			   // 
			   // adressePersonnelLabel
			   // 
			   this->adressePersonnelLabel->AutoSize = true;
			   this->adressePersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->adressePersonnelLabel->Location = System::Drawing::Point(114, 188);
			   this->adressePersonnelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->adressePersonnelLabel->Name = L"adressePersonnelLabel";
			   this->adressePersonnelLabel->Size = System::Drawing::Size(76, 20);
			   this->adressePersonnelLabel->TabIndex = 13;
			   this->adressePersonnelLabel->Text = L"Adresse :";
			   // 
			   // adressePersonnelBouton
			   // 
			   this->adressePersonnelBouton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->adressePersonnelBouton->Location = System::Drawing::Point(206, 185);
			   this->adressePersonnelBouton->Name = L"adressePersonnelBouton";
			   this->adressePersonnelBouton->Size = System::Drawing::Size(243, 27);
			   this->adressePersonnelBouton->TabIndex = 12;
			   this->adressePersonnelBouton->Text = L"Aucune Adresse";
			   this->adressePersonnelBouton->UseVisualStyleBackColor = true;
			   this->adressePersonnelBouton->Click += gcnew System::EventHandler(this, &Projet::clickOnBoutonAdressePersonnel);
			   // 
			   // dateEmbauchePersonnelLabel
			   // 
			   this->dateEmbauchePersonnelLabel->AutoSize = true;
			   this->dateEmbauchePersonnelLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->dateEmbauchePersonnelLabel->Location = System::Drawing::Point(45, 158);
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
			   this->dateEmbauchePersonnelPicker->CustomFormat = L"MMMM yyyy";
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
			   this->prenomPersonnelLabel->Location = System::Drawing::Point(116, 125);
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
			   this->nomPersonnelLabel->Location = System::Drawing::Point(137, 94);
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
			   this->idPersonnelLabel->Location = System::Drawing::Point(158, 62);
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
			   // personnelTitreLabel
			   // 
			   this->personnelTitreLabel->AutoSize = true;
			   this->personnelTitreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->personnelTitreLabel->Location = System::Drawing::Point(208, 3);
			   this->personnelTitreLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->personnelTitreLabel->Name = L"personnelTitreLabel";
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
			   this->tabAccueil->Controls->Add(this->superviseurCheckBox);
			   this->tabAccueil->Controls->Add(this->connexionBouton);
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
			   // superviseurCheckBox
			   // 
			   this->superviseurCheckBox->AutoSize = true;
			   this->superviseurCheckBox->Location = System::Drawing::Point(401, 242);
			   this->superviseurCheckBox->Name = L"superviseurCheckBox";
			   this->superviseurCheckBox->Size = System::Drawing::Size(82, 17);
			   this->superviseurCheckBox->TabIndex = 13;
			   this->superviseurCheckBox->Text = L"Superviseur";
			   this->superviseurCheckBox->UseVisualStyleBackColor = true;
			   // 
			   // connexionBouton
			   // 
			   this->connexionBouton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->connexionBouton->Location = System::Drawing::Point(186, 237);
			   this->connexionBouton->Margin = System::Windows::Forms::Padding(2);
			   this->connexionBouton->Name = L"connexionBouton";
			   this->connexionBouton->Size = System::Drawing::Size(208, 24);
			   this->connexionBouton->TabIndex = 12;
			   this->connexionBouton->Text = L"Connexion";
			   this->connexionBouton->UseVisualStyleBackColor = true;
			   this->connexionBouton->Click += gcnew System::EventHandler(this, &Projet::clickOnConnexionBDD);
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
			   this->boutonAfficherTout->Location = System::Drawing::Point(42, 368);
			   this->boutonAfficherTout->Name = L"boutonAfficherTout";
			   this->boutonAfficherTout->Size = System::Drawing::Size(114, 26);
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
			   // 
			   // rechercheColonnesBox
			   // 
			   this->rechercheColonnesBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->rechercheColonnesBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->rechercheColonnesBox->FormattingEnabled = true;
			   this->rechercheColonnesBox->Location = System::Drawing::Point(307, 368);
			   this->rechercheColonnesBox->Name = L"rechercheColonnesBox";
			   this->rechercheColonnesBox->Size = System::Drawing::Size(112, 25);
			   this->rechercheColonnesBox->TabIndex = 11;
			   // 
			   // rechercheBox
			   // 
			   this->rechercheBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->rechercheBox->Location = System::Drawing::Point(162, 369);
			   this->rechercheBox->Name = L"rechercheBox";
			   this->rechercheBox->Size = System::Drawing::Size(141, 23);
			   this->rechercheBox->TabIndex = 12;
			   // 
			   // voirRequetesCheckBox
			   // 
			   this->voirRequetesCheckBox->AutoSize = true;
			   this->voirRequetesCheckBox->Location = System::Drawing::Point(506, 440);
			   this->voirRequetesCheckBox->Name = L"voirRequetesCheckBox";
			   this->voirRequetesCheckBox->Size = System::Drawing::Size(88, 17);
			   this->voirRequetesCheckBox->TabIndex = 13;
			   this->voirRequetesCheckBox->Text = L"Voir requêtes";
			   this->voirRequetesCheckBox->UseVisualStyleBackColor = true;
			   // 
			   // clearBouton
			   // 
			   this->clearBouton->Location = System::Drawing::Point(15, 369);
			   this->clearBouton->Name = L"clearBouton";
			   this->clearBouton->Size = System::Drawing::Size(24, 24);
			   this->clearBouton->TabIndex = 14;
			   this->clearBouton->Text = L"✕";
			   this->clearBouton->UseVisualStyleBackColor = true;
			   this->clearBouton->Click += gcnew System::EventHandler(this, &Projet::clickOnClearBouton);
			   // 
			   // superviseurPersonnelCheckBox
			   // 
			   this->superviseurPersonnelCheckBox->AutoSize = true;
			   this->superviseurPersonnelCheckBox->Location = System::Drawing::Point(205, 250);
			   this->superviseurPersonnelCheckBox->Name = L"superviseurPersonnelCheckBox";
			   this->superviseurPersonnelCheckBox->Size = System::Drawing::Size(130, 17);
			   this->superviseurPersonnelCheckBox->TabIndex = 16;
			   this->superviseurPersonnelCheckBox->Text = L"Personnel supervisé \?";
			   this->superviseurPersonnelCheckBox->UseVisualStyleBackColor = true;this->superviseurCheckBox->CheckedChanged += gcnew System::EventHandler(this, &Projet::clickOnSuperviseurCheckBox);
			   this->superviseurPersonnelCheckBox->CheckedChanged += gcnew System::EventHandler(this, &Projet::clickOnSuperviseurCheckBox);
			   // 
			   // Projet
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoSize = true;
			   this->BackColor = System::Drawing::SystemColors::ScrollBar;
			   this->ClientSize = System::Drawing::Size(1190, 573);
			   this->Controls->Add(this->clearBouton);
			   this->Controls->Add(this->voirRequetesCheckBox);
			   this->Controls->Add(this->rechercheBox);
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
			   this->tabStatistiques->ResumeLayout(false);
			   this->tabStatistiques->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idClientStatistiqueBox))->EndInit();
			   this->tabClients->ResumeLayout(false);
			   this->tabClients->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idClientBox))->EndInit();
			   this->tabCommandes->ResumeLayout(false);
			   this->tabCommandes->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idClientCommandeBox))->EndInit();
			   this->tabStocks->ResumeLayout(false);
			   this->tabStocks->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tvaStockBox))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quantiteStockBox))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seuilStockBox))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prixStockBox))->EndInit();
			   this->tabPersonnel->ResumeLayout(false);
			   this->tabPersonnel->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idSuperviseurPersonnelBox))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idPersonnelBox))->EndInit();
			   this->tabAccueil->ResumeLayout(false);
			   this->tabAccueil->PerformLayout();
			   this->tabController->ResumeLayout(false);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

	private: System::Void onFormLoad(System::Object^ sender, System::EventArgs^ e);
	private: System::Void setConnected(bool connected);
	private: System::Void clickOnBoutonValider(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnConnexionBDD(System::Object^ sender, System::EventArgs^ e);
	private: System::Void addHistorique(System::String^ historique);
	private: System::Void clickOnBoutonAfficher(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnBoutonSupprimer(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnBoutonAjouter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnBoutonModifier(System::Object^ sender, System::EventArgs^ e);
	private: System::Void changeMode(SqlMode mode);
	private: System::Void clickOnBoutonArticlesCommandes(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnBoutonAfficherTout(System::Object^ sender, System::EventArgs^ e);
	private: System::Void onChangeTab(System::Object^ sender, System::Windows::Forms::TabControlEventArgs^ e);
	private: System::Void afficherTable();
	private: System::Void clickOnCellule(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void clickOnBoutonAdressePersonnel(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnBoutonAdresseLivraisonClient(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnBoutonAdresseFacturationClient(System::Object^ sender, System::EventArgs^ e);
	private: System::Void updateAdresseBouton(TypeAdresse type);
	private: System::Void clickOnClearBouton(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnCalculerStatistiques(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnStatistiqueBox(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clickOnSuperviseurCheckBox(System::Object^ sender, System::EventArgs^ e);
	private: System::Void resetBoxes();
	private: System::Boolean isActive(System::Windows::Forms::TabPage^ tab);

	public:
		ArrayList^ getArticlesCommande();
		SqlMode getMode();
		AdresseMap^ getPersonnelAdresse();
	public:
		System::Void setAdresseValue(TypeAdresse, AdresseMap^);
		System::Void updateArticlesCommande(ArrayList^ list);
		System::Void addQueryHistorique(System::String^ query);
		System::Void updateRechercheColonneBox();
};
}
#pragma endregion
