CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT MAX(SecondHighestSalary) AS SecondHighestSalary
FROM (
    SELECT salary AS SecondHighestSalary,
           DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
) ranked
WHERE rnk = N

  );
END