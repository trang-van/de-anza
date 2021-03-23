'''
Lab 2

Trang Van
CIS 41B

User Interface - Uses tkinter and EnrollData class to create a graphic interface. Displays plots create from given file.
'''

from enrolldata import EnrollData

import tkinter as tk
import tkinter.messagebox  as  tkmb

import matplotlib
matplotlib.use('TkAgg')               	                         # tell matplotlib to work with Tkinter
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg  # Canvas widget
import matplotlib.pyplot as plt	                                 # normal import of pyplot to plot

FILENAME = "students2.csv"                                       #const variable for file name

class mainWin (tk.Tk):
    # Creates the main window with the widgets: 2 buttons for 2 plots and a label
    def __init__(self):                
        super().__init__()
        self.geometry("300x75")
        self.title("CCC Enrollment")
        description = "Enrollment data for California Community Colleges"
        L1 = tk.Label(self, text=description, fg="blue")    # No need for a variable is it's not being used just "tk.Label"    
        L1.grid(row=0, column = 0,columnspan = 2)    
        self.columnconfigure(1, weight =1)

        try:
            self.ed = EnrollData(FILENAME)
            self.ed.readFile()
            self.yearsArr = self.ed.getYearArr()
        except FileNotFoundError: #except IOError
            fw = fileExceptWin()
            # OR do the if tkmb.showerror() == 'ok': self.destroy()
            self.destroy()   #WOULDN'T need this OR THE FILEEXCEPTCLASS         
            return
            
        F1 = tk.Frame(self) #Frame for buttons 
        
    #Button for Enrollment Trend By Year
    
        B1_main = tk.Button(F1, text = "Enrollment Trend", command = self.getPlotWin) # command = lamda: PlotWin( self, self._d.enrollmentTrend) <= get function name
        B1_main.grid(row = 1, column = 0)
        
    #Button for Enrollment Trend By Age
        B2_main = tk.Button(F1, text = "Enrollment By Age", command = self.getDialogBox)
        B2_main.grid(row = 1, column = 1)

        F1.grid(row = 1, column= 1)
    
    # Creates a Toplevel dialog box for user to specify year
    def getDialogBox(self):
        return self.wait_window(dialogBox(self))
    '''
    # def plotAge(self):
    years= self._d.getYears()
    dialog =DialogWin(self, years)
    self.wait_window(dialog) => wont run functions below until dialogbox is closed
    choice = dialog.getChoice()
    if choice != -1:
        PlotWin(self, self._d.enrollmentbyAge, choice)
    '''
    # Creates plotWin to plot the enrollment trend plot
    def getPlotWin(self):
        pw = plotWin(self)
        pw.enrollTrendPlt()
    
  
# Dialog Box Window after user chooses Enrollement

