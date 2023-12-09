#pragma once
#include "PersonneMap.h"
#include "AdresseMap.h"

using namespace System;

namespace ProjetPOOMappage
{
	ref class ClientMap : public PersonneMap
	{
	private:
		DateTime^ dateNaissance; // Date de naissance
		DateTime^ datePremierAchat;
		AdresseMap^ adresseLivraison;
		AdresseMap^ adresseFacturation;
	public:
		ClientMap(int id, String^ nom, String^ prenom, DateTime^ dateNaissance, DateTime^ datePremierAchat, AdresseMap^ adresseLivraison, AdresseMap^ adresseFacturation) : PersonneMap(id, nom, prenom), dateNaissance(dateNaissance), datePremierAchat(datePremierAchat), adresseLivraison(adresseLivraison), adresseFacturation(adresseFacturation)
		{};
		ClientMap() : ClientMap(-1, "", "", gcnew DateTime(), gcnew DateTime(), gcnew AdresseMap(), gcnew AdresseMap())
		{};

		DateTime^ getDateNaissance();
		void setDateNaissance(DateTime^ dateNaissance);
		DateTime^ getDatePremierAchat();
		void setDatePremierAchat(DateTime^ datePremierAchat);
		AdresseMap^ getAdresseLivraison();
		void setAdresseLivraison(AdresseMap^ adresseLivraison);
		AdresseMap^ getAdresseFacturation();
		void setAdresseFacturation(AdresseMap^ adresseFacturation);
	};
}