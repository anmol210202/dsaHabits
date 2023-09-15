# Write your MySQL query statement below
SELECT P.PRODUCT_NAME , S.YEAR , S.PRICE 
FROM SALES S
INNER JOIN PRODUCT P
ON P.PRODUCT_ID = S.PRODUCT_ID

# SELECT P.product_name, S.year, S.price
# FROM Sales S
# JOIN Product P ON S.product_id = P.product_id;

