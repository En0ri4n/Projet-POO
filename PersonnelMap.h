#pragma once
#include "PersonneMap.h"
#include "AdresseMap.h"

using namespace System;

namespace ProjetPOOMappage
{
	ref class PersonnelMap : public PersonneMap
	{
	private:
		DateTime^ dateEmbauche;
		AdresseMap^ adresse;
		int idSuperviseur;
	public:
		PersonnelMap(int id, String^ nom, String^ prenom, AdresseMap^ adresse, DateTime^ dateEmbauche, int idSuperviseur) : PersonneMap(id, nom, prenom), adresse(adresse), dateEmbauche(dateEmbauche), idSuperviseur(idSuperviseur) {}
		PersonnelMap() : PersonnelMap(0, "", "", gcnew AdresseMap(), gcnew DateTime(), -1) {}
		void setAdresse(AdresseMap^);
		AdresseMap^ getAdresse();
		void setDateEmbauche(DateTime^);
		DateTime^ getDateEmbauche();
		void setIdSuperviseur(int);
		int getIdSuperviseur();
	};
}
