﻿#ifndef BASE_THREAD_H
#define BASE_THREAD_H

#include "../config.h"
#include <QObject>
#include <atomic>

class BaseObject : public QObject
{
    Q_OBJECT

public:

    BaseObject(QObject* parent = nullptr);

public slots:

    virtual void startSlot() = 0;
    virtual void pauseSlot() = 0;
    virtual void replaySlot() = 0;
    virtual void restoreSlot() = 0;

protected:

    enum ThreadState { running, paused };

    std::atomic<ThreadState> m_threadState;

    inline void setThreadState(ThreadState state) { m_threadState.store(state); }
    inline ThreadState threadState() const { return m_threadState.load(); }

};

#endif /* BASE_THREAD_H */