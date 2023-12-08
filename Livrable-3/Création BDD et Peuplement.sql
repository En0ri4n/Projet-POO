USE Projet;


CREATE TABLE Villes(
   Id_ville INT IDENTITY,
   Nom_ville VARCHAR(50)  NOT NULL,
   Code_postal VARCHAR(10) ,
   PRIMARY KEY(Id_ville)
);

CREATE TABLE Personnes(
   Id_personne INT IDENTITY,
   Nom VARCHAR(50)  NOT NULL,
   Prenom VARCHAR(50)  NOT NULL,
   PRIMARY KEY(Id_personne)
);

CREATE TABLE Articles(
   Reference_article VARCHAR(30) ,
   Nom_article VARCHAR(50)  NOT NULL,
   Prix_article_HT MONEY NOT NULL,
   Nature_article VARCHAR(20) ,
   Couleur_article VARCHAR(20) ,
   Seuil_reapprovisionnement SMALLINT,
   Quantite_article SMALLINT,
   Pourcentage_taxe TINYINT NOT NULL,
   PRIMARY KEY(Reference_article)
);

CREATE TABLE Adresses(
   Id_adresse INT IDENTITY,
   Numero_rue SMALLINT,
   Nom_rue VARCHAR(50)  NOT NULL,
   Id_ville INT NOT NULL,
   PRIMARY KEY(Id_adresse),
   FOREIGN KEY(Id_ville) REFERENCES Villes(Id_ville)
);

CREATE TABLE Clients(
   Id_client INT,
   Date_naissance DATE NOT NULL,
   Date_premier_achat DATE,
   Id_adresse_livraison INT NOT NULL,
   Id_adresse_facturation INT NOT NULL,
   PRIMARY KEY(Id_client),
   UNIQUE(Id_adresse_livraison),
   UNIQUE(Id_adresse_facturation),
   FOREIGN KEY(Id_client) REFERENCES Personnes(Id_personne),
   FOREIGN KEY(Id_adresse_livraison) REFERENCES Adresses(Id_adresse),
   FOREIGN KEY(Id_adresse_facturation) REFERENCES Adresses(Id_adresse)
);

CREATE TABLE Commandes(
   Reference_commande VARCHAR(30) ,
   Date_livraison DATE NOT NULL,
   Date_emission DATE NOT NULL,
   Moyen_paiement VARCHAR(30)  NOT NULL,
   Date_paiement DATE NOT NULL,
   Pourcentage_remise TINYINT NOT NULL,
   Id_client INT,
   PRIMARY KEY(Reference_commande),
   FOREIGN KEY(Id_client) REFERENCES Clients(Id_client)
);

CREATE TABLE Personnels(
   Id_personnel INT,
   Date_embauche DATE NOT NULL,
   Id_adresse INT NOT NULL,
   Id_superieur INT,
   PRIMARY KEY(Id_personnel),
   FOREIGN KEY(Id_personnel) REFERENCES Personnes(Id_personne),
   FOREIGN KEY(Id_adresse) REFERENCES Adresses(Id_adresse),
   FOREIGN KEY(Id_superieur) REFERENCES Personnels(Id_personnel)
);

CREATE TABLE constituer(
   Reference_commande VARCHAR(30) ,
   Reference_article VARCHAR(30) ,
   Quantite_article_commande SMALLINT NOT NULL,
   Pourcentage_remise_article TINYINT,
   PRIMARY KEY(Reference_commande, Reference_article),
   FOREIGN KEY(Reference_commande) REFERENCES Commandes(Reference_commande),
   FOREIGN KEY(Reference_article) REFERENCES Articles(Reference_article)
);

----------------------------------------------------------

INSERT INTO Villes (Nom_ville, Code_postal) VALUES 
('Paris', 75000),
('Marseille', 13000),
('Lyon', 69000),
('Toulouse', 31000),
('Nice', 6000),
('Nantes', 44000),
('Strasbourg', 67000),
('Montpellier', 34000),
('Bordeaux', 33000),
('Lille', 59000),
('Rennes', 35000),
('Reims', 51000),
('Le Havre', 76600),
('Saint-Étienne', 42000),
('Toulon', 83000),
('Grenoble', 38000),
('Dijon', 21000),
('Angers', 49000),
('Nîmes', 30000),
('Villeurbanne', 69100),
('Saint-Denis', 93200),
('Le Mans', 72000),
('Aix-en-Provence', 13090),
('Clermont-Ferrand', 63000),
('Brest', 29200),
('Limoges', 87000),
('Tours', 37000),
('Amiens', 80000),
('Perpignan', 66000),
('Metz', 57000),
('Besançon', 25000),
('Boulogne-Billancourt', 92100),
('Orléans', 45000),
('Mulhouse', 68100),
('Rouen', 76000),
('Caen', 14000),
('Nancy', 54000),
('Argenteuil', 95100),
('Montreuil', 93100),
('Roubaix', 59100),
('Tourcoing', 59200),
('Nanterre', 92000),
('Vitry-sur-Seine', 94400),
('Créteil', 94000),
('Dunkerque', 59140),
('Poitiers', 86000),
('Asnières-sur-Seine', 92600),
('Courbevoie', 92400),
('Versailles', 78000),
('Colmar', 68000),
('La Rochelle', 17000),
('Aubervilliers', 93300),
('Pau', 64445),
('Avignon', 84000),
('Calais', 62100),
('Antibes', 6600),
('Saint-Maur-des-Fossés', 94100),
('Chambéry', 73000),
('Niort', 79000),
('Annecy', 74000),
('Saint-Nazaire', 44600),
('Aubagne', 13400),
('Saint-Quentin', 2100),
('Mâcon', 71000),
('Châtellerault', 86100),
('Cagnes-sur-Mer', 6800),
('Chelles', 77500),
('Chartres', 28000),
('Vénissieux', 69200),
('Pessac', 33600),
('Valence', 26000),
('Ajaccio', 20000),
('Quimper', 29000),
('Villefranche-sur-Saône', 69400),
('Beauvais', 60000),
('Les Abymes', 97139),
('Baie-Mahault', 97122),
('Le Gosier', 97190),
('Sainte-Anne', 97180),
('Petit-Bourg', 97170),
('Fort-de-France', 97200),
('Le Lamentin', 97232),
('Saint-Joseph', 97212),
('Schoelcher', 97233),
('Ducos', 97224),
('Cayenne', 97300),
('Matoury', 97351),
('Saint-Laurent-du-Maroni', 97320),
('Kourou', 97310),
('Remire-Montjoly', 97354),
('Saint-Denis', 97400),
('Saint-Paul', 97460),
('Saint-Pierre', 97410),
('Le Tampon', 97430),
('Saint-André', 97440),
('Mamoudzou', 97600),
('Koungou', 97650),
('Dzaoudzi', 97615),
('Sada', 97640),
('Bandraboua', 97660);

