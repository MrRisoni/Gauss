# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created: Sun May 31 11:43:29 2015
#      by: PyQt4 UI code generator 4.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
from adduser import  Ui_AddUserDialog
import sys
from pymongo import Connection
from pymongo import MongoClient




try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_MainWindow(object):


    DB = MongoClient()  ## connects by default to db at localhost:27017




    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(877, 477)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.treeView = QtGui.QTreeView(self.centralwidget)
        self.treeView.setGeometry(QtCore.QRect(10, 20, 231, 421))
        self.treeView.setObjectName(_fromUtf8("treeView"))
        self.tableView = QtGui.QTableView(self.centralwidget)
        self.tableView.setGeometry(QtCore.QRect(260, 20, 511, 421))
        self.tableView.setObjectName(_fromUtf8("tableView"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.toolBar = QtGui.QToolBar(MainWindow)
        self.toolBar.setMovable(False)
        self.toolBar.setIconSize(QtCore.QSize(30, 30))
        self.toolBar.setObjectName(_fromUtf8("toolBar"))
        MainWindow.addToolBar(QtCore.Qt.LeftToolBarArea, self.toolBar)
        self.actionAddFile = QtGui.QAction(MainWindow)
        self.actionAddFile.setObjectName(_fromUtf8("actionAddFile"))
        self.actionEditFile = QtGui.QAction(MainWindow)
        self.actionEditFile.setObjectName(_fromUtf8("actionEditFile"))
        self.actionDownloadFile = QtGui.QAction(MainWindow)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/icons/forms/save.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionDownloadFile.setIcon(icon)
        self.actionDownloadFile.setObjectName(_fromUtf8("actionDownloadFile"))
        self.actionCommentFile = QtGui.QAction(MainWindow)
        self.actionCommentFile.setObjectName(_fromUtf8("actionCommentFile"))
        self.actionAddUser = QtGui.QAction(MainWindow)
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(_fromUtf8(":/icons/forms/adduser.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionAddUser.setIcon(icon1)
        self.actionAddUser.setObjectName(_fromUtf8("actionAddUser"))
        self.toolBar.addAction(self.actionAddFile)
        self.toolBar.addAction(self.actionEditFile)
        self.toolBar.addAction(self.actionDownloadFile)
        self.toolBar.addAction(self.actionCommentFile)
        self.toolBar.addAction(self.actionAddUser)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        # slots
        self.actionAddUser.triggered.connect(self.adduser)



    def adduser(self):
        user = QtGui.QDialog()
        user.ui = Ui_AddUserDialog()
        user.ui.DB = self.DB.Friedrich
        user.ui.setupUi(user)
        user.exec_()


    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.toolBar.setWindowTitle(_translate("MainWindow", "toolBar", None))
        self.actionAddFile.setText(_translate("MainWindow", "addFile", None))
        self.actionEditFile.setText(_translate("MainWindow", "editFile", None))
        self.actionDownloadFile.setText(_translate("MainWindow", "downloadFile", None))
        self.actionCommentFile.setText(_translate("MainWindow", "commentFile", None))
        self.actionAddUser.setText(_translate("MainWindow", "addUser", None))

import pigesdms_rc

# pyrcc4 -o pigesdms_rc pigesdms.qrc





def main():

    reload(sys)
    sys.setdefaultencoding('utf-8')
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())


if __name__=="__main__":
    main()

