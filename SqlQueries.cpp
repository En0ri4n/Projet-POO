#include "SqlQueries.h"

String^ ProjetPOOServices::SqlQueries::listePersonnel()
{
	return "SELECT Personnels.Id_personnel, Personnes.Nom, Personnes.Prenom, Personnels.Date_embauche, Personnels.Id_superieur, Adresses.Id_adresse, Adresses.Numero_rue, Adresses.Nom_rue, Villes.Id_ville, Villes.Nom_ville, Villes.Code_postal FROM [Projet].[dbo].[Personnes] INNER JOIN [Projet].[dbo].[Personnels] ON Personnes.Id_personne = Personnels.Id_personnel INNER JOIN [Projet].[dbo].[Adresses] ON Personnels.Id_adresse = Adresses.Id_adresse INNER JOIN [Projet].[dbo].[Villes] ON Adresses.Id_ville = Villes.Id_ville";
}

String^ ProjetPOOServices::SqlQueries::AjouterPersonnel(PersonnelMap^ personnel)
{
	String^ query = String::Format("DECLARE @IdPersonne INT; " +
		"DECLARE @NomPersonne VARCHAR(50); " +
		"DECLARE @PrenomPersonne VARCHAR(50); " +
		"DECLARE @IdAdresse INT; " +
		"DECLARE @NomVille VARCHAR(50); " +
		"DECLARE @CodePostal VARCHAR(10); " +
		"DECLARE @Date_embauche DATE; " +
		"DECLARE @Id_superieur INT; " +
		"DECLARE @Numero_rue INT; " +
		"DECLARE @Nom_rue VARCHAR(50); " +
		" " +
		"SET @Numero_rue = {2}; " +
		"SET @Nom_rue = '{3}'; " +
		"SET @NomVille = '{4}'; " +
		"SET @CodePostal = '{5}'; " +
		"SET @NomPersonne = '{0}'; " +
		"SET @PrenomPersonne = '{1}'; " +
		"SET @Date_embauche = '{6}'; " +
		"SET @Id_superieur = {7}; " +
		" " +
		"BEGIN TRANSACTION; " +
		"DECLARE @IdVille INT; " +
		"SET @IdVille = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVille AND Code_postal = @CodePostal); " +
		" " +
		"IF @IdVille IS NULL " +
		"BEGIN  " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annul� car la ville n''existe pas'; " +
		"END  " +
		"ELSE  " +
		"BEGIN  " +
		"    SET @Id_superieur = (SELECT Id_personnel FROM Personnels WHERE Id_personnel = @Id_superieur); " +
		" " +
		"    IF @Id_superieur IS NULL " +
		"    BEGIN " +
		"        ROLLBACK; " +
		"        PRINT 'Ajout annul� car le sup�rieur n''existe pas'; " +
		"    END " +
		"    ELSE " +
		"    BEGIN " +
		"        DECLARE @Id_sup_sup INT; " +
		"        SET @Id_sup_sup = (SELECT Id_superieur FROM Personnels WHERE Id_personnel = @Id_superieur); " +
		" " +
		"        IF @Id_sup_sup IS NOT NULL " +
		"        BEGIN  " +
		"            ROLLBACK; " +
		"            PRINT 'Ajout annul� car le sup�rieur a lui-m�me un sup�rieur'; " +
		"        END  " +
		"        ELSE  " +
		"        BEGIN  " +
		"            INSERT INTO Personnes (Nom, Prenom) " +
		"            VALUES (@NomPersonne, @PrenomPersonne); " +
		"            SET @IdPersonne = SCOPE_IDENTITY(); " +
		" " +
		"            INSERT INTO Adresses (Numero_rue, Nom_rue, Id_ville) " +
		"            VALUES (@Numero_rue, @Nom_rue, @IdVille); " +
		"            SET @IdAdresse = SCOPE_IDENTITY(); " +
		" " +
		"            INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) " +
		"            VALUES (@IdPersonne, @Date_embauche, @IdAdresse, @Id_superieur); " +
		"            COMMIT; " +
		"        END; " +
		"    END; " +
		"END;",
		personnel->getNom(),
		personnel->getPrenom(),
		personnel->getAdresse()->getNumero().ToString(),
		personnel->getAdresse()->getRue(),
		personnel->getAdresse()->getVille()->getNom(),
		personnel->getAdresse()->getVille()->getCodePostal(),
		personnel->getDateEmbauche()->ToShortDateString(),
		personnel->getIdSuperviseur() == 0 ? "NULL" : personnel->getIdSuperviseur().ToString());

	return query;
}

