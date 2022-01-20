# 596. Classes More Than 5 Students

SELECT class FROM Courses
GROUP BY Courses.class
HAVING COUNT(1) >= 5;
