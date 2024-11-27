-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 27, 2024 at 08:38 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `educloud`
--

-- --------------------------------------------------------

--
-- Table structure for table `assignment`
--

CREATE TABLE `assignment` (
                              `Id` varchar(36) NOT NULL DEFAULT uuid(),
                              `Name` varchar(255) NOT NULL,
                              `Content` text DEFAULT NULL,
                              `Grade` varchar(255) DEFAULT NULL,
                              `Description` text DEFAULT NULL,
                              `CreatedAt` datetime DEFAULT current_timestamp(),
                              `UpdatedAt` datetime DEFAULT current_timestamp() ON UPDATE current_timestamp(),
                              `CategoryId` varchar(36) DEFAULT NULL,
                              `ProfessionId` varchar(36) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `category`
--

CREATE TABLE `category` (
                            `Id` varchar(36) NOT NULL DEFAULT uuid(),
                            `CategoryName` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `grade`
--

CREATE TABLE `grade` (
                         `Id` varchar(36) NOT NULL DEFAULT uuid(),
                         `GradeName` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `profession`
--

CREATE TABLE `profession` (
                              `Id` varchar(36) NOT NULL DEFAULT uuid(),
                              `ProfessionName` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `subject`
--

CREATE TABLE `subject` (
                           `Id` varchar(36) NOT NULL DEFAULT uuid(),
                           `Name` varchar(255) NOT NULL,
                           `Content` text DEFAULT NULL,
                           `Grade` varchar(255) DEFAULT NULL,
                           `Description` text DEFAULT NULL,
                           `CreatedAt` datetime DEFAULT current_timestamp(),
                           `UpdatedAt` datetime DEFAULT current_timestamp() ON UPDATE current_timestamp(),
                           `CategoryId` varchar(36) DEFAULT NULL,
                           `ProfessionId` varchar(36) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `teacher`
--

CREATE TABLE `teacher` (
                           `Id` varchar(36) NOT NULL DEFAULT uuid(),
                           `Name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `teacherassignment`
--

CREATE TABLE `teacherassignment` (
                                     `AssignmentId` varchar(36) NOT NULL,
                                     `TeacherId` varchar(36) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `teachersubject`
--

CREATE TABLE `teachersubject` (
                                  `SubjectId` varchar(36) NOT NULL,
                                  `TeacherId` varchar(36) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `teacheruser`
--

CREATE TABLE `teacheruser` (
                               `TeacherId` varchar(36) NOT NULL,
                               `UserId` varchar(36) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
                        `Id` varchar(36) NOT NULL DEFAULT uuid(),
                        `Username` varchar(255) NOT NULL,
                        `HashedPwd` varchar(255) NOT NULL,
                        `DisplayName` varchar(255) NOT NULL,
                        `Created_at` datetime DEFAULT current_timestamp(),
                        `Updated_at` datetime DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

-- --------------------------------------------------------

--
-- Table structure for table `userdata`
--

CREATE TABLE `userdata` (
                            `UserId` varchar(36) NOT NULL DEFAULT uuid(),
                            `Email` varchar(255) DEFAULT NULL,
                            `BirthDate` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_hungarian_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `assignment`
--
ALTER TABLE `assignment`
    ADD PRIMARY KEY (`Id`),
  ADD KEY `FK_Assignment_Category` (`CategoryId`),
  ADD KEY `FK_Assignment_Profession` (`ProfessionId`);

--
-- Indexes for table `category`
--
ALTER TABLE `category`
    ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `CategoryName` (`CategoryName`);

--
-- Indexes for table `grade`
--
ALTER TABLE `grade`
    ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `GradeName` (`GradeName`);

--
-- Indexes for table `profession`
--
ALTER TABLE `profession`
    ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `ProfessionName` (`ProfessionName`);

--
-- Indexes for table `subject`
--
ALTER TABLE `subject`
    ADD PRIMARY KEY (`Id`),
  ADD KEY `FK_Subject_Category` (`CategoryId`),
  ADD KEY `FK_Subject_Profession` (`ProfessionId`);

--
-- Indexes for table `teacher`
--
ALTER TABLE `teacher`
    ADD PRIMARY KEY (`Id`);

--
-- Indexes for table `teacherassignment`
--
ALTER TABLE `teacherassignment`
    ADD PRIMARY KEY (`TeacherId`,`AssignmentId`),
  ADD KEY `FK_TeacherAssignment_Assignment` (`AssignmentId`);

--
-- Indexes for table `teachersubject`
--
ALTER TABLE `teachersubject`
    ADD PRIMARY KEY (`TeacherId`,`SubjectId`),
  ADD KEY `FK_TeacherSubject_Subject` (`SubjectId`);

--
-- Indexes for table `teacheruser`
--
ALTER TABLE `teacheruser`
    ADD PRIMARY KEY (`UserId`,`TeacherId`),
  ADD KEY `FK_TeacherUser_Teacher` (`TeacherId`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
    ADD PRIMARY KEY (`Id`);

--
-- Indexes for table `userdata`
--
ALTER TABLE `userdata`
    ADD PRIMARY KEY (`UserId`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `assignment`
--
ALTER TABLE `assignment`
    ADD CONSTRAINT `FK_Assignment_Category` FOREIGN KEY (`CategoryId`) REFERENCES `category` (`Id`) ON DELETE CASCADE,
  ADD CONSTRAINT `FK_Assignment_Profession` FOREIGN KEY (`ProfessionId`) REFERENCES `profession` (`Id`) ON DELETE CASCADE;

--
-- Constraints for table `subject`
--
ALTER TABLE `subject`
    ADD CONSTRAINT `FK_Subject_Category` FOREIGN KEY (`CategoryId`) REFERENCES `category` (`Id`) ON DELETE CASCADE,
  ADD CONSTRAINT `FK_Subject_Profession` FOREIGN KEY (`ProfessionId`) REFERENCES `profession` (`Id`) ON DELETE CASCADE;

--
-- Constraints for table `teacherassignment`
--
ALTER TABLE `teacherassignment`
    ADD CONSTRAINT `FK_TeacherAssignment_Assignment` FOREIGN KEY (`AssignmentId`) REFERENCES `assignment` (`Id`) ON DELETE CASCADE,
  ADD CONSTRAINT `FK_TeacherAssignment_Teacher` FOREIGN KEY (`TeacherId`) REFERENCES `teacher` (`Id`) ON DELETE CASCADE;

--
-- Constraints for table `teachersubject`
--
ALTER TABLE `teachersubject`
    ADD CONSTRAINT `FK_TeacherSubject_Subject` FOREIGN KEY (`SubjectId`) REFERENCES `subject` (`Id`) ON DELETE CASCADE,
  ADD CONSTRAINT `FK_TeacherSubject_Teacher` FOREIGN KEY (`TeacherId`) REFERENCES `teacher` (`Id`) ON DELETE CASCADE;

--
-- Constraints for table `teacheruser`
--
ALTER TABLE `teacheruser`
    ADD CONSTRAINT `FK_TeacherUser_Teacher` FOREIGN KEY (`TeacherId`) REFERENCES `teacher` (`Id`) ON DELETE CASCADE,
  ADD CONSTRAINT `FK_TeacherUser_User` FOREIGN KEY (`UserId`) REFERENCES `user` (`Id`) ON DELETE CASCADE;

--
-- Constraints for table `userdata`
--
ALTER TABLE `userdata`
    ADD CONSTRAINT `FK_UserData_User` FOREIGN KEY (`UserId`) REFERENCES `user` (`Id`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
