# Entity Relationship Model and ER Table &mdash; Module 1

<link rel="stylesheet" href="./styles/tables.css">

## <u>Entity</u>
---

An entity is a thing that exists either physically or logically.

- An entity may be a physical object such as a house or a car, or an entity may be a logical concept like an event such as a house sale or a car service, or a concept such as a customer transaction or order.

- The E-R model consists of entities and relationships between those entities. An entity is nothing but a thing having its own properties.

- These properties help to differentiate the object (entity) from other objects.

- In the ER diagram, an entity can be represented as rectangles.

**Example:** In the following ER model the Employee and department are Entities.

## <u>Attributes</u>
---

**Attributes are the properties which define the entity type.**  
<u>Eclipse is used to represent an attribute.</u>   

**Example:** The Employee entity could use Employee id, Employee name and The Department entity could use Department number and Department name as attribute.

### <u>Types of Attributes</u>

**Simple Attribute:** It can not be divided into simpler components.  
**Example:** Gender of an Employee. Gender cannot be broken down into smaller parts.  

**Composite Attributes:** An attribute composed of many other attribute is called as composite attribute.  
**Example:** Address attribute of Employee Entity type consists of Street, City, State, and Country. In ER diagram, composite attribute is represented by an oval comprising of ovals.  

**Multi-valued Attributes:** The attribute having many values for a particular entity is called as multi-valued attribute.  
**Example:** Each Employee has multiple mobile numbers.  

**Derived Attribute:** The value of this attributes which can be derived from the value of related stored attribute which are known as derived attribute.  
**Example:** The First Name & Last Name can be derived from the Full Name of a customer.  

**Key Attribute:** An attribute of an entity type for which each entity must have a unique value is called a key attribute of the entity type. **Key attributes are also called as Super Keys**  
**Example:** StudentId of each student in a college is unique.  

**Null Attributes:** This attribute can take NULL value when entity does not have value for it.  
**Example:** Before any exams are conducted, the result attribute of a student may show NULL to indicate that data does not exist.

**Stored Attributes:** The attribute that need to be stored permanently in database.  
**Example:** Date of joining of Employee is stored permanently.

  
<div class="dyntable">
<table>
<tr>
<th>Type </th>
<th> Notation </th>
</tr>

<tr>
<td>Attribute (Simple/Single valued/Stored)
<td>Key attributes
</tr>

<tr>
<td>Oval notation
<td>Oval with underline
</tr>

</table>
</div>


## <u>Keys</u>
---
Keys are used for uniquely identifying a row in a table and form different types of relationships between two or more tables.  
The following are the different types of keys.  

#### Super Key
Any attribute that can uniquely identify a row is called a super key or a key attribute

#### Candidate Key
Anything that uniquely identifies a row without any redundant attributes is called a Candidate Key, Candidate Keys are also called **Minimal Super Keys**  

#### Composite Key
Anything which is made using combination of two or more columns/attributes (like {name,age}) and can uniquely identify a row is called a composite key  

*Not all composite keys are candidate keys, for example - In the composite key {StudentUID,StudentName} StudentUID can identify all students independently, thus the student name is redundant and unnecessary, hence this composite key is NOT a candidate key*

#### Primary Key
The candidate key selected to uniquely identify the row by default. It has to be unique and **NOT NULL** by schema rules. 

#### Natural Key
An attribute of a record which can be used to uniquely identify a row but also holds real world meaning other than identification purposes (like an aadhar number)

#### Surrogate Key
An artificially generated value which solely functions to uniquely identify a row and has no real world connection outside of identification purposes.

#### Foreign Key 
The key which bridges two tables. It is borrowed from a different table. The primary key of one table can be the foreign key of multiple tables.

> Foreign keys are not Super Keys by default as they allow multiple rows under the same key, except for Foreign Keys in 1:1 Relationship Models , where the **Foreign Key is used as the Primary key or is forced to be unique**, thereby upgrading it to a candidate key.


## <u>Entity Set</u>
---
An Entity is an object of Entity Type and set of all entities is called as entity set.

- Entity set is a collection of similar entities.

- An entity set is a group of entities that passes the same set of attributes.

- Each entity in an entity set has its own set of values for the attributes which make it distinct from other entities in a table.

- No two entities in an entity set will have the same values for the attributes.

There are two types of Entity Sets.  

#### <u>Strong Entity Set</u>

- An entity set that has a primary key using which, entities in the table can be uniquely identified. This kind of entity set is termed as a strong entity set. Strong entity set is also known as a regular entity set.  
- In an ER diagram, the strong entity set is represented by the rectangle. Here, the primary key is underlined with the solid line.

