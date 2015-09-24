# -*- coding: utf-8 -*-
"""
Created on Wed Sep 23 19:51:27 2015

@author: linguine
"""

#create 15 English 7 french and 6 de teachers
import MySQLdb
import random

# get should pay for each student

sql = "SELECT StudentID,SUM(Amount) FROM ShouldBePayed WHERE StudentID>92 GROUP BY StudentID"

db = MySQLdb.connect(host="localhost", user='jamie', passwd='jamie', db="Gauss", charset="utf8")



cur = db.cursor()
data = []
cur.execute(sql)
rows=cur.fetchall()
for row in rows:
    data.append([row[0],row[1]])

import pandas as pd

for row in data:
    #sql = "SELECT SUM(Amount) FROM Funds Where StudentID='"+ str(row[0])+"'"
    #cur.execute(sql)
    #records = cur.fetchone()
    pliromeno = 0 #records[0]
    print pliromeno
    times =0
    startdate = "01/03/2014"
    arxiko = row[1]
    left = arxiko - pliromeno
    while  times<20:
        amount = random.randint(88,150)
        times+=1

        startdate = pd.to_datetime(startdate) + pd.DateOffset(days= random.randint(25,45))
        dat = str(startdate)
        dat = dat[:10]  
        print dat
        left-=amount
        sql = "INSERT INTO `Funds`(`StudentID`, `Dat`, `Amount`) VALUES ('"+ str(row[0]) +"','"+ dat+"','"+ str(amount)+"')"
        print sql
        cur.execute(sql)
db.commit()