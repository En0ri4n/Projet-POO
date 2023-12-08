SELECT 
    CAST(ROUND(SUM(a.Prix_article_HT * (1 + CAST(a.Pourcentage_taxe AS DECIMAL(2)) / 100) *
	a.Quantite_article), 2) AS float) AS ValeurAchatDuStock
FROM 
    [Projet].[dbo].[Articles] a;
