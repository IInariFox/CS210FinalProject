import re
import string



def getFreqAllItems(string = ""):  #this method returns a string which contains all the items & their respective frequency
    filename = "input.txt" #give your input file name here, it should be in the same directory where python code is present
    f= open(filename, "r") #open input data file
    if not f:
        print("Could not open the file, please check the file name") #print error message if , file is not opened
    else:
        data= f.read() #read file read
        listItems= data.split() #split the data into individual items & store them in a list
        frequency = {} # dictionary to store item:frequeny
        for item in listItems:
            frequency[item]= frequency.get(item,0)+1 #calculating frequency

        return_string = "" #answer string
        for item,freq in frequency.items():
            return_string+= item + " : " + str(freq) + '\n' #appending data to answer string
        return return_string  #return answer_string



def getFrequencySingleItem(item_name):#this method returns a string which contains the given item & respective frequency
    filename = "input.txt"  #give your input file name here, it should be in the same directory where python code is present
    f= open(filename, "r")  #open input data file
    if not f:
        print("Could not open the file, please check the file name") #print error message if , file is not opened
    else:
        data= f.read()  #read file read
        listItems= data.split()   #split the data into individual items & store them in a list
        frequency = {}  # dictionary to store item:frequeny
        for item in listItems:
            frequency[item]= frequency.get(item,0)+1   #calculating frequency

        if item_name in frequency:  #if given item is present in the string
            return frequency[item_name]  #return the frequency
        return "NO such item present"  #else return no such item present

def showHistogram(string=""):
    filename = "input.txt"  #give your input file name here, it should be in the same directory where python code is present
    f= open(filename, "r")  #open input data file
    if not f:
        print("Could not open the file, please check the file name") #print error message if , file is not opened
    else:
        data= f.read()  #read file read
        listItems= data.split()   #split the data into individual items & store them in a list
        frequency = {}  # dictionary to store item:frequeny
        for item in listItems:
            frequency[item]= frequency.get(item,0)+1   #calculating frequency

        ans=""  #answer string
        for item,freq in frequency.items():
            ans+=item + " " +  '*'* freq + '\n'  #appending item, '*' no.of times the item occures

        return ans #returning answer
