-- phpMyAdmin SQL Dump
-- version 4.4.8
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 06, 2015 at 04:01 PM
-- Server version: 10.0.19-MariaDB
-- PHP Version: 5.6.9

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
-- Table structure for table `AccedFees`
--

CREATE TABLE IF NOT EXISTS `AccedFees` (
  `AccID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `Amount` float NOT NULL,
  `GroupID` int(11) NOT NULL,
  `Updated` date NOT NULL,
  `Discount` float NOT NULL COMMENT 'discount at time of creation [0-1]'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='calculated fees for students for each month';

-- --------------------------------------------------------

--
-- Table structure for table `AccedPayments`
--

CREATE TABLE IF NOT EXISTS `AccedPayments` (
  `AccID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `Amount` float NOT NULL,
  `GroupID` int(11) NOT NULL,
  `Updated` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='calculated payments for profs for each month';

-- --------------------------------------------------------

--
-- Table structure for table `BaseWages`
--

CREATE TABLE IF NOT EXISTS `BaseWages` (
  `SalID` int(11) NOT NULL,
  `EchelID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `Wages` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='salaries go according to experience';

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
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Days`
--

CREATE TABLE IF NOT EXISTS `Days` (
  `DayID` tinyint(4) NOT NULL,
  `DayName` varchar(18) CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Departments`
--

CREATE TABLE IF NOT EXISTS `Departments` (
  `DepID` int(11) NOT NULL,
  `DepName` varchar(55) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

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
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='diplomas and levels';

-- --------------------------------------------------------

--
-- Table structure for table `Disciplines`
--

CREATE TABLE IF NOT EXISTS `Disciplines` (
  `DiscID` tinyint(3) unsigned NOT NULL,
  `Name` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Discount`
--

CREATE TABLE IF NOT EXISTS `Discount` (
  `DiscID` int(11) NOT NULL,
  `CatID` tinyint(3) unsigned NOT NULL,
  `Reduce` float NOT NULL,
  `Dat` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='monthly discount only latest value is valid';

-- --------------------------------------------------------

--
-- Table structure for table `DiscountCats`
--

CREATE TABLE IF NOT EXISTS `DiscountCats` (
  `SpecialID` tinyint(3) unsigned NOT NULL,
  `Description` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='ειδικές κατηγορίες : πχ τριτεκνοι ορφανα ';

-- --------------------------------------------------------

--
-- Table structure for table `Dropout`
--

CREATE TABLE IF NOT EXISTS `Dropout` (
  `DropID` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL,
  `StudID` int(11) NOT NULL,
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='categorizee teachers according to experience more experience more wages';

-- --------------------------------------------------------

--
-- Table structure for table `Ensembles`
--

CREATE TABLE IF NOT EXISTS `Ensembles` (
  `EnsPK` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL,
  `StudID` int(11) NOT NULL,
  `Added` date NOT NULL COMMENT 'a  student may be added after the groups creation'
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
  `GroupID` int(11) NOT NULL COMMENT 'we want to know for which group did we got the money',
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
  `LessTypeID` tinyint(4) NOT NULL,
  `BW` float NOT NULL COMMENT ' base wage at time of creation',
  `CW` float NOT NULL COMMENT 'course wage at time of creation',
  `Fee` float NOT NULL COMMENT 'fee at the time of creation'
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
  `RoomID` tinyint(4) NOT NULL COMMENT 'roomid=0 gia ta monima ',
  `Valid` tinyint(1) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Hours`
--

CREATE TABLE IF NOT EXISTS `Hours` (
  `HourID` tinyint(4) NOT NULL COMMENT 'id represents the cell row',
  `HourN` varchar(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Instituts`
--

CREATE TABLE IF NOT EXISTS `Instituts` (
  `InstID` int(11) NOT NULL,
  `Name` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='foreign language instituts';

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
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `LessonType`
--

CREATE TABLE IF NOT EXISTS `LessonType` (
  `TypeID` tinyint(4) NOT NULL,
  `Description` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Meeting`
--

CREATE TABLE IF NOT EXISTS `Meeting` (
  `MeetID` int(11) NOT NULL,
  `SchulerID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `Comments` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Members`
--

CREATE TABLE IF NOT EXISTS `Members` (
  `MembID` int(11) NOT NULL,
  `Name` varchar(80) CHARACTER SET utf8 NOT NULL,
  `FName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `MName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `Address` varchar(80) CHARACTER SET utf8 DEFAULT NULL,
  `Phone` varchar(10) CHARACTER SET utf8 NOT NULL,
  `Mobile` varchar(10) CHARACTER SET utf8 NOT NULL,
  `EMail` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `MembTypeID` tinyint(11) DEFAULT NULL,
  `RegDate` date DEFAULT NULL,
  `BirthDate` date NOT NULL,
  `ADT` varchar(8) CHARACTER SET utf8 NOT NULL COMMENT 'ausweisID'
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `MembTypes`
--

CREATE TABLE IF NOT EXISTS `MembTypes` (
  `MembTypeID` tinyint(11) NOT NULL,
  `MembTypeName` varchar(20) CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `PayKassen`
--

CREATE TABLE IF NOT EXISTS `PayKassen` (
  `SalID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `Wages` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='how much money we will pay each month for health insurance';

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
  `PayTypeID` tinyint(3) unsigned NOT NULL,
  `GroupID` int(11) NOT NULL DEFAULT '0' COMMENT 'for which group lessons was he payed'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='payments to professors';

-- --------------------------------------------------------

--
-- Table structure for table `PayType`
--

CREATE TABLE IF NOT EXISTS `PayType` (
  `PayTypeID` tinyint(3) unsigned NOT NULL,
  `Comment` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='describes the type of payment';

-- --------------------------------------------------------

--
-- Table structure for table `Permament`
--

CREATE TABLE IF NOT EXISTS `Permament` (
  `PermaID` int(11) NOT NULL,
  `GroupID` int(11) NOT NULL DEFAULT '0',
  `StartsOn` date NOT NULL,
  `EndsOn` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='uni and schule courses that take part every week ';

-- --------------------------------------------------------

--
-- Table structure for table `PermaTimes`
--

CREATE TABLE IF NOT EXISTS `PermaTimes` (
  `TimesID` int(11) NOT NULL,
  `PermaID` int(11) NOT NULL,
  `DayID` tinyint(4) NOT NULL,
  `StartHourID` tinyint(4) NOT NULL,
  `Duration` float NOT NULL,
  `RoomID` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='schedule hours and days for diplomas';

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
-- Table structure for table `Roles`
--

CREATE TABLE IF NOT EXISTS `Roles` (
  `RoleID` tinyint(3) unsigned NOT NULL,
  `Description` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
-- Table structure for table `Schuler`
--

CREATE TABLE IF NOT EXISTS `Schuler` (
  `SchulID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `DiscipleID` tinyint(3) unsigned NOT NULL,
  `FatherMobile` varchar(10) NOT NULL,
  `MotherMobile` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='schuler table';

-- --------------------------------------------------------

--
-- Table structure for table `Schwierigkeit`
--

CREATE TABLE IF NOT EXISTS `Schwierigkeit` (
  `SchwerID` tinyint(4) NOT NULL,
  `Red` tinyint(6) unsigned NOT NULL,
  `Green` tinyint(6) unsigned NOT NULL,
  `Blue` tinyint(6) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='color for different difficulty levels from 0 to 10';

-- --------------------------------------------------------

--
-- Table structure for table `SpecialFees`
--

CREATE TABLE IF NOT EXISTS `SpecialFees` (
  `DiscID` int(11) NOT NULL,
  `StudentID` int(11) NOT NULL,
  `CatID` tinyint(3) unsigned NOT NULL,
  `Created` date NOT NULL,
  `Expires` date NOT NULL COMMENT 'discount expires at some date'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='discount scheme for schuler';

-- --------------------------------------------------------

--
-- Table structure for table `TeachEchelon`
--

CREATE TABLE IF NOT EXISTS `TeachEchelon` (
  `TEID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `EchelonID` int(11) NOT NULL,
  `Dat` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='assigns a teacher to an echelon id it can be updated over ti';

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
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='schedule hours and days for diplomas';

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
-- Indexes for table `AccedFees`
--
ALTER TABLE `AccedFees`
  ADD PRIMARY KEY (`AccID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `GroupID` (`GroupID`);

--
-- Indexes for table `AccedPayments`
--
ALTER TABLE `AccedPayments`
  ADD PRIMARY KEY (`AccID`),
  ADD KEY `StudentID` (`TeacherID`),
  ADD KEY `GroupID` (`GroupID`),
  ADD KEY `TeacherID` (`TeacherID`);

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
-- Indexes for table `Disciplines`
--
ALTER TABLE `Disciplines`
  ADD PRIMARY KEY (`DiscID`);

--
-- Indexes for table `Discount`
--
ALTER TABLE `Discount`
  ADD PRIMARY KEY (`DiscID`),
  ADD KEY `CatID` (`CatID`);

--
-- Indexes for table `DiscountCats`
--
ALTER TABLE `DiscountCats`
  ADD PRIMARY KEY (`SpecialID`);

--
-- Indexes for table `Dropout`
--
ALTER TABLE `Dropout`
  ADD PRIMARY KEY (`DropID`),
  ADD KEY `GroupID` (`GroupID`),
  ADD KEY `StudentID` (`StudID`);

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
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `GroupID` (`GroupID`);

--
-- Indexes for table `Groups`
--
ALTER TABLE `Groups`
  ADD PRIMARY KEY (`GroupID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `CourseID` (`CourseID`),
  ADD KEY `BW` (`BW`),
  ADD KEY `LessTypeID` (`LessTypeID`);

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
-- Indexes for table `Meeting`
--
ALTER TABLE `Meeting`
  ADD PRIMARY KEY (`MeetID`),
  ADD KEY `SchulerID` (`SchulerID`),
  ADD KEY `TeacherID` (`TeacherID`);

--
-- Indexes for table `Members`
--
ALTER TABLE `Members`
  ADD PRIMARY KEY (`MembID`),
  ADD UNIQUE KEY `ADT` (`ADT`),
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
  ADD KEY `GroupID` (`GroupID`);

--
-- Indexes for table `PermaTimes`
--
ALTER TABLE `PermaTimes`
  ADD PRIMARY KEY (`TimesID`),
  ADD KEY `DayID` (`DayID`),
  ADD KEY `HourID` (`StartHourID`),
  ADD KEY `SchedID` (`PermaID`),
  ADD KEY `PermaID` (`PermaID`),
  ADD KEY `RoomID` (`RoomID`);

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
-- Indexes for table `Schuler`
--
ALTER TABLE `Schuler`
  ADD PRIMARY KEY (`SchulID`),
  ADD UNIQUE KEY `StudentID_2` (`StudentID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `DiscipleID` (`DiscipleID`);

--
-- Indexes for table `Schwierigkeit`
--
ALTER TABLE `Schwierigkeit`
  ADD PRIMARY KEY (`SchwerID`);

--
-- Indexes for table `SpecialFees`
--
ALTER TABLE `SpecialFees`
  ADD PRIMARY KEY (`DiscID`),
  ADD UNIQUE KEY `StudentID_3` (`StudentID`),
  ADD KEY `CatID` (`CatID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `StudentID_2` (`StudentID`);

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
-- AUTO_INCREMENT for table `AccedFees`
--
ALTER TABLE `AccedFees`
  MODIFY `AccID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `AccedPayments`
--
ALTER TABLE `AccedPayments`
  MODIFY `AccID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `BaseWages`
--
ALTER TABLE `BaseWages`
  MODIFY `SalID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Buildings`
--
ALTER TABLE `Buildings`
  MODIFY `BuildID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Contract`
--
ALTER TABLE `Contract`
  MODIFY `ConID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Courses`
--
ALTER TABLE `Courses`
  MODIFY `CourseID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Days`
--
ALTER TABLE `Days`
  MODIFY `DayID` tinyint(4) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Departments`
--
ALTER TABLE `Departments`
  MODIFY `DepID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Diplomas`
--
ALTER TABLE `Diplomas`
  MODIFY `DiplID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Disciplines`
--
ALTER TABLE `Disciplines`
  MODIFY `DiscID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `DiscountCats`
--
ALTER TABLE `DiscountCats`
  MODIFY `SpecialID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Dropout`
--
ALTER TABLE `Dropout`
  MODIFY `DropID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Echelon`
--
ALTER TABLE `Echelon`
  MODIFY `EchelID` int(11) NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `Expenses`
--
ALTER TABLE `Expenses`
  MODIFY `ExpID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `ExpensesCats`
--
ALTER TABLE `ExpensesCats`
  MODIFY `ExpenseID` smallint(5) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `FeeSchule`
--
ALTER TABLE `FeeSchule`
  MODIFY `FrSchID` int(11) NOT NULL AUTO_INCREMENT;
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
  MODIFY `InstID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Kassen`
--
ALTER TABLE `Kassen`
  MODIFY `KasseID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Languages`
--
ALTER TABLE `Languages`
  MODIFY `LangID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `LessonType`
--
ALTER TABLE `LessonType`
  MODIFY `TypeID` tinyint(4) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Meeting`
--
ALTER TABLE `Meeting`
  MODIFY `MeetID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Members`
--
ALTER TABLE `Members`
  MODIFY `MembID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `MembTypes`
--
ALTER TABLE `MembTypes`
  MODIFY `MembTypeID` tinyint(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `PayKassen`
--
ALTER TABLE `PayKassen`
  MODIFY `SalID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Payments`
--
ALTER TABLE `Payments`
  MODIFY `PayID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `PayType`
--
ALTER TABLE `PayType`
  MODIFY `PayTypeID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Permament`
--
ALTER TABLE `Permament`
  MODIFY `PermaID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `PermaTimes`
--
ALTER TABLE `PermaTimes`
  MODIFY `TimesID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Receipts`
--
ALTER TABLE `Receipts`
  MODIFY `ReceiptID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `ReceiptType`
--
ALTER TABLE `ReceiptType`
  MODIFY `TypeID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `Roles`
--
ALTER TABLE `Roles`
  MODIFY `RoleID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `Schuler`
--
ALTER TABLE `Schuler`
  MODIFY `SchulID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Schwierigkeit`
--
ALTER TABLE `Schwierigkeit`
  MODIFY `SchwerID` tinyint(4) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `SpecialFees`
--
ALTER TABLE `SpecialFees`
  MODIFY `DiscID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `TeachEchelon`
--
ALTER TABLE `TeachEchelon`
  MODIFY `TEID` int(11) NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `Users`
--
ALTER TABLE `Users`
  MODIFY `UserID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
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
-- Constraints for table `AccedFees`
--
ALTER TABLE `AccedFees`
  ADD CONSTRAINT `AccedFees_ibfk_1` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `AccedFees_ibfk_2` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`);

--
-- Constraints for table `AccedPayments`
--
ALTER TABLE `AccedPayments`
  ADD CONSTRAINT `AccedPayments_ibfk_1` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`),
  ADD CONSTRAINT `AccedPayments_ibfk_2` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `BaseWages`
--
ALTER TABLE `BaseWages`
  ADD CONSTRAINT `fkechelid` FOREIGN KEY (`EchelID`) REFERENCES `Echelon` (`EchelID`);

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
-- Constraints for table `Discount`
--
ALTER TABLE `Discount`
  ADD CONSTRAINT `Discount_ibfk_1` FOREIGN KEY (`CatID`) REFERENCES `DiscountCats` (`SpecialID`);

--
-- Constraints for table `Dropout`
--
ALTER TABLE `Dropout`
  ADD CONSTRAINT `fkkropid` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`),
  ADD CONSTRAINT `flsid` FOREIGN KEY (`StudID`) REFERENCES `Members` (`MembID`);

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
  ADD CONSTRAINT `Funds_ibfk_1` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`),
  ADD CONSTRAINT `studid` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

--
-- Constraints for table `Groups`
--
ALTER TABLE `Groups`
  ADD CONSTRAINT `Groups_ibfk_3` FOREIGN KEY (`LessTypeID`) REFERENCES `LessonType` (`TypeID`),
  ADD CONSTRAINT `csrid` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
  ADD CONSTRAINT `teach` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `History`
--
ALTER TABLE `History`
  ADD CONSTRAINT `fkhourid` FOREIGN KEY (`StartHourID`) REFERENCES `Hours` (`HourID`),
  ADD CONSTRAINT `fkroom` FOREIGN KEY (`RoomID`) REFERENCES `Rooms` (`RoomID`),
  ADD CONSTRAINT `group` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`);

--
-- Constraints for table `Meeting`
--
ALTER TABLE `Meeting`
  ADD CONSTRAINT `Meeting_ibfk_1` FOREIGN KEY (`SchulerID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `Meeting_ibfk_2` FOREIGN KEY (`TeacherID`) REFERENCES `Members` (`MembID`);

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
  ADD CONSTRAINT `Permament_ibfk_1` FOREIGN KEY (`GroupID`) REFERENCES `Groups` (`GroupID`);

--
-- Constraints for table `PermaTimes`
--
ALTER TABLE `PermaTimes`
  ADD CONSTRAINT `PermaTimes_ibfk_1` FOREIGN KEY (`PermaID`) REFERENCES `Permament` (`PermaID`),
  ADD CONSTRAINT `PermaTimes_ibfk_2` FOREIGN KEY (`DayID`) REFERENCES `Days` (`DayID`),
  ADD CONSTRAINT `PermaTimes_ibfk_3` FOREIGN KEY (`StartHourID`) REFERENCES `Hours` (`HourID`),
  ADD CONSTRAINT `PermaTimes_ibfk_4` FOREIGN KEY (`RoomID`) REFERENCES `Rooms` (`RoomID`);

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
-- Constraints for table `Schuler`
--
ALTER TABLE `Schuler`
  ADD CONSTRAINT `Schuler_ibfk_1` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`),
  ADD CONSTRAINT `Schuler_ibfk_2` FOREIGN KEY (`DiscipleID`) REFERENCES `Disciplines` (`DiscID`);

--
-- Constraints for table `SpecialFees`
--
ALTER TABLE `SpecialFees`
  ADD CONSTRAINT `SpecialFees_ibfk_1` FOREIGN KEY (`CatID`) REFERENCES `DiscountCats` (`SpecialID`),
  ADD CONSTRAINT `SpecialFees_ibfk_2` FOREIGN KEY (`StudentID`) REFERENCES `Members` (`MembID`);

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
