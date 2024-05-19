CREATE TABLE IF NOT EXISTS Tweets(
	tweet_id 		INT,
	content			VARCHAR(50)
);

TRUNCATE TABLE Tweets;

insert into Tweets (tweet_id, content) values ('1', 'Vote for Biden');
insert into Tweets (tweet_id, content) values ('2', 'Let us make America great again!');

select tweet_id from Tweets where length(content) > 15;