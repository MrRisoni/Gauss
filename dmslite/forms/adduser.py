# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'adduser.ui'
#
# Created: Sun May 31 11:43:37 2015
#      by: PyQt4 UI code generator 4.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

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

class Ui_AddUserDialog(object):
    def setupUi(self, AddUserDialog):
        AddUserDialog.setObjectName(_fromUtf8("AddUserDialog"))
        AddUserDialog.resize(485, 238)
        self.label = QtGui.QLabel(AddUserDialog)
        self.label.setGeometry(QtCore.QRect(10, 30, 81, 31))
        self.label.setObjectName(_fromUtf8("label"))
        self.lineName = QtGui.QLineEdit(AddUserDialog)
        self.lineName.setGeometry(QtCore.QRect(120, 30, 221, 31))
        self.lineName.setObjectName(_fromUtf8("lineName"))
        self.pushButton = QtGui.QPushButton(AddUserDialog)
        self.pushButton.setGeometry(QtCore.QRect(360, 30, 100, 31))
        self.pushButton.setObjectName(_fromUtf8("pushButton"))
        self.label_2 = QtGui.QLabel(AddUserDialog)
        self.label_2.setGeometry(QtCore.QRect(10, 90, 81, 31))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.labelADT = QtGui.QLabel(AddUserDialog)
        self.labelADT.setGeometry(QtCore.QRect(130, 90, 81, 31))
        self.labelADT.setObjectName(_fromUtf8("labelADT"))
        self.label_3 = QtGui.QLabel(AddUserDialog)
        self.label_3.setGeometry(QtCore.QRect(10, 130, 81, 41))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.comboRoles = QtGui.QComboBox(AddUserDialog)
        self.comboRoles.setGeometry(QtCore.QRect(120, 140, 241, 24))
        self.comboRoles.setObjectName(_fromUtf8("comboRoles"))
        self.pushAdd = QtGui.QPushButton(AddUserDialog)
        self.pushAdd.setGeometry(QtCore.QRect(360, 180, 100, 31))
        self.pushAdd.setObjectName(_fromUtf8("pushAdd"))

        self.retranslateUi(AddUserDialog)
        QtCore.QMetaObject.connectSlotsByName(AddUserDialog)

    def retranslateUi(self, AddUserDialog):
        AddUserDialog.setWindowTitle(_translate("AddUserDialog", "Add User", None))
        self.label.setText(_translate("AddUserDialog", "Name", None))
        self.pushButton.setText(_translate("AddUserDialog", "Search", None))
        self.label_2.setText(_translate("AddUserDialog", "ADT", None))
        self.labelADT.setText(_translate("AddUserDialog", "ADT", None))
        self.label_3.setText(_translate("AddUserDialog", "Role", None))
        self.pushAdd.setText(_translate("AddUserDialog", "Add", None))

