SELECT TOP 10
    a.Reference_article,
    a.Nom_article,
    COALESCE(SUM(co.Quantite_article_commande), 0) AS QuantiteVendue
FROM 
    [Projet].[dbo].[Articles] a
    LEFT JOIN [Projet].[dbo].[constituer] co ON a.Reference_article = co.Reference_article 
GROUP BY
    a.Reference_article, a.Nom_article
ORDER BY	
    QuantiteVendue DESC,
	a.Nom_article ASC;
