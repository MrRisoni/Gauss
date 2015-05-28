-- phpMyAdmin SQL Dump
-- version 4.4.7
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 28, 2015 at 06:27 AM
-- Server version: 10.0.17-MariaDB
-- PHP Version: 5.6.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `Gauss`
--

-- --------------------------------------------------------

--
-- Table structure for table `Absent`
--

CREATE TABLE IF NOT EXISTS `Absent` (
  `AbsID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `HistID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='show when a student was absent';

-- --------------------------------------------------------

--
-- Table structure for table `BaseWages`
--

CREATE TABLE IF NOT EXISTS `BaseWages` (
  `SalID` int(11) NOT NULL,
  `EchelID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `Wages` float NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf32 COMMENT='salaries go according to experience';

--
-- Dumping data for table `BaseWages`
--

INSERT INTO `BaseWages` (`SalID`, `EchelID`, `Dat`, `Wages`) VALUES
(1, 3, '2015-05-10', 7.25),
(2, 2, '2015-05-10', 9.78),
(3, 1, '2015-05-10', 8.67);

-- --------------------------------------------------------

--
-- Table structure for table `Buildings`
--

CREATE TABLE IF NOT EXISTS `Buildings` (
  `BuildID` int(11) NOT NULL,
  `Address` varchar(45) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Buildings`
--

INSERT INTO `Buildings` (`BuildID`, `Address`) VALUES
(1, 'ΜΕΣΣΗΝΙΑΣ ΚΑΙ ΣΟΥΛΙΟΥ 4, ΓΕΡΑΚΑΣ'),
(2, 'ΦΡΑΓΚΟΚΛΗΣΣΙΑΣ 15 , ΜΑΡΟΥΣΙ');

-- --------------------------------------------------------

--
-- Table structure for table `Canceled`
--

CREATE TABLE IF NOT EXISTS `Canceled` (
  `CancID` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL,
  `Dat` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='canceled courses';

-- --------------------------------------------------------

--
-- Table structure for table `Contract`
--

CREATE TABLE IF NOT EXISTS `Contract` (
  `ConID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `End` date NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf32 COMMENT='end date of Contract';

--
-- Dumping data for table `Contract`
--

INSERT INTO `Contract` (`ConID`, `TeacherID`, `End`) VALUES
(16, 23, '2016-05-23'),
(17, 24, '2015-08-12'),
(18, 25, '2016-05-24'),
(19, 26, '2016-05-24'),
(20, 27, '2016-05-25'),
(21, 24, '2016-05-24'),
(22, 28, '2016-05-25'),
(23, 29, '2016-05-25'),
(24, 30, '2016-05-26'),
(25, 36, '2016-05-29');

-- --------------------------------------------------------

--
-- Table structure for table `Courses`
--

CREATE TABLE IF NOT EXISTS `Courses` (
  `CourseID` int(11) NOT NULL,
  `DepID` int(11) NOT NULL,
  `CourseName` varchar(120) NOT NULL,
  `Schwer` tinyint(4) NOT NULL COMMENT 'Schwerigkeit',
  `Active` tinyint(1) NOT NULL DEFAULT '1'
) ENGINE=InnoDB AUTO_INCREMENT=36 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Courses`
--

INSERT INTO `Courses` (`CourseID`, `DepID`, `CourseName`, `Schwer`, `Active`) VALUES
(1, 2, 'ΕΝΕΡΓΕΙΑΚΑ', 10, 1),
(2, 2, 'ΕΙΣΑΓΩΓΗ ΣΤΑ ΣΗΕ', 10, 1),
(3, 1, 'ΜΑΘΗΜΑΤΙΚΑ ΚΑΤΕΥΘΥΝΣΗΣ Γ ΛΥΚΕΙΟΥ', 10, 1),
(4, 1, 'ΑΡΧΕΣ ΔΙΟΙΚΗΣΗΣΗ ΕΠΙΧΕΙΡΗΣΕΩΝ', 11, 1),
(5, 1, 'ΛΑΤΙΝΙΚΑ Γ ΛΥΚΕΙΟΥ', 9, 1),
(6, 1, 'ΛΑΤΙΝΙΚΑ Β ΛΥΚΕΙΟΥ', 10, 1),
(7, 1, 'ΜΑΘΗΜΑΤΙΚΑ ΚΑΤΕΥΘΥΝΣΗΣ Β ΛΥΚΕΙΟΥ', 11, 1),
(8, 1, 'ΗΛΕΚΤΡΟΛΟΓΙΑ', 11, 1),
(9, 1, 'ΑΡΧΕΣ ΟΙΚΟΝΟΜΙΚΗΣ ΘΕΩΡΙΑΣ', 10, 1),
(10, 1, 'ΙΣΤΟΡΙΑ Γ ΛΥΚΕΙΟΥ', 11, 1),
(11, 1, 'ΒΙΟΧΗΜΕΙΑ', 11, 1),
(12, 1, 'ΑΡΧΑΙΑ ΚΑΤΕΥΘΥΝΣΗΣ Γ ΛΥΚΕΙΟΥ', 10, 1),
(13, 1, 'ΜΑΘΗΜΑΤΙΚΑ Γ ΛΥΚΕΙΟΥ ΓΕΝΙΚΗΣ', 11, 1),
(14, 1, 'ΑΡΧΑΙΑ ΚΑΤΕΥΘΥΝΣΗΣ Β ΛΥΚΕΙΟΥ', 13, 1),
(15, 1, ' ΛΟΓΟΤΕΧΝΙΑ ΚΑΤΕΥΘΥΝΗΣΗΣ Β ΛΥΚΕΙΟΥ', 13, 1),
(16, 1, 'ΙΣΤΟΡΙΑ Β ΛΥΚΕΙΟΥ', 11, 1),
(17, 1, 'ΒΙΟΛΟΓΙΑ Γ ΛΥΚΕΙΟΥ', 13, 1),
(18, 1, 'ΒΙΟΛΟΓΙΑ ΚΑΤΕΥΘΥΝΣΗΣ Γ ΛΥΚΕΙΟΥ', 11, 1),
(19, 1, 'ΧΗΜΕΙΑ ΚΑΤΕΥΘΥΝΣΗΣ Γ ΛΥΚΕΙΟΥ', 10, 1),
(20, 1, 'ΧΗΜΕΙΑ ΚΑΤΕΥΘΥΝΣΗΣ Β ΛΥΚΕΙΟΥ', 12, 1),
(21, 2, 'ΜΑΘΗΜΑΤΙΚΑ I', 10, 1),
(22, 2, 'ΜΑΘΗΜΑΤΙΚΑ IΙ', 10, 1),
(23, 2, 'ΜΑΘΗΜΑΤΙΚΑ IΙΙ', 10, 1),
(24, 2, 'ΜΑΘΗΜΑΤΙΚΑ IV', 10, 1),
(25, 2, 'ΔΙΑΦΟΡΙΚΕΣ ΕΞΙΣΏΣΕΙΣ', 13, 1),
(26, 2, 'ΓΡΑΜΜΙΚΗ ΑΛΓΕΒΡΑ', 11, 1),
(27, 2, 'ΑΡΙΘΜΗΤΙΚΗ ΑΝΑΛΥΣΗ', 12, 1),
(28, 1, 'ΕΚΘΕΣΗ Γ ΛΥΚΕΙΟΥ', 11, 1),
(29, 3, 'ΑΛΓΟΡΙΘΜΟΙ', 9, 1),
(30, 3, 'ΣΤΟΧΑΣΤΙΚΕΣ ΔΙΑΔΙΚΑΣΙΕΣ', 10, 1),
(31, 3, 'JAVA', 10, 1),
(32, 3, 'ΕΙΣΑΓΩΓΗ ΣΤΟΝ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟ Ι', 13, 1),
(33, 3, 'ΕΙΣΑΓΩΓΗ ΣΤΟΝ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟ ΙΙ', 11, 1),
(34, 3, 'ΔΟΜΕΣ ΔΕΔΟΜΕΝΩΝ', 11, 1),
(35, 3, 'ΑΡΧΙΤΕΚΤΟΝΙΚΗ ΥΠΟΛΟΓΙΣΤΩΝ', 10, 1);

-- --------------------------------------------------------

--
-- Table structure for table `Days`
--

CREATE TABLE IF NOT EXISTS `Days` (
  `DayID` tinyint(4) NOT NULL,
  `DayName` varchar(18) CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Days`
--

INSERT INTO `Days` (`DayID`, `DayName`) VALUES
(1, 'Sunday'),
(2, 'Monday'),
(3, 'Tuesday'),
(4, 'Wednesday'),
(5, 'Thursday'),
(6, 'Saturday');

-- --------------------------------------------------------

--
-- Table structure for table `Departments`
--

CREATE TABLE IF NOT EXISTS `Departments` (
  `DepID` int(11) NOT NULL,
  `DepName` varchar(55) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Departments`
--

INSERT INTO `Departments` (`DepID`, `DepName`) VALUES
(1, 'Λύκειο'),
(2, 'ΗΛΕΚΤΡΟΛΟΓΟΙ ΜΗΧΑΝΙΚΟΙ'),
(3, 'ΠΛΗΡΟΦΟΡΙΚΗ');

-- --------------------------------------------------------

--
-- Table structure for table `Diplomas`
--

CREATE TABLE IF NOT EXISTS `Diplomas` (
  `DiplID` int(11) NOT NULL,
  `LangID` int(11) NOT NULL,
  `ProvID` int(11) NOT NULL COMMENT 'institut provider',
  `Name` varchar(45) NOT NULL,
  `Schwer` tinyint(4) NOT NULL COMMENT 'higherr is more difficult',
  `Active` tinyint(1) NOT NULL DEFAULT '1'
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf32 COMMENT='diplomas and levels';

--
-- Dumping data for table `Diplomas`
--

INSERT INTO `Diplomas` (`DiplID`, `LangID`, `ProvID`, `Name`, `Schwer`, `Active`) VALUES
(2, 6, 1, 'Zertifikat C2', 10, 1),
(3, 6, 1, 'Zertifikat C1', 9, 1),
(4, 6, 1, 'Zertifikat B2', 11, 1),
(5, 6, 1, 'Zertifikat B1', 13, 1),
(6, 5, 4, 'Dalf SB C2', 10, 1);

-- --------------------------------------------------------

--
-- Table structure for table `DiscData`
--

CREATE TABLE IF NOT EXISTS `DiscData` (
  `StudentID` int(11) NOT NULL,
  `DiscID` tinyint(3) unsigned NOT NULL,
  `MobileFather` varchar(10) NOT NULL,
  `MobileMother` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='discipline of students and phones of parents';

-- --------------------------------------------------------

--
-- Table structure for table `Disciplines`
--

CREATE TABLE IF NOT EXISTS `Disciplines` (
  `DiscID` tinyint(3) unsigned NOT NULL,
  `Name` varchar(22) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `Disciplines`
--

INSERT INTO `Disciplines` (`DiscID`, `Name`) VALUES
(1, 'ΘΕΩΡΗΤΙΚΗ'),
(2, 'ΘΕΤΙΚΗ'),
(3, 'ΤΕΧΝΟΛΟΓΙΚΗ'),
(4, 'ΤΕΧΝΟΛΟΓΙΚΗ-ΠΛΗΡΟΦΟΡΙΚ'),
(5, 'ΤΕΧΝΟΛΟΓΙΚΗ-ΒΙΟΧΗΜΕΙΑ');

-- --------------------------------------------------------

--
-- Table structure for table `Discounts`
--

CREATE TABLE IF NOT EXISTS `Discounts` (
  `DiscID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `CatID` tinyint(3) unsigned NOT NULL,
  `Dat` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='monthly discount only latest value is valid';

-- --------------------------------------------------------

--
-- Table structure for table `Dropout`
--

CREATE TABLE IF NOT EXISTS `Dropout` (
  `GroupID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `Dat` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='a student may decide to drop from a group we need to know when';

-- --------------------------------------------------------

--
-- Table structure for table `Echelon`
--

CREATE TABLE IF NOT EXISTS `Echelon` (
  `EchelID` int(11) NOT NULL,
  `Exp` int(11) NOT NULL COMMENT 'exp in months',
  `Active` tinyint(1) DEFAULT '1'
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COMMENT='categorizee teachers according to experience more experience more wages';

--
-- Dumping data for table `Echelon`
--

INSERT INTO `Echelon` (`EchelID`, `Exp`, `Active`) VALUES
(1, 12, 1),
(2, 24, 1),
(3, 6, 1),
(4, 456, 0);

-- --------------------------------------------------------

--
-- Table structure for table `Ensembles`
--

CREATE TABLE IF NOT EXISTS `Ensembles` (
  `EnsPK` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL,
  `StudID` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Ensembles`
--

INSERT INTO `Ensembles` (`EnsPK`, `GroupID`, `StudID`) VALUES
(2, 8, 35),
(3, 8, 7),
(4, 8, 5),
(5, 8, 1),
(6, 8, 34);

-- --------------------------------------------------------

--
-- Table structure for table `Erlaubnis`
--

CREATE TABLE IF NOT EXISTS `Erlaubnis` (
  `UlrID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `StartDat` date NOT NULL,
  `EndDat` date NOT NULL,
  `DaysLeft` tinyint(4) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf32 COMMENT='days off ';

--
-- Dumping data for table `Erlaubnis`
--

INSERT INTO `Erlaubnis` (`UlrID`, `TeacherID`, `StartDat`, `EndDat`, `DaysLeft`) VALUES
(16, 23, '2015-05-19', '2015-05-19', 15),
(17, 24, '2015-05-20', '2015-05-20', 15),
(18, 25, '2015-05-20', '2015-05-20', 15),
(19, 26, '2015-05-20', '2015-05-20', 15),
(20, 27, '2015-05-21', '2015-05-21', 15),
(21, 28, '2015-05-21', '2015-05-21', 15),
(22, 29, '2015-05-21', '2015-05-21', 15),
(23, 30, '2015-05-22', '2015-05-22', 15),
(24, 36, '2015-05-25', '2015-05-25', 15);

-- --------------------------------------------------------

--
-- Table structure for table `ExamSchule`
--

CREATE TABLE IF NOT EXISTS `ExamSchule` (
  `ExamID` int(11) NOT NULL,
  `CourseID` int(11) NOT NULL,
  `ExamDat` date NOT NULL,
  `StudentID` int(11) NOT NULL,
  `Grade` float NOT NULL COMMENT 'totalaverage grade'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='actual exams  success rates';

-- --------------------------------------------------------

--
-- Table structure for table `ExamSprache`
--

CREATE TABLE IF NOT EXISTS `ExamSprache` (
  `TestID` int(11) NOT NULL,
  `DiplID` int(11) NOT NULL,
  `ExamDat` date NOT NULL,
  `StudentID` int(11) NOT NULL,
  `Grade` float NOT NULL COMMENT 'average pass grade'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='actual foreign language success rates';

-- --------------------------------------------------------

--
-- Table structure for table `Expenses`
--

CREATE TABLE IF NOT EXISTS `Expenses` (
  `ExpID` int(11) NOT NULL,
  `ExpCat` smallint(5) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `Amount` float NOT NULL,
  `Comments` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ExpensesCats`
--

CREATE TABLE IF NOT EXISTS `ExpensesCats` (
  `ExpenseID` smallint(5) unsigned NOT NULL,
  `Description` varchar(200) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ExpensesCats`
--

INSERT INTO `ExpensesCats` (`ExpenseID`, `Description`) VALUES
(1, 'ΔΕΗ'),
(2, 'ΟΤΕ'),
(3, 'ΝΕΡΟ'),
(4, 'ΑΓΟΡΑ ΓΡΑΦΙΚΗΣ ΥΛΗΣ');

-- --------------------------------------------------------

--
-- Table structure for table `FeeSchule`
--

CREATE TABLE IF NOT EXISTS `FeeSchule` (
  `FrSchID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `CourseID` int(11) NOT NULL COMMENT 'not all courses and classes are the same',
  `Fee` float NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `FeeSchule`
--

INSERT INTO `FeeSchule` (`FrSchID`, `Dat`, `CourseID`, `Fee`) VALUES
(1, '2015-05-20', 3, 22),
(2, '2015-05-20', 7, 20),
(3, '2015-05-20', 8, 18),
(4, '2015-05-20', 5, 23),
(5, '2015-05-20', 6, 24),
(6, '2015-05-22', 15, 18),
(7, '2015-05-22', 28, 20),
(8, '2015-05-22', 9, 24);

-- --------------------------------------------------------

--
-- Table structure for table `FeeSprache`
--

CREATE TABLE IF NOT EXISTS `FeeSprache` (
  `FspID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `SchedID` int(11) NOT NULL,
  `Fee` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='each schedule has a different fare';

-- --------------------------------------------------------

--
-- Table structure for table `FeeUni`
--

CREATE TABLE IF NOT EXISTS `FeeUni` (
  `FareID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `CourseID` int(11) NOT NULL COMMENT 'not all course have the same fee e.g. very difficult courses have higher fees',
  `Fee` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Funds`
--

CREATE TABLE IF NOT EXISTS `Funds` (
  `FundID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `Amount` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='money we received from students';

-- --------------------------------------------------------

--
-- Table structure for table `Groups`
--

CREATE TABLE IF NOT EXISTS `Groups` (
  `GroupID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `CourseID` int(11) NOT NULL,
  `StartDate` date NOT NULL,
  `Active` tinyint(4) NOT NULL DEFAULT '1',
  `LessTypeID` tinyint(4) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Groups`
--

INSERT INTO `Groups` (`GroupID`, `TeacherID`, `CourseID`, `StartDate`, `Active`, `LessTypeID`) VALUES
(8, 28, 28, '2015-05-23', 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `History`
--

CREATE TABLE IF NOT EXISTS `History` (
  `HistID` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `StartHourID` tinyint(4) NOT NULL,
  `Duration` float NOT NULL,
  `RoomID` tinyint(4) NOT NULL COMMENT 'roomid=0 gia ta monima '
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Hours`
--

CREATE TABLE IF NOT EXISTS `Hours` (
  `HourID` tinyint(4) NOT NULL COMMENT 'id represents the cell row',
  `HourN` varchar(4) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Hours`
--

INSERT INTO `Hours` (`HourID`, `HourN`) VALUES
(1, '0830'),
(2, '0900'),
(3, '0930'),
(4, '1000'),
(5, '1030'),
(6, '1100'),
(7, '1130'),
(8, '1200'),
(9, '1230'),
(10, '1300'),
(11, '1330'),
(12, '1400'),
(13, '1430'),
(14, '1500'),
(15, '1530'),
(16, '1600'),
(17, '1630'),
(18, '1700'),
(19, '1730'),
(20, '1800'),
(21, '1830'),
(22, '1900'),
(23, '1930'),
(24, '2000'),
(25, '2030'),
(26, '2100'),
(27, '2130'),
(28, '2200'),
(29, '2230');

-- --------------------------------------------------------

--
-- Table structure for table `Instituts`
--

CREATE TABLE IF NOT EXISTS `Instituts` (
  `InstID` int(11) NOT NULL,
  `Name` varchar(60) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf32 COMMENT='foreign language instituts';

--
-- Dumping data for table `Instituts`
--

INSERT INTO `Instituts` (`InstID`, `Name`) VALUES
(1, 'Goethe'),
(2, 'Cambridge'),
(3, 'Michigan'),
(4, 'Sorbonne');

-- --------------------------------------------------------

--
-- Table structure for table `Kassen`
--

CREATE TABLE IF NOT EXISTS `Kassen` (
  `KasseID` int(11) NOT NULL,
  `Name` varchar(20) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COMMENT='versicherungskasse';

--
-- Dumping data for table `Kassen`
--

INSERT INTO `Kassen` (`KasseID`, `Name`) VALUES
(1, 'ΙΚΑ'),
(2, 'ΤΕΒΕ'),
(3, 'ΟΓΑ'),
(4, 'ΤΣΜΕΔΕ');

-- --------------------------------------------------------

--
-- Table structure for table `Languages`
--

CREATE TABLE IF NOT EXISTS `Languages` (
  `LangID` int(11) NOT NULL,
  `Name` varchar(12) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Languages`
--

INSERT INTO `Languages` (`LangID`, `Name`) VALUES
(4, 'Αγγλικά'),
(5, 'Γαλλικά'),
(6, 'Γερμανικά'),
(7, 'Ολλανδικά'),
(8, 'Ισπανικά'),
(9, 'Ιταλικά'),
(10, 'Αραβικά'),
(11, 'Κινέζικα');

-- --------------------------------------------------------

--
-- Table structure for table `LessonType`
--

CREATE TABLE IF NOT EXISTS `LessonType` (
  `TypeID` tinyint(4) NOT NULL,
  `Description` varchar(10) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `LessonType`
--

INSERT INTO `LessonType` (`TypeID`, `Description`) VALUES
(1, 'Schule'),
(2, 'Uni'),
(3, 'Sprache'),
(4, 'Skype');

-- --------------------------------------------------------

--
-- Table structure for table `Members`
--

CREATE TABLE IF NOT EXISTS `Members` (
  `MembID` int(11) NOT NULL,
  `Name` varchar(80) CHARACTER SET utf8 NOT NULL,
  `FName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `MName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `Address` varchar(80) CHARACTER SET utf8 NOT NULL,
  `Phone` varchar(10) CHARACTER SET utf8 NOT NULL,
  `Mobile` varchar(10) CHARACTER SET utf8 NOT NULL,
  `EMail` varchar(50) CHARACTER SET utf8 NOT NULL,
  `MembTypeID` tinyint(11) DEFAULT NULL,
  `RegDate` date DEFAULT NULL,
  `BirthDate` date NOT NULL,
  `TotHours` float NOT NULL DEFAULT '0',
  `TotPaidHours` float NOT NULL DEFAULT '0' COMMENT 'pososto tot hours poy exoun plirwthei / xrwstane',
  `ADT` varchar(8) CHARACTER SET utf8 NOT NULL COMMENT 'ausweisID'
) ENGINE=InnoDB AUTO_INCREMENT=37 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Members`
--

INSERT INTO `Members` (`MembID`, `Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `TotHours`, `TotPaidHours`, `ADT`) VALUES
(1, 'ΠΑΡΙΣΗΣ ΝΙΚΟΛΑΟΣ', 'dfdfdf', 'dffdfd', 'dfdfdf', 'dfdfd', 'dfdfd', 'dfdfd????', 2, '2015-04-21', '1997-05-01', 0, 0, 'GZ458903'),
(2, 'ΔΕΔΕΔΑΚΗ ΕΛΕΝΗ', '????', '??????', '?????', '??', '???', '?????', 1, '2015-04-21', '1990-08-21', 0, 0, 'AX890433'),
(3, 'ΣΙΜΟΥ ΦΛΩΡΑ', 'γφγφ', 'γφγφγ', 'γφγφ', 'φγφγφ', 'γφγφ', 'γφγφγφ', 1, '2015-04-21', '1970-01-01', 0, 0, 'ZJ458902'),
(4, 'Φράγκος Άρης', 'Πέτρος', 'Σοφία', 'Ζαβλάνι 12', '2610773601', '6947128400', 'arisf@gmail.com', 1, '2015-04-21', '1970-01-01', 0, 0, 'KQ500734'),
(5, 'ΠΑΠΑΔΟΠΟΥΛΟΣ ΣΠΥΡΟΣ', 'Κωνσταντίνος', 'Ακριβή', '1212', 'δφγ', 'δφ', '1212121', 2, '2015-04-20', '1998-12-22', 0, 0, 'QJ563312'),
(6, 'Μπισδίκης Χρήστος', 'Ανδρέας', 'Άννα', 'Φραγκοκλησσιάς 8 , Μαρούσι', '2107882431', '6956009812', 'bischris@gmail.com', 1, '2015-04-21', '1991-08-09', 0, 0, 'LP563478'),
(7, 'ΓΙΑΒΟΡΔΙΟΣ ΕΛΕΥΘΕΡΙΟΣ', 'ΚΩΝΣΤΑΝΤΙΝΟΣ', 'ΜΑΡΙΑ', 'ΜΕΣΣΗΝΙΑΣ 14 ΓΕΡΑΚΑΣ', '2122424', '46464', 'giavord@hotmail.com', 2, '2015-05-13', '1999-10-22', 0, 0, 'YR348754'),
(23, 'ΔΗΜΑΝΚΗ ΑΙΚΑΤΕΡΙΝΗ', 'ΓΕΩΡΓΙΟΣ', 'ΣΟΦΙΑ', 'ΙΩΝΙΑΣ 45 ΓΕΡΑΚΑΣ', '2103015578', '6901989317', 'dimanki@gmail.com', 5, '2015-05-19', '1981-05-19', 0, 0, 'GK798191'),
(24, 'ΜΟΛΛΑ ΕΙΡΗΝΗ', 'ΖΩΗΣ', 'ΕΥΘΥΜΙΑ', ' ΑΓΙΑΣ ΛΑΥΡΑΣ 24 ΑΓΙΑ ΠΑΡΑΣΚΕΥΗ', '2108019893', '6917070336', 'mollair@gmail.com', 5, '2015-05-20', '1980-06-18', 0, 0, 'TX301557'),
(25, 'ΔΗΜΑ ΑΙΚΑΤΕΡΙΝΗ', 'ΠΕΤΡΟΣ', 'ΑΛΕΞΑΝΔΡΑ', 'ΜΕΓΑ ΒΑΣΙΛΕΙΟΥ 45 ΚΙΦΗΣΙΑΣ', '2105780198', '6993170703', 'katjadima@gmail.com', 5, '2015-05-20', '1984-06-30', 0, 0, 'ST913015'),
(26, 'ΙΩΑΝΝΑ ΘΕΟΔΩΡΟΥ', 'ΠΑΝΑΓΙΩΤΗΣ', 'ΝΕΚΤΑΡΙΑ', 'ΙΩΣΗΦΙΝΑΣ 45,ΠΑΛΛΗΝΗ', '2101557801', '6998931707', 'theoio@gmail.com', 5, '2015-05-20', '1986-04-07', 0, 0, 'RZ819130'),
(27, 'ΜΑΛΕΝΑ ΤΣΟΠΑΝΙΔΟΥ', 'ΙΩΑΝΝΗΣ', 'ELENA', 'ΑΡΓΟΥΣ 34,ΑΓΙΑ ΠΑΡΑΣΚΕΥΗ', '2101557801', '6998931707', 'tsopmalena@hotmail.com', 5, '2015-05-21', '1988-04-19', 0, 0, 'RZ819130'),
(28, 'ΑΛΕΞΑΝΔΡΑ ΠΑΛΑΙΟΛΟΓΟΥ', 'ΘΕΟΦΡΑΣΤΟΣ', 'ΑΓΛΑΙΑ', 'ΜΕΣΣΟΠΟΤΑΜΙΑΣ 56 ΘΡΑΚΟΜΑΚΕΔΟΝΕΣ', '2101557801', '6998931707', 'palaiolalexia@gmail.com', 5, '2015-05-21', '1984-06-19', 0, 0, 'RZ819130'),
(29, 'ΕΥΓΕΝΙΑ ΑΜΑΛΙΑΔΟΥ', 'ΘΕΟΔΟΣΙΟΣ', 'ΑΝΝΑ', 'ΚΟΛΟΚΥΝΘΟΥΣ 56 , ΜΑΡΟΥΣΙ', '2105780198', '6993170703', 'euegeamal@gmail.com', 5, '2015-05-21', '1984-03-14', 0, 0, 'ST913015'),
(30, 'ΛΗΝΑ ΒΑΛΜΑΣ', 'ΙΩΑΝΝΗΣ', 'ΑΔΑΜΑΝΤΙΑ', 'ΜΠΟΥΜΠΟΥΛΙΝΑΣ 45 , ΧΟΛΑΡΓΟΣ', '2101557801', '6998931707', 'valmas@gmail.com', 5, '2015-05-22', '1979-05-17', 0, 0, 'RZ819130'),
(34, 'ΕΛΕΥΘΕΡΙΑ ΑΝΑΣΤΑΣΟΠΟΥΛΟΥ', 'ΠΟΛΥΠΈΡΧΩΝ', 'ΞΕΝΊΑ', 'ΣΤΑΘΑ 15, ΑΘΗΝΑ', '2108179831', '6926798191', 'anastasop@gmail.com', 2, '2015-05-23', '1999-04-07', 0, 0, 'RK155780'),
(35, 'ΑΔΑΜΑΝΤΙΟΣ ΚΟΡΑΗΣ', 'ΑΝΆΡΓΥΡΟΣ', 'ΘΕΟΔΟΣΊΑ', 'ΜΥΡΙΟΦΥΤΟΥ 45 ,ΑΙΓΑΛΕΩ', '2107983126', '6979819130', 'korais@gmail.com', 2, '2015-05-23', '1997-03-02', 0, 0, 'NR578019'),
(36, 'ΜΑΙΡΗ ΣΟΥΙΦΤ', 'JACOB', 'ΕΛΙΣΣΑΒΕΤ', 'ΟΘΩΝΑΣ 56 , ΟΜΟΝΟΙΑ', '2105780198', '6993170703', '', 5, '2015-05-25', '1983-07-22', 0, 0, 'ST913015');

-- --------------------------------------------------------

--
-- Table structure for table `MembTypes`
--

CREATE TABLE IF NOT EXISTS `MembTypes` (
  `MembTypeID` tinyint(11) NOT NULL,
  `MembTypeName` varchar(20) CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `MembTypes`
--

INSERT INTO `MembTypes` (`MembTypeID`, `MembTypeName`) VALUES
(1, 'Φοιτητής'),
(2, 'Μαθητής'),
(3, 'Γραμματεία'),
(4, 'Διευθυντής'),
(5, 'Καθηγητής');

-- --------------------------------------------------------

--
-- Table structure for table `PayKassen`
--

CREATE TABLE IF NOT EXISTS `PayKassen` (
  `SalID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `Wages` float NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf32 COMMENT='how much money we will pay each month for health insurance';

--
-- Dumping data for table `PayKassen`
--

INSERT INTO `PayKassen` (`SalID`, `TeacherID`, `Dat`, `Wages`) VALUES
(16, 23, '2015-05-19', 34.45),
(17, 24, '2015-05-20', 25),
(18, 25, '2015-05-20', 23.56),
(19, 26, '2015-05-20', 9.45),
(20, 27, '2015-05-21', 12.78),
(21, 28, '2015-05-21', 9.78),
(22, 29, '2015-05-21', 34.45),
(23, 30, '2015-05-22', 29.67),
(24, 36, '2015-05-25', 12.34);

-- --------------------------------------------------------

--
-- Table structure for table `Payments`
--

CREATE TABLE IF NOT EXISTS `Payments` (
  `PayID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `Amount` float unsigned NOT NULL,
  `Comments` varchar(100) DEFAULT NULL COMMENT 'what did we pay him for?',
  `PayTypeID` tinyint(3) unsigned NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf32 COMMENT='payments to professors';

--
-- Dumping data for table `Payments`
--

INSERT INTO `Payments` (`PayID`, `TeacherID`, `Dat`, `Amount`, `Comments`, `PayTypeID`) VALUES
(1, 23, '2015-05-24', 34.34, NULL, 3),
(2, 24, '2015-05-24', 21.78, NULL, 3),
(3, 25, '2015-05-24', 89.45, NULL, 3),
(4, 26, '2015-05-24', 289.45, NULL, 3),
(5, 27, '2015-05-24', 12.34, NULL, 3),
(6, 28, '2015-05-24', 36.78, NULL, 3),
(7, 29, '2015-05-24', 4.56, NULL, 3),
(8, 30, '2015-05-24', 14.26, NULL, 3),
(9, 30, '2015-05-24', 14.26, NULL, 3),
(10, 27, '2015-05-24', 2.34, NULL, 3),
(11, 29, '2015-05-24', 0.34, NULL, 3);

-- --------------------------------------------------------

--
-- Table structure for table `PayType`
--

CREATE TABLE IF NOT EXISTS `PayType` (
  `PayTypeID` tinyint(3) unsigned NOT NULL,
  `Comment` varchar(50) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COMMENT='describes the type of payment';

--
-- Dumping data for table `PayType`
--

INSERT INTO `PayType` (`PayTypeID`, `Comment`) VALUES
(1, 'ΜΗΝΙΑΤΙΚΟ'),
(2, 'ΔΩΡΟ'),
(3, 'ΑΣΦΑΛΙΣΗ');

-- --------------------------------------------------------

--
-- Table structure for table `Permament`
--

CREATE TABLE IF NOT EXISTS `Permament` (
  `PermaID` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL DEFAULT '0',
  `DayID` tinyint(4) NOT NULL,
  `HourID` tinyint(4) NOT NULL,
  `RoomID` tinyint(4) NOT NULL,
  `StartsOn` date NOT NULL,
  `EndsOn` date NOT NULL,
  `Active` tinyint(4) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='uni and schule courses that take part every week ';

-- --------------------------------------------------------

--
-- Table structure for table `Receipts`
--

CREATE TABLE IF NOT EXISTS `Receipts` (
  `ReceiptID` int(11) NOT NULL,
  `TypeID` tinyint(3) unsigned NOT NULL,
  `PersonID` int(11) NOT NULL COMMENT 'which of our member signed the receipt',
  `EmployerID` tinyint(11) unsigned NOT NULL COMMENT 'which employer signed the receipt',
  `Date` date NOT NULL,
  `Money` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ReceiptType`
--

CREATE TABLE IF NOT EXISTS `ReceiptType` (
  `TypeID` tinyint(3) unsigned NOT NULL,
  `Description` varchar(25) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ReceiptType`
--

INSERT INTO `ReceiptType` (`TypeID`, `Description`) VALUES
(1, 'ΕΙΣΠΡΑΞΗ'),
(2, 'ΠΛΗΡΩΜΗ');

-- --------------------------------------------------------

--
-- Table structure for table `RequestSchule`
--

CREATE TABLE IF NOT EXISTS `RequestSchule` (
  `RequestID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `CourseID` int(6) NOT NULL,
  `Settled` tinyint(4) NOT NULL DEFAULT '0' COMMENT '0 unsettled 1 settled 2 closed group',
  `ReqDate` date NOT NULL,
  `Comments` text NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `RequestSchule`
--

INSERT INTO `RequestSchule` (`RequestID`, `StudentID`, `CourseID`, `Settled`, `ReqDate`, `Comments`) VALUES
(2, 7, 8, 0, '2015-05-20', ''),
(3, 5, 8, 0, '2015-05-20', ''),
(4, 7, 7, 0, '2015-05-20', ''),
(5, 35, 12, 0, '2015-05-23', ''),
(6, 35, 17, 0, '2015-05-23', ''),
(7, 35, 28, 1, '2015-05-23', ''),
(8, 35, 10, 0, '2015-05-23', ''),
(9, 35, 5, 0, '2015-05-23', ''),
(10, 7, 17, 0, '2015-05-23', ''),
(11, 7, 28, 1, '2015-05-23', ''),
(12, 7, 10, 0, '2015-05-23', ''),
(13, 5, 10, 0, '2015-05-23', ''),
(14, 5, 28, 1, '2015-05-23', ''),
(15, 1, 28, 1, '2015-05-23', ''),
(16, 1, 12, 0, '2015-05-23', ''),
(17, 34, 12, 0, '2015-05-23', ''),
(18, 34, 17, 0, '2015-05-23', ''),
(19, 34, 28, 1, '2015-05-23', ''),
(20, 34, 5, 0, '2015-05-23', ''),
(21, 34, 13, 0, '2015-05-23', '');

-- --------------------------------------------------------

--
-- Table structure for table `RequestSprache`
--

CREATE TABLE IF NOT EXISTS `RequestSprache` (
  `RequestID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `ScheduleID` int(11) NOT NULL,
  `Settled` tinyint(4) NOT NULL DEFAULT '0' COMMENT '0 unsettled 1 settled 2 closed group',
  `ReqDate` date NOT NULL,
  `Comments` varchar(300) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `RequestUni`
--

CREATE TABLE IF NOT EXISTS `RequestUni` (
  `RequestID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `CourseID` int(11) NOT NULL,
  `Settled` tinyint(4) NOT NULL DEFAULT '0' COMMENT '0 unsettled 1 settled 2 closed group',
  `ReqDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Roles`
--

CREATE TABLE IF NOT EXISTS `Roles` (
  `RoleID` tinyint(3) unsigned NOT NULL,
  `Description` varchar(20) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `Roles`
--

INSERT INTO `Roles` (`RoleID`, `Description`) VALUES
(1, 'ΓΡΑΜΜΑΤΕΑΣ'),
(2, 'ΔΙΕΥΘΥΝΤΗΣ');

-- --------------------------------------------------------

--
-- Table structure for table `Rooms`
--

CREATE TABLE IF NOT EXISTS `Rooms` (
  `RoomID` tinyint(4) NOT NULL,
  `BuildID` int(4) NOT NULL,
  `Name` varchar(15) NOT NULL,
  `Capacity` tinyint(4) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Rooms`
--

INSERT INTO `Rooms` (`RoomID`, `BuildID`, `Name`, `Capacity`) VALUES
(1, 1, 'ΛΗΤΩ', 12),
(2, 1, 'ΗΛΕΚΤΡΑ', 4),
(3, 1, 'ΣΑΠΦΩ', 15),
(4, 1, 'ΑΘΗΝΑ', 7),
(5, 1, 'ΔΗΜΗΤΡΑ', 9),
(6, 1, 'ΚΑΣΣΑΝΔΡΑ', 12),
(7, 2, 'ΠΛΟΥΤΩΝΑΣ', 9),
(8, 2, 'ΑΦΡΟΔΙΤΗ', 13),
(9, 2, 'ΞΕΝΟΦΩΝΤΑΣ', 5),
(10, 2, 'ΑΝΔΡΟΜΑΧΗ', 9);

-- --------------------------------------------------------

--
-- Table structure for table `Schedule`
--

CREATE TABLE IF NOT EXISTS `Schedule` (
  `SchedID` int(11) NOT NULL,
  `Active` tinyint(4) NOT NULL DEFAULT '1',
  `AgeLow` tinyint(4) NOT NULL COMMENT 'age group',
  `AgeTop` tinyint(4) NOT NULL,
  `Comments` varchar(180) NOT NULL COMMENT 'other comments',
  `Title` varchar(60) NOT NULL,
  `DiploID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='there are of course different schedules for learning lanuages';

-- --------------------------------------------------------

--
-- Table structure for table `Schwierigkeit`
--

CREATE TABLE IF NOT EXISTS `Schwierigkeit` (
  `SchwerID` tinyint(4) NOT NULL,
  `Red` tinyint(6) unsigned NOT NULL,
  `Green` tinyint(6) unsigned NOT NULL,
  `Blue` tinyint(6) unsigned NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf32 COMMENT='color for different difficulty levels from 0 to 10';

--
-- Dumping data for table `Schwierigkeit`
--

INSERT INTO `Schwierigkeit` (`SchwerID`, `Red`, `Green`, `Blue`) VALUES
(9, 255, 23, 127),
(10, 255, 0, 0),
(11, 255, 255, 0),
(12, 0, 255, 127),
(13, 85, 85, 255);

-- --------------------------------------------------------

--
-- Table structure for table `SpecialCats`
--

CREATE TABLE IF NOT EXISTS `SpecialCats` (
  `SpecialID` tinyint(3) unsigned NOT NULL,
  `Description` varchar(30) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COMMENT='ειδικές κατηγορίες : πχ τριτεκνοι ορφανα ';

--
-- Dumping data for table `SpecialCats`
--

INSERT INTO `SpecialCats` (`SpecialID`, `Description`) VALUES
(1, 'ΤΡΙΤΕΚΝΟΙ'),
(2, 'ΠΟΛΥΤΕΚΝΟΙ'),
(3, 'ΟΡΦΑΝΑ'),
(4, 'ΑΝΑΠΗΡΙΑ');

-- --------------------------------------------------------

--
-- Table structure for table `TeachEchelon`
--

CREATE TABLE IF NOT EXISTS `TeachEchelon` (
  `TEID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `EchelonID` int(11) NOT NULL,
  `Dat` date NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8 COMMENT='assigns a teacher to an echelon id it can be updated over ti';

--
-- Dumping data for table `TeachEchelon`
--

INSERT INTO `TeachEchelon` (`TEID`, `TeacherID`, `EchelonID`, `Dat`) VALUES
(1, 23, 3, '2015-05-28'),
(2, 24, 2, '2015-05-28'),
(3, 25, 1, '2015-05-28'),
(4, 26, 3, '2015-05-28'),
(5, 27, 1, '2015-05-28'),
(6, 28, 2, '2015-05-28'),
(7, 29, 2, '2015-05-28'),
(8, 30, 2, '2015-05-28'),
(9, 36, 1, '2015-05-28');

-- --------------------------------------------------------

--
-- Table structure for table `TeachOther`
--

CREATE TABLE IF NOT EXISTS `TeachOther` (
  `TTID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `CourseID` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=60 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `TeachOther`
--

INSERT INTO `TeachOther` (`TTID`, `TeacherID`, `CourseID`) VALUES
(4, 23, 3),
(5, 23, 7),
(6, 23, 8),
(7, 24, 3),
(8, 24, 7),
(9, 24, 8),
(10, 25, 3),
(11, 25, 7),
(12, 25, 8),
(13, 25, 1),
(14, 25, 2),
(15, 26, 5),
(16, 26, 6),
(17, 26, 12),
(18, 26, 10),
(19, 27, 3),
(20, 27, 9),
(21, 27, 4),
(22, 27, 7),
(23, 27, 13),
(24, 28, 5),
(25, 28, 6),
(26, 28, 12),
(27, 28, 10),
(28, 28, 16),
(29, 28, 14),
(30, 28, 15),
(31, 29, 3),
(32, 29, 7),
(33, 29, 11),
(34, 29, 13),
(35, 30, 5),
(36, 30, 3),
(37, 30, 6),
(38, 30, 7),
(39, 30, 8),
(40, 30, 13),
(41, 30, 1),
(42, 30, 2),
(43, 30, 21),
(44, 30, 22),
(45, 30, 23),
(46, 30, 24),
(47, 30, 26),
(48, 30, 27),
(49, 30, 25),
(50, 26, 28),
(51, 28, 28),
(52, 36, 5),
(53, 36, 6),
(54, 36, 12),
(55, 36, 10),
(56, 36, 16),
(57, 36, 28),
(58, 36, 14),
(59, 36, 15);

-- --------------------------------------------------------

--
-- Table structure for table `TeachSprache`
--

CREATE TABLE IF NOT EXISTS `TeachSprache` (
  `SPID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `DiplomaID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='welche Sprachen kann ein Lehrer lehren?';

-- --------------------------------------------------------

--
-- Table structure for table `TestSchule`
--

CREATE TABLE IF NOT EXISTS `TestSchule` (
  `TestSpID` int(11) NOT NULL,
  `StudID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `CourseID` int(11) NOT NULL,
  `Grade` float NOT NULL COMMENT 'from 0 to 100'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='in house tests aka student progress';

-- --------------------------------------------------------

--
-- Table structure for table `TestSprache`
--

CREATE TABLE IF NOT EXISTS `TestSprache` (
  `TestSpID` int(11) NOT NULL,
  `StudID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `ScheduleID` int(11) NOT NULL,
  `Grade` float NOT NULL COMMENT 'from 0 to 100'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='in house tests aka student progress';

-- --------------------------------------------------------

--
-- Table structure for table `Times`
--

CREATE TABLE IF NOT EXISTS `Times` (
  `TimesID` int(11) NOT NULL,
  `SchedID` int(11) NOT NULL,
  `DayID` tinyint(4) NOT NULL,
  `HourID` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='schedule hours and days';

-- --------------------------------------------------------

--
-- Table structure for table `TrainingSprache`
--

CREATE TABLE IF NOT EXISTS `TrainingSprache` (
  `ExID` int(11) NOT NULL,
  `TeachID` int(11) NOT NULL COMMENT 'if class is yes that is the correspondent teacherid',
  `Age` float NOT NULL,
  `Native` tinyint(4) NOT NULL COMMENT '0 not native 1 native speaker ',
  `Sprachen` tinyint(4) NOT NULL,
  `EduDegrees` float NOT NULL,
  `EduQuality` float NOT NULL,
  `Msc` tinyint(4) NOT NULL COMMENT 'number of msc diplomas',
  `Seminars` tinyint(4) NOT NULL COMMENT 'number of seminars ',
  `SprachDegrees` float NOT NULL COMMENT 'average degree of foreign language diplomas',
  `TeachYears` float NOT NULL COMMENT 'teaching years',
  `Ausland` float NOT NULL COMMENT 'year in a foreign country',
  `Interview` float NOT NULL,
  `Exams` float NOT NULL,
  `Class` tinyint(4) NOT NULL COMMENT '1 hire -1 no hire'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='A training set for employing foreign language';

-- --------------------------------------------------------

--
-- Table structure for table `TrainingUni`
--

CREATE TABLE IF NOT EXISTS `TrainingUni` (
  `ExampleID` int(11) NOT NULL,
  `Age` float NOT NULL,
  `Degrees` float NOT NULL,
  `Msc` tinyint(4) NOT NULL COMMENT 'number of msc',
  `PhD` tinyint(4) NOT NULL COMMENT '1 has a phd 0  no phd',
  `Years` float NOT NULL COMMENT 'teaching years',
  `Interview` float NOT NULL,
  `Exams` float NOT NULL,
  `Class` tinyint(4) NOT NULL COMMENT '1 hire -1 no hire'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='A training set for employing university';

-- --------------------------------------------------------

--
-- Table structure for table `Unavailable`
--

CREATE TABLE IF NOT EXISTS `Unavailable` (
  `UnavailID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `DayID` tinyint(4) NOT NULL,
  `HourID` tinyint(4) NOT NULL,
  `Duration` float unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='days which the prof is unavailable';

-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE IF NOT EXISTS `Users` (
  `UserID` tinyint(3) unsigned NOT NULL,
  `UsName` varchar(20) NOT NULL,
  `UsPass` varchar(100) NOT NULL,
  `RoleID` tinyint(3) unsigned NOT NULL,
  `Name` varchar(90) NOT NULL,
  `ADT` varchar(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Versicherung`
--

CREATE TABLE IF NOT EXISTS `Versicherung` (
  `SicherID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `KasseID` int(11) NOT NULL,
  `AFM` varchar(9) NOT NULL,
  `AMKA` varchar(12) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `Versicherung`
--

INSERT INTO `Versicherung` (`SicherID`, `TeacherID`, `KasseID`, `AFM`, `AMKA`) VALUES
(14, 23, 1, '8179831', ''),
(15, 24, 4, '1267981', ''),
(16, 25, 4, '8312679', ''),
(17, 26, 1, '7983126', ''),
(18, 27, 3, '7983126', ''),
(19, 28, 3, '7983126', ''),
(20, 29, 2, '8312679', ''),
(21, 30, 4, '7983126', ''),
(22, 36, 3, '8312679', '');

-- --------------------------------------------------------

--
-- Table structure for table `WagesSchule`
--

CREATE TABLE IF NOT EXISTS `WagesSchule` (
  `WagesSchuleID` int(11) NOT NULL,
  `EchelID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `CourseID` int(11) NOT NULL COMMENT 'not all courses and classes are the same',
  `Wage` float NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=24 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `WagesSchule`
--

INSERT INTO `WagesSchule` (`WagesSchuleID`, `EchelID`, `Dat`, `CourseID`, `Wage`) VALUES
(9, 3, '2015-05-13', 3, 0.87),
(10, 1, '2015-05-13', 3, 1),
(11, 2, '2015-05-13', 3, 1.8),
(12, 2, '2015-05-15', 5, 2.25),
(13, 1, '2015-05-15', 5, 1.76),
(14, 2, '2015-05-15', 6, 2),
(15, 3, '2015-05-15', 6, 0.45),
(16, 3, '2015-05-15', 7, 0.45),
(17, 3, '2015-05-15', 8, 0.23),
(18, 3, '2015-05-20', 12, 0.12),
(19, 2, '2015-05-20', 12, 2.56),
(20, 2, '2015-05-20', 9, 1.28),
(21, 3, '2015-05-22', 28, 0.12),
(22, 1, '2015-05-22', 28, 0.42),
(23, 2, '2015-05-22', 28, 0.98);

-- --------------------------------------------------------

--
-- Table structure for table `WagesSprache`
--

CREATE TABLE IF NOT EXISTS `WagesSprache` (
  `WageSpracheID` int(11) NOT NULL,
  `EchelID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `SchedID` int(11) NOT NULL,
  `Wage` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='each schedule has a different fare';

-- --------------------------------------------------------

--
-- Table structure for table `WagesUni`
--

CREATE TABLE IF NOT EXISTS `WagesUni` (
  `WageUniID` int(11) NOT NULL,
  `EchelID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `CourseID` int(11) NOT NULL COMMENT 'not all course have the same fee e.g. very difficult courses have higher fees',
  `Wage` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Absent`
--
ALTER TABLE `Absent`
  ADD PRIMARY KEY (`AbsID`),
  ADD KEY `MembID` (`StudentID`),
  ADD KEY `HistID` (`HistID`);

--
-- Indexes for table `BaseWages`
--
ALTER TABLE `BaseWages`
  ADD PRIMARY KEY (`SalID`),
  ADD KEY `EchelID` (`EchelID`);

--
-- Indexes for table `Buildings`
--
ALTER TABLE `Buildings`
  ADD PRIMARY KEY (`BuildID`);

--
-- Indexes for table `Canceled`
--
ALTER TABLE `Canceled`
  ADD PRIMARY KEY (`CancID`),
  ADD KEY `GroupID` (`GroupID`);

--
-- Indexes for table `Contract`
--
ALTER TABLE `Contract`
  ADD PRIMARY KEY (`ConID`),
  ADD KEY `TeacherID` (`TeacherID`);

--
-- Indexes for table `Courses`
--
ALTER TABLE `Courses`
  ADD PRIMARY KEY (`CourseID`),
  ADD KEY `DepID` (`DepID`),
  ADD KEY `Schwer` (`Schwer`);

--
-- Indexes for table `Days`
--
ALTER TABLE `Days`
  ADD PRIMARY KEY (`DayID`);

--
-- Indexes for table `Departments`
--
ALTER TABLE `Departments`
  ADD PRIMARY KEY (`DepID`);

--
-- Indexes for table `Diplomas`
--
ALTER TABLE `Diplomas`
  ADD PRIMARY KEY (`DiplID`),
  ADD KEY `LangID` (`LangID`),
  ADD KEY `ProvID` (`ProvID`),
  ADD KEY `Schwer` (`Schwer`);

--
-- Indexes for table `DiscData`
--
ALTER TABLE `DiscData`
  ADD KEY `DiscID` (`DiscID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `Disciplines`
--
ALTER TABLE `Disciplines`
  ADD PRIMARY KEY (`DiscID`);

--
-- Indexes for table `Discounts`
--
ALTER TABLE `Discounts`
  ADD PRIMARY KEY (`DiscID`),
  ADD KEY `CatID` (`CatID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `Dropout`
--
ALTER TABLE `Dropout`
  ADD KEY `GroupID` (`GroupID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `Echelon`
--
ALTER TABLE `Echelon`
  ADD PRIMARY KEY (`EchelID`);

--
-- Indexes for table `Ensembles`
--
ALTER TABLE `Ensembles`
  ADD PRIMARY KEY (`EnsPK`),
  ADD KEY `GroupID` (`GroupID`),
  ADD KEY `StudID` (`StudID`);

--
-- Indexes for table `Erlaubnis`
--
ALTER TABLE `Erlaubnis`
  ADD PRIMARY KEY (`UlrID`),
  ADD KEY `TeacherID` (`TeacherID`);

--
-- Indexes for table `ExamSchule`
--
ALTER TABLE `ExamSchule`
  ADD PRIMARY KEY (`ExamID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `ExamSprache`
--
ALTER TABLE `ExamSprache`
  ADD PRIMARY KEY (`TestID`),
  ADD KEY `DiplID` (`DiplID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `Expenses`
--
ALTER TABLE `Expenses`
  ADD PRIMARY KEY (`ExpID`),
  ADD KEY `ExpCat` (`ExpCat`);

--
-- Indexes for table `ExpensesCats`
--
ALTER TABLE `ExpensesCats`
  ADD PRIMARY KEY (`ExpenseID`);

--
-- Indexes for table `FeeSchule`
--
ALTER TABLE `FeeSchule`
  ADD PRIMARY KEY (`FrSchID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `FeeSprache`
--
ALTER TABLE `FeeSprache`
  ADD PRIMARY KEY (`FspID`),
  ADD KEY `SchedID` (`SchedID`);

--
-- Indexes for table `FeeUni`
--
ALTER TABLE `FeeUni`
  ADD PRIMARY KEY (`FareID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `Funds`
--
ALTER TABLE `Funds`
  ADD PRIMARY KEY (`FundID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `Groups`
--
ALTER TABLE `Groups`
  ADD PRIMARY KEY (`GroupID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `CourseID` (`CourseID`),
  ADD KEY `Edu` (`LessTypeID`),
  ADD KEY `Edu_2` (`LessTypeID`);

--
-- Indexes for table `History`
--
ALTER TABLE `History`
  ADD PRIMARY KEY (`HistID`),
  ADD KEY `GroupID` (`GroupID`),
  ADD KEY `StartHourID` (`StartHourID`),
  ADD KEY `RoomID` (`RoomID`);

--
-- Indexes for table `Hours`
--
ALTER TABLE `Hours`
  ADD PRIMARY KEY (`HourID`);

--
-- Indexes for table `Instituts`
--
ALTER TABLE `Instituts`
  ADD PRIMARY KEY (`InstID`);

--
-- Indexes for table `Kassen`
--
ALTER TABLE `Kassen`
  ADD PRIMARY KEY (`KasseID`);

--
-- Indexes for table `Languages`
--
ALTER TABLE `Languages`
  ADD PRIMARY KEY (`LangID`);

--
-- Indexes for table `LessonType`
--
ALTER TABLE `LessonType`
  ADD PRIMARY KEY (`TypeID`);

--
-- Indexes for table `Members`
--
ALTER TABLE `Members`
  ADD PRIMARY KEY (`MembID`),
  ADD KEY `MembTypeID` (`MembTypeID`);

--
-- Indexes for table `MembTypes`
--
ALTER TABLE `MembTypes`
  ADD PRIMARY KEY (`MembTypeID`);

--
-- Indexes for table `PayKassen`
--
ALTER TABLE `PayKassen`
  ADD PRIMARY KEY (`SalID`),
  ADD KEY `EchelID` (`TeacherID`),
  ADD KEY `TeacherID` (`TeacherID`);

--
-- Indexes for table `Payments`
--
ALTER TABLE `Payments`
  ADD PRIMARY KEY (`PayID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `PayTypeID` (`PayTypeID`);

--
-- Indexes for table `PayType`
--
ALTER TABLE `PayType`
  ADD PRIMARY KEY (`PayTypeID`);

--
-- Indexes for table `Permament`
--
ALTER TABLE `Permament`
  ADD PRIMARY KEY (`PermaID`),
  ADD KEY `GroupID` (`GroupID`),
  ADD KEY `DayID` (`DayID`),
  ADD KEY `RoomID` (`RoomID`),
  ADD KEY `HourID` (`HourID`);

--
-- Indexes for table `Receipts`
--
ALTER TABLE `Receipts`
  ADD PRIMARY KEY (`ReceiptID`),
  ADD KEY `TypeID` (`TypeID`),
  ADD KEY `Person` (`PersonID`),
  ADD KEY `EmployerID` (`EmployerID`);

--
-- Indexes for table `ReceiptType`
--
ALTER TABLE `ReceiptType`
  ADD PRIMARY KEY (`TypeID`);

--
-- Indexes for table `RequestSchule`
--
ALTER TABLE `RequestSchule`
  ADD PRIMARY KEY (`RequestID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `RequestSprache`
--
ALTER TABLE `RequestSprache`
  ADD PRIMARY KEY (`RequestID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `ScheduleID` (`ScheduleID`);

--
-- Indexes for table `RequestUni`
--
ALTER TABLE `RequestUni`
  ADD PRIMARY KEY (`RequestID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `Roles`
--
ALTER TABLE `Roles`
  ADD PRIMARY KEY (`RoleID`);

--
-- Indexes for table `Rooms`
--
ALTER TABLE `Rooms`
  ADD PRIMARY KEY (`RoomID`),
  ADD KEY `BuildID` (`BuildID`);

--
-- Indexes for table `Schedule`
--
ALTER TABLE `Schedule`
  ADD PRIMARY KEY (`SchedID`),
  ADD KEY `DiploID` (`DiploID`);

--
-- Indexes for table `Schwierigkeit`
--
ALTER TABLE `Schwierigkeit`
  ADD PRIMARY KEY (`SchwerID`);

--
-- Indexes for table `SpecialCats`
--
ALTER TABLE `SpecialCats`
  ADD PRIMARY KEY (`SpecialID`);

--
-- Indexes for table `TeachEchelon`
--
ALTER TABLE `TeachEchelon`
  ADD PRIMARY KEY (`TEID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `EchelonID` (`EchelonID`);

--
-- Indexes for table `TeachOther`
--
ALTER TABLE `TeachOther`
  ADD PRIMARY KEY (`TTID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `TeachSprache`
--
ALTER TABLE `TeachSprache`
  ADD PRIMARY KEY (`SPID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `DiplomaID` (`DiplomaID`);

--
-- Indexes for table `TestSchule`
--
ALTER TABLE `TestSchule`
  ADD PRIMARY KEY (`TestSpID`),
  ADD KEY `StudID` (`StudID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `TestSprache`
--
ALTER TABLE `TestSprache`
  ADD PRIMARY KEY (`TestSpID`),
  ADD KEY `StudID` (`StudID`),
  ADD KEY `ScheduleID` (`ScheduleID`);

--
-- Indexes for table `Times`
--
ALTER TABLE `Times`
  ADD PRIMARY KEY (`TimesID`),
  ADD KEY `DayID` (`DayID`),
  ADD KEY `HourID` (`HourID`),
  ADD KEY `SchedID` (`SchedID`);

--
-- Indexes for table `TrainingSprache`
--
ALTER TABLE `TrainingSprache`
  ADD PRIMARY KEY (`ExID`);

--
-- Indexes for table `TrainingUni`
--
ALTER TABLE `TrainingUni`
  ADD PRIMARY KEY (`ExampleID`);

--
-- Indexes for table `Unavailable`
--
ALTER TABLE `Unavailable`
  ADD PRIMARY KEY (`UnavailID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `DayID` (`DayID`),
  ADD KEY `HourID` (`HourID`);

--
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`UserID`),
  ADD KEY `RoleID` (`RoleID`);

--
-- Indexes for table `Versicherung`
--
ALTER TABLE `Versicherung`
  ADD PRIMARY KEY (`SicherID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `KasseID` (`KasseID`);

--
-- Indexes for table `WagesSchule`
--
ALTER TABLE `WagesSchule`
  ADD PRIMARY KEY (`WagesSchuleID`),
  ADD KEY `EchelID` (`EchelID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `WagesSprache`
--
ALTER TABLE `WagesSprache`
  ADD PRIMARY KEY (`WageSpracheID`),
  ADD KEY `EchelID` (`EchelID`),
  ADD KEY `SchedID` (`SchedID`);

--
-- Indexes for table `WagesUni`
--
ALTER TABLE `WagesUni`
  ADD PRIMARY KEY (`WageUniID`),
  ADD KEY `EchelID` (`EchelID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `Absent`
--
ALTER TABLE `Absent`
  MODIFY `AbsID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `BaseWages`
--
ALTER TABLE `BaseWages`
  MODIFY `SalID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `Buildings`
--
ALTER TABLE `Buildings`
  MODIFY `BuildID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `Canceled`
--
ALTER TABLE `Canceled`
  MODIFY `CancID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Contract`
--
ALTER TABLE `Contract`
  MODIFY `ConID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=26;
--
-- AUTO_INCREMENT for table `Courses`
--
ALTER TABLE `Courses`
  MODIFY `CourseID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=36;
--
-- AUTO_INCREMENT for table `Days`
--
ALTER TABLE `Days`
  MODIFY `DayID` tinyint(4) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `Departments`
--
ALTER TABLE `Departments`
  MODIFY `DepID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `Diplomas`
--
ALTER TABLE `Diplomas`
  MODIFY `DiplID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `Disciplines`
--
ALTER TABLE `Disciplines`
  MODIFY `DiscID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `Discounts`
--
ALTER TABLE `Discounts`
  MODIFY `DiscID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Echelon`
--
ALTER TABLE `Echelon`
  MODIFY `EchelID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Ensembles`
--
ALTER TABLE `Ensembles`
  MODIFY `EnsPK` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `Erlaubnis`
--
ALTER TABLE `Erlaubnis`
  MODIFY `UlrID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=25;
--
-- AUTO_INCREMENT for table `ExamSchule`
--
ALTER TABLE `ExamSchule`
  MODIFY `ExamID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `ExamSprache`
--
ALTER TABLE `ExamSprache`
  MODIFY `TestID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Expenses`
--
ALTER TABLE `Expenses`
  MODIFY `ExpID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `ExpensesCats`
--
ALTER TABLE `ExpensesCats`
  MODIFY `ExpenseID` smallint(5) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `FeeSchule`
--
ALTER TABLE `FeeSchule`
  MODIFY `FrSchID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT for table `FeeSprache`
--
ALTER TABLE `FeeSprache`
  MODIFY `FspID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `FeeUni`
--
ALTER TABLE `FeeUni`
  MODIFY `FareID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Funds`
--
ALTER TABLE `Funds`
  MODIFY `FundID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Groups`
--
ALTER TABLE `Groups`
  MODIFY `GroupID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT for table `History`
--
ALTER TABLE `History`
  MODIFY `HistID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Hours`
--
ALTER TABLE `Hours`
  MODIFY `HourID` tinyint(4) NOT NULL AUTO_INCREMENT COMMENT 'id represents the cell row',AUTO_INCREMENT=30;
--
-- AUTO_INCREMENT for table `Instituts`
--
ALTER TABLE `Instituts`
  MODIFY `InstID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Kassen`
--
ALTER TABLE `Kassen`
  MODIFY `KasseID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Languages`
--
ALTER TABLE `Languages`
  MODIFY `LangID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT for table `LessonType`
--
ALTER TABLE `LessonType`
  MODIFY `TypeID` tinyint(4) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Members`
--
ALTER TABLE `Members`
  MODIFY `MembID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=37;
--
-- AUTO_INCREMENT for table `MembTypes`
--
ALTER TABLE `MembTypes`
  MODIFY `MembTypeID` tinyint(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `PayKassen`
--
ALTER TABLE `PayKassen`
  MODIFY `SalID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=25;
--
-- AUTO_INCREMENT for table `Payments`
--
ALTER TABLE `Payments`
  MODIFY `PayID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT for table `PayType`
--
ALTER TABLE `PayType`
  MODIFY `PayTypeID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `Permament`
--
ALTER TABLE `Permament`
  MODIFY `PermaID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Receipts`
--
ALTER TABLE `Receipts`
  MODIFY `ReceiptID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `ReceiptType`
--
ALTER TABLE `ReceiptType`
  MODIFY `TypeID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `RequestSchule`
--
ALTER TABLE `RequestSchule`
  MODIFY `RequestID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=22;
--
-- AUTO_INCREMENT for table `RequestSprache`
--
ALTER TABLE `RequestSprache`
  MODIFY `RequestID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `RequestUni`
--
ALTER TABLE `RequestUni`
  MODIFY `RequestID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Roles`
--
ALTER TABLE `Roles`
  MODIFY `RoleID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `Rooms`
--
ALTER TABLE `Rooms`
  MODIFY `RoomID` tinyint(4) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `Schedule`
--
ALTER TABLE `Schedule`
  MODIFY `SchedID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Schwierigkeit`
--
ALTER TABLE `Schwierigkeit`
  MODIFY `SchwerID` tinyint(4) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=14;
--
-- AUTO_INCREMENT for table `SpecialCats`
--
ALTER TABLE `SpecialCats`
  MODIFY `SpecialID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `TeachEchelon`
--
ALTER TABLE `TeachEchelon`
  MODIFY `TEID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=10;
--
-- AUTO_INCREMENT for table `TeachOther`
--
ALTER TABLE `TeachOther`
  MODIFY `TTID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=60;
--
-- AUTO_INCREMENT for table `TeachSprache`
--
ALTER TABLE `TeachSprache`
  MODIFY `SPID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `TestSchule`
--
ALTER TABLE `TestSchule`
  MODIFY `TestSpID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `TestSprache`
--
ALTER TABLE `TestSprache`
  MODIFY `TestSpID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Times`
--
ALTER TABLE `Times`
  MODIFY `TimesID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `TrainingSprache`
--
ALTER TABLE `TrainingSprache`
  MODIFY `ExID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `TrainingUni`
--
ALTER TABLE `TrainingUni`
  MODIFY `ExampleID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Unavailable`
--
ALTER TABLE `Unavailable`
  MODIFY `UnavailID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Users`
--
ALTER TABLE `Users`
  MODIFY `UserID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Versicherung`
--
ALTER TABLE `Versicherung`
  MODIFY `SicherID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=23;
--
-- AUTO_INCREMENT for table `WagesSchule`
--
ALTER TABLE `WagesSchule`
  MODIFY `WagesSchuleID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=24;
--
-- AUTO_INCREMENT for table `WagesSprache`
--
ALTER TABLE `WagesSprache`
  MODIFY `WageSpracheID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `WagesUni`
--
ALTER TABLE `WagesUni`
  MODIFY `WageUniID` int(11) NOT NULL AUTO_INCREMENT;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `Absent`
--
ALTER TABLE `Absent`
  ADD CONSTRAINT `fkhistid` FOREIGN KEY (`HistID`) REFERENCES `History` (`HistID`),
  ADD CONSTRAINT `fkstudid` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `BaseWages`
--
ALTER TABLE `BaseWages`
  ADD CONSTRAINT `fkechelid` FOREIGN KEY (`EchelID`) REFERENCES `Echelon` (`EchelID`);

--
-- Constraints for table `Canceled`
--
ALTER TABLE `Canceled`
  ADD CONSTRAINT `fkgroupid` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`);

--
-- Constraints for table `Contract`
--
ALTER TABLE `Contract`
  ADD CONSTRAINT `fkteachid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Courses`
--
ALTER TABLE `Courses`
  ADD CONSTRAINT `fkdepid` FOREIGN KEY (`DepID`) REFERENCES `Departments` (`DepID`),
  ADD CONSTRAINT `fkschwerid` FOREIGN KEY (`Schwer`) REFERENCES `Schwierigkeit` (`SchwerID`);

--
-- Constraints for table `Diplomas`
--
ALTER TABLE `Diplomas`
  ADD CONSTRAINT `Diplomas_ibfk_1` FOREIGN KEY (`Schwer`) REFERENCES `Schwierigkeit` (`SchwerID`),
  ADD CONSTRAINT `fklangid` FOREIGN KEY (`LangID`) REFERENCES `Languages` (`LangID`),
  ADD CONSTRAINT `fkprovid` FOREIGN KEY (`ProvID`) REFERENCES `Instituts` (`InstID`);

--
-- Constraints for table `DiscData`
--
ALTER TABLE `DiscData`
  ADD CONSTRAINT `DiscData_ibfk_1` FOREIGN KEY (`DiscID`) REFERENCES `Disciplines` (`DiscID`),
  ADD CONSTRAINT `DiscData_ibfk_2` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Discounts`
--
ALTER TABLE `Discounts`
  ADD CONSTRAINT `Discounts_ibfk_1` FOREIGN KEY (`CatID`) REFERENCES `SpecialCats` (`SpecialID`),
  ADD CONSTRAINT `Discounts_ibfk_2` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Dropout`
--
ALTER TABLE `Dropout`
  ADD CONSTRAINT `fkkropid` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`),
  ADD CONSTRAINT `flsid` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Ensembles`
--
ALTER TABLE `Ensembles`
  ADD CONSTRAINT `Ensembles_ibfk_1` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `enskdstudid` FOREIGN KEY (`StudID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Erlaubnis`
--
ALTER TABLE `Erlaubnis`
  ADD CONSTRAINT `erteachid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `ExamSchule`
--
ALTER TABLE `ExamSchule`
  ADD CONSTRAINT `exstudid` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `fkcourseid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`);

--
-- Constraints for table `ExamSprache`
--
ALTER TABLE `ExamSprache`
  ADD CONSTRAINT `exstudentid` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `fkdiplid` FOREIGN KEY (`DiplID`) REFERENCES `Diplomas` (`DiplID`);

--
-- Constraints for table `Expenses`
--
ALTER TABLE `Expenses`
  ADD CONSTRAINT `Expenses_ibfk_1` FOREIGN KEY (`ExpCat`) REFERENCES `ExpensesCats` (`ExpenseID`);

--
-- Constraints for table `FeeSchule`
--
ALTER TABLE `FeeSchule`
  ADD CONSTRAINT `feecourseid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`);

--
-- Constraints for table `FeeSprache`
--
ALTER TABLE `FeeSprache`
  ADD CONSTRAINT `fkshedid` FOREIGN KEY (`SchedID`) REFERENCES `Schedule` (`SchedID`);

--
-- Constraints for table `FeeUni`
--
ALTER TABLE `FeeUni`
  ADD CONSTRAINT `fecourseid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`);

--
-- Constraints for table `Funds`
--
ALTER TABLE `Funds`
  ADD CONSTRAINT `studid` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Groups`
--
ALTER TABLE `Groups`
  ADD CONSTRAINT `Groups_ibfk_1` FOREIGN KEY (`LessTypeID`) REFERENCES `LessonType` (`TypeID`),
  ADD CONSTRAINT `csrid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
  ADD CONSTRAINT `edyy` FOREIGN KEY (`LessTypeID`) REFERENCES `LessonType` (`TypeID`),
  ADD CONSTRAINT `teach` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `History`
--
ALTER TABLE `History`
  ADD CONSTRAINT `fkhourid` FOREIGN KEY (`StartHourID`) REFERENCES `Hours` (`HourID`),
  ADD CONSTRAINT `fkroom` FOREIGN KEY (`RoomID`) REFERENCES `Rooms` (`RoomID`),
  ADD CONSTRAINT `group` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`);

--
-- Constraints for table `Members`
--
ALTER TABLE `Members`
  ADD CONSTRAINT `fkmembtype` FOREIGN KEY (`MembTypeID`) REFERENCES `MembTypes` (`MembTypeID`);

--
-- Constraints for table `PayKassen`
--
ALTER TABLE `PayKassen`
  ADD CONSTRAINT `fklehreid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Payments`
--
ALTER TABLE `Payments`
  ADD CONSTRAINT `fkpaytypeid` FOREIGN KEY (`PayTypeID`) REFERENCES `PayType` (`PayTypeID`),
  ADD CONSTRAINT `fkteacherid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Permament`
--
ALTER TABLE `Permament`
  ADD CONSTRAINT `fkday` FOREIGN KEY (`DayID`) REFERENCES `Days` (`DayID`),
  ADD CONSTRAINT `fkhour` FOREIGN KEY (`HourID`) REFERENCES `Hours` (`HourID`),
  ADD CONSTRAINT `gropu` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`),
  ADD CONSTRAINT `room` FOREIGN KEY (`RoomID`) REFERENCES `Rooms` (`RoomID`);

--
-- Constraints for table `Receipts`
--
ALTER TABLE `Receipts`
  ADD CONSTRAINT `Receipts_ibfk_1` FOREIGN KEY (`TypeID`) REFERENCES `ReceiptType` (`TypeID`),
  ADD CONSTRAINT `Receipts_ibfk_2` FOREIGN KEY (`PersonID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `Receipts_ibfk_3` FOREIGN KEY (`EmployerID`) REFERENCES `Users` (`UserID`);

--
-- Constraints for table `RequestSchule`
--
ALTER TABLE `RequestSchule`
  ADD CONSTRAINT `fkcourse` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
  ADD CONSTRAINT `fkstudent` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `RequestSprache`
--
ALTER TABLE `RequestSprache`
  ADD CONSTRAINT `fksched` FOREIGN KEY (`ScheduleID`) REFERENCES `Schedule` (`SchedID`),
  ADD CONSTRAINT `stud` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `RequestUni`
--
ALTER TABLE `RequestUni`
  ADD CONSTRAINT `kursid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
  ADD CONSTRAINT `reqstudid` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Rooms`
--
ALTER TABLE `Rooms`
  ADD CONSTRAINT `fkbuildid` FOREIGN KEY (`BuildID`) REFERENCES `Buildings` (`BuildID`);

--
-- Constraints for table `Schedule`
--
ALTER TABLE `Schedule`
  ADD CONSTRAINT `fkdiplo` FOREIGN KEY (`DiploID`) REFERENCES `Diplomas` (`DiplID`);

--
-- Constraints for table `TeachEchelon`
--
ALTER TABLE `TeachEchelon`
  ADD CONSTRAINT `fkdaskalosid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `fkskalaid` FOREIGN KEY (`EchelonID`) REFERENCES `Echelon` (`EchelID`);

--
-- Constraints for table `TeachOther`
--
ALTER TABLE `TeachOther`
  ADD CONSTRAINT `fkcours` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
  ADD CONSTRAINT `fkteach` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `TeachSprache`
--
ALTER TABLE `TeachSprache`
  ADD CONSTRAINT `fktfeach` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `fkurz` FOREIGN KEY (`DiplomaID`) REFERENCES `Diplomas` (`DiplID`);

--
-- Constraints for table `TestSchule`
--
ALTER TABLE `TestSchule`
  ADD CONSTRAINT `fkkurz` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
  ADD CONSTRAINT `fkstid` FOREIGN KEY (`StudID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `TestSprache`
--
ALTER TABLE `TestSprache`
  ADD CONSTRAINT `fkscheid` FOREIGN KEY (`ScheduleID`) REFERENCES `Schedule` (`SchedID`),
  ADD CONSTRAINT `fkstuid` FOREIGN KEY (`StudID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Times`
--
ALTER TABLE `Times`
  ADD CONSTRAINT `fkdayid` FOREIGN KEY (`DayID`) REFERENCES `Days` (`DayID`),
  ADD CONSTRAINT `fkshed` FOREIGN KEY (`SchedID`) REFERENCES `Schedule` (`SchedID`),
  ADD CONSTRAINT `fkstundeid` FOREIGN KEY (`HourID`) REFERENCES `Hours` (`HourID`);

--
-- Constraints for table `Unavailable`
--
ALTER TABLE `Unavailable`
  ADD CONSTRAINT `fkdid` FOREIGN KEY (`DayID`) REFERENCES `Days` (`DayID`),
  ADD CONSTRAINT `fkoraid` FOREIGN KEY (`HourID`) REFERENCES `Hours` (`HourID`),
  ADD CONSTRAINT `fktid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Users`
--
ALTER TABLE `Users`
  ADD CONSTRAINT `Users_ibfk_1` FOREIGN KEY (`RoleID`) REFERENCES `Roles` (`RoleID`);

--
-- Constraints for table `Versicherung`
--
ALTER TABLE `Versicherung`
  ADD CONSTRAINT `fkasseid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `fkverkassenid` FOREIGN KEY (`KasseID`) REFERENCES `Kassen` (`KasseID`);

--
-- Constraints for table `WagesSchule`
--
ALTER TABLE `WagesSchule`
  ADD CONSTRAINT `fkcid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
  ADD CONSTRAINT `fkechel` FOREIGN KEY (`EchelID`) REFERENCES `Echelon` (`EchelID`);

--
-- Constraints for table `WagesSprache`
--
ALTER TABLE `WagesSprache`
  ADD CONSTRAINT `fkeid` FOREIGN KEY (`EchelID`) REFERENCES `Echelon` (`EchelID`),
  ADD CONSTRAINT `fksd` FOREIGN KEY (`SchedID`) REFERENCES `Schedule` (`SchedID`);

--
-- Constraints for table `WagesUni`
--
ALTER TABLE `WagesUni`
  ADD CONSTRAINT `fkhird` FOREIGN KEY (`EchelID`) REFERENCES `Echelon` (`EchelID`),
  ADD CONSTRAINT `fkuci` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
