#pragma once

using namespace System;

ref class PersonneMap
{
protected:
	int id;
	String^ nom;
	String^ prenom;
public:
	PersonneMap(int id, String^ nom, String^ prenom) : id(id), nom(nom), prenom(prenom) {}
	PersonneMap() : PersonneMap(-1, "", "") {}
	void setId(int id);
	int getId();
	void setNom(String^ nom);
	String^ getNom();
	void setPrenom(String^ prenom);
	String^ getPrenom();
};