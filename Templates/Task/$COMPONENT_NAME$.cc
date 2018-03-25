// THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
// AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
// ARGO'S PERMISSION.
// Copyright (c) $YEAR$ Argo AI, LLC.

#include "$COMPONENT_NAME$.hh"

#include <Comms/ZMQ/ZMQFactory.hh>
#include <Task/TaskRunner.hh>

$NAMESPACE_START$

void $COMPONENT_NAME$::init()
{
  // Get our Task configuration.
  config_ = get_task_config<$CONFIG_NAME$>();
  if (!config_)
  {
    ARGO_THROW_LOG_ERROR(std::runtime_error, "Load config failed.");
  }
}

void $COMPONENT_NAME$::exec()
{

}

void DiagnosticsValiditySignalTestTask::shutdown()
{
  LOG_INFO("Shutdown");
}

$NAMESPACE_END$

TASK_MAIN_ZMQ($NAMESPACE_ONE_LINE_SEPARATED_BY_DOUBLE_COLON$::$COMPONENT_NAME$)
