/*___ Database ___*/
create database Students;
drop database world;

/*___ Table ___*/
use Students;

/* Create table */
create table Student(
	Id int primary key,
    Name varchar(50) not null,
    Roll varchar(10) not null,
    Phone varchar(11),
    Depertment varchar(3) not null
);

/* Add Table Field */
alter table Student add Email varchar(50);

/* Delete table */
drop table Student;

/* Insert data in table */ 
insert into Student
	(Id,Name,Roll,Phone,Depertment)
    values(4,'sexy','520143','019','ent');

/* Delete data */
delete from Student where Id=4;

/* Update data */
update Student set Roll='520120' where Id=2;

select * from student;
select * from student where Id=1;

/* Sorting */
select * from student order by Name asc;
select * from student order by Name desc;