---------------PERSONNELS---------------------

---------- Ajout personnel ------------

DECLARE @IdPersonne INT;
DECLARE @NomPersonne VARCHAR(50);
DECLARE @PrenomPersonne VARCHAR(50);
DECLARE @IdAdresse INT;
DECLARE @NomVille VARCHAR(50);
DECLARE @CodePostal VARCHAR(10);
DECLARE @Date_embauche DATE;
DECLARE @Id_superieur INT;
DECLARE @Numero_rue INT;
DECLARE @Nom_rue VARCHAR(50);

SET @Numero_rue = 3;
SET @Nom_rue = 'Rue test';
SET @NomVille = 'Paris';
SET @CodePostal = '75000';
SET @NomPersonne = 'Enorian';
SET @PrenomPersonne = 'Bro';
SET @Date_embauche = '2023-01-01';
SET @Id_superieur = NULL;

BEGIN TRANSACTION;
DECLARE @IdVille INT;
SET @IdVille = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVille AND Code_postal = @CodePostal);

IF @IdVille IS NULL
BEGIN
    ROLLBACK;
    PRINT 'Ajout annulé car la ville n''existe pas';
END
ELSE
BEGIN
	IF @Id_superieur IS NOT NULL
	BEGIN 
		SET @Id_superieur = (SELECT Id_personnel FROM [Projet].[dbo].[Personnels] WHERE Id_personnel = @Id_superieur);
		IF @Id_superieur IS NULL
		BEGIN
			ROLLBACK;
			PRINT 'Ajout annulé car le supérieur n''existe pas';
		END
		ELSE 
		BEGIN
			DECLARE @Id_sup_sup INT;
			SET @Id_sup_sup = (SELECT Id_superieur FROM [Projet].[dbo].[Personnels] WHERE Id_personnel = @Id_superieur);

			IF @Id_sup_sup IS NOT NULL
			BEGIN
			    ROLLBACK;
			    PRINT 'Ajout annulé car le supérieur a lui-même un supérieur';
			END
			ELSE 
			BEGIN
				INSERT INTO [Projet].[dbo].[Adresses] (Numero_rue, Nom_rue, Id_ville)
				VALUES (@Numero_rue, @Nom_rue, @IdVille);
				SET @IdAdresse = SCOPE_IDENTITY();

			    INSERT INTO [Projet].[dbo].[Personnes] (Nom, Prenom)
				VALUES (@NomPersonne, @PrenomPersonne);
				SET @IdPersonne = SCOPE_IDENTITY();

				INSERT INTO [Projet].[dbo].[Personnels] (Id_personnel, Date_embauche, Id_adresse, Id_superieur)
				VALUES (@IdPersonne, @Date_embauche, @IdAdresse, @Id_superieur);
			END
		END
	END
    ELSE IF @Id_superieur IS NULL
    BEGIN
        INSERT INTO [Projet].[dbo].[Adresses] (Numero_rue, Nom_rue, Id_ville)
        VALUES (@Numero_rue, @Nom_rue, @IdVille);
        SET @IdAdresse = SCOPE_IDENTITY();

        INSERT INTO [Projet].[dbo].[Personnes] (Nom, Prenom)
        VALUES (@NomPersonne, @PrenomPersonne);
        SET @IdPersonne = SCOPE_IDENTITY();

        INSERT INTO [Projet].[dbo].[Personnels] (Id_personnel, Date_embauche, Id_adresse, Id_superieur)
        VALUES (@IdPersonne, @Date_embauche, @IdAdresse, @Id_superieur);
    END;
END;

COMMIT;


--------- Modification personnel ---------

DECLARE @IdPersonne INT;
DECLARE @NomPersonne VARCHAR(50);
DECLARE @PrenomPersonne VARCHAR(50);
DECLARE @IdAdresse INT;
DECLARE @NomVille VARCHAR(50);
DECLARE @CodePostal VARCHAR(10);
DECLARE @Date_embauche DATE;
DECLARE @Id_superieur INT;
DECLARE @Numero_rue INT;
DECLARE @Nom_rue VARCHAR(50);

