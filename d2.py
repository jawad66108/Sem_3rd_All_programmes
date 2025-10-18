# num = input("Enter a string: ")
# org=num
# rev=0
# while num>0:
#     dig=num%10
#     rev=rev*10+dig
#     num =num//10
# if org==rev:
#     print("It is a palindrome")
# else:
#     print("It's not")

# ====================================================
# num = input("Enter a string: ")
# org =num
# reversed(num)
# if num==org:
#     print("IT is")
# else:
#     print("IT is not")

# ========================================================
# num = input("Enter a string: ")

# text = input("Enter a string: ").lower()

# vowels = "aeiou"
# vowel_count = 0
# consonant_count = 0

# for char in text:
#     # if char.isalpha():
#         if char in vowels:
#             vowel_count += 1
#         else:
#             consonant_count += 1

# print("Vowels:", vowel_count)
# print("Consonants:", consonant_count)

# ================================================
# str1= input("Enter your String: ").lower()
# str =str1.replace(" ","")

# for i in str:
#     count =0
#     for j in str:
#         if i==j:
#             count +=1
#     print(i," appeared ",count)

#===================================================
# str= input("Enter your String: ").lower()
# le=len(str)
# rev=" "
# for i in range(le-1,-1,-1):
#     rev+=str[i]
# print(rev)


#=====================================================
# str= input("Enter your String: ").lower()
# str1=str.replace(" ","")
# print(str1)

#=====================================================
# num = int(input("Enter your number: "))

# for i in range(1,num+1):
#     if(num%i==0):
#         print(i," ")

#======================================================
# num = int(input("Enter your number: "))
# org=num
# sum =0
# leng =len(str(num))
# while num>0:
#     dig =0
#     dig +=num%10
#     sum =sum+( dig**leng)
#     num //=10
# print (sum)
# if sum==org:
#     print("Is is an armstrong number")
# else:
#     print("It is not")

#========================================================
# n =5
# for i in range(n+1):
#     for j in range(1,i+1):
#         print(j,end="")
#     print(end=" ")

#===========================================================
# import random
# a=0
# cs = random.randint(1,99)

# while True:
#     num = int(input("Enter number: "))
#     a=a+1
#     if(a>=4):
#         print("You are out of moves try later!!!\nThe number was ",cs)
#         break
#     elif num>cs:
#         print(num," is large think of a bit small one")
#     elif num<cs:
#         print(num," is small think of a bit large one")
#     else:
#         print("Congrates you guessed it right!!!!!!")
#         break

#=============================================================
# import random
# count,marks =0,0
# while count<4:
#     a = random.randint(20,99)
#     b= random.randint(2,10)
#     ans=a*b
#     print(a," * ",b)
#     c=int(input("Ans= "))
#     if c==ans:
#         marks+=1

#     count+=1
# print("You got ",marks," of them correct out 5")

#=============================================================
# import random 

# while True:
#     ran= random.randint(1,6)
#     b = int(input("Press 1 to roll it and 2 for quiting: "))
#     if b==1:
#         print("It gives: ",ran)
#     else:
#         break

#============================================================

# tasks =[]
# def view(task):
#     print(tasks)

# def add(task):
#     app =input("Add your task: ")
#     tasks.append(app)


# def rem(task):
#     re= int(input("Enter task number you want to remove": ))
#     tasks.pop(re)
#     print("New list is: ",list)


# while True:

#     num =int(input("Press 1 to view the list\nPress 2 for addding another task\n Press 3 to remove the task\n Your choice: "))
#     if num==1:
#         view(tasks)
#     elif num==2:
#         add(tasks)
#     elif num==3:
#         rem(tasks)
#     else:
#         print("Have a wonderfull day!!!")
#         break


#=============================================================

# num =[24,32,4,34,56,66,108]
# le =len(num)
# sum =0
# for  i in num:
#     sum+=i
# print(sum)
# avg= sum/le
# print("Avg: ",avg)

# mi =num[0]
# ma =num[0]

# for i in num:
#     if ma>i:
#             ma=i
#     else:
#          mi=i
# print(mi," ",ma)

#====================================================================
     
