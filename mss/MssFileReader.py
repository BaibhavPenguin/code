from pathlib import Path
from MssError import MssInvalidSourceFileError

def ReadSourceFile(src_path :str):
    src = Path(src_path)

    #Check if PATH is a file, if not raise an error
    if not src.is_file:
        raise MssInvalidSourceFileError(src_path)

    #Check if PATH is a .mss file , if not raise an error
    if not src.suffix.lower() == '.mss':
        raise MssInvalidSourceFileError(src_path)

    lines = []
    with open(src,'r') as source:
        for line in source:
            lines.append(line.strip())

    if not lines:
        raise MssInvalidSourceFileError(src_path)
    
    return lines