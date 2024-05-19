CREATE TABLE IF NOT EXISTS Sales (
	sale_id			INT,
	product_id		INT,
	year			INT,
	quantity		INT,
	price			INT
);

CREATE TABLE IF NOT EXISTS Product (
	product_id		INT,
	product_name	VARCHAR(10)
);

TRUNCATE TABLE Sales;
TRUNCATE TABLE Product;

insert into Sales (sale_id, product_id, year, quantity, price) values ('1', '100', '2008', '10', '5000');
insert into Sales (sale_id, product_id, year, quantity, price) values ('2', '100', '2009', '12', '5000');
insert into Sales (sale_id, product_id, year, quantity, price) values ('7', '200', '2011', '15', '9000');

insert into Product (product_id, product_name) values ('100', 'Nokia');
insert into Product (product_id, product_name) values ('200', 'Apple');
insert into Product (product_id, product_name) values ('300', 'Samsung');


select product_name, year, price
from Sales s left join Product p on s.product_id = p.product_id;