""" class bepo:
    def __init__(self):
        self.a=[1,2,3,4,5]
    def ret(self):
        return self.a[:]
    def prin(self):
        print(self.a) """
""" def partition(array,low,high):
    i=low-1
    pivot=array[high]
    for j in range(low,high):
        if array[j]<=pivot:
            i+=1
            array[i],array[j]=array[j],array[i]
    array[i+1],array[high]=array[high],array[i+1]
    return i+1

def quicksor(array,low,high):
    if low>=high:
        return None
    
    pi=partition(array,low,high)
    quicksor(array,low,pi-1)
    quicksor(array,pi+1,high)

j=[2,46,23436,56,342431,354,0]
quicksor(j,0,len(j)-1)
print(j) """

n=int(input())
def years_to_roman(a):
    numbers=[1,4,5,9,10,40,50,90,100,400,500,900,1000]
    roman=['i','iv','v','ix','x','xl','l','xc','c','cd','d','cm','m']
    i=12
    roman_numeral=''
    while (a!=0):
        if numbers[i]<=a:
            roman_numeral+=roman[i]
            a=a-numbers[i]
        else:
            i=i-1
    return (roman_numeral)
for i in list(years_to_roman(n)):
    print(i)