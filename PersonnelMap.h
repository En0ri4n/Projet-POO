#pragma once

using namespace System;

namespace ProjetPOOMappage
{
	ref class PersonnelMap
	{
	private:
		int idPersonnel;
		String^ nom;
		String^ prenom;
		DateTime^ dateEmbauche;
	public:
		PersonnelMap();

		void setIdPersonnel(int);
		int getIdPersonnel();
		void setNom(String^);
		String^ getNom();
		void setPrenom(String^);
		String^ getPrenom();
		void setDateEmbauche(DateTime^);
		DateTime^ getDateEmbauche();
	};
}
