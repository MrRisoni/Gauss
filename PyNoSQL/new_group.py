# -*- coding: utf-8 -*-
"""
Created on Sun Jun  7 23:50:50 2015

@author: linguine
"""
from pymongo import MongoClient
from datetime import datetime
from bson.objectid import ObjectId


client = MongoClient()
db = client.Friedrich


result = db.Groups.insert(

{
  'EndDate' : datetime.utcnow(),
  'Active' : True,
  
  'Schulern' : [{
     'StudentID' :ObjectId('5574982ee1382319cc9bb5dc'),
     'Joined' : datetime.strptime("2015-05-01", "%Y-%m-%d"),
     'Dropped' : datetime.strptime("2015-10-01", "%Y-%m-%d")
    },
    {
     'StudentID' :ObjectId('5574983de1382319d47a6fab'),
     'Joined' : datetime.strptime("2015-05-01", "%Y-%m-%d"),
     'Dropped' : datetime.strptime("2015-10-01", "%Y-%m-%d")
    },
    
    {
     'StudentID' :ObjectId('5574a97ae138231d8f74e3a3'),
     'Joined' : datetime.strptime("2015-05-01", "%Y-%m-%d"),
     'Dropped' : datetime.strptime("2015-10-01", "%Y-%m-%d")
    },
    
    {
     'StudentID' :ObjectId('55752a52e1382308204e650f'),
     'Joined' : datetime.strptime("2015-05-01", "%Y-%m-%d"),
     'Dropped' : datetime.strptime("2015-10-01", "%Y-%m-%d")
    },
  
  
  ],
  


   
  'UpdatedMoney' : datetime.utcnow(),
    
  'ShouldBePayed' : []
  
})

'''
#insert to Shulern

db.Groups.update (
    { _id: ObjectId('55752d89e13823094cdae7e4')},
{
$push : {
       Schulern : {
           StudentID : ObjectId('556ad710e138231d9dd93d4a'),
           Joined : new Date(),
           Dropped : ISODate("2015-10-11")
     }
}
}
)


#insert to Should Pay FROM start of creation

db.Groups.update (
    { _id: ObjectId('55752d89e13823094cdae7e4')},
{
$push : {
       ShouldPay : {
           StudentID : ObjectId('556ad710e138231d9dd93d4a'),
           Amount : 20.45 
     }
}
}


#update dropped






db.Groups.update (
    { _id: ObjectId('55752d89e13823094cdae7e4') ,
    
    Schulern.StudentID : ObjectId('5574982ee1382319cc9bb5dc')

    },
{
$push : {
       ShouldPay : {
           Dropped : ISODate("2015-07-11")
     }
}
}














# update group end date 



update  shouldbepayed 
'''