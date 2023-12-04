#include "SqlQuery.h"

String^ ProjetPOOMappage::SqlQuery::Select(void)
{
	return "SELECT [id], [nom], [prenom] FROM [dbo].[rsl]";
}

String^ ProjetPOOMappage::SqlQuery::Insert(void)
{
	return System::String::Format("INSERT INTO rsl (nom, prenom) VALUES('{0}','{1}');", this->nom, this->prenom);
}

String^ ProjetPOOMappage::SqlQuery::Delete(void)
{
	return System::String::Format("DELETE FROM rsl WHERE id={0}", this->Id);
}

String^ ProjetPOOMappage::SqlQuery::Update(void)
{
	return System::String::Format("UPDATE rsl SET nom='{0}', prenom='{1}' WHERE id={2}", this->nom, this->prenom, this->Id);
}

void ProjetPOOMappage::SqlQuery::setId(int Id)
{
	this->Id = Id;
}

void ProjetPOOMappage::SqlQuery::setNom(String^ nom)
{
	this->nom = nom;
}

void ProjetPOOMappage::SqlQuery::setPrenom(String^ prenom)
{
	this->prenom = prenom;
}

int ProjetPOOMappage::SqlQuery::getId(void) { return this->Id; }
String^ ProjetPOOMappage::SqlQuery::getNom(void) { return this->nom; }
String^ ProjetPOOMappage::SqlQuery::getPrenom(void) { return this->prenom; }