SELECT product_id
FROM Products as p
WHERE p.low_fats='Y' and p.recyclable='Y';

/*
-- Create table with the equivalent of ENUM in PostgreSQL
CREATE TABLE IF NOT EXISTS Products (
    product_id INT,
    low_fats CHAR(1) CHECK (low_fats IN ('Y', 'N')),
    recyclable CHAR(1) CHECK (recyclable IN ('Y', 'N'))
);

-- Truncate the table
TRUNCATE TABLE Products;

-- Insert data into the table
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (0, 'Y', 'N');
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (1, 'Y', 'Y');
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (2, 'N', 'Y');
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (3, 'Y', 'Y');
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (4, 'N', 'N');
*/