String^ ProjetPOOServices::SqlQueries::ModifierPersonnel(PersonnelMap^ personnel)
{
	return String::Format("DECLARE @IdPersonne INT; " +
		"DECLARE @NomPersonne VARCHAR(50); " +
		"DECLARE @PrenomPersonne VARCHAR(50); " +
		"DECLARE @IdAdresse INT; " +
		"DECLARE @NomVille VARCHAR(50); " +
		"DECLARE @CodePostal VARCHAR(10); " +
		"DECLARE @Date_embauche DATE; " +
		"DECLARE @Id_superieur INT; " +
		"DECLARE @Numero_rue INT; " +
		"DECLARE @Nom_rue VARCHAR(50); " +
		" " +
		"SET @Numero_rue = {2}; " +
		"SET @Nom_rue = '{3}'; " +
		"SET @NomVille = '{4}'; " +
		"SET @CodePostal = '{5}'; " +
		"SET @NomPersonne = '{0}'; " +
		"SET @PrenomPersonne = '{1}'; " +
		"SET @Date_embauche = '{6}'; " +
		"SET @Id_superieur = {7}; " +
		" " +
		"SET @IdPersonne = {8}; " +
		" " +
		"BEGIN TRANSACTION; " +
		"IF NOT EXISTS (SELECT 1 FROM Personnes WHERE Id_personne = @IdPersonne) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Modification annul�e car la personne n''existe pas'; " +
		"END " +
		"ELSE " +
		"BEGIN " +
		"    DECLARE @IdVille INT; " +
		"    SET @IdVille = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVille AND Code_postal = @CodePostal); " +
		"    IF @IdVille IS NULL " +
		"    BEGIN " +
		// "        -- Annuler la transaction en cas d'erreur " +
		"        ROLLBACK; " +
		"        PRINT 'Modification annul�e car la ville n''existe pas'; " +
		// "        ----- Erreur Adresse ville n'existe pas ------; " +
		"    END " +
		"    ELSE " +
		"    BEGIN " +
		"       SET @Id_superieur = (SELECT Id_personnel FROM Personnels WHERE Id_personnel = @Id_superieur); " +
		"       IF @Id_superieur IS NULL " +
		"       BEGIN " +
		"           ROLLBACK; " +
		"           PRINT 'Modification annul�e car le sup�rieur n''existe pas'; " +
		"       END; " +
		" " +
		"   DECLARE @Id_sup_sup INT; " +
		"       SET @Id_sup_sup = (SELECT Id_superieur FROM Personnels WHERE Id_personnel = @Id_superieur); " +
		" " +
		"       IF @Id_sup_sup IS NOT NULL " +
		"       BEGIN " +
		"           ROLLBACK; " +
		"           PRINT 'Ajout annul� car le sup�rieur a lui-m�me un sup�rieur'; " +
		"       END " +
		"       ELSE " +
		"       BEGIN " +
		"       UPDATE Personnes " +
		"       SET  " +
		"           Nom = @NomPersonne, " +
		"           Prenom = @PrenomPersonne " +
		"       WHERE Id_personne = @IdPersonne; " +
		" " +
		"       UPDATE Adresses " +
		"       SET  " +
		"           Nom_rue = @Nom_rue, " +
		"           Numero_rue = @Numero_rue, " +
		"           Id_ville = @IdVille " +
		"       WHERE Id_adresse = (SELECT Id_adresse FROM Personnels WHERE Id_personnel = @IdPersonne); " +
		" " +
		"       UPDATE Personnels " +
		"       SET " +
		"           Date_embauche = @Date_embauche, " +
		"           Id_superieur = @Id_superieur " +
		"       WHERE Id_personnel = @IdPersonne; " +
		"       COMMIT; " +
		"        END; " +
		"    END; " +
		"END;",
		personnel->getNom(),
		personnel->getPrenom(),
		personnel->getAdresse()->getNumero().ToString(),
		personnel->getAdresse()->getRue(),
		personnel->getAdresse()->getVille()->getNom(),
		personnel->getAdresse()->getVille()->getCodePostal(),
		personnel->getDateEmbauche()->ToShortDateString(),
		personnel->getIdSuperviseur().ToString(),
		personnel->getId());
}

