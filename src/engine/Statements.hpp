#pragma once
#include <string>

namespace tagallery
{
	constexpr char* STATEMENT_BUILD_SCHEMA = R"sqlite(
CREATE TABLE tagType (
	id           INTEGER UNIQUE,
	name         TEXT UNIQUE,
	defaultValue INTEGER,
	PRIMARY KEY(id AUTOINCREMENT)
);

CREATE TABLE tag (
	id      INTEGER UNIQUE,
	name    TEXT UNIQUE,
	typeId  INTEGER,
	FOREIGN KEY(typeId) REFERENCES tagType(id),
	PRIMARY KEY(id AUTOINCREMENT)
);

CREATE TABLE item (
	id        INTEGER UNIQUE,
	filename  UNIQUE,
	dateAdded INTEGER,
	PRIMARY KEY(id AUTOINCREMENT)
);

CREATE TABLE binds (
	itemId	INTEGER,
	tagId	INTEGER,
	FOREIGN KEY(tagId) REFERENCES tag(id),
	FOREIGN KEY(itemId) REFERENCES item(id)
);

INSERT INTO tagType(name, defaultValue) VALUES (NULL, NULL);
INSERT INTO tagType(name, defaultValue) VALUES ("dir", NULL);
INSERT INTO tagType(name, defaultValue) VALUES ("author", 1);
INSERT INTO tagType(name, defaultValue) VALUES ("rating", 2);

INSERT INTO tag(name, typeId) VALUES ("unknown", 3);
INSERT INTO tag(name, typeId) VALUES ("unrated", 4);
INSERT INTO tag(name, typeId) VALUES ("safe", 4);
INSERT INTO tag(name, typeId) VALUES ("unsafe", 4);
)sqlite";

}
