# -*- coding: utf-8 -*-
"""
Created on Wed Sep 23 19:51:27 2015

@author: linguine
"""

#create 15 English 7 french and 6 de teachers
import MySQLdb
import random

names = []
with open ('/home/linguine/Gauss/female.txt') as fil:
    for line in fil:
        names.append(line.replace('\n',''))
with open ('/home/linguine/Gauss/male.txt') as fil:
    for line in fil:
        names.append(line.replace('\n',''))
        
        


db = MySQLdb.connect(host="localhost", user='jamie', passwd='jamie', db="Gauss", charset="utf8")

cur = db.cursor()

for i in xrange(0,8):
    
    jahr = str(random.randint(1982,1987)) + '-' + str(random.randint(1,12)) + '-' + str(random.randint(2,27))
    
    sql="INSERT INTO `Members` (`Name`, `MembTypeID`, `RegDate`, `BirthDate`) VALUES "
    sql+= "('"+ random.choice(names) +"',1,'2014-01-01','"+ jahr+"')"        
    cur.execute(sql)
    
    

db.commit()