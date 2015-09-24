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
startdate = "01/03/2014"

cur.execute("select StudID FROM Ensembles Where GroupID>12")
rows = cur.fetchall()
studs = []
for row in rows:
    studs.append(row[0])

print len(studs)

for i in xrange(42):
    startdate = pd.to_datetime(startdate) + pd.DateOffset(days= 15)
    dat = str(startdate)
    dat = dat[:10]  
    print dat
    for t in studs:    
        sql = "INSERT INTO `Tests` (`StudID`, `Dat`, `FachID`, `Grade`) VALUES "
        sql+= " ('"+ str(t)+"','"+ dat +"',9,'" + str(random.randint(85,100))+"')"
        print sql
        cur.execute(sql)
        
db.commit()