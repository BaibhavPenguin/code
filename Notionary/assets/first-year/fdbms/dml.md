# DML Statements &mdash; Module 1

<link rel="stylesheet" href="./styles/tables.css">

## <u>Introduction</u>
---
Data Manipulation Language (DML) statements are used for managing data within database. DML commands are not auto-committed. It means changes are not permanent to database, they can be rolled back.

## <u>Viewing the Structure of a Table</u>
---
Using create table command, we can create table.  
So, we have tables in MySQL, so we will use the DESCRIBE command to show the structure of our table, such as column names, constraints on columns, etc.  
The `DESC` command is a short form of the `DESCRIBE` command. Both `DESCRIBE` and `DESC` command are equivalent and case insensitive.  

#### Example
`DESC Student`

## <u>Inserting Data into a Table</u>
---
In MySQL, we can use `INSERT` statement to store or add data in table within the database.

#### Syntax
`INSERT INTO table_name(field1, field2,...fieldN)VALUES(value1, value2,...valueN);`

#### Example
`INSERT INTO STUDENT1(RollNo,NAME,AGE) values(101,'Gauri',21);`

## <u>Deleting Rows from a Table</u>
---
The `DELETE` statement is used to delete a record from table.  
Using this delete statement, the full row from the table is deleted.  
Once we delete the records using the query, we cannot recover it.  

#### Syntax
`DELETE FROM table_name WHERE condition;`

#### Example
`DELETE FROM student1 WHERE RollNo=101;`
