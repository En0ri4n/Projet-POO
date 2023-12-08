#include "AdressePopup.h"
#include "Projet.h"

void ProjetPOO::AdressePopup::OnLoadForm(System::Object^ sender, System::EventArgs^ e)
{
	this->idAdresseBox->Text = this->getAdresse()->getIdAdresse().ToString();
	this->idAdresseBox->Enabled = false;
	this->numeroAdresseBox->Value = this->getAdresse()->getNumero();
	this->rueAdresseBox->Text = this->getAdresse()->getRue();
	this->codePostalAdresse->Text = this->getAdresse()->getVille()->getCodePostal();
	this->villeAdresseBox->Text = this->getAdresse()->getVille()->getNom();

	bool active = Projet::instance->getMode() == SqlMode::AFFICHER || Projet::instance->getMode() == SqlMode::SUPPRIMER;

	this->numeroAdresseBox->Enabled = !active;
	this->rueAdresseBox->Enabled = !active;
	this->codePostalAdresse->Enabled = !active;
	this->villeAdresseBox->Enabled = !active;
}

System::Void ProjetPOO::AdressePopup::clickOnBoutonValider(System::Object^ sender, System::EventArgs^ e)
{
	this->getAdresse()->setNumero((int)this->numeroAdresseBox->Value);
	this->getAdresse()->setRue(this->rueAdresseBox->Text);
	this->getAdresse()->getVille()->setCodePostal(this->codePostalAdresse->Text);
	this->getAdresse()->getVille()->setNom(this->villeAdresseBox->Text);
	Projet::instance->setAdresseValue(typeAdresse, getAdresse());
	this->Close();
}

AdresseMap^ ProjetPOO::AdressePopup::getAdresse()
{
	return this->adresse;
}
