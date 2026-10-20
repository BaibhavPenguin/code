import argparse 
import sys
from pathlib import Path
from MssError import MssFileNotFoundError
from MssError import MssInvalidSourceFileError
from MssError import MssMissingArgsError

SRC = 'source'
BIN = 'small'

def ParseBootArguments():
    parser = argparse.ArgumentParser(description='Build arguments for Micro Symbolic Script')
    parser.add_argument('-s','--src',type=str,help='The path to your source file')
    parser.add_argument('-small','--set_binary_size_small',action="store_true",help='Generates a smaller binary , is disabled by default')

    #Raise an Error if n arguments provided
    if len(sys.argv) == 1:
        raise MssMissingArgsError(['--src','-small'])

    #Parse arguments here
    args = parser.parse_args()
    #Extract Arguments into appropriate variables
    source_path = args.src
    binary_size = args.set_binary_size_small

    #Check if source file is valid 
    if Path(source_path).exists():
        #if everything is ok , return a dictionary containing the source and binary type
        return {SRC:source_path, BIN:binary_size}
    else:
        raise MssFileNotFoundError(path = source_path)

    

