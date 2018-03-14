set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5Widgets)

argo_add_library(
  TARGET  $WIDGET_NAME$
  SOURCES $WIDGET_NAME$.cc
  LIBS    Qt5Core
          Qt5Gui
          Qt5Widgets
)
