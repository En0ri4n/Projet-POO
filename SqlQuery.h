#pragma once

using namespace System;

namespace ProjetPOOMappage
{
	ref class SqlQuery
	{
	private:
		String^ sSql;
		int Id;
		String^ nom;
		String^ prenom;
	public:
		String^ Select(void);
		String^ Insert(void);
		String^ Delete(void);
		String^ Update(void);
		void setId(int);
		void setNom(String^);
		void setPrenom(String^);
		int getId(void);
		String^ getNom(void);
		String^ getPrenom(void);
	};
}