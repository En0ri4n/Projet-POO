
-----------------------------------------------COMMANDES-------------------------------------------

----------------Ajouter--------------------

DECLARE @IdClientCommande INT;
DECLARE @DateEmission DATE;
DECLARE @DateLivraison DATE;
DECLARE @DatePaiement DATE; 
DECLARE @MoyenPaiement VARCHAR(50);
DECLARE @Remise INT;

SET @IdClientCommande = 70; 
SET @DateEmission = '2023-01-07'; 
SET @DateLivraison = '2023-01-10'; 
SET @DatePaiement = '2023-01-05'; 
SET @MoyenPaiement = 'Carte';
SET @Remise = CASE
    WHEN MONTH(@DatePaiement) = MONTH((SELECT Date_naissance FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))
         AND DAY(@DatePaiement) = DAY((SELECT Date_naissance FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))
         AND MONTH(@DatePaiement) = MONTH((SELECT Date_premier_achat FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))
         AND DAY(@DatePaiement) = DAY((SELECT Date_premier_achat FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) THEN 15
    WHEN MONTH(@DatePaiement) = MONTH((SELECT Date_naissance FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))
         AND DAY(@DatePaiement) = DAY((SELECT Date_naissance FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) THEN 10
    WHEN MONTH(@DatePaiement) = MONTH((SELECT Date_premier_achat FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))
         AND DAY(@DatePaiement) = DAY((SELECT Date_premier_achat FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)) THEN 5
    ELSE 0
END;

DECLARE @ReferenceCommande VARCHAR(50);

SET @ReferenceCommande = (
    SELECT UPPER(SUBSTRING(Prenom, 1, 2) + SUBSTRING(Nom, 1, 2) +
        CONVERT(VARCHAR, YEAR(@DateEmission)) +
        CASE
            WHEN (LEN((SELECT Nom_ville FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)))) >= 3)
                THEN SUBSTRING((SELECT UPPER(LEFT(Nom_ville, 3)) FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande))), 1, 3)
            ELSE
                (SELECT UPPER(Nom_ville) FROM [Projet].[dbo].[Villes] WHERE Id_ville = (SELECT Id_ville FROM [Projet].[dbo].[Adresses] WHERE Id_adresse = (SELECT Id_adresse_livraison FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)))
        END +
        CONVERT(VARCHAR, (SELECT COUNT(*) + 1 FROM [Projet].[dbo].[Commandes])))
    FROM [Projet].[dbo].[Personnes] WHERE Id_personne = @IdClientCommande
);

BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)
BEGIN
    ROLLBACK;
    PRINT 'Ajout annulé car le client n''existe pas';
END

ELSE IF @DatePaiement > @DateLivraison OR @DatePaiement > @DateEmission OR @DateEmission > @DateLivraison
BEGIN
    ROLLBACK;
    PRINT 'Ajout annulé car la date de paiement doit être antérieure à la date de livraison';
END

ELSE IF @MoyenPaiement NOT IN ('Carte', 'Bitcoin', 'Paypal', 'Cash')
BEGIN
	ROLLBACK;
	PRINT 'Ajout annulé car le moyen de paiement n''est pas disponible'
END

ELSE
BEGIN
    INSERT INTO [Projet].[dbo].[Commandes] (Reference_commande, Date_emission, Date_livraison, Date_paiement, Moyen_paiement, Pourcentage_remise, Id_client)
    VALUES (@ReferenceCommande, @DateEmission, @DateLivraison, @DatePaiement, @MoyenPaiement, @Remise, @IdClientCommande);

    IF (SELECT COUNT(*) FROM [Projet].[dbo].[Commandes] WHERE Id_client = @IdClientCommande) = 1
    BEGIN
        UPDATE [Projet].[dbo].[Clients] 
			SET Date_premier_achat = @DatePaiement
        WHERE Id_client = @IdClientCommande;
    END 
	COMMIT;
END

----------------Modifier-------------------

DECLARE @IdClientCommande INT;
DECLARE @ReferenceCommandeAModifier VARCHAR(50);
DECLARE @NouvelleDateEmission DATE;
DECLARE @NouvelleDateLivraison DATE;
DECLARE @NouveauMoyenPaiement VARCHAR(50);
DECLARE @DatePaiement DATE;
DECLARE @DateLivraison DATE;
DECLARE @DateEmission DATE;

SET @IdClientCommande = 70; 
SET @ReferenceCommandeAModifier = 'RAPI2023SAI18';
SET @NouvelleDateEmission = '2023-02-01';
SET @NouvelleDateLivraison = '2000-02-10';
SET @NouveauMoyenPaiement = 'Cash';


BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Commandes] WHERE [Projet].[dbo].[Commandes].Id_client = @IdClientCommande AND [Projet].[dbo].[Commandes].Reference_commande = @ReferenceCommandeAModifier)
BEGIN
    ROLLBACK;
    PRINT 'La commande avec la référence spécifiée n''existe pas pour le client spécifié.';
END

ELSE IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Clients] WHERE Id_client = @IdClientCommande)
BEGIN 
    ROLLBACK;
    PRINT 'Ajout annulé car le client n''existe pas';
END

ELSE IF @DatePaiement > @DateLivraison OR @DateEmission > @DateLivraison
BEGIN
    ROLLBACK;
    PRINT 'Ajout annulé car la date de paiement doit être antérieure à la date de livraison';
END

ELSE IF @NouveauMoyenPaiement NOT IN ('Carte', 'Bitcoin', 'Paypal', 'Cash')
BEGIN
	ROLLBACK;
	PRINT 'Ajout annulé car le moyen de paiement n''est pas disponible'
END

BEGIN
	SET @DatePaiement = (SELECT Date_paiement FROM [Projet].[dbo].[Commandes] WHERE Reference_commande = @ReferenceCommandeAModifier)
    UPDATE [Projet].[dbo].[Commandes]
    SET 
        Date_emission = @NouvelleDateEmission,
        Date_livraison = @NouvelleDateLivraison,
        Moyen_paiement = @NouveauMoyenPaiement
    WHERE [Projet].[dbo].[Commandes].Id_client = @IdClientCommande AND [Projet].[dbo].[Commandes].Reference_commande = @ReferenceCommandeAModifier;

    COMMIT;
    PRINT 'Commande modifiée avec succès.';
END

----------------Supprimer------------------

BEGIN TRANSACTION;

DECLARE @ReferenceCommandeASuppr VARCHAR(50);
SET @ReferenceCommandeASuppr = 'TEST'; 

IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Commandes] WHERE Reference_commande = @ReferenceCommandeASuppr)
BEGIN
    ROLLBACK;
    PRINT 'Suppression annulée car la commande n''existe pas';
END

ELSE IF (SELECT Date_paiement FROM [Projet].[dbo].[Commandes] WHERE Commandes.Reference_commande = @ReferenceCommandeASuppr) >= DATEADD(YEAR, -10, GETDATE())
BEGIN
    ROLLBACK;
    PRINT 'Suppression annulée car la date de paiement est plus récente que 10 ans';
END

ELSE
BEGIN
	DELETE FROM [Projet].[dbo].[constituer] WHERE constituer.Reference_commande = @ReferenceCommandeASuppr;
    DELETE FROM [Projet].[dbo].[Commandes] WHERE Commandes.Reference_commande = @ReferenceCommandeASuppr;

    COMMIT;
    PRINT 'Suppression de la commande réussie';
END

----------------Afficher-------------------

SELECT * FROM Commandes


---------------Ajouter article dans commande--------------

DECLARE @Reference_commande VARCHAR(30);
DECLARE @Reference_article VARCHAR(30);
DECLARE @Quantite_article_commande INT;
DECLARE @Pourcentage_remise_article INT;

SET @Reference_commande = 'TEST';
SET @Reference_article = 'TEST';
SET @Quantite_article_commande = 5;
SET @Pourcentage_remise_article = 5;

BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Commandes] WHERE Reference_commande = @Reference_commande)
BEGIN	
	ROLLBACK;
	PRINT 'Erreur d''ajout car la commande n''existe pas';
END

ELSE IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Articles] WHERE Reference_article = @Reference_article)
BEGIN 
	ROLLBACK;
	PRINT 'Erreur d''ajout car l''article n''existe pas';
END

ELSE IF ((SELECT Quantite_article FROM [Projet].[dbo].[Articles] WHERE Reference_article = @Reference_article) - @Quantite_article_commande) < 0
BEGIN
	ROLLBACK;
	PRINT 'Erreur d''ajout de l''article car le nombre commandé est supérieur au stock';
END

ELSE IF @Pourcentage_remise_article < 0
BEGIN
	ROLLBACK;
	PRINT 'Erreur d''ajout de la remise car celle-ci est inférieure à 0';
END

ELSE 
BEGIN
	INSERT INTO [Projet].[dbo].constituer (Reference_commande, Reference_article, Quantite_article_commande, Pourcentage_remise_article)
	VALUES (@Reference_commande, @Reference_article, @Quantite_article_commande, @Pourcentage_remise_article);

	UPDATE [Projet].[dbo].[Articles] 
	SET Quantite_article = (Quantite_article - @Quantite_article_commande)
	WHERE Reference_article = @Reference_article;
	COMMIT;
END



