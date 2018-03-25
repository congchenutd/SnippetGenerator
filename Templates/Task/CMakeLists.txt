argo_add_executable(
  TARGET  $COMPONENT_NAME$
  SCHEMAS $CONFIG_NAME$.asl
  SOURCES $COMPONENT_NAME$.cc 
          $CONFIG_NAME$.cc
  LIBS    ErrorHandling
          Task
)