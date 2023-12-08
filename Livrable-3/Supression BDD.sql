-- Utiliser la base de données master
USE master;

-- Vérifier si la base de données 'Projet' existe avant de la supprimer
IF DB_ID('Projet') IS NOT NULL
BEGIN
    -- Mettre la base de données en mode RESTRICTED_USER pour fermer les connexions
    ALTER DATABASE [Projet] SET RESTRICTED_USER WITH ROLLBACK IMMEDIATE;

    -- Supprimer la base de données 'Projet'
    DROP DATABASE [Projet];
END;

-- Créer une nouvelle base de données 'Projet'
CREATE DATABASE [Projet];