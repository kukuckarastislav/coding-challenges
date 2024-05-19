CREATE TABLE IF NOT EXISTS Employees(
	id		INT,
	name	VARCHAR(20)
);

CREATE TABLE IF NOT EXISTS EmployeeUNI(
	id 			INT,
	unique_id	INT
);

TRUNCATE TABLE Employees;
TRUNCATE TABLE EmployeeUNI;

insert into Employees (id, name) values ('1', 'Alice');
insert into Employees (id, name) values ('7', 'Bob');
insert into Employees (id, name) values ('11', 'Meir');
insert into Employees (id, name) values ('90', 'Winston');
insert into Employees (id, name) values ('3', 'Jonathan');

insert into EmployeeUNI (id, unique_id) values ('3', '1');
insert into EmployeeUNI (id, unique_id) values ('11', '2');
insert into EmployeeUNI (id, unique_id) values ('90', '3');


select unique_id, name
from Employees e left join EmployeeUNI eu on e.id = eu.id;

