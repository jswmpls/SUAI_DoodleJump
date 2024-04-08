#include "Score.h"

//Обновление счёта
void Score::updateScore()
{
	score += 50;
	scoreText.setString("Score: " + to_string(score));
}

void Score::saveRecordToFile()
{
	ofstream fileScore("Image/score.txt"); // создаём объект класса ofstream для записи и связываем его с файлом score.txt
	fileScore << record << endl; // запись строки в файл
	fileScore.close(); // закрываем файл
}


void Score::updateRecord()
{
	if (score > getRecord()) {
		record = score;
		saveRecordToFile();
	}
}

int Score::getRecord()
{
	int maxRecord = 0; // начальное значение для поиска максимума
	ifstream file("Image/score.txt");
	if (file.is_open())
	{
		int temp;
		while (file >> temp) // пока есть что читать из файла
		{
			maxRecord = max(maxRecord, temp);
		}
		file.close();
	}
	return maxRecord;
}