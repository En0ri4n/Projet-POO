#pragma once

#include "CLservices.h"


namespace POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			oDs = gcnew System::Data::DataSet();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgv_enr;
	protected:

	private: System::Windows::Forms::Button^ btn_load;
	private: System::Windows::Forms::Button^ btn_insert;
	private: System::Windows::Forms::Button^ btn_delete;
	private: System::Windows::Forms::Button^ btn_update;
	private: System::Windows::Forms::TextBox^ idStockBox;
	private: System::Windows::Forms::TextBox^ prixStockBox;
	private: System::Windows::Forms::TextBox^ tvaStockBox;











	private: NS_Comp_Svc::CLservices^ oSvc;
	private: System::Data::DataSet^ oDs;
	private: System::Windows::Forms::TextBox^ natureStockBox;
	private: System::Windows::Forms::TextBox^ quantiteStockBox;



	private: System::Windows::Forms::TextBox^ seuilStockBox;

	private: System::Windows::Forms::TextBox^ nomStockBox;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;



	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ couleurStockBox;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgv_enr = (gcnew System::Windows::Forms::DataGridView());
			this->btn_load = (gcnew System::Windows::Forms::Button());
			this->btn_insert = (gcnew System::Windows::Forms::Button());
			this->btn_delete = (gcnew System::Windows::Forms::Button());
			this->btn_update = (gcnew System::Windows::Forms::Button());
			this->idStockBox = (gcnew System::Windows::Forms::TextBox());
			this->prixStockBox = (gcnew System::Windows::Forms::TextBox());
			this->tvaStockBox = (gcnew System::Windows::Forms::TextBox());
			this->natureStockBox = (gcnew System::Windows::Forms::TextBox());
			this->quantiteStockBox = (gcnew System::Windows::Forms::TextBox());
			this->seuilStockBox = (gcnew System::Windows::Forms::TextBox());
			this->nomStockBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->couleurStockBox = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_enr))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_enr
			// 
			this->dgv_enr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_enr->Location = System::Drawing::Point(16, 15);
			this->dgv_enr->Margin = System::Windows::Forms::Padding(4);
			this->dgv_enr->Name = L"dgv_enr";
			this->dgv_enr->RowHeadersWidth = 51;
			this->dgv_enr->Size = System::Drawing::Size(991, 185);
			this->dgv_enr->TabIndex = 0;
			// 
			// btn_load
			// 
			this->btn_load->Location = System::Drawing::Point(20, 225);
			this->btn_load->Margin = System::Windows::Forms::Padding(4);
			this->btn_load->Name = L"btn_load";
			this->btn_load->Size = System::Drawing::Size(100, 159);
			this->btn_load->TabIndex = 1;
			this->btn_load->Text = L"Load DB";
			this->btn_load->UseVisualStyleBackColor = true;
			this->btn_load->Click += gcnew System::EventHandler(this, &MyForm::btn_load_Click);
			// 
			// btn_insert
			// 
			this->btn_insert->Location = System::Drawing::Point(128, 225);
			this->btn_insert->Margin = System::Windows::Forms::Padding(4);
			this->btn_insert->Name = L"btn_insert";
			this->btn_insert->Size = System::Drawing::Size(100, 46);
			this->btn_insert->TabIndex = 2;
			this->btn_insert->Text = L"INS";
			this->btn_insert->UseVisualStyleBackColor = true;
			this->btn_insert->Click += gcnew System::EventHandler(this, &MyForm::btn_insert_Click);
			// 
			// btn_delete
			// 
			this->btn_delete->Location = System::Drawing::Point(128, 338);
			this->btn_delete->Margin = System::Windows::Forms::Padding(4);
			this->btn_delete->Name = L"btn_delete";
			this->btn_delete->Size = System::Drawing::Size(100, 46);
			this->btn_delete->TabIndex = 3;
			this->btn_delete->Text = L"DEL";
			this->btn_delete->UseVisualStyleBackColor = true;
			this->btn_delete->Click += gcnew System::EventHandler(this, &MyForm::btn_delete_Click);
			// 
			// btn_update
			// 
			this->btn_update->Location = System::Drawing::Point(128, 282);
			this->btn_update->Margin = System::Windows::Forms::Padding(4);
			this->btn_update->Name = L"btn_update";
			this->btn_update->Size = System::Drawing::Size(100, 46);
			this->btn_update->TabIndex = 4;
			this->btn_update->Text = L"UPD";
			this->btn_update->UseVisualStyleBackColor = true;
			this->btn_update->Click += gcnew System::EventHandler(this, &MyForm::btn_update_Click);
			// 
			// idStockBox
			// 
			this->idStockBox->Location = System::Drawing::Point(236, 225);
			this->idStockBox->Margin = System::Windows::Forms::Padding(4);
			this->idStockBox->Name = L"idStockBox";
			this->idStockBox->Size = System::Drawing::Size(408, 22);
			this->idStockBox->TabIndex = 5;
			// 
			// prixStockBox
			// 
			this->prixStockBox->Location = System::Drawing::Point(236, 303);
			this->prixStockBox->Margin = System::Windows::Forms::Padding(4);
			this->prixStockBox->Name = L"prixStockBox";
			this->prixStockBox->Size = System::Drawing::Size(408, 22);
			this->prixStockBox->TabIndex = 6;
			// 
			// tvaStockBox
			// 
			this->tvaStockBox->Location = System::Drawing::Point(235, 496);
			this->tvaStockBox->Margin = System::Windows::Forms::Padding(4);
			this->tvaStockBox->Name = L"tvaStockBox";
			this->tvaStockBox->Size = System::Drawing::Size(408, 22);
			this->tvaStockBox->TabIndex = 7;
			// 
			// natureStockBox
			// 
			this->natureStockBox->Location = System::Drawing::Point(237, 338);
			this->natureStockBox->Name = L"natureStockBox";
			this->natureStockBox->Size = System::Drawing::Size(407, 22);
			this->natureStockBox->TabIndex = 8;
			// 
			// quantiteStockBox
			// 
			this->quantiteStockBox->Location = System::Drawing::Point(237, 453);
			this->quantiteStockBox->Name = L"quantiteStockBox";
			this->quantiteStockBox->Size = System::Drawing::Size(407, 22);
			this->quantiteStockBox->TabIndex = 9;
			// 
			// seuilStockBox
			// 
			this->seuilStockBox->Location = System::Drawing::Point(237, 411);
			this->seuilStockBox->Name = L"seuilStockBox";
			this->seuilStockBox->Size = System::Drawing::Size(407, 22);
			this->seuilStockBox->TabIndex = 10;
			// 
			// nomStockBox
			// 
			this->nomStockBox->Location = System::Drawing::Point(237, 264);
			this->nomStockBox->Name = L"nomStockBox";
			this->nomStockBox->Size = System::Drawing::Size(407, 22);
			this->nomStockBox->TabIndex = 11;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(673, 303);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 16);
			this->label1->TabIndex = 13;
			this->label1->Text = L"prix_produit_ht";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(689, 502);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 16);
			this->label2->TabIndex = 14;
			this->label2->Text = L"taux_tva";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(682, 459);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 16);
			this->label5->TabIndex = 17;
			this->label5->Text = L"quantite_stock";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(671, 414);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(161, 16);
			this->label6->TabIndex = 18;
			this->label6->Text = L"seuil_reaprovisionnement";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(671, 225);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(74, 16);
			this->label7->TabIndex = 19;
			this->label7->Text = L"= référence";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(671, 270);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(92, 16);
			this->label8->TabIndex = 20;
			this->label8->Text = L"= Désignation ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(863, 225);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 16);
			this->label9->TabIndex = 22;
			this->label9->Text = L"= string";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(680, 338);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(54, 16);
			this->label12->TabIndex = 24;
			this->label12->Text = L"= nature";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(866, 344);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(49, 16);
			this->label13->TabIndex = 25;
			this->label13->Text = L"= string";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(682, 376);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(63, 16);
			this->label17->TabIndex = 29;
			this->label17->Text = L"= Couleur";
			// 
			// couleurStockBox
			// 
			this->couleurStockBox->Location = System::Drawing::Point(235, 373);
			this->couleurStockBox->Name = L"couleurStockBox";
			this->couleurStockBox->Size = System::Drawing::Size(408, 22);
			this->couleurStockBox->TabIndex = 30;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(866, 267);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(49, 16);
			this->label18->TabIndex = 31;
			this->label18->Text = L"= string";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(863, 502);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(33, 16);
			this->label19->TabIndex = 32;
			this->label19->Text = L" = int";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(854, 303);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(52, 16);
			this->label20->TabIndex = 33;
			this->label20->Text = L" = string";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(866, 459);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(33, 16);
			this->label21->TabIndex = 34;
			this->label21->Text = L" = int";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(866, 417);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(33, 16);
			this->label22->TabIndex = 35;
			this->label22->Text = L" = int";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(866, 379);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(52, 16);
			this->label23->TabIndex = 36;
			this->label23->Text = L" = string";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1020, 536);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->couleurStockBox);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->nomStockBox);
			this->Controls->Add(this->seuilStockBox);
			this->Controls->Add(this->quantiteStockBox);
			this->Controls->Add(this->natureStockBox);
			this->Controls->Add(this->tvaStockBox);
			this->Controls->Add(this->prixStockBox);
			this->Controls->Add(this->idStockBox);
			this->Controls->Add(this->btn_update);
			this->Controls->Add(this->btn_delete);
			this->Controls->Add(this->btn_insert);
			this->Controls->Add(this->btn_load);
			this->Controls->Add(this->dgv_enr);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_enr))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_load_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->dgv_enr->Refresh();
		this->oDs = this->oSvc->selectionnerTousLesArticles("Rsl");
		this->dgv_enr->DataSource = this->oDs;
		this->dgv_enr->DataMember = "Rsl";
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->oSvc = gcnew NS_Comp_Svc::CLservices();
	}

	private: System::Void btn_insert_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!VerifierChampsRemplis())
			return;
		
		String^ référence = this->idStockBox->Text;

		String^ prixProduitHT = this->prixStockBox->Text;

		String^ strTauxTVA = this->tvaStockBox->Text;
		int tauxTVA = System::Convert::ToInt32(strTauxTVA);

		String^ nature = this->natureStockBox->Text;

		String^ strQuantiteStock = this->quantiteStockBox->Text;
		int quantiteStock = System::Convert::ToInt32(strQuantiteStock);

		String^ strSeuilReapprovisionnement = this->seuilStockBox->Text;
		int seuilReapprovisionnement = System::Convert::ToInt32(strSeuilReapprovisionnement);

		String^ désignation = this->nomStockBox->Text;

		String^ couleur = this->couleurStockBox->Text;
		

		

		this->oSvc->ajouterUnArticle(référence, prixProduitHT, tauxTVA, nature, quantiteStock, seuilReapprovisionnement, désignation, couleur);

		this->dgv_enr->DataSource = this->oSvc->selectionnerTousLesArticles("Rsl");

		this->idStockBox->Text = "";
		this->prixStockBox->Text = "";
		this->tvaStockBox->Text = "";
		this->natureStockBox->Text = "";
		this->quantiteStockBox->Text = "";
		this->seuilStockBox->Text = "";
		this->nomStockBox->Text = "";
		this->couleurStockBox->Text = "";

	}

	private: System::Void btn_delete_Click(System::Object^ sender, System::EventArgs^ e)
	{
		   String^ référence = this->idStockBox->Text;
		   this->oSvc->supprimerUnArticle(référence);

		   this->dgv_enr->DataSource = this->oSvc->selectionnerTousLesArticles("Rsl");

		   this->idStockBox->Text = "";
		   this->prixStockBox->Text = "";
		   this->tvaStockBox->Text = "";
		   this->natureStockBox->Text = "";
		   this->quantiteStockBox->Text = "";
		   this->seuilStockBox->Text = "";
		   this->nomStockBox->Text = "";
		   this->couleurStockBox->Text = "";
	}





		   


	private: System::Void btn_update_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!VerifierChampsRemplis())
			return;
		
		String^ référence = this->idStockBox->Text;

		String^ prixProduitHT = this->prixStockBox->Text;

		String^ strTauxTVA = this->tvaStockBox->Text;
		int tauxTVA = System::Convert::ToInt32(strTauxTVA);

		String^ nature = this->natureStockBox->Text;

		String^ strQuantiteStock = this->quantiteStockBox->Text;
		int quantiteStock = System::Convert::ToInt32(strQuantiteStock);

		String^ strSeuilReapprovisionnement = this->seuilStockBox->Text;
		int seuilReapprovisionnement = System::Convert::ToInt32(strSeuilReapprovisionnement);

		String^ désignation = this->nomStockBox->Text;

		String^ couleur = this->couleurStockBox->Text;

		this->oSvc->modifierUnArticle(référence, prixProduitHT, tauxTVA, nature, quantiteStock, seuilReapprovisionnement, désignation, couleur);

		this->dgv_enr->DataSource = this->oSvc->selectionnerTousLesArticles("Rsl");

		this->idStockBox->Text = "";
		this->prixStockBox->Text = "";
		this->tvaStockBox->Text = "";
		this->natureStockBox->Text = "";
		this->quantiteStockBox->Text = "";
		this->seuilStockBox->Text = "";
		this->nomStockBox->Text = "";
		this->couleurStockBox->Text = "";
	}


	private: System::Boolean VerifierChampsRemplis()
	{
		if (String::IsNullOrEmpty(idStockBox->Text) || String::IsNullOrEmpty(prixStockBox->Text) ||
			String::IsNullOrEmpty(tvaStockBox->Text) || String::IsNullOrEmpty(natureStockBox->Text) ||
			String::IsNullOrEmpty(quantiteStockBox->Text) || String::IsNullOrEmpty(seuilStockBox->Text) ||
			String::IsNullOrEmpty(nomStockBox->Text) || String::IsNullOrEmpty(couleurStockBox->Text))
		{
			MessageBox::Show("Veuillez remplir tous les champs.", "Champs obligatoires", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return false;
		}
		return true;
	}

};
}


