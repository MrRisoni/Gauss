# -*- coding: utf-8 -*-



#create 15 English 7 french and 6 de teachers
import MySQLdb
import random


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
    #sql = "SELECT SUM(Amount) FROM Payments Where TeacherID='"+ str(row[0])+"' AND PayTypeID=1"
    #cur.execute(sql)
    #records = cur.fetchone()
    #pliromeno = records[0]
    #print pliromeno
    #arxiko = row[1] - pliromeno
    left = row[1]
    while left>0:
        amount = random.randint(450,550)
    

        startdate = pd.to_datetime(startdate) + pd.DateOffset(days= random.randint(28,32))
        dat = str(startdate)
        dat = dat[:10]  
        print dat
        left-=amount
        sql = "INSERT INTO `Payments`  (`TeacherID`, `Dat`, `Amount`) VALUES ('"+ str(row[0])+"','"+ dat+"','"+ str(amount)+"')"
        print sql        
        cur.execute(sql)
db.commit()