SET @IdPersonne = 153; 
SET @Numero_rue = 3;
SET @Nom_rue = 'Rue test';
SET @NomVille = 'Paris';
SET @CodePostal = '75000';
SET @NomPersonne = 'Enorian';
SET @PrenomPersonne = 'Bro';
SET @Date_embauche = '2023-01-01';
SET @Id_superieur = 3;

BEGIN TRANSACTION;

BEGIN TRANSACTION;
DECLARE @IdVille INT;
SET @IdVille = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVille AND Code_postal = @CodePostal);

IF @IdVille IS NULL
BEGIN
    ROLLBACK;
    PRINT 'Modification annulée car la ville n''existe pas';
END
ELSE
BEGIN
    SET @Id_superieur = (SELECT Id_personnel FROM [Projet].[dbo].[Personnels] WHERE Id_personnel = @Id_superieur);

    IF @Id_superieur IS NOT NULL
    BEGIN 
        IF NOT EXISTS (SELECT 1 FROM [Projet].[dbo].[Personnels] WHERE Id_personnel = @Id_superieur)
        BEGIN
            ROLLBACK;
            PRINT 'Modification annulée car le supérieur n''existe pas';
        END
        ELSE
        BEGIN
            DECLARE @Id_sup_sup INT;
            SET @Id_sup_sup = (SELECT Id_superieur FROM [Projet].[dbo].[Personnels] WHERE Id_personnel = @Id_superieur);

            IF @Id_sup_sup IS NOT NULL
            BEGIN
                ROLLBACK;
                PRINT 'Modification annulée car le supérieur a lui-même un supérieur';
            END
            ELSE 
            BEGIN
                UPDATE [Projet].[dbo].[Personnes]
                SET 
                    Nom = @NomPersonne,
                    Prenom = @PrenomPersonne
                WHERE Id_personne = @IdPersonne;

                UPDATE [Projet].[dbo].[Adresses]
                SET 
                    Nom_rue = @Nom_rue,
                    Numero_rue = @Numero_rue,
                    Id_ville = @IdVille
                WHERE Id_adresse = (SELECT Id_adresse FROM [Projet].[dbo].[Personnels] WHERE Id_personnel = @IdPersonne);

                UPDATE [Projet].[dbo].[Personnels]
                SET
                    Date_embauche = @Date_embauche,
                    Id_superieur = @Id_superieur
                WHERE Id_personnel = @IdPersonne;
                
                COMMIT;
            END
        END
    END
    ELSE
    BEGIN
        UPDATE [Projet].[dbo].[Personnes]
        SET 
            Nom = @NomPersonne,
            Prenom = @PrenomPersonne
        WHERE Id_personne = @IdPersonne;

        UPDATE [Projet].[dbo].[Adresses]
        SET 
            Nom_rue = @Nom_rue,
            Numero_rue = @Numero_rue,
            Id_ville = @IdVille
        WHERE Id_adresse = (SELECT Id_adresse FROM [Projet].[dbo].[Personnels] WHERE Id_personnel = @IdPersonne);

        UPDATE [Projet].[dbo].[Personnels]
        SET
            Date_embauche = @Date_embauche,
            Id_superieur = @Id_superieur
        WHERE Id_personnel = @IdPersonne;
        

    END
END;

COMMIT;

--------- Supression personnel -----------

DECLARE @IdPersonnel INT;
SET @IdPersonnel = 1; 

BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM Personnes WHERE Id_personne = @IdPersonnel)
BEGIN
    ROLLBACK;
    PRINT 'Suppression annulée car la personne n''existe pas';
END
ELSE
BEGIN
    DECLARE @IdAdresse INT;
    SET @IdAdresse = (SELECT Id_adresse FROM Personnels WHERE Id_personnel = @IdPersonnel);

    DECLARE @IdSuperieur INT;
    SET @IdSuperieur = (SELECT Id_superieur FROM Personnels WHERE Id_personnel = @IdPersonnel);

	UPDATE Personnels 
	SET Id_superieur = NULL 
	WHERE Id_superieur = @IdPersonnel;

	DELETE FROM Personnels WHERE Id_personnel = @IdPersonnel;
	DELETE FROM Personnes WHERE Id_personne = @IdPersonnel;
	DELETE FROM Adresses WHERE Id_adresse = @IdAdresse;

	END;
