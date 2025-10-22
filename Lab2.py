# furits = ["apple","banana"," cherry"]

# for m in furits:
#     print(m)
#     if m=="banana":
#         break


# st="Programming"
# for j in st:
#     if j!="m":
#         print(j)
#         continue
108
# name =input("Enter your name: ")
# key = 

# stdid =[]
# sum=0
# while True:
    
#     a=int(input("Enter id: "))
#     if a==0:
#         break
#     else:
        
#         if  a in stdid:
#                 print("Warning!!! ID ERROR")
#                 break
#         stdid.append(a)
#     sum+=1
# print("Total stdId's are: ",sum)

# pas = input("Enter password: ")
# le =len(pas)
# while True:
#     if le<8:
#         print("your pass has less then 8 characters!!\nTry again")
# pas=input()
    # len(pas)
    
# temp =[]
# day =["Mon","Tue","Wed","Thur","Fri","Sat","Sun"]
# a=0
# sum=0

# while True:
#     if a==7:
#         break
#     else:
#         print("Temp for",day[a]," ")
#         b=float(input("= "))
#         temp.append(b)
#         a+=1
# min =temp[0]
# ma=temp[0]

# for m in temp:
#     sum+=m
#     if ma>m:
#         ma=m
#     else:
#         min=m

# print("MAX: ",ma," MIN: ",min)
# avg=sum/7
# print("Avg: ",avg)
# for m in temp:
#     if m>avg:  
#         print(m)

# while True:
#     pw=input("Enter password: ")
#     if len(pw)<8:
#         print("Password must be at least 8 characters long")
#         continue
#     if not any(ch.isupper() for ch in pw):
#         print("Add at least one uppercase letter")
#     elif not any(ch.isdigit() for ch in pw):
#         print("Add at least one number")
#     elif not any(ch in "!@#$%&*" for ch in pw):
#         print("Add at least one special character (!@#$%&*)")
#     else:
#         print("Password is strong")
#         break

# def add_student(name,*marks):
#     return (name,marks)

# def calculate_average(*marks):
#     return sum(marks)/len(marks)

# def assign_grade(avg):
#     if avg>=85:return "A"
#     elif avg>=70:return "B"
#     elif avg>=55:return "C"
#     else:return "D"
# students=[]
# for i in range(5):
#     name=input("Enter name: ")
#     marks_input=input("Enter marks separated by space: ").split()
#     marks=[]
#     for m in marks_input:
#         marks.append(int(m))
#     students.append(add_student(name,*marks))
# for s in students:
#     avg=calculate_average(*s[1])
#     grade=assign_grade(avg)
#     print(s[0],"- Average:",avg,"Grade:",grade)


# temps=[]
# for i in range(7):
#     temps.append(int(input("Enter temperature: ")))
# def get_max_min(temps):
#     max_t=temps[0]
#     min_t=temps[0]
#     for t in temps:
#         if t>max_t:max_t=t
#         if t<min_t:min_t=t
#     return max_t,min_t
# def above_average(temps):
#     total=0
#     for t in temps:total+=t
#     avg=total/len(temps)
#     print("Above average days:")
#     for t in temps:
#         if t>avg:print(t)
# mx,mn=get_max_min(temps)
# print("Max:",mx,"Min:",mn)
# above_average(temps)


# class Book:
#     def __init__(self,title,author):
#         self.title=title
#         self.author=author
#         self.is_borrowed=False

#     def borrow_book(self):
#         if not self.is_borrowed:
#             self.is_borrowed=True
#             print("Book borrowed")
#         else:
#             print("Already borrowed")

#     def return_book(self):
#         if self.is_borrowed:
#             self.is_borrowed=False
#             print("Book returned")
#         else:
#             print("Book was not borrowed")

#     def display_info(self):
#         status="Borrowed" if self.is_borrowed else "Available"
#         print(self.title,"by",self.author,"-",status)

# books=[Book("Book1","A"),Book("Book2","B"),Book("Book3","C"),Book("Book4","D"),Book("Book5","E")]
# while True:
#     for i,b in enumerate(books):
#         print(i+1,end=". ");b.display_info()
#     choice=input("Enter book number to borrow/return or 0 to exit: ")
#     if choice=="0":
#         break
#     num=int(choice)-1
#     action=input("Enter 'b' to borrow or 'r' to return: ")
#     if action=="b":books[num].borrow_book()
#     elif action=="r":books[num].return_book()



# class Employee:
#     def __init__(self,name,dept):
#         self.name=name
#         self.department=dept
#         self.monthly_scores=[]

#     def add_score(self,score):
#         self.monthly_scores.append(score)

#     def average_score(self):
#         return sum(self.monthly_scores)/len(self.monthly_scores)
    
#     def performance_level(self):
#         avg=self.average_score()
#         if avg>=85:return "Excellent"
#         elif avg>=70:return "Good"
#         elif avg>=55:return "Average"
#         else:return "Poor"

# import random
# emps=[Employee("Ali","HR"),Employee("Jawad","IT"),Employee("Roonham","Finance")]
# for e in emps:
#     for i in range(5):
#         e.add_score(random.randint(40,100))
# for e in emps:
#     print(e.name,"-",e.department,"Average:",e.average_score(),"Performance:",e.performance_level())

