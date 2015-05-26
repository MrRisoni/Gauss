#extract points from mongodb and create image 
#Input <ADT>
#Output  /tmp/<ADT>.png
#extract pixels from image and save to mongodb  
#Input ADT,/tmp/X.png
#Output  ADT,[],[],[]
import cv2
import sys
import json
from bson.json_util import dumps
from  SetUpMongo import setUpDB
import numpy as np
def main(TeacherID):

     db = setUpDB()

     Dok=db.find_one( { '_id' : int(TeacherID) })
     print Dok
                
                
     X,Y = DocumentToClass(Dok)
     # create a new image with 150 x 60
     blank = np.zeros((60,150,1), np.uint8)
     blank.fill(255)
     
     for row,col in zip(X,Y):
         blank[row][col]=0
     
     #cv2.imshow(str(TeacherID),blank)
     #cv2.waitKey()
     #cv2.destroyAllWindows()
     cv2.imwrite('/tmp/'+ TeacherID +'.png', blank, [cv2.cv.CV_IMWRITE_PNG_COMPRESSION,4])

     



def DocumentToClass(MongoDoc):
   """
   Convert a MongoDB Document to a class
   """
   x = MongoDoc['X']
   y = MongoDoc['Y']
   print x,y
   return x,y

  

if __name__=='__main__':
    main(sys.argv[1])


