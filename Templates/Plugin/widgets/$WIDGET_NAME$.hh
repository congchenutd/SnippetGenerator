// THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
// AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
// ARGO'S PERMISSION.
// Copyright (c) $YEAR$ Argo AI, LLC.

#pragma once

#include <ClassHelper/ClassHelpers.hh>

#include <QWidget>

#include <memory>

namespace Ui
{
  class $WIDGET_NAME$UI;
}

namespace $NAMESPACE_DOUBLE_COLON$
{

class $WIDGET_NAME$ : public QWidget
{
public:
  $WIDGET_NAME$();
  ~$WIDGET_NAME$() override;
  COPY_CONSTRUCT($WIDGET_NAME$) = delete;
  COPY_ASSIGN($WIDGET_NAME$) = delete;
  MOVE_CONSTRUCT($WIDGET_NAME$) = delete;
  MOVE_ASSIGN($WIDGET_NAME$) = delete;

private:
  /// @brief Pointer to the Qt auto-generated type.
  std::unique_ptr<Ui::$WIDGET_NAME$UI> ui_;
};

}  // namespace $NAMESPACE_DOUBLE_COLON$
