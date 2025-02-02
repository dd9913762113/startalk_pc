﻿//
// Created by cc on 2018/11/29.
//
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef STALK_V2_MESSAGEPROMPT_H
#define STALK_V2_MESSAGEPROMPT_H

#include "CustomUi/UShadowWnd.h"
#include "NativeChatStruct.h"
#include <QTimer>
#include <QMutexLocker>
#include <QFrame>
#include "entity/im_message.h"

class QLabel;
class QPropertyAnimation;
class HeadPhotoLab;
class MessagePrompt : public QFrame
{
	Q_OBJECT
public:
    explicit MessagePrompt(const st::entity::ImMessageInfo& msg);
    ~MessagePrompt() override;

public:
    void startToshow(const QPoint& startPoint);
    void stopAndDelete();
    void moveTop();

private:
    void initUi();
    void dealTimer();
    QString dealMessageContent();

Q_SIGNALS:
    void openChatWnd(QUInt8, QString,QString, QString, QString);

protected:
    void mousePressEvent(QMouseEvent* e) override;

private:
    HeadPhotoLab* _pLabelHead;
    QLabel* _pLabelName;
    QLabel* _pLabelContent;

    QTimer* _timer;
    QPropertyAnimation *animation;

private:
	st::entity::ImMessageInfo _msg;
};


#endif //STALK_V2_MESSAGEPROMPT_H
