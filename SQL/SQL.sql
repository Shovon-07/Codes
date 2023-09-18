/*___ Database ___*/ 
create database Students;

drop database Students;


/*___ Table ___*/
use Students;
create table Student(
	Id int,
    Name varchar(50),
    Roll varchar(10),
    Phone varchar(11),
    Depertment varchar(4)
);

insert into student(
	Id, Name, Roll, Phone, Depertment
) values(
	1,'Shovon', '52057', '0179999', 'CMT'
);

delete from Student where Id=1;

select * from student;
