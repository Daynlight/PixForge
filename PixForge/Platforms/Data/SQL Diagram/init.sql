PRAGMA foreign_keys = ON;

------------------------ Git ------------------------ 
DROP TABLE IF EXISTS Users;
DROP TABLE IF EXISTS Commits;
DROP TABLE IF EXISTS Branches;
DROP TABLE IF EXISTS Projects;
DROP TABLE IF EXISTS History;
DROP TABLE IF EXISTS Collaborators;

CREATE TABLE Users(
  nick varchar(100) PRIMARY KEY NOT NULL UNIQUE,
  password varchar(255) NOT NULL,
  created TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  active TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  logged bool NOT NULL DEFAULT FALSE
);

CREATE TABLE Projects(
  idp INT PRIMARY KEY NOT NULL UNIQUE,
  owner varchar(100) NOT NULL,
  name varchar(100) NOT NULL DEFAULT 'New Project'
);

CREATE TABLE Commits(
  idc int PRIMARY KEY NOT NULL UNIQUE,
  idp int NOT NULL,
  owner varchar(100) NOT NULL,
  time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  message varchar(100) NOT NULL,
  description varchar(200) DEFAULT NULL
);

CREATE TABLE Branches(
  idb int PRIMARY KEY NOT NULL UNIQUE,
  idc int NOT NULL UNIQUE,
  owner varchar(100) NOT NULL,
  name varchar(100) NOT NULL,
  active bool NOT NULL DEFAULT FALSE,
  time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE History(
  idh int PRIMARY KEY NOT NULL UNIQUE,
  'action' varchar(100) NOT NULL,
  idc NOT NULL,
  time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Collaborators(
  idcol int PRIMARY KEY NOT NULL UNIQUE,
  user varchar(100) NOT NULL,
  idp int NOT NULL,
  idb int NOT NULL,
  idc int NOT NULL,
  joined TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  opened bool NOT NULL DEFAULT FALSE
);


------------------------ Game ------------------------
