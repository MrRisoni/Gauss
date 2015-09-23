# -*- coding: utf-8 -*-
"""
Created on Wed Sep 23 22:11:15 2015

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
print 3/0
# get should pay for each student

sql = "Select G.TeacherID , SUM(Amount) FROM Groups G ,ShouldPay S WHERE S.GroupID = G.GroupID Group BY G.TeacherID "

db = MySQLdb.connect(host="localhost", user='jamie', passwd='jamie', db="Gauss", charset="utf8")

cur = db.cursor()
data = []
cur.execute(sql)
rows=cur.fetchall()
for row in rows:
    data.append([row[0],row[1]])

import pandas as pd

for row in data:
    startdate = "01/01/2007"
    arxiko = row[1]
    left = arxiko
    while left>0:
        amount = random.randint(150,250)
    

        startdate = pd.to_datetime(startdate) + pd.DateOffset(days= random.randint(28,32))
        dat = str(startdate)
        dat = dat[:10]  
        print dat
        left-=amount
        sql = "INSERT INTO `Payments`  (`TeacherID`, `Dat`, `Amount`) VALUES ('"+ str(row[0])+"','"+ dat+"','"+ str(amount)+"')"
        print sql        
        cur.execute(sql)
db.commit()