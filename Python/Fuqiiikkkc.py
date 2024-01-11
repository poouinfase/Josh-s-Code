""" #A PROTOTYPE FOR CONWAYS GAME OF LIFE
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
from random import random
class game:
    def printfield(l):
        #PRINTS A 2D ARRAY L (USED ONLY FOR GAMEFIELD)
        for i in l:
            for j in i:
                print(j,end=" ")
            print("")
        print("")
        return None #VOID

    def initafield (n,m):
        #INTIALIZES A 2D ARRAY WHICH IS N X M TO USE AS THE FIELD
        gam=[]
        for i in range(n):
            gam.append([])
            for j in range(m):
                gam[i].append(0)
        return gam #LIST

    def randfillfield(l):
        #PASS THE GAMEFIELD AND RANDOMLY ASSIGN 1 or 0
        for i in range(1,len(l)-1):
            for j in range(1,len(l[i])-1):
                l[i][j]=int(random()>0.5)
        return None #VOID

    def Evaluatenextcopy(gamefield, cpyfield):
        #INPUT THE GAMEFIELD AND A COPYFIELD NAD EVALUATE THE NEXT FRAME
        for i in range(1,len(gamefield)-1):
            for j in range(1,len(gamefield[i])-1):
                cpyfield[i][j]=gamefield[i-1][j-1]+gamefield[i][j-1]+gamefield[i+1][j-1]+gamefield[i-1][j]+gamefield[i+1][j]+gamefield[i-1][j+1]+gamefield[i][j+1]+gamefield[i+1][j+1]
        return None #VOID

    def EvaluatenextFrame(l,copyl):
        #INPUT THE GAMEFIELD AND COPYFIELD AND EVALUATES THE NEXT GAMEFIELD
        for i in range(len(l)):
            for j in range(len(l[i])):
                if 3>copyl[i][j] or copyl[i][j]>5:
                    l[i][j]=0
                else:
                    l[i][j]=1
        return None #VOID

    def perframe( n, m, gamefield):
        #THE PERFRAME CALCULATION
        cpyfield=game.initafield(n,m)
        game.Evaluatenextcopy(gamefield, cpyfield)
        game.EvaluatenextFrame(gamefield,cpyfield)
        game.printfield(gamefield)
        return None #VOID

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
n,m=input().split() #N X M INPUT
n,m=int(n),int(m)

gamefield=game.initafield(n, m)
game.randfillfield(gamefield)

for i in range(64):
    game.perframe(n, m, gamefield)
    if input()=="q":
        break """