**Example:** In case of Employee in class each employee is identified by unique Emp_id which is a primary key.

#### <u>Weak Entity Set</u>

A weak entity set doesn't have any primary key which can identify each entity in a set distinctly. But, for discriminating the entities in a set, the weak entity set is dependent on a particular strong entity set.

- A weak entity is also said to be existence dependent as for the existence of its entities it has to be dependent on a particular strong entity set i.e. a particular “strong entity set”.

- The relation between a weak entity set and a strong entity set is said to be identifying relationship.

- Weak entity set is represented by double rectangle.

**Example:** In case of ‘Department’ entity depend on employee entity for primary key.


## <u>Relationship</u>
---

- A relationship is used to describe the relation between entities.

- The association among entities is called a relationship.

For example, an employee works_at a department, a student enrols in a course. Here, Works_at and Enrolls are called relationships.

**Diamond or rhombus is used to represent the relationship.**

#### <u>Concepts in Relationship</u>

**Relationship Set:** A set of relationships of similar type is called a relationship set. Like entities, a relationship too can have attributes. These attributes are described attributes.

**Degree of Relationship:** The number of participating entities in a relationship defines the degree of relationship.  **2 Entities = Binary Relationship** , **3 Entities = Ternary Relationship , 4 Entities = Quaternary Relationship**

## <u>Constraints on Relationship</u>
---

### <u>Mapping Constraints</u>
A mapping constraint is a data constraint that expresses the number of entities to which another entity can be related via a relationship.  
It is most useful in describing the relationship sets that involve more than two entity sets.  
For binary relationship set R on an entity set A and B, there are four possible mapping cardinalities. These are as follows:  
- One to one (1:1) 
- One to many (1:M) 
- Many to one (M:1) 
- Many to many (M:M)

#### <u>One to One (1:1)</u>
In a one to one relationship, a row of a table is only related to a single row in another table.   
**Example:** Assume two tables, **StudentDetails** and **StudentAttendance** are in a 1:1 relationship with StudentID as the Foreign Key. Here, in StudentAttendance, each student with a StudentID will only have a single attendance ie a single row of data. Hence, in both the tables Student Details and Student Attendance, StudentID is the primary key used for uniquely identifying a record.

#### <u>One to Many (1:M)</u>
In a one to many relationship, a row in one table can be related to multiple rows in another table.
**Example:** Assume two tables **StudentDetails** and **Subjects** with StudentID as the Foreign Key. 

#### <u>Many to One (M:1)</u>
Multiple rows in one table are related to at most a single row in another table. It is essentially a One to Many relationship backwards.  
**Example**: In a table Subjects, A Student with the same StudentID can select multiple subjects, hence multiple rows in table Subjects are related to a single row of the corresponding StudentID in table StudentDetails.

#### <u>Many to Many (M:M)</u>
Multiple rows in one table can be related to multiple rows in another table.

---
### <u>Additional Constraints</u>
Constraints in database management systems relate to restrictions on data or data processing. This means that only a specific kind of data can be added to the database or that a specific kind of action may be carried out on the data in there.
Thus, constraints in a database management system (DBMS) ensure data accuracy.  

#### <u>Key Constraint</u>
In order to guarantee data accuracy and consistency in a database, a DBMS employs rules known as "key constraints"  
They ensure that the data is accurate by defining the relationship between the values in one or more columns of a table and the values in other tables.  
Following are some key constraints:  

**Primary Key Constraint:** An unique identifier for every record in a database is known as a primary key constraint. It ensures that every database record uses a unique value or two separate values that are non-null as a means of identification. Can be set by `PRIMARY KEY` keywords while creating a table.     

**Foreign Key Constraint:** A foreign key constraint is a reference to the primary key in another table. It guarantees that a column's or group of columns' values in one table match the primary key column(s) in another table. Can be set by `FOREIGN KEY` keyword while creating a table.  

**Unique Constraint:** A unique constraint in a database makes sure that no two values inside a column or group of columns are the same. Can be set by `UNIQUE` keyword while creating a table.

#### <u>Participation Constraint</u>
Participation Constraints in database management systems (DBMS) are rules that specify the minimum and maximum number of entities or relationships that are required to participate in a given relationship.  
Participation constraints are necessary to maintain the consistency and integrity of the data.  
In database management systems, there are two kinds of participation constraints, such as:  

