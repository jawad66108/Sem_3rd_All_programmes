# class Student:
#     def __init__(self,name,reg,gpa,section):
#         self.name=name
#         self.reg=reg
#         self.gpa=gpa
#         self.section=section

#     def Add_std(self):
#         self.name=input("Enter you name: ")
#         self.gpa=input("Enter GPA: ")
#         self.reg=input("Enter Reg: ")
#         self.section=input("Section: ")

#     def Rd_std(self):
#         print("add1")
#     def Up_std(self):
#         print("add2")
#     def rem_std(self):
#         print("add3")

# std1 = Student ("Jawad",108,3.0,"A")

# Create a dictionary for a book with title, author, and year
# Add a new key "genre" with value "Fiction"
# Update the year to current year
# Print all book information

# Book= {
#     "Title" : "DSA",
#     "author" :"Jawad",
#     "year" :  2015
# }

# print(Book)

# Book["genre"] = "Fiction"
# Book["year"] = 200
# print("New DIc\n",Book)
# print (Book.get("author\n"))
# num =[1,2,3,4,5,5,6,88]
# print("\n",num)
# num.append(108)
# print("updated list\n",num)
# num.remove(4)
# print(num)
# print("Length: ",len(num))
# a=(len(num)-1)//2
# print("mid element: ",num[a])

# nu =[1,2,3,4,5,6,8,70]
# print(nu[3])
# jawad husain =10
# print(jawad hussain)
# while True:
#     pas=input("Enter password: ")
    
#     if len(pas)<8:
#         print("Password must be greater then 8 characters: ")
#         continue
#     if not any(m.isupper() for m in pas):
#         print("Add atleast one upper case letter!!!")
#     elif not any(m.isdigit() for m in pas):
#         print("ADD atleat one digit")
#     elif not any(m in "!@#$%^&*()" for m in pas):
#         print("Add atleast one spacial character")
#     else:
#         print("Password is strong")
#         break


