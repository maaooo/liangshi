﻿#include "LoginButton.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#pragma execution_character_set("utf-8")
#endif

LoginButton::LoginButton(QString title, QWidget *parent):
QPushButton(title, parent)
{
}

LoginButton::~LoginButton()
{
}