**Total participation:** A **total participation constraint** means that every single entity in a table must take part in a relationship. No exceptions, no blanks, and no unassigned entities allowed.  
**Example:** Imagine a college database with two entities: `STUDENT` and `DEPARTMENT`, connected by the relationship `Belongs_To`. Here, according to college policy, **Each and every student must be enrolled in a course like (BSc, BComm, etc)**; Thus, the design enforces a total participation constraint on student where every `STUDENT` must participate in the relationship `Belongs_To` as they must have a `DEPARTMENT`

**Partial Participation:** A **partial participation constraint** means that not every record in an entity set needs to participate in a relationship. Participation is optional. Some entities participate, while others do not.  
**Example:** In a College Database, every student does not need to participate in every competition, While some students participate, it is not forced by design. Hence the `STUDENT` entity is in a partial participation constraint with `EVENTS` relationship.

> While designing the schema, relations made using `FOREIGN KEY` are partial participation by default as it accepts NULL in the Foreign Key attribute of a record however, by using the `NOT NULL` constraint we can enforce mandatory participation, formally called as Total participation Constraint.

## <u>Weak & Strong Entities</u>
---

<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>#</th>
        <th>Feature</th>
        <th>Strong Entity</th>
        <th>Weak Entity</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>1</td>
        <td><strong>Primary Key</strong></td>
        <td>Has a dedicated primary key that uniquely identifies each record independently.</td>
        <td>Lacks an independent primary key; relies on a partial key (discriminator) combined with the parent's primary key.</td>
      </tr>
      <tr>
        <td>2</td>
        <td><strong>Existence Dependency</strong></td>
        <td>Can exist independently of any other entity in the database.</td>
        <td>Cannot exist on its own; its existence depends entirely on an identifying (strong) owner entity.</td>
      </tr>
      <tr>
        <td>3</td>
        <td><strong>Participation Constraint</strong></td>
        <td>Participation in relationships may be total or partial (often optional).</td>
        <td>Always has total participation (mandatory) in the identifying relationship with its parent entity.</td>
      </tr>
      <tr>
        <td>4</td>
        <td><strong>ER Diagram Notation</strong></td>
        <td>Represented by a single rectangular box.</td>
        <td>Represented by a double rectangular box (connected via a double diamond identifying relationship).</td>
      </tr>
      <tr>
        <td>5</td>
        <td><strong>Discriminator / Key Line Style</strong></td>
        <td>Primary key attribute is underlined with a solid line (e.g., <u>student_id</u>).</td>
        <td>Partial key attribute is underlined with a dashed line (e.g., <span style="border-bottom: 1px dashed #000;">relation_type</span>).</td>
      </tr>
      <tr>
        <td>6</td>
        <td><strong>Real-World Example</strong></td>
        <td><strong><code>Student</code></strong> is uniquely identified by <code>student_id</code> which exists independently in the system.</td>
        <td><strong><code>Parent_Contact</code></strong> only has <code>contact_name</code>; cannot be identified or used without the <code>student_id</code>.</td>
      </tr>
    </tbody>
  </table>
</div>


## <u>Aggregation</u>
---

- Aggregation is meant to represent a relationship between a whole object and its component parts.

- It is used when we have to model a relationship involving (entity sets) and a relationship set.

- Aggregation allows us to treat a relationship set as an entity set for purposes of participation in (other) relationships.

**Example:** A project is sponsored by a department. This is simple relationship. An Employee monitors this sponsors (and not project or department). This is aggregation. Monitors are mapped to the table like any other relationship set.


## <u>Generalization & Specialization</u>

### <u>Specialization</u>
- A Specialization is a top-down approach in which a higher-level entity is divided into multiple specialized lower-level entities.

- In addition to sharing the attributes of the higher-level entity, these lower-level entities have specific attributes of their own.

- Specialization is usually used to find subsets of an entity that has a few different or additional attributes.

**Example:** Set of subclass (SECRETARY, TECHNICIAN, ENGINEER) are specialization of super class EMPLOYEE.  

**Notation:** The subclass defined in a specialization is attached by lines to a circle which is connected to super class. ○ The subset symbol on each line connecting a subclass to circle indicates the direction of super class/subclass relationship.

**Specific Attribute:** An attribute applied only to entities of particular subclass is called as specific attribute.

### <u>Generalization</u>
It is reverse process of specialization or this is bottom up approach of Superclass/subclass relationship.  
Generalization is a process in which we differentiate among several entity types identifying there common features and generalizing them to a single super class of which original entity type are special subclass.  