INSERT INTO Adresses (Nom_rue, Numero_rue, Id_ville) VALUES
('Route des Séquoias', 2, 1),
       ('Rue des Fabres', 11, 2),
       ('Boulevard de Fortune', 9, 3),
       ('Rue du May', 5, 4),
       ('Avenue des Fleurs', 20, 5),
       ('Rue de Verdun', 7, 6),
       ('Rue du Maroquin', 17, 7),
       ('Rue de la Fontaine', 1, 8),
       ('Rue Saint-Rémi', 21, 9),
       ('Rue Esquermoise', 14, 10),
       ('Rue du Faubourg Saint-Antoine', 2, 1),
       ('Chemin des Noisettes', 15, 3),
       ('Rue du Musée', 6, 1),
       ('Rue du Port', 31, 7),
       ('Rue des Carmes', 12, 9),
       ('Chemin des Cerises', 10, 1),
       ('Voie des Plumes', 20, 1),
       ('Voie des Criquets', 30, 1),
       ('Avenue de Rue de Victoire', 40, 1),
       ('Chemin du Syndicat', 50, 1),
       ('Rue Saint-Ferréol', 35, 1),
       ('Rue Paradis', 45, 1),
       ('Rue des Canons', 55, 1),
       ('Rue de Lavande', 65, 1),
       ('Rue des Plumes', 75, 1),
       ('Rue de la Paix', 15, 2),
       ('Rue Royale', 25, 2),
       ('Place Vendôme', 5, 2),
       ('Rue de Clair de Lune', 10, 2),
       ('Rue Saint-Alexandre', 20, 2),
       ('Rue du Comte', 35, 3),
       ('Rue de Saphir', 45, 3),
       ('Cours Lieutaud', 55, 3),
       ('Rue de Rome', 65, 3),
       ('Rue de la République', 75, 3),
       ('Boulevard de Bois', 15, 3),
       ('Rue des Archives', 25, 3),
       ('Rue des Colombes', 35, 4),
       ('Voie du Château', 55, 4),
       ('Rue de Rivoli', 15, 4),
       ('Rue du Quai', 25, 4),
       ('Rue Saint-Antoine', 35, 4),
       ('Rue Saint-Jules', 45, 4),
       ('Rue Saint-Paul', 55, 4),
       ('Rue de Cuivre', 10, 5),
       ('Voie de Lavande', 20, 5),
       ('Rue des Vergers', 30, 5),
       ('Rue de la Rivière', 40, 5),
       ('Rue du Lac', 50, 5),
       ('Rue de la Pompe', 15, 6),
       ('Avenue Foch', 25, 6),
       ('Avenue des Ternes', 35, 6),
       ('Rue du Centre', 45, 6),
       ('Boulevard du Pégase', 55, 6),
       ('Rue du Commerce', 10, 7),
       ('Rue de Mugissement', 20, 7),
       ('Rue de Vaugirard', 30, 7),
       ('Rue Bleue', 40, 7),
       ('Rue de la Convention', 50, 7),
       ('Rue de la Nova', 15, 7),
       ('Boulevard de Vermillon', 25, 7),
       ('Avenue Montaigne', 35, 7),
       ('Rue de Tonnerre', 55, 8),
       ('Avenue des Gobelins', 15, 8),
       ('Rue Mouffetard', 25, 8),
       ('Boulevard Saint-Germain', 35, 10),
       ('Rue Saint-Jacques', 45, 10),
       ('Rue de la Huchette', 55, 10),
       ('Rue de Turbigo', 10, 9),
       ('Boulevard Saint-Denis', 20, 9),
       ('Boulevard de Sébastopol', 30, 9),
       ('Rue du Refuge', 40, 15),
       ('Rue du Forestier', 50, 15),
       ('Rue du Faubourg Saint-Honoré', 10, 15),
       ('Route de la Chapelle', 20, 78),
       ('Avenue des Champs-Élysées', 30, 85),
       ('Avenue de Friedland', 40, 86),
       ('Rue d''Aviation', 50, 93),
       ('Rue de la Boétie', 15, 99),
       ('Rue des Lilas', 12, 78),
       ('Rue de la Paix', 25, 78),
       ('Avenue des Champs-Élysées', 8, 78),
       ('Rue du Temple', 17, 85),
       ('Rue de Rivoli', 42, 85),
       ('Boulevard Saint-Germain', 73, 85),
       ('Avenue Montaigne', 21, 86),
       ('Rue Saint-Honoré', 33, 86),
       ('Boulevard Haussmann', 128, 86),
       ('Rue de la Roquette', 55, 93),
       ('Boulevard de Belleville', 78, 93),
       ('Avenue Parmentier', 29, 93),
       ('Rue de la Pompe', 12, 99),
       ('Rue de Passy', 7, 99),
       ('Boulevard Suchet', 84, 99);
	   
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Bashford', 5, 60);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Messerschmidt', 11, 4);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Northview', 27, 7);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Westerfield', 25, 20);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Melody', 19, 35);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Fairfield', 26, 80);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Carberry', 30, 60);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Ilene', 24, 31);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Bultman', 8, 46);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Fallview', 13, 28);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Sunnyside', 25, 64);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Prairieview', 15, 8);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Grayhawk', 30, 43);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Blue Bill Park', 22, 80);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Summit', 20, 23);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Vera', 22, 9);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Meadow Vale', 7, 44);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Lukken', 13, 10);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Sage', 6, 38);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Myrtle', 6, 65);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Parkside', 4, 59);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Crowley', 18, 51);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hayes', 1, 70);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Memorial', 13, 99);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hauk', 9, 75);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Truax', 30, 92);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Onsgard', 18, 32);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hermina', 10, 23);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Grayhawk', 7, 48);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Derek', 3, 64);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hintze', 28, 15);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Express', 23, 17);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Oriole', 7, 27);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Heffernan', 14, 76);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Bonner', 30, 6);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Tennyson', 22, 89);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('American', 29, 25);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Dawn', 14, 34);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hazelcrest', 14, 30);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Granby', 26, 19);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Caliangt', 13, 44);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Tennyson', 10, 92);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Esker', 15, 39);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Golf Course', 20, 48);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Golf Course', 7, 63);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Wayridge', 30, 19);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Roth', 8, 14);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Magdeline', 27, 50);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Cordelia', 15, 86);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Del Mar', 16, 20);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Caliangt', 9, 92);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Russell', 6, 84);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Becker', 22, 31);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Comanche', 24, 37);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Vernon', 3, 81);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Texas', 27, 27);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Beilfuss', 29, 56);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Fuller', 16, 64);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Paget', 25, 54);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Monument', 11, 83);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Cascade', 14, 69);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Pond', 29, 45);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Claremont', 17, 37);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Roth', 17, 79);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Mayfield', 14, 81);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Annamark', 14, 69);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Pine View', 5, 13);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Orin', 11, 94);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Knutson', 27, 65);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Pepper Wood', 27, 49);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('American', 8, 92);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Loomis', 8, 45);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Eastlawn', 5, 79);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hooker', 28, 7);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Sullivan', 3, 82);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Alpine', 27, 47);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Forest Run', 30, 60);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Jenifer', 13, 47);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Mitchell', 19, 38);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Grayhawk', 21, 96);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Melvin', 18, 25);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Myrtle', 5, 38);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Mcguire', 13, 65);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Buena Vista', 24, 25);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Northland', 15, 87);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Aberg', 6, 36);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Annamark', 8, 69);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Green', 29, 67);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hanover', 10, 48);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Vahlen', 18, 2);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Cambridge', 3, 55);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Lukken', 23, 96);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Heffernan', 14, 14);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Bowman', 23, 22);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Carpenter', 22, 94);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Drewry', 25, 70);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Gina', 16, 57);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Prairie Rose', 18, 64);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Messerschmidt', 27, 58);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Ilene', 25, 74);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Barnett', 14, 14);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Leroy', 21, 97);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hallows', 15, 25);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Ronald Regan', 26, 29);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Mcguire', 12, 47);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Toban', 30, 100);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Delladonna', 23, 96);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Fieldstone', 10, 84);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Ohio', 1, 29);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Burning Wood', 14, 57);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Garrison', 4, 88);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hintze', 30, 75);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Aberg', 2, 33);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Sutherland', 7, 51);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Vera', 6, 35);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Butternut', 21, 14);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Onsgard', 20, 29);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Lakewood Gardens', 27, 44);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Lillian', 7, 46);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Nancy', 16, 84);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Arapahoe', 2, 93);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Elgar', 30, 79);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hallows', 6, 77);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Arrowood', 17, 16);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Mendota', 23, 98);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Gerald', 15, 3);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Rockefeller', 28, 61);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Glacier Hill', 22, 79);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Lake View', 4, 40);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('1st', 30, 23);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Farwell', 14, 97);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Karstens', 22, 88);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Trailsway', 6, 58);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Dovetail', 2, 71);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Main', 13, 71);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Pennsylvania', 30, 48);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Sunnyside', 10, 52);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Packers', 4, 30);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Luster', 23, 39);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Gerald', 29, 12);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Red Cloud', 17, 40);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Arapahoe', 4, 53);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Annamark', 12, 8);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Carpenter', 1, 90);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Oriole', 29, 28);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Duke', 2, 85);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Mockingbird', 12, 67);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Hermina', 19, 66);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Fisk', 16, 27);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Shopko', 2, 75);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Green Ridge', 8, 6);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Nelson', 5, 37);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Lillian', 8, 28);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Coleman', 26, 29);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Tennyson', 9, 51);
insert into Adresses (Nom_rue, Numero_rue, Id_ville) values ('Colorado', 14, 6);

