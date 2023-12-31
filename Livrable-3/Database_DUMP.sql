USE [master]
GO
/****** Object:  Database [Projet]    Script Date: 07/12/2023 14:40:59 ******/
CREATE DATABASE [Projet]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'Projet', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\DATA\Projet.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'Projet_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\DATA\Projet_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT, LEDGER = OFF
GO
ALTER DATABASE [Projet] SET COMPATIBILITY_LEVEL = 160
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [Projet].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [Projet] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [Projet] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [Projet] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [Projet] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [Projet] SET ARITHABORT OFF 
GO
ALTER DATABASE [Projet] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [Projet] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [Projet] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [Projet] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [Projet] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [Projet] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [Projet] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [Projet] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [Projet] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [Projet] SET  ENABLE_BROKER 
GO
ALTER DATABASE [Projet] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [Projet] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [Projet] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [Projet] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [Projet] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [Projet] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [Projet] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [Projet] SET RECOVERY FULL 
GO
ALTER DATABASE [Projet] SET  MULTI_USER 
GO
ALTER DATABASE [Projet] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [Projet] SET DB_CHAINING OFF 
GO
ALTER DATABASE [Projet] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [Projet] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [Projet] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [Projet] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
EXEC sys.sp_db_vardecimal_storage_format N'Projet', N'ON'
GO
ALTER DATABASE [Projet] SET QUERY_STORE = ON
GO
ALTER DATABASE [Projet] SET QUERY_STORE (OPERATION_MODE = READ_WRITE, CLEANUP_POLICY = (STALE_QUERY_THRESHOLD_DAYS = 30), DATA_FLUSH_INTERVAL_SECONDS = 900, INTERVAL_LENGTH_MINUTES = 60, MAX_STORAGE_SIZE_MB = 1000, QUERY_CAPTURE_MODE = AUTO, SIZE_BASED_CLEANUP_MODE = AUTO, MAX_PLANS_PER_QUERY = 200, WAIT_STATS_CAPTURE_MODE = ON)
GO
USE [Projet]
GO
/****** Object:  Table [dbo].[Adresses]    Script Date: 07/12/2023 14:41:00 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Adresses](
	[Id_adresse] [int] IDENTITY(1,1) NOT NULL,
	[Numero_rue] [smallint] NULL,
	[Nom_rue] [varchar](50) NOT NULL,
	[Id_ville] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Id_adresse] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Articles]    Script Date: 07/12/2023 14:41:00 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Articles](
	[Reference_article] [varchar](30) NOT NULL,
	[Nom_article] [varchar](50) NOT NULL,
	[Prix_article_HT] [money] NOT NULL,
	[Nature_article] [varchar](20) NULL,
	[Couleur_article] [varchar](20) NULL,
	[Seuil_reapprovisionnement] [smallint] NULL,
	[Quantite_article] [smallint] NULL,
	[Pourcentage_taxe] [tinyint] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Reference_article] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Clients]    Script Date: 07/12/2023 14:41:00 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Clients](
	[Id_client] [int] NOT NULL,
	[Date_naissance] [date] NOT NULL,
	[Date_premier_achat] [date] NULL,
	[Id_adresse_livraison] [int] NOT NULL,
	[Id_adresse_facturation] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Id_client] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Commandes]    Script Date: 07/12/2023 14:41:00 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Commandes](
	[Reference_commande] [varchar](30) NOT NULL,
	[Date_livraison] [date] NOT NULL,
	[Date_emission] [date] NOT NULL,
	[Moyen_paiement] [varchar](30) NOT NULL,
	[Date_paiement] [date] NOT NULL,
	[Pourcentage_remise] [tinyint] NOT NULL,
	[Id_client] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[Reference_commande] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[constituer]    Script Date: 07/12/2023 14:41:00 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[constituer](
	[Reference_commande] [varchar](30) NOT NULL,
	[Reference_article] [varchar](30) NOT NULL,
	[Quantite_article_commande] [smallint] NOT NULL,
	[Pourcentage_remise_article] [tinyint] NULL,
PRIMARY KEY CLUSTERED 
(
	[Reference_commande] ASC,
	[Reference_article] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Personnels]    Script Date: 07/12/2023 14:41:00 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Personnels](
	[Id_personnel] [int] NOT NULL,
	[Date_embauche] [date] NOT NULL,
	[Id_adresse] [int] NOT NULL,
	[Id_superieur] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[Id_personnel] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Personnes]    Script Date: 07/12/2023 14:41:00 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Personnes](
	[Id_personne] [int] IDENTITY(1,1) NOT NULL,
	[Nom] [varchar](50) NOT NULL,
	[Prenom] [varchar](50) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Id_personne] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Villes]    Script Date: 07/12/2023 14:41:00 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Villes](
	[Id_ville] [int] IDENTITY(1,1) NOT NULL,
	[Nom_ville] [varchar](50) NOT NULL,
	[Code_postal] [varchar](10) NULL,
PRIMARY KEY CLUSTERED 
(
	[Id_ville] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Adresses] ON 

INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (1, 2, N'Route des Séquoias', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (2, 11, N'Rue des Fabres', 2)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (3, 9, N'Boulevard de Fortune', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (4, 5, N'Rue du May', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (5, 20, N'Avenue des Fleurs', 5)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (6, 7, N'Rue de Verdun', 6)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (7, 17, N'Rue du Maroquin', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (8, 1, N'Rue de la Fontaine', 8)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (9, 21, N'Rue Saint-Rémi', 9)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (10, 14, N'Rue Esquermoise', 10)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (11, 2, N'Rue du Faubourg Saint-Antoine', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (12, 15, N'Chemin des Noisettes', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (13, 6, N'Rue du Musée', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (14, 31, N'Rue du Port', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (15, 12, N'Rue des Carmes', 9)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (16, 10, N'Chemin des Cerises', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (17, 20, N'Voie des Plumes', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (18, 30, N'Voie des Criquets', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (19, 40, N'Avenue de Rue de Victoire', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (20, 50, N'Chemin du Syndicat', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (21, 35, N'Rue Saint-Ferréol', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (22, 45, N'Rue Paradis', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (23, 55, N'Rue des Canons', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (24, 65, N'Rue de Lavande', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (25, 75, N'Rue des Plumes', 1)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (26, 15, N'Rue de la Paix', 2)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (27, 25, N'Rue Royale', 2)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (28, 5, N'Place Vendôme', 2)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (29, 10, N'Rue de Clair de Lune', 2)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (30, 20, N'Rue Saint-Alexandre', 2)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (31, 35, N'Rue du Comte', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (32, 45, N'Rue de Saphir', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (33, 55, N'Cours Lieutaud', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (34, 65, N'Rue de Rome', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (35, 75, N'Rue de la République', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (36, 15, N'Boulevard de Bois', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (37, 25, N'Rue des Archives', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (38, 35, N'Rue des Colombes', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (39, 55, N'Voie du Château', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (40, 15, N'Rue de Rivoli', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (41, 25, N'Rue du Quai', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (42, 35, N'Rue Saint-Antoine', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (43, 45, N'Rue Saint-Jules', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (44, 55, N'Rue Saint-Paul', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (45, 10, N'Rue de Cuivre', 5)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (46, 20, N'Voie de Lavande', 5)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (47, 30, N'Rue des Vergers', 5)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (48, 40, N'Rue de la Rivière', 5)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (49, 50, N'Rue du Lac', 5)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (50, 15, N'Rue de la Pompe', 6)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (51, 25, N'Avenue Foch', 6)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (52, 35, N'Avenue des Ternes', 6)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (53, 45, N'Rue du Centre', 6)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (54, 55, N'Boulevard du Pégase', 6)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (55, 10, N'Rue du Commerce', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (56, 20, N'Rue de Mugissement', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (57, 30, N'Rue de Vaugirard', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (58, 40, N'Rue Bleue', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (59, 50, N'Rue de la Convention', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (60, 15, N'Rue de la Nova', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (61, 25, N'Boulevard de Vermillon', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (62, 35, N'Avenue Montaigne', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (63, 55, N'Rue de Tonnerre', 8)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (64, 15, N'Avenue des Gobelins', 8)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (65, 25, N'Rue Mouffetard', 8)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (66, 35, N'Boulevard Saint-Germain', 10)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (67, 45, N'Rue Saint-Jacques', 10)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (68, 55, N'Rue de la Huchette', 10)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (69, 10, N'Rue de Turbigo', 9)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (70, 20, N'Boulevard Saint-Denis', 9)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (71, 30, N'Boulevard de Sébastopol', 9)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (72, 40, N'Rue du Refuge', 15)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (73, 50, N'Rue du Forestier', 15)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (74, 10, N'Rue du Faubourg Saint-Honoré', 15)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (75, 20, N'Route de la Chapelle', 78)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (76, 30, N'Avenue des Champs-Élysées', 85)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (77, 40, N'Avenue de Friedland', 86)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (78, 50, N'Rue d''Aviation', 93)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (79, 15, N'Rue de la Boétie', 99)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (80, 12, N'Rue des Lilas', 78)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (81, 25, N'Rue de la Paix', 78)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (82, 8, N'Avenue des Champs-Élysées', 78)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (83, 17, N'Rue du Temple', 85)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (84, 42, N'Rue de Rivoli', 85)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (85, 73, N'Boulevard Saint-Germain', 85)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (86, 21, N'Avenue Montaigne', 86)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (87, 33, N'Rue Saint-Honoré', 86)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (88, 128, N'Boulevard Haussmann', 86)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (89, 55, N'Rue de la Roquette', 93)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (90, 78, N'Boulevard de Belleville', 93)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (91, 29, N'Avenue Parmentier', 93)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (92, 12, N'Rue de la Pompe', 99)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (93, 7, N'Rue de Passy', 99)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (94, 84, N'Boulevard Suchet', 99)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (95, 5, N'Bashford', 60)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (96, 11, N'Messerschmidt', 4)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (97, 27, N'Northview', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (98, 25, N'Westerfield', 20)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (99, 19, N'Melody', 35)
GO
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (100, 26, N'Fairfield', 80)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (101, 30, N'Carberry', 60)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (102, 24, N'Ilene', 31)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (103, 8, N'Bultman', 46)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (104, 13, N'Fallview', 28)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (105, 25, N'Sunnyside', 64)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (106, 15, N'Prairieview', 8)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (107, 30, N'Grayhawk', 43)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (108, 22, N'Blue Bill Park', 80)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (109, 20, N'Summit', 23)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (110, 22, N'Vera', 9)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (111, 7, N'Meadow Vale', 44)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (112, 13, N'Lukken', 10)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (113, 6, N'Sage', 38)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (114, 6, N'Myrtle', 65)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (115, 4, N'Parkside', 59)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (116, 18, N'Crowley', 51)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (117, 1, N'Hayes', 70)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (118, 13, N'Memorial', 99)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (119, 9, N'Hauk', 75)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (120, 30, N'Truax', 92)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (121, 18, N'Onsgard', 32)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (122, 10, N'Hermina', 23)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (123, 7, N'Grayhawk', 48)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (124, 3, N'Derek', 64)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (125, 28, N'Hintze', 15)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (126, 23, N'Express', 17)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (127, 7, N'Oriole', 27)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (128, 14, N'Heffernan', 76)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (129, 30, N'Bonner', 6)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (130, 22, N'Tennyson', 89)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (131, 29, N'American', 25)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (132, 14, N'Dawn', 34)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (133, 14, N'Hazelcrest', 30)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (134, 26, N'Granby', 19)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (135, 13, N'Caliangt', 44)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (136, 10, N'Tennyson', 92)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (137, 15, N'Esker', 39)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (138, 20, N'Golf Course', 48)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (139, 7, N'Golf Course', 63)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (140, 30, N'Wayridge', 19)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (141, 8, N'Roth', 14)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (142, 27, N'Magdeline', 50)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (143, 15, N'Cordelia', 86)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (144, 16, N'Del Mar', 20)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (145, 9, N'Caliangt', 92)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (146, 6, N'Russell', 84)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (147, 22, N'Becker', 31)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (148, 24, N'Comanche', 37)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (149, 3, N'Vernon', 81)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (150, 27, N'Texas', 27)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (151, 29, N'Beilfuss', 56)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (152, 16, N'Fuller', 64)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (153, 25, N'Paget', 54)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (154, 11, N'Monument', 83)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (155, 14, N'Cascade', 69)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (156, 29, N'Pond', 45)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (157, 17, N'Claremont', 37)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (158, 17, N'Roth', 79)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (159, 14, N'Mayfield', 81)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (160, 14, N'Annamark', 69)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (161, 5, N'Pine View', 13)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (162, 11, N'Orin', 94)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (163, 27, N'Knutson', 65)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (164, 27, N'Pepper Wood', 49)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (165, 8, N'American', 92)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (166, 8, N'Loomis', 45)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (167, 5, N'Eastlawn', 79)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (168, 28, N'Hooker', 7)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (169, 3, N'Sullivan', 82)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (170, 27, N'Alpine', 47)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (171, 30, N'Forest Run', 60)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (172, 13, N'Jenifer', 47)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (173, 19, N'Mitchell', 38)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (174, 21, N'Grayhawk', 96)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (175, 18, N'Melvin', 25)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (176, 5, N'Myrtle', 38)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (177, 13, N'Mcguire', 65)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (178, 24, N'Buena Vista', 25)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (179, 15, N'Northland', 87)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (180, 6, N'Aberg', 36)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (181, 8, N'Annamark', 69)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (182, 29, N'Green', 67)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (183, 10, N'Hanover', 48)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (184, 18, N'Vahlen', 2)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (185, 3, N'Cambridge', 55)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (186, 23, N'Lukken', 96)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (187, 14, N'Heffernan', 14)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (188, 23, N'Bowman', 22)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (189, 22, N'Carpenter', 94)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (190, 25, N'Drewry', 70)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (191, 16, N'Gina', 57)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (192, 18, N'Prairie Rose', 64)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (193, 27, N'Messerschmidt', 58)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (194, 25, N'Ilene', 74)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (195, 14, N'Barnett', 14)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (196, 21, N'Leroy', 97)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (197, 15, N'Hallows', 25)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (198, 26, N'Ronald Regan', 29)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (199, 12, N'Mcguire', 47)
GO
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (200, 30, N'Toban', 100)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (201, 23, N'Delladonna', 96)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (202, 10, N'Fieldstone', 84)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (203, 1, N'Ohio', 29)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (204, 14, N'Burning Wood', 57)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (205, 4, N'Garrison', 88)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (206, 30, N'Hintze', 75)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (207, 2, N'Aberg', 33)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (208, 7, N'Sutherland', 51)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (209, 6, N'Vera', 35)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (210, 21, N'Butternut', 14)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (211, 20, N'Onsgard', 29)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (212, 27, N'Lakewood Gardens', 44)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (213, 7, N'Lillian', 46)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (214, 16, N'Nancy', 84)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (215, 2, N'Arapahoe', 93)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (216, 30, N'Elgar', 79)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (217, 6, N'Hallows', 77)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (218, 17, N'Arrowood', 16)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (219, 23, N'Mendota', 98)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (220, 15, N'Gerald', 3)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (221, 28, N'Rockefeller', 61)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (222, 22, N'Glacier Hill', 79)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (223, 4, N'Lake View', 40)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (224, 30, N'1st', 23)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (225, 14, N'Farwell', 97)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (226, 22, N'Karstens', 88)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (227, 6, N'Trailsway', 58)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (228, 2, N'Dovetail', 71)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (229, 13, N'Main', 71)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (230, 30, N'Pennsylvania', 48)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (231, 10, N'Sunnyside', 52)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (232, 4, N'Packers', 30)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (233, 23, N'Luster', 39)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (234, 29, N'Gerald', 12)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (235, 17, N'Red Cloud', 40)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (236, 4, N'Arapahoe', 53)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (237, 12, N'Annamark', 8)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (238, 1, N'Carpenter', 90)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (239, 29, N'Oriole', 28)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (240, 2, N'Duke', 85)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (241, 12, N'Mockingbird', 67)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (242, 19, N'Hermina', 66)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (243, 16, N'Fisk', 27)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (244, 2, N'Shopko', 75)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (245, 8, N'Green Ridge', 6)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (246, 5, N'Nelson', 37)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (247, 8, N'Lillian', 28)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (248, 26, N'Coleman', 29)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (249, 9, N'Tennyson', 51)
INSERT [dbo].[Adresses] ([Id_adresse], [Numero_rue], [Nom_rue], [Id_ville]) VALUES (250, 14, N'Colorado', 6)
SET IDENTITY_INSERT [dbo].[Adresses] OFF
GO
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF001', N'Chemise en coton', 49.9900, N'Vêtement', N'Blanc', 20, 50, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF002', N'Ordinateur portable', 899.9900, N'Électronique', N'Argent', 10, 30, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF003', N'Chaussures de course', 79.9500, N'Chaussures', N'Bleu', 15, 40, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF004', N'Lampe de bureau LED', 34.5000, N'Éclairage', N'Noir', 25, 15, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF005', N'Sac à dos en cuir', 129.9900, N'Accessoire', N'Marron', 30, 25, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF006', N'Canapé en cuir', 899.0000, N'Mobilier', N'Gris', 5, 10, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF007', N'Montre-bracelet élégante', 149.9500, N'Accessoire', N'Or', 8, 20, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF008', N'Machine à café automatique', 249.9900, N'Électroménager', N'Noir', 12, 30, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF009', N'Enceinte Bluetooth', 79.9900, N'Audio', N'Rouge', 18, 15, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF010', N'Téléviseur 4K', 1299.0000, N'Électronique', N'Noir', 10, 5, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF011', N'Livre de cuisine', 19.9500, N'Livre', N'Multicolore', 25, 50, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF012', N'Vélo de montagne', 499.9900, N'Sport', N'Vert', 15, 8, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF013', N'Robe de soirée', 129.5000, N'Vêtement', N'Rouge', 20, 20, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF014', N'Aspirateur robot', 179.0000, N'Électroménager', N'Blanc', 10, 15, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF015', N'Tablette graphique', 199.9500, N'Électronique', N'Noir', 30, 12, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF016', N'Tapis de yoga', 29.9900, N'Sport', N'Bleu', 25, 30, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF017', N'Guitare acoustique', 299.0000, N'Musique', N'Naturel', 8, 18, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF018', N'Tondeuse à gazon', 129.9900, N'Jardin', N'Rouge', 12, 22, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF019', N'Casserole en acier inoxydable', 39.9500, N'Cuisine', N'Argent', 15, 40, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF020', N'Sac de voyage', 59.9900, N'Accessoire', N'Bleu', 20, 25, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF021', N'Casque audio sans fil', 89.9900, N'Audio', N'Noir', 18, 15, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF022', N'Bouteille d''eau réutilisable', 12.5000, N'Accessoire', N'Vert', 30, 50, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF023', N'Chaise de bureau ergonomique', 149.0000, N'Mobilier', N'Noir', 10, 10, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF024', N'Jeans déchirés', 59.9500, N'Vêtement', N'Bleu', 25, 30, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF025', N'Enceinte intelligente', 129.9900, N'Audio', N'Blanc', 15, 20, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF026', N'Bouilloire électrique', 24.9900, N'Cuisine', N'Inox', 20, 35, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF027', N'Sac à main en cuir', 79.5000, N'Accessoire', N'Rose', 25, 18, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF028', N'Tapis de souris ergonomique', 14.9900, N'Informatique', N'Noir', 15, 40, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF029', N'Casquette de baseball', 19.9500, N'Accessoire', N'Rouge', 12, 50, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF030', N'Haut-parleur portable', 59.9900, N'Audio', N'Bleu', 30, 15, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF031', N'Chaise pliante', 29.5000, N'Mobilier', N'Vert', 20, 25, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF032', N'Horloge murale', 39.9900, N'Décoration', N'Noir', 18, 20, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF033', N'Serviette de bain en coton', 9.9500, N'Linge de maison', N'Blanc', 40, 50, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF034', N'Pantalon de yoga', 34.9900, N'Vêtement', N'Gris', 15, 30, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF035', N'Parapluie pliant', 14.5000, N'Accessoire', N'Bleu', 25, 10, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF036', N'Étagère murale', 49.9900, N'Mobilier', N'Bois', 12, 15, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF037', N'Théière en fonte', 79.9500, N'Cuisine', N'Noir', 10, 20, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF038', N'Puzzle 1000 pièces', 19.9900, N'Jeux', N'Multicolore', 30, 8, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF039', N'Cadre photo en argent', 29.5000, N'Décoration', N'Argent', 20, 12, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF040', N'Brosse à dents électrique', 39.9900, N'Soin personnel', N'Blanc', 15, 30, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF041', N'Vernis à ongles', 8.9900, N'Soin personnel', N'Rose', 25, 25, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF042', N'Pèse-personne électronique', 29.9500, N'Soin personnel', N'Vert', 37, 49, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF043', N'Plante d''intérieur', 24.9900, N'Décoration', N'Vert', 18, 10, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF044', N'Miroir mural', 59.5000, N'Décoration', N'Argent', 15, 15, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF045', N'Cafetière à piston', 34.9500, N'Cuisine', N'Inox', 20, 20, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF046', N'Sacoche pour ordinateur portable', 49.9900, N'Accessoire', N'Noir', 25, 18, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF047', N'Plateau de service en bambou', 19.9900, N'Cuisine', N'Naturel', 12, 25, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF048', N'Coussin décoratif', 14.5000, N'Décoration', N'Bleu', 30, 30, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF049', N'Câble de charge USB-C', 9.9500, N'Accessoire', N'Gris', 25, 40, 20)
INSERT [dbo].[Articles] ([Reference_article], [Nom_article], [Prix_article_HT], [Nature_article], [Couleur_article], [Seuil_reapprovisionnement], [Quantite_article], [Pourcentage_taxe]) VALUES (N'REF050', N'Carafe en verre', 22.9900, N'Cuisine', N'Transparent', 18, 22, 20)
GO
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (51, CAST(N'1984-04-22' AS Date), CAST(N'2022-05-02' AS Date), 51, 52)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (52, CAST(N'1995-09-20' AS Date), CAST(N'2017-08-20' AS Date), 53, 54)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (53, CAST(N'1984-02-12' AS Date), CAST(N'2020-12-04' AS Date), 55, 56)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (54, CAST(N'1994-09-13' AS Date), CAST(N'2022-11-26' AS Date), 57, 58)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (55, CAST(N'1998-12-28' AS Date), CAST(N'2018-06-13' AS Date), 59, 60)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (56, CAST(N'1987-12-11' AS Date), CAST(N'2023-05-03' AS Date), 61, 62)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (57, CAST(N'1993-07-25' AS Date), CAST(N'2021-05-19' AS Date), 63, 64)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (58, CAST(N'2003-01-29' AS Date), CAST(N'2021-04-21' AS Date), 65, 66)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (59, CAST(N'1998-12-09' AS Date), CAST(N'2015-09-17' AS Date), 67, 68)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (60, CAST(N'1998-05-29' AS Date), CAST(N'2022-10-12' AS Date), 69, 70)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (61, CAST(N'2001-10-14' AS Date), CAST(N'2015-12-04' AS Date), 71, 72)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (62, CAST(N'1987-09-21' AS Date), CAST(N'2019-02-18' AS Date), 73, 74)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (63, CAST(N'1998-04-02' AS Date), CAST(N'2020-05-02' AS Date), 75, 76)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (64, CAST(N'1983-05-30' AS Date), CAST(N'2015-08-30' AS Date), 77, 78)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (65, CAST(N'1995-11-30' AS Date), CAST(N'2015-12-06' AS Date), 79, 80)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (66, CAST(N'1993-06-27' AS Date), NULL, 81, 82)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (67, CAST(N'1991-05-06' AS Date), NULL, 83, 84)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (68, CAST(N'1982-01-13' AS Date), NULL, 85, 86)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (69, CAST(N'1995-03-01' AS Date), NULL, 87, 88)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (70, CAST(N'1989-08-14' AS Date), NULL, 89, 90)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (71, CAST(N'2003-07-23' AS Date), NULL, 91, 92)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (72, CAST(N'1987-10-23' AS Date), NULL, 93, 94)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (73, CAST(N'1994-08-16' AS Date), NULL, 95, 96)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (74, CAST(N'1986-12-03' AS Date), NULL, 97, 98)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (75, CAST(N'1982-01-26' AS Date), NULL, 99, 100)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (76, CAST(N'1998-10-14' AS Date), NULL, 101, 102)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (77, CAST(N'1988-08-10' AS Date), NULL, 103, 104)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (78, CAST(N'1995-12-25' AS Date), NULL, 105, 106)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (79, CAST(N'1980-06-20' AS Date), NULL, 107, 108)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (80, CAST(N'1988-08-05' AS Date), NULL, 109, 110)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (81, CAST(N'1998-12-01' AS Date), NULL, 111, 112)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (82, CAST(N'1993-04-24' AS Date), NULL, 113, 114)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (83, CAST(N'2000-07-11' AS Date), NULL, 115, 116)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (84, CAST(N'1997-04-15' AS Date), NULL, 117, 118)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (85, CAST(N'2003-06-07' AS Date), NULL, 119, 120)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (86, CAST(N'1992-12-09' AS Date), NULL, 121, 122)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (87, CAST(N'2001-05-19' AS Date), NULL, 123, 124)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (88, CAST(N'1983-02-24' AS Date), NULL, 125, 126)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (89, CAST(N'1984-03-11' AS Date), NULL, 127, 128)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (90, CAST(N'1981-08-16' AS Date), NULL, 129, 130)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (91, CAST(N'1984-03-05' AS Date), NULL, 131, 132)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (92, CAST(N'2002-05-05' AS Date), NULL, 133, 134)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (93, CAST(N'1985-02-09' AS Date), NULL, 135, 136)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (94, CAST(N'1994-02-23' AS Date), NULL, 137, 138)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (95, CAST(N'1984-11-06' AS Date), NULL, 139, 140)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (96, CAST(N'1984-02-21' AS Date), NULL, 141, 142)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (97, CAST(N'1997-11-21' AS Date), NULL, 143, 144)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (98, CAST(N'1985-07-29' AS Date), NULL, 145, 146)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (99, CAST(N'1980-12-28' AS Date), NULL, 147, 148)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (100, CAST(N'1984-11-28' AS Date), NULL, 149, 150)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (101, CAST(N'1989-05-15' AS Date), NULL, 151, 152)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (102, CAST(N'1993-01-10' AS Date), NULL, 153, 154)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (103, CAST(N'1988-06-11' AS Date), NULL, 155, 156)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (104, CAST(N'1984-07-05' AS Date), NULL, 157, 158)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (105, CAST(N'1992-01-19' AS Date), NULL, 159, 160)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (106, CAST(N'1996-06-22' AS Date), NULL, 161, 162)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (107, CAST(N'2001-06-19' AS Date), NULL, 163, 164)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (108, CAST(N'1984-11-20' AS Date), NULL, 165, 166)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (109, CAST(N'1995-05-12' AS Date), NULL, 167, 168)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (110, CAST(N'1994-09-11' AS Date), NULL, 169, 170)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (111, CAST(N'1995-02-19' AS Date), NULL, 171, 172)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (112, CAST(N'1986-11-05' AS Date), NULL, 173, 174)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (113, CAST(N'1999-09-06' AS Date), NULL, 175, 176)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (114, CAST(N'2003-01-18' AS Date), NULL, 177, 178)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (115, CAST(N'1990-11-24' AS Date), NULL, 179, 180)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (116, CAST(N'1998-10-20' AS Date), NULL, 181, 182)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (117, CAST(N'1984-04-22' AS Date), NULL, 183, 184)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (118, CAST(N'1986-07-23' AS Date), NULL, 185, 186)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (119, CAST(N'1987-10-31' AS Date), NULL, 187, 188)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (120, CAST(N'1987-08-05' AS Date), NULL, 189, 190)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (121, CAST(N'1999-04-15' AS Date), NULL, 191, 192)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (122, CAST(N'1990-10-18' AS Date), NULL, 193, 194)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (123, CAST(N'1988-11-08' AS Date), NULL, 195, 196)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (124, CAST(N'1983-11-26' AS Date), NULL, 197, 198)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (125, CAST(N'1982-04-18' AS Date), NULL, 199, 200)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (126, CAST(N'1982-03-08' AS Date), NULL, 201, 202)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (127, CAST(N'1995-09-28' AS Date), NULL, 203, 204)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (128, CAST(N'1999-09-16' AS Date), NULL, 205, 206)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (129, CAST(N'1989-04-13' AS Date), NULL, 207, 208)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (130, CAST(N'1991-12-21' AS Date), NULL, 209, 210)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (131, CAST(N'1997-11-20' AS Date), NULL, 211, 212)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (132, CAST(N'1995-12-22' AS Date), NULL, 213, 214)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (133, CAST(N'1992-07-11' AS Date), NULL, 215, 216)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (134, CAST(N'1986-02-23' AS Date), NULL, 217, 218)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (135, CAST(N'2001-06-11' AS Date), NULL, 219, 220)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (136, CAST(N'1998-11-05' AS Date), NULL, 221, 222)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (137, CAST(N'2001-08-08' AS Date), NULL, 223, 224)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (138, CAST(N'1995-07-21' AS Date), NULL, 225, 226)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (139, CAST(N'1996-07-01' AS Date), NULL, 227, 228)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (140, CAST(N'1983-04-09' AS Date), NULL, 229, 230)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (141, CAST(N'1993-01-09' AS Date), NULL, 231, 232)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (142, CAST(N'1985-03-31' AS Date), NULL, 233, 234)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (143, CAST(N'1984-05-01' AS Date), NULL, 235, 236)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (144, CAST(N'1999-12-19' AS Date), NULL, 237, 238)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (145, CAST(N'1988-01-19' AS Date), NULL, 239, 240)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (146, CAST(N'1995-05-07' AS Date), NULL, 241, 242)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (147, CAST(N'1998-06-21' AS Date), NULL, 243, 244)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (148, CAST(N'2003-01-29' AS Date), NULL, 245, 246)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (149, CAST(N'2000-01-26' AS Date), NULL, 247, 248)
INSERT [dbo].[Clients] ([Id_client], [Date_naissance], [Date_premier_achat], [Id_adresse_livraison], [Id_adresse_facturation]) VALUES (150, CAST(N'1997-09-08' AS Date), NULL, 249, 250)
GO
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'AGGA2015SAD15', CAST(N'2015-12-09' AS Date), CAST(N'2015-12-05' AS Date), N'Bitcoin', CAST(N'2015-12-06' AS Date), 0, 65)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'ANHA2023STR6', CAST(N'2023-05-10' AS Date), CAST(N'2023-05-06' AS Date), N'Bitcoin', CAST(N'2023-05-03' AS Date), 0, 56)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'BAEU2020STR3', CAST(N'2021-12-08' AS Date), CAST(N'2021-12-04' AS Date), N'Carte', CAST(N'2020-12-04' AS Date), 0, 53)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'BAHI2020LEG13', CAST(N'2020-05-05' AS Date), CAST(N'2020-05-01' AS Date), N'Bitcoin', CAST(N'2020-05-02' AS Date), 0, 63)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'HOSA2021MON7', CAST(N'2021-05-24' AS Date), CAST(N'2021-05-21' AS Date), N'Bitcoin', CAST(N'2021-05-19' AS Date), 0, 57)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'KAKA2017NAN2', CAST(N'2017-08-27' AS Date), CAST(N'2017-08-23' AS Date), N'Carte', CAST(N'2017-08-20' AS Date), 0, 52)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'KISC2018STR5', CAST(N'2018-06-20' AS Date), CAST(N'2018-06-16' AS Date), N'Cash', CAST(N'2018-06-13' AS Date), 0, 55)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'LOME2015CAY14', CAST(N'2015-09-05' AS Date), CAST(N'2015-09-01' AS Date), N'Carte', CAST(N'2015-08-30' AS Date), 0, 64)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'LOSC2022NAN1', CAST(N'2023-05-09' AS Date), CAST(N'2023-05-05' AS Date), N'Cash', CAST(N'2022-05-02' AS Date), 0, 51)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'PEMI2019TOU12', CAST(N'2019-02-25' AS Date), CAST(N'2019-02-21' AS Date), N'Paypal', CAST(N'2019-02-18' AS Date), 0, 62)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'REDE2015BOR11', CAST(N'2015-12-11' AS Date), CAST(N'2015-12-07' AS Date), N'Cash', CAST(N'2015-12-04' AS Date), 0, 61)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'ROBU2022BOR10', CAST(N'2022-10-16' AS Date), CAST(N'2022-10-12' AS Date), N'Paypal', CAST(N'2022-10-12' AS Date), 0, 60)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'TYWH2015LIL9', CAST(N'2015-09-24' AS Date), CAST(N'2015-09-20' AS Date), N'Paypal', CAST(N'2015-09-17' AS Date), 0, 59)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'VIFU2022STR4', CAST(N'2022-11-30' AS Date), CAST(N'2022-11-26' AS Date), N'Carte', CAST(N'2022-11-26' AS Date), 0, 54)
INSERT [dbo].[Commandes] ([Reference_commande], [Date_livraison], [Date_emission], [Moyen_paiement], [Date_paiement], [Pourcentage_remise], [Id_client]) VALUES (N'VIPA2021MON8', CAST(N'2021-04-28' AS Date), CAST(N'2021-04-24' AS Date), N'Paypal', CAST(N'2021-04-21' AS Date), 0, 58)
GO
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'AGGA2015SAD15', N'REF040', 3, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'AGGA2015SAD15', N'REF041', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'AGGA2015SAD15', N'REF042', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'ANHA2023STR6', N'REF016', 5, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'ANHA2023STR6', N'REF017', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'ANHA2023STR6', N'REF018', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'BAEU2020STR3', N'REF007', 3, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'BAEU2020STR3', N'REF008', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'BAEU2020STR3', N'REF009', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'BAHI2020LEG13', N'REF034', 3, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'BAHI2020LEG13', N'REF035', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'BAHI2020LEG13', N'REF036', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'HOSA2021MON7', N'REF019', 3, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'HOSA2021MON7', N'REF020', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'HOSA2021MON7', N'REF021', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'KAKA2017NAN2', N'REF004', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'KAKA2017NAN2', N'REF005', 4, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'KAKA2017NAN2', N'REF006', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'KISC2018STR5', N'REF013', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'KISC2018STR5', N'REF014', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'KISC2018STR5', N'REF015', 3, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'LOME2015CAY14', N'REF037', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'LOME2015CAY14', N'REF038', 5, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'LOME2015CAY14', N'REF039', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'LOSC2022NAN1', N'REF001', 3, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'LOSC2022NAN1', N'REF002', 5, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'LOSC2022NAN1', N'REF003', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'PEMI2019TOU12', N'REF031', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'PEMI2019TOU12', N'REF032', 4, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'PEMI2019TOU12', N'REF033', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'REDE2015BOR11', N'REF028', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'REDE2015BOR11', N'REF029', 3, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'REDE2015BOR11', N'REF030', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'ROBU2022BOR10', N'REF025', 3, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'ROBU2022BOR10', N'REF026', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'ROBU2022BOR10', N'REF027', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'TYWH2015LIL9', N'REF022', 4, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'TYWH2015LIL9', N'REF023', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'TYWH2015LIL9', N'REF024', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'VIFU2022STR4', N'REF010', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'VIFU2022STR4', N'REF011', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'VIFU2022STR4', N'REF012', 4, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'VIPA2021MON8', N'REF043', 2, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'VIPA2021MON8', N'REF044', 1, 0)
INSERT [dbo].[constituer] ([Reference_commande], [Reference_article], [Quantite_article_commande], [Pourcentage_remise_article]) VALUES (N'VIPA2021MON8', N'REF045', 4, 0)
GO
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (1, CAST(N'2020-05-18' AS Date), 1, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (2, CAST(N'2019-11-29' AS Date), 2, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (3, CAST(N'2015-12-30' AS Date), 3, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (4, CAST(N'2020-06-20' AS Date), 4, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (5, CAST(N'2018-09-10' AS Date), 5, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (6, CAST(N'2019-12-29' AS Date), 6, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (7, CAST(N'2018-02-12' AS Date), 7, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (8, CAST(N'2018-11-06' AS Date), 8, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (9, CAST(N'2022-08-19' AS Date), 9, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (10, CAST(N'2023-03-07' AS Date), 10, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (11, CAST(N'2016-10-07' AS Date), 11, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (12, CAST(N'2023-08-02' AS Date), 12, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (13, CAST(N'2020-04-09' AS Date), 13, NULL)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (14, CAST(N'2017-07-09' AS Date), 14, 1)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (15, CAST(N'2021-05-17' AS Date), 15, 1)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (16, CAST(N'2017-04-13' AS Date), 16, 1)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (17, CAST(N'2015-09-13' AS Date), 17, 2)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (18, CAST(N'2016-06-20' AS Date), 18, 2)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (19, CAST(N'2019-03-09' AS Date), 19, 2)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (20, CAST(N'2020-06-21' AS Date), 20, 3)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (21, CAST(N'2017-02-07' AS Date), 21, 3)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (22, CAST(N'2022-05-22' AS Date), 22, 3)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (23, CAST(N'2019-05-06' AS Date), 23, 4)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (24, CAST(N'2015-05-31' AS Date), 24, 4)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (25, CAST(N'2017-07-20' AS Date), 25, 4)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (26, CAST(N'2019-06-04' AS Date), 26, 5)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (27, CAST(N'2020-02-26' AS Date), 27, 5)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (28, CAST(N'2023-09-06' AS Date), 28, 5)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (29, CAST(N'2015-06-08' AS Date), 29, 6)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (30, CAST(N'2019-07-08' AS Date), 30, 6)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (31, CAST(N'2021-07-27' AS Date), 31, 6)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (32, CAST(N'2019-08-08' AS Date), 32, 7)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (33, CAST(N'2022-01-13' AS Date), 33, 7)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (34, CAST(N'2018-04-23' AS Date), 34, 7)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (35, CAST(N'2017-06-01' AS Date), 35, 8)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (36, CAST(N'2021-03-18' AS Date), 36, 8)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (37, CAST(N'2019-02-09' AS Date), 37, 8)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (38, CAST(N'2016-07-02' AS Date), 38, 9)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (39, CAST(N'2018-05-09' AS Date), 39, 9)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (40, CAST(N'2020-09-27' AS Date), 40, 9)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (41, CAST(N'2017-04-06' AS Date), 41, 10)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (42, CAST(N'2022-07-09' AS Date), 42, 10)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (43, CAST(N'2019-08-03' AS Date), 43, 10)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (44, CAST(N'2016-07-20' AS Date), 44, 11)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (45, CAST(N'2018-01-25' AS Date), 45, 11)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (46, CAST(N'2018-08-13' AS Date), 46, 11)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (47, CAST(N'2016-02-27' AS Date), 47, 12)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (48, CAST(N'2023-09-02' AS Date), 48, 12)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (49, CAST(N'2019-08-17' AS Date), 49, 12)
INSERT [dbo].[Personnels] ([Id_personnel], [Date_embauche], [Id_adresse], [Id_superieur]) VALUES (50, CAST(N'2019-04-07' AS Date), 50, 13)
GO
SET IDENTITY_INSERT [dbo].[Personnes] ON 

INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (1, N'Ingleson', N'Lezlie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (2, N'Nickoll', N'Lissy')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (3, N'Duxbury', N'Dot')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (4, N'Semple', N'Marge')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (5, N'Halworth', N'Karlotte')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (6, N'McCombe', N'Leonie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (7, N'Shackelton', N'Cleo')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (8, N'Bowry', N'Andriana')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (9, N'Baglow', N'Rinaldo')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (10, N'Bart', N'Loria')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (11, N'Lathleiff', N'Jennifer')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (12, N'Euesden', N'Brade')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (13, N'Matous', N'Kimmie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (14, N'Worsom', N'Cosetta')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (15, N'Domenichini', N'Dedie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (16, N'McGirl', N'Karly')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (17, N'Davitt', N'Perrine')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (18, N'Starten', N'Zelma')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (19, N'Sproul', N'Arlyne')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (20, N'Relton', N'Bertine')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (21, N'Saffell', N'Dorthy')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (22, N'Hindrick', N'Abagail')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (23, N'Ettritch', N'Barry')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (24, N'Colebrook', N'Esther')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (25, N'Arlow', N'Merrili')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (26, N'Midghall', N'Rheba')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (27, N'Weller', N'Doria')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (28, N'Godson', N'Giovanni')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (29, N'Manford', N'Clemmy')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (30, N'Nockles', N'Cristionna')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (31, N'Franzelini', N'Farand')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (32, N'Wikey', N'Sigismondo')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (33, N'Grimestone', N'Rakel')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (34, N'Ipgrave', N'Zorah')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (35, N'Ebbett', N'Ara')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (36, N'Troke', N'Rouvin')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (37, N'Dack', N'Elianore')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (38, N'Kingsley', N'Diane')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (39, N'McCrackan', N'Rosamund')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (40, N'Cranham', N'Kenton')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (41, N'Luciani', N'Larina')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (42, N'Morrison', N'Bendick')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (43, N'Regenhardt', N'Ddene')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (44, N'Perryman', N'Corly')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (45, N'Nolin', N'Graehme')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (46, N'Grisard', N'Joell')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (47, N'Pirnie', N'Lorine')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (48, N'Halfacree', N'Duane')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (49, N'Kuhlen', N'Doy')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (50, N'Aaronson', N'Maryrose')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (51, N'Scarff', N'Lou')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (52, N'Kahen', N'Karmen')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (53, N'Eustace', N'Barth')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (54, N'Fuente', N'Vicki')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (55, N'Scriviner', N'Kippie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (56, N'Halson', N'Anya')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (57, N'Salvidge', N'Hodge')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (58, N'Pakenham', N'Vinson')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (59, N'Whittlesee', N'Tybie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (60, N'Buchan', N'Rossy')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (61, N'de Werk', N'Regan')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (62, N'Midlar', N'Petronia')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (63, N'Hirjak', N'Bay')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (64, N'Meriott', N'Lombard')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (65, N'Gallelli', N'Agnese')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (66, N'Bizley', N'Yoko')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (67, N'Loche', N'Faye')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (68, N'Tomanek', N'Cherey')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (69, N'Kilrow', N'Emmalee')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (70, N'Pittle', N'Raye')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (71, N'Kempston', N'Amalle')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (72, N'Kettridge', N'Leah')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (73, N'Leet', N'Ara')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (74, N'MacLachlan', N'Witty')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (75, N'Vivyan', N'Codi')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (76, N'Ordelt', N'Lyon')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (77, N'Pugh', N'Kendricks')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (78, N'Mulliss', N'Teodorico')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (79, N'Burtwhistle', N'Miller')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (80, N'Barkhouse', N'Tonie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (81, N'Grayer', N'Brendon')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (82, N'Prendergrast', N'Rivkah')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (83, N'Golton', N'Arlette')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (84, N'Traves', N'Padraig')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (85, N'Woodhams', N'Conan')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (86, N'Alner', N'Blane')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (87, N'Allderidge', N'Adrianne')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (88, N'Kienl', N'Maureene')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (89, N'Hadgkiss', N'Worth')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (90, N'Roper', N'Jermaine')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (91, N'Warman', N'Gayle')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (92, N'Berre', N'Derril')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (93, N'Eliassen', N'Dilan')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (94, N'Isacsson', N'Linea')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (95, N'Ritchley', N'Darryl')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (96, N'Morter', N'Ferdinand')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (97, N'Frankland', N'Lonna')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (98, N'Pilgram', N'Gonzalo')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (99, N'McGennis', N'Trixie')
GO
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (100, N'Leafe', N'Minna')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (101, N'Gerty', N'Abrahan')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (102, N'McQuaide', N'Norene')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (103, N'Methven', N'Brett')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (104, N'Golightly', N'Rudie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (105, N'Ledgard', N'Astrix')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (106, N'Phillins', N'Jillie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (107, N'MacGown', N'Oliver')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (108, N'Lindholm', N'Fergus')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (109, N'Barbe', N'Jens')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (110, N'Veryan', N'Mehetabel')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (111, N'Patey', N'Berti')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (112, N'Farfoot', N'Ailyn')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (113, N'McGiffin', N'Clarissa')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (114, N'Bummfrey', N'Viviene')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (115, N'Hatt', N'Luce')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (116, N'Bridger', N'Wendeline')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (117, N'Count', N'Francoise')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (118, N'Baldacchino', N'Else')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (119, N'Redsall', N'Carola')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (120, N'Keelan', N'Adorne')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (121, N'de Almeida', N'Phylis')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (122, N'Laurentino', N'Lamont')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (123, N'Felmingham', N'Berke')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (124, N'Girke', N'Anne-marie')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (125, N'Volonte', N'Abeu')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (126, N'De Cruze', N'Axe')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (127, N'Bowling', N'Marshal')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (128, N'McTavy', N'Felizio')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (129, N'Calbaithe', N'Lawrence')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (130, N'Bothram', N'Ashton')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (131, N'Taunton.', N'Lillis')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (132, N'Bendon', N'Barri')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (133, N'Wenzel', N'Micheline')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (134, N'Saunton', N'Gran')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (135, N'Coster', N'Mychal')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (136, N'Dunnaway', N'Lindsay')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (137, N'Teeney', N'Jeromy')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (138, N'Wildin', N'Lurette')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (139, N'Bixley', N'Iolanthe')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (140, N'Grichukhin', N'Nikolaus')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (141, N'Capelle', N'Saunderson')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (142, N'Lafay', N'Rochelle')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (143, N'Jone', N'Van')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (144, N'Earingey', N'Blithe')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (145, N'Dauber', N'Denis')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (146, N'Colbridge', N'Alix')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (147, N'Wisniewski', N'Rebeka')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (148, N'Jaime', N'Rhea')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (149, N'Sail', N'Katalin')
INSERT [dbo].[Personnes] ([Id_personne], [Nom], [Prenom]) VALUES (150, N'Varrow', N'Cobby')
SET IDENTITY_INSERT [dbo].[Personnes] OFF
GO
SET IDENTITY_INSERT [dbo].[Villes] ON 

INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (1, N'Paris', N'75000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (2, N'Marseille', N'13000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (3, N'Lyon', N'69000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (4, N'Toulouse', N'31000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (5, N'Nice', N'6000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (6, N'Nantes', N'44000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (7, N'Strasbourg', N'67000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (8, N'Montpellier', N'34000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (9, N'Bordeaux', N'33000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (10, N'Lille', N'59000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (11, N'Rennes', N'35000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (12, N'Reims', N'51000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (13, N'Le Havre', N'76600')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (14, N'Saint-Étienne', N'42000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (15, N'Toulon', N'83000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (16, N'Grenoble', N'38000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (17, N'Dijon', N'21000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (18, N'Angers', N'49000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (19, N'Nîmes', N'30000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (20, N'Villeurbanne', N'69100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (21, N'Saint-Denis', N'93200')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (22, N'Le Mans', N'72000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (23, N'Aix-en-Provence', N'13090')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (24, N'Clermont-Ferrand', N'63000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (25, N'Brest', N'29200')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (26, N'Limoges', N'87000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (27, N'Tours', N'37000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (28, N'Amiens', N'80000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (29, N'Perpignan', N'66000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (30, N'Metz', N'57000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (31, N'Besançon', N'25000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (32, N'Boulogne-Billancourt', N'92100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (33, N'Orléans', N'45000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (34, N'Mulhouse', N'68100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (35, N'Rouen', N'76000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (36, N'Caen', N'14000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (37, N'Nancy', N'54000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (38, N'Argenteuil', N'95100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (39, N'Montreuil', N'93100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (40, N'Roubaix', N'59100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (41, N'Tourcoing', N'59200')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (42, N'Nanterre', N'92000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (43, N'Vitry-sur-Seine', N'94400')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (44, N'Créteil', N'94000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (45, N'Dunkerque', N'59140')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (46, N'Poitiers', N'86000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (47, N'Asnières-sur-Seine', N'92600')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (48, N'Courbevoie', N'92400')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (49, N'Versailles', N'78000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (50, N'Colmar', N'68000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (51, N'La Rochelle', N'17000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (52, N'Aubervilliers', N'93300')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (53, N'Pau', N'64445')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (54, N'Avignon', N'84000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (55, N'Calais', N'62100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (56, N'Antibes', N'6600')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (57, N'Saint-Maur-des-Fossés', N'94100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (58, N'Chambéry', N'73000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (59, N'Niort', N'79000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (60, N'Annecy', N'74000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (61, N'Saint-Nazaire', N'44600')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (62, N'Aubagne', N'13400')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (63, N'Saint-Quentin', N'2100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (64, N'Mâcon', N'71000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (65, N'Châtellerault', N'86100')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (66, N'Cagnes-sur-Mer', N'6800')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (67, N'Chelles', N'77500')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (68, N'Chartres', N'28000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (69, N'Vénissieux', N'69200')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (70, N'Pessac', N'33600')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (71, N'Valence', N'26000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (72, N'Ajaccio', N'20000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (73, N'Quimper', N'29000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (74, N'Villefranche-sur-Saône', N'69400')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (75, N'Beauvais', N'60000')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (76, N'Les Abymes', N'97139')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (77, N'Baie-Mahault', N'97122')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (78, N'Le Gosier', N'97190')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (79, N'Sainte-Anne', N'97180')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (80, N'Petit-Bourg', N'97170')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (81, N'Fort-de-France', N'97200')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (82, N'Le Lamentin', N'97232')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (83, N'Saint-Joseph', N'97212')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (84, N'Schoelcher', N'97233')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (85, N'Ducos', N'97224')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (86, N'Cayenne', N'97300')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (87, N'Matoury', N'97351')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (88, N'Saint-Laurent-du-Maroni', N'97320')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (89, N'Kourou', N'97310')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (90, N'Remire-Montjoly', N'97354')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (91, N'Saint-Denis', N'97400')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (92, N'Saint-Paul', N'97460')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (93, N'Saint-Pierre', N'97410')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (94, N'Le Tampon', N'97430')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (95, N'Saint-André', N'97440')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (96, N'Mamoudzou', N'97600')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (97, N'Koungou', N'97650')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (98, N'Dzaoudzi', N'97615')
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (99, N'Sada', N'97640')
GO
INSERT [dbo].[Villes] ([Id_ville], [Nom_ville], [Code_postal]) VALUES (100, N'Bandraboua', N'97660')
SET IDENTITY_INSERT [dbo].[Villes] OFF
GO
/****** Object:  Index [UQ__Clients__BEF4898CAC866B66]    Script Date: 07/12/2023 14:41:00 ******/
ALTER TABLE [dbo].[Clients] ADD UNIQUE NONCLUSTERED 
(
	[Id_adresse_livraison] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [UQ__Clients__C3C7A4EB6055E257]    Script Date: 07/12/2023 14:41:00 ******/
ALTER TABLE [dbo].[Clients] ADD UNIQUE NONCLUSTERED 
(
	[Id_adresse_facturation] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Adresses]  WITH CHECK ADD FOREIGN KEY([Id_ville])
REFERENCES [dbo].[Villes] ([Id_ville])
GO
ALTER TABLE [dbo].[Clients]  WITH CHECK ADD FOREIGN KEY([Id_adresse_livraison])
REFERENCES [dbo].[Adresses] ([Id_adresse])
GO
ALTER TABLE [dbo].[Clients]  WITH CHECK ADD FOREIGN KEY([Id_adresse_facturation])
REFERENCES [dbo].[Adresses] ([Id_adresse])
GO
ALTER TABLE [dbo].[Clients]  WITH CHECK ADD FOREIGN KEY([Id_client])
REFERENCES [dbo].[Personnes] ([Id_personne])
GO
ALTER TABLE [dbo].[Commandes]  WITH CHECK ADD FOREIGN KEY([Id_client])
REFERENCES [dbo].[Clients] ([Id_client])
GO
ALTER TABLE [dbo].[constituer]  WITH CHECK ADD FOREIGN KEY([Reference_commande])
REFERENCES [dbo].[Commandes] ([Reference_commande])
GO
ALTER TABLE [dbo].[constituer]  WITH CHECK ADD FOREIGN KEY([Reference_article])
REFERENCES [dbo].[Articles] ([Reference_article])
GO
ALTER TABLE [dbo].[Personnels]  WITH CHECK ADD FOREIGN KEY([Id_adresse])
REFERENCES [dbo].[Adresses] ([Id_adresse])
GO
ALTER TABLE [dbo].[Personnels]  WITH CHECK ADD FOREIGN KEY([Id_personnel])
REFERENCES [dbo].[Personnes] ([Id_personne])
GO
ALTER TABLE [dbo].[Personnels]  WITH CHECK ADD FOREIGN KEY([Id_superieur])
REFERENCES [dbo].[Personnels] ([Id_personnel])
GO
USE [master]
GO
ALTER DATABASE [Projet] SET  READ_WRITE 
GO
