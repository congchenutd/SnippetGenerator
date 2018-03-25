// THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
// AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
// ARGO'S PERMISSION.
// Copyright (c) $YEAR$ Argo AI, LLC.

#pragma once

#include <$FOLDER_NAME$/widgets/ui_$WIDGET_NAME$.h>  // Autogen.

#include <ClassHelper/ClassHelpers.hh>

#include <memory>

$NAMESPACE_START$

class $WIDGET_NAME$ : public QWidget
{
public:
  $WIDGET_NAME$();
  NONCOPYABLE_AND_NONMOVABLE($WIDGET_NAME$)
  ~$WIDGET_NAME$() override = default;

private:
  /// @brief Pointer to the Qt auto-generated type.
  std::unique_ptr<Ui::$WIDGET_NAME$UI> ui_;
};

$NAMESPACE_END$
