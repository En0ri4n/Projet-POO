 #pragma once

#define ACCUEIL_TAB 0
#define PERSONNELS_TAB 1
#define STOCKS_TAB 2
#define COMMANDES_TAB 3
#define CLIENTS_TAB 4
#define STATISTIQUES_TAB 5


namespace ProjetPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::TabControl^ tabController;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage6;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabController = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->tabController->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(50, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(180, 71);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Clique moi !";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Projet::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(50, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(180, 71);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ne clique pas";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Projet::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(47, 215);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToOrderColumns = true;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Name, this->id });
			this->dataGridView->Location = System::Drawing::Point(715, 12);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(795, 548);
			this->dataGridView->TabIndex = 3;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Name";
			this->Name->Name = L"Name";
			// 
			// id
			// 
			this->id->HeaderText = L"Id";
			this->id->Name = L"id";
			// 
			// tabController
			// 
			this->tabController->Controls->Add(this->tabPage1);
			this->tabController->Controls->Add(this->tabPage2);
			this->tabController->Controls->Add(this->tabPage3);
			this->tabController->Controls->Add(this->tabPage4);
			this->tabController->Controls->Add(this->tabPage5);
			this->tabController->Controls->Add(this->tabPage6);
			this->tabController->Location = System::Drawing::Point(12, 12);
			this->tabController->Name = L"tabController";
			this->tabController->SelectedIndex = 0;
			this->tabController->Size = System::Drawing::Size(686, 548);
			this->tabController->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(678, 522);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Accueil";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(339, 327);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(195, 49);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Statistiques";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Projet::clickOnStatistiquesTab);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(138, 327);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(195, 49);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Clients";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Projet::clickOnClientsTab);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(438, 272);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(213, 49);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Commandes";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Projet::clickOnCommandesTab);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(237, 272);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(195, 49);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Stocks";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Projet::clickOnStocksTab);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(16, 272);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(215, 49);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Personnel";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Projet::clickOnPersonnelsTab);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 24);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Raccourcis :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(76, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(522, 37);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Bienvenue sur Business Manager";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(678, 522);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Personnel";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &Projet::tabPage2_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(678, 522);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Stocks";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(678, 522);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Commandes";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(678, 522);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Clients";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// tabPage6
			// 
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(678, 522);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Statistiques";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// Projet
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1522, 572);
			this->Controls->Add(this->tabController);
			this->Controls->Add(this->dataGridView);
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Text = L"Business Manager - Powered by EVAL";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->tabController->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Text = "BIEN JOUE";
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Text = "le code va s'autodétruire dans 3 secondes";
	}
	private: System::Void tabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void clickOnPersonnelsTab(System::Object^ sender, System::EventArgs^ e) {
	this->tabController->SelectedIndex = PERSONNELS_TAB;
}
private: System::Void clickOnStocksTab(System::Object^ sender, System::EventArgs^ e) {
	this->tabController->SelectedIndex = STOCKS_TAB;
}
private: System::Void clickOnCommandesTab(System::Object^ sender, System::EventArgs^ e) {
	this->tabController->SelectedIndex = COMMANDES_TAB;
}
private: System::Void clickOnClientsTab(System::Object^ sender, System::EventArgs^ e) {
	this->tabController->SelectedIndex = CLIENTS_TAB;
}
private: System::Void clickOnStatistiquesTab(System::Object^ sender, System::EventArgs^ e) {
	this->tabController->SelectedIndex = STATISTIQUES_TAB;
}
};
}
