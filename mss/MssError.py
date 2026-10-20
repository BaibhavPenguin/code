class MssError(Exception):
    #Base class for All MssErrors
    def __init__(self, message: str, code :str , line :int):
        self.message = message
        self.code = code
        if type(line) is int:
            self.line = line
        else:
            self.line  = 0

class MssInvalidSourceFileError(MssError):
    #Source File is Invalid 
    def __init__(self, path :str):
        self.path = path
        super().__init__(
            message= f"'{path}' is not a valid Micro Symbolic Script (*.mss) source file!",
            code = 'ERR_INVALID_SOURCE',
            line=0
        )

class MssFileNotFoundError(MssError):
     #Source File is Invalid 
        def __init__(self, path :str):
            self.path = path
            super().__init__(
                message= f"'{path}' is missing or does not exist",
                code = 'ERR_FILE_NOT_FOUND',
                line=0
            )

class MssMissingArgsError(MssError):
     #Source File is Invalid 
        def __init__(self, parameters :list):
            self.parameters = parameters
            super().__init__(
                message= f"Valid arguments for {','.join(parameters)} parameters not provided",
                code = 'ERR_MISSING_ARGUMENTS',
                line=0
            )
