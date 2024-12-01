/**
 *
 *  Grade.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Grade.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::educloud;

const std::string Grade::Cols::_Id = "\"Id\"";
const std::string Grade::Cols::_GradeName = "\"GradeName\"";
const std::string Grade::primaryKeyName = "Id";
const bool Grade::hasPrimaryKey = true;
const std::string Grade::tableName = "\"Grade\"";

const std::vector<typename Grade::MetaData> Grade::metaData_={
{"Id","std::string","uuid",0,0,1,1},
{"GradeName","std::string","character varying",0,0,0,1}
};
const std::string &Grade::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Grade::Grade(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["Id"].isNull())
        {
            id_=std::make_shared<std::string>(r["Id"].as<std::string>());
        }
        if(!r["GradeName"].isNull())
        {
            gradename_=std::make_shared<std::string>(r["GradeName"].as<std::string>());
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
            gradename_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Grade::Grade(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
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
            gradename_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
}

Grade::Grade(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("Id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["Id"].isNull())
        {
            id_=std::make_shared<std::string>(pJson["Id"].asString());
        }
    }
    if(pJson.isMember("GradeName"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["GradeName"].isNull())
        {
            gradename_=std::make_shared<std::string>(pJson["GradeName"].asString());
        }
    }
}

void Grade::updateByMasqueradedJson(const Json::Value &pJson,
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
            gradename_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
}

void Grade::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("Id"))
    {
        if(!pJson["Id"].isNull())
        {
            id_=std::make_shared<std::string>(pJson["Id"].asString());
        }
    }
    if(pJson.isMember("GradeName"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["GradeName"].isNull())
        {
            gradename_=std::make_shared<std::string>(pJson["GradeName"].asString());
        }
    }
}

const std::string &Grade::getValueOfId() const noexcept
{
    static const std::string defaultValue = std::string();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Grade::getId() const noexcept
{
    return id_;
}
void Grade::setId(const std::string &pId) noexcept
{
    id_ = std::make_shared<std::string>(pId);
    dirtyFlag_[0] = true;
}
void Grade::setId(std::string &&pId) noexcept
{
    id_ = std::make_shared<std::string>(std::move(pId));
    dirtyFlag_[0] = true;
}
const typename Grade::PrimaryKeyType & Grade::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Grade::getValueOfGradename() const noexcept
{
    static const std::string defaultValue = std::string();
    if(gradename_)
        return *gradename_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Grade::getGradename() const noexcept
{
    return gradename_;
}
void Grade::setGradename(const std::string &pGradename) noexcept
{
    gradename_ = std::make_shared<std::string>(pGradename);
    dirtyFlag_[1] = true;
}
void Grade::setGradename(std::string &&pGradename) noexcept
{
    gradename_ = std::make_shared<std::string>(std::move(pGradename));
    dirtyFlag_[1] = true;
}

void Grade::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Grade::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "Id",
        "GradeName"
    };
    return inCols;
}

void Grade::outputArgs(drogon::orm::internal::SqlBinder &binder) const
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
        if(getGradename())
        {
            binder << getValueOfGradename();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Grade::updateColumns() const
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

void Grade::updateArgs(drogon::orm::internal::SqlBinder &binder) const
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
        if(getGradename())
        {
            binder << getValueOfGradename();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Grade::toJson() const
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
    if(getGradename())
    {
        ret["GradeName"]=getValueOfGradename();
    }
    else
    {
        ret["GradeName"]=Json::Value();
    }
    return ret;
}

Json::Value Grade::toMasqueradedJson(
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
            if(getGradename())
            {
                ret[pMasqueradingVector[1]]=getValueOfGradename();
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
    if(getGradename())
    {
        ret["GradeName"]=getValueOfGradename();
    }
    else
    {
        ret["GradeName"]=Json::Value();
    }
    return ret;
}

bool Grade::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("Id"))
    {
        if(!validJsonOfField(0, "Id", pJson["Id"], err, true))
            return false;
    }
    if(pJson.isMember("GradeName"))
    {
        if(!validJsonOfField(1, "GradeName", pJson["GradeName"], err, true))
            return false;
    }
    else
    {
        err="The GradeName column cannot be null";
        return false;
    }
    return true;
}
bool Grade::validateMasqueradedJsonForCreation(const Json::Value &pJson,
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
bool Grade::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("GradeName"))
    {
        if(!validJsonOfField(1, "GradeName", pJson["GradeName"], err, false))
            return false;
    }
    return true;
}
bool Grade::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
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
bool Grade::validJsonOfField(size_t index,
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