String^ ProjetPOOServices::SqlQueries::SupprimerPersonnel(PersonnelMap^ personnel)
{
	return String::Format("DECLARE @IdPersonnel INT; " +
		"SET @IdPersonnel = {0};  " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM Personnes WHERE Id_personne = @IdPersonnel) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Suppression annul�e car la personne n''existe pas'; " +
		"END " +
		"ELSE " +
		"BEGIN " +
		"    DECLARE @IdAdresse INT; " +
		"    SET @IdAdresse = (SELECT Id_adresse FROM Personnels WHERE Id_personnel = @IdPersonnel); " +
		" " +
		"    DECLARE @IdSuperieur INT; " +
		"    SET @IdSuperieur = (SELECT Id_superieur FROM Personnels WHERE Id_personnel = @IdPersonnel); " +
		" " +
		"    UPDATE Personnels  " +
		"    SET Id_superieur = NULL  " +
		"    WHERE Id_superieur = @IdPersonnel; " +
		" " +
		"    DELETE FROM Personnels WHERE Id_personnel = @IdPersonnel; " +
		"    DELETE FROM Personnes WHERE Id_personne = @IdPersonnel; " +
		"    DELETE FROM Adresses WHERE Id_adresse = @IdAdresse; " +
		" " +
		"    COMMIT; " +
		"END; ",
		personnel->getId());
}

String^ ProjetPOOServices::SqlQueries::listeCommande()
{
	return String::Format("SELECT * FROM {0}", Table::COMMANDES->getName());
}

String^ ProjetPOOServices::SqlQueries::AjouterCommande(CommandeMap^ commande)
{
	return String::Format("DECLARE @IdClientCommande INT; " +
		"DECLARE @DateEmission DATE; " +
		"DECLARE @DateLivraison DATE; " +
		"DECLARE @DatePaiement DATE;  " +
		"DECLARE @MoyenPaiement VARCHAR(50); " +
		"DECLARE @Remise INT; " +
		" " +
		"SET @IdClientCommande = {0};  " +
		"SET @DateEmission = '{1}';  " +
		"SET @DateLivraison = '{2}';  " +
		"SET @DatePaiement = '{3}';  " +
		"SET @MoyenPaiement = '{4}'; " +
		"SET @Remise = CASE " +
		"    WHEN MONTH(@DatePaiement) = MONTH((SELECT Date_naissance FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) " +
		"         AND DAY(@DatePaiement) = DAY((SELECT Date_naissance FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) " +
		"         AND MONTH(@DatePaiement) = MONTH((SELECT Date_premier_achat FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) " +
		"         AND DAY(@DatePaiement) = DAY((SELECT Date_premier_achat FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) THEN 15 " +
		"    WHEN MONTH(@DatePaiement) = MONTH((SELECT Date_naissance FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) " +
		"         AND DAY(@DatePaiement) = DAY((SELECT Date_naissance FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) THEN 10 " +
		"    WHEN MONTH(@DatePaiement) = MONTH((SELECT Date_premier_achat FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) " +
		"         AND DAY(@DatePaiement) = DAY((SELECT Date_premier_achat FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) THEN 5 " +
		"    ELSE 0 " +
		"END; " +
		" " +
		"DECLARE @ReferenceCommande VARCHAR(50); " +
		" " +
		"SET @ReferenceCommande = ( " +
		"    SELECT UPPER(SUBSTRING(Prenom, 1, 2) + SUBSTRING(Nom, 1, 2) + " +
		"        CONVERT(VARCHAR, YEAR(@DateEmission)) + " +
		"        CASE " +
		"            WHEN (LEN((SELECT Nom_ville FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)))) >= 3) " +
		"                THEN SUBSTRING((SELECT UPPER(LEFT(Nom_ville, 3)) FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))), 1, 3) " +
		"            ELSE " +
		"                (SELECT UPPER(Nom_ville) FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))) " +
		"        END + " +
		"        CONVERT(VARCHAR, (SELECT COUNT(*) + 1 FROM [Projet].[dbo].[Commandes]))) " +
		"    FROM [Projet].[dbo].[Personnes] WHERE Id_personne = @IdClientCommande " +
		"); " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annul� car le client n''existe pas'; " +
		"END " +
		" " +
		"ELSE IF @DatePaiement > @DateLivraison OR @DatePaiement > @DateEmission OR @DateEmission > @DateLivraison " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annul� car la date de paiement doit �tre ant�rieure � la date de livraison'; " +
		"END " +
		" " +
		"ELSE IF @MoyenPaiement NOT IN ('Carte', 'Bitcoin', 'Paypal', 'Cash') " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annul� car le moyen de paiement n''est pas disponible' " +
		"END " +
		" " +
		"ELSE " +
		"BEGIN " +
		"    INSERT INTO [Projet].[dbo].[Commandes] (Reference_commande, Date_emission, Date_livraison, Date_paiement, Moyen_paiement, Pourcentage_remise, Id_client) " +
		"    VALUES (@ReferenceCommande, @DateEmission, @DateLivraison, @DatePaiement, @MoyenPaiement, @Remise, @IdClientCommande); " +
		" " +
		"    IF (SELECT COUNT(*) FROM [Projet].[dbo].[Commandes] WHERE Id_client = @IdClientCommande) = 1 " +
		"    BEGIN " +
		"        UPDATE [Projet].[dbo].[Clients]  " +
		"            SET Date_premier_achat = @DatePaiement " +
		"        WHERE Id_client = @IdClientCommande; " +
		"    END  " +
		"    COMMIT; " +
		"END ",
		commande->getIdClient(),
		commande->getDateEmission()->ToShortDateString(),
		commande->getDateLivraison()->ToShortDateString(),
		commande->getDatePaiement()->ToShortDateString(),
		commande->getMoyenPaiement());
}

