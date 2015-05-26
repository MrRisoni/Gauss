#extract pixels from image and save to mongodb  
#Input ADT,/tmp/X.png
#Output  ADT,[],[],[]
import cv2
import sys
import json
from bson.json_util import dumps
from  SetUpMongo import setUpDB

def main(TeacherID,TeacherFace):

    Face = cv2.imread(TeacherFace,0)
    h,w = Face.shape
    print 'rows ' + str(h) + ' cols ' + str(w)
    # binarize the image
    ret,thresed = cv2.threshold(Face,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)

    X = []
    Y = []
    for r in xrange(0,h):
        for c in xrange(0,w):
            if thresed[r][c]==0:
                X.append(r)
                Y.append(c)
                
                
    # print X
    # print Y
                
                
    db = setUpDB()
    db.insert(ToDocument(TeacherID,X, Y))


def ToDocument(TeacherID,x_coords, y_coords):
    try:
        python_object = { '_id' :  int(TeacherID) ,
                 'X' : x_coords,
                 'Y' : y_coords
               
             }
        
        json_string = dumps(python_object)
        new_python_object = json.loads(json_string)
        # print json_string    
        return new_python_object
        
    except Exception as ex:
        print str(ex)
        return ''
  

if __name__=='__main__':
    main(sys.argv[1],sys.argv[2])


