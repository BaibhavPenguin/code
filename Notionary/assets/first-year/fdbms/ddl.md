# DDL Statements &mdash; Module 1

<link rel="stylesheet" href="./styles/tables.css">

## <u>DDL Statements</u>

- DDL Stands for **Data Definition Language**, it is used to define the structure or **schema** of the database.
- All DDL Statements are auto-committed i.e. the changes made by DDL Statements are saved permanently in the database.
- It deals with the creation, modification and deletion of Databases, Tables, Views, etc but NOT Data.
- These commands should only be used by the programmer working at the logical level and should remain hidden from the End Users at the View Level.

#### <u>List of DDL Statements</u>

- `CREATE` : This command is used to create the database or its objects (like table, index, function, views, store procedure, and triggers).

- `DROP` :  This command is used to delete objects from the database and/or the database itself.

- `ALTER` : This is used to alter the structure of the database.

- `TRUNCATE` : This is used to remove all records from a table, including all spaces allocated for the records are removed.

- `COMMENT` : This is used to add comments to the data dictionary.

- `RENAME` : This is used to rename an object existing in the database.




#### <u>Datatypes</u>

<h4>1. Integer Data Types</h4>
<p>Used to store whole numbers without decimal values. Example: 123, 78, etc.</p>
<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>Type</th>
        <th>Storage (Bytes)</th>
        <th>Minimum Value (Signed)</th>
        <th>Maximum Value (Signed)</th>
        <th>Minimum Value (Unsigned)</th>
        <th>Maximum Value (Unsigned)</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td><strong>TINYINT</strong></td>
        <td>1</td>
        <td>-128</td>
        <td>127</td>
        <td>0</td>
        <td>255</td>
      </tr>
      <tr>
        <td><strong>SMALLINT</strong></td>
        <td>2</td>
        <td>-32,768</td>
        <td>32,767</td>
        <td>0</td>
        <td>65,535</td>
      </tr>
      <tr>
        <td><strong>MEDIUMINT</strong></td>
        <td>3</td>
        <td>-8,388,608</td>
        <td>8,388,607</td>
        <td>0</td>
        <td>16,777,215</td>
      </tr>
      <tr>
        <td><strong>INT</strong></td>
        <td>4</td>
        <td>-2,147,483,648</td>
        <td>2,147,483,647</td>
        <td>0</td>
        <td>4,294,967,295</td>
      </tr>
      <tr>
        <td><strong>BIGINT</strong></td>
        <td>8</td>
        <td>-9,223,372,036,854,775,808</td>
        <td>9,223,372,036,854,775,807</td>
        <td>0</td>
        <td>18,446,744,073,709,551,615</td>
      </tr>
    </tbody>
  </table>
</div>
<hr>
  <h4>2. Floating Point Data Types</h4>
  <p>Used for storing decimal numbers. Example: 74.7, 23.4, etc.</p>
<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>Type</th>
        <th>Storage (Bytes)</th>
        <th>Minimum Value (Signed)</th>
        <th>Maximum Value (Signed)</th>
        <th>Minimum Value (Unsigned)</th>
        <th>Maximum Value (Unsigned)</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td><strong>FLOAT</strong></td>
        <td>4</td>
        <td>-3.402823466E+38</td>
        <td>1.175494351E-38</td>
        <td>0</td>
        <td>3.402823466E+38</td>
      </tr>
      <tr>
        <td><strong>DOUBLE</strong></td>
        <td>8</td>
        <td>-1.7976931348623157E+308</td>
        <td>-2.2250738585072014E-308</td>
        <td>0</td>
        <td>1.7976931348623157E+308</td>
      </tr>
    </tbody>
  </table>
</div>
<hr>
  <h4>3. Date and Time Data Types</h4>
  <p>Used to represent temporal values such as date, time, datetime, timestamp, and year.</p>
<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>Data Type Syntax</th>
        <th>Storage Size</th>
        <th>Range / Supported Values</th>
        <th>Format / Explanation</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td><strong>YEAR[(4)]</strong></td>
        <td>1 Byte</td>
        <td>1901 to 2155</td>
        <td>Year value as 2 digits or 4 digits (default is 4 digits).</td>
      </tr>
      <tr>
        <td><strong>DATE</strong></td>
        <td>3 Bytes</td>
        <td>'1000-01-01' to '9999-12-31'</td>
        <td>Displayed as <code>YYYY-MM-DD</code>.</td>
      </tr>
      <tr>
        <td><strong>TIME</strong></td>
        <td>3 Bytes + fractional seconds</td>
        <td>'-838:59:59' to '838:59:59'</td>
        <td>Displayed as <code>HH:MM:SS</code>.</td>
      </tr>
      <tr>
        <td><strong>DATETIME</strong></td>
        <td>5 Bytes + fractional seconds</td>
        <td>'1000-01-01 00:00:00' to '9999-12-31 23:59:59'</td>
        <td>Displayed as <code>YYYY-MM-DD HH:MM:SS</code>.</td>
      </tr>
      <tr>
        <td><strong>TIMESTAMP(m)</strong></td>
        <td>4 Bytes + fractional seconds</td>
        <td>1970-01-01 00:00:01 UTC to 2038-01-19 03:14:07 UTC</td>
        <td>Displayed as <code>YYYY-MM-DD HH:MM:SS</code>.</td>
      </tr>
    </tbody>
  </table>
</div>
<hr>
  <h4>4. String Data Types</h4>
