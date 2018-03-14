#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QString>

class QJsonObject;

class Template
{
public:
  Template(const QString& path);
  virtual ~Template() = default;

  QString getPath() const;
  void setPath(const QString& path);

  virtual void run(const QJsonObject& config) const = 0;

protected:
  QString _path;
};

class PluginTemplate: public Template
{
public:
  PluginTemplate(const QString& path);

  void run(const QJsonObject& config) const;
};

#endif // TEMPLATE_H