String^ ProjetPOOServices::SqlQueries::ModifierCommande(CommandeMap^ commande)
{
	return String::Format("DECLARE @IdClientCommande INT; " +
		"DECLARE @ReferenceCommandeAModifier VARCHAR(50); " +
		"DECLARE @NouvelleDateEmission DATE; " +
		"DECLARE @NouvelleDateLivraison DATE; " +
		"DECLARE @NouveauMoyenPaiement VARCHAR(50); " +
		"DECLARE @DatePaiement DATE; " +
		"DECLARE @DateLivraison DATE; " +
		"DECLARE @DateEmission DATE; " +
		" " +
		"SET @IdClientCommande = {0};  " +
		"SET @ReferenceCommandeAModifier = '{1}'; " +
		"SET @NouvelleDateEmission = '{2}'; " +
		"SET @NouvelleDateLivraison = '{3}'; " +
		"SET @NouveauMoyenPaiement = '{4}'; " +
		" " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Commandes] WHERE [Projet].[dbo].[Commandes].Id_client = @IdClientCommande AND [Projet].[dbo].[Commandes].Reference_commande = @ReferenceCommandeAModifier) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'La commande avec la r�f�rence sp�cifi�e n''existe pas pour le client sp�cifi�.'; " +
		"END " +
		" " +
		"ELSE IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande) " +
		"BEGIN  " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annul� car le client n''existe pas'; " +
		"END " +
		" " +
		"ELSE IF @DatePaiement > @DateLivraison OR @DateEmission > @DateLivraison " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annul� car la date de paiement doit �tre ant�rieure � la date de livraison'; " +
		"END " +
		" " +
		"ELSE IF @NouveauMoyenPaiement NOT IN ('Carte', 'Bitcoin', 'Paypal', 'Cash') " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annul� car le moyen de paiement n''est pas disponible' " +
		"END " +
		" " +
		"BEGIN " +
		"    SET @DatePaiement = (SELECT Date_paiement FROM [Projet].[dbo].[Commandes] WHERE Reference_commande = @ReferenceCommandeAModifier) " +
		"    UPDATE [Projet].[dbo].[Commandes] " +
		"    SET  " +
		"        Date_emission = @NouvelleDateEmission, " +
		"        Date_livraison = @NouvelleDateLivraison, " +
		"        Moyen_paiement = @NouveauMoyenPaiement " +
		"    WHERE [Projet].[dbo].[Commandes].Id_client = @IdClientCommande AND [Projet].[dbo].[Commandes].Reference_commande = @ReferenceCommandeAModifier; " +
		" " +
		"    COMMIT; " +
		"    PRINT 'Commande modifi�e avec succ�s.'; " +
		"END ",
		commande->getIdClient(),
		commande->getIdCommande(),
		commande->getDateEmission()->ToShortDateString(),
		commande->getDateLivraison()->ToShortDateString(),
		commande->getMoyenPaiement());
}