insert into Personnes (Nom, Prenom) values ('Ingleson', 'Lezlie');
insert into Personnes (Nom, Prenom) values ('Nickoll', 'Lissy');
insert into Personnes (Nom, Prenom) values ('Duxbury', 'Dot');
insert into Personnes (Nom, Prenom) values ('Semple', 'Marge');
insert into Personnes (Nom, Prenom) values ('Halworth', 'Karlotte');
insert into Personnes (Nom, Prenom) values ('McCombe', 'Leonie');
insert into Personnes (Nom, Prenom) values ('Shackelton', 'Cleo');
insert into Personnes (Nom, Prenom) values ('Bowry', 'Andriana');
insert into Personnes (Nom, Prenom) values ('Baglow', 'Rinaldo');
insert into Personnes (Nom, Prenom) values ('Bart', 'Loria');
insert into Personnes (Nom, Prenom) values ('Lathleiff', 'Jennifer');
insert into Personnes (Nom, Prenom) values ('Euesden', 'Brade');
insert into Personnes (Nom, Prenom) values ('Matous', 'Kimmie');
insert into Personnes (Nom, Prenom) values ('Worsom', 'Cosetta');
insert into Personnes (Nom, Prenom) values ('Domenichini', 'Dedie');
insert into Personnes (Nom, Prenom) values ('McGirl', 'Karly');
insert into Personnes (Nom, Prenom) values ('Davitt', 'Perrine');
insert into Personnes (Nom, Prenom) values ('Starten', 'Zelma');
insert into Personnes (Nom, Prenom) values ('Sproul', 'Arlyne');
insert into Personnes (Nom, Prenom) values ('Relton', 'Bertine');
insert into Personnes (Nom, Prenom) values ('Saffell', 'Dorthy');
insert into Personnes (Nom, Prenom) values ('Hindrick', 'Abagail');
insert into Personnes (Nom, Prenom) values ('Ettritch', 'Barry');
insert into Personnes (Nom, Prenom) values ('Colebrook', 'Esther');
insert into Personnes (Nom, Prenom) values ('Arlow', 'Merrili');
insert into Personnes (Nom, Prenom) values ('Midghall', 'Rheba');
insert into Personnes (Nom, Prenom) values ('Weller', 'Doria');
insert into Personnes (Nom, Prenom) values ('Godson', 'Giovanni');
insert into Personnes (Nom, Prenom) values ('Manford', 'Clemmy');
insert into Personnes (Nom, Prenom) values ('Nockles', 'Cristionna');
insert into Personnes (Nom, Prenom) values ('Franzelini', 'Farand');
insert into Personnes (Nom, Prenom) values ('Wikey', 'Sigismondo');
insert into Personnes (Nom, Prenom) values ('Grimestone', 'Rakel');
insert into Personnes (Nom, Prenom) values ('Ipgrave', 'Zorah');
insert into Personnes (Nom, Prenom) values ('Ebbett', 'Ara');
insert into Personnes (Nom, Prenom) values ('Troke', 'Rouvin');
insert into Personnes (Nom, Prenom) values ('Dack', 'Elianore');
insert into Personnes (Nom, Prenom) values ('Kingsley', 'Diane');
insert into Personnes (Nom, Prenom) values ('McCrackan', 'Rosamund');
insert into Personnes (Nom, Prenom) values ('Cranham', 'Kenton');
insert into Personnes (Nom, Prenom) values ('Luciani', 'Larina');
insert into Personnes (Nom, Prenom) values ('Morrison', 'Bendick');
insert into Personnes (Nom, Prenom) values ('Regenhardt', 'Ddene');
insert into Personnes (Nom, Prenom) values ('Perryman', 'Corly');
insert into Personnes (Nom, Prenom) values ('Nolin', 'Graehme');
insert into Personnes (Nom, Prenom) values ('Grisard', 'Joell');
insert into Personnes (Nom, Prenom) values ('Pirnie', 'Lorine');
insert into Personnes (Nom, Prenom) values ('Halfacree', 'Duane');
insert into Personnes (Nom, Prenom) values ('Kuhlen', 'Doy');
insert into Personnes (Nom, Prenom) values ('Aaronson', 'Maryrose');
insert into Personnes (Nom, Prenom) values ('Scarff', 'Lou');
insert into Personnes (Nom, Prenom) values ('Kahen', 'Karmen');
insert into Personnes (Nom, Prenom) values ('Eustace', 'Barth');
insert into Personnes (Nom, Prenom) values ('Fuente', 'Vicki');
insert into Personnes (Nom, Prenom) values ('Scriviner', 'Kippie');
insert into Personnes (Nom, Prenom) values ('Halson', 'Anya');
insert into Personnes (Nom, Prenom) values ('Salvidge', 'Hodge');
insert into Personnes (Nom, Prenom) values ('Pakenham', 'Vinson');
insert into Personnes (Nom, Prenom) values ('Whittlesee', 'Tybie');
insert into Personnes (Nom, Prenom) values ('Buchan', 'Rossy');
insert into Personnes (Nom, Prenom) values ('de Werk', 'Regan');
insert into Personnes (Nom, Prenom) values ('Midlar', 'Petronia');
insert into Personnes (Nom, Prenom) values ('Hirjak', 'Bay');
insert into Personnes (Nom, Prenom) values ('Meriott', 'Lombard');
insert into Personnes (Nom, Prenom) values ('Gallelli', 'Agnese');
insert into Personnes (Nom, Prenom) values ('Bizley', 'Yoko');
insert into Personnes (Nom, Prenom) values ('Loche', 'Faye');
insert into Personnes (Nom, Prenom) values ('Tomanek', 'Cherey');
insert into Personnes (Nom, Prenom) values ('Kilrow', 'Emmalee');
insert into Personnes (Nom, Prenom) values ('Pittle', 'Raye');
insert into Personnes (Nom, Prenom) values ('Kempston', 'Amalle');
insert into Personnes (Nom, Prenom) values ('Kettridge', 'Leah');
insert into Personnes (Nom, Prenom) values ('Leet', 'Ara');
insert into Personnes (Nom, Prenom) values ('MacLachlan', 'Witty');
insert into Personnes (Nom, Prenom) values ('Vivyan', 'Codi');
insert into Personnes (Nom, Prenom) values ('Ordelt', 'Lyon');
insert into Personnes (Nom, Prenom) values ('Pugh', 'Kendricks');
insert into Personnes (Nom, Prenom) values ('Mulliss', 'Teodorico');
insert into Personnes (Nom, Prenom) values ('Burtwhistle', 'Miller');
insert into Personnes (Nom, Prenom) values ('Barkhouse', 'Tonie');
insert into Personnes (Nom, Prenom) values ('Grayer', 'Brendon');
insert into Personnes (Nom, Prenom) values ('Prendergrast', 'Rivkah');
insert into Personnes (Nom, Prenom) values ('Golton', 'Arlette');
insert into Personnes (Nom, Prenom) values ('Traves', 'Padraig');
insert into Personnes (Nom, Prenom) values ('Woodhams', 'Conan');
insert into Personnes (Nom, Prenom) values ('Alner', 'Blane');
insert into Personnes (Nom, Prenom) values ('Allderidge', 'Adrianne');
insert into Personnes (Nom, Prenom) values ('Kienl', 'Maureene');
insert into Personnes (Nom, Prenom) values ('Hadgkiss', 'Worth');
insert into Personnes (Nom, Prenom) values ('Roper', 'Jermaine');
insert into Personnes (Nom, Prenom) values ('Warman', 'Gayle');
insert into Personnes (Nom, Prenom) values ('Berre', 'Derril');
insert into Personnes (Nom, Prenom) values ('Eliassen', 'Dilan');
insert into Personnes (Nom, Prenom) values ('Isacsson', 'Linea');
insert into Personnes (Nom, Prenom) values ('Ritchley', 'Darryl');
insert into Personnes (Nom, Prenom) values ('Morter', 'Ferdinand');
insert into Personnes (Nom, Prenom) values ('Frankland', 'Lonna');
insert into Personnes (Nom, Prenom) values ('Pilgram', 'Gonzalo');
insert into Personnes (Nom, Prenom) values ('McGennis', 'Trixie');
insert into Personnes (Nom, Prenom) values ('Leafe', 'Minna');
insert into Personnes (Nom, Prenom) values ('Gerty', 'Abrahan');
insert into Personnes (Nom, Prenom) values ('McQuaide', 'Norene');
insert into Personnes (Nom, Prenom) values ('Methven', 'Brett');
insert into Personnes (Nom, Prenom) values ('Golightly', 'Rudie');
insert into Personnes (Nom, Prenom) values ('Ledgard', 'Astrix');
insert into Personnes (Nom, Prenom) values ('Phillins', 'Jillie');
insert into Personnes (Nom, Prenom) values ('MacGown', 'Oliver');
insert into Personnes (Nom, Prenom) values ('Lindholm', 'Fergus');
insert into Personnes (Nom, Prenom) values ('Barbe', 'Jens');
insert into Personnes (Nom, Prenom) values ('Veryan', 'Mehetabel');
insert into Personnes (Nom, Prenom) values ('Patey', 'Berti');
insert into Personnes (Nom, Prenom) values ('Farfoot', 'Ailyn');
insert into Personnes (Nom, Prenom) values ('McGiffin', 'Clarissa');
insert into Personnes (Nom, Prenom) values ('Bummfrey', 'Viviene');
insert into Personnes (Nom, Prenom) values ('Hatt', 'Luce');
insert into Personnes (Nom, Prenom) values ('Bridger', 'Wendeline');
insert into Personnes (Nom, Prenom) values ('Count', 'Francoise');
insert into Personnes (Nom, Prenom) values ('Baldacchino', 'Else');
insert into Personnes (Nom, Prenom) values ('Redsall', 'Carola');
insert into Personnes (Nom, Prenom) values ('Keelan', 'Adorne');
insert into Personnes (Nom, Prenom) values ('de Almeida', 'Phylis');
insert into Personnes (Nom, Prenom) values ('Laurentino', 'Lamont');
insert into Personnes (Nom, Prenom) values ('Felmingham', 'Berke');
insert into Personnes (Nom, Prenom) values ('Girke', 'Anne-marie');
insert into Personnes (Nom, Prenom) values ('Volonte', 'Abeu');
insert into Personnes (Nom, Prenom) values ('De Cruze', 'Axe');
insert into Personnes (Nom, Prenom) values ('Bowling', 'Marshal');
insert into Personnes (Nom, Prenom) values ('McTavy', 'Felizio');
insert into Personnes (Nom, Prenom) values ('Calbaithe', 'Lawrence');
insert into Personnes (Nom, Prenom) values ('Bothram', 'Ashton');
insert into Personnes (Nom, Prenom) values ('Taunton.', 'Lillis');
insert into Personnes (Nom, Prenom) values ('Bendon', 'Barri');
insert into Personnes (Nom, Prenom) values ('Wenzel', 'Micheline');
insert into Personnes (Nom, Prenom) values ('Saunton', 'Gran');
insert into Personnes (Nom, Prenom) values ('Coster', 'Mychal');
insert into Personnes (Nom, Prenom) values ('Dunnaway', 'Lindsay');
insert into Personnes (Nom, Prenom) values ('Teeney', 'Jeromy');
insert into Personnes (Nom, Prenom) values ('Wildin', 'Lurette');
insert into Personnes (Nom, Prenom) values ('Bixley', 'Iolanthe');
insert into Personnes (Nom, Prenom) values ('Grichukhin', 'Nikolaus');
insert into Personnes (Nom, Prenom) values ('Capelle', 'Saunderson');
insert into Personnes (Nom, Prenom) values ('Lafay', 'Rochelle');
insert into Personnes (Nom, Prenom) values ('Jone', 'Van');
insert into Personnes (Nom, Prenom) values ('Earingey', 'Blithe');
insert into Personnes (Nom, Prenom) values ('Dauber', 'Denis');
insert into Personnes (Nom, Prenom) values ('Colbridge', 'Alix');
insert into Personnes (Nom, Prenom) values ('Wisniewski', 'Rebeka');
insert into Personnes (Nom, Prenom) values ('Jaime', 'Rhea');
insert into Personnes (Nom, Prenom) values ('Sail', 'Katalin');
insert into Personnes (Nom, Prenom) values ('Varrow', 'Cobby');

INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (1, '2020-05-18', 1, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (2, '2019-11-29', 2, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (3, '2015-12-30', 3, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (4, '2020-06-20', 4, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (5, '2018-09-10', 5, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (6, '2019-12-29', 6, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (7, '2018-02-12', 7, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (8, '2018-11-06', 8, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (9, '2022-08-19', 9, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (10, '2023-03-07', 10, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (11, '2016-10-07', 11, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (12, '2023-08-02', 12, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (13, '2020-04-9', 13, NULL);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (14, '2017-7-09', 14, 1);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (15, '2021-5-17', 15, 1);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (16, '2017-04-13', 16, 1);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (17, '2015-09-13', 17, 2);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (18, '2016-6-20', 18, 2);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (19, '2019-03-09', 19, 2);
insert into Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (20, '2020-06-21', 20, 3);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (21, '2017-02-07', 21, 3);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (22, '2022-05-22', 22, 3);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (23, '2019-5-06', 23, 4);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (24, '2015-5-31', 24, 4);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (25, '2017-07-20', 25, 4);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (26, '2019-06-04', 26, 5);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (27, '2020-02-26', 27, 5);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (28, '2023-09-6', 28, 5);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (29, '2015-06-08', 29, 6);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (30, '2019-7-8', 30, 6);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (31, '2021-07-27', 31, 6);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (32, '2019-08-08', 32, 7);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (33, '2022-01-13', 33, 7);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (34, '2018-04-23', 34, 7);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (35, '2017-6-01', 35, 8);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (36, '2021-03-18', 36, 8);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (37, '2019-02-9', 37, 8);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (38, '2016-07-02', 38, 9);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (39, '2018-05-09', 39, 9);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (40, '2020-09-27', 40, 9);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (41, '2017-04-6', 41, 10);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (42, '2022-07-9', 42, 10);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (43, '2019-08-03', 43, 10);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (44, '2016-7-20', 44, 11);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (45, '2018-01-25', 45, 11);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (46, '2018-08-13', 46, 11);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (47, '2016-02-27', 47, 12);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (48, '2023-09-02', 48, 12);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (49, '2019-08-17', 49, 12);
INSERT INTO Personnels (Id_personnel, Date_embauche, Id_adresse, Id_superieur) VALUES (50, '2019-04-07', 50, 13);

insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (51, '1984-04-22', '2022-05-02', 51, 52); 
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (52, '1995-09-20', '2017-08-20', 53, 54);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (53, '1984-02-12', '2020-12-04', 55, 56);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (54, '1994-09-13', '2022-11-26', 57, 58);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (55, '1998-12-28', '2018-06-13', 59, 60);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (56, '1987-12-11', '2023-05-03', 61, 62);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (57, '1993-07-25', '2021-05-19', 63, 64);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (58, '2003-01-29', '2021-04-21', 65, 66);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (59, '1998-12-09', '2015-09-17', 67, 68);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (60, '1998-05-29', '2022-10-12', 69, 70);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (61, '2001-10-14', '2015-12-04', 71, 72);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (62, '1987-09-21', '2019-02-18', 73, 74);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (63, '1998-04-02', '2020-05-02', 75, 76);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (64, '1983-05-30', '2015-08-30', 77, 78);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (65, '1995-11-30', '2015-12-06', 79, 80);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (66, '1993-06-27', NULL, 81, 82);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (67, '1991-05-06', NULL, 83, 84);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (68, '1982-01-13', NULL, 85, 86);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (69, '1995-03-01', NULL, 87, 88);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (70, '1989-08-14', NULL, 89, 90);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (71, '2003-07-23', NULL, 91, 92);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (72, '1987-10-23', NULL, 93, 94);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (73, '1994-08-16', NULL, 95, 96);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (74, '1986-12-03', NULL, 97, 98);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (75, '1982-01-26', NULL, 99, 100);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (76, '1998-10-14', NULL, 101, 102);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (77, '1988-08-10', NULL, 103, 104);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (78, '1995-12-25', NULL, 105, 106);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (79, '1980-06-20', NULL, 107, 108);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (80, '1988-08-05', NULL, 109, 110);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (81, '1998-12-01', NULL, 111, 112);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (82, '1993-04-24', NULL, 113, 114);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (83, '2000-07-11', NULL, 115, 116);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (84, '1997-04-15', NULL, 117, 118);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (85, '2003-06-07', NULL, 119, 120);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (86, '1992-12-09', NULL, 121, 122);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (87, '2001-05-19', NULL, 123, 124);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (88, '1983-02-24', NULL, 125, 126);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (89, '1984-03-11', NULL, 127, 128);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (90, '1981-08-16', NULL, 129, 130);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (91, '1984-03-05', NULL, 131, 132);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (92, '2002-05-05', NULL, 133, 134);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (93, '1985-02-09', NULL, 135, 136);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (94, '1994-02-23', NULL, 137, 138);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (95, '1984-11-06', NULL, 139, 140);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (96, '1984-02-21', NULL, 141, 142);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (97, '1997-11-21', NULL, 143, 144);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (98, '1985-07-29', NULL, 145, 146);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (99, '1980-12-28', NULL, 147, 148);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (100, '1984-11-28', NULL, 149, 150);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (101, '1989-05-15', NULL, 151, 152);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (102, '1993-01-10', NULL, 153, 154);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (103, '1988-06-11', NULL, 155, 156);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (104, '1984-07-05', NULL, 157, 158);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (105, '1992-01-19', NULL, 159, 160);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (106, '1996-06-22', NULL, 161, 162);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (107, '2001-06-19', NULL, 163, 164);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (108, '1984-11-20', NULL, 165, 166);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (109, '1995-05-12', NULL, 167, 168);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (110, '1994-09-11', NULL, 169, 170);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (111, '1995-02-19', NULL, 171, 172);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (112, '1986-11-05', NULL, 173, 174);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (113, '1999-09-06', NULL, 175, 176);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (114, '2003-01-18', NULL, 177, 178);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (115, '1990-11-24', NULL, 179, 180);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (116, '1998-10-20', NULL, 181, 182);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (117, '1984-04-22', NULL, 183, 184);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (118, '1986-07-23', NULL, 185, 186);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (119, '1987-10-31', NULL, 187, 188);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (120, '1987-08-05', NULL, 189, 190);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (121, '1999-04-15', NULL, 191, 192);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (122, '1990-10-18', NULL, 193, 194);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (123, '1988-11-08', NULL, 195, 196);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (124, '1983-11-26', NULL, 197, 198);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (125, '1982-04-18', NULL, 199, 200);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (126, '1982-03-08', NULL, 201, 202);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (127, '1995-09-28', NULL, 203, 204);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (128, '1999-09-16', NULL, 205, 206);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (129, '1989-04-13', NULL, 207, 208);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (130, '1991-12-21', NULL, 209, 210);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (131, '1997-11-20', NULL, 211, 212);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (132, '1995-12-22', NULL, 213, 214);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (133, '1992-07-11', NULL, 215, 216);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (134, '1986-02-23', NULL, 217, 218);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (135, '2001-06-11', NULL, 219, 220);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (136, '1998-11-05', NULL, 221, 222);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (137, '2001-08-08', NULL, 223, 224);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (138, '1995-07-21', NULL, 225, 226);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (139, '1996-07-01', NULL, 227, 228);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (140, '1983-04-09', NULL, 229, 230);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (141, '1993-01-09', NULL, 231, 232);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (142, '1985-03-31', NULL, 233, 234);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (143, '1984-05-01', NULL, 235, 236);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (144, '1999-12-19', NULL, 237, 238);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (145, '1988-01-19', NULL, 239, 240);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (146, '1995-05-07', NULL, 241, 242);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (147, '1998-06-21', NULL, 243, 244);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (148, '2003-01-29', NULL, 245, 246);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (149, '2000-01-26', NULL, 247, 248);
insert into Clients (Id_client, Date_naissance, Date_premier_achat, Id_adresse_livraison, Id_adresse_facturation) values (150, '1997-09-08', NULL, 249, 250);

INSERT INTO Articles (Reference_article, Nom_article, Prix_article_HT, Nature_article, Couleur_article, Seuil_reapprovisionnement, Quantite_article, Pourcentage_taxe)
VALUES
    ('REF001', 'Chemise en coton', 49.99, 'Vêtement', 'Blanc', 20, 50, 20),
    ('REF002', 'Ordinateur portable', 899.99, 'Électronique', 'Argent', 10, 30, 20),
    ('REF003', 'Chaussures de course', 79.95, 'Chaussures', 'Bleu', 15, 40, 20),
    ('REF004', 'Lampe de bureau LED', 34.50, 'Éclairage', 'Noir', 25, 15, 20),
    ('REF005', 'Sac à dos en cuir', 129.99, 'Accessoire', 'Marron', 30, 25, 20),
    ('REF006', 'Canapé en cuir', 899.00, 'Mobilier', 'Gris', 5, 10, 20),
    ('REF007', 'Montre-bracelet élégante', 149.95, 'Accessoire', 'Or', 8, 20, 20),
    ('REF008', 'Machine à café automatique', 249.99, 'Électroménager', 'Noir', 12, 30, 20),
    ('REF009', 'Enceinte Bluetooth', 79.99, 'Audio', 'Rouge', 18, 15, 20),
    ('REF010', 'Téléviseur 4K', 1299.00, 'Électronique', 'Noir', 10, 5, 20),
    ('REF011', 'Livre de cuisine', 19.95, 'Livre', 'Multicolore', 25, 50, 20),
    ('REF012', 'Vélo de montagne', 499.99, 'Sport', 'Vert', 15, 8, 20),
    ('REF013', 'Robe de soirée', 129.50, 'Vêtement', 'Rouge', 20, 20, 20),
    ('REF014', 'Aspirateur robot', 179.00, 'Électroménager', 'Blanc', 10, 15, 20),
    ('REF015', 'Tablette graphique', 199.95, 'Électronique', 'Noir', 30, 12, 20),
    ('REF016', 'Tapis de yoga', 29.99, 'Sport', 'Bleu', 25, 30, 20),
    ('REF017', 'Guitare acoustique', 299.00, 'Musique', 'Naturel', 8, 18, 20),
    ('REF018', 'Tondeuse à gazon', 129.99, 'Jardin', 'Rouge', 12, 22, 20),
    ('REF019', 'Casserole en acier inoxydable', 39.95, 'Cuisine', 'Argent', 15, 40, 20),
    ('REF020', 'Sac de voyage', 59.99, 'Accessoire', 'Bleu', 20, 25, 20),
    ('REF021', 'Casque audio sans fil', 89.99, 'Audio', 'Noir', 18, 15, 20),
    ('REF022', 'Bouteille d''eau réutilisable', 12.50, 'Accessoire', 'Vert', 30, 50, 20),
    ('REF023', 'Chaise de bureau ergonomique', 149.00, 'Mobilier', 'Noir', 10, 10, 20),
    ('REF024', 'Jeans déchirés', 59.95, 'Vêtement', 'Bleu', 25, 30, 20),
    ('REF025', 'Enceinte intelligente', 129.99, 'Audio', 'Blanc', 15, 20, 20),
    ('REF026', 'Bouilloire électrique', 24.99, 'Cuisine', 'Inox', 20, 35, 20),
    ('REF027', 'Sac à main en cuir', 79.50, 'Accessoire', 'Rose', 25, 18, 20),
    ('REF028', 'Tapis de souris ergonomique', 14.99, 'Informatique', 'Noir', 15, 40, 20),
    ('REF029', 'Casquette de baseball', 19.95, 'Accessoire', 'Rouge', 12, 50, 20),
    ('REF030', 'Haut-parleur portable', 59.99, 'Audio', 'Bleu', 30, 15, 20),
    ('REF031', 'Chaise pliante', 29.50, 'Mobilier', 'Vert', 20, 25, 20),
    ('REF032', 'Horloge murale', 39.99, 'Décoration', 'Noir', 18, 20, 20),
    ('REF033', 'Serviette de bain en coton', 9.95, 'Linge de maison', 'Blanc', 40, 50, 20),
    ('REF034', 'Pantalon de yoga', 34.99, 'Vêtement', 'Gris', 15, 30, 20),
    ('REF035', 'Parapluie pliant', 14.50, 'Accessoire', 'Bleu', 25, 10, 20),
    ('REF036', 'Étagère murale', 49.99, 'Mobilier', 'Bois', 12, 15, 20),
    ('REF037', 'Théière en fonte', 79.95, 'Cuisine', 'Noir', 10, 20, 20),
    ('REF038', 'Puzzle 1000 pièces', 19.99, 'Jeux', 'Multicolore', 30, 8, 20),
    ('REF039', 'Cadre photo en argent', 29.50, 'Décoration', 'Argent', 20, 12, 20),
    ('REF040', 'Brosse à dents électrique', 39.99, 'Soin personnel', 'Blanc', 15, 30, 20),
    ('REF041', 'Vernis à ongles', 8.99, 'Soin personnel', 'Rose', 25, 25, 20),
    ('REF042', 'Pèse-personne électronique', 29.95, 'Soin personnel', 'Vert', 37, 49, 20),
	('REF043', 'Plante d''intérieur', 24.99, 'Décoration', 'Vert', 18, 10, 20),
    ('REF044', 'Miroir mural', 59.50, 'Décoration', 'Argent', 15, 15, 20),
    ('REF045', 'Cafetière à piston', 34.95, 'Cuisine', 'Inox', 20, 20, 20),
    ('REF046', 'Sacoche pour ordinateur portable', 49.99, 'Accessoire', 'Noir', 25, 18, 20),
    ('REF047', 'Plateau de service en bambou', 19.99, 'Cuisine', 'Naturel', 12, 25, 20),
    ('REF048', 'Coussin décoratif', 14.50, 'Décoration', 'Bleu', 30, 30, 20),
    ('REF049', 'Câble de charge USB-C', 9.95, 'Accessoire', 'Gris', 25, 40, 20),
    ('REF050', 'Carafe en verre', 22.99, 'Cuisine', 'Transparent', 18, 22, 20);

INSERT INTO Commandes (Reference_commande, Date_livraison, Date_emission, Moyen_paiement, Date_paiement, Pourcentage_remise, Id_client)
VALUES ('LOSC2022NAN1', '2023-05-09', '2023-05-05', 'Cash', '2022-05-02', 0, 51),
       ('KAKA2017NAN2', '2017-08-27', '2017-08-23', 'Carte', '2017-08-20', 0, 52),
       ('BAEU2020STR3', '2021-12-08', '2021-12-04', 'Carte', '2020-12-04', 0, 53),
       ('VIFU2022STR4', '2022-11-30', '2022-11-26', 'Carte', '2022-11-26', 0, 54),
       ('KISC2018STR5', '2018-06-20', '2018-06-16', 'Cash', '2018-06-13', 0, 55),
       ('ANHA2023STR6', '2023-05-10', '2023-05-06', 'Bitcoin', '2023-05-03', 0, 56),
       ('HOSA2021MON7', '2021-05-24', '2021-05-21', 'Bitcoin', '2021-05-19', 0, 57),
       ('VIPA2021MON8', '2021-04-28', '2021-04-24', 'Paypal', '2021-04-21', 0, 58),
       ('TYWH2015LIL9', '2015-09-24', '2015-09-20', 'Paypal', '2015-09-17', 0, 59),
       ('ROBU2022BOR10', '2022-10-16', '2022-10-12', 'Paypal', '2022-10-12', 0, 60),
       ('REDE2015BOR11', '2015-12-11', '2015-12-07', 'Cash', '2015-12-04', 0, 61),
       ('PEMI2019TOU12', '2019-02-25', '2019-02-21', 'Paypal', '2019-02-18', 0, 62),
       ('BAHI2020LEG13', '2020-05-05', '2020-05-01', 'Bitcoin', '2020-05-02', 0, 63),
       ('LOME2015CAY14', '2015-09-05', '2015-09-01', 'Carte', '2015-08-30', 0, 64),
       ('AGGA2015SAD15', '2015-12-09', '2015-12-05', 'Bitcoin', '2015-12-06', 0, 65);

INSERT INTO constituer (Reference_commande, Reference_article, Quantite_article_commande, Pourcentage_remise_article)
VALUES
    ('LOSC2022NAN1', 'REF001', 3, 0),
    ('LOSC2022NAN1', 'REF002', 5, 0),
    ('LOSC2022NAN1', 'REF003', 2, 0),
    ('KAKA2017NAN2', 'REF004', 1, 0),
    ('KAKA2017NAN2', 'REF005', 4, 0),
    ('KAKA2017NAN2', 'REF006', 2, 0),
    ('BAEU2020STR3', 'REF007', 3, 0),
    ('BAEU2020STR3', 'REF008', 2, 0),
    ('BAEU2020STR3', 'REF009', 1, 0),
    ('VIFU2022STR4', 'REF010', 1, 0),
    ('VIFU2022STR4', 'REF011', 2, 0),
    ('VIFU2022STR4', 'REF012', 4, 0),
    ('KISC2018STR5', 'REF013', 2, 0),
    ('KISC2018STR5', 'REF014', 1, 0),
    ('KISC2018STR5', 'REF015', 3, 0),
    ('ANHA2023STR6', 'REF016', 5, 0),
    ('ANHA2023STR6', 'REF017', 2, 0),
    ('ANHA2023STR6', 'REF018', 1, 0),
    ('HOSA2021MON7', 'REF019', 3, 0),
    ('HOSA2021MON7', 'REF020', 2, 0),
    ('HOSA2021MON7', 'REF021', 1, 0),
    ('VIPA2021MON8', 'REF043', 2, 0),
    ('VIPA2021MON8', 'REF044', 1, 0),
    ('VIPA2021MON8', 'REF045', 4, 0),
    ('TYWH2015LIL9', 'REF022', 4, 0),
    ('TYWH2015LIL9', 'REF023', 2, 0),
    ('TYWH2015LIL9', 'REF024', 1, 0),
    ('ROBU2022BOR10', 'REF025', 3, 0),
    ('ROBU2022BOR10', 'REF026', 2, 0),
    ('ROBU2022BOR10', 'REF027', 1, 0),
    ('REDE2015BOR11', 'REF028', 2, 0),
    ('REDE2015BOR11', 'REF029', 3, 0),
    ('REDE2015BOR11', 'REF030', 1, 0),
    ('PEMI2019TOU12', 'REF031', 1, 0),
    ('PEMI2019TOU12', 'REF032', 4, 0),
    ('PEMI2019TOU12', 'REF033', 2, 0),
    ('BAHI2020LEG13', 'REF034', 3, 0),
    ('BAHI2020LEG13', 'REF035', 1, 0),
    ('BAHI2020LEG13', 'REF036', 2, 0),
    ('LOME2015CAY14', 'REF037', 2, 0),
    ('LOME2015CAY14', 'REF038', 5, 0),
    ('LOME2015CAY14', 'REF039', 1, 0),
    ('AGGA2015SAD15', 'REF040', 3, 0),
    ('AGGA2015SAD15', 'REF041', 2, 0),
    ('AGGA2015SAD15', 'REF042', 1, 0);

