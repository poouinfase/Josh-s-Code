f=open("input/Day2.txt",'r');
scor={"A":1,"B":2,"C":3};
winingplay={'A':'B','B':'C','C':'A'}
losingplay={winingplay[i]:i for i in winingplay}
#x for rock y for paper z for scissors
#a for rock b for paper c for scissors
#1r 2p 3s
poin=0;
for LINE in f.readlines():
    op=None;
    win=LINE[2]=='Z';
    draw=LINE[2]=='Y';
    lose=LINE[2]=='X';
    if win:poin += 6;op=winingplay[LINE[0]];
    if draw:poin += 3;op=LINE[0];
    if lose:poin += 0;op=losingplay[LINE[0]];
    #print(LINE,win,draw,poin);
    #input();
    poin+=scor[op]
print(poin)
