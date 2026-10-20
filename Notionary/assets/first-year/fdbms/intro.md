# Introduction to DBMS &mdash; Module 1

## <u>Definition of Database </u>
**A Database is an organized collection of related data.** In this context, data refers to a known, raw fact, such as a student ID number, an attendance count, or a phone number. **Data is fundamentally different from information: data consists of unorganized raw facts**, whereas information is data that has been processed, contextualized, and organized to provide meaningful insight.

**Example:** The number `101` by itself is purely raw data; it could represent a classroom room number, a score, a rank, or credits earned. However, when associated with an attribute like `Student_Roll_No`, it immediately conveys context and transforms into actionable information.

## <u>Database Management System (DBMS) </u>

A Database Management System (DBMS) is specialized system software designed to create, maintain, and manage databases. It facilitates core operations such as the creation, retrieval, insertion, modification, and deletion of data systematically based on defined business rules.

DBMS platforms are engineered to handle large volumes of data while ensuring data protection against system crashes, hardware failures, and unauthorized access. It provides an efficient and standardized interface between users, application programs, and the underlying storage.

**Example:** MySQL, PostgreSQL, and Oracle are widely used Database Management Systems.

---
**A Database Management System** is a computerized software suite that enables users to create, read, update, and delete (CRUD) records within a database, supporting its complete operational lifecycle. 
It functions as a general-purpose software framework that facilitates the process of **defining, constructing, manipulating, and sharing** databases across multiple applications and concurrent users.

#### Defining a Database
Defining a database involves specifying the schema: the data types, structures, relationships, and integrity constraints for the data to be stored. All descriptive schema information is stored in the system catalog or data dictionary as metadata.

#### Constructing the Database
Constructing the database is the process of storing the initial data records onto physical storage media managed directly by the DBMS engine.

#### Manipulating the Database
Manipulating the database includes querying to retrieve specific records, inserting or updating data to reflect real-world status changes (such as enrolling a student in a course), and generating structured reports from stored entities.

#### Sharing a Database
Sharing a database enables multiple users, background services, and application programs to access and query the database concurrently without conflict.

### Query & Transaction
Applications interact with the database engine by dispatching queries or executing transactions.

A **query** is an explicit request to access or alter data (such as a `SELECT`, `INSERT`, `UPDATE`, or `DELETE` statement). A **transaction** is a logical unit of work consisting of a sequence of one or more queries that must execute entirely or not at all (adhering to ACID properties) to ensure system consistency.

## <u>Characteristics of DBMS</u>

The following are the fundamental characteristics of a Database Management System:

### Data Integrity
- Data integrity enforces consistency rules across all operations using explicit constraints (such as primary keys, foreign keys, and check constraints).
- It ensures that modifications made by authorized users do not violate data accuracy or lead to invalid data states.
- While system constraints enforce domain and referential correctness, business-level input validation remains critical to ensure overall operational accuracy.

### Security
- The DBMS enforces robust authentication and role-based access control (RBAC).
- Users are granted minimal privileges required for their role; for instance, students cannot modify the marks in a database.
- Unauthorized access and data exposure are blocked through encryption and strict permissions.

### Real World Entity
- A DBMS models real-world business domains directly. Entities, attributes, and relationships inside the database mirror physical systems.
- For example, a college database represents tangible entities such as `Student`, `Instructor`, `Course`, and `Department`.

### Self-Explaining Nature
- A DBMS is self-describing because it maintains a system catalog (data dictionary) containing metadata; data that defines the structure of the data itself.
- Metadata includes table names, attribute names, data types, indexing paths, and constraint definitions.
- This catalog enables the DBMS software to operate independently across distinct databases without hardcoded application logic.

### Can store any kind of structured data
- Modern relational systems store and manage structured tabular data while enforcing schema definitions.
- They allow complex real-world relationships—such as one-to-many and many-to-many associations, to be structured cleanly and predictably.

### Ease of Access
- Stored data is retrieved efficiently via declarative query languages like SQL, utilizing underlying indexing mechanisms rather than manual file scans.
- All core record interactions are implemented cleanly through standardized CRUD operations (Create, Read, Update, Delete).

### SQL & NoSQL Databases
- Modern databases broadly categorize into relational (SQL) and non-relational (NoSQL) architectures.
- SQL databases store data in predefined relational schemas composed of tables, columns, and rows.
- NoSQL databases support flexible, dynamic schemas designed for unstructured or semi-structured data, using document (e.g., JSON in MongoDB), key-value, column-family, or graph stores.
- Enterprise DBMS environments often integrate both paradigms depending on structural consistency and scaling requirements.