String^ ProjetPOOServices::SqlQueries::SupprimerCommande(CommandeMap^ commande)
{
	return String::Format("BEGIN TRANSACTION; " +
		" " +
		"DECLARE @ReferenceCommandeASuppr VARCHAR(50); " +
		"SET @ReferenceCommandeASuppr = '{0}';  " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Commandes] WHERE Reference_commande = @ReferenceCommandeASuppr) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Suppression annul�e car la commande n''existe pas'; " +
		"END " +
		" " +
		"ELSE IF (SELECT Date_paiement FROM [Projet].[dbo].[Commandes] WHERE Commandes.Reference_commande = @ReferenceCommandeASuppr) >= DATEADD(YEAR, -10, GETDATE()) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Suppression annul�e car la date de paiement est plus r�cente que 10 ans'; " +
		"END " +
		" " +
		"ELSE " +
		"BEGIN " +
		"    DELETE FROM [Projet].[dbo].[constituer] WHERE constituer.Reference_commande = @ReferenceCommandeASuppr; " +
		"    DELETE FROM [Projet].[dbo].[Commandes] WHERE Commandes.Reference_commande = @ReferenceCommandeASuppr; " +
		" " +
		"    COMMIT; " +
		"    PRINT 'Suppression de la commande r�ussie'; " +
		"END ",
		commande->getIdCommande());
}

String^ ProjetPOOServices::SqlQueries::listeArticles()
{
	return String::Format("SELECT * FROM {0}", Table::ARTICLES->getName());
}

String^ ProjetPOOServices::SqlQueries::AjouterArticle(ArticleMap^)
{
	throw gcnew System::NotImplementedException();
	// TODO: insert return statement here
}

String^ ProjetPOOServices::SqlQueries::ModifierArticle(ArticleMap^)
{
	throw gcnew System::NotImplementedException();
	// TODO: insert return statement here
}

String^ ProjetPOOServices::SqlQueries::SupprimerArticle(ArticleMap^)
{
	throw gcnew System::NotImplementedException();
	// TODO: insert return statement here
}

String^ ProjetPOOServices::SqlQueries::listeClient()
{
	return "SELECT " +
		"    Clients.Id_client, " +
		"    Clients.Id_adresse_livraison, " +
		"    AdressesLivraison.Nom_rue AS Nom_rue_livraison, " +
		"    AdressesLivraison.Numero_rue AS Numero_rue_livraison, " +
		"    Clients.Id_adresse_facturation, " +
		"    AdressesFacturation.Nom_rue AS Nom_rue_facturation, " +
		"    AdressesFacturation.Numero_rue AS Numero_rue_facturation " +
		"FROM [Projet].[dbo].[Clients] " +
		"LEFT JOIN [Projet].[dbo].[Adresses] AS AdressesLivraison ON Clients.Id_adresse_livraison = AdressesLivraison.Id_adresse " +
		"LEFT JOIN [Projet].[dbo].[Adresses] AS AdressesFacturation ON Clients.Id_adresse_facturation = AdressesFacturation.Id_adresse; ";
}

