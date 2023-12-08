#pragma once
#include "AdresseMap.h"
#include "Projet.h"

using namespace ProjetPOOMappage;

namespace ProjetPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdressePopup
	/// </summary>
	public ref class AdressePopup : public System::Windows::Forms::Form
	{
	private:
		int idType;
	public:
		AdressePopup(AdresseMap^ adresse, int idType)
		{
			InitializeComponent();
			this->adresse = adresse;
			this->idType = idType;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdressePopup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private: System::Windows::Forms::TextBox^ rueAdresseBox;
	private: System::Windows::Forms::TextBox^ codePostalAdresse;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ villeAdresseBox;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		AdresseMap^ adresse;

	private: System::Windows::Forms::NumericUpDown^ numeroAdresseBox;
	private: System::Windows::Forms::NumericUpDown^ idAdresseBox;

	private: System::Windows::Forms::Label^ idAdresseLabel;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rueAdresseBox = (gcnew System::Windows::Forms::TextBox());
			this->codePostalAdresse = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->villeAdresseBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numeroAdresseBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->idAdresseBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->idAdresseLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeroAdresseBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idAdresseBox))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(39, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Numéro :";
			// 
			// rueAdresseBox
			// 
			this->rueAdresseBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rueAdresseBox->Location = System::Drawing::Point(122, 92);
			this->rueAdresseBox->Name = L"rueAdresseBox";
			this->rueAdresseBox->Size = System::Drawing::Size(193, 27);
			this->rueAdresseBox->TabIndex = 2;
			// 
			// codePostalAdresse
			// 
			this->codePostalAdresse->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->codePostalAdresse->Location = System::Drawing::Point(122, 134);
			this->codePostalAdresse->Name = L"codePostalAdresse";
			this->codePostalAdresse->Size = System::Drawing::Size(193, 27);
			this->codePostalAdresse->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(71, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Rue :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Code Postal :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(68, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Ville :";
			// 
			// villeAdresseBox
			// 
			this->villeAdresseBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->villeAdresseBox->Location = System::Drawing::Point(122, 167);
			this->villeAdresseBox->Name = L"villeAdresseBox";
			this->villeAdresseBox->Size = System::Drawing::Size(193, 27);
			this->villeAdresseBox->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(224, 210);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 28);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Valider";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdressePopup::clickOnBoutonValider);
			// 
			// numeroAdresseBox
			// 
			this->numeroAdresseBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numeroAdresseBox->Location = System::Drawing::Point(122, 59);
			this->numeroAdresseBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			{
				999999, 0, 0, 0
			});
			this->numeroAdresseBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			{
				1, 0, 0, System::Int32::MinValue
			});
			this->numeroAdresseBox->Name = L"numeroAdresseBox";
			this->numeroAdresseBox->Size = System::Drawing::Size(193, 27);
			this->numeroAdresseBox->TabIndex = 9;
			// 
			// idAdresseBox
			// 
			this->idAdresseBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idAdresseBox->Location = System::Drawing::Point(122, 26);
			this->idAdresseBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4)
			{
				1, 0, 0, System::Int32::MinValue
			});
			this->idAdresseBox->Name = L"idAdresseBox";
			this->idAdresseBox->Size = System::Drawing::Size(193, 27);
			this->idAdresseBox->TabIndex = 11;
			// 
			// idAdresseLabel
			// 
			this->idAdresseLabel->AutoSize = true;
			this->idAdresseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idAdresseLabel->Location = System::Drawing::Point(84, 28);
			this->idAdresseLabel->Name = L"idAdresseLabel";
			this->idAdresseLabel->Size = System::Drawing::Size(32, 20);
			this->idAdresseLabel->TabIndex = 10;
			this->idAdresseLabel->Text = L"ID :";
			// 
			// AdressePopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(348, 261);
			this->Controls->Add(this->idAdresseBox);
			this->Controls->Add(this->idAdresseLabel);
			this->Controls->Add(this->numeroAdresseBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->villeAdresseBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->codePostalAdresse);
			this->Controls->Add(this->rueAdresseBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AdressePopup";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Entrer adresse";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &AdressePopup::OnLoadForm);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeroAdresseBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->idAdresseBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:

			void OnLoadForm(System::Object^ sender, System::EventArgs^ e);
private: System::Void clickOnBoutonValider(System::Object^ sender, System::EventArgs^ e);
	   AdresseMap^ getAdresse() { return this->adresse; }
};
}
