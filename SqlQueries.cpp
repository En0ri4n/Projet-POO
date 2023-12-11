#include "SqlQueries.h"
#include "SqlManager.h"

String^ ProjetPOOServices::SqlQueries::listePersonnels()
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
		"    PRINT 'Ajout annulé car la ville n''existe pas'; " +
		"END  " +
		"ELSE  " +
		"BEGIN  " +
		"    SET @Id_superieur = (SELECT Id_personnel FROM Personnels WHERE Id_personnel = @Id_superieur); " +
		" " +
		"    IF @Id_superieur IS NULL " +
		"    BEGIN " +
		"        ROLLBACK; " +
		"        PRINT 'Ajout annulé car le supérieur n''existe pas'; " +
		"    END " +
		"    ELSE " +
		"    BEGIN " +
		"        DECLARE @Id_sup_sup INT; " +
		"        SET @Id_sup_sup = (SELECT Id_superieur FROM Personnels WHERE Id_personnel = @Id_superieur); " +
		" " +
		"        IF @Id_sup_sup IS NOT NULL " +
		"        BEGIN  " +
		"            ROLLBACK; " +
		"            PRINT 'Ajout annulé car le supérieur a lui-même un supérieur'; " +
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
		"    PRINT 'Modification annulée car la personne n''existe pas'; " +
		"END " +
		"ELSE " +
		"BEGIN " +
		"    DECLARE @IdVille INT; " +
		"    SET @IdVille = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVille AND Code_postal = @CodePostal); " +
		"    IF @IdVille IS NULL " +
		"    BEGIN " +
		// "        -- Annuler la transaction en cas d'erreur " +
		"        ROLLBACK; " +
		"        PRINT 'Modification annulée car la ville n''existe pas'; " +
		// "        ----- Erreur Adresse ville n'existe pas ------; " +
		"    END " +
		"    ELSE " +
		"    BEGIN " +
		"       SET @Id_superieur = (SELECT Id_personnel FROM Personnels WHERE Id_personnel = @Id_superieur); " +
		"       IF @Id_superieur IS NULL " +
		"       BEGIN " +
		"           ROLLBACK; " +
		"           PRINT 'Modification annulée car le supérieur n''existe pas'; " +
		"       END; " +
		" " +
		"   DECLARE @Id_sup_sup INT; " +
		"       SET @Id_sup_sup = (SELECT Id_superieur FROM Personnels WHERE Id_personnel = @Id_superieur); " +
		" " +
		"       IF @Id_sup_sup IS NOT NULL " +
		"       BEGIN " +
		"           ROLLBACK; " +
		"           PRINT 'Ajout annulé car le supérieur a lui-même un supérieur'; " +
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
		"    PRINT 'Suppression annulée car la personne n''existe pas'; " +
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

