#include "SqlQueries.h"

String^ ProjetPOOServices::SqlQueries::listePersonnel()
{
	return "SELECT Personnels.Id_personnel, Personnes.Nom, Personnes.Prenom, Personnels.Date_embauche, Personnels.Id_superieur, Adresses.Numero_rue, Adresses.Nom_rue, Villes.Nom_ville, Villes.Code_postal FROM [Projet].[dbo].[Personnes] INNER JOIN [Projet].[dbo].[Personnels] ON Personnes.Id_personne = Personnels.Id_personnel INNER JOIN [Projet].[dbo].[Adresses] ON Personnels.Id_adresse = Adresses.Id_adresse INNER JOIN [Projet].[dbo].[Villes] ON Adresses.Id_ville = Villes.Id_ville";
}

String^ ProjetPOOServices::SqlQueries::AjouterPersonnel(PersonnelMap^ personnel)
{
	String^ query = String::Format("DECLARE @IdPersonne INT; DECLARE @NomPersonne VARCHAR(50); DECLARE @PrenomPersonne VARCHAR(50); DECLARE @IdAdresse INT; DECLARE @NomVille VARCHAR(50); DECLARE @CodePostal VARCHAR(10); DECLARE @Date_embauche DATE; DECLARE @Id_superieur INT; DECLARE @Numero_rue INT; DECLARE @Nom_rue VARCHAR(50); SET @Numero_rue = {2}; SET @Nom_rue = '{3}'; SET @NomVille = '{4}'; SET @CodePostal = '{5}'; SET @NomPersonne = '{0}'; SET @PrenomPersonne = '{1}'; SET @Date_embauche = '{6}'; SET @Id_superieur = {7}; BEGIN TRANSACTION; DECLARE @IdVille INT; SET @IdVille = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVille AND Code_postal = @CodePostal); IF @IdVille IS NULL BEGIN ROLLBACK; PRINT 'Ajout annulé car la ville n''existe pas'; END ELSE BEGIN SET @Id_superieur = (SELECT Id_personnel FROM Personnels WHERE Id_personnel = @Id_superieur); IF @Id_superieur IS NULL BEGIN ROLLBACK; PRINT 'Ajout annulé car le supérieur n''existe pas'; END ELSE BEGIN DECLARE @Id_sup_sup INT; SET @Id_sup_sup = (SELECT Id_superieur FROM Personnels WHERE Id_personnel = @Id_superieur); IF @Id_sup_sup IS NOT NULL BEGIN ROLLBACK; PRINT 'Ajout annulé car le supérieur a lui-même un supérieur'; END ELSE BEGIN INSERT INTO Personnes (Nom, Prenom) VALUES (@NomPersonne, @PrenomPersonne); SET @IdPersonne = SCOPE_IDENTITY(); INSERT INTO Adresses (Numero_rue, Nom_rue, Id_ville) VALUES (@Numero_rue, @Nom_rue, @IdVille); SET @IdAdresse = SCOPE_IDENTITY(); INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (@IdPersonne, @Date_embauche, @IdAdresse, @Id_superieur); COMMIT; END; END; END;",
		personnel->getNom(),
		personnel->getPrenom(),
		personnel->getAdresse()->getNumero().ToString(),
		personnel->getAdresse()->getRue(),
		personnel->getAdresse()->getVille()->getNom(),
		personnel->getAdresse()->getVille()->getCodePostal(),
		personnel->getDateEmbauche()->ToShortDateString(),
		personnel->getIdSuperviseur().ToString());

	return query;
}