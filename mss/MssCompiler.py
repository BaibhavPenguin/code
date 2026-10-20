import MssBootArguments
import MssFileReader
from MssError import MssError

try:
    args = MssBootArguments.ParseBootArguments()
    source = MssFileReader.ReadSourceFile(args[MssBootArguments.SRC])
    print(source)
except MssError as err:
    print(err.message)
    print(err.code)
    print(f"Error on line {err.line}")


