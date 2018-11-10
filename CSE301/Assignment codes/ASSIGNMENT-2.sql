-- 2.A.
SELECT CUSTOMER.CUSTOMER_NAME, CUSTOMER.CUSTOMER_STREET, CUSTOMER.CUSTOMER_CITY
                                                FROM CUSTOMER, BORROWER, LOAN, BRANCH
                                                WHERE CUSTOMER.CUSTOMER_NAME = BORROWER.CUSTOMER_NAME
                                                AND BORROWER.LOAN_NUMBER = LOAN.LOAN_NUMBER
                                                AND LOAN.BRANCH_NAME = BRANCH.BRANCH_NAME
                                                AND CUSTOMER.CUSTOMER_CITY = BRANCH.BRANCH_CITY;
                                                
-- 2.B.
SELECT * FROM CUSTOMER WHERE (CUSTOMER_NAME, CUSTOMER_CITY) IN (SELECT CUSTOMER_NAME, BRANCH_CITY
                                                                FROM BRANCH NATURAL JOIN LOAN NATURAL JOIN BORROWER);

--4.A
WITH BRANCH_LOAN(BRANCH_CITY, TOTAL_LOAN) AS (
                    SELECT BRANCH.BRANCH_CITY, AVG(LOAN.AMOUNT)
                    FROM BRANCH, LOAN 
                    WHERE BRANCH.BRANCH_NAME = LOAN.BRANCH_NAME                                                              
                    GROUP BY BRANCH.BRANCH_CITY )
                            SELECT * FROM BRANCH_LOAN WHERE TOTAL_LOAN>1500;
                            
--4.B
SELECT BRANCH_CITY, AVG(AMOUNT) TOTAL_LOAN FROM BRANCH JOIN LOAN USING (BRANCH_NAME)
        GROUP BY BRANCH_CITY
        HAVING AVG(AMOUNT)>1500;
        
--6.A.
SELECT CUSTOMER.CUSTOMER_NAME, CUSTOMER.CUSTOMER_STREET, CUSTOMER.CUSTOMER_CITY FROM CUSTOMER, BORROWER, LOAN
                                                              WHERE CUSTOMER.CUSTOMER_NAME = BORROWER.CUSTOMER_NAME
                                                              AND BORROWER.LOAN_NUMBER = LOAN.LOAN_NUMBER
                                                              AND LOAN.AMOUNT IN (SELECT MIN(AMOUNT) FROM LOAN);
--6.B
SELECT * FROM CUSTOMER CM WHERE EXISTS(SELECT CUSTOMER_NAME FROM (SELECT CUSTOMER_NAME, LOAN_NUMBER, AMOUNT  
                                                                    FROM BORROWER NATURAL JOIN LOAN
                                                                    WHERE AMOUNT IN(SELECT MIN(AMOUNT) FROM LOAN)) MIN_LOAN_TBL
                                                              WHERE MIN_LOAN_TBL.CUSTOMER_NAME = CM.CUSTOMER_NAME
                                                                    );
                                                                    
                                                                    
--8.A
SELECT DISTINCT CUSTOMER_NAME, CUSTOMER_CITY FROM CUSTOMER NATURAL JOIN DEPOSITOR
                                             WHERE CUSTOMER_NAME NOT IN(SELECT CUSTOMER_NAME FROM BORROWER);
--8.B
SELECT DISTINCT CM_ACC.CUSTOMER_NAME, CM_ACC.CUSTOMER_CITY 
FROM (SELECT CUSTOMER_NAME, CUSTOMER_CITY FROM CUSTOMER  NATURAL JOIN DEPOSITOR) CM_ACC 
      WHERE NOT EXISTS(SELECT CUSTOMER_NAME
                       FROM BORROWER BR
                       WHERE BR.CUSTOMER_NAME = CM_ACC.CUSTOMER_NAME );
                       
--10.A
WITH SUM_LOAN(BRANCH_NAME, SUM_AMOUNT) AS(
            SELECT BRANCH_NAME, SUM(AMOUNT) FROM LOAN
            GROUP BY BRANCH_NAME)
    SELECT BRANCH_NAME FROM SUM_LOAN
    WHERE SUM_AMOUNT < (SELECT AVG(SUM_AMOUNT) FROM SUM_LOAN);
        
--10.B
SELECT BRANCH_NAME FROM LOAN
GROUP BY BRANCH_NAME
HAVING SUM(AMOUNT)< ALL(SELECT AVG(SUM(AMOUNT)) FROM LOAN
GROUP BY BRANCH_NAME);
                                                                           
                                                                    
                                                                  