**SQL Databases are formally called Relational Databases while NoSQL Databases are formally called Non&mdash;Relational Databases**

> Unlike SQL databases, NoSQL databases can easily store different types of flexible data. For example, in an application where users can log in through Google, Microsoft, or directly with a mobile number and password, a NoSQL database like MongoDB can store each account format cleanly in the same place without creating empty fields or repeating unnecessary data, because it does not enforce a rigid table structure.

## <u>Advantages of DBMS</u>

The following are the primary advantages of utilizing a **Database Management System** over traditional file-processing systems:

#### 1 &mdash; Controlling Data Redundancy
In traditional file-processing systems, independent departments maintain isolated files. This creates duplicate copies of identical data across multiple storage locations.  
A DBMS centralizes organizational data into a single repository, ensuring every entity is recorded once.  

Reducing redundant entries optimizes storage utilization and eliminates update anomalies.  

**Example:** In a college file system, the Admissions Office and the Library might both store duplicate copies of a student's contact details. In a DBMS, this information resides in a single `Student` table, which is referenced by both departments.

#### 2 &mdash; Data Consistency
Data consistency is achieved directly by minimizing data redundancy. When an attribute value changes, it is updated in one centralized location, making the update immediately visible across all modules.

**Example:** When exam results are uploaded from the college, they are instantly visible to the students across all mediums (Website, ERP Software, Dashboards, etc). Thus, data is consistent across all access points (formally called as views)

#### 3 &mdash; Sharing of Data
A DBMS facilitates concurrent access to a unified database for multiple client applications and users. The Database Administrator (DBA) configures access rights and permissions systematically.  
Authorized local and remote services can query and read shared records safely at the same time.

#### 4 &mdash; Data Independence
A DBMS decouples the conceptual schema (data structure definitions) from the application software that queries it.  
This abstraction ensures that structural enhancements at the storage or schema layer do not break existing application logic.

**Example:** Adding an optional `Alternate_Phone_Number` column to a student table or altering a field length from `VARCHAR(50)` to `VARCHAR(100)` does not require rewriting or recompiling the student portal application.

#### 5 &mdash; Data Control
Centralized architecture gives the organization unified control over its data assets. Unlike decentralized file systems, central administration eliminates version mismatches, configuration drift, and unmanaged file duplicates.  

**Example:** Suppose, In a traditional college filesystem, two students were removed from the Main College File but were not removed from the file of the Physics lecture, This created a version mismatch which may cause garbage data to be collected (Like attendance of non&mdash;existent students)

#### 6 &mdash; Security
A DBMS provides granular access control based on user authentication and operational roles.  

**Example:** In a college portal, a student can view only their personal profile and semester grades. A course instructor can view and enter grades for students enrolled in their assigned subjects. The College Principal retains administrative visibility across the entire institution.

#### 7 &mdash; Concurrency Control
In unmanaged file systems, simultaneous write attempts by multiple users can overwrite data or corrupt system state.  
DBMS engines use robust concurrency control mechanisms (such as locking protocols and time-stamping) to serialize concurrent transactions, preventing race conditions and preserving accuracy.

#### 8 &mdash; Data Modelling of Real World
A DBMS provides rich semantic modeling tools (such as Entity-Relationship models and foreign key constraints) to represent intricate real-world dependencies and workflows accurately.

## <u>Levels of Abstraction</u>

To simplify user interaction and shield applications from underlying hardware complexity, the DBMS implements data abstraction.  
**Data abstraction is the technique of suppressing low-level internal storage details and exposing only the necessary conceptual interfaces to users.**
This architecture is structured into three distinct abstraction levels: Physical, Logical, and View.

<figure>
<img src="https://i.postimg.cc/K886Vxhg/image1.png">
<figcaption align="center">Levels of Abstraction</figcaption>
</figure>

### <u>View (External) Level</u>
The View Level is the highest level of abstraction. It defines tailored perspectives of the database for specific user roles while hiding unnecessary details. This custom tailoring simplifies user interaction and safeguards confidential attributes by exposing only authorized data.

### <u>Logical Level (Conceptual Level)</u>
The Logical Level defines the overall logical schema of the entire database; what data is stored and how data entities relate to one another, without going into hardware-specific implementation. This level incorporates tables, attributes, records, data types, primary/foreign keys, and integrity rules. Database administrators and system designers operate primarily at this level. The Logical Level 

