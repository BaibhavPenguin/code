from console import terminal as _terminal
from tools import index as _index
from tools import db_create as _dbs
from sql import db_functions as _db_functions
from sql.dbtools import NoDatabaseError
import sqlite3 as _sqlite3
import globals as _globals




#SHOW SUBCOMMANDS

def scmd_show_databases(_command ):
    headers = ["[bold yellow]Databases[/bold yellow]"]
    rows = []
    for key in _globals.global_indexed_databases.keys():
        rows.append([f"[bold white]{key}[/bold white]"])

    _terminal.print_generic_table(headers,rows,False)
    return True

def scmd_show_error(_command ):
    return False

def scmd_show_tables(command_obj :dict):
    query = command_obj['command']
    SHOW_TABLES = ("SELECT name FROM sqlite_schema WHERE type='table' AND name NOT LIKE 'sqlite_%'")
    try:
        data = _db_functions.execute_sql_query(SHOW_TABLES)
    except _sqlite3.Error as err:
        _terminal.console_errors(query,err,'Query failed!')
        return False
    except NoDatabaseError:
        _terminal.console_errors(query,'Query failed to execute as there is no active database.','Query failed!')
        return False;

    #Construct Rows & Columns
    headers = [f"[bold yellow]Tables[/bold yellow]"]
    rows = []
    for row in data[2]:
        rows.append([*row])
    #Initiate table construction
    _terminal.print_generic_table(headers,rows)
    return True

def scmd_show_views(command_obj :dict):
    query = command_obj['command']
    SHOW_VIEWS = ("SELECT name FROM sqlite_schema WHERE type='view' AND name NOT LIKE 'sqlite_%'")
    try:
        data = _db_functions.execute_sql_query(SHOW_VIEWS)
    except _sqlite3.Error as err:
        _terminal.console_errors(query,err,'Query failed!')
        return False
    except NoDatabaseError:
        _terminal.console_errors(query,'Query failed to execute as there is no active database.','Query failed!')
        return False;

    #Construct Rows & Columns
    headers = [f"[bold yellow]Views[/bold yellow]"]
    rows = []
    for row in data[2]:
        rows.append([*row])
    #Initiate table construction
    _terminal.print_generic_table(headers,rows)

def scmd_show_create(command_obj :dict):
    object_type = command_obj['tokens'][2]
    object_name = command_obj['tokens'][3]

    supported_objects = ('table','trigger')
    if object_type.lower() not in supported_objects:
        _terminal.console_errors(object_type,f"{object_type} is not a valid argument for the [bold white]show create[/bold white] command.","Invalid arguments provided!")
        return False


    query = f"SELECT sql from sqlite_master WHERE type='{object_type.lower()}' AND name='{object_name}'"

    try:
        data = _db_functions.execute_sql_query(query)
    except _sqlite3.Error as err:
        _terminal.console_errors(query,err,'Query failed!')
        return False
    except NoDatabaseError:
        _terminal.console_errors(command_obj['command'],'Query failed to execute as there is no active database.','Query failed!')
        return False;

    sql_return = []
    for row in data[2]:
        sql_return.append(*row)
    headers = [f"[bold yellow]{object_type.upper()}[/bold yellow]",f"[bold yellow]CREATE {object_type.upper()}[/bold yellow]"]
    rows = [[object_name,*sql_return]]
    _terminal.print_generic_table(headers,rows)
    return True

def scmd_show_triggers(command_obj :dict):
    pass
    


#CREATE SUBCOMMANDS
def smd_ignore_execution(_command):
    return False

def scmd_create_database(command_obj :dict):
   command = command_obj['tokens']
   db_name = command[2]
   if  _dbs.create_database(_globals.PATH_DB_DATA,db_name):
        _index.write_index((_globals.PATH_DB_INDEX / _globals.filename_database_index),db_name,(_globals.PATH_DB_DATA / f"{db_name}.db"))
        _index.read_index((_globals.PATH_DB_INDEX / _globals.filename_database_index),_globals.global_indexed_databases)
        _terminal.print(f'[bold white]Created new database [bold green]{command[2]}[/bold green] at [italic yellow]"{(_globals.PATH_DB_DATA / command[2])}.db"') 
        return True
   else:
        _terminal.console_errors(command[1],f"Failed to create database named {command[1]}","Command couldn't be executed!")
        return False




#Show Databases
#Show tables
#Show Columns
#Show Views
#Show Triggers
#Show Create Table
#Show Create View
#Show Index



#EXECUTE SQL QUERIES - NEEDS MORE WORK
def scmd_execute_sql(command_obj :dict):
    query = command_obj['command']
    try:
        sql_result = _db_functions.execute_sql_query(query)
    except _sqlite3.Error as err:
        _terminal.console_errors(query,err,'Query failed!')
        return False
    except NoDatabaseError:
        _terminal.console_errors(query,'Query failed to execute as there is no active database.','Query failed!')
        return False;

    if sql_result[0] and not sql_result[1]:
        if sql_result[3] == -1 : sql_result[3] = 0
        _terminal.print(f'[bold white]Query successful. Rows affected {sql_result[2] }.[/bold white]')
        return True
