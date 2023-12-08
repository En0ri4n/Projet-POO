-----------------Articles------------------

----------Ajouter------------

DECLARE @Reference_article VARCHAR(30);
DECLARE @Nom_article VARCHAR(50);
DECLARE @Prix_article_HT MONEY;
DECLARE @Nature_article VARCHAR(20);
DECLARE @Couleur_article VARCHAR(20);
DECLARE @Seuil_reapprovisionnement INT;
DECLARE @Quantite_article INT;
DECLARE @Pourcentage_taxe INT;

SET @Reference_article = 'Ratio'
SET @Nom_article = 'Ginitho'
SET @Prix_article_HT = 49.99
SET @Nature_article = 'Homme'
SET @Couleur_article = 'Blanc'
SET @Seuil_reapprovisionnement = 1 
SET @Quantite_article = 1
SET @Pourcentage_taxe = 0

BEGIN TRANSACTION;

IF @Quantite_article < 0 
BEGIN 
	ROLLBACK;
	PRINT 'Ajout de l''article impossible, car la quantite est inférieure à 0'
END

ELSE IF @Pourcentage_taxe < 0
BEGIN
	ROLLBACK;
	PRINT 'Ajout de l''article impossible, car la taxe est inférieure à 0'
END

INSERT INTO [Projet].[dbo].[Articles] 
(Reference_article, Nom_article, Prix_article_HT, Nature_article, Couleur_article, Seuil_reapprovisionnement, Quantite_article, Pourcentage_taxe)
VALUES (@Reference_article, @Nom_article, @Prix_article_HT, @Nature_article, @Couleur_article, @Seuil_reapprovisionnement, @Quantite_article, @Pourcentage_taxe)

COMMIT;

---------------Modifier----------------

DECLARE @Reference_article_modif VARCHAR(30);
DECLARE @Nom_article VARCHAR(50);
DECLARE @Prix_article_HT MONEY;
DECLARE @Nature_article VARCHAR(20);
DECLARE @Couleur_article VARCHAR(20);
DECLARE @Seuil_reapprovisionnement INT;
DECLARE @Quantite_article INT;
DECLARE @Pourcentage_taxe INT;

SET @Reference_article_modif = 'Ratio'
SET @Nom_article = 'Ginitho'
SET @Prix_article_HT = 49.99
SET @Nature_article = 'Homme'
SET @Couleur_article = 'Noir'
SET @Seuil_reapprovisionnement = 1 
SET @Quantite_article = 1
SET @Pourcentage_taxe = 0

BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM Articles WHERE Reference_article = @Reference_article_modif)
BEGIN
    ROLLBACK;
    PRINT 'Modification annulée car la personne n''existe pas';
END

IF @Quantite_article < 0 
BEGIN 
	ROLLBACK;
	PRINT 'Ajout de l''article impossible, car la quantite est inférieure à 0'
END

ELSE IF @Pourcentage_taxe < 0
BEGIN
	ROLLBACK;
	PRINT 'Ajout de l''article impossible, car la taxe est inférieure à 0'
END

UPDATE Articles 
	SET 
		Nom_article = @Nom_article,
		Prix_article_HT = @Prix_article_HT,
		Nature_article = @Nature_article,
		Couleur_article = @Couleur_article,
		Seuil_reapprovisionnement = @Seuil_reapprovisionnement,
		Quantite_article = @Quantite_article,
		Pourcentage_taxe = @Pourcentage_taxe

WHERE Articles.Reference_article = @Reference_article_modif

COMMIT;

---------------Supprimer---------------

DECLARE @Reference_article_suppr VARCHAR(30);

SET @Reference_article_suppr = 'Ratio';

BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM Articles WHERE Reference_article = @Reference_article_suppr)
BEGIN
    ROLLBACK;
    PRINT 'Suppression annulée car l''article n''existe pas';
END

ELSE IF EXISTS (SELECT 1 FROM constituer WHERE Reference_article = @Reference_article_suppr)
BEGIN
    UPDATE Articles 
    SET 
        Quantite_article = -1,
        Seuil_reapprovisionnement = -1
    WHERE Reference_article = @Reference_article_suppr;
	COMMIT;
END

ELSE IF NOT EXISTS (SELECT 1 FROM constituer WHERE Reference_article = @Reference_article_suppr)
BEGIN
    DELETE FROM Articles 
    WHERE Articles.Reference_article = @Reference_article_suppr
    COMMIT;
END

---------------Afficher----------------

SELECT * FROM Articles