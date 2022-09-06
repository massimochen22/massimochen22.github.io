time_in_mins = 6 * 60 + 52 ##starting time 6:52 am
tot_runtime_mins = (((8 * 60 + 15) * 2) + (7 * 60 + 12)*3) // 60 #in seconds
arrive_hrs = (tot_runtime_mins + time_in_mins) // 60
arrive_mins = (tot_runtime_mins + time_in_mins) % 60
print("I will get home at",arrive_hrs,":", arrive_mins)
