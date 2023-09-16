SELECT w2.id
# FROM Weather w1 , Weather w2
# WHERE DATEDIFF(w1.recordDate , w2.recordDate) = 1 AND w1.temperature > w2.temperature;

FROM Weather w1
JOIN Weather w2
ON DATEDIFF (w2.recordDate , w1.recordDate) = 1 and w2.temperature > w1.temperature