class dialogBox(tk.Toplevel):  
    # Constructs dialogBox object and its widgets: radiobuttons and a confirm button
    def __init__(self, master):
        super().__init__(master)
        
        self.grab_set()        #=> cant't go back
        self.focus_set()  
        #self.protocol("WM_DELETE_WINDOW", self._close) 
        #MAIN SHOULD DO ALL PLOTTING, DIALOG JUST COLLECTS INFORMATION USER
        self.transient()
        
        self.geometry()
        self.title("Enrollment By Age")     
        
        self.year = 0
        
        # RADIO BUTTONS in for loop
        count = 0       
        F2 = tk.Frame(self)
        radiobuttons = []        
        controlVar = tk.IntVar() # make it self._controlVar

        for i in range(len(self.master.yearsArr)):
            count += 1
            rb = tk.Radiobutton(F2, text = str(self.master.yearsArr[i]), variable=controlVar, value= count, command = lambda : self.setYear(controlVar.get()))
            radiobuttons.append(rb)
            radiobuttons[i].grid(row = 0 , column = i)        
        '''   
        for i, y in enumerate(self._years):
            tk.Radiobutton(self, text = str(y), variableself._ControlVar, value = i_. grid (row =0, column =i))
        i = is counting
        y= is elements in years
        '''
        controlVar.set(1)                   #set first button as default
        
        '''   
        # MANUALLY CREATE BUTTON
        rb1 = tk.Radiobutton(F2, text = "2014", variable=controlVar, value= 1, command = lambda : self.setYear(controlVar.get()))
        rb1.grid(row = 0, column = 2)
        
        rb2 = tk.Radiobutton(F2, text="2015", variable=controlVar, value=2, command = lambda : self.setYear(controlVar.get()))
        rb2.grid(row = 0, column = 3)
        
        rb3 = tk.Radiobutton(F2, text = "2016", variable=controlVar, value=3, command = lambda : self.setYear(controlVar.get()))
        rb3.grid(row = 0, column = 4)
        
        rb4 = tk.Radiobutton(F2, text="2017", variable=controlVar, value=4, command = lambda : self.setYear(controlVar.get()))
        rb4.grid(row = 0, column = 5)
        '''
        
        #OK BUTTON
        confirm_bttn = tk.Button(F2, text = "OK", command = self.getPlotWin)
        confirm_bttn.grid(row = 1, column = 2)
        F2.grid()
        
        # OK Button self.destroy , set value at last input 
        
    
    # Uses control variable to set year that will be passed into function
    def setYear(self, var):
        self.year = self.master.yearsArr[var-1]
        
    # GET CHOICE TO RETURN CONTROL VAR TO CALL
    
    #Plots after year is set by creating a plot window 
    def getPlotWin(self):
        pw = plotWin(self.master)
        pw.ageGroupPlt(self.year)    

    # CLOSE 
    '''
    def close():
       self._controlVar.set(-1)
       self.destroy()
    '''
#Plot Window

class plotWin(tk.Toplevel):
    # Constructs the object inherited from Toplevel    
    def __init__(self, master):  #master is MainWin 
        #init__ (self, master, plotFct, *args, **kwargs) to get plotFct
        super().__init__(master)    
        
        #self.transient(master) => put in focus
        #fig = plt.figure(figsize = (8,4))
        #plotFct(*args, **kwargs) =>works for both, just in case function getting passed in might need something, use *args, **kwargs
        
    # Uses EnrollData's plotEnrollTrend to plot total students
    def enrollTrendPlt(self):
        fig = plt.figure(figsize=(10,10))
        
        self.master.ed.plotEnrollTrend()

        canvas = FigureCanvasTkAgg(fig, master=self)      # create canvas with figure that matplotlib used
        canvas.get_tk_widget().grid()                        # position canvas
        canvas.draw()     
    
    # Uses EnrollData's plotByAgeGroups to plot based on the year chosen by user
    def ageGroupPlt(self, year):
        fig = plt.figure(figsize=(10,10))
        
        self.master.ed.plotByAgeGroups(year)
     
        canvas = FigureCanvasTkAgg(fig, master=self)
        canvas.get_tk_widget().grid()
        canvas.draw()                                        
 
# File Exception Handling - Window tries to open file, displays error if it can't find the file
# Exits the GUI if user clicks okay or X

class fileExceptWin ():
    # Calls showerror from tkmb
    def __init__(self):
        tkmb.showerror("Error", "Can't open: " + FILENAME + "\nCheck file and try again", parent = None)
            
     

# MAIN FUNCTION - Creates the main window, checks for the file, and runs the mainloop
def main():
    app = mainWin() 
    app.mainloop()    

main()


'''

DATA ANALYSIS ON STUDENTS2.CSV
------------------------------
The enrollment trend graph shows a spike in the number of students in 2009 and the numbers have been decreasing since then.
While the number of students in the "19 or less" or "20-24" has been consistent, there has been a descrease in students who are 30+ years old.
A possible reason for this increase and decrease in older students may be due to the 2008-2009 recession in California. This could have caused the 
older population to lose jobs and during their unemployment went to school. Since the economy has grown since 2009,
the older population are more likely to find jobs which might deter them from school.

'''