String^ ProjetPOOServices::SqlQueries::listeCommandes()
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
		"    SELECT UPPER(REPLACE(SUBSTRING(Prenom, 1, 2) + SUBSTRING(Nom, 1, 2), ' ', '') + " +
		"        CONVERT(VARCHAR, YEAR(@DateEmission)) + " +
		"        CASE " +
		"            WHEN (LEN((SELECT Nom_ville FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)))) >= 3) " +
		"                THEN LEFT(REPLACE((SELECT UPPER(LTRIM(Nom_ville, 3)) FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))), ' ', ''), 3) " +
		"            ELSE " +
		"                LEFT(REPLACE((SELECT UPPER(Nom_ville) FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))), ' ', ''), 3) " +
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
		"    PRINT 'Ajout annulé car le client n''existe pas'; " +
		"END " +
		" " +
		"ELSE IF @DatePaiement > @DateLivraison OR @DatePaiement > @DateEmission OR @DateEmission > @DateLivraison " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annulé car la date de paiement doit être antérieure à la date de livraison'; " +
		"END " +
		" " +
		"ELSE IF @MoyenPaiement NOT IN ('Carte', 'Bitcoin', 'Paypal', 'Cash') " +
		"BEGIN " +
		"	ROLLBACK; " +
		"	PRINT 'Ajout annulé car le moyen de paiement n''est pas disponible' " +
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
		"			SET Date_premier_achat = @DatePaiement " +
		"        WHERE Id_client = @IdClientCommande; " +
		"	  COMMIT; " +
		"    END  " +
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
		"    PRINT 'La commande avec la référence spécifiée n''existe pas pour le client spécifié.'; " +
		"END " +
		" " +
		"ELSE IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande) " +
		"BEGIN  " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annulé car le client n''existe pas'; " +
		"END " +
		" " +
		"ELSE IF @DatePaiement > @DateLivraison OR @DateEmission > @DateLivraison " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annulé car la date de paiement doit être antérieure à la date de livraison'; " +
		"END " +
		" " +
		"ELSE IF @NouveauMoyenPaiement NOT IN ('Carte', 'Bitcoin', 'Paypal', 'Cash') " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout annulé car le moyen de paiement n''est pas disponible' " +
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
		"    PRINT 'Commande modifiée avec succès.'; " +
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
		"    PRINT 'Suppression annulée car la commande n''existe pas'; " +
		"END " +
		" " +
		"ELSE IF (SELECT COUNT(constituer.Reference_commande) FROM [Projet].[dbo].constituer WHERE constituer.Reference_commande = @ReferenceCommandeASuppr) <= 0 " +
		"BEGIN " +
		"    DELETE FROM [Projet].[dbo].[Commandes] WHERE Commandes.Reference_commande = @ReferenceCommandeASuppr; " +
		" " +
		"    COMMIT; " +
		"    PRINT 'Suppression de la commande réussie'; " +
		"END " +
		" " +
		"ELSE " +
		"BEGIN " +
		"    IF (SELECT Date_paiement FROM [Projet].[dbo].[Commandes] WHERE Commandes.Reference_commande = @ReferenceCommandeASuppr) >= DATEADD(YEAR, -10, GETDATE()) " +
		"    BEGIN " +
		"        ROLLBACK; " +
		"        PRINT 'Suppression annulée car la date de paiement est plus récente que 10 ans, nous nous devons de garder un historique de 10 ans'; " +
		"    END " +
		"     " +
		"    ELSE  " +
		"    BEGIN " +
		"        DELETE FROM [Projet].[dbo].[constituer] WHERE constituer.Reference_commande = @ReferenceCommandeASuppr; " +
		"        DELETE FROM [Projet].[dbo].[Commandes] WHERE Commandes.Reference_commande = @ReferenceCommandeASuppr; " +
		"     " +
		"        PRINT 'Suppression de la commande réussie'; " +
		"        COMMIT; " +
		"    END " +
		"END",
		commande->getIdCommande());
}

String^ ProjetPOOServices::SqlQueries::listeArticles()
{
	return String::Format("SELECT * FROM {0}", Table::ARTICLES->getName());
}

String^ ProjetPOOServices::SqlQueries::AjouterArticle(ArticleMap^ article)
{
	return String::Format("DECLARE @Reference_article VARCHAR(30); " +
		"DECLARE @Nom_article VARCHAR(50); " +
		"DECLARE @Prix_article_HT MONEY; " +
		"DECLARE @Nature_article VARCHAR(20); " +
		"DECLARE @Couleur_article VARCHAR(20); " +
		"DECLARE @Seuil_reapprovisionnement INT; " +
		"DECLARE @Quantite_article INT; " +
		"DECLARE @Pourcentage_taxe INT; " +
		" " +
		"SET @Reference_article = '{0}' " +
		"SET @Nom_article = '{1}' " +
		"SET @Prix_article_HT = {2} " +
		"SET @Nature_article = '{3}' " +
		"SET @Couleur_article = '{4}' " +
		"SET @Seuil_reapprovisionnement = {5} " +
		"SET @Quantite_article = {6} " +
		"SET @Pourcentage_taxe = {7} " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF @Quantite_article < 0  " +
		"BEGIN  " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout de l''article impossible, car la quantite est inférieure à 0' " +
		"END " +
		" " +
		"ELSE IF @Pourcentage_taxe < 0 " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout de l''article impossible, car la taxe est inférieure à 0' " +
		"END " +
		" " +
		"INSERT INTO [Projet].[dbo].[Articles]  " +
		"(Reference_article, Nom_article, Prix_article_HT, Nature_article, Couleur_article, Seuil_reapprovisionnement, Quantite_article, Pourcentage_taxe) " +
		"VALUES (@Reference_article, @Nom_article, @Prix_article_HT, @Nature_article, @Couleur_article, @Seuil_reapprovisionnement, @Quantite_article, @Pourcentage_taxe) " +
		" " +
		"COMMIT; ",
		article->getIdArticle(),
		article->getNom(),
		article->getPrix().ToString(),
		article->getNature(),
		article->getCouleur(),
		article->getSeuilReapprovisionnement().ToString(),
		article->getQuantite().ToString(),
		article->getTaxe().ToString());
}

