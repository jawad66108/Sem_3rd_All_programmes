# import numpy as py
# arr= py.array([10,20,30])

# print(arr.dtype)
# print(arr.size)
# print(arr.shape)

# a = py.arange(1,7)
# print(a)
# a=a.reshape(2,3)
# print(a)
# b= py.full((2,1),99)
# print(b)
# print(a+b)

# import pandas as pd 
# df =pd.read_csv('student.csv')
# print(df.head(5))
# print(df.tail(3))

# print(df[df['Age']>21])
# print(df.sort_values(by='Age',ascending=False))

# print(df.groupby('Department').size())
# print(df.groupby('Department')['Salary'].mean())

import matplotlib.pyplot as plt

days = ['Mon','Tue','Wed','Thu','Fri','Sat','Sun']
temp = [22, 24, 26, 25, 27, 28, 29]

plt.plot(days,temp,color="Red",linewidth=3,linestyle="--",marker='o')
plt.xlabel("DAYS")
plt.ylabel("TEMPRATURE")
plt.grid()
plt.show()
