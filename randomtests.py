# -*- coding: utf-8 -*-
"""
Created on Wed Sep 23 19:57:26 2015

@author: linguine
"""

# -*- coding: utf-8 -*-
"""
Created on Wed Sep 23 19:51:27 2015

@author: linguine
"""

#create 15 English 7 french and 6 de teachers
import MySQLdb
import random
import datetime


db = MySQLdb.connect(host="localhost", user='jamie', passwd='jamie', db="Gauss", charset="utf8")

cur = db.cursor()


import pandas as pd
startdate = "01/01/2009"



for i in xrange(35):
    startdate = pd.to_datetime(startdate) + pd.DateOffset(days= 15)
    dat = str(startdate)
    dat = dat[:10]  
    print dat
    for t in xrange(9,90):    
        sql = "INSERT INTO `Tests` (`StudID`, `Dat`, `FachID`, `Grade`) VALUES "
        sql+= " ('"+ str(t)+"','"+ dat +"',1,'" + str(random.randint(65,100))+"')"
        print sql
        cur.execute(sql)
        
db.commit()