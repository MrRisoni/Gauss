# -*- coding: utf-8 -*-
'''
Created on Sun Jun  7 21:26:19 2015

@author: linguine
'''

from pymongo import MongoClient
from datetime import datetime
from bson.objectid import ObjectId

# insert a student

client = MongoClient()
db = client.Friedrich
# http://docs.mongodb.org/getting-started/python/insert/

result = db.Members.insert(

{
  'Name'   : 'John Doe',
  'Address' : 'Xolarogs 56 45623',
  'Mobile'  : '6912345678',
  'Phone' : '1234567890',
  'Father_Name' : 'Hamlet',
  'Mom_Name' :  'Alcmene',
  'Email' :  'john@doe.com',
  'BirthDate' : datetime.strptime("1990-10-01", "%Y-%m-%d"),
  'RegDate' : datetime.utcnow(),
  'ADT' : 'aq456798'
}
)

id=result
print result


result_one = db.Schuler.insert(

{
  '_id' : ObjectId(id), 
  'Father_Mobile' : '6912345678',
  'Mother_Mobile' : '6912345678',
  'Discipline' : ObjectId('5574971dd1459a512f29bb6e'),
  'Class' : 'A',
  'Discounts' :  {
    'Cat' : ObjectId('5574975bd1459a512f29bb6f'),
    'Von' : datetime.strptime("2016-10-01", "%Y-%m-%d"),
    'Bis' : datetime.strptime("2016-10-01", "%Y-%m-%d"),
    
  },
  
  'Absent' :[],
  
  
  
  'Funds' : []
  

})




print 'OK'

''' fetces a student
  db.Schuler.find( { _id: ObjectId('5574983de1382319d47a6fab')});    
  '''

id=result_one
'''
insert into funds


  db.Schuler.update(
     {_id: ObjectId('5574a9e8e138231dbe815c6a')},
     {
     $push: {
       Funds : {
           GroupID : 2,
           Amount : 25.65,
           Dat : new Date()
           
       }
     }
     });
     
     
 FIND SUM OF FUNDS


    

'''
