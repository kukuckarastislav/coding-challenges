CREATE TABLE IF NOT EXISTS Visits(
	visit_id	INT,
	customer_id	INT
);

CREATE TABLE IF NOT EXISTS Transactions(
	transaction_id 	INT, 
	visit_id 		INT, 
	amount 			INT
);

TRUNCATE TABLE Visits;
TRUNCATE TABLE Transactions;

insert into Visits (visit_id, customer_id) values ('1', '23');
insert into Visits (visit_id, customer_id) values ('2', '9');
insert into Visits (visit_id, customer_id) values ('4', '30');
insert into Visits (visit_id, customer_id) values ('5', '54');
insert into Visits (visit_id, customer_id) values ('6', '96');
insert into Visits (visit_id, customer_id) values ('7', '54');
insert into Visits (visit_id, customer_id) values ('8', '54');

insert into Transactions (transaction_id, visit_id, amount) values ('2', '5', '310');
insert into Transactions (transaction_id, visit_id, amount) values ('3', '5', '300');
insert into Transactions (transaction_id, visit_id, amount) values ('9', '5', '200');
insert into Transactions (transaction_id, visit_id, amount) values ('12', '1', '910');
insert into Transactions (transaction_id, visit_id, amount) values ('13', '2', '970');

select v.customer_id, count(v.visit_id) as count_no_trans
from Visits v left join Transactions t on v.visit_id = t.visit_id
where t.transaction_id is NULL
group by v.customer_id

