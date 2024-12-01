CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

-- Users Table
CREATE TABLE "User" (
                        "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                        "Username" VARCHAR NOT NULL,
                        "HashedPwd" VARCHAR NOT NULL,
                        "DisplayName" VARCHAR NOT NULL,
                        "Created_at" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                        "Updated_at" TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- UserData Table
CREATE TABLE "UserData" (
                            "UserId" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                            "Email" VARCHAR,
                            "BirthDate" TIMESTAMP NOT NULL,
                            FOREIGN KEY ("UserId") REFERENCES "User"("Id") ON DELETE CASCADE
);

-- Category Table
CREATE TABLE "Category" (
                            "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                            "CategoryName" VARCHAR UNIQUE NOT NULL
);

-- Profession Table
CREATE TABLE "Profession" (
                              "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                              "ProfessionName" VARCHAR UNIQUE NOT NULL
);

-- Subject Table
CREATE TABLE "Subject" (
                           "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                           "Name" VARCHAR NOT NULL,
                           "Content" TEXT,
                           "Grade" VARCHAR,
                           "Description" TEXT,
                           "CreatedAt" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                           "UpdatedAt" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                           "CategoryId" UUID,
                           "ProfessionId" UUID,
                           FOREIGN KEY ("CategoryId") REFERENCES "Category"("Id") ON DELETE CASCADE,
                           FOREIGN KEY ("ProfessionId") REFERENCES "Profession"("Id") ON DELETE CASCADE
);

-- Assignment Table
CREATE TABLE "Assignment" (
                              "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                              "Name" VARCHAR NOT NULL,
                              "Content" TEXT,
                              "Grade" VARCHAR,
                              "Description" TEXT,
                              "CreatedAt" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                              "UpdatedAt" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                              "CategoryId" UUID,
                              "ProfessionId" UUID,
                              FOREIGN KEY ("CategoryId") REFERENCES "Category"("Id") ON DELETE CASCADE,
                              FOREIGN KEY ("ProfessionId") REFERENCES "Profession"("Id") ON DELETE CASCADE
);

-- Teacher Table
CREATE TABLE "Teacher" (
                           "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                           "Name" VARCHAR NOT NULL
);

-- TeacherSubject Table (Many-to-Many relationship between Teacher and Subject)
CREATE TABLE "TeacherSubject" (
                                  "TeacherId" UUID,
                                  "SubjectId" UUID,
                                  PRIMARY KEY ("TeacherId", "SubjectId"),
                                  FOREIGN KEY ("TeacherId") REFERENCES "Teacher"("Id") ON DELETE CASCADE,
                                  FOREIGN KEY ("SubjectId") REFERENCES "Subject"("Id") ON DELETE CASCADE
);

-- TeacherAssignment Table (Many-to-Many relationship between Teacher and Assignment)
CREATE TABLE "TeacherAssignment" (
                                     "TeacherId" UUID,
                                     "AssignmentId" UUID,
                                     PRIMARY KEY ("TeacherId", "AssignmentId"),
                                     FOREIGN KEY ("TeacherId") REFERENCES "Teacher"("Id") ON DELETE CASCADE,
                                     FOREIGN KEY ("AssignmentId") REFERENCES "Assignment"("Id") ON DELETE CASCADE
);

-- TeacherUser Table (Many-to-Many relationship between Teacher and User)
CREATE TABLE "TeacherUser" (
                               "TeacherId" UUID,
                               "UserId" UUID,
                               PRIMARY KEY ("TeacherId", "UserId"),
                               FOREIGN KEY ("TeacherId") REFERENCES "Teacher"("Id") ON DELETE CASCADE,
                               FOREIGN KEY ("UserId") REFERENCES "User"("Id") ON DELETE CASCADE
);

-- Grade Table
CREATE TABLE "Grade" (
                         "Id" UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                         "GradeName" VARCHAR UNIQUE NOT NULL
);

-- The relationships with Grade will be managed via Subject and Assignment tables
-- No direct foreign key in Grade table for now.