String^ ProjetPOOServices::SqlQueries::AjouterClient(ClientMap^ client)
{
	return String::Format("DECLARE @IdClient INT; " +
		"DECLARE @NomClient VARCHAR(50); " +
		"DECLARE @PrenomClient VARCHAR(50); " +
		"DECLARE @DateNaissance DATE; " +
		"DECLARE @DatePremierAchat DATE; " +
		"DECLARE @NumeroRueLivraison INT; " +
		"DECLARE @NomRueLivraison VARCHAR(50); " +
		"DECLARE @NomVilleLivraison VARCHAR(50); " +
		"DECLARE @CodePostalLivraison VARCHAR(10); " +
		"DECLARE @NumeroRueFacturation INT; " +
		"DECLARE @NomRueFacturation VARCHAR(50); " +
		"DECLARE @NomVilleFacturation VARCHAR(50); " +
		"DECLARE @CodePostalFacturation VARCHAR(10); " +
		"DECLARE @IdAdresseLivraison INT; " +
		"DECLARE @IdAdresseFacturation INT; " +
		" " +
		"SET @NomClient = '{0}'; " +
		"SET @PrenomClient = '{1}'; " +
		"SET @DateNaissance = '{2}'; " +
		"SET @DatePremierAchat = NULL; " +
		" " +
		"SET @NumeroRueLivraison = {3}; " +
		"SET @NomRueLivraison = '{4}'; " +
		"SET @NomVilleLivraison = '{5}'; " +
		"SET @CodePostalLivraison = '{6}'; " +
		" " +
		"SET @NumeroRueFacturation = {7}; " +
		"SET @NomRueFacturation = '{8}'; " +
		"SET @NomVilleFacturation = '{9}'; " +
		"SET @CodePostalFacturation = '{10}'; " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM Villes WHERE Nom_ville = @NomVilleLivraison AND Code_postal = @CodePostalLivraison) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annul� car la ville de livraison n''existe pas'; " +
		"END " +
		"ELSE " +
		"BEGIN " +
		"    INSERT INTO Personnes (Nom, Prenom) " +
		"    VALUES (@NomClient, @PrenomClient); " +
		"    SET @IdClient = SCOPE_IDENTITY(); " +
		" " +
		"    INSERT INTO Adresses (Numero_rue, Nom_rue, Id_ville) " +
		"    VALUES (@NumeroRueLivraison, @NomRueLivraison, (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVilleLivraison AND Code_postal = @CodePostalLivraison)); " +
		"    SET @IdAdresseLivraison = SCOPE_IDENTITY(); " +
		" " +
		"    INSERT INTO Adresses (Numero_rue, Nom_rue, Id_ville) " +
		"    VALUES (@NumeroRueFacturation, @NomRueFacturation, (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVilleFacturation AND Code_postal = @CodePostalFacturation)); " +
		"    SET @IdAdresseFacturation = SCOPE_IDENTITY(); " +
		" " +
		"    INSERT INTO Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) " +
		"    VALUES (@IdClient, @DateNaissance, @DatePremierAchat, @IdAdresseLivraison, @IdAdresseFacturation); " +
		" " +
		"    COMMIT; " +
		"END; ",
		client->getNom(),
		client->getPrenom(),
		client->getDateNaissance()->ToShortDateString(),

		client->getAdresseLivraison()->getNumero(),
		client->getAdresseLivraison()->getRue(),
		client->getAdresseLivraison()->getVille()->getNom(),
		client->getAdresseLivraison()->getVille()->getCodePostal(),
		
		client->getAdresseFacturation()->getNumero(),
		client->getAdresseFacturation()->getRue(),
		client->getAdresseFacturation()->getVille()->getNom(),
		client->getAdresseFacturation()->getVille()->getCodePostal());
}