String^ ProjetPOOServices::SqlQueries::ModifierArticle(ArticleMap^ article)
{
	return String::Format("DECLARE @Reference_article_modif VARCHAR(30); " +
		"DECLARE @Nom_article VARCHAR(50); " +
		"DECLARE @Prix_article_HT MONEY; " +
		"DECLARE @Nature_article VARCHAR(20); " +
		"DECLARE @Couleur_article VARCHAR(20); " +
		"DECLARE @Seuil_reapprovisionnement INT; " +
		"DECLARE @Quantite_article INT; " +
		"DECLARE @Pourcentage_taxe INT; " +
		" " +
		"SET @Reference_article_modif = '{0}' " +
		"SET @Nom_article = '{1}' " +
		"SET @Prix_article_HT = {2} " +
		"SET @Nature_article = '{3}' " +
		"SET @Couleur_article = '{4}' " +
		"SET @Seuil_reapprovisionnement = {5} " +
		"SET @Quantite_article = {6} " +
		"SET @Pourcentage_taxe = {7} " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM Articles WHERE Reference_article = @Reference_article_modif) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Modification annulée car la personne n''existe pas'; " +
		"END " +
		" " +
		"IF @Quantite_article < 0  " +
		"BEGIN  " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout de l''article impossible, car la quantite est inférieure à 0' " +
		"END " +
		" " +
		"ELSE IF @Pourcentage_taxe < 0 " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Ajout de l''article impossible, car la taxe est inférieure à 0' " +
		"END " +
		" " +
		"UPDATE Articles  " +
		"    SET  " +
		"        Nom_article = @Nom_article, " +
		"        Prix_article_HT = @Prix_article_HT, " +
		"        Nature_article = @Nature_article, " +
		"        Couleur_article = @Couleur_article, " +
		"        Seuil_reapprovisionnement = @Seuil_reapprovisionnement, " +
		"        Quantite_article = @Quantite_article, " +
		"        Pourcentage_taxe = @Pourcentage_taxe " +
		" " +
		"WHERE Articles.Reference_article = @Reference_article_modif " +
		" " +
		"COMMIT; ",
		article->getIdArticle(),
		article->getNom(),
		article->getPrix().ToString(),
		article->getNature(),
		article->getCouleur(),
		article->getSeuilReapprovisionnement().ToString(),
		article->getQuantite().ToString(),
		article->getTaxe().ToString());
}

String^ ProjetPOOServices::SqlQueries::SupprimerArticle(ArticleMap^ article)
{
	return String::Format("DECLARE @Reference_article_suppr VARCHAR(30); " +
		" " +
		"SET @Reference_article_suppr = '{0}'; " +
		" " +
		"BEGIN TRANSACTION; " +
		" " +
		"IF NOT EXISTS (SELECT 1 FROM Articles WHERE Reference_article = @Reference_article_suppr) " +
		"BEGIN " +
		"    ROLLBACK; " +
		"    PRINT 'Suppression annulée car l''article n''existe pas'; " +
		"END " +
		" " +
		"ELSE IF EXISTS (SELECT 1 FROM constituer WHERE Reference_article = @Reference_article_suppr) " +
		"BEGIN " +
		"    UPDATE Articles  " +
		"    SET  " +
		"        Quantite_article = -1, " +
		"        Seuil_reapprovisionnement = -1 " +
		"    WHERE Reference_article = @Reference_article_suppr; " +
		"    COMMIT; " +
		"END " +
		" " +
		"ELSE IF NOT EXISTS (SELECT 1 FROM constituer WHERE Reference_article = @Reference_article_suppr) " +
		"BEGIN " +
		"    DELETE FROM Articles  " +
		"    WHERE Articles.Reference_article = @Reference_article_suppr " +
		"    COMMIT; " +
		"END ",
		article->getIdArticle());
}

