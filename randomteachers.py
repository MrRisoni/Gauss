#create 15 English 7 french and 6 de teachers
import MySQLdb
import random


print 3/0
names = []
with open ('/home/linguine/Gauss/female.txt') as fil:
    for line in fil:
        names.append(line.replace('\n',''))
for n in names:
    print n

db = MySQLdb.connect(host="localhost", user='jamie', passwd='jamie', db="Gauss", charset="utf8")

fache = [9,10,11,12]
cur = db.cursor()
for i in xrange(0,7):
    
    jahr = str(random.randint(1965,1975)) + '-' + str(random.randint(1,12)) + '-' + str(random.randint(2,27))
    sql="INSERT INTO Members  (Name, MembTypeID, RegDate, BirthDate) VALUES ('"+random.choice(names)+"',5,'2007-01-01','"+jahr+"')"
        
    print sql
    cur.execute(sql)
    membid = cur.lastrowid
    
    
    sql="INSERT INTO Contract  (TeacherID, End) VALUES ('"+ str(membid) +"','2016-101-01')"
    print sql    
    cur.execute(sql)
    
    
    
    sql="INSERT INTO Erlaubnis  (TeacherID, StartDat, EndDat, DaysLeft) VALUES ('"+ str(membid)+"','2015-01-01','2015-12-31',20)"
    print sql    
    cur.execute(sql)
    
    
    
    
    sql="INSERT INTO PayKassen  (TeacherID, Dat, Wages) VALUES ('"+  str(membid)+"','2007-01-01','"+ str(random.randint(25,55))+"')"
    print sql    
    cur.execute(sql)
    
    sql="INSERT INTO TeachEchelon (TeacherID, EchelonID, Dat) VALUES ('"+ str(membid)+"',4,'2007-01-01')"
    print sql    
    cur.execute(sql)
    
    for f in fache:
        sql="INSERT INTO TeachFach  (TeacherID, FachID) VALUES ('"+ str(membid)+"','"+ str(f)+"')"
        print sql   
        cur.execute(sql)
    
    
    sql="INSERT INTO Versicherung  (TeacherID, KasseID) VALUES ('"+ str(membid)+"',1)"
    print sql    
    cur.execute(sql)

db.commit()