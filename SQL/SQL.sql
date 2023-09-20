/*___ Database ___*/ 
create database Students;

drop database Students;


/*___ Table ___*/
use Students;
create table Student(
	Id int primary key auto_increment,
    Name varchar(50) not null,
    Age varchar(3) not null,
    Roll varchar(10) not null,
    Phone varchar(11),
    Depertment varchar(4) not null
);

alter table student add Mark varchar(3) not null;

drop table Student;

insert into student(
	Name, Age, Roll, Phone, Depertment
) values(
	'Said', '40', '520132', '0179', 'ET'
);

update Student set Name='Shovon', Roll='' where Id=6;

delete from Student where Id=5;

select * from student;
select name from student;
select name from student where id=1;
select * from student order by name asc;
select * from student order by id desc;
select * from student where id=1;
select * from student where name='shovon';
select * from student where depertment='ct';


/* Use Foreign key */
create table Result(
	Id int primary key auto_increment,
    StdId int,
	foreign key(StdId) references Student(Id),
    Name varchar(50),
    Roll varchar(10),
    Subject varchar(10) not null,
    CGPA varchar(2) not null
);

drop table result;

insert into Result(StdId,Name,Roll,Subject,CGPA)
	values(5,'Shovon','520157','CMT','4');


