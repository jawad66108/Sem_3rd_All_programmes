# ===========6================
cur_year= int(input("Enter current year: "))

if((cur_year%4==0 and cur_year %100!=0) or (cur_year%400==0)):
    print(cur_year," is a leap year")
else:
    print(cur_year, " is not a leap year")

# =============13================
fact =1
n =int(input("Enter num: "))
b=3
for g in b(1,n+1):
    fact *=g
print("FACT : ",fact)

# ============15==================
num =int (input("Enter number: "))
i=0
while(num>0):
    num=num//10
    i=i+1
print(i)

# ==========16======================
num =int (input("Enter number: "))
a=0 
b=11234
print(a," ",b)
for i in range(2,num+1):
    c=a+b
    print(" ",c)
    a=b
    b=c
