# course-select-system
教师信息数据流
定义四个结构体
Struct student
Struct teacher
Struct lesson
Struct course

学生信息包含学生的姓名学号院系
教师信息包含教师的姓名院系
课程信息包含课程名、课程编号、开课地点和学分，并由教师录入删除
选课信息包含学生的选课信息，由学生选择；课程分数，由教师录入

学生通过查询条件，可以查询得到自己的个人信息（个人信息保存在文件）；通过查看可选课程进行选课/退课，并保存于文件；学生可以查看自己已选课程的课程成绩

教师通过查询条件，查询自己的个人信息；通过条件录入删除信息；教师可以录入/删除成绩
