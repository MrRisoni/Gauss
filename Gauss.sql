-- phpMyAdmin SQL Dump
-- version 4.4.13.1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Sep 23, 2015 at 06:34 PM
-- Server version: 10.0.21-MariaDB
-- PHP Version: 5.6.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `Gauss`
--

-- --------------------------------------------------------

--
-- Table structure for table `Absent`
--

CREATE TABLE IF NOT EXISTS `Absent` (
  `StudentID` int(11) unsigned NOT NULL,
  `HistID` int(11) unsigned NOT NULL,
  `Truant` tinyint(1) unsigned NOT NULL DEFAULT '1' COMMENT 'if truant is - that means there was a very serious reason for this absence dont calc fee'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='show when a student was absent';

-- --------------------------------------------------------

--
-- Table structure for table `BaseWages`
--

CREATE TABLE IF NOT EXISTS `BaseWages` (
  `SalID` int(11) unsigned NOT NULL,
  `EchelID` int(11) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `Wages` float unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='salaries go according to experience';

-- --------------------------------------------------------

--
-- Table structure for table `Buildings`
--

CREATE TABLE IF NOT EXISTS `Buildings` (
  `BuildID` tinyint(3) unsigned NOT NULL,
  `Address` varchar(45) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Buildings`
--

INSERT INTO `Buildings` (`BuildID`, `Address`) VALUES
(1, 'ΜΕΣΣΗΝΙΑΣ ΚΑΙ ΣΟΥΛΙΟΥ 4, ΓΕΡΑΚΑΣ'),
(2, 'ΦΡΑΓΚΟΚΛΗΣΣΙΑΣ 15 , ΜΑΡΟΥΣΙ'),
(3, 'ΑΧΑΡΝΩΝ 65'),
(4, 'ΧΑΡΙΛΑΟΥ ΤΡΙΚΟΥΠΗ 178 Μ ΚΙΦΗΣΙΑΣ');

-- --------------------------------------------------------

--
-- Table structure for table `Contract`
--

CREATE TABLE IF NOT EXISTS `Contract` (
  `TeacherID` int(11) unsigned NOT NULL,
  `End` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='end date of Contract';

-- --------------------------------------------------------

--
-- Table structure for table `Days`
--

CREATE TABLE IF NOT EXISTS `Days` (
  `DayID` tinyint(4) unsigned NOT NULL,
  `DayName` varchar(18) CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf32;

--
-- Dumping data for table `Days`
--

INSERT INTO `Days` (`DayID`, `DayName`) VALUES
(1, 'Sunday'),
(2, 'Monday'),
(3, 'Tuesday'),
(4, 'Wednesday'),
(5, 'Thursday'),
(6, 'Friday'),
(7, 'Saturday');

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
(1, 'ΠΟΛΙΤΙΚΟΙ ΜΗΧΑΝΙΚΟΙ'),
(2, 'ΗΛΕΚΤΡΟΛΟΓΟΙ ΜΗΧΑΝΙΚΟΙ'),
(3, 'ΠΛΗΡΟΦΟΡΙΚΗ');

-- --------------------------------------------------------

--
-- Table structure for table `Diplomas`
--

CREATE TABLE IF NOT EXISTS `Diplomas` (
  `DiplID` tinyint(3) unsigned NOT NULL,
  `LangID` tinyint(3) unsigned NOT NULL,
  `ProvID` tinyint(3) unsigned NOT NULL COMMENT 'institut provider',
  `FachID` int(10) unsigned NOT NULL,
  `Schwer` tinyint(4) unsigned NOT NULL COMMENT 'higherr is more difficult',
  `Active` tinyint(1) unsigned NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='diplomas and levels';

-- --------------------------------------------------------

--
-- Table structure for table `Disciplines`
--

CREATE TABLE IF NOT EXISTS `Disciplines` (
  `DiscID` tinyint(3) unsigned NOT NULL,
  `Name` varchar(45) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `Disciplines`
--

INSERT INTO `Disciplines` (`DiscID`, `Name`) VALUES
(1, 'ΑΝΘΡΩΠΙΣΤΙΚΕΣ'),
(2, 'ΘΕΤΙΚΕΣ'),
(3, 'ΠΛΗΡΟΦΟΡΙΚΗ'),
(4, 'ΥΓΕΙΑ'),
(5, 'ΟΙΚΟΝΟΜΙΚΑ');

-- --------------------------------------------------------

--
-- Table structure for table `Discount`
--

CREATE TABLE IF NOT EXISTS `Discount` (
  `DiscID` int(11) unsigned NOT NULL,
  `CatID` tinyint(3) unsigned NOT NULL,
  `Reduce` float unsigned NOT NULL,
  `Dat` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='monthly discount only latest value is valid';

-- --------------------------------------------------------

--
-- Table structure for table `DiscountCats`
--

CREATE TABLE IF NOT EXISTS `DiscountCats` (
  `SpecialID` tinyint(3) unsigned NOT NULL,
  `Description` varchar(30) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COMMENT='ειδικές κατηγορίες : πχ τριτεκνοι ορφανα ';

--
-- Dumping data for table `DiscountCats`
--

INSERT INTO `DiscountCats` (`SpecialID`, `Description`) VALUES
(1, 'ΚΑΜΙΑ'),
(2, 'ΠΟΛΥΤΕΚΝΟΙ'),
(3, 'ΟΡΦΑΝΑ'),
(4, 'ΑΝΑΠΗΡΙΑ'),
(5, 'ΤΡΙΤΕΚΝΟΙ');

-- --------------------------------------------------------

--
-- Table structure for table `Echelon`
--

CREATE TABLE IF NOT EXISTS `Echelon` (
  `EchelID` int(11) unsigned NOT NULL,
  `Exp` int(11) unsigned NOT NULL COMMENT 'exp in months',
  `Active` tinyint(1) unsigned DEFAULT '1'
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
  `GroupID` int(11) unsigned NOT NULL,
  `StudID` int(11) unsigned NOT NULL,
  `Added` date NOT NULL COMMENT 'a  student may be added after the groups creation',
  `Dropped` date NOT NULL COMMENT 'a student may decide to drop from a group we need to know when'
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Erlaubnis`
--

CREATE TABLE IF NOT EXISTS `Erlaubnis` (
  `TeacherID` int(11) unsigned NOT NULL,
  `StartDat` date NOT NULL,
  `EndDat` date NOT NULL,
  `DaysLeft` tinyint(4) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='days off ';

-- --------------------------------------------------------

--
-- Table structure for table `Exam`
--

CREATE TABLE IF NOT EXISTS `Exam` (
  `TestID` int(11) unsigned NOT NULL,
  `FachID` int(11) unsigned NOT NULL,
  `ExamDat` date NOT NULL,
  `StudentID` int(11) unsigned NOT NULL,
  `Grade` float unsigned NOT NULL COMMENT 'average pass grade'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='exam results';

-- --------------------------------------------------------

--
-- Table structure for table `Expenses`
--

CREATE TABLE IF NOT EXISTS `Expenses` (
  `ExpID` int(11) NOT NULL,
  `ExpCat` smallint(5) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `Amount` float unsigned NOT NULL,
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
-- Table structure for table `Fache`
--

CREATE TABLE IF NOT EXISTS `Fache` (
  `FachID` int(11) unsigned NOT NULL,
  `FachTypeID` tinyint(3) unsigned NOT NULL COMMENT '1 school 2 uni 3 sprache',
  `Name` varchar(120) NOT NULL,
  `Active` tinyint(1) unsigned NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `FachType`
--

CREATE TABLE IF NOT EXISTS `FachType` (
  `TypeID` tinyint(4) NOT NULL,
  `Description` varchar(10) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `FachType`
--

INSERT INTO `FachType` (`TypeID`, `Description`) VALUES
(1, 'Schule'),
(2, 'Uni'),
(3, 'Sprache');

-- --------------------------------------------------------

--
-- Table structure for table `Fee`
--

CREATE TABLE IF NOT EXISTS `Fee` (
  `FspID` int(11) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `FachID` int(11) unsigned NOT NULL,
  `ScheduleID` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'this is only for sprache courses',
  `Fee` float unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='each course has a different fare';

-- --------------------------------------------------------

--
-- Table structure for table `Funds`
--

CREATE TABLE IF NOT EXISTS `Funds` (
  `FundID` int(11) unsigned NOT NULL,
  `StudentID` int(11) unsigned NOT NULL,
  `GroupID` int(11) unsigned NOT NULL COMMENT 'we want to know for which group did we got the money',
  `Dat` date NOT NULL,
  `Amount` float unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='money we received from students';

-- --------------------------------------------------------

--
-- Table structure for table `Groups`
--

CREATE TABLE IF NOT EXISTS `Groups` (
  `GroupID` int(11) unsigned NOT NULL,
  `TeacherID` int(11) unsigned NOT NULL,
  `FachID` int(11) unsigned NOT NULL,
  `StartDate` date NOT NULL,
  `Active` tinyint(4) unsigned NOT NULL DEFAULT '1',
  `Skype` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'is lesson is via internet set this to 1'
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `History`
--

CREATE TABLE IF NOT EXISTS `History` (
  `HistID` int(11) unsigned NOT NULL,
  `GroupID` int(11) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `StartHourID` tinyint(4) unsigned NOT NULL,
  `Duration` float unsigned NOT NULL,
  `RoomID` tinyint(4) unsigned NOT NULL COMMENT 'roomid=0 gia ta monima ',
  `Valid` tinyint(1) unsigned NOT NULL DEFAULT '1',
  `bw` float unsigned NOT NULL,
  `cw` float unsigned NOT NULL,
  `fee` float unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Hours`
--

CREATE TABLE IF NOT EXISTS `Hours` (
  `HourID` tinyint(4) unsigned NOT NULL COMMENT 'id represents the cell row',
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
  `InstID` tinyint(4) NOT NULL,
  `Name` varchar(60) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf32 COMMENT='foreign language instituts';

--
-- Dumping data for table `Instituts`
--

INSERT INTO `Instituts` (`InstID`, `Name`) VALUES
(1, 'Goethe'),
(2, 'Cambridge'),
(3, 'Michigan'),
(4, 'Sorbonne'),
(5, 'Institut Française');

-- --------------------------------------------------------

--
-- Table structure for table `Kassen`
--

CREATE TABLE IF NOT EXISTS `Kassen` (
  `KasseID` tinyint(3) unsigned NOT NULL,
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
  `LangID` tinyint(3) unsigned NOT NULL,
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
  `MembID` int(11) unsigned NOT NULL,
  `Name` varchar(80) CHARACTER SET utf8 NOT NULL,
  `FName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `MName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `Address` varchar(80) CHARACTER SET utf8 DEFAULT NULL,
  `Phone` varchar(10) CHARACTER SET utf8 NOT NULL,
  `Mobile` varchar(10) CHARACTER SET utf8 NOT NULL,
  `EMail` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `MembTypeID` tinyint(11) unsigned DEFAULT NULL,
  `RegDate` date DEFAULT NULL,
  `BirthDate` date NOT NULL,
  `ADT` varchar(8) CHARACTER SET utf8 NOT NULL COMMENT 'ausweisID'
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `MembTypes`
--

CREATE TABLE IF NOT EXISTS `MembTypes` (
  `MembTypeID` tinyint(11) unsigned NOT NULL,
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
  `SalID` int(11) unsigned NOT NULL,
  `TeacherID` int(11) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `Wages` float unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='how much money we will pay each month for health insurance';

-- --------------------------------------------------------

--
-- Table structure for table `Payments`
--

CREATE TABLE IF NOT EXISTS `Payments` (
  `PayID` int(11) unsigned NOT NULL,
  `TeacherID` int(11) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `Amount` float unsigned NOT NULL,
  `Comments` varchar(100) DEFAULT NULL COMMENT 'what did we pay him for?',
  `PayTypeID` tinyint(3) unsigned NOT NULL,
  `GroupID` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'for which group lessons was he payed'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='payments to professors';

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
  `GroupID` int(11) unsigned NOT NULL DEFAULT '0',
  `StartsOn` date NOT NULL,
  `EndsOn` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='uni and schule courses that take part every week ';

-- --------------------------------------------------------

--
-- Table structure for table `PermaTimes`
--

CREATE TABLE IF NOT EXISTS `PermaTimes` (
  `TimesID` int(11) unsigned NOT NULL,
  `PermaID` int(11) unsigned NOT NULL,
  `DayID` tinyint(4) unsigned NOT NULL,
  `StartHourID` tinyint(4) unsigned NOT NULL,
  `Duration` float unsigned NOT NULL,
  `RoomID` tinyint(4) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='schedule hours and days for diplomas';

-- --------------------------------------------------------

--
-- Table structure for table `Receipts`
--

CREATE TABLE IF NOT EXISTS `Receipts` (
  `ReceiptID` int(11) unsigned NOT NULL,
  `TypeID` tinyint(3) unsigned NOT NULL,
  `PersonID` int(11) unsigned NOT NULL COMMENT 'which of our member signed the receipt',
  `EmployerID` tinyint(11) unsigned NOT NULL COMMENT 'which employer signed the receipt',
  `Date` date NOT NULL,
  `Money` float unsigned NOT NULL
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
-- Table structure for table `Requests`
--

CREATE TABLE IF NOT EXISTS `Requests` (
  `RequestID` int(11) unsigned NOT NULL,
  `StudentID` int(11) unsigned NOT NULL,
  `FachID` int(10) unsigned NOT NULL,
  `ScheduleID` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'only for language',
  `Settled` tinyint(4) unsigned NOT NULL DEFAULT '0' COMMENT '0 unsettled 1 settled 2 closed group',
  `ReqDate` date NOT NULL,
  `Comments` varchar(300) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32;

-- --------------------------------------------------------

--
-- Table structure for table `Rooms`
--

CREATE TABLE IF NOT EXISTS `Rooms` (
  `RoomID` tinyint(4) unsigned NOT NULL,
  `BuildID` int(4) unsigned NOT NULL,
  `Name` varchar(15) NOT NULL,
  `Capacity` tinyint(4) unsigned NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf32;

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
(10, 2, 'ΑΝΔΡΟΜΑΧΗ', 9),
(11, 3, 'ΠΟΣΕΙΔΩΝΑΣ', 17),
(12, 3, 'ΦΘΑΕΘΩΝ', 17),
(13, 3, 'ΡΩΞΑΝΗ', 16),
(14, 4, 'ΠΑΝΔΩΡΑ', 14),
(15, 3, 'ΕΡΜΗΣ', 13),
(16, 2, 'ΚΛΩΘΩ', 10),
(17, 4, 'ΑΠΟΛΛΩΝΑΣ', 10),
(18, 1, 'ΠΕΡΣΕΦΟΝΗ', 11);

-- --------------------------------------------------------

--
-- Table structure for table `Schedule`
--

CREATE TABLE IF NOT EXISTS `Schedule` (
  `SchedID` int(11) unsigned NOT NULL,
  `Active` tinyint(4) unsigned NOT NULL DEFAULT '1',
  `AgeLow` tinyint(4) unsigned NOT NULL COMMENT 'age group',
  `AgeTop` tinyint(4) unsigned NOT NULL,
  `Comments` varchar(180) NOT NULL COMMENT 'other comments',
  `Title` varchar(60) NOT NULL,
  `DiploID` tinyint(3) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='there are of course different schedules for learning lanuages';

-- --------------------------------------------------------

--
-- Table structure for table `SchuleCourses`
--

CREATE TABLE IF NOT EXISTS `SchuleCourses` (
  `FachID` int(10) unsigned NOT NULL,
  `DiscipleID` tinyint(3) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Schuler`
--

CREATE TABLE IF NOT EXISTS `Schuler` (
  `SchulID` int(11) unsigned NOT NULL,
  `StudentID` int(11) unsigned NOT NULL,
  `DiscipleID` tinyint(3) unsigned NOT NULL,
  `FatherMobile` varchar(10) NOT NULL,
  `MotherMobile` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='schuler table';

-- --------------------------------------------------------

--
-- Table structure for table `Schwierigkeit`
--

CREATE TABLE IF NOT EXISTS `Schwierigkeit` (
  `SchwerID` tinyint(4) unsigned NOT NULL,
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
-- Table structure for table `ShouldBePayed`
--

CREATE TABLE IF NOT EXISTS `ShouldBePayed` (
  `StudentID` int(11) unsigned NOT NULL,
  `Amount` float unsigned NOT NULL,
  `GroupID` int(11) unsigned NOT NULL,
  `Updated` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='calculated fees for students discount at time of group creation';

-- --------------------------------------------------------

--
-- Table structure for table `ShouldPay`
--

CREATE TABLE IF NOT EXISTS `ShouldPay` (
  `GroupID` int(11) unsigned NOT NULL,
  `Amount` float unsigned NOT NULL,
  `Updated` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='calculated payments for profs for each month';

-- --------------------------------------------------------

--
-- Table structure for table `SpecialFees`
--

CREATE TABLE IF NOT EXISTS `SpecialFees` (
  `DiscID` int(11) unsigned NOT NULL,
  `StudentID` int(11) unsigned NOT NULL,
  `CatID` tinyint(3) unsigned NOT NULL,
  `Created` date NOT NULL,
  `Expires` date NOT NULL COMMENT 'discount expires at some date'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='discount scheme for schuler';

-- --------------------------------------------------------

--
-- Table structure for table `TeachEchelon`
--

CREATE TABLE IF NOT EXISTS `TeachEchelon` (
  `TEID` int(11) unsigned NOT NULL,
  `TeacherID` int(11) unsigned NOT NULL,
  `EchelonID` int(11) unsigned NOT NULL,
  `Dat` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='assigns a teacher to an echelon id it can be updated over ti';

-- --------------------------------------------------------

--
-- Table structure for table `TeachFach`
--

CREATE TABLE IF NOT EXISTS `TeachFach` (
  `TeacherID` int(11) unsigned NOT NULL,
  `FachID` int(11) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='welche Fache kann ein Lehrer lehren?';

-- --------------------------------------------------------

--
-- Table structure for table `Tests`
--

CREATE TABLE IF NOT EXISTS `Tests` (
  `StudID` int(11) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `FachID` int(11) unsigned NOT NULL,
  `Grade` float unsigned NOT NULL COMMENT 'from 0 to 100'
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='in house tests aka student progress';

-- --------------------------------------------------------

--
-- Table structure for table `Times`
--

CREATE TABLE IF NOT EXISTS `Times` (
  `TimesID` int(11) unsigned NOT NULL,
  `SchedID` int(11) unsigned NOT NULL,
  `DayID` tinyint(4) unsigned NOT NULL,
  `HourID` tinyint(4) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='schedule hours and days for diplomas';

-- --------------------------------------------------------

--
-- Table structure for table `Unavailable`
--

CREATE TABLE IF NOT EXISTS `Unavailable` (
  `UnavailID` int(11) unsigned NOT NULL,
  `TeacherID` int(11) unsigned NOT NULL,
  `DayID` tinyint(4) unsigned NOT NULL,
  `HourID` tinyint(4) unsigned NOT NULL,
  `Duration` float unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='days which the prof is unavailable';

-- --------------------------------------------------------

--
-- Table structure for table `UniCourses`
--

CREATE TABLE IF NOT EXISTS `UniCourses` (
  `FachID` int(10) unsigned NOT NULL,
  `DepID` int(10) unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Versicherung`
--

CREATE TABLE IF NOT EXISTS `Versicherung` (
  `SicherID` int(11) unsigned NOT NULL,
  `TeacherID` int(11) unsigned NOT NULL,
  `KasseID` int(11) unsigned NOT NULL,
  `AFM` varchar(9) NOT NULL,
  `AMKA` varchar(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `WagesSprache`
--

CREATE TABLE IF NOT EXISTS `WagesSprache` (
  `WageSpracheID` int(11) unsigned NOT NULL,
  `EchelID` int(11) unsigned NOT NULL,
  `Dat` date NOT NULL,
  `SchedID` int(11) unsigned NOT NULL,
  `Wage` float unsigned NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='each schedule has a different fare';

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Absent`
--
ALTER TABLE `Absent`
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
-- Indexes for table `Contract`
--
ALTER TABLE `Contract`
  ADD KEY `TeacherID` (`TeacherID`);

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
-- Indexes for table `Echelon`
--
ALTER TABLE `Echelon`
  ADD PRIMARY KEY (`EchelID`);

--
-- Indexes for table `Ensembles`
--
ALTER TABLE `Ensembles`
  ADD KEY `GroupID` (`GroupID`),
  ADD KEY `StudID` (`StudID`);

--
-- Indexes for table `Erlaubnis`
--
ALTER TABLE `Erlaubnis`
  ADD KEY `TeacherID` (`TeacherID`);

--
-- Indexes for table `Exam`
--
ALTER TABLE `Exam`
  ADD PRIMARY KEY (`TestID`),
  ADD KEY `DiplID` (`FachID`),
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
-- Indexes for table `Fache`
--
ALTER TABLE `Fache`
  ADD PRIMARY KEY (`FachID`),
  ADD KEY `DepID` (`FachTypeID`);

--
-- Indexes for table `FachType`
--
ALTER TABLE `FachType`
  ADD PRIMARY KEY (`TypeID`);

--
-- Indexes for table `Fee`
--
ALTER TABLE `Fee`
  ADD PRIMARY KEY (`FspID`),
  ADD KEY `SchedID` (`FachID`);

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
  ADD KEY `CourseID` (`FachID`),
  ADD KEY `LessTypeID` (`Skype`);

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
  ADD PRIMARY KEY (`GroupID`);

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
-- Indexes for table `Requests`
--
ALTER TABLE `Requests`
  ADD PRIMARY KEY (`RequestID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `ScheduleID` (`ScheduleID`);

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
-- Indexes for table `ShouldBePayed`
--
ALTER TABLE `ShouldBePayed`
  ADD PRIMARY KEY (`StudentID`,`GroupID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `GroupID` (`GroupID`);

--
-- Indexes for table `ShouldPay`
--
ALTER TABLE `ShouldPay`
  ADD PRIMARY KEY (`GroupID`),
  ADD KEY `GroupID` (`GroupID`);

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
-- Indexes for table `TeachFach`
--
ALTER TABLE `TeachFach`
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `DiplomaID` (`FachID`);

--
-- Indexes for table `Tests`
--
ALTER TABLE `Tests`
  ADD KEY `StudID` (`StudID`),
  ADD KEY `CourseID` (`FachID`);

--
-- Indexes for table `Times`
--
ALTER TABLE `Times`
  ADD PRIMARY KEY (`TimesID`),
  ADD KEY `DayID` (`DayID`),
  ADD KEY `HourID` (`HourID`),
  ADD KEY `SchedID` (`SchedID`);

--
-- Indexes for table `Unavailable`
--
ALTER TABLE `Unavailable`
  ADD PRIMARY KEY (`UnavailID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `DayID` (`DayID`),
  ADD KEY `HourID` (`HourID`);

--
-- Indexes for table `Versicherung`
--
ALTER TABLE `Versicherung`
  ADD PRIMARY KEY (`SicherID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `KasseID` (`KasseID`);

--
-- Indexes for table `WagesSprache`
--
ALTER TABLE `WagesSprache`
  ADD PRIMARY KEY (`WageSpracheID`),
  ADD KEY `EchelID` (`EchelID`),
  ADD KEY `SchedID` (`SchedID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `BaseWages`
--
ALTER TABLE `BaseWages`
  MODIFY `SalID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Buildings`
--
ALTER TABLE `Buildings`
  MODIFY `BuildID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Days`
--
ALTER TABLE `Days`
  MODIFY `DayID` tinyint(4) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT for table `Departments`
--
ALTER TABLE `Departments`
  MODIFY `DepID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `Diplomas`
--
ALTER TABLE `Diplomas`
  MODIFY `DiplID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Disciplines`
--
ALTER TABLE `Disciplines`
  MODIFY `DiscID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `DiscountCats`
--
ALTER TABLE `DiscountCats`
  MODIFY `SpecialID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `Echelon`
--
ALTER TABLE `Echelon`
  MODIFY `EchelID` int(11) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Exam`
--
ALTER TABLE `Exam`
  MODIFY `TestID` int(11) unsigned NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `Fache`
--
ALTER TABLE `Fache`
  MODIFY `FachID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `FachType`
--
ALTER TABLE `FachType`
  MODIFY `TypeID` tinyint(4) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Fee`
--
ALTER TABLE `Fee`
  MODIFY `FspID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Funds`
--
ALTER TABLE `Funds`
  MODIFY `FundID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Groups`
--
ALTER TABLE `Groups`
  MODIFY `GroupID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `History`
--
ALTER TABLE `History`
  MODIFY `HistID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Hours`
--
ALTER TABLE `Hours`
  MODIFY `HourID` tinyint(4) unsigned NOT NULL AUTO_INCREMENT COMMENT 'id represents the cell row',AUTO_INCREMENT=30;
--
-- AUTO_INCREMENT for table `Instituts`
--
ALTER TABLE `Instituts`
  MODIFY `InstID` tinyint(4) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `Kassen`
--
ALTER TABLE `Kassen`
  MODIFY `KasseID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `Languages`
--
ALTER TABLE `Languages`
  MODIFY `LangID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT for table `Members`
--
ALTER TABLE `Members`
  MODIFY `MembID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `MembTypes`
--
ALTER TABLE `MembTypes`
  MODIFY `MembTypeID` tinyint(11) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `PayKassen`
--
ALTER TABLE `PayKassen`
  MODIFY `SalID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Payments`
--
ALTER TABLE `Payments`
  MODIFY `PayID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `PayType`
--
ALTER TABLE `PayType`
  MODIFY `PayTypeID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `PermaTimes`
--
ALTER TABLE `PermaTimes`
  MODIFY `TimesID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Receipts`
--
ALTER TABLE `Receipts`
  MODIFY `ReceiptID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `ReceiptType`
--
ALTER TABLE `ReceiptType`
  MODIFY `TypeID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `Requests`
--
ALTER TABLE `Requests`
  MODIFY `RequestID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Rooms`
--
ALTER TABLE `Rooms`
  MODIFY `RoomID` tinyint(4) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=19;
--
-- AUTO_INCREMENT for table `Schedule`
--
ALTER TABLE `Schedule`
  MODIFY `SchedID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Schuler`
--
ALTER TABLE `Schuler`
  MODIFY `SchulID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Schwierigkeit`
--
ALTER TABLE `Schwierigkeit`
  MODIFY `SchwerID` tinyint(4) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=14;
--
-- AUTO_INCREMENT for table `SpecialFees`
--
ALTER TABLE `SpecialFees`
  MODIFY `DiscID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `TeachEchelon`
--
ALTER TABLE `TeachEchelon`
  MODIFY `TEID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Times`
--
ALTER TABLE `Times`
  MODIFY `TimesID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Unavailable`
--
ALTER TABLE `Unavailable`
  MODIFY `UnavailID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Versicherung`
--
ALTER TABLE `Versicherung`
  MODIFY `SicherID` int(11) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `WagesSprache`
--
ALTER TABLE `WagesSprache`
  MODIFY `WageSpracheID` int(11) unsigned NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