COMMIT;
--------- Affichage personnel ------------

SELECT Personnels.Id_personnel, Personnes.Nom, Personnes.Prenom,  Personnels.Date_embauche, Personnels.Id_superieur, Adresses.Numero_rue, Adresses.Nom_rue, Villes.Nom_ville, Villes.Code_postal
FROM [Projet].[dbo].[Personnes] INNER JOIN [Projet].[dbo].[Personnels] ON Personnes.Id_personne = Personnels.Id_personnel INNER JOIN [Projet].[dbo].[Adresses] ON Personnels.Id_adresse = Adresses.Id_adresse INNER JOIN [Projet].[dbo].[Villes] ON Adresses.Id_ville = Villes.Id_ville

-------------------------------------------------CLIENTS-------------------------------------------------------------

-----------------Ajouter---------------------
DECLARE @IdClient INT;
DECLARE @NomClient VARCHAR(50);
DECLARE @PrenomClient VARCHAR(50);
DECLARE @DateNaissance DATE;
DECLARE @DatePremierAchat DATE;
DECLARE @NumeroRueLivraison INT;
DECLARE @NomRueLivraison VARCHAR(50);
DECLARE @NomVilleLivraison VARCHAR(50);
DECLARE @CodePostalLivraison VARCHAR(10);
DECLARE @NumeroRueFacturation INT;
DECLARE @NomRueFacturation VARCHAR(50);
DECLARE @NomVilleFacturation VARCHAR(50);
DECLARE @CodePostalFacturation VARCHAR(10);
DECLARE @IdAdresseLivraison INT;
DECLARE @IdAdresseFacturation INT;

SET @NomClient = 'Ian';
SET @PrenomClient = 'Enor';
SET @DateNaissance = '2008-01-01';
SET @DatePremierAchat = NULL;
SET @NumeroRueLivraison = 3;
SET @NomRueLivraison = 'Rue Ratio';
SET @NomVilleLivraison = 'Paris';
SET @CodePostalLivraison = '75000';
SET @NumeroRueFacturation = 3;
SET @NomRueFacturation = 'Rue test';
SET @NomVilleFacturation = 'Paris';
SET @CodePostalFacturation = '75000';

BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM Villes WHERE Nom_ville = @NomVilleLivraison AND Code_postal = @CodePostalLivraison)
BEGIN
    ROLLBACK;
    PRINT 'Ajout annulé car la ville de livraison n''existe pas';
END
ELSE
BEGIN
    INSERT INTO Personnes (Nom, Prenom)
    VALUES (@NomClient, @PrenomClient);
    SET @IdClient = SCOPE_IDENTITY();

    INSERT INTO Adresses (Numero_rue, Nom_rue, Id_ville)
    VALUES (@NumeroRueLivraison, @NomRueLivraison, (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVilleLivraison AND Code_postal = @CodePostalLivraison));
    SET @IdAdresseLivraison = SCOPE_IDENTITY();

    INSERT INTO Adresses (Numero_rue, Nom_rue, Id_ville)
    VALUES (@NumeroRueFacturation, @NomRueFacturation, (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVilleFacturation AND Code_postal = @CodePostalFacturation));
    SET @IdAdresseFacturation = SCOPE_IDENTITY();

    INSERT INTO Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation)
    VALUES (@IdClient, @DateNaissance, @DatePremierAchat, @IdAdresseLivraison, @IdAdresseFacturation);

    END;
COMMIT;

-----------------Modifier--------------------

DECLARE @IdClient INT;
DECLARE @NomClient VARCHAR(50);
DECLARE @PrenomClient VARCHAR(50);
DECLARE @DateNaissance DATE;
DECLARE @DatePremierAchat DATE;
DECLARE @NumeroRueLivraison INT;
DECLARE @NomRueLivraison VARCHAR(50);
DECLARE @NomVilleLivraison VARCHAR(50);
DECLARE @CodePostalLivraison VARCHAR(10);
DECLARE @NumeroRueFacturation INT;
DECLARE @NomRueFacturation VARCHAR(50);
DECLARE @NomVilleFacturation VARCHAR(50);
DECLARE @CodePostalFacturation VARCHAR(10);
DECLARE @IdAdresseLivraison INT;
DECLARE @IdAdresseFacturation INT;

