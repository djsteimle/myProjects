import sys
# import numpy as np
# import pandas as pd
# from sklearn import ...

for line in sys.stdin:
    
    length = 0
    mthSpot = ''
    
    #read string from user assuming they know to enter only one integer at the end
    #remove spaces in the string
    line = line.replace(" ", "")
    length = len(line)
    #find the int at the end of the string and save the variable
    mthInt = line[length-2]
    #if the M is larger than the length of the actual string, print blank and end
    if int(mthInt) > length - 2:
        #print(" ", end)
        print()
    #find the mth spot by using the mthInt and where the actual string ends
    mthSpot = line[length-2 - int(mthInt)]
    #mthSpot = line[(lenght-1) - mthInt]
    #print(mthSpot, end="")
    print(mthSpot)
