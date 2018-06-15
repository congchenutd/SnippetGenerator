// THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
// AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
// ARGO'S PERMISSION.
// Copyright (c) $YEAR$ Argo AI, LLC.

#include "$COMPONENT_NAME$.hh"

#include <Task/TaskRunner.hh>

namespace $NAMESPACE_DOUBLE_COLON$
{

void $COMPONENT_NAME$::init()
{
  // Get our Task configuration.
  config_ = get_task_config<$CONFIG_NAME$>();
  if (!config_)
  {
    LOG_ERROR("Unable to load task config for $COMPONENT_NAME$. Shutting down the task.");
    shutdown_task();
    return;
  }
}

void $COMPONENT_NAME$::exec()
{

}

void $COMPONENT_NAME$::shutdown()
{
  LOG_INFO("$COMPONENT_NAME$ is shut down.");
}

}  // namespace $NAMESPACE_DOUBLE_COLON$

TASK_MAIN($NAMESPACE_DOUBLE_COLON$::$COMPONENT_NAME$)
