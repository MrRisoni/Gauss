# -*- coding: utf-8 -*-
"""
Created on Wed Sep 23 20:52:34 2015

@author: linguine
"""

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

cur.execute("select StudID FROM Ensembles Where GroupID>7")
rows = cur.fetchall()
studs = []
for row in rows:
    studs.append(row[0])

print len(studs)

print 3/0


# a small percentage of failure
grades = [ random.randint(75,100) for t in studs]

fail = int ( 8* len(grades) /100 )
print fail
random.shuffle(grades)
for i in xrange(fail):
  grades[i]= random.randint(45,63)  


random.shuffle(grades)


i=0
for t in studs:    
    sql = "INSERT INTO Exam (FachID, ExamDat, StudentID, Grade) "
    sql+= " VALUES (1,'2011-07-15','"+ str(t)+"','"+ str(grades[i])+"')"
    i+=1
    print sql
    cur.execute(sql)
        
db.commit()