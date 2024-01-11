
from numba import jit, cuda,int64
import numpy as np

class disp:
    def __init__(self) -> None:
        pass

    def printfieldFactory(self,Field,method=1):
        match method:
            case 1:
                self.printfieldtoCommandLine(Field)
    
    def printfieldtoCommandLine(self,Diss):
        for i in Diss:
            for j in i:
                print(j,end=" ")
            print("")
        print("")

class primgener:
    def __init__(self):
        self.prime=1
    
    def isprim(n):
        for i in range(2,round(n**0.5)+1):
            if n%i==0:
                return False
        return True
    
    def nexprim(self):
        self.prime+=1
        while(not primgener.isprim(self.prime)):
            self.prime+=1
        return self.prime
   
    def retrprimemap(self,m,n):
        primhash=[]
        for i in range(m):
            primhash.append([])
            for j in range(n):
                    primhash[i].append(self.nexprim())
        return primhash


""" class hasmaker:
    def hasser(m,n):
        l=[]
        for i in range(m):
            l.append([])
            coun=0
            for j in range(n):
                l.append(2**coun)
                coun+=1
        return l """

from random import random
class field:

    def __init__(self,m,n):
        #MAKE THE FIELD AS M x N 
        self.gamefield=[[0 for j in range(n)] for i in range(m)]
        self.columns,self.rows=n,m
        self.primhash=[]
        a=primgener()
        self.primhash=a.retrprimemap(m,n)
        #INTIALIZING
        
    def setfield(self, copy):
        #SET THE FIELD TO A NEWER VALUE
        self.gamefield=[[copy[i][j] for j in range(self.columns)] for i in range(self.rows)]
        return None #VOID
    
    def getgamefieldcopy(self):
        #RETURNS A COPY THE FIELD THAT THE INSTANCE CONTAINS
        return self.gamefield[:] #LIST
        
    def getgamefield(self):
        #RETURNS A COPY THE FIELD THAT THE INSTANCE CONTAINS
        return self.gamefield #LIST
    
    def getprimfieldcopy(self):
        #RETURNS A COPY OF THE FIELD HASH MAP THAT THE INSTANCE CONTAINS
        return self.primhash[:] #LIST

    def getsize(self):
        #RETURNS THE SIZE OF THE INSTANCE FIELD
        return (self.rows,self.columns) #TUPLE(INT,INT)
     
    def randfillfield(self):
        #PASS THE FIELD AND RANDOMLY ASSIGN 1 or 0
        for i in range(1,self.rows-1):
            for j in range(1,self.columns-1):
                self.gamefield[i][j]=int(random()>0.5) #RANDOM NUMBER GENERATOR
        return None #VOID

    def printfield(self):
        #DISLPLAY THE FIELD USING THE DISP CLASS
        self.printer=disp()
        self.printer.printfieldFactory(self.gamefield)
        return None #VOID

    def fieldclear(self):
        #CLEAR THE FIELD
        for i in range(self.rows):
            for j in range(self.columns):
                self.gamefield[i][j]=0
        return None #VOID

    def val(self):
        #THE NUMBER OF LIVING CELLS
        s=0
        for i in self.gamefield:
            for j in i:
                s+=j
        return s #INT

    def hashthefield(self):
        #COMPUTE THE UNIQUE ID FOR THE GAMESTATE
        l=[]
        has=1
        for i in range(self.rows):
            l.append([])
            for j in range(self.columns):
                l[i].append(self.primhash[i][j]*self.gamefield[i][j])
        for i in l:
            for j in i:
                if j==0:
                    continue
                has*=j
        return has #INT
    
    def fieldthehash(self,has):
        #COMPUTE THE FIELD FROM A HASH
        l=self.getprimfieldcopy()
        for i in range(self.rows):
            for j in range(self.columns):
                l[i][j]=int((has%l[i][j] ==0))
        return l #list
    
class comper:
    def main(n=None,m=None):
        if not n:n=int(input())
        if not m:m=int(input())
        game=field(n,m)
        copy=game.getgamefieldcopy()
        game.randfillfield()
        game.printfield()
        comper.eval(game.getgamefield(),copy)
        game.setfield(copy)
        game.printfield()
        return None
    
    def eval(game,l):
        comper.eval_jj(game,l)
        comper.eval_Live_Or_Dead(l)
        return None
    
    def eval_jj(gamefield,cpyfield):
        #INPUT THE GAMEFIELD AND A COPYFIELD NAD EVALUATE THE NEXT FRAME
        for i in range(1,len(gamefield)-1):
            for j in range(1,len(gamefield[i])-1):
                cpyfield[i][j]=gamefield[i-1][j-1]+gamefield[i][j-1]+gamefield[i+1][j-1]+gamefield[i-1][j]+gamefield[i+1][j]+gamefield[i-1][j+1]+gamefield[i][j+1]+gamefield[i+1][j+1]
        return None #VOID
        
        return None
    def eval_Live_Or_Dead(l):
        #INPUT THE GAMEFIELD AND COPYFIELD AND EVALUATES THE NEXT GAMEFIELD
        for i in range(len(l)):
            for j in range(len(l[i])):
                if 3>l[i][j] or l[i][j]>5:
                    l[i][j]=0
                else:
                    l[i][j]=1
        return None #VOID

comper.main(50,50)