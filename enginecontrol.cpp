#include "enginecontrol.h"

EngineControl::EngineControl(QQmlApplicationEngine* engine, QObject *parent) : QObject(parent)
{
    m_engine=engine;
}

void EngineControl::load(QString url)
{
    QUrl link = QUrl(url);
    m_engine->load(link);
}