SET @IdClient = 52;
SET @NomClient = 'NouveauNom';
SET @PrenomClient = 'NouveauPrenom';
SET @DateNaissance = '1990-02-01';
SET @DatePremierAchat = '2023-02-15';
SET @NumeroRueLivraison = 4;
SET @NomRueLivraison = 'TRainzdqd';
SET @NomVilleLivraison = 'Paris';
SET @CodePostalLivraison = '75000';
SET @NumeroRueFacturation = 4;
SET @NomRueFacturation = 'NouvelleRueFacturation';
SET @NomVilleFacturation = 'Paris';
SET @CodePostalFacturation = '75000';

BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM Clients WHERE Id_client = @IdClient)
BEGIN
    ROLLBACK;
    PRINT 'Modification annulée car le client n''existe pas';
END
ELSE
BEGIN
    UPDATE Personnes
    SET
        Nom = @NomClient,
        Prenom = @PrenomClient
    WHERE Id_personne = @IdClient;

    UPDATE Adresses
    SET
        Numero_rue = @NumeroRueLivraison,
        Nom_rue = @NomRueLivraison,
        Id_ville = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVilleLivraison AND Code_postal = @CodePostalLivraison)
    WHERE Id_adresse = (SELECT Id_adresse_livraison FROM Clients WHERE Id_client = @IdClient);

    UPDATE Adresses
    SET
        Numero_rue = @NumeroRueFacturation,
        Nom_rue = @NomRueFacturation,
        Id_ville = (SELECT Id_ville FROM Villes WHERE Nom_ville = @NomVilleFacturation AND Code_postal = @CodePostalFacturation)
    WHERE Id_adresse = (SELECT Id_adresse_facturation FROM Clients WHERE Id_client = @IdClient);

    UPDATE Clients
    SET
        Date_naissance = @DateNaissance,
        Date_premier_achat = @DatePremierAchat
    WHERE Id_client = @IdClient;

	END;
COMMIT;

-----------------Supprimer-------------------

DECLARE @IdClient INT;
SET @IdClient = 51;

BEGIN TRANSACTION;

IF NOT EXISTS (SELECT 1 FROM Clients WHERE Id_client = @IdClient)
BEGIN
    ROLLBACK;
    PRINT 'Suppression annulée car le client n''existe pas';
END
ELSE
BEGIN
	UPDATE Commandes 
	SET 
		Commandes.Id_client = NULL
	WHERE Commandes.Id_client = @IdClient;

    DELETE FROM Clients WHERE Id_client = @IdClient;
    DELETE FROM Adresses WHERE Id_adresse = (SELECT Id_adresse_livraison FROM Clients WHERE Id_client = @IdClient);
    DELETE FROM Adresses WHERE Id_adresse = (SELECT Id_adresse_facturation FROM Clients WHERE Id_client = @IdClient);
    DELETE FROM Personnes WHERE Id_personne = @IdClient;

	END;
COMMIT;

-----------------Afficher--------------------

SELECT
    Clients.Id_client,
    Clients.Id_adresse_livraison,
    AdressesLivraison.Nom_rue AS Nom_rue_livraison,
    AdressesLivraison.Numero_rue AS Numero_rue_livraison,
	Clients.Id_adresse_facturation,
    AdressesFacturation.Nom_rue AS Nom_rue_facturation,
    AdressesFacturation.Numero_rue AS Numero_rue_facturation
FROM [Projet].[dbo].[Clients]
LEFT JOIN [Projet].[dbo].[Adresses] AS AdressesLivraison ON Clients.Id_adresse_livraison = AdressesLivraison.Id_adresse
LEFT JOIN [Projet].[dbo].[Adresses] AS AdressesFacturation ON Clients.Id_adresse_facturation = AdressesFacturation.Id_adresse;