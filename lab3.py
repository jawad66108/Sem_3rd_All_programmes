# cou =2
# while cou<=20:
#     print(cou)
#     cou+=2


# for m in range(1,11):
#     if m%2==0:
#         print("even: ",m)

# def r(c,f):
#     sum=c+f
#     print(sum)

# r(74,24)

# import math 
# print(math.factorial(5))

#=====================================================
# num = int(input("Enter number: "))
# for m in range(1,11):

#     print(m,"*",num," = ",m*num)

#========================================================
# sum,a=0,0
# while a<50:
#     a+=2
#     print(a)
#     sum +=a
# print("Sum of all is: ",sum)


#============================================================
# n1=int(input("Enter num1: "))
# n2=int(input("Enter num2: "))
# n3=int(input("Enter num3: "))
# def find_largest(n1,n2,n3):
#     if n1>n2 and n1>n3:
#          print(n1," is the largest of all")
#     elif n2>n1 and n2>n3:
#         print(n2," is the largest of all")
#     else:
#         print(n3," is largest of all")

# find_largest(n1,n2,n3)

#=================================================================
# num = int(input("Enter Radius: "))

# def calcuate_area(radius):
#      return 3.14*(radius*radius)

# print("Area: ",calcuate_area(num))

#=======================================================================

num =int(input("Enter Marks: "))
def student_report():
    
    def grade_status(num):
        if num>=50:
            print ("Pass")
        else:
            print ("Fail")
    
    grade_status(num)

student_report()

