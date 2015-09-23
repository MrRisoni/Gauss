#create 15 English 7 french and 6 de teachers
import MySqlDb
import random

for i in xrange(0,7):
    
    jahr = str(random.randint(1965-1975)) + '-' + str(random.randint(1-12)) + '-' + str(random.randint(2-27))
    sql="INSERT INTO Members  (Name, MembTypeID, RegDate, BirthDate) VALUES ('"++"',5,2007-01-01,'"+jahr+"')
        
    sql="INSERT INTO Contract(TeacherID, End) VALUES ([value-1],[value-2])
    sql="INSERT INTO Erlaubnis(TeacherID, StartDat, EndDat, DaysLeft) VALUES ([value-1],[value-2],[value-3],[value-4])
    
    
    
    
    sql="INSERT INTO PayKassen(SalID, TeacherID, Dat, Wages) VALUES ([value-1],[value-2],[value-3],[value-4])
    
    sql="INSERT INTO TeachEchelon(TEID, TeacherID, EchelonID, Dat) VALUES ([value-1],[value-2],[value-3],[value-4])
    
    
    sql="INSERT INTO TeachFach(TeacherID, FachID) VALUES ([value-1],[value-2])
    
    
    sql="INSERT INTO Versicherung(SicherID, TeacherID, KasseID, AFM, AMKA) VALUES ([value-1],[value-2],[value-3],[value-4],[value-5])
