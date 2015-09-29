import MySQLdb
db = MySQLdb.connect(host="localhost", user='jamie', passwd='jamie', db="Gauss", charset="utf8")
import random

letters = 'abcdefghijklmnopqrstuvwxyz'
print letters[3]
alle = []

for i in xrange(50000):
  
  adt = ''
  for j in xrange(0,4):
    adt+= letters[random.randint(0,len(letters)-1)]
  
  for j in xrange(0,8):
    adt+= str(random.randint(0,9))
  alle.append(adt.upper())

alle = list(set(alle))

cur = db.cursor()
for i in xrange(1,100):
  sql = "UPDATE Members SET ADT = '"+ alle[i]+"' Where MembID='"+ str(i)+"'";
  cur.execute(sql)
  print sql
db.commit()
