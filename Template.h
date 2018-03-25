#pragma once

#include <QString>

class QJsonObject;

class Template
{
public:
  Template(const QString& path);
  ~Template() = default;

  void run(const QJsonObject& config) const;

protected:
  QString _path;
};
