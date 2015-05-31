__author__ = 'linguine'
import json
from bson.json_util import dumps

class Use:

    def __init__(self,name, adt, role):
        self.Role = role
        self.UsName = ''
        self.UsPass = ''
        self.RealName = name
        self.ADT = adt


    def DocumentToClass(self, MongoDoc , col):
         pass



    def ToDocument(self, db):
        # query the db to get the roleID
        roleID = db.Roles.find_one( { 'Name' : str(self.Role) },{ '_id' : 1})
        fk = str(roleID['_id'])
        print fk
        python_object = { 'RoleID' : fk,
                          'UsName' : '',
                          'UsPass' : '',
                          'RealName' : str(self.RealName),
                          'ADT' : str(self.ADT)
                        }
        json_string = dumps(python_object)
        new_python_object = json.loads(json_string)
        print json_string
        return new_python_object