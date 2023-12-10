#pragma once
#include "AdresseMap.h"

using namespace System;
using namespace ProjetPOOMappage;

namespace ProjetPOO
{
	public ref class SocieteReference
	{
	public:
		static String^ NAME = "EVAL";
		static String^ LOGO = "logo.png";
		static AdresseMap^ ADRESSE = gcnew AdresseMap(-1, gcnew VilleMap(-1, "Obernai", "67210"), "Rue du Général Gouraud", 80);
		static String^ SERVICE_CLIENT = "03 88 95 50 50";
		static String^ MAIL = "contact@eval.fr";
		static String^ SITE = "www.eval.fr";
	};
}