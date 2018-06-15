set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

argo_add_library(
  TARGET  $WIDGET_NAME$
  SOURCES $WIDGET_NAME$.cc
  LIBS    Qt5::Core
          Qt5::Gui
          Qt5::Widgets
)
