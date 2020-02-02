#include <iostream>

using namespace std;

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {}
	virtual double GetArea() = 0;
	virtual double GetPerim() = 0;
	virtual void Draw() = 0;
};

void Shape::Draw()
{
	cout << "the abstract class is called...\n";
}

class Circle :public Shape
{
private:
	int itsRadius;
public:
	Circle() :itsRadius(0) {}
	Circle(int radius) :itsRadius(radius) {}
	virtual ~Circle() {}

	double GetArea()
	{
		return 3.14 * itsRadius * itsRadius;
	}
	double GetPerim()
	{
		return 2 * 3.14 * itsRadius;
	}
	void Draw()
	{
		cout << "Circle drawing routing here!\n" << endl;
		Shape::Draw();
	}
};

class Rectangle :public Shape
{
private:
	int itsWidth;
	int itsLength;

public:
	Rectangle() :itsLength(0), itsWidth(0) {}
	Rectangle(int len, int width) :itsWidth(width), itsLength(len) {}
	virtual ~Rectangle() {}

	double GetArea()
	{
		return ((double)itsLength * (double)itsWidth);
	}
	double GetPerim()
	{
		return (2 * ((double)itsLength + (double)itsWidth));
	}
	void Draw()
	{
		for (int i = 0; i < itsLength; i++)
		{
			for (int j = 0; j < itsWidth; j++)
			{
				cout << "x ";
			}
			cout << endl;
		}
	}
	virtual int GetLength() { return itsLength; }
	virtual int GetWidth() { return itsWidth; }

};

class Square :public Rectangle
{
public:
	Square() {}
	Square(int len);
	Square(int len, int width);
	virtual ~Square() {}
	double GetPerim() { return (4 * (double)GetLength()); }

};
Square::Square(int len) :Rectangle(len, len) {}
Square::Square(int len, int width) : Rectangle(len, width)
{
	if (GetLength() != GetWidth())
	{
		cout << "Error, not a square... a Rectangel\n";
	}
}

int main()
{
	/*Circle a;
	a.Draw();
	Rectangle r(4,6);
	cout << r.GetLength() << endl;
	cout << r.GetPerim() << endl;
	cout << r.GetArea() << endl;
	r.Draw();
	Square s(8, 8);
	s.Draw();*/

	int choice;
	bool fQuit = false;
	

	while (fQuit == false)
	{
		cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";
		cin >> choice;
		Shape* sp = NULL;
		switch (choice)
		{
		case 0:
			fQuit = true;
			break;
		case 1:
			sp = new Circle(5);
			break;
		case 2:
			sp = new Rectangle(4, 6);
			break;
		case 3:
			sp = new Square(5);
			break;
		default:
			break;
		}
		if (fQuit == false)
		{
			sp->Draw();
			delete sp;
		}
	}

	
	system("pause");
	return 0;
}