<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>Type</th>
        <th>Description</th>
        <th>Display Format</th>
        <th>Range in Characters</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td><strong>CHAR</strong></td>
        <td>Contains non-binary strings. Fixed length declared upon table creation. Right-padded with spaces when stored.</td>
        <td>Trailing spaces are removed upon retrieval.</td>
        <td>0 to 255 characters</td>
      </tr>
      <tr>
        <td><strong>VARCHAR</strong></td>
        <td>Contains non-binary strings. Variable-length strings.</td>
        <td>Retained as stored.</td>
        <td>0 to 255 (before MySQL 5.0.3); 0 to 65,535 (MySQL 5.0.3 and later)</td>
      </tr>
    </tbody>
  </table>
</div>
<hr>
  <h4>5. Binary Data Types</h4>
  <p>Similar to CHAR and VARCHAR, except they contain binary byte strings rather than non-binary character strings.</p>
<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>Type</th>
        <th>Description</th>
        <th>Range in Bytes</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td><strong>BINARY</strong></td>
        <td>Contains fixed-length binary strings.</td>
        <td>0 to 255 bytes</td>
      </tr>
      <tr>
        <td><strong>VARBINARY</strong></td>
        <td>Contains variable-length binary strings.</td>
        <td>65535</td>
      </tr>
    </tbody>
  </table>
</div>

#### <u>ENUM Types</u>
A string object whose value is chosen from a list of values given at the time of table creation. **Example:**  
`CREATE TABLE length ( length ENUM('small', 'medium', 'large') );`

#### <u>Set Types</u>
A string object having zero or more comma separated values (maximum 64). Values are chosen from a list of values given at the time of table creation.  

---

## <u> Creating a Database </u>
---
To create a database, we use the `CREATE` DDL Statement with the `DATABASE` argument.  

### Syntax
`CREATE DATABASE <database_name>`

### Example
`CREATE DATABASE College`

## <u> Using a Database </u>
---
To run queries, we first need to tell the DBMS what database to run these queries on, hence we need to `USE <database_name>`   
This statement is required because a DBMS like MySQL Supports running queries on multiple databases.   

#### Syntax
`USE <database_name>`

#### Example
`USE College`


## <u>Creating a Table</u>
---

#### <u>What is a Table?</u>
A table can represent a single entity (entity is an object whose information is stored in database) that you want to track within your system. Each entity or table has number of characteristics.  
The table must have a unique name through which it can be referred to after its creation. The characteristics of the table are called its attributes. These attributes can hold data.


#### <u>Rules of Table Creation</u>
- Table name and Column name can be 1 to 30 characters long. First character must be alphabetic, but name may include letters, numbers and underscores.

- Names must contain only the characters A-Z, a-z, 0-9, _ (underscore) $ and #.

- Names must not be an Oracle Server reserved word. (**Eg:** information_schema)

- Names must not duplicate the names of other objects owned by the same Oracle server user.

- Table name is not case sensitive.

#### <u>Syntax</u>
`CREATE TABLE <table_name> (<column_name> <datatype>, <column_name> datatype>, ...)`

#### <u>Example</u>

<code>CREATE TABLE students( 
    name VARCHAR(30),
    roll_no INT,
    phone_no INT,
    email VARCHAR(50)
);</code>

#### <u>Constraints</u>

**NOT NULL:** NOT NULL constraint makes sure that a column does not hold NULL value. By specifying NOT NULL constraint, we can be sure that a particular column(s) cannot have NULL values.  
`CREATE TABLE Student (INT StudentID NOT NULL);`  

**UNIQUE:** UNIQUE Constraint enforces a column or set of columns to have unique values, If a column has a UNIQUE constraint, it means that a particular column cannot have duplicate values in a table.  
`CREATE TABLE Details (INT Aadhar UNIQUE);`  

**CHECK:** CHECK constraint is used to restrict the value of a column between a range. It performs check on the values, before storing them into the database. Its like condition checking before saving data into a column.  
When this constraint is being set on a column, it ensures that the specified column must have the value falling in the specified range.  
`CREATE TABLE Student (S_id INT NOT NULL CHECK (S_id> 100));`  

**DEFAULT:** The DEFAULT constraint provides a default value to a column when there is no value provided while inserting a record into a table.  
`CREATE TABLE Payments (INT Current DEFAULT 20000);`  

**PRIMARY KEY:** Primary key uniquely identifies each record in a table.
It must have unique values and cannot contain nulls. In the below example the ROLL_NO field is marked as primary key, that means the ROLL_NO field cannot have duplicate and null values.  
`CREATE TABLE Student (INT RollNo PRIMARY KEY);`  

## <u>Altering a Table</u>
---
The `ALTER` command is used to alter the structure of tables and views.  

#### Add a new column
`ALTER TABLE <table_name> ADD <new_column_name>;`  
You can add `FIRST` or `AFTER <column_name>` to the above command before `<new_column_name>` to specify the position of the new column.  

#### Remove a new column
`ALTER TABLE <table_name> DROP COLUMN <column_name>;`

#### Modify a Column
`ALTER TABLE <table_name> MODIFY <column_name> <column_description>;`  

#### Renaming a Column
`ALTER TABLE <table_name> RENAME COLUMN <old_column_name> TO <new_column_name>;`  

## <u>Truncating Tables</u>
---
`TRUNCATE TABLE` statement is used to remove all records from a table. It performs the same function as a `DELETE` statement without a WHERE clause.  
#### Syntax
`TRUNCATE TABLE table_name;`

## <u>Deleting a Table (Dropping tables)</u>
---
`DROP TABLE` statement allows you to remove or delete a table from the MySQL database.
#### Syntax
`DROP TABLE table_name;`

## <u>Dropping Databases</u>
---
To remove a database from MySQL, we can use the `DROP DATABASE` statement.  
#### Syntax
`DROP DATABASE <database_name>`

*&mdash; Edited by Baibhav Bhattacharya*

