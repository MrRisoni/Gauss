-- phpMyAdmin SQL Dump
-- version 4.3.12
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 10, 2015 at 04:16 PM
-- Server version: 10.0.15-MariaDB
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
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf32 COMMENT='salaries go according to experience';

--
-- Dumping data for table `BaseWages`
--

INSERT INTO `BaseWages` (`SalID`, `EchelID`, `Dat`, `Wages`) VALUES
(1, 3, '2015-05-10', 7.25);

-- --------------------------------------------------------

--
-- Table structure for table `Buildings`
--

CREATE TABLE IF NOT EXISTS `Buildings` (
  `BuildID` int(11) NOT NULL,
  `Address` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='end date of Contract';

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Courses`
--

INSERT INTO `Courses` (`CourseID`, `DepID`, `CourseName`, `Schwer`, `Active`) VALUES
(1, 2, 'Ενεργειακά', 10, 1),
(2, 2, 'Εισαγωγή στα ΣΗΕ', 10, 1);

-- --------------------------------------------------------

--
-- Table structure for table `Days`
--

CREATE TABLE IF NOT EXISTS `Days` (
  `DayID` tinyint(4) NOT NULL,
  `DayName` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Departments`
--

CREATE TABLE IF NOT EXISTS `Departments` (
  `DepID` int(11) NOT NULL,
  `DepName` varchar(55) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Departments`
--

INSERT INTO `Departments` (`DepID`, `DepName`) VALUES
(1, 'Λύκειο'),
(2, 'Ηλεκτρολόγοι Μηχανικοί');

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
  `Active` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='diplomas and levels';

-- --------------------------------------------------------

--
-- Table structure for table `Echelon`
--

CREATE TABLE IF NOT EXISTS `Echelon` (
  `EchelID` int(11) NOT NULL,
  `Exp` int(11) NOT NULL COMMENT 'exp in months'
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COMMENT='categorizee teachers according to experience more experience more wages';

--
-- Dumping data for table `Echelon`
--

INSERT INTO `Echelon` (`EchelID`, `Exp`) VALUES
(1, 12),
(2, 24),
(3, 6);

-- --------------------------------------------------------

--
-- Table structure for table `EduTypes`
--

CREATE TABLE IF NOT EXISTS `EduTypes` (
  `EduID` tinyint(4) NOT NULL,
  `Description` varchar(10) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `EduTypes`
--

INSERT INTO `EduTypes` (`EduID`, `Description`) VALUES
(1, 'Group');

-- --------------------------------------------------------

--
-- Table structure for table `Ensembles`
--

CREATE TABLE IF NOT EXISTS `Ensembles` (
  `EnsPK` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL,
  `StudID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='days off ';

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
-- Table structure for table `Faces`
--

CREATE TABLE IF NOT EXISTS `Faces` (
  `MembID` int(11) NOT NULL,
  `Pic` blob NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='faces of members!!!';

-- --------------------------------------------------------

--
-- Table structure for table `FeeSchule`
--

CREATE TABLE IF NOT EXISTS `FeeSchule` (
  `FrSchID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `CourseID` int(11) NOT NULL COMMENT 'not all courses and classes are the same',
  `Fee` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
  `EduType` tinyint(11) NOT NULL COMMENT '1 is solo v 2 is group group university',
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
  `Edu` tinyint(4) NOT NULL COMMENT '1 is univ 2 is school 3 is language'
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
  `HourN` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='versicherungskasse';

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
  `TotPaidHours` float NOT NULL DEFAULT '0' COMMENT 'pososto tot hours poy exoun plirwthei / xrwstane'
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Members`
--

INSERT INTO `Members` (`MembID`, `Name`, `FName`, `MName`, `Address`, `Phone`, `Mobile`, `EMail`, `MembTypeID`, `RegDate`, `BirthDate`, `TotHours`, `TotPaidHours`) VALUES
(1, 'Παρίσης Νικόλαος', 'dfdfdf', 'dffdfd', 'dfdfdf', 'dfdfd', 'dfdfd', 'dfdfd????', 1, '2015-04-21', '1970-01-01', 0, 0),
(2, 'Δεδεκάκη Ελένη', '????', '??????', '?????', '??', '???', '?????', 1, '2015-04-21', '1970-01-01', 0, 0),
(3, 'Σίμου Φλώρα', 'γφγφ', 'γφγφγ', 'γφγφ', 'φγφγφ', 'γφγφ', 'γφγφγφ', 2, '2015-04-21', '1970-01-01', 0, 0),
(4, 'Φράγκος Άρης', 'Πέτρος', 'Σοφία', 'Ζαβλάνι 12', '2610773601', '6947128400', 'arisf@gmail.com', 1, '2015-04-21', '1970-01-01', 0, 0),
(5, 'Παπαδόπουλος Σπύρος', 'Κωνσταντίνος', 'Ακριβή', '1212', 'δφγ', 'δφ', '1212121', 1, '2015-04-20', '2015-04-23', 0, 0),
(6, 'Μπισδίκης Χρήστος', 'Ανδρέας', 'Άννα', 'Φραγκοκλησσιάς 8 , Μαρούσι', '2107882431', '6956009812', 'bischris@gmail.com', 1, '2015-04-21', '1991-08-09', 0, 0);

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
-- Table structure for table `Payments`
--

CREATE TABLE IF NOT EXISTS `Payments` (
  `PayID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `Amount` float NOT NULL,
  `Comments` varchar(100) NOT NULL COMMENT 'what did we pay him for?'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='payments to professors';

-- --------------------------------------------------------

--
-- Table structure for table `Permament`
--

CREATE TABLE IF NOT EXISTS `Permament` (
  `PermaID` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL DEFAULT '0',
  `Type` tinyint(4) NOT NULL COMMENT '1 univ 2 skype 3 school 4 language',
  `DayID` tinyint(4) NOT NULL,
  `RoomID` tinyint(4) NOT NULL,
  `HourID` tinyint(4) NOT NULL,
  `StartsOn` date NOT NULL,
  `EndsOn` date NOT NULL,
  `Active` tinyint(4) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='courses that take part every week ';

-- --------------------------------------------------------

--
-- Table structure for table `RequestSchule`
--

CREATE TABLE IF NOT EXISTS `RequestSchule` (
  `RequestID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `CourseID` int(6) NOT NULL,
  `Settled` tinyint(4) NOT NULL DEFAULT '0' COMMENT '0 unsettled 1 settled 2 closed group',
  `ReqDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
-- Table structure for table `Rooms`
--

CREATE TABLE IF NOT EXISTS `Rooms` (
  `RoomID` tinyint(4) NOT NULL,
  `BuildID` int(4) NOT NULL,
  `Name` varchar(15) NOT NULL,
  `Capacity` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
-- Table structure for table `TeachOther`
--

CREATE TABLE IF NOT EXISTS `TeachOther` (
  `TTID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `CourseID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
  `StartHour` time NOT NULL,
  `Duration` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='days which the prof is unavailable';

-- --------------------------------------------------------

--
-- Table structure for table `Versicherung`
--

CREATE TABLE IF NOT EXISTS `Versicherung` (
  `SicherID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `KasseID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
  `EduType` tinyint(11) NOT NULL COMMENT '1 is solo v 2 is group group university',
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
  ADD PRIMARY KEY (`AbsID`), ADD KEY `MembID` (`StudentID`), ADD KEY `HistID` (`HistID`);

--
-- Indexes for table `BaseWages`
--
ALTER TABLE `BaseWages`
  ADD PRIMARY KEY (`SalID`), ADD KEY `EchelID` (`EchelID`);

--
-- Indexes for table `Buildings`
--
ALTER TABLE `Buildings`
  ADD PRIMARY KEY (`BuildID`);

--
-- Indexes for table `Canceled`
--
ALTER TABLE `Canceled`
  ADD PRIMARY KEY (`CancID`), ADD KEY `GroupID` (`GroupID`);

--
-- Indexes for table `Contract`
--
ALTER TABLE `Contract`
  ADD PRIMARY KEY (`ConID`), ADD KEY `TeacherID` (`TeacherID`);

--
-- Indexes for table `Courses`
--
ALTER TABLE `Courses`
  ADD PRIMARY KEY (`CourseID`), ADD KEY `DepID` (`DepID`), ADD KEY `Schwer` (`Schwer`);

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
  ADD PRIMARY KEY (`DiplID`), ADD KEY `LangID` (`LangID`), ADD KEY `ProvID` (`ProvID`), ADD KEY `Schwer` (`Schwer`);

--
-- Indexes for table `Echelon`
--
ALTER TABLE `Echelon`
  ADD PRIMARY KEY (`EchelID`);

--
-- Indexes for table `EduTypes`
--
ALTER TABLE `EduTypes`
  ADD PRIMARY KEY (`EduID`);

--
-- Indexes for table `Ensembles`
--
ALTER TABLE `Ensembles`
  ADD PRIMARY KEY (`EnsPK`), ADD KEY `GroupID` (`GroupID`), ADD KEY `StudID` (`StudID`);

--
-- Indexes for table `Erlaubnis`
--
ALTER TABLE `Erlaubnis`
  ADD PRIMARY KEY (`UlrID`), ADD KEY `TeacherID` (`TeacherID`);

--
-- Indexes for table `ExamSchule`
--
ALTER TABLE `ExamSchule`
  ADD PRIMARY KEY (`ExamID`), ADD KEY `StudentID` (`StudentID`), ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `ExamSprache`
--
ALTER TABLE `ExamSprache`
  ADD PRIMARY KEY (`TestID`), ADD KEY `DiplID` (`DiplID`), ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `Faces`
--
ALTER TABLE `Faces`
  ADD PRIMARY KEY (`MembID`);

--
-- Indexes for table `FeeSchule`
--
ALTER TABLE `FeeSchule`
  ADD PRIMARY KEY (`FrSchID`), ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `FeeSprache`
--
ALTER TABLE `FeeSprache`
  ADD PRIMARY KEY (`FspID`), ADD KEY `SchedID` (`SchedID`);

--
-- Indexes for table `FeeUni`
--
ALTER TABLE `FeeUni`
  ADD PRIMARY KEY (`FareID`), ADD KEY `CourseID` (`CourseID`), ADD KEY `EduType` (`EduType`);

--
-- Indexes for table `Funds`
--
ALTER TABLE `Funds`
  ADD PRIMARY KEY (`FundID`), ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `Groups`
--
ALTER TABLE `Groups`
  ADD PRIMARY KEY (`GroupID`), ADD KEY `TeacherID` (`TeacherID`), ADD KEY `CourseID` (`CourseID`), ADD KEY `Edu` (`Edu`);

--
-- Indexes for table `History`
--
ALTER TABLE `History`
  ADD PRIMARY KEY (`HistID`), ADD KEY `GroupID` (`GroupID`), ADD KEY `StartHourID` (`StartHourID`), ADD KEY `RoomID` (`RoomID`);

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
-- Indexes for table `Members`
--
ALTER TABLE `Members`
  ADD PRIMARY KEY (`MembID`), ADD KEY `MembTypeID` (`MembTypeID`);

--
-- Indexes for table `MembTypes`
--
ALTER TABLE `MembTypes`
  ADD PRIMARY KEY (`MembTypeID`);

--
-- Indexes for table `Payments`
--
ALTER TABLE `Payments`
  ADD PRIMARY KEY (`PayID`), ADD KEY `TeacherID` (`TeacherID`);

--
-- Indexes for table `Permament`
--
ALTER TABLE `Permament`
  ADD PRIMARY KEY (`PermaID`), ADD KEY `GroupID` (`GroupID`), ADD KEY `DayID` (`DayID`), ADD KEY `RoomID` (`RoomID`), ADD KEY `HourID` (`HourID`), ADD KEY `Type` (`Type`);

--
-- Indexes for table `RequestSchule`
--
ALTER TABLE `RequestSchule`
  ADD PRIMARY KEY (`RequestID`), ADD KEY `StudentID` (`StudentID`), ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `RequestSprache`
--
ALTER TABLE `RequestSprache`
  ADD PRIMARY KEY (`RequestID`), ADD KEY `StudentID` (`StudentID`), ADD KEY `ScheduleID` (`ScheduleID`);

--
-- Indexes for table `RequestUni`
--
ALTER TABLE `RequestUni`
  ADD PRIMARY KEY (`RequestID`), ADD KEY `StudentID` (`StudentID`), ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `Rooms`
--
ALTER TABLE `Rooms`
  ADD PRIMARY KEY (`RoomID`), ADD KEY `BuildID` (`BuildID`);

--
-- Indexes for table `Schedule`
--
ALTER TABLE `Schedule`
  ADD PRIMARY KEY (`SchedID`), ADD KEY `DiploID` (`DiploID`);

--
-- Indexes for table `Schwierigkeit`
--
ALTER TABLE `Schwierigkeit`
  ADD PRIMARY KEY (`SchwerID`);

--
-- Indexes for table `TeachOther`
--
ALTER TABLE `TeachOther`
  ADD PRIMARY KEY (`TTID`), ADD KEY `TeacherID` (`TeacherID`), ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `TeachSprache`
--
ALTER TABLE `TeachSprache`
  ADD PRIMARY KEY (`SPID`), ADD KEY `TeacherID` (`TeacherID`), ADD KEY `DiplomaID` (`DiplomaID`);

--
-- Indexes for table `TestSchule`
--
ALTER TABLE `TestSchule`
  ADD PRIMARY KEY (`TestSpID`), ADD KEY `StudID` (`StudID`), ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `TestSprache`
--
ALTER TABLE `TestSprache`
  ADD PRIMARY KEY (`TestSpID`), ADD KEY `StudID` (`StudID`), ADD KEY `ScheduleID` (`ScheduleID`);

--
-- Indexes for table `Times`
--
ALTER TABLE `Times`
  ADD PRIMARY KEY (`TimesID`), ADD KEY `DayID` (`DayID`), ADD KEY `HourID` (`HourID`), ADD KEY `SchedID` (`SchedID`);

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
  ADD PRIMARY KEY (`UnavailID`), ADD KEY `TeacherID` (`TeacherID`), ADD KEY `DayID` (`DayID`);

--
-- Indexes for table `Versicherung`
--
ALTER TABLE `Versicherung`
  ADD PRIMARY KEY (`SicherID`), ADD KEY `TeacherID` (`TeacherID`), ADD KEY `KasseID` (`KasseID`);

--
-- Indexes for table `WagesSchule`
--
ALTER TABLE `WagesSchule`
  ADD PRIMARY KEY (`WagesSchuleID`), ADD KEY `EchelID` (`EchelID`), ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `WagesSprache`
--
ALTER TABLE `WagesSprache`
  ADD PRIMARY KEY (`WageSpracheID`), ADD KEY `EchelID` (`EchelID`), ADD KEY `SchedID` (`SchedID`);

--
-- Indexes for table `WagesUni`
--
ALTER TABLE `WagesUni`
  ADD PRIMARY KEY (`WageUniID`), ADD KEY `EchelID` (`EchelID`), ADD KEY `EduType` (`EduType`), ADD KEY `CourseID` (`CourseID`);

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
  MODIFY `SalID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `Buildings`
--
ALTER TABLE `Buildings`
  MODIFY `BuildID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Canceled`
--
ALTER TABLE `Canceled`
  MODIFY `CancID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Contract`
--
ALTER TABLE `Contract`
  MODIFY `ConID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Courses`
--
ALTER TABLE `Courses`
  MODIFY `CourseID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `Days`
--
ALTER TABLE `Days`
  MODIFY `DayID` tinyint(4) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Departments`
--
ALTER TABLE `Departments`
  MODIFY `DepID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `Diplomas`
--
ALTER TABLE `Diplomas`
  MODIFY `DiplID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Echelon`
--
ALTER TABLE `Echelon`
  MODIFY `EchelID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `EduTypes`
--
ALTER TABLE `EduTypes`
  MODIFY `EduID` tinyint(4) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `Ensembles`
--
ALTER TABLE `Ensembles`
  MODIFY `EnsPK` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Erlaubnis`
--
ALTER TABLE `Erlaubnis`
  MODIFY `UlrID` int(11) NOT NULL AUTO_INCREMENT;
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
  MODIFY `GroupID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `History`
--
ALTER TABLE `History`
  MODIFY `HistID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Hours`
--
ALTER TABLE `Hours`
  MODIFY `HourID` tinyint(4) NOT NULL AUTO_INCREMENT COMMENT 'id represents the cell row';
--
-- AUTO_INCREMENT for table `Instituts`
--
ALTER TABLE `Instituts`
  MODIFY `InstID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Kassen`
--
ALTER TABLE `Kassen`
  MODIFY `KasseID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Languages`
--
ALTER TABLE `Languages`
  MODIFY `LangID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT for table `Members`
--
ALTER TABLE `Members`
  MODIFY `MembID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `MembTypes`
--
ALTER TABLE `MembTypes`
  MODIFY `MembTypeID` tinyint(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `Payments`
--
ALTER TABLE `Payments`
  MODIFY `PayID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Permament`
--
ALTER TABLE `Permament`
  MODIFY `PermaID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `RequestSchule`
--
ALTER TABLE `RequestSchule`
  MODIFY `RequestID` int(11) NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `Rooms`
--
ALTER TABLE `Rooms`
  MODIFY `RoomID` tinyint(4) NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `TeachOther`
--
ALTER TABLE `TeachOther`
  MODIFY `TTID` int(11) NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `Versicherung`
--
ALTER TABLE `Versicherung`
  MODIFY `SicherID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `WagesSchule`
--
ALTER TABLE `WagesSchule`
  MODIFY `WagesSchuleID` int(11) NOT NULL AUTO_INCREMENT;
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
ADD CONSTRAINT `fecourseid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
ADD CONSTRAINT `fkedu` FOREIGN KEY (`EduType`) REFERENCES `EduTypes` (`EduID`);

--
-- Constraints for table `Funds`
--
ALTER TABLE `Funds`
ADD CONSTRAINT `studid` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Groups`
--
ALTER TABLE `Groups`
ADD CONSTRAINT `csrid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
ADD CONSTRAINT `edyy` FOREIGN KEY (`Edu`) REFERENCES `EduTypes` (`EduID`),
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
-- Constraints for table `Payments`
--
ALTER TABLE `Payments`
ADD CONSTRAINT `fkteacherid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Permament`
--
ALTER TABLE `Permament`
ADD CONSTRAINT `fkday` FOREIGN KEY (`DayID`) REFERENCES `Days` (`DayID`),
ADD CONSTRAINT `fkhour` FOREIGN KEY (`HourID`) REFERENCES `Hours` (`HourID`),
ADD CONSTRAINT `fktype` FOREIGN KEY (`Type`) REFERENCES `EduTypes` (`EduID`),
ADD CONSTRAINT `gropu` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`),
ADD CONSTRAINT `room` FOREIGN KEY (`RoomID`) REFERENCES `Rooms` (`RoomID`);

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
ADD CONSTRAINT `fktid` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Versicherung`
--
ALTER TABLE `Versicherung`
ADD CONSTRAINT `fkasseid` FOREIGN KEY (`TeacherID`) REFERENCES `Kassen` (`KasseID`),
ADD CONSTRAINT `fkverid` FOREIGN KEY (`KasseID`) REFERENCES `Kassen` (`KasseID`);

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
ADD CONSTRAINT `fkedy` FOREIGN KEY (`EduType`) REFERENCES `EduTypes` (`EduID`),
ADD CONSTRAINT `fkhird` FOREIGN KEY (`EchelID`) REFERENCES `Echelon` (`EchelID`),
ADD CONSTRAINT `fkuci` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
