#  23. Reverse a string without using slicing.
# st = input("Enter string: ")
# rev = ""

# for i in st:
#     rev =  i+rev # Prepend each character

# print("Reversed string:", rev)

# 26. Convert the first letter of every word to uppercase.
# st=input("Enter string: ")
# capitalize_next= False
# result=" "
# for m in st:
#     if capitalize_next:
#         result+=m.upper()
#         capitalize_next= False
#     else: 
#         result+=m
#     if m == " ":
#         capitalize_next = True
   
# print(result)

# 28. Remove duplicates from a list
# name =["Jawad","Mahnoor","Jawad","Ali"]
# new=[]
# for m in name:
#     if m not in new:
#         new.append(m)

# print(new)

# 29. Sort a list without using the built-in sort() function.
# numbers = [5, 2, 9, 1, 5, 6]

# for i in range(len(numbers)):
#     for j in range(0, len(numbers) - i - 1):
#         if numbers[j] > numbers[j + 1]:
#             numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]

# print("sorted list :", numbers)

# num = [34,5,435,25,46,2345,346,345,25]

# for m in range(len(num)):
#     for j in range(0,len(num)-m-1):
#         if num[j]<num[j+1]:
#             num[j],num[j+1]=num[j+1],num[j]

# print("2nd largest number is: ",num[1])


# Password Strength Checker — Check if password is strong (mix of chars, numbers, etc.)