String^ ProjetPOOServices::SqlQueries::ModifierClient(ClientMap^ client)
{
	return String::Format("DECLARE @IdClient INT; " +
		"DECLARE @NomClient VARCHAR(50); " +
		"DECLARE @PrenomClient VARCHAR(50); " +
		"DECLARE @DateNaissance DATE; " +
		"DECLARE @DatePremierAchat DATE; " +
		"DECLARE @NumeroRueLivraison INT; " +
		"DECLARE @NomRueLivraison VARCHAR(50); " +
		"DECLARE @NomVilleLivraison VARCHAR(50); " +
		"DECLARE @CodePostalLivraison VARCHAR(10); " +
		"DECLARE @NumeroRueFacturation INT; " +
		"DECLARE @NomRueFacturation VARCHAR(50); " +
		"DECLARE @NomVilleFacturation VARCHAR(50); " +
		"DECLARE @CodePostalFacturation VARCHAR(10); " +
		"DECLARE @IdAdresseLivraison INT; " +
		"DECLARE @IdAdresseFacturation INT; " +
		" " +
		"SET @IdClient = {0}; " +
		"SET @NomClient = '{1}'; " +
		"SET @PrenomClient = '{2}'; " +
		"SET @DateNaissance = '{3}'; " +
		"SET @DatePremierAchat = '{4}'; " +
		" " +
		"SET @NumeroRueLivraison = {5}; " +
		"SET @NomRueLivraison = '{6}'; " +
		"SET @NomVilleLivraison = '{7}'; " +
		"SET @CodePostalLivraison = '{8}'; " +
		" " +
		"SET @NumeroRueFacturation = {9}; " +
		"SET @NomRueFacturation = '{10}'; " +
		"SET @NomVilleFacturation = '{11}'; " +
		"SET @CodePostalFacturation = '{12}'; " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM Clients WHERE Id_client = @IdClient) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Modification annul�e car le client n''existe pas'; " +
		"END " +
		"ELSE " +
		"BEGIN " +
		"    UPDATE Personnes " +
		"    SET " +
		"        Nom = @NomClient, " +
		"        Prenom = @PrenomClient " +
		"    WHERE Id_personne = @IdClient; " +
		" " +
		"    UPDATE Adresses " +
		"    SET " +
		"        Numero_rue = @NumeroRueLivraison, " +
		"        Nom_rue = @NomRueLivraison, " +
		"        Id_ville = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVilleLivraison AND Code_postal = @CodePostalLivraison) " +
		"    WHERE Id_adresse = (SELECT Id_adresse_livraison FROM Clients WHERE Id_client = @IdClient); " +
		" " +
		"    UPDATE Adresses " +
		"    SET " +
		"        Numero_rue = @NumeroRueFacturation, " +
		"        Nom_rue = @NomRueFacturation, " +
		"        Id_ville = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVilleFacturation AND Code_postal = @CodePostalFacturation) " +
		"    WHERE Id_adresse = (SELECT Id_adresse_facturation FROM Clients WHERE Id_client = @IdClient); " +
		" " +
		"    UPDATE Clients " +
		"    SET " +
		"        Date_naissance = @DateNaissance, " +
		"        Date_premier_achat = @DatePremierAchat " +
		"    WHERE Id_client = @IdClient; " +
		" " +
		"    COMMIT; " +
		"END; ",
		client->getId(),
		client->getNom(),
		client->getPrenom(),
		client->getDateNaissance()->ToShortDateString(),
		client->getDatePremierAchat()->ToShortDateString(),

		client->getAdresseLivraison()->getNumero(),
		client->getAdresseLivraison()->getRue(),
		client->getAdresseLivraison()->getVille()->getNom(),
		client->getAdresseLivraison()->getVille()->getCodePostal(),

		client->getAdresseFacturation()->getNumero(),
		client->getAdresseFacturation()->getRue(),
		client->getAdresseFacturation()->getVille()->getNom(),
		client->getAdresseFacturation()->getVille()->getCodePostal());
}

String^ ProjetPOOServices::SqlQueries::SupprimerClient(ClientMap^ client)
{
	return String::Format("DECLARE @IdClient INT; " +
		"SET @IdClient = {0}; " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM Clients WHERE Id_client = @IdClient) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Suppression annul�e car le client n''existe pas'; " +
		"END " +
		"ELSE " +
		"BEGIN " +
		"    UPDATE Commandes  " +
		"    SET  " +
		"        Commandes.Id_client = NULL " +
		"    WHERE Commandes.Id_client = @IdClient; " +
		" " +
		"    DELETE FROM Clients WHERE Id_client = @IdClient; " +
		"    DELETE FROM Adresses WHERE Id_adresse = (SELECT Id_adresse_livraison FROM Clients WHERE Id_client = @IdClient); " +
		"    DELETE FROM Adresses WHERE Id_adresse = (SELECT Id_adresse_facturation FROM Clients WHERE Id_client = @IdClient); " +
		"    DELETE FROM Personnes WHERE Id_personne = @IdClient; " +
		"    COMMIT; " +
		"END; ",
		client->getId());
}
