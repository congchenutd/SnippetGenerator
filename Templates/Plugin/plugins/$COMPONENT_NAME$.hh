// THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
// AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
// ARGO'S PERMISSION.
// Copyright (c) $YEAR$ Argo AI, LLC.

#pragma once

#include "$CONFIG_NAME$.hh"

#include <ClassHelper/ClassHelpers.hh>
#include <$FOLDER_NAME$/widgets/$WIDGET_NAME$.hh>
#include <PluginManagement/PluginMacros.hh>
#include <Visualization/gui/TemplatedPluginInterfaceHelper.hh>

namespace $NAMESPACE_DOUBLE_COLON$
{

class $COMPONENT_NAME$ : public Visualization::TemplatedPluginInterfaceHelper<$CONFIG_NAME$>
{
public:
  $COMPONENT_NAME$();
  ~$COMPONENT_NAME$() override = default;
  COPY_CONSTRUCT($COMPONENT_NAME$) = delete;
  COPY_ASSIGN($COMPONENT_NAME$) = delete;
  MOVE_CONSTRUCT($COMPONENT_NAME$) = delete;
  MOVE_ASSIGN($COMPONENT_NAME$) = delete;

  /// @brief Whether or not the plugin has the ability to draw on the GL window.  False.
  bool can_draw() const override;

  /// @brief Called each iteration of task exec, to tell this plugin to update as needed.
  void update() override;

  /// @brief Returns this plugin's widget if it has one.
  QWidget* get_widget() const override;

protected:
  /// @brief Initialize the plugin (such as subscribe to messages, etc.).
  void on_init() override;

private:

  /// @brief Pointer to global time provider
  std::shared_ptr<Time::TimeProvider> time_provider_;

  /// @brief Widget of this plugin
  std::unique_ptr<$WIDGET_NAME$> widget_;
};

// Define a dynamic plugin creation function that the PluginManager can lookup and invoke.
PLUGIN_CREATE_FUNCTION_DECL($COMPONENT_NAME$, $COMPONENT_NAME$)

}  // namespace $NAMESPACE_DOUBLE_COLON$
