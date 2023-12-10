#pragma once

using namespace System;

namespace ProjetPOOMappage
{
	ref class Table
	{
	public:
		static Table^ PERSONNES = gcnew Table(L"Personnes");
		static Table^ PERSONNELS = gcnew Table(L"Personnels");
		static Table^ CLIENTS = gcnew Table(L"Clients");
		static Table^ COMMANDES = gcnew Table(L"Commandes");
		static Table^ ARTICLES = gcnew Table(L"Articles");
		static Table^ ADRESSES = gcnew Table(L"Adresses");
		static Table^ VILLES = gcnew Table(L"Villes");
		static Table^ CONSITUTER_LIEN_COMMANDES_ARTICLES = gcnew Table(L"constituer");

		// Tables pour l'affichage
		static Table^ STATISTIQUES = gcnew Table(L"Statistiques");
	private:
		String^ name;
	private:
		Table(String^ tableName) : name(tableName) {};
	public:
		String^ getName()
		{
			return name;
		};
	};

	ref class SqlQuery
	{
	private:
		static String^ DATABASE_NAME = "Projet";
		bool isTransaction;
		System::Collections::ArrayList^ queries;
	public:
		SqlQuery();
		~SqlQuery();
		void newQuery(bool, String^);
		void addQuery(String^);
		void useTransaction();
		System::Collections::ArrayList^ getQueries();
		String^ toQuery();
	};
}

using namespace ProjetPOOMappage;