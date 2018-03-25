set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5Core)

argo_add_plugin(
  TARGET  $COMPONENT_NAME$
  SCHEMAS $CONFIG_NAME$.asl
  SOURCES $COMPONENT_NAME$.cc
          $CONFIG_NAME$.cc
  LIBS    $WIDGET_NAME$
          Config
          DebugLog
          Time
          TemplatedPluginInterfaceHelper
          PluginUtils
)
