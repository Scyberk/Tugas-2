#tipe data = number (int, float), string

#num = 10
#fl = 3.5 , tdk perlu declare data type

#sentence = "Hello world"
#sentence2 = 'Halo dunia'

# quote = '"This is a quote'
# print(quote) #utk output

# age = 19
# string format
# print(f'My age is {age}')

#Input bisa menerima parameter string
# age = Input("Please input your age: ") #input diterima dalam bntk string
# print(age)

#typecasting
#date_of_birth = 2025 - int(age)

#Comparison operator > < >= == !=
# x = 10
# y = 20

# print(x > y)
# print(x < y)
# print(x == y)

#Logical operator
#Arithmetic Operator + - / * % **
# x+= 100
# print(x)

#Selection
# input = input()

# if(int(input) > 1000):
#     print ("Yes")
# elif(int (input) > 200 and int (input) < 500):
#     print("The number is between 200 and 500")
# else :
#     print("Number is below 200")

#Repetition
#For loop
#iterable = list -> array

#for alias in iterable

# numbers = [3,5,1,6,7,8,9,10]
# for num in numbers :
#     print(num)

#range -> membentuk list angka
#range (start,end (exclusive), increment)

#for i in range(5) : #  1 - 4, (0,5,1)
#     print(i)

# for i in range(1,10,2):
#     print(i, end = '#') #default endingnya \n

#Slicing -> mengambil sebagian dari iterable saja
# iterable[start:end:increment]
# for i in numbers[1:5:2] :
#     print(i)

#enumerate =kalo mau keep track index
#index dan value
# for idx, i in enumerate(numbers):
#     print(f'index: {idx}, Value : {i}')

# #While
# counter = 0
# while True:
#     if(counter == 5):
#         break
#     counter +=1
#     print(counter)

#List
#ordered, changeable, allow duplicate

# new_list = [1,2,3,3]
# print(new_list)

# new_list.append("Haiii")

# new_list[1] = 0, buat ubah
# new_list[new_list.index(2)] = 0

# new_list.pop()
# new_list.remove(3)
# new_list.clear()
# print(new_list)

#Set
#unordered, unchangeable,no duplicate
# new_set= {'a', 'b', 'c'}
# print(new_set)

#Tuple
#ordered, unchangeable, allow duplicate
# new_tuple = (1,2,3)

#ubah ke list
# temp_list = list(new_tuple)
#ubah listnya
# temp_list[1] = 10
#ubah lagi ke tuple
# new_tuple = tuple(temp_list)

# print(new_tuple)

#Dictionary
#menyimpan data dalam key value
#key = identifier
#value = data yg disimpan oleh key

# student = {
#     "name" : "Patricia",
#     "age" : 20
# }

# student["name"] = "Kennedy"
# print(student["name"])

#Function
# def printIntroduction (name = 'Kennedy', major = 'Information System') :
#     print("Hai kamu")
#     # return #yg bawah ga ke process lagi krn udah di return
#     print("Semangat ya")

#     print(f"Hello my name is {name} and I'm a {major} major")

# printIntroduction()

# angka = 55
# def addNumber () :
#     global angka
#     angka = angka + 5
#     return angka

# print(addNumber())

