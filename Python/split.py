class StringHelper:

    def filt(Func,Itter):
        for i in Itter:
            if Func(i):yield i;
    
    def split(sentencetoseperte:str,seperator:str)->list:
        out=[[]];
        seperator=set(seperator);
        seperator.update("");
        previous,next=0,0;
        for i in sentencetoseperte:
            if i in seperator:
                out.append([]);
                continue;
            out[-1].append(i);
        for i in range(len(out)):
            out[i]=("".join(out[i]));
        delet=[x for x in StringHelper.filt(lambda x:x!="",out)];
        return delet;

    def remove(sent,seper):
        seper=set(seper);
        out=[x for x in StringHelper.filt(lambda x: x not in seper,sent)];
        a="".join(out);
        return a;

def test(__name__):
    if __name__=="__main__":
        s="""
        Gay.
        Jay is happy.
        The lord is Broken.
        God is asleep."""
        print(StringHelper.split(s,' \nabcdefghijlkmnopqrstuvwxyz.'));
        print(StringHelper.remove(s,"a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,x,y,z\n ."));

test(__name__)