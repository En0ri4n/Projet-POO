#pragma once

using namespace System;

namespace ProjetPOOMappage
{
	ref class VilleMap
	{
	private:
		int idVille;
		String^ nom;
		String^ codePostal;
	public:
		VilleMap(int id, String^ nom, String^ codePostal) : idVille(id), nom(nom), codePostal(codePostal) {}
		VilleMap() : VilleMap(-1, "", "") {}

		void setIdVille(int);
		int getIdVille();
		void setNom(String^);
		String^ getNom();
		void setCodePostal(String^);
		String^ getCodePostal();
	};
}