String^ ProjetPOOServices::SqlQueries::listeClients()
{
	return "SELECT  " +
		"    Id_client AS Id_client, " +
		"    Nom AS Nom, " +
		"    Prenom AS Prenom, " +
		"    Date_naissance, " +
		"    Date_premier_achat, " +
		"     " +
		"    Id_adresse_facturation AS ID_Adresse_Facturation, " +
		"    AdressesFacturation.Numero_rue AS Numero_rue_Adresse_Facturation, " +
		"    AdressesFacturation.Nom_rue AS Nom_rue_Adresse_Facturation, " +
		"    AdressesFacturation.Id_ville AS ID_Ville_Facturation, " +
		"    VilleFacturation.Nom_ville AS Nom_Ville_Facturation, " +
		"    VilleFacturation.Code_postal AS Code_postal_Ville_Facturation, " +
		"     " +
		"    Id_adresse_livraison AS ID_Adresse_Livraison, " +
		"    AdressesLivraison.Numero_rue AS Numero_rue_Adresse_Livraison, " +
		"    AdressesLivraison.Nom_rue AS Nom_rue_Adresse_Livraison, " +
		"    AdressesLivraison.Id_ville AS ID_Ville_Livraison, " +
		"    VilleLivraison.Nom_ville AS Nom_Ville_Livraison, " +
		"    VilleLivraison.Code_postal AS Code_postal_Ville_Livraison " +
		" " +
		"FROM [Projet].[dbo].[Clients]  " +
		"INNER JOIN [Projet].[dbo].[Personnes] ON Clients.Id_client = Personnes.Id_personne " +
		"LEFT JOIN Adresses AS AdressesFacturation ON Clients.Id_adresse_facturation = AdressesFacturation.Id_adresse " +
		"LEFT JOIN Adresses AS AdressesLivraison ON Clients.Id_adresse_livraison = AdressesLivraison.Id_adresse " +
		"LEFT JOIN Villes AS VilleFacturation ON AdressesFacturation.Id_ville = VilleFacturation.Id_ville " +
		"LEFT JOIN Villes AS VilleLivraison ON AdressesLivraison.Id_ville = VilleLivraison.Id_ville";
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
		"    PRINT 'Ajout annulé car la ville de livraison n''existe pas'; " +
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
		"    PRINT 'Modification annulée car le client n''existe pas'; " +
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
		"    PRINT 'Suppression annulée car le client n''existe pas'; " +
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

String^ ProjetPOOServices::SqlQueries::listeCommandeArticles(CommandeMap^ commande)
{
	return String::Format("DECLARE @Reference_commande VARCHAR(30); " +
		"SET @Reference_commande = '{0}'; " +
		" " +
		"SELECT Commandes.Reference_commande " +
		"      ,Date_livraison " +
		"      ,Date_emission " +
		"      ,Moyen_paiement " +
		"      ,Date_paiement " +
		"      ,Pourcentage_remise " +
		"      ,Articles.Reference_article " +
		"      ,Nom_article " +
		"      ,Prix_article_HT " +
		"      ,Nature_article " +
		"      ,Couleur_article " +
		"      ,Seuil_reapprovisionnement " +
		"      ,Quantite_article " +
		"      ,Articles.Pourcentage_taxe " +
		"      ,Quantite_article_commande " +
		"      ,Pourcentage_remise_article " +
		"FROM [Projet].[dbo].Commandes INNER JOIN [Projet].[dbo].constituer ON Commandes.Reference_commande = constituer.Reference_commande " +
		"INNER JOIN [Projet].[dbo].Articles ON constituer.Reference_article = Articles.Reference_article " +
		" " +
		"WHERE Commandes.Reference_commande = @Reference_commande;",
		commande->getIdCommande());
}

String^ ProjetPOOServices::SqlQueries::AjouterCommandeArticle(SqlQuery^ query, CommandeMap^ commande)
{
	for each(ArticleMap ^ article in commande->getListeArticles())
	{
		query->addQuery(String::Format("DECLARE @ReferenceNum INT; " +
			"DECLARE @Reference_article VARCHAR(30); " +
			"DECLARE @Quantite_article_commande INT; " +
			"DECLARE @Pourcentage_remise_article INT; " +
			" " +
			"SET @Reference_article = '{0}'; " +
			"SET @Quantite_article_commande = {1}; " +
			"SET @Pourcentage_remise_article = {2}; " +
			" " +
			"SELECT " +
			"    @ReferenceNum = MAX(CAST(SUBSTRING(SUBSTRING(Reference_commande, 10, LEN(Reference_commande)),  " +
			"                            PATINDEX('%[0-9]%', SUBSTRING(Reference_commande, 10, LEN(Reference_commande))),  " +
			"                            LEN(SUBSTRING(Reference_commande, 10, LEN(Reference_commande)))) AS INT)) " +
			"FROM " +
			"    [Projet].[dbo].Commandes; " +
			" " +
			"DECLARE @ReferenceAssociee VARCHAR(30); " +
			" " +
			"SET  " +
			"    @ReferenceAssociee = (SELECT Reference_commande " +
			"FROM  " +
			"    [Projet].[dbo].Commandes " +
			"WHERE  " +
			"    CAST(SUBSTRING(SUBSTRING(Reference_commande, 10, LEN(Reference_commande)),  " +
			"                PATINDEX('%[0-9]%', SUBSTRING(Reference_commande, 10, LEN(Reference_commande))),  " +
			"                LEN(SUBSTRING(Reference_commande, 10, LEN(Reference_commande)))) AS INT) = @ReferenceNum); " +
			" " +
			" " +
			" " +
			"BEGIN TRANSACTION; " +
			" " +
			"IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Articles] WHERE Reference_article = @Reference_article) " +
			"BEGIN  " +
			"	ROLLBACK; " +
			"	PRINT 'Erreur d''ajout car l''article n''existe pas'; " +
			"END " +
			" " +
			"ELSE IF ((SELECT Quantite_article FROM [Projet].[dbo].[Articles] WHERE Reference_article = @Reference_article) - @Quantite_article_commande) < 0 " +
			"BEGIN " +
			"	ROLLBACK; " +
			"	PRINT 'Erreur d''ajout de l''article car le nombre commandé est supérieur au stock'; " +
			"END " +
			" " +
			"ELSE IF @Pourcentage_remise_article < 0 " +
			"BEGIN " +
			"	ROLLBACK; " +
			"	PRINT 'Erreur d''ajout de la remise car celle-ci est inférieure à 0'; " +
			"END " +
			" " +
			"ELSE  " +
			"BEGIN " +
			"	INSERT INTO [Projet].[dbo].constituer (Reference_commande, Reference_article, Quantite_article_commande, Pourcentage_remise_article) " +
			"	VALUES (@ReferenceAssociee, @Reference_article, @Quantite_article_commande, @Pourcentage_remise_article); " +
			" " +
			"	UPDATE [Projet].[dbo].[Articles]  " +
			"	SET Quantite_article = (Quantite_article - @Quantite_article_commande) " +
			"	WHERE Reference_article = @Reference_article; " +
			"	COMMIT; " +
			"END",
			article->getIdArticle(),
			article->getQuantite(),
			article->getRemise()));
	}

	return query->toQuery();
}

String^ ProjetPOOServices::SqlQueries::ModifierCommandeArticle(SqlQuery^ query, CommandeMap^ commande)
{
	CommandeMap^ cmdSuppr = gcnew CommandeMap();
	cmdSuppr->setIdCommande(commande->getIdCommande());
	cmdSuppr->setListeArticles(commande->getDerniereListeArticles());

	SupprimerCommandeArticle(query, cmdSuppr);

	for each(ArticleMap ^ article in commande->getListeArticles())
	{
		query->addQuery(String::Format("DECLARE @Reference_commande VARCHAR(30); " +
			"DECLARE @Reference_article VARCHAR(30); " +
			"DECLARE @Quantite_article_commande INT; " +
			"DECLARE @Pourcentage_remise_article INT; " +
			" " +
			"SET @Reference_commande = '{0}'; " +
			"SET @Reference_article = '{1}'; " +
			"SET @Quantite_article_commande = {2}; " +
			"SET @Pourcentage_remise_article = {3}; " +
			" " +
			"BEGIN TRANSACTION; " +
			" " +
			"IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Commandes] WHERE Reference_commande = @Reference_commande) " +
			"BEGIN     " +
			"    ROLLBACK; " +
			"    PRINT 'Erreur d''ajout car la commande n''existe pas'; " +
			"END " +
			" " +
			"ELSE IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Articles] WHERE Reference_article = @Reference_article) " +
			"BEGIN  " +
			"    ROLLBACK; " +
			"    PRINT 'Erreur d''ajout car l''article n''existe pas'; " +
			"END " +
			" " +
			"ELSE IF ((SELECT Quantite_article FROM [Projet].[dbo].[Articles] WHERE Reference_article = @Reference_article) - @Quantite_article_commande) < 0 " +
			"BEGIN " +
			"    ROLLBACK; " +
			"    PRINT 'Erreur d''ajout de l''article car le nombre commandé est supérieur au stock'; " +
			"END " +
			" " +
			"ELSE IF (SELECT Quantite_article FROM [Projet].[dbo].[Articles] WHERE Reference_article = @Reference_article) < 0 " +
			"BEGIN " +
			"    ROLLBACK; " +
			"    PRINT 'Erreur d''ajout de l''article, car celui-ci n''est plus en stock' " +
			"END " +
			" " +
			"ELSE IF @Pourcentage_remise_article < 0 " +
			"BEGIN " +
			"    ROLLBACK; " +
			"    PRINT 'Erreur d''ajout de la remise car celle-ci est inférieure à 0'; " +
			"END " +
			" " +
			"ELSE  " +
			"BEGIN " +
			"    INSERT INTO [Projet].[dbo].constituer (Reference_commande, Reference_article, Quantite_article_commande, Pourcentage_remise_article) " +
			"    VALUES (@Reference_commande, @Reference_article, @Quantite_article_commande, @Pourcentage_remise_article); " +
			" " +
			"    UPDATE [Projet].[dbo].[Articles]  " +
			"    SET Quantite_article = (Quantite_article - @Quantite_article_commande) " +
			"    WHERE Reference_article = @Reference_article; " +
			"    COMMIT; " +
			"END;",
			commande->getIdCommande(),
			article->getIdArticle(),
			article->getQuantite(),
			article->getRemise()));
	}

	return query->toQuery();
}

String^ ProjetPOOServices::SqlQueries::SupprimerCommandeArticle(SqlQuery^ query, CommandeMap^ commande)
{
	for each(ArticleMap ^ article in commande->getListeArticles())
	{
		query->addQuery(String::Format("DECLARE @Reference_commande VARCHAR(30); " +
			"DECLARE @Reference_article_suppr VARCHAR(30); " +
			" " +
			"SET @Reference_commande = '{0}'; " +
			"SET @Reference_article_suppr = '{1}'; " +
			" " +
			"BEGIN TRANSACTION; " +
			" " +
			"IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].constituer WHERE Reference_commande = @Reference_commande) " +
			"BEGIN  " +
			"    ROLLBACK; " +
			"    PRINT 'Impossible de supprimer un article d''une commande inexistante'; " +
			"END " +
			" " +
			"ELSE IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].constituer WHERE Reference_article = @Reference_article_suppr AND Reference_commande = @Reference_commande) " +
			"BEGIN " +
			"    ROLLBACK; " +
			"    PRINT 'Impossible de supprimer un article inexistant d''une commande'; " +
			"END " +
			" " +
			"ELSE " +
			"BEGIN " +
			"    IF (SELECT Quantite_article FROM [Projet].[dbo].Articles WHERE Reference_article = @Reference_article_suppr)  < 0 " +
			"    BEGIN " +
			"        DELETE FROM [Projet].[dbo].constituer " +
			"        WHERE constituer.Reference_article = @Reference_article_suppr AND constituer.Reference_commande = @Reference_commande; " +
			"        COMMIT; " +
			"    END " +
			"    ELSE " +
			"    BEGIN " +
			"        UPDATE [Projet].[dbo].Articles " +
			"        SET Quantite_article = Quantite_article + (SELECT quantite_article_commande FROM [Projet].[dbo].constituer WHERE constituer.Reference_article = @Reference_article_suppr AND constituer.Reference_commande = @Reference_commande) " +
			"        WHERE Reference_article = @Reference_article_suppr; " +
			" " +
			"        DELETE FROM [Projet].[dbo].constituer " +
			"        WHERE constituer.Reference_article = @Reference_article_suppr AND constituer.Reference_commande = @Reference_commande; " +
			"        COMMIT; " +
			"    END; " +
			"END;",
			commande->getIdCommande(),
			article->getIdArticle()));
	}

	return query->toQuery();
}

String^ ProjetPOOServices::SqlQueries::getPanierMoyen()
{
	return "SELECT CAST(ROUND(AVG(PanierMoyenApresRemise), 2) AS float) AS PanierMoyen " +
		"FROM ( " +
		"    SELECT  " +
		"        SUM((a.Prix_article_HT * (1 + CAST(a.Pourcentage_taxe AS DECIMAL(2)) / 100)  " +
		"            * (1 - CAST(co.Pourcentage_remise_article AS DECIMAL(2)) / 100)) * co.Quantite_article_commande) " +
		"            * (1 - CAST(c.Pourcentage_remise AS DECIMAL(2)) / 100) AS PanierMoyenApresRemise " +
		"    FROM  " +
		"        [Projet].[dbo].[Commandes] c " +
		"        INNER JOIN [Projet].[dbo].[constituer] co ON c.Reference_commande = co.Reference_commande " +
		"        INNER JOIN [Projet].[dbo].[Articles] a ON co.Reference_article = a.Reference_article " +
		"    GROUP BY  " +
		"        co.Reference_commande, c.Pourcentage_remise " +
		") AS Paniers;";
}

String^ ProjetPOOServices::SqlQueries::getChiffreAffaire(DateTime^ date)
{
	return String::Format("DECLARE @Mois DATE = '{0}'; " +
		" " +
		"SELECT " +
		"    CAST(ROUND(SUM(TotalPrix), 2) AS float) AS ChiffreAffaires " +
		"FROM ( " +
		"    SELECT " +
		"        SUM((a.Prix_article_HT * (1 - CAST(co.Pourcentage_remise_article AS DECIMAL(2)) / 100))  " +
		"        * co.Quantite_article_commande) " +
		"        * (1 - CAST(c.Pourcentage_remise / 100 AS DECIMAL(2))) AS TotalPrix " +
		"    FROM  " +
		"        [Projet].[dbo].[Commandes] c " +
		"        INNER JOIN [Projet].[dbo].[constituer] co ON c.Reference_commande = co.Reference_commande " +
		"        INNER JOIN [Projet].[dbo].[Articles] a ON co.Reference_article = a.Reference_article " +
		"    WHERE " +
		"        MONTH(c.Date_paiement) = MONTH(@Mois) AND YEAR(c.Date_paiement) = YEAR(@Mois) " +
		"    GROUP BY  " +
		"        c.Reference_commande, c.Pourcentage_remise " +
		") AS ChiffreAffairesMois;",
		date->ToShortDateString());
}

String^ ProjetPOOServices::SqlQueries::getProduitSousSeuilReapprovisionnement()
{
	return "SELECT * FROM [Projet].[dbo].[Articles] AS A " +
		"WHERE A.Quantite_article < A.Seuil_reapprovisionnement";
}

String^ ProjetPOOServices::SqlQueries::getMontantTotalClient(ClientMap^ client)
{
	return String::Format("SELECT  " +
		"    c.Id_client, " +
		"    CAST(ROUND(SUM((a.Prix_article_HT * (1 + CAST(a.Pourcentage_taxe AS DECIMAL(2)) / 100)  " +
		"        * (1 - CAST(co.Pourcentage_remise_article AS DECIMAL(2)) / 100)) * co.Quantite_article_commande)  " +
		"        * (1 - CAST(c.Pourcentage_remise AS DECIMAL(2)) / 100), 2) AS float) AS MontantTotalAchats " +
		"FROM  " +
		"    [Projet].[dbo].[Commandes] c " +
		"    INNER JOIN [Projet].[dbo].[constituer] co ON c.Reference_commande = co.Reference_commande " +
		"    INNER JOIN [Projet].[dbo].[Articles] a ON co.Reference_article = a.Reference_article " +
		"WHERE " +
		"    c.Id_client = '{0}' " +
		"GROUP BY  " +
		"    c.Id_client, c.Pourcentage_remise;",
		client->getId());
}

String^ ProjetPOOServices::SqlQueries::getProduitPlusVendu()
{
	return "SELECT TOP 10 " +
		"    a.Reference_article, " +
		"    a.Nom_article, " +
		"    COALESCE(SUM(co.Quantite_article_commande), 0) AS QuantiteVendue " +
		"FROM  " +
		"    [Projet].[dbo].[Articles] a " +
		"    LEFT JOIN [Projet].[dbo].[constituer] co ON a.Reference_article = co.Reference_article  " +
		"GROUP BY " +
		"    a.Reference_article, a.Nom_article " +
		"ORDER BY     " +
		"    QuantiteVendue DESC, " +
		"    a.Nom_article ASC;";
}

String^ ProjetPOOServices::SqlQueries::getProduitMoinsVendu()
{
	return "SELECT TOP 10 " +
		"    a.Reference_article, " +
		"    a.Nom_article, " +
		"    COALESCE(SUM(co.Quantite_article_commande), 0) AS QuantiteVendue " +
		"FROM  " +
		"    [Projet].[dbo].[Articles] a " +
		"    LEFT JOIN [Projet].[dbo].[constituer] co ON a.Reference_article = co.Reference_article  " +
		"GROUP BY " +
		"    a.Reference_article, a.Nom_article " +
		"ORDER BY     " +
		"    QuantiteVendue ASC, " +
		"    a.Nom_article ASC;";
}

String^ ProjetPOOServices::SqlQueries::getValeurCommercialStock()
{
	return "SELECT " +
		"SUM(a.Prix_article_HT * a.Quantite_article) AS ValeurCommercialeDuStock " +
		"FROM " +
		"[Projet].[dbo].[Articles] a;";
}

String^ ProjetPOOServices::SqlQueries::getValeurAchatStock()
{
	return "SELECT " +
		"CAST(ROUND(SUM(a.Prix_article_HT * (1 + CAST(a.Pourcentage_taxe AS DECIMAL(2)) / 100) * " +
		"	a.Quantite_article), 2) AS float) AS ValeurAchatDuStock " +
		"FROM " +
		"[Projet].[dbo].[Articles] a;";
}

String^ ProjetPOOServices::SqlQueries::filtre(Table^ table, String^ column, String^ value)
{
	String^ query = "";
	if(table == Table::PERSONNELS)
		query += listePersonnels();
	else if(table == Table::CLIENTS)
		query += listeClients();
	else if(table == Table::ARTICLES)
		query += listeArticles();
	else if(table == Table::COMMANDES)
		query += listeCommandes();


	query += String::Format(" WHERE {0} LIKE '%{1}%';", column, value);

	return query;
}

String^ ProjetPOOServices::SqlQueries::filtreClients(String^ column, String^ value)
{
	String^ query = listeClients();

	column = column->ToLower();
	String^ table = "";
	String^ attribut = "";

	if(column->Contains("facturation"))
	{
		if(column->Contains("ville"))
		{
			table = "VilleFacturation";
		}
		else if(column->Contains("adresse"))
		{
			table = "AdressesFacturation";
		}
	}
	else if(column->Contains("livraison"))
	{
		if(column->Contains("ville"))
		{
			table = "VilleLivraison";
		}
		else if(column->Contains("adresse"))
		{
			table = "AdressesLivraison";
		}
	}

	if(column->Contains("facturation") || column->Contains("livraison"))
	{
		if(column->Contains("numero"))
		{
			attribut = "Numero_rue";
		}
		else if(column->Contains("rue"))
		{
			attribut = "Nom_rue";
		}
		else if(column->Contains("ville"))
		{
			attribut = "Nom_ville";
		}
		else if(column->Contains("code"))
		{
			attribut = "Code_postal";
		}
		else if(column->Contains("id"))
		{
			if(column->Contains("adresse"))
			{
				attribut = "Id_adresse";
			}
			else if(column->Contains("ville"))
			{
				attribut = "Id_ville";
			}
		}
	}


	query += String::Format(" WHERE [{0}].[{1}] LIKE '%{2}%';", table, attribut, value);

	return query;
}

String^ ProjetPOOServices::SqlQueries::getFullCommande(CommandeMap^ commande)
{
	return String::Format("DECLARE @Reference_commande VARCHAR(30); " +
		" " +
		"SET @Reference_commande = '{0}'; " +
		" " +
		"SELECT  " +
		"	Clients.Id_client, " +
		"    Personnes.Nom,  " +
		"    Personnes.Prenom, " +
		"    Clients.Date_naissance,  " +
		"    Clients.Date_premier_achat, " +
		"    AdressesLivraison.Nom_rue AS Nom_rue_livraison, " +
		"    AdressesLivraison.Numero_rue AS Numero_rue_livraison, " +
		"    VilleLivraison.Nom_ville AS Nom_ville_livraison, " +
		"    AdressesFacturation.Nom_rue AS Nom_rue_facturation, " +
		"    AdressesFacturation.Numero_rue AS Numero_rue_facturation, " +
		"    VilleFacturation.Nom_ville AS Nom_ville_facturation, " +
		"	 VilleFacturation.Code_postal AS Code_postal_facturation, " +
		"    Commandes.Reference_commande, " +
		"    Commandes.Date_paiement, " +
		"	 Commandes.Date_emission, " +
		"    Commandes.Date_livraison, " +
		"	 Commandes.Moyen_paiement, " +
		"    constituer.Quantite_article_commande, " +
		"    Articles.Nom_article, " +
		"	 constituer.Pourcentage_remise_article, " +
		"    Articles.Prix_article_HT AS Prix_unitaire_HT, " +
		"    Articles.Prix_article_HT * (1 + (CAST(Articles.Pourcentage_taxe AS DECIMAL(2)) / 100)) AS Prix_unitaire_TVA, " +
		"    Articles.Prix_article_HT * (1 + (CAST(Articles.Pourcentage_taxe AS DECIMAl(2)) / 100)) * constituer.Quantite_article_commande AS Prix_commande_TTC, " +
		"    Articles.Prix_article_HT * (1 + (CAST(Articles.Pourcentage_taxe AS DECIMAL(2)) / 100)) * constituer.Quantite_article_commande * (1 - (CAST(constituer.Pourcentage_remise_article AS DECIMAL(2)) / 100)) AS Prix_commande_TTC_remise " +
		"FROM  " +
		"    [Projet].[dbo].[Personnes] AS Personnes " +
		"INNER JOIN  " +
		"    [Projet].[dbo].[Clients] AS Clients ON Personnes.Id_personne = Clients.Id_client " +
		"LEFT JOIN  " +
		"    [Projet].[dbo].[Adresses] AS AdressesLivraison ON Clients.Id_adresse_livraison = AdressesLivraison.Id_adresse " +
		"LEFT JOIN  " +
		"    [Projet].[dbo].[Adresses] AS AdressesFacturation ON Clients.Id_adresse_facturation = AdressesFacturation.Id_adresse " +
		"LEFT JOIN " +
		"    [Projet].[dbo].[Villes] AS VilleLivraison ON AdressesLivraison.Id_ville = VilleLivraison.Id_ville " +
		"LEFT JOIN " +
		"    [Projet].[dbo].[Villes] AS VilleFacturation ON AdressesFacturation.Id_ville = VilleFacturation.Id_ville " +
		"INNER JOIN  " +
		"    [Projet].[dbo].[Commandes] AS Commandes ON Clients.Id_client = Commandes.Id_client " +
		"INNER JOIN  " +
		"    [Projet].[dbo].[constituer] AS constituer ON Commandes.Reference_commande = constituer.Reference_commande " +
		"INNER JOIN  " +
		"    [Projet].[dbo].[Articles] AS Articles ON constituer.Reference_article = Articles.Reference_article " +
		"WHERE Commandes.Reference_commande = @Reference_commande;", commande->getIdCommande());
}
