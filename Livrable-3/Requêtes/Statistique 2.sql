DECLARE @Mois DATE = '2023-05-01';

SELECT
    CAST(ROUND(SUM(TotalPrix), 2) AS float) AS ChiffreAffaires
FROM (
    SELECT
        SUM((a.Prix_article_HT * (1 - CAST(co.Pourcentage_remise_article AS DECIMAL(2)) / 100)) 
		* co.Quantite_article_commande)
        * (1 - CAST(c.Pourcentage_remise / 100 AS DECIMAL(2))) AS TotalPrix
    FROM 
        [Projet].[dbo].[Commandes] c
        INNER JOIN [Projet].[dbo].[constituer] co ON c.Reference_commande = co.Reference_commande
        INNER JOIN [Projet].[dbo].[Articles] a ON co.Reference_article = a.Reference_article
    WHERE
        MONTH(c.Date_paiement) = MONTH(@Mois) AND YEAR(c.Date_paiement) = YEAR(@Mois)
    GROUP BY 
        c.Reference_commande, c.Pourcentage_remise
) AS ChiffreAffairesMois;