### <u>Physical Level (Internal Level)</u>
The Physical Level is the lowest level of abstraction. It describes how data is physically arranged, encoded, and stored on persistent hardware storage media (SSD and/or HDD). Managed directly by the DBMS storage engine and the DBA, it governs data blocks, file clustering, B-tree indexes, disk allocation, memory caching, and buffer management.
All the DML, DDL and DCL languages work at the logical level.

## <u>Data Independence</u>

### <u>Physical Data Independence</u>
Physical Data Independence is the capacity to alter the internal storage schema without altering the logical (conceptual) schema.  
Migrating database storage from conventional hard drives to high-speed NVMe SSDs, repartitioning disk blocks, or creating secondary search indexes does not require alterations to tables or existing query structures.

### <u>Logical Data Independence</u>
Logical Data Independence is the capacity to alter the logical schema without modifying external views or breaking existing application programs.  
Adding new tables, introducing optional attributes to an existing entity, or expanding data domains can occur without rewriting the application code that relies on the established schema.

## <u>Data Architecture</u>
The DBMS serves as the centralized software interface between end users, applications, and physical data storage.  
It translates high-level user operations (such as select, insert, update, and delete requests) into optimized low-level storage routines.

### <u>Structure of Database</u>

#### 1 &mdash; DDL Compiler
The Data Definition Language (DDL) Compiler processes and validates DDL statements (such as `CREATE`, `ALTER`, and `DROP`). It translates these definitions into low-level metadata tables stored within the data dictionary.

#### 2 &mdash; DML Compiler & Query Optimizer
The Data Manipulation Language (DML) Compiler processes data access operations (`SELECT`, `INSERT`, `UPDATE`, `DELETE`). It parses high-level SQL commands into executable machine code. The Query Optimizer evaluates multiple access paths to select the most efficient execution plan based on system metrics, passing the compiled plan to the storage engine.

#### 3 &mdash; Data Manager
The Data Manager (or Database Control System) is the core operational module of the DBMS engine.  
Its primary responsibilities include:
- Translating execution plans into direct disk input/output operations.
- Interfacing with OS file managers to control disk access and allocation.
- Managing main memory buffers and caching algorithms to optimize throughput.
- Enforcing structural integrity constraints and domain validations.
- Coordinating concurrency control protocols across active transactions.
- Managing write-ahead logging, system checkpointing, and crash recovery procedures.

#### 4 &mdash; Data Dictionary
The Data Dictionary (system catalog) is the central repository holding metadata regarding database structure and configuration.  
It maintains:
- Schema definitions, table names, attributes, data types, and row metrics.
- Domain integrity constraints, check conditions, and referential constraints.
- Physical design specifications, including record formats, storage allocations, and index paths.
- User authorization profiles, security credentials, roles, and resource limits.
- System runtime statistics, query costs, and transaction monitoring logs.

**Importance of Data Dictionary**  
The Data Dictionary is a foundational component of modern database architectures because:
- It provides the DBA with unified administrative control and clear insight into structural metadata.
- It documents design specifications across every phase of the database lifecycle.
- It assists the query processor in resolving object references and authorization privileges.
- It identifies object dependencies across applications, simplifying schema refactoring and maintenance.

#### 5 &mdash; Data File
Data files represent the actual persistent storage on disk where raw records and indexed information reside.  
Historically stored on magnetic tape and older magnetic drives, enterprise deployments now rely on Solid State Drives (SSDs) and high-throughput Storage Area Networks (SANs) for speed, concurrent throughput, and fault tolerance.

#### 6 &mdash; Compiled DML
The output of compiled DML statements is translated into efficient, low-level execution instructions. Repeated or parameterized queries (such as stored procedures and prepared statements) are cached here to reduce parsing and compilation overhead on subsequent executions. *The DBMS does not repeat the entire compilation process for `SELECT * from Table;` if it is used multiple times in a sequence, as it may already be cached for faster response times.*

#### 7 &mdash; End Users
End users are the people and services that interact with the database system.  
They comprise:
- **Application Programmers:** Software engineers writing database-driven applications.
- **Database Administrators (DBAs):** Specialists managing system performance, security, and schema definitions.
- **System Administrators:** Analysts and engineers writing complex queries.
- **Users:** Everyday users interacting with the database through simplified interfaces (such as students viewing grades on a college portal).

*&mdash; Edited by Baibhav Bhattacharya & Prem Vishwakarma*