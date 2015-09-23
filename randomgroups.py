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



for g in xrange(1,8):
    startdate = "01/01/2007"

    for i in xrange(250):
        print g
        startdate = pd.to_datetime(startdate) + pd.DateOffset(days= 5)
        dat = str(startdate)
        dat = dat[:10]  
        sql = "INSERT INTO History ( `GroupID`, `Dat`, `StartHourID`, `Duration`, `RoomID`,  `bw`, `fw`, `fee`) "
        sql+= " VALUES ('"+ str(g) +"','"+ dat +"','"+ str(random.randint(2,19))+"','"+ str(random.choice([1, 1.5, 2.5]))+"','"+ str(random.randint(1,17))+"','12','2','12')"
        print sql
        cur.execute(sql)
db.commit()