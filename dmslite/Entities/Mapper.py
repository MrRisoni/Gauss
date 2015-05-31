__author__ = 'linguine'





def getRoles(col):
    return [dok['Name'] for dok in list(col.find())]



def insertUser(col, obj):
    col.insert(obj)
