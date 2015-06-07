-- phpMyAdmin SQL Dump
-- version 4.4.8
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 07, 2015 at 06:21 PM
-- Server version: 10.0.19-MariaDB
-- PHP Version: 5.6.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `NoSQL`
--

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
-- Table structure for table `Instituts`
--

CREATE TABLE IF NOT EXISTS `Instituts` (
  `InstID` int(11) NOT NULL,
  `Name` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='foreign language instituts';

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
-- Table structure for table `Roles`
--

CREATE TABLE IF NOT EXISTS `Roles` (
  `RoleID` tinyint(3) unsigned NOT NULL,
  `Description` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
-- Table structure for table `TeachSprache`
--

CREATE TABLE IF NOT EXISTS `TeachSprache` (
  `SPID` int(11) NOT NULL,
  `TeacherID` int(11) NOT NULL,
  `DiplomaID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='welche Sprachen kann ein Lehrer lehren?';

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
-- Table structure for table `WagesSprache`
--

CREATE TABLE IF NOT EXISTS `WagesSprache` (
  `WageSpracheID` int(11) NOT NULL,
  `EchelID` int(11) NOT NULL,
  `Dat` date NOT NULL,
  `SchedID` int(11) NOT NULL,
  `Wage` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf32 COMMENT='each schedule has a different fare';

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Diplomas`
--
ALTER TABLE `Diplomas`
  ADD PRIMARY KEY (`DiplID`),
  ADD KEY `LangID` (`LangID`),
  ADD KEY `ProvID` (`ProvID`),
  ADD KEY `Schwer` (`Schwer`);

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
-- Indexes for table `FeeSprache`
--
ALTER TABLE `FeeSprache`
  ADD PRIMARY KEY (`FspID`),
  ADD KEY `SchedID` (`SchedID`);

--
-- Indexes for table `Instituts`
--
ALTER TABLE `Instituts`
  ADD PRIMARY KEY (`InstID`);

--
-- Indexes for table `Languages`
--
ALTER TABLE `Languages`
  ADD PRIMARY KEY (`LangID`);

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
-- Indexes for table `RequestSprache`
--
ALTER TABLE `RequestSprache`
  ADD PRIMARY KEY (`RequestID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `ScheduleID` (`ScheduleID`);

--
-- Indexes for table `Roles`
--
ALTER TABLE `Roles`
  ADD PRIMARY KEY (`RoleID`);

--
-- Indexes for table `Schedule`
--
ALTER TABLE `Schedule`
  ADD PRIMARY KEY (`SchedID`),
  ADD KEY `DiploID` (`DiploID`);

--
-- Indexes for table `TeachSprache`
--
ALTER TABLE `TeachSprache`
  ADD PRIMARY KEY (`SPID`),
  ADD KEY `TeacherID` (`TeacherID`),
  ADD KEY `DiplomaID` (`DiplomaID`);

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
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`UserID`),
  ADD KEY `RoleID` (`RoleID`);

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
-- AUTO_INCREMENT for table `Diplomas`
--
ALTER TABLE `Diplomas`
  MODIFY `DiplID` int(11) NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `FeeSprache`
--
ALTER TABLE `FeeSprache`
  MODIFY `FspID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Instituts`
--
ALTER TABLE `Instituts`
  MODIFY `InstID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Languages`
--
ALTER TABLE `Languages`
  MODIFY `LangID` int(11) NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `RequestSprache`
--
ALTER TABLE `RequestSprache`
  MODIFY `RequestID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Roles`
--
ALTER TABLE `Roles`
  MODIFY `RoleID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Schedule`
--
ALTER TABLE `Schedule`
  MODIFY `SchedID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `TeachSprache`
--
ALTER TABLE `TeachSprache`
  MODIFY `SPID` int(11) NOT NULL AUTO_INCREMENT;
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
-- AUTO_INCREMENT for table `Users`
--
ALTER TABLE `Users`
  MODIFY `UserID` tinyint(3) unsigned NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `WagesSprache`
--
ALTER TABLE `WagesSprache`
  MODIFY `WageSpracheID` int(11) NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
