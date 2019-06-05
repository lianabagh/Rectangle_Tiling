#include <QGraphicsRectItem>
#include<iostream>
#include "Lian_Kurs.h"
#include<vector>
std::map<int, QColor> map_ = { { 1,Qt::red },{ 2,Qt::blue },{ 3,Qt::green },{ 4,Qt::yellow } };

Lian_Kurs::Lian_Kurs(QWidget *parent)
	: QMainWindow(parent), m_scene(new QGraphicsScene(parent))
{
	ui.setupUi(this);
	ui.graphicsView->setScene(m_scene);

	connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(onBuild()));
}

void Lian_Kurs::onBuild()
{

	const int height = ui.heightSpinBox->value();
	const int width = ui.widthSpinBox->value();

	std::vector<std::vector<int>> matrix(height, std::vector<int>(width));


	for (int rowIndex = 0; rowIndex < height; rowIndex += 4)
		for (int columnIndex = 0; columnIndex < width; columnIndex += 4)

		{
			int direction = 0;
			int dx[] = { 0, 1, 0, -1 };
			int dy[] = { 1, 0, -1, 0 };
			int x = rowIndex;
			int y = columnIndex - 1;

			for (int i = 1; i <= 16; ++i)
			{
				x += dx[direction];
				y += dy[direction];

				if (x < 0 || x >= rowIndex + 4 || y < 0 || y >= columnIndex + 4 || matrix[x][y] != 0)
				{

					x -= dx[direction];
					y -= dy[direction];

					direction = (direction + 1) % 4;
					if (matrix[x][y] == direction)
						matrix[x][y] = direction + 1;
					paintRect(x, y, setColor(matrix[x][y]).second, setColor(matrix[x][y]).first);
					x += dx[direction];
					y += dy[direction];

				}
				if (i == 16)
					matrix[x][y] = direction + 2;
				else
					matrix[x][y] = direction + 1;
				

			paintRect(x, y, setColor(matrix[x][y]).second, setColor(matrix[x][y]).first);
			}
		}

}


std::pair<QBrush, QPen> Lian_Kurs::setColor(int value)
{
	QBrush brush(map_[value]);
	QPen pen;
	pen.setColor(map_[value]);
	return std::pair<QBrush, QPen>({ brush,pen });
}

void Lian_Kurs::paintRect(int i, int j, const QPen& pen, const QBrush& brush) {
	QRectF rectangle(i * 50, j * 50, 50, 50);
	m_scene->addRect(rectangle, pen, brush);
}


