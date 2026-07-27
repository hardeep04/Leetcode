# Write your MySQL query statement below
select st.student_id, st.student_name, s.subject_name, count(e.student_id) as attended_exams 
FROM Students st CROSS JOIN Subjects s
LEFT JOIN Examinations e 
    ON st.student_id = e.student_id 
   AND s.subject_name = e.subject_name
group by st.student_id, st.student_name, s.subject_name
order by st.student_id, s.subject_name ASC