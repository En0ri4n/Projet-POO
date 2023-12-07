#pragma once
#include "VilleMap.h"

using namespace System;

namespace ProjetPOOMappage
{
	ref class AdresseMap
	{
	private:
		int idAdresse;
		VilleMap^ ville;
		String^ rue;
		int numero;
	public:
		AdresseMap(int id, VilleMap^ ville, String^ rue, int numero) : idAdresse(id), ville(ville), rue(rue), numero(numero) {}
		AdresseMap() : AdresseMap(-1, gcnew VilleMap(), "", -1) {}

		void setIdAdresse(int);
		int getIdAdresse();
		void setVille(VilleMap^);
		VilleMap^ getVille();
		void setRue(String^);
		String^ getRue();
		void setNumero(int);
		int getNumero();
	};
}