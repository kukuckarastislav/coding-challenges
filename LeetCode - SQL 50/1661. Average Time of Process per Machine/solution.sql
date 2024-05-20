-- Create the table with ENUM equivalent in PostgreSQL
CREATE TABLE IF NOT EXISTS Activity (
    machine_id INT,
    process_id INT,
    activity_type VARCHAR(5) CHECK (activity_type IN ('start', 'end')),
    timestamp FLOAT
);

-- Truncate the table
TRUNCATE TABLE Activity;

-- Insert data into the table
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (0, 0, 'start', 0.712);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (0, 0, 'end', 1.52);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (0, 1, 'start', 3.14);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (0, 1, 'end', 4.12);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (1, 0, 'start', 0.55);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (1, 0, 'end', 1.55);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (1, 1, 'start', 0.43);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (1, 1, 'end', 1.42);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (2, 0, 'start', 4.1);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (2, 0, 'end', 4.512);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (2, 1, 'start', 2.5);
INSERT INTO Activity (machine_id, process_id, activity_type, timestamp) VALUES (2, 1, 'end', 5);




select a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp)::numeric, 3)  as processing_time
from Activity a1, Activity a2
where a1.machine_id = a2.machine_id and a1.process_id = a2.process_id 
	and a1.activity_type='start' and a2.activity_type='end'
group by a1.machine_id;