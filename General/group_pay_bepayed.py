import MySQLdb
import sys
import  matplotlib.pyplot as plt
import numpy as np
import matplotlib.dates as mdates
import datetime as dt 







def main(groupid):
   db = MySQLdb.connect(host="localhost", user='jamie', passwd='jamie', db='Gauss', charset="utf8")

 
  # you still need a union of the two arrays
   
   Teacher_Dates = []
   Teacher_Money = [] 
   
   Student_Dates = []
   Student_Money = [] 
   
   # union payments and funds
   # -1 means we GAVE money 
   # +1 we received money
   qry ="select Dat,Amount,-1 As Aus FROM Payments Where GroupID='"+ groupid+"' AND "
   qry += " PayTypeID=1 UNION select Dat,Amount,+1 As Aus FROM Funds Where "
   qry +=" GroupID='"+ groupid+"' ORDER BY Dat ASC "
   
   print qry
   
   cur = db.cursor()
   # feth payments to teachers , show that with red
   cur.execute(qry)
   rows= cur.fetchall()
   for row in rows:
       print row
       if int(row[2])>0:
           Student_Dates.append(str(row[0]))
           Student_Money.append(float(row[1]))

       else:
           Teacher_Dates.append(str(row[0]))
           Teacher_Money.append(float(row[1]))
            
       
   
   # i want however the union of dates ...
   
    
   x_t = [dt.datetime.strptime(d,'%Y-%m-%d').date() for d in Teacher_Dates]
   x_s = [dt.datetime.strptime(d,'%Y-%m-%d').date() for d in Student_Dates]


   plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d'))
   plt.gca().xaxis.set_major_locator(mdates.DayLocator())
   
   
   plt.plot(x_t, Student_Money,linewidth=2,color='blue',label='TP')
   plt.plot(x_s,Teacher_Money,linewidth=2,color='red',label='FP')



   plt.gcf().autofmt_xdate()  
   plt.show()
    
if __name__ == '__main__':
    main(sys.argv[1])