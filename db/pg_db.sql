-- Enable UUID extension for PostgreSQL
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

-- User table
CREATE TABLE "User" (
                        "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                        "Username" TEXT NOT NULL,
                        "HashedPwd" TEXT NOT NULL,
                        "DisplayName" TEXT NOT NULL,
                        "Created_at" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                        "Updated_at" TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- UserData table
CREATE TABLE "UserData" (
                            "UserId" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                            "Email" TEXT,
                            "BirthDate" TIMESTAMP NOT NULL,
                            CONSTRAINT "FK_UserData_User" FOREIGN KEY ("UserId") REFERENCES "User" ("Id") ON DELETE CASCADE
);

-- Teacher table
CREATE TABLE "Teacher" (
                           "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                           "Name" TEXT NOT NULL
);

-- TeacherUser table
CREATE TABLE "TeacherUser" (
                               "TeacherId" UUID NOT NULL,
                               "UserId" UUID NOT NULL,
                               PRIMARY KEY ("UserId", "TeacherId"),
                               CONSTRAINT "FK_TeacherUser_Teacher" FOREIGN KEY ("TeacherId") REFERENCES "Teacher" ("Id") ON DELETE CASCADE,
                               CONSTRAINT "FK_TeacherUser_User" FOREIGN KEY ("UserId") REFERENCES "User" ("Id") ON DELETE CASCADE
);

-- Grade table
CREATE TABLE "Grade" (
                         "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                         "GradeName" TEXT UNIQUE NOT NULL
);

-- Category table
CREATE TABLE "Category" (
                            "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                            "CategoryName" TEXT UNIQUE NOT NULL
);

-- Profession table
CREATE TABLE "Profession" (
                              "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                              "ProfessionName" TEXT UNIQUE NOT NULL
);

-- Subject table
CREATE TABLE "Subject" (
                           "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                           "Name" TEXT NOT NULL,
                           "Content" TEXT,
                           "Description" TEXT,
                           "CreatedAt" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                           "UpdatedAt" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                           "GradeId" UUID,
                           "CategoryId" UUID,
                           "ProfessionId" UUID,
                           CONSTRAINT "FK_Subject_Grade" FOREIGN KEY ("GradeId") REFERENCES "Grade" ("Id") ON DELETE CASCADE,
                           CONSTRAINT "FK_Subject_Category" FOREIGN KEY ("CategoryId") REFERENCES "Category" ("Id") ON DELETE CASCADE,
                           CONSTRAINT "FK_Subject_Profession" FOREIGN KEY ("ProfessionId") REFERENCES "Profession" ("Id") ON DELETE CASCADE
);

-- Assignment table
CREATE TABLE "Assignment" (
                              "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                              "Name" TEXT NOT NULL,
                              "Content" TEXT,
                              "Description" TEXT,
                              "CreatedAt" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                              "UpdatedAt" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                              "GradeId" UUID,
                              "CategoryId" UUID,
                              "ProfessionId" UUID,
                              CONSTRAINT "FK_Assignment_Grade" FOREIGN KEY ("GradeId") REFERENCES "Grade" ("Id") ON DELETE CASCADE,
                              CONSTRAINT "FK_Assignment_Category" FOREIGN KEY ("CategoryId") REFERENCES "Category" ("Id") ON DELETE CASCADE,
                              CONSTRAINT "FK_Assignment_Profession" FOREIGN KEY ("ProfessionId") REFERENCES "Profession" ("Id") ON DELETE CASCADE
);

-- TeacherSubject table
CREATE TABLE "TeacherSubject" (
                                  "TeacherId" UUID NOT NULL,
                                  "SubjectId" UUID NOT NULL,
                                  PRIMARY KEY ("TeacherId", "SubjectId"),
                                  CONSTRAINT "FK_TeacherSubject_Teacher" FOREIGN KEY ("TeacherId") REFERENCES "Teacher" ("Id") ON DELETE CASCADE,
                                  CONSTRAINT "FK_TeacherSubject_Subject" FOREIGN KEY ("SubjectId") REFERENCES "Subject" ("Id") ON DELETE CASCADE
);

-- TeacherAssignment table
CREATE TABLE "TeacherAssignment" (
                                     "TeacherId" UUID NOT NULL,
                                     "AssignmentId" UUID NOT NULL,
                                     PRIMARY KEY ("TeacherId", "AssignmentId"),
                                     CONSTRAINT "FK_TeacherAssignment_Teacher" FOREIGN KEY ("TeacherId") REFERENCES "Teacher" ("Id") ON DELETE CASCADE,
                                     CONSTRAINT "FK_TeacherAssignment_Assignment" FOREIGN KEY ("AssignmentId") REFERENCES "Assignment" ("Id") ON DELETE CASCADE
);
