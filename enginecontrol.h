#ifndef ENGINECONTROL_H
#define ENGINECONTROL_H
#include <QQmlApplicationEngine>
#include <QObject>

class EngineControl : public QObject
{
    Q_OBJECT
public:
    explicit EngineControl(QQmlApplicationEngine* engine, QObject *parent = nullptr);
    Q_INVOKABLE void load(QString url);

signals:

public slots:

private:
    QQmlApplicationEngine* m_engine;

};

#endif // ENGINECONTROL_H
