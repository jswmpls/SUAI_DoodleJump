#include "Score.h"

//���������� �����
void Score::updateScore()
{
	score += 50;
	scoreText.setString("Score: " + to_string(score));
}

void Score::saveRecordToFile()
{
	ofstream fileScore("Image/score.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ score.txt
	fileScore << record << endl; // ������ ������ � ����
	fileScore.close(); // ��������� ����
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
	int maxRecord = 0; // ��������� �������� ��� ������ ���������
	ifstream file("Image/score.txt");
	if (file.is_open())
	{
		int temp;
		while (file >> temp) // ���� ���� ��� ������ �� �����
		{
			maxRecord = max(maxRecord, temp);
		}
		file.close();
	}
	return maxRecord;
}