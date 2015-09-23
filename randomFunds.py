# -*- coding: utf-8 -*-
"""
Created on Wed Sep 23 19:51:27 2015

@author: linguine
"""

#create 15 English 7 french and 6 de teachers
import MySQLdb
import random

# get should pay for each student

sql = "SELECT StudentID,SUM(Amount) FROM ShouldBePayed GROUP BY StudentID"
print 3/0

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
        amount = random.randint(88,150)
    

        startdate = pd.to_datetime(startdate) + pd.DateOffset(days= random.randint(25,45))
        dat = str(startdate)
        dat = dat[:10]  
        print dat
        left-=amount
        sql = "INSERT INTO `Funds`(`StudentID`, `Dat`, `Amount`) VALUES ('"+ str(row[0]) +"','"+ dat+"','"+ str(amount)+"')"
        print sql
        cur.execute(sql)
db.commit()