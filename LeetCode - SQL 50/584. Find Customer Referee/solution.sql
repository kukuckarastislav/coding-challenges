
-- Create table
CREATE TABLE IF NOT EXISTS Customer (
    id INT,
    name VARCHAR(25),
    referee_id INT
);

-- Truncate the table
TRUNCATE TABLE Customer;

-- Insert data into the table
INSERT INTO Customer (id, name, referee_id) VALUES (1, 'Will', NULL);
INSERT INTO Customer (id, name, referee_id) VALUES (2, 'Jane', NULL);
INSERT INTO Customer (id, name, referee_id) VALUES (3, 'Alex', 2);
INSERT INTO Customer (id, name, referee_id) VALUES (4, 'Bill', NULL);
INSERT INTO Customer (id, name, referee_id) VALUES (5, 'Zack', 1);
INSERT INTO Customer (id, name, referee_id) VALUES (6, 'Mark', 2);


select name
from Customer as cr
where cr.referee_id != 2; -- not valid for NULLs

select name
from Customer as cr
where referee_id is distinct from 2; -- properly hanlde NULLs

-- ok
SELECT name FROM Customer WHERE referee_id != 2 OR referee_id IS NULL;