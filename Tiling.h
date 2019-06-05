#include<map>
#ifndef LIAN_KURS
#define LIAN_KURS

#include "ui_Lian_Kurs.h"

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>

class Lian_Kurs : public QMainWindow
{
	Q_OBJECT

public:
	Lian_Kurs(QWidget *parent = Q_NULLPTR);

	private slots:
	void onBuild();

private:
	std::pair<QBrush, QPen> setColor(int value);
	void paintRect(int i, int j, const QPen& pen, const QBrush& brush);
private:
	Ui::Lian_KursClass ui;

	QGraphicsScene* m_scene;


};

#endif
