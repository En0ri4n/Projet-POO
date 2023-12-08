SELECT 
    SUM(a.Prix_article_HT * a.Quantite_article) AS ValeurCommercialeDuStock
FROM 
    [Projet].[dbo].[Articles] a;