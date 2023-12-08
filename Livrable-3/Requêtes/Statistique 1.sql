SELECT CAST(ROUND(AVG(PanierMoyenApresRemise), 2) AS float) AS PanierMoyen
FROM (
    SELECT 
        SUM((a.Prix_article_HT * (1 + CAST(a.Pourcentage_taxe AS DECIMAL(2)) / 100) 
            * (1 - CAST(co.Pourcentage_remise_article AS DECIMAL(2)) / 100)) * co.Quantite_article_commande)
            * (1 - CAST(c.Pourcentage_remise AS DECIMAL(2)) / 100) AS PanierMoyenApresRemise
    FROM 
        [Projet].[dbo].[Commandes] c
        INNER JOIN [Projet].[dbo].[constituer] co ON c.Reference_commande = co.Reference_commande
        INNER JOIN [Projet].[dbo].[Articles] a ON co.Reference_article = a.Reference_article
    GROUP BY 
        co.Reference_commande, c.Pourcentage_remise
) AS Paniers;
