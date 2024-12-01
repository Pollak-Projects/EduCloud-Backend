/**
 *
 *  Teacher.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Teacher.h"
#include "Teacherassignment.h"
#include "Teachersubject.h"
#include "Teacheruser.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::educloud;

const std::string Teacher::Cols::_Id = "\"Id\"";
const std::string Teacher::Cols::_Name = "\"Name\"";
const std::string Teacher::primaryKeyName = "Id";
const bool Teacher::hasPrimaryKey = true;
const std::string Teacher::tableName = "\"Teacher\"";

const std::vector<typename Teacher::MetaData> Teacher::metaData_={
{"Id","std::string","uuid",0,0,1,1},
{"Name","std::string","text",0,0,0,1}
};
const std::string &Teacher::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Teacher::Teacher(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["Id"].isNull())
        {
            id_=std::make_shared<std::string>(r["Id"].as<std::string>());
        }
        if(!r["Name"].isNull())
        {
            name_=std::make_shared<std::string>(r["Name"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 2 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            name_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Teacher::Teacher(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
}

Teacher::Teacher(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("Id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["Id"].isNull())
        {
            id_=std::make_shared<std::string>(pJson["Id"].asString());
        }
    }
    if(pJson.isMember("Name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["Name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["Name"].asString());
        }
    }
}

void Teacher::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
}

void Teacher::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("Id"))
    {
        if(!pJson["Id"].isNull())
        {
            id_=std::make_shared<std::string>(pJson["Id"].asString());
        }
    }
    if(pJson.isMember("Name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["Name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["Name"].asString());
        }
    }
}

const std::string &Teacher::getValueOfId() const noexcept
{
    static const std::string defaultValue = std::string();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Teacher::getId() const noexcept
{
    return id_;
}
void Teacher::setId(const std::string &pId) noexcept
{
    id_ = std::make_shared<std::string>(pId);
    dirtyFlag_[0] = true;
}
void Teacher::setId(std::string &&pId) noexcept
{
    id_ = std::make_shared<std::string>(std::move(pId));
    dirtyFlag_[0] = true;
}
const typename Teacher::PrimaryKeyType & Teacher::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Teacher::getValueOfName() const noexcept
{
    static const std::string defaultValue = std::string();
    if(name_)
        return *name_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Teacher::getName() const noexcept
{
    return name_;
}
void Teacher::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[1] = true;
}
void Teacher::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[1] = true;
}

void Teacher::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Teacher::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "Id",
        "Name"
    };
    return inCols;
}

void Teacher::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Teacher::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    return ret;
}

void Teacher::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Teacher::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["Id"]=getValueOfId();
    }
    else
    {
        ret["Id"]=Json::Value();
    }
    if(getName())
    {
        ret["Name"]=getValueOfName();
    }
    else
    {
        ret["Name"]=Json::Value();
    }
    return ret;
}

Json::Value Teacher::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 2)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[1]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["Id"]=getValueOfId();
    }
    else
    {
        ret["Id"]=Json::Value();
    }
    if(getName())
    {
        ret["Name"]=getValueOfName();
    }
    else
    {
        ret["Name"]=Json::Value();
    }
    return ret;
}

bool Teacher::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("Id"))
    {
        if(!validJsonOfField(0, "Id", pJson["Id"], err, true))
            return false;
    }
    if(pJson.isMember("Name"))
    {
        if(!validJsonOfField(1, "Name", pJson["Name"], err, true))
            return false;
    }
    else
    {
        err="The Name column cannot be null";
        return false;
    }
    return true;
}
bool Teacher::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                 const std::vector<std::string> &pMasqueradingVector,
                                                 std::string &err)
{
    if(pMasqueradingVector.size() != 2)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Teacher::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("Id"))
    {
        if(!validJsonOfField(0, "Id", pJson["Id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("Name"))
    {
        if(!validJsonOfField(1, "Name", pJson["Name"], err, false))
            return false;
    }
    return true;
}
bool Teacher::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                               const std::vector<std::string> &pMasqueradingVector,
                                               std::string &err)
{
    if(pMasqueradingVector.size() != 2)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Teacher::validJsonOfField(size_t index,
                               const std::string &fieldName,
                               const Json::Value &pJson,
                               std::string &err,
                               bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
Teacheruser Teacher::getTeacheruser(const DbClientPtr &clientPtr) const {
    static const std::string sql = "select * from TeacherUser where TeacherId  = $1";
    Result r(nullptr);
    {
        auto binder = *clientPtr << sql;
        binder << *id_ << Mode::Blocking >>
            [&r](const Result &result) { r = result; };
        binder.exec();
    }
    if (r.size() == 0)
    {
        throw UnexpectedRows("0 rows found");
    }
    else if (r.size() > 1)
    {
        throw UnexpectedRows("Found more than one row");
    }
    return Teacheruser(r[0]);
}

void Teacher::getTeacheruser(const DbClientPtr &clientPtr,
                             const std::function<void(Teacheruser)> &rcb,
                             const ExceptionCallback &ecb) const
{
    static const std::string sql = "select * from TeacherUser where TeacherId  = $1";
    *clientPtr << sql
               << *id_
               >> [rcb = std::move(rcb), ecb](const Result &r){
                    if (r.size() == 0)
                    {
                        ecb(UnexpectedRows("0 rows found"));
                    }
                    else if (r.size() > 1)
                    {
                        ecb(UnexpectedRows("Found more than one row"));
                    }
                    else
                    {
                        rcb(Teacheruser(r[0]));
                    }
               }
               >> ecb;
}
std::vector<Teacherassignment> Teacher::getTeacherassignment(const DbClientPtr &clientPtr) const {
    static const std::string sql = "select * from TeacherAssignment where TeacherId = $1";
    Result r(nullptr);
    {
        auto binder = *clientPtr << sql;
        binder << *id_ << Mode::Blocking >>
            [&r](const Result &result) { r = result; };
        binder.exec();
    }
    std::vector<Teacherassignment> ret;
    ret.reserve(r.size());
    for (auto const &row : r)
    {
        ret.emplace_back(Teacherassignment(row));
    }
    return ret;
}

void Teacher::getTeacherassignment(const DbClientPtr &clientPtr,
                                   const std::function<void(std::vector<Teacherassignment>)> &rcb,
                                   const ExceptionCallback &ecb) const
{
    static const std::string sql = "select * from TeacherAssignment where TeacherId = $1";
    *clientPtr << sql
               << *id_
               >> [rcb = std::move(rcb)](const Result &r){
                   std::vector<Teacherassignment> ret;
                   ret.reserve(r.size());
                   for (auto const &row : r)
                   {
                       ret.emplace_back(Teacherassignment(row));
                   }
                   rcb(ret);
               }
               >> ecb;
}
std::vector<Teachersubject> Teacher::getTeachersubject(const DbClientPtr &clientPtr) const {
    static const std::string sql = "select * from TeacherSubject where TeacherId = $1";
    Result r(nullptr);
    {
        auto binder = *clientPtr << sql;
        binder << *id_ << Mode::Blocking >>
            [&r](const Result &result) { r = result; };
        binder.exec();
    }
    std::vector<Teachersubject> ret;
    ret.reserve(r.size());
    for (auto const &row : r)
    {
        ret.emplace_back(Teachersubject(row));
    }
    return ret;
}

void Teacher::getTeachersubject(const DbClientPtr &clientPtr,
                                const std::function<void(std::vector<Teachersubject>)> &rcb,
                                const ExceptionCallback &ecb) const
{
    static const std::string sql = "select * from TeacherSubject where TeacherId = $1";
    *clientPtr << sql
               << *id_
               >> [rcb = std::move(rcb)](const Result &r){
                   std::vector<Teachersubject> ret;
                   ret.reserve(r.size());
                   for (auto const &row : r)
                   {
                       ret.emplace_back(Teachersubject(row));
                   }
                   rcb(ret);
               }
               >> ecb;
}
