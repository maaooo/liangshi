#pragma once

#include <string>
#include <vector>
using namespace std;

#include <qtGui/QVector2D>
#include <qtGui/QPainterPath>

//��������������Ҫ�Լ����ͻ���point�࣬��������skia����Qt
vector<QVector2D> toVector(const vector<QVector2D>& inputPoints, double tolerance, double error);
QPainterPath toPath(const vector<QVector2D>& inputPoints);
