'''
Lab 2

Trang Van
CIS 41B

Enroll Data Class: Reads in csv file and plots 2 graphs. One graph is the enrollment trend by year 
                   and the other is enrollment by age groups. Implements numpy and pyplot.
'''

import csv
import numpy as np
import matplotlib.pyplot as plt

class EnrollData:
    # Constructs EnrollData object and initializes to numpy arrays
    def __init__(self, file):
        self.file = file
        self.dataArrInt = np.array([])
        self.yearArrInt = np.array([])
        
        # should read in file here, shouldn't have to do ed = EnrollData(), ed.readFile()
        # MAKE VARIABLES PRIVATE
        '''
        self._data = np.loadtext(self._file, dtype = int, delimiter =',') => EASIER TO READ FILE
        self._years = self._data[0,:] => create view of first row
        self._num = self._years.shape[0] => keep for radio buttons same as finding length, returns shape in rows and columns
        self._students = self._data[1:,:] => collect data from students in all columns
        '''
    # Decorator that prints return array of numbers from function
    def showNums(f):
        def wrapper(*args, **kwargs):
            result = f(*args, **kwargs)
            print(result)
            return result
        return wrapper 
    
    # Reads file and stores first row into years array and the populates the data into the array
    def readFile(self): 
        with open(self.file) as fin:
            reader = csv.reader(fin)
            years = next(reader)
            years_arr = np.array(years)
            self.yearArrInt = years_arr.astype(int)

            data_list = [row for row in reader]
            dataArr = np.array(data_list)
            self.dataArrInt = dataArr.astype(int)
          
    # Sums up data array for the total of students and creates a plot graph
    @showNums
    def plotEnrollTrend(self) ->list():
        #matplotlib. rcPArams['figure.figsize'] =[12,8]
        
        totalStudents = self.dataArrInt.sum(0) # MAKE INTO NP ARRAY 
        plt.plot(self.yearArrInt, totalStudents/1000000, "--*g")
        plt.title("Total Enrollment (2014-2017)")
        plt.xlabel("Year")
        plt.ylabel("Num of Students (in millions)")
        plt.xticks(self.yearArrInt, self.yearArrInt)        
        #plt.show() #WON'T NEED in GUI
        
        return totalStudents
    
    # Sums up students from each age group and graphs the results on a bar graph by category (except Unknown)
    @showNums 
    def plotByAgeGroups(self, year):
        
        # Find year's index
        idxCt = 0
        yearIdx = 0
        for i in self.yearArrInt:
            if i == year:
                yearIdx = idxCt
            idxCt += 1
        
        # Append sum from each category into list    
        catg_sum_list = []
        for i in range(0,8):
            catg = [self.dataArrInt[j,yearIdx] for j in range(len(self.dataArrInt)) if j % 8 == i]
            catg_sum_list.append(sum(catg))
        
        # Plot Data            
        categoriesLabel = ["19 or less","20-24","25-29","30-34","35-39","40-49","50+"]
        
        plt.bar(np.arange(len(categoriesLabel)), catg_sum_list[0:(len(catg_sum_list)-1)], align='center')
        plt.title ("Enrollment By Categories")
        plt.xlabel("Categories")
        plt.ylabel("Num of Students")
        plt.xticks(np.arange(len(categoriesLabel)),categoriesLabel)
        #plt.show()
        
        return catg_sum_list
    
    # Returns years array for lab2.py to use in GUI
    def getYearArr(self):
        return self.yearArrInt

'''
def main():        
    ed = EnrollData("students2.csv")
    ed.readFile()
    ed.plotEnrollTrend()
    ed.plotByAgeGroups(2008)
    ed.plotByAgeGroups(2017)   
    

main()
'''