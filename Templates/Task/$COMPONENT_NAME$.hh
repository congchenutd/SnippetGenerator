// THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
// AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
// ARGO'S PERMISSION.
// Copyright (c) 2018 Argo AI, LLC.

#pragma once

#include "$CONFIG_NAME$.hh"

#include <ClassHelper/ClassHelpers.hh>
#include <Task/Task.hh>

#include <memory>

$NAMESPACE_START$

class $COMPONENT_NAME$ : public Task::Task
{
public:
  NONCOPYABLE_AND_NONMOVABLE($COMPONENT_NAME$)
  $COMPONENT_NAME$() = default;
  ~$COMPONENT_NAME$() final = default;

  void init() final;
  void exec() final;
  void shutdown() final;

private:
  DEFINE_LOAD_CONFIG($CONFIG_NAME$);

  // Stores our TaskConfig for later use.
  std::shared_ptr<$CONFIG_NAME$> config_;
};

$NAMESPACE_END$
