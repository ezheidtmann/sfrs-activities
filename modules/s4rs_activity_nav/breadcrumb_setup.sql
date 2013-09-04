/**
 * @file Dump of "custom_breadcrumb" table, to document custom_breadcrumbs
 * settings for S4RS Activity Pages and Extensions.
 *
 * The data included here is included for documentation purposes; unless you
 * are on a fresh install you should probably not simply run this SQL.
 */

-- MySQL dump 10.13  Distrib 5.5.24, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: sfrs1
-- ------------------------------------------------------
-- Server version	5.5.24-0ubuntu0.12.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `custom_breadcrumb`
--

DROP TABLE IF EXISTS `custom_breadcrumb`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `custom_breadcrumb` (
  `bid` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Unique identifier for the custom_breadcrumb.',
  `name` varchar(128) DEFAULT NULL COMMENT 'An optional name for the custom breadcrumb.',
  `titles` varchar(255) NOT NULL DEFAULT '' COMMENT 'A return-delimited list of titles for the breadcrumb links.',
  `paths` varchar(255) DEFAULT NULL COMMENT 'A return-delimited list of url paths for the breadcrumb links.',
  `visibility_php` mediumtext NOT NULL COMMENT 'An optional PHP snippet to control the custom_breadcrumb visibility.',
  `node_type` varchar(64) DEFAULT 'AND' COMMENT 'Node types the custom_breadcrumb should apply to.',
  `language` varchar(12) NOT NULL DEFAULT '' COMMENT 'The language this breadcrumb is for; if blank, the breadcrumb will be used for unknown languages.',
  PRIMARY KEY (`bid`),
  KEY `language` (`language`),
  KEY `node_language` (`node_type`,`language`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='Stores custom breadcrumb trail overrides.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `custom_breadcrumb`
--

LOCK TABLES `custom_breadcrumb` WRITE;
/*!40000 ALTER TABLE `custom_breadcrumb` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `custom_breadcrumb` VALUES (1,'S4RS Activity Pages','Activities','activity-search','','s4rs_activity',''),(2,'S4RS Activity Extension Pages[node:field-parent-activity:title]','Activities\r\n[node:field-parent-activity:title]','activity-search\r\n[node:field-parent-activity:url]','','extension_activity','');
/*!40000 ALTER TABLE `custom_breadcrumb` ENABLE KEYS */;
UNLOCK TABLES;
commit;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-11-15 17:23:25
