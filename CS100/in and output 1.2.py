name1 = input('What is your first person\'s name?')
age1 = int(input('How old is he/she?'))
weight1 = float(input('Please give his/her weight'))

name2 = input('What is your second person\'s name?')
age2 = int(input('How old is he/she?'))
weight2 = float(input('Please give his/her weight'))

name3 = input('What is your third person\'s name?')
age3 = int(input('How old is he/she?'))
weight3 = float(input('Please give his/her weight'))
print("    ")
tot_age = age1+age2+age3
print(name1,",",name2,",and",name3,"total age is --->",tot_age,)
avg_age = (age1+age2+age3)/3
print(name1,",",name2,",and",name3,"average age is --->",avg_age,)
print("    ")
tot_weight = weight1+weight2+weight3
print(name1,",",name2,",and",name3,"total weight is --->",tot_weight,)
avg_weight = (weight1+weight2+weight3)/3
print(name1,",",name2,",and",name3,"average weight is --->",avg_weight,)





