set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

argo_add_schema(TARGET  $CONFIG_NAME$
                SOURCES $CONFIG_NAME$.asl
                        $CONFIG_NAME$.cc
                LIBS    Config
                )

argo_add_plugin(
  TARGET  $COMPONENT_NAME$
  SCHEMAS $CONFIG_NAME$
  SOURCES $COMPONENT_NAME$.cc
  LIBS    $WIDGET_NAME$
          DebugLog
          PluginUtils
          Time
          TemplatedPluginInterfaceHelper
)
