class inter:
    def __init__(self):
        self.stack=[]
    
    def LOADVALUE(self,arg):
        self.stack.append(arg)

    def PRNPOP(self):
        try:print(self.stack.pop())
        except:print("Empty PRINT")
    
    def ADDTWONUM(self):
        try:self.stack.append(self.stack.pop()+self.stack.pop())
        except:print("Empty ADD")
    
    def run(self,codelist):
        instructions = codelist["INS"]
        arguments = codelist["ARG"]
        for step,val in instructions:
            match step:
                case "LOADVALUE":
                    try:self.LOADVALUE(arguments[val])
                    except:print("Missing Argument")
                case "ADDTWONUM":
                    self.ADDTWONUM()
                case "PRNPOP":
                    self.PRNPOP()
                case _:
                    print("ERROR: ",step," UNRECOGNIZED INSTRUCTION",sep="")
                    break

what_to_execute = {
    "INS": [("LOADVALUE", 0),
                    ("LOADVALUE", 1),
                    ("ADDTWONUM", None),
                    ("LOADVALUE", 2),
                    ("ADDTWONUM", None),
                    ("PRNPOP", None)],
    "ARG": [7, 5, 8] }

a=inter()
a.run(what_to_execute)