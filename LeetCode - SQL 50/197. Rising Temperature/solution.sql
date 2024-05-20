select w2.id
from Weather w1 join Weather w2 on w1.recordDate = w2.recordDate-1
where w2.temperature > w1.temperature

-- same
select today.id
from Weather yesterday join Weather today on yesterday.recordDate = today.recordDate-1
where today.temperature > yesterday.temperature