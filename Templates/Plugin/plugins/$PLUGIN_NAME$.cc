// THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
// AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
// ARGO'S PERMISSION.
// Copyright (c) 2018 Argo AI, LLC.

#include "$PLUGIN_NAME$.hh"

#include <PluginManagement/PluginUtils.hh>

$NAMESPACE_START$

$PLUGIN_NAME$::$PLUGIN_NAME$()
  : Visualization::TemplatedPluginInterfaceHelper<$PLUGIN_NAME$Config>("$PLUGIN_DESCRIPTION$")
{
}

bool $PLUGIN_NAME$::can_draw() const
{
  return false;
}

QWidget* $PLUGIN_NAME$::get_widget() const
{
  return widget_.get();
}

void $PLUGIN_NAME$::on_init()
{
  Time::ExpectedTimeProvider expected_time_provider = Time::get_time_provider();
  if (!expected_time_provider)
  {
    ARGO_THROW(std::runtime_error{"Could not get time provider in " + get_plugin_name()});
  }
  time_provider_ = expected_time_provider.get();

  // Instantiate the widget owned by this plugin.
  widget_ = std::make_unique<$WIDGET_NAME$>();
}

void $PLUGIN_NAME$::update()
{

}

// Define a dynamic plugin creation function that the PluginManager can lookup and invoke.
PLUGIN_CREATE_FUNCTION_IMPL($PLUGIN_NAME$, $PLUGIN_NAME$)

$NAMESPACE_END$