**Example:** Car and Truck all having several common attribute they can generalize to super class Vehicle.

**Notation:** A diagrammatic notation to distinguish between generalization and specialization is used in some programming methodologies.  
Arrow pointing to generalized superclass represents generalization.   Arrow pointing to generalized subclass represents specialization.  
 
**Attribute Inheritance:** The attribute of higher and lower level entities created by specialization and generalization are attributes inheritance.    
Abstraction through which relationship (aggregation) is treated as higher level entities.  

## <u>Entities & Attributes</u>  
---
<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>#</th>
        <th>Comparison Basis</th>
        <th>Entity</th>
        <th>Attribute</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>1</td>
        <td><strong>Fundamental Definition</strong></td>
        <td>A distinct real-world object, concept, or thing that exists independently.</td>
        <td>A specific characteristic, quality, or property that describes an entity.</td>
      </tr>
      <tr>
        <td>2</td>
        <td><strong>Structural Role</strong></td>
        <td>Acts as the core subject about which data is collected and stored.</td>
        <td>Supplies the detailed data values that describe the subject.</td>
      </tr>
      <tr>
        <td>3</td>
        <td><strong>Relational Representation</strong></td>
        <td>Maps directly to an entire table (relation) in a relational database schema.</td>
        <td>Maps directly to a column or field within that table.</td>
      </tr>
      <tr>
        <td>4</td>
        <td><strong>ER Diagram Notation</strong></td>
        <td>Represented visually by a <strong>rectangle</strong>.</td>
        <td>Represented visually by an <strong>oval (ellipse)</strong> connected to its entity.</td>
      </tr>
      <tr>
        <td>5</td>
        <td><strong>Classification Types</strong></td>
        <td>Classified primarily into <em>Strong Entities</em> and <em>Weak Entities</em>.</td>
        <td>Classified into <em>Simple, Composite, Single-valued, Multi-valued, Key,</em> and <em>Derived</em> attributes.</td>
      </tr>
      <tr>
        <td>6</td>
        <td><strong>Independence</strong></td>
        <td>Can hold meaning and identity on its own without needing another object.</td>
        <td>Cannot exist in isolation; it becomes meaningless without an associated entity.</td>
      </tr>
      <tr>
        <td>7</td>
        <td><strong>Real-World Example</strong></td>
        <td><strong><code>Car</code></strong> (a distinct physical vehicle represented as a table).</td>
        <td><strong><code>VIN</code></strong>, <strong><code>Color</code></strong>, <strong><code>Model</code></strong>, and <strong><code>Fuel_Capacity</code></strong> (the descriptive fields of the vehicle).</td>
      </tr>
    </tbody>
  </table>
</div>


## <u>Binary vs Ternary Relationship</u>  
---

<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>#</th>
        <th>Comparison Basis</th>
        <th>Binary Relationship</th>
        <th>Ternary Relationship</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>1</td>
        <td><strong>Degree of Relationship</strong></td>
        <td>Degree is 2; it connects exactly two distinct entity sets.</td>
        <td>Degree is 3; it connects exactly three distinct entity sets simultaneously.</td>
      </tr>
      <tr>
        <td>2</td>
        <td><strong>ER Diagram Representation</strong></td>
        <td>The relationship diamond has lines connecting to exactly two entity rectangles.</td>
        <td>The relationship diamond has lines connecting to three entity rectangles at once.</td>
      </tr>
      <tr>
        <td>3</td>
        <td><strong>Relational Implementation</strong></td>
        <td>Usually resolved by placing a foreign key in one table, or using a two-column junction table for many-to-many associations.</td>
        <td>Requires a dedicated relationship table with at least three foreign keys to capture the combined association correctly.</td>
      </tr>
      <tr>
        <td>4</td>
        <td><strong>Decomposability</strong></td>
        <td>Represents a direct link between two entities that requires no further division.</td>
        <td>Cannot be split into multiple independent binary relationships without losing the exact context of how the three entities interact together.</td>
      </tr>
      <tr>
        <td>5</td>
        <td><strong>Real-World Example</strong></td>
        <td>A <strong>Doctor</strong> <em>Treats</em> a <strong>Patient</strong> (two entities linked directly).</td>
        <td>A <strong>Doctor</strong> <em>Prescribes</em> a <strong>Medicine</strong> to a <strong>Patient</strong> (all three must be linked together to record which doctor gave which medicine to which specific patient).</td>
      </tr>
    </tbody>
  </table>
</div>

*&mdash; Edited by Baibhav Bhattacharya & Prem Vishwakarma*