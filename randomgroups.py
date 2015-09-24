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

studs = []
sql = "SELECT MembID FROM Members Where MembTypeID = 1"
cur.execute(sql)
rows = cur.fetchall()
for row in rows:
    studs.append(row[0])
    
random.shuffle(studs)

groups = [ 13]


import pandas as pd


stop =0
for g in groups:
    '''
    print '--------------'
    maxGroup= random.randint(10,15)
    for i in xrange(stop, stop+maxGroup):
        print studs[i]
    '''
    
    for t in [93,94,95,96,97,98,99,100]:
        sql= " INSERT INTO `ShouldBePayed` (`StudentID`, `Amount`, `GroupID`, `Updated`) "
        sql+= " VALUES ('"+ str(t)+"',0,'"+ str(g)+"','2008-01-01')"
        cur.execute(sql)   
        
        sql = "INSERT INTO `Ensembles`(`GroupID`, `StudID`, `Added`, `Dropped`) "
        sql+= " VALUES ('"+ str(g)+"','"+ str(t)+"','2014-03-11','2016-02-12')"
        cur.execute(sql)   
        
    #stop+=maxGroup        
    


    # end 2011-07-15
    startdate = "03/11/2014"
    
    for i in xrange(211):
    
        startdate = pd.to_datetime(startdate) + pd.DateOffset(days= 5)
        dat = str(startdate)
        dat = dat[:10]  
        print dat
        sql = "INSERT INTO History ( `GroupID`, `Dat`, `StartHourID`, `Duration`, `RoomID`,  `bw`, `fw`, `fee`) "
        sql+= " VALUES ('"+ str(g) +"','"+ dat +"','"+ str(random.randint(2,19))+"','"+ str(random.choice([1.5, 2]))+"','"+ str(random.randint(1,17))+"','12','9','16')"
        print sql
        cur.execute(sql)
